#include "PrintOut.h"

void printScreen(node* _this)
{
	node* _newNode;
	
	int activity = 0;

	while (activity != 6)
	{
		printList(_this);
		
		printf("\n\n-----------------------------------------\n");
		printf("1. 작업 추가\t2. 최소값\t3. 최소 우선순위 작업 처리\n");
		printf("4. 원소 키값 증가\t5. 작업 제거,\t6. 종료\n");

		scanf("%d", &activity);

		int titleNum;
		int nextNum = 0;
		char title[30];
		char* data;

		switch (activity)
		{
		case 1:
			printf("\n과목번호: ");
			scanf("%d", &titleNum);
			printf("\n과목명: ");
			scanf("%s", &title);

			int i = 0;
			for (i = 0; i < 30; i++)
			{
				if (title[i] == '\0')
					break;
			}

			data = (char*)malloc(sizeof(char*) * i);
			memset(data, NULL, sizeof(char*) * i);

			strcat(data, title);

			insert(_this, titleNum, data);
			break;
		
		case 2:
			_newNode = min(_this);
			printf("%d.\t%s\n", _newNode->number, _newNode->title);
			break;

		case 3:
			extract_min(_this);
			break;
			
		case 4:
			printf("\n현재번호: ");
			scanf("%d", &titleNum);
			printf("\n바꿀번호: ");
			scanf("%d", &nextNum);
			increase_key(_this, titleNum, nextNum);
			break;
		
		case 5:
			printf("\n지울 과목번호: ");
			scanf("%d", &titleNum);
			delete(_this, titleNum);
			break;

		default:
			activity = 6;
		}
	}
}

void printList(node* _this)
{
	printf("**** 현재 우선 순위 큐에 저장되어있는 작업 대기 목록은 다음과 같습니다 ****\n\n");
	_this = _this->next;

	while (_this != NULL)
	{
		printf("%d.\t%s\n", getNum(_this), getTitle(_this));
		_this = _this->next;
	}
}