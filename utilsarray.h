#pragma once
#include <stddef.h>

int* utils_intpop(int *arr, size_t length, int amount);
float* utils_floatpop(float *arr, size_t length, int amount);
double* utils_doublepop(double *arr, size_t length, int amount);
char* utils_stringpop(char *arr, size_t length, int amount);
int* utils_intpush(int *arr, size_t length, int iteam);
float* utils_floatpush(float *arr, size_t length, float iteam);
double* utils_doublepush(double *arr, size_t length, double iteam);
char* utils_stringpush(char *arr, size_t length, char iteam);
int* utils_intarrayreverse(int *arr, size_t lenght);
void utils_printarray(int *arr, size_t lenght);
// add reverse and dymaic
