#include "AllOOneDataStructure_432.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* --------------------------------------------------------------------------
   Internal Data Structures
   -------------------------------------------------------------------------- */

/* NodeKey: entry for each key within a Node */
typedef struct NodeKey {
    char *key;
    struct NodeKey *prevKey;
    struct NodeKey *nextKey;
} NodeKey;

/* Node: doubly-linked list node for a particular count */
typedef struct Node {
    int count;
    NodeKey *keysHead;
    NodeKey *keysTail;
    struct Node *prev;
    struct Node *next;
} Node;

/* Hash table entry mapping key to its Node and NodeKey */
typedef struct Key2NodeEntry {
    char *key;            // allocated copy of the key
    Node *node;           // pointer to the Node that holds this key
    NodeKey *nodeKey;     // pointer to the NodeKey in the node's key list
    struct Key2NodeEntry *next; // for chaining
} Key2NodeEntry;

#define HASH_CAPACITY 100003  // prime number for hash table size

typedef struct {
    Key2NodeEntry **table;
    int capacity;
} Key2NodeHash;

/* The main AllOne structure */
struct AllOne {
    Node *head;           // sentinel head (dummy: count = INT_MIN)
    Node *tail;           // sentinel tail (dummy: count = INT_MAX)
    Key2NodeHash *k2n;    // hash table mapping key -> (Node, NodeKey)
};

/* --------------------------------------------------------------------------
   Hash Table Functions for key-to-node mapping
   -------------------------------------------------------------------------- */

static unsigned long hashString(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = (unsigned char)*str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

static Key2NodeHash* createKey2NodeHash(int capacity) {
    Key2NodeHash *h = (Key2NodeHash*)malloc(sizeof(Key2NodeHash));
    h->capacity = capacity;
    h->table = (Key2NodeEntry**)calloc(capacity, sizeof(Key2NodeEntry*));
    return h;
}

static Key2NodeEntry* key2NodeFind(Key2NodeHash *h, const char *key) {
    unsigned long hh = hashString(key) % h->capacity;
    Key2NodeEntry *cur = h->table[hh];
    while (cur) {
        if (strcmp(cur->key, key) == 0)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

static Key2NodeEntry* key2NodeInsert(Key2NodeHash *h, const char *key, Node *node, NodeKey *nk) {
    unsigned long hh = hashString(key) % h->capacity;
    Key2NodeEntry *cur = h->table[hh];
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            cur->node = node;
            cur->nodeKey = nk;
            return cur;
        }
        cur = cur->next;
    }
    Key2NodeEntry *newEntry = (Key2NodeEntry*)malloc(sizeof(Key2NodeEntry));
    newEntry->key = strdup(key);
    newEntry->node = node;
    newEntry->nodeKey = nk;
    newEntry->next = h->table[hh];
    h->table[hh] = newEntry;
    return newEntry;
}

static void key2NodeRemove(Key2NodeHash *h, const char *key) {
    unsigned long hh = hashString(key) % h->capacity;
    Key2NodeEntry *cur = h->table[hh], *prev = NULL;
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            if (prev)
                prev->next = cur->next;
            else
                h->table[hh] = cur->next;
            free(cur->key);
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

static void key2NodeHashFree(Key2NodeHash *h) {
    if (!h) return;
    for (int i = 0; i < h->capacity; i++) {
        Key2NodeEntry *cur = h->table[i];
        while (cur) {
            Key2NodeEntry *tmp = cur;
            cur = cur->next;
            free(tmp->key);
            free(tmp);
        }
    }
    free(h->table);
    free(h);
}

/* --------------------------------------------------------------------------
   Functions to manage NodeKey list inside a Node
   -------------------------------------------------------------------------- */

static void nodeKeyListInit(Node *node) {
    node->keysHead = NULL;
    node->keysTail = NULL;
}

static void nodeKeyListAppend(Node *node, NodeKey *nk) {
    nk->prevKey = NULL;
    nk->nextKey = NULL;
    if (node->keysTail == NULL) {
        node->keysHead = nk;
        node->keysTail = nk;
    } else {
        nk->prevKey = node->keysTail;
        node->keysTail->nextKey = nk;
        node->keysTail = nk;
    }
}

static void nodeKeyListRemove(Node *node, NodeKey *nk) {
    NodeKey *p = nk->prevKey;
    NodeKey *n = nk->nextKey;
    if (p)
        p->nextKey = n;
    else
        node->keysHead = n;
    if (n)
        n->prevKey = p;
    else
        node->keysTail = p;
}

/* --------------------------------------------------------------------------
   Functions to manage the doubly-linked list of Nodes (by count)
   -------------------------------------------------------------------------- */

static Node* createNode(int count) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->count = count;
    node->prev = NULL;
    node->next = NULL;
    nodeKeyListInit(node);
    return node;
}

static void insertNodeAfter(Node *prevNode, Node *newNode) {
    Node *nxt = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = nxt;
    if (nxt)
        nxt->prev = newNode;
}

static void removeNode(Node *node) {
    Node *p = node->prev;
    Node *n = node->next;
    if (p)
        p->next = n;
    if (n)
        n->prev = p;
    free(node);
}

static Node* addNodeAfter(Node *prevNode, int count) {
    Node *newN = createNode(count);
    insertNodeAfter(prevNode, newN);
    return newN;
}

/* --------------------------------------------------------------------------
   Implementation of AllOne functions
   -------------------------------------------------------------------------- */

AllOne* allOneCreate() {
    AllOne *obj = (AllOne*)malloc(sizeof(AllOne));
    obj->head = createNode(INT_MIN);
    obj->tail = createNode(INT_MAX);
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    obj->k2n = createKey2NodeHash(HASH_CAPACITY);
    return obj;
}

void allOneInc(AllOne* obj, char* key) {
    Key2NodeEntry *entry = key2NodeFind(obj->k2n, key);
    if (!entry) {
        if (obj->head->next == obj->tail || obj->head->next->count != 1)
            addNodeAfter(obj->head, 1);
        Node *n1 = obj->head->next;
        NodeKey *nk = (NodeKey*)malloc(sizeof(NodeKey));
        nk->key = key; // Assumes key persists; use strdup(key) if ownership is needed.
        nk->prevKey = NULL;
        nk->nextKey = NULL;
        nodeKeyListAppend(n1, nk);
        key2NodeInsert(obj->k2n, key, n1, nk);
    } else {
        Node *curNode = entry->node;
        NodeKey *nk = entry->nodeKey;
        curNode->keysHead;  // Not used, just for clarity
        curNode->keysTail;
        curNode->prev;
        int newCount = curNode->count + 1;
        nodeKeyListRemove(curNode, nk);
        Node *nextNode = curNode->next;
        if (nextNode == obj->tail || nextNode->count != newCount)
            nextNode = addNodeAfter(curNode, newCount);
        nodeKeyListAppend(nextNode, nk);
        entry->node = nextNode;
        entry->nodeKey = nk;
        if (curNode->keysHead == NULL)
            removeNode(curNode);
    }
}

void allOneDec(AllOne* obj, char* key) {
    Key2NodeEntry *entry = key2NodeFind(obj->k2n, key);
    if (!entry) return; // Should not happen as key is guaranteed to exist
    Node *curNode = entry->node;
    NodeKey *nk = entry->nodeKey;
    nodeKeyListRemove(curNode, nk);
    int newCount = curNode->count - 1;
    if (newCount == 0) {
        key2NodeRemove(obj->k2n, key);
        free(nk);
    } else {
        Node *prevNode = curNode->prev;
        if (prevNode == obj->head || prevNode->count != newCount)
            prevNode = addNodeAfter(prevNode, newCount);
        nodeKeyListAppend(prevNode, nk);
        entry->node = prevNode;
        entry->nodeKey = nk;
    }
    if (curNode->keysHead == NULL)
        removeNode(curNode);
}

char* allOneGetMaxKey(AllOne* obj) {
    Node *maxNode = obj->tail->prev;
    if (maxNode == obj->head)
        return "";
    return maxNode->keysHead->key;
}

char* allOneGetMinKey(AllOne* obj) {
    Node *minNode = obj->head->next;
    if (minNode == obj->tail)
        return "";
    return minNode->keysHead->key;
}

void allOneFree(AllOne* obj) {
    if (!obj) return;
    Node *cur = obj->head;
    while (cur) {
        Node *nextNode = cur->next;
        NodeKey *nk = cur->keysHead;
        while (nk) {
            NodeKey *nkNext = nk->nextKey;
            /* 
             * Note: If you allocated a copy of the key (via strdup) for NodeKey->key,
             * free(nk->key) here.
             */
            free(nk);
            nk = nkNext;
        }
        free(cur);
        cur = nextNode;
    }
    key2NodeHashFree(obj->k2n);
    free(obj);
}
