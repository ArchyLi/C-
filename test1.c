    #include <stdio.h>  
    #include <assert.h>  
    #include <string.h>  
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
    }  
    int main()  
    {  
        char arr[]="abcdefghi";  
        RightLoopMove(arr,2);  
        printf("%s\n",arr);  
        return 0;  
    }  
