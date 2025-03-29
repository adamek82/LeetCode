#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct AllOne AllOne;

/* Create an AllOne data structure */
AllOne* allOneCreate();

/* Increment the count for key */
void allOneInc(AllOne* obj, char* key);

/* Decrement the count for key */
void allOneDec(AllOne* obj, char* key);

/* Returns one of the keys with maximal count (or "" if none) */
char* allOneGetMaxKey(AllOne* obj);

/* Returns one of the keys with minimal count (or "" if none) */
char* allOneGetMinKey(AllOne* obj);

/* Free the AllOne object and associated memory */
void allOneFree(AllOne* obj);

#ifdef __cplusplus
}
#endif
