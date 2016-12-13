    // 请实现字符串循环右移函数。列如字符串“abcdefghi”向右移2位就是“hiabcdefg”  
    // 函数原型为：void RightLoopMove(char *pstr,unsigned short steps)  
    #include <stdio.h>  
    #include <assert.h>  
    #include <string.h>  
    void severse(char *p,char *q)       //字符串翻转  
    {  
        char temp;  
        assert(p);  
        assert(q);  
        while(p<q)  
        {  
            temp=*p;  
            *p=*q;  
            *q=temp;  
            p++;  
            q--;  
        }  
    }  
    void RightLoopMove(char *pstr,unsigned short steps)  
    {  
        int len=strlen(pstr);  
        severse(pstr,pstr+len-steps-1);       //前部分翻转  
        severse(pstr+len-steps,pstr+len-1);   //后部分翻转  
        severse(pstr,pstr+len-1);             //整体翻转  
    }  
    int main()  
    {  
        char arr[]="abcdefghi";  
        RightLoopMove(arr,2);  
        printf("%s\n",arr);  
        return 0;  
    }  