#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
char *my_strcpy(char *dest, const char *src)
{
    char *ret = dest;
    assert(dest);
    assert(src);
    while (*dest++ = *src++)
    {
        NULL;
    }
    return dest;
}
int main()
{
    char arr1[40];
    char *arr2 = "hello,world";
    my_strcpy(arr1, arr2);
    printf("%s\n", arr1);
    system("pause");
    return 0;
}