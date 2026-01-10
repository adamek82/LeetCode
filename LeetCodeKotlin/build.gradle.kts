plugins {
    kotlin("jvm") version "2.1.20"
    application
}

repositories {
    mavenCentral()
}

application {
    mainClass.set("TestsRunner")
}

kotlin {
    jvmToolchain(21)
}

// Treat repo root as sources, but exclude Gradle/VSCode/build folders etc.
sourceSets {
    main {
        kotlin {
            setSrcDirs(listOf("."))
            include("**/*.kt")
            exclude(
                "**/*.kts",
                "**/.gradle/**",
                "**/.kotlin/**",
                "**/.vscode/**",
                "**/build/**",
                "**/bin/**",
                "**/gradle/**",
                "**/gradle-*/**"
            )
        }
    }
}
