# ASA1
Primeiro projeto da cadeira de análise e síntese de algoritmos - 2º ano de faculdade

Overview

This project implements an algorithm to determine the correct parenthesization of a sequence of binary operations, given a custom-defined operation table. The objective is to check whether a sequence of numbers can be parenthesized to produce a given result.
Problem Description

Given an operation table and a sequence of integers, the goal is to find if there exists a valid parenthesization of the sequence that yields a desired result. If it is possible, the program should print the leftmost valid parenthesization.
Input

    An integer n (size of the operation table).
    An integer m (size of the sequence).
    A n x n table defining the results of the binary operation.
    A sequence of m integers.
    An integer representing the desired result.

Output

    If the sequence can be parenthesized to produce the desired result, the program outputs 1 followed by the leftmost valid parenthesization.
    Otherwise, it prints 0.

Example
Input:

3 6
3 2 1
3 2 1
1 3 3
2 2 2 2 1 3
1

Output:

1
((((2 2) 2) (2 1)) 3)

How to Compile & Run
Compilation

To compile the project, use the following command:

g++ -std=c++11 -O3 -Wall main.cpp -o parenthesization

Execution

Run the program with:

./parenthesization < input.txt

Where input.txt contains the input data.
Grade

Score: 20/20

This project was graded 20/20, as it efficiently implements the required algorithm.
