#define _CRT_SECURE_NO_WARNINGS

#include "FileIO.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

node* readFile(void)
{
	FILE *fp = fopen("data05_closest.txt", "r");

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

	node* head = new_node();
	node* _current = head;
	node* _next;

	char s1[10];
	memset(s1, NULL, 10);
	boolean check = FALSE;

	while (i < size)
	{
		if (!check)	// 아직 y좌표로 가지 않은 경우
		{
			if (buffer[i] != ',')
			{
				s1[j] = buffer[i];
				i++;
				j++;
			}
			else
			{
				float num = atof(s1);

				_next = new_node();
				
				setDataX(_next, num);
				
				memset(s1, NULL, 10);
				check = TRUE;
				j = 0;
				i++;
			}
		}
		// y좌표를 체크하는 경우
		else
		{
			if ((buffer[i] > 47 && buffer[i] < 58) || buffer[i] == '.')
			{
				s1[j] = buffer[i];
				j++;
			}
			else if (buffer[i] == '\n')
			{
				float num = atof(s1);

				setDataY(_next, num);
				setNext(_current, _next);

				_current = _current->next;
				memset(s1, NULL, 10);
				j = 0;
				check = FALSE;
			}
			i++;
		}
	}

	//check가 TRUE일 경우에는 Y축 좌표가 입력된 이후 ENTER가 존재하지 않을 경우
	if (check)
	{
		float num = atof(s1);
		setDataY(_next, num);
		setNext(_current, _next);
	}
	
	fclose(fp);

	return head;
}

float writeFile(node* _result)
{

}