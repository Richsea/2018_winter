#define	_CRT_SECURE_NO_WARNINGS		// fopen ���� ����� ���� ������ ���� ����

#include "FileIO.h"
#include <stdio.h>					// fopen, fgets, fclose �Լ��� ����� ��� ����
#include <string.h>

int readFile() {
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

	return 0;	
}

int writeFile(int* outputData) {
	fp = fopen("data02_Insertion.txt", "w");

	fprintf(fp, "test");
	char* data = saveChar(outputData);

	fp = fopen("data02_Insertion.txt", "a");
	fprintf(fp, "�Ϸ�");
	/*
	while (*outputData != '\0') {
		
	}
	*/
	fprintf(fp, "�Ϸ�");
	fclose(fp);


	return 0;
}

char* saveChar(int* outputData) {
	//char* data = malloc(sizeof(char) * 1000);
	//strcat(data, outputData);
	char* intData;
	int location = 0;

	intData = *(char*)outputData;
	
	//üũ
	printf("%d\n", *outputData);

	int size = sizeof(outputData);
	char* result = malloc(sizeof(int) * size);	//char���� ũ�Ⱑ �Ѿ�� ©���� ���������� �����Ҵ�
	result = *outputData;
	outputData++;
	
	//üũ
	printf("%d:%d\n", *outputData, result);

	while (*outputData != '\0') {
		append(result, ',');
		printf("%d", result);
		append(result, *outputData);
		printf("%d", result);
		strcat(result, *outputData);
		printf("%d", result);
		location++;
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