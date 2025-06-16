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

add_executable(zapc
  src/main.cpp
  src/ASTVisitor.h
  src/ASTVisitor.cpp
  ${GENERATED_SOURCES}
  ${RUNTIME_SOURCES}
)

# Add ANTLR include paths
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
)

# Link Threads if on Unix
if(UNIX)
  find_package(Threads REQUIRED)
  target_link_libraries(zapc PRIVATE Threads::Threads)
endif()

