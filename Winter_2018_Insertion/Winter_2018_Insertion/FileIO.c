#define	_CRT_SECURE_NO_WARNINGS		// fopen 보안 경고로 인한 컴파일 에러 방지

#include "FileIO.h"
#include <stdio.h>					// fopen, fgets, fclose 함수가 선언된 헤더 파일
#include <string.h>
#include <stdlib.h>

int* readFile() {
	fp = fopen("data02.txt", "r");

	char* buffer;
	int size;
	int count;

	// 파일 크기를 구하기
	fseek(fp, 0, SEEK_END);		// 파일 포인터를 파일의 끝으로 이동시킴
	size = ftell(fp);			// 파일 포인터의 현재 위치를 얻음

	// 버퍼 생성. malloc 함수로 이전 값이 남아있기 때문에 memset으로 0으로 초기화
	buffer = malloc(size + 1);	// 파일 크기 + 1byte(문자열 마지막의 NULL)만큼 동적 메모리 할당
	memset(buffer, 0, size + 1);	// 파일 크기 + 1byte만큼 메모리를 0으로 초기화

	// 앞에서 파일 포인터를 끝으로 이동시켰기 때문에 파일 포인터를 파일의 처음으로 이동
	fseek(fp, 0, SEEK_SET);		// 파일 포인터를 파일의 처음으로 이동시킴
	count = fread(buffer, size, 1, fp);	// 파일 크기만큼 값을 읽음

	int i = 0;
	int j = 0;
	int loc = 0;
	
	int* data = malloc(size + 1);
	memset(data, NULL, size + 1);
	printf("%d\n", data);
	char s1[10];
	memset(s1, NULL, 10);
	while (i < size)
	{
		
		if (buffer[i] != ',')
		{
			s1[j] = buffer[i];
			i++;
			j++;
			printf("%s", s1);
		}
		else
		{
			int temp = atoi(s1);
			data[loc] = temp;
			j = 0;
			loc++;
			i++;
			memset(s1, NULL, 10);
		}
	}
	data[loc] = atoi(s1);
	fclose(fp);

	return data;	
}

//fprintf와 fwrite 모두 사용할 때 fclose를 해줘야 변경사항이 적용된다.
int writeFile(int* outputData[]) {
	fp = fopen("data02_Insertion.txt", "wt");

	char answer[16];
	int size = 0;
	int temp = 0;

	while (*(outputData+temp) != '\0') {
		size++;
		temp++;
	}

	char* data = (char*)malloc(sizeof(char)*size);
	memset(data, NULL, sizeof(char)*size);
	temp = 0;

	for (int i = 0; i < size-1; i++)
	{
		char s1[10];
		sprintf(s1, "%d", outputData[i]);
		strcat(s1,",");
		strcat(data,s1);
	}

	char s1[10];
	sprintf(s1, "%d", outputData[size-1]);
	strcat(data, s1);
	
	//printf("%s", data);
	fprintf(fp, data);
	
	fclose(fp);

	return 0;
}

char* saveChar(int* outputData) {
	//char* data = malloc(sizeof(char) * 1000);
	//strcat(data, outputData);

	//체크
	printf("%d\n", *outputData);

	int size = sizeof(outputData);
	char* result = malloc(sizeof(int) * size);	//char형은 크기가 넘어가면 짤리는 문제때문에 동적할당
	char** data = malloc(sizeof(int) * 4);

	result = *outputData;
	outputData++;
	
	//체크
	printf("%d:%d\n", *outputData, result);

	while (*outputData != '\0') {
		data = *outputData;
		append(result, ',');
		printf("%d", result);
		append(result, *outputData);
		printf("%d", result);
		strcat(result, *outputData);
		printf("%d", result);
	}
	/*
	while (*outputData != '\0') {
		//strcat(data, ",");
		printf("%d", *outputData);
		//strcat(data, outputData);
		
//		printf("%d,", data);
//		printf("%d\n", *data);
		outputData++;
	}
	*/
	return result;
	//return 0;
}
void append(char *dst, char c) {
	char *p = dst;
	while (*p != '\0')	p++;
	*p = c;
	*(p + 1) = '\0';
}