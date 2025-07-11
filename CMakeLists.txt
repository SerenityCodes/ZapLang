cmake_minimum_required(VERSION 3.15)
project(ZapLang)

# Gather ANTLR sources
file(GLOB_RECURSE ANTLR_SOURCES
  vendor/antlr-runtime/src/*.cpp
  vendor/antlr-runtime/src/*.h
)

file(GLOB_RECURSE GENERATED_SOURCES
    src/antlr/*.cpp
    src/antlr/*.h
    src/ast/*.h
    src/ast/*.cpp
    src/ir/*.cpp
    src/ir/*.h
)

# Gather runtime sources (excluding Vulkan, Engine, and Systems due to external dependencies)
file(GLOB RUNTIME_CORE_SOURCES
    src/memory/*.cpp
    src/memory/Allocators/*.cpp
    src/runtime/Logging/*.cpp
    src/containers/*.cpp
)

file(GLOB RUNTIME_CORE_HEADERS
    src/memory/*.h
    src/memory/Allocators/*.h
    src/containers/*.h
)

# Gather vendor sources
file(GLOB_RECURSE VENDOR_SOURCES
    vendor/spdlog/src/*.cpp
    vendor/stb_image/*.cpp
    vendor/flecs/*.c
    vendor/doctest/doctest.h
)

add_executable(zapc
  src/main.cpp
  src/common.h
  src/logger/Logger.cpp
  src/logger/Logger.h
  src/typechecker/TypeChecker.h
  src/typechecker/TypeChecker.cpp
  ${GENERATED_SOURCES}
  ${ANTLR_SOURCES}
  ${RUNTIME_CORE_SOURCES}
  ${RUNTIME_CORE_HEADERS}
  ${VENDOR_SOURCES}
)

# Add include paths
target_include_directories(zapc PRIVATE
  vendor/antlr-runtime/src
  vendor/antlr-runtime/src/atn
  vendor/antlr-runtime/src/dfa
  vendor/antlr-runtime/src/internal
  vendor/antlr-runtime/src/misc
  vendor/antlr-runtime/src/support
  vendor/antlr-runtime/src/tree
  vendor/antlr-runtime/src/tree/pattern
  vendor/antlr-runtime/src/tree/xpath
  src
  vendor/spdlog/include
  vendor/vma/include
  vendor/stb_image
  vendor/flecs
  vendor/doctest
)

# Add compile definitions
target_compile_definitions(zapc PRIVATE
  SPDLOG_COMPILED_LIB
)

# Link Threads if on Unix
if(UNIX)
  find_package(Threads REQUIRED)
  target_link_libraries(zapc PRIVATE Threads::Threads)
endif()

