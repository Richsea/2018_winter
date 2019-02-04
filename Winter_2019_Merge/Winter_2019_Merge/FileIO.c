#define	_CRT_SECURE_NO_WORNINGS

#include "FileIO.h"
#include <string.h>

#include <time.h>

node* readFile()
{
	fp = fopen("data02.txt", "r");

	char* buffer;
	int size;
	int count;

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	buffer = malloc(size + 1);
	memset(buffer, 0, size + 1);

	fseek(fp, 0, SEEK_SET);
	count = fread(buffer, size, 1, fp);

	int i = 0;
	int j = 0;
	int loc = 0;

	int* data = malloc(size + 1);
	memset(data, NULL, size + 1);

	node* head = new_node();

	char s1[10];
	memset(s1, NULL, 10);

	while (i < size)
	{
		if (buffer[i] != ',')
		{
			s1[j] = buffer[i];
			i++;
			j++;
		}
		else
		{
			int temp = atoi(s1);

			node* _next = new_node();
			node* _current = head;

			while (_current->next != NULL)
			{
				_current = _current->next;
			}
			
			setData(_next, temp);
			setNext(_current, _next);
			
			j = 0;
			i++;
			memset(s1, NULL, 10);
		}
	}

	// 파일 입출력 최종 출력
	node* _current = head;
	node* _next = new_node();

	while (_current->next != NULL)
	{
		_current = _current->next;
	}
	setData(_next, atoi(s1));
	setNext(_current, _next);
	
	fclose(fp);

	return head;
}

int writeFile(node* outputData)
{
	fp = fopen("data02_MergeSort.txt", "wt");

	char answer[16];
	int size = 0;
	int temp = 0;

	/*  배열로 된 데이터로 쓰기를 진행할 때 사용
	while (*(outputData + temp) != '\0')
	{
		size++;
		temp++;
	}

	char* data = (char*)malloc(sizeof(char)*size);
	memset(data, NULL, sizeof(char)* size);
	temp = 0;

	for (int i = 0; i < size - 1; i++)
	{
		char s1[10];
		sprintf(s1, "%d", outputData[i]);
		strcat(s1, ",");
		strcat(data, s1);
	}
	
	char s1[10];
	sprintf(s1, "%d", outputData[size]);
	strcat(data, s1);
	*/

	node* head = outputData->next;

	while (head != NULL)
	{
		size++;
		head = head->next;
	}

	char* data = (char*)malloc(sizeof(char)*size);
	memset(data, NULL, sizeof(char)* size);
	temp = 0;

	head = outputData->next;

	while (head->next != NULL)
	{
		char s1[10];
		sprintf(s1, "%d", head->data);
		strcat(s1, ",");
		strcat(data, s1);
		head = head->next;
	}
	char s1[10];
	sprintf(s1, "%d", head->data);
	strcat(data, s1);

	fprintf(fp, data);
	fclose(fp);

	return 0;
}