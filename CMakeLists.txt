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
)

# Gather runtime sources (excluding Vulkan, Engine, and Systems due to external dependencies)
file(GLOB RUNTIME_CORE_SOURCES
    src/runtime/Memory/*.cpp
    src/runtime/Memory/Allocators/*.cpp
    src/runtime/Logging/*.cpp
    src/runtime/Containers/*.cpp
)

file(GLOB RUNTIME_CORE_HEADERS
    src/runtime/Memory/*.h
    src/runtime/Memory/Allocators/*.h
    src/runtime/Logging/*.h
    src/runtime/Containers/*.h
    src/runtime/common.h
)

# Gather vendor sources
file(GLOB_RECURSE VENDOR_SOURCES
    vendor/spdlog/src/*.cpp
    vendor/stb_image/*.cpp
    vendor/flecs/*.c
)

add_executable(zapc
  src/main.cpp
  src/ASTVisitor.h
  src/ASTVisitor.cpp
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
  src/runtime
  vendor/spdlog/include
  vendor/vma/include
  vendor/stb_image
  vendor/flecs
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

