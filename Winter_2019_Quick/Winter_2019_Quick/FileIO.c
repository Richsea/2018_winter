#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>

#include "FileIO.h"

node* readFile(void)
{
	FILE *fp = fopen("data04.txt", "r");

	char* buffer;
	int size;
	int count;

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	buffer = malloc(size + 1);
	memset(buffer, NULL, size + 1);

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
	boolean check = FALSE;

	while (i < size)
	{
		if (buffer[i] != ',')
		{
			s1[j] = buffer[i];
			i++;
			j++;
			check = TRUE;
		}
		else
		{
			int num = atoi(s1);

			node* _next = new_node();
			node* _current = head;

			while (_current->next != NULL)
			{
				_current = _current->next;
			}

			setData(_next, num);
			setNext(_current, _next);

			j = 0;
			i++;

			memset(s1, NULL, 10);
			check = FALSE;
		}
	}

	if (check)
	{
		int num = atoi(s1);

		node* _next = new_node();
		node* _current = head;

		while (_current->next != NULL)
		{
			_current = _current->next;
		}

		setData(_next, num);
		setNext(_current, _next);
	}

	fclose(fp);

	return head;
}

int writeFile(node* _result)
{
	FILE *fp = fopen("data04_QuickSort.txt", "wt");
	fp = fopen("data04_QuickSort.txt", "a");

	char answer[16];
	int size = 0;

	node* head = _result->next;

	while (head != NULL)
	{
		size++;
		head = head->next;
	}

	head = _result->next;

	while (head->next != NULL)
	{
		char s1[10];
		sprintf(s1, "%d", getData(head));
		strcat(s1, ",");
		fprintf(fp, s1);
	
		head = head->next;
	}
	char s1[10];
	sprintf(s1, "%d", getData(head));
	fprintf(fp, s1);

	fclose(fp);

	return 0;
}
