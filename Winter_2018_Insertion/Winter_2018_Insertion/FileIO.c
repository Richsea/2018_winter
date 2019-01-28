#define	_CRT_SECURE_NO_WARNINGS		// fopen ���� ����� ���� ������ ���� ����

#include "FileIO.h"
#include <stdio.h>					// fopen, fgets, fclose �Լ��� ����� ��� ����
#include <string.h>
#include <stdlib.h>

int* readFile() {
	fp = fopen("data02.txt", "r");

	char* buffer;
	int size;
	int count;

	// ���� ũ�⸦ ���ϱ�
	fseek(fp, 0, SEEK_END);		// ���� �����͸� ������ ������ �̵���Ŵ
	size = ftell(fp);			// ���� �������� ���� ��ġ�� ����

	// ���� ����. malloc �Լ��� ���� ���� �����ֱ� ������ memset���� 0���� �ʱ�ȭ
	buffer = malloc(size + 1);	// ���� ũ�� + 1byte(���ڿ� �������� NULL)��ŭ ���� �޸� �Ҵ�
	memset(buffer, 0, size + 1);	// ���� ũ�� + 1byte��ŭ �޸𸮸� 0���� �ʱ�ȭ

	// �տ��� ���� �����͸� ������ �̵����ױ� ������ ���� �����͸� ������ ó������ �̵�
	fseek(fp, 0, SEEK_SET);		// ���� �����͸� ������ ó������ �̵���Ŵ
	count = fread(buffer, size, 1, fp);	// ���� ũ�⸸ŭ ���� ����

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

//fprintf�� fwrite ��� ����� �� fclose�� ����� ��������� ����ȴ�.
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

	//üũ
	printf("%d\n", *outputData);

	int size = sizeof(outputData);
	char* result = malloc(sizeof(int) * size);	//char���� ũ�Ⱑ �Ѿ�� ©���� ���������� �����Ҵ�
	char** data = malloc(sizeof(int) * 4);

	result = *outputData;
	outputData++;
	
	//üũ
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