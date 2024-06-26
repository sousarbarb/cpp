/**
 * @file simple_math.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-01
 *
 * @copyright Copyright (c) 2024
 *
 * pragma once is required to avoid the compiler to copy several times when
 * #include "simple_math.h" is called
 *
 * #pragma once is an alternate form of header guards using the #pragma
 * preprocessor directive, serving the same purpose as header guards - avoid a
 * header file from being included multiple times
 */
#pragma once

#include <iostream>





int add(int a, int b);
int minus(int a, int b);
int mult(int a, int b);
int divide(int a, int b);

void add(int a[], int b[], int res[], size_t n);
void minus(int a[], int b[], int res[], size_t n);
void mult(int a[], int b[], int res[], size_t n);
void divide(int a[], int b[], int res[], size_t n);

void add(float a[], float b[], float res[], size_t n);
void minus(float a[], float b[], float res[], size_t n);
void mult(float a[], float b[], float res[], size_t n);
void divide(float a[], float b[], float res[], size_t n);
