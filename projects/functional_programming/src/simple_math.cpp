#include "simple_math.h"





int add(int a, int b)
{
  return a+b;
}

int minus(int a, int b)
{
  return a-b;
}

int mult(int a, int b)
{
  return a*b;
}

int divide(int a, int b)
{
  return a/b;
}



void add(int a[], int b[], int res[], size_t n)
{
  for (size_t idx = 0; idx < n; idx++)
  {
    res[idx] = a[idx] + b[idx];
  }
}

void minus(int a[], int b[], int res[], size_t n)
{
  for (size_t idx = 0; idx < n; idx++)
  {
    res[idx] = a[idx] - b[idx];
  }
}

void mult(int a[], int b[], int res[], size_t n)
{
  for (size_t idx = 0; idx < n; idx++)
  {
    res[idx] = a[idx] * b[idx];
  }
}

void divide(int a[], int b[], int res[], size_t n)
{
  for (size_t idx = 0; idx < n; idx++)
  {
    res[idx] = a[idx] / b[idx];
  }
}



void add(float a[], float b[], float res[], size_t n)
{
  for (size_t idx = 0; idx < n; idx++)
  {
    res[idx] = a[idx] + b[idx];
  }
}

void minus(float a[], float b[], float res[], size_t n)
{
  for (size_t idx = 0; idx < n; idx++)
  {
    res[idx] = a[idx] - b[idx];
  }
}

void mult(float a[], float b[], float res[], size_t n)
{
  for (size_t idx = 0; idx < n; idx++)
  {
    res[idx] = a[idx] * b[idx];
  }
}

void divide(float a[], float b[], float res[], size_t n)
{
  for (size_t idx = 0; idx < n; idx++)
  {
    res[idx] = a[idx] / b[idx];
  }
}
