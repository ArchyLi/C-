#include "sweep.h"  

void inti_game(char mine[ROWS][COLS], char show[ROWS][COLS])
{
	memset(mine, '0', ROWS*COLS*sizeof(char));
	memset(show, '*', ROWS*COLS*sizeof(char));
	set_mine(mine);
}

int get_mine_num(int x, int y)
{
	return rand() % (y - x + 1) + x;
}

void set_mine(char mine[ROWS][COLS])
{
	int count = COUNT;
	int x = 0;
	int y = 0;
	srand((unsigned)time(NULL));
	while (count)
	{
		x = get_mine_num(1, 9);
		y = get_mine_num(1, 9);
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

void display(char show[ROWS][COLS])  //打印出界面  
{
	int i = 0;
	int j = 0;
	printf(" ");
	for (i = 1; i < COLS - 1; i++)
	{
		printf(" %d ", i);
	}
	printf("\n");
	for (i = 1; i < ROWS - 1; i++)
	{
		printf("%d", i);
		for (j = 1; j < COLS - 1; j++)
		{
			printf(" %c ", show[i][j]);
		}
		printf("\n");
	}
}

void sweep(char mine[ROWS][COLS], char show[ROWS][COLS])
{
	int count = 0;
	int x = 0;
	int y = 0;
	while (count != ((ROWS - 2)*(COLS - 2) - COUNT))
	{
		printf("请输入坐标：\n");
		scanf("%d%d", &x, &y);
		if (mine[x][y] == '1')
		{
			printf("踩雷了！\n");
			return;
		}
		else
		{
			int ret = get__mine(mine, x, y);
			show[x][y] = ret + '0';
			display(show);
			count++;
		}
	}
	printf("恭喜你赢了！\n");
	display(mine);
}
int get__mine(char mine[ROWS][COLS], int x, int y)   //附近雷的个数  
{
	int count = 0;
	if (mine[x + 1][y + 1] == '1')count++;
	if (mine[x + 1][y - 1] == '1')count++;
	if (mine[x + 1][y] == '1')count++;

	if (mine[x - 1][y + 1] == '1')count++;
	if (mine[x - 1][y - 1] == '1')count++;
	if (mine[x - 1][y] == '1')count++;

	if (mine[x][y + 1] == '1')count++;
	if (mine[x][y - 1] == '1')count++;

	return count;
}

#include "sweep.h"  
void menu()
{
	printf("**********************\n");
	printf("****** 1、play  ******\n");
	printf("****** 2、exit  ******\n");
	printf("**********************\n");
}

void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	inti_game(mine, show);
	display(show);
	display(mine);
	sweep(mine, show);
}

void test()
{
	int input;
	do
	{
		menu();
		printf("请输入选择->:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("请重新输入正确选项：\n");
			break;
		}

	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1  

#ifndef __MINE_H__  
#define __MINE_H__  

enum op
{
	EXIT,
	PLAY
};

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <time.h>  

#define COLS 11  
#define ROWS 11  
#define COUNT 30  

void display(char show[ROWS][COLS]);
void inti_game(char mine[ROWS][COLS], char show[ROWS][COLS]);
void set_mine(char mine[ROWS][COLS]);//设置雷区  
									 //void get_num(int x, int y);    //随机产生雷的位置  
void sweep(char mine[ROWS][COLS], char show[ROWS][COLS]);  //开始扫雷  
int get__mine(char mine[ROWS][COLS], int x, int y);   //附近雷的个数  

#endif  