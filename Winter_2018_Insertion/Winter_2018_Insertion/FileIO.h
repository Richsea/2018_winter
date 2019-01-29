#pragma once

#include <stdio.h>	// fopen, fgets, fclose 함수가 선언된 헤더 파일

FILE *fp;

int* readFile(void);
int writeFile(int* outputData[]);