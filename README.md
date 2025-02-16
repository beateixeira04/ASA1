# ASA1
Primeiro projeto da cadeira de análise e síntese de algoritmos - 2º ano de faculdade

Parenthesization of Binary Operations

Description

This project implements an algorithm to determine the correct parenthesization of a sequence of binary operations, given a custom-defined operation table. The goal is to check if a sequence of numbers can be parenthesized to produce a given result.

Input Format

An integer n (size of the operation table) and an integer m (size of the sequence).

A n x n table defining the results of the binary operation.

A sequence of m integers.

An integer representing the desired result.

Output Format

If the sequence can be parenthesized to obtain the desired result, the program prints 1 followed by the leftmost valid parenthesization.

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

Compilation & Execution

Compile with:

g++ -std=c++11 -O3 -Wall main.cpp -o parenthesization

Run with:

./parenthesization < input.txt

Grade

Score: 20/20 ✅

This project was graded 20/20, meaning it correctly implements the required algorithm efficiently.
