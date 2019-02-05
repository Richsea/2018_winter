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

	int i = 0;		// 파일 내의 위치저장을 위한 변수
	int j = 0;		// string을 저장하기위한 char의 저장 위치를 위한 변수

	node* head = new_node();
	boolean check = FALSE;

	char s1[30];
	memset(s1, NULL, 30);

	node* _current = head;
	int title_num;

	while (i < size)
	{
		if ((buffer[i] > 47 && buffer[i] < 58) && !check)	// 숫자가 입력되었을 때
		{
			s1[j] = buffer[i];
			j++;
			i++;
		}
		else if ((buffer[i] == ',' || buffer[i] == 32) && !check)	// ','나 SPACE가 눌렸을 때
		{
			i++;
			j = 0;
			title_num = atoi(s1);
			memset(s1, NULL, 30);
			check = TRUE;
		}
		else if (buffer[i] == '\n' && check)	// ENTER가 눌렸을 때
		{
			node* _next = new_node();
			
			j = 0;
			while (s1[j] != '\0')
			{
				j++;
			}

			// new_node로 char의 데이터 크기 설정해주는 부분에서 오류 발생 -> malloc 변수 data 생성
			char* data = (char*)malloc(sizeof(char) * j);
			memset(data, NULL, sizeof(char) * j);
			strcat(data, s1);

			i++;
			j = 0;
		
			setTitle(_next, data);
			setNum(_next, title_num);
			setNext(_current, _next);
			_current = _current->next;

			memset(s1, NULL, 30);

			check = FALSE;
		}
		else			// ','와 '과목명' 사이의 데이터가 공백일 경우를 대비
		{		
			if (buffer[i] == 32 && j == 0)
			{
				i++;
				continue;
			}
			if (check)
			{
				s1[j] = buffer[i];
				i++;
				j++;
			}
		}
	}

	// 마지막에 'ENTER'가 입력이 되지 않아서 최종데이터를 저장하지 못하는 상황 방지
	if (check)
	{
		node* _next = new_node();

		setTitle(_next, s1);
		setNum(_next, title_num);
		setNext(_current, _next);
	}
	
	fclose(fp);

	return head;
}