#pragma once

#include <stdio.h>	// fopen, fgets, fclose �Լ��� ����� ��� ����

FILE *fp;

int* readFile(void);
int writeFile(int* outputData[]);