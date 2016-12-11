#include <stdio.h>  
#pragma warning(disable:4996)  
int main()  
{  
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };  
    int key;  
    int left = 0;  
    int right = sizeof(arr) / sizeof(arr[0]) - 1;//下标    
    printf("请输入需要查找的数字(0-9):>");  
    scanf("%d", &key);  
    if ((key >= 0) && (key <= 9))  
    {  
        while (left <= right)  
        {  
            //int mid = left&right + (left^right) >> 1;  
            int mid = left - ((left - right) >> 1);//若用int mid = (left+right)/2,容易溢出    
            if (arr[mid] > key)  
            {  
                right = mid - 1;  
            }  
            else if (arr[mid] < key)  
            {  
                left = mid + 1;  
            }  
            else  
            {  
                printf("找到了\n");  
                break;  
            }  
        }  
        if (left > right)//来到这有两种情况，1，break跳出循环，找到了2，没找到    
        {  
            printf("找不到\n");  
        }  
    }  
    system("pause");  
    return 0;  
}