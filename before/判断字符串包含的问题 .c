//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 �� AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.

//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA

//AABCD����һ���ַ��õ�DAABC 
//AABCD���������ַ��õ�CDAAB




//��arr1��׷��һ��arr1��Ȼ��鿴arr2ʱ����arr1�����ַ�����
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int judgement_string(char arr1[], const char *arr2)
{
	assert(arr1);
	assert(arr2);
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
	{
		return 0;
	}
	strncat(arr1, arr1, len1);
	if (strstr(arr1, arr2) == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	char arr1[30] = "AABCD";
	char *arr2 = "BCDAA";
	int ret = judgement_string(arr1, arr2);
	if (ret)
	{
		printf("���ַ�����ת֮����ַ���\n");
	}
	else
	{
		printf("�����ַ�����ת֮����ַ���");
	}
	system("pause");
	return 0;
}