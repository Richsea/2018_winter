#define _CRT_SECURE_NO_WARNINGS

#include "FileIO.h"
#include <string.h>

node* readFile(void)
{
	fp = fopen("data03.txt", "r");

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
	memset(data, NULL, size);

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