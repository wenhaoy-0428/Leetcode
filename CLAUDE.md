# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

This is a personal LeetCode solutions repository containing C++ implementations organized by problem number. Each problem folder contains the solution code and a makefile for building.

## Common Commands

**Build a problem solution:**
```bash
cd <problem_number>
make
```

**Run the solution:**
```bash
./solution
```

**Clean build artifacts:**
```bash
cd <problem_number>
make clean
```

**Build with gtest tests (some problems):**
```bash
cd <problem_number>
make
./solution
```

## Repository Structure

- `<problem_number>/` - Each LeetCode problem has its own folder (e.g., `100/`, `3548/`)
- `util/util.h` - Shared data structures (ListNode, TreeNode) and helper functions (printVector, createLinkedList, compareVectors, etc.)
- `gtest/` - Google Test framework setup (CMake-based) for problems with unit tests
- `<problem_number>/<date>/` - Some problems have multiple solution attempts in date-stamped subdirectories

## Build Patterns

**Simple problems (no tests):**
```make
CC = g++
CFLAGS = -Wall -Wextra -std=c++11
```

**Problems with gtest:**
```make
CC = g++
CFLAGS = -Wall -Wextra -std=c++17 -g -L ../gtest/lib -l gtest -l gtest_main
GTEST = ../gtest/_deps/googletest-src/googletest/include
```

## Code Conventions

- Solutions include `../util/util.h` for shared utilities
- Problem solutions are typically in a `Solution` class or as standalone functions
- Test files use Google Test with `SolutionTest : public testing::Test` pattern
- C++ standard varies by problem (c++11, c++17)
