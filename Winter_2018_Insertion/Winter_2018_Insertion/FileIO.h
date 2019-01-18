#pragma once

#include <stdio.h>

FILE *fp;

int readFile(void);

int writeFile(int* outputData);
char* saveChar(int* outputData);
void append(char* dst, char c);