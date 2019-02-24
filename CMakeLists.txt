cmake_minimum_required(VERSION 3.13)
project(cDs)

set(CMAKE_CXX_STANDARD 14)

add_executable(cDs main.cpp config.h SqList/SqList.h SqList/others.h SqList/yiyuan.h string/c/mstring.h tree/avl/c++/avlTree.h tree/bst/c++/BSTree.h tree/BinaryTree/c++/BinaryTree.h stack/c++/calculator.h string/c++/kmp.h graph/c/graph.h graph/c/Adjacency_Matrix.h graph/c++/DenseGraph.h graph/c++/SparseGraph.h graph/c++/ReadGraph.h graph/c++/Components.h)