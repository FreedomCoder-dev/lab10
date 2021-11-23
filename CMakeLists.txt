cmake_minimum_required(VERSION 3.17)
project(lab10 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab10 main.c btree.h btree.c graph.h graph_adapter.c graph_adapter.h graph_reader.c graph_reader.h stack.h stack.c)
