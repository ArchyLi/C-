//判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 ＝ AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.

//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA

//AABCD右旋一个字符得到DAABC 
//AABCD右旋两个字符得到CDAAB




//在arr1后追加一个arr1，然后查看arr2时候是arr1的子字符串。
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
		printf("是字符串旋转之后的字符串\n");
	}
	else
	{
		printf("不是字符串旋转之后的字符串");
	}
	system("pause");
	return 0;
}