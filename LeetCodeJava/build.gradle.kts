plugins {
    application
    java
}

repositories {
    mavenCentral()
}

application {
    mainClass.set("TestsRunner")
}

java {
    toolchain {
        languageVersion.set(JavaLanguageVersion.of(21))
    }
}

// Treat repo root as sources, but exclude Gradle/VSCode/build folders etc.
sourceSets {
    main {
        java {
            setSrcDirs(listOf("."))
            include("**/*.java")
            exclude(
                "**/.gradle/**",
                "**/.vscode/**",
                "**/build/**",
                "**/bin/**",
                "**/gradle/**",
                "**/gradle-*/**"
            )
        }
    }
}
