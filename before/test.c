# test
测试文件
    //基于顺序表实现的简易通讯录-----1  
      
    #define _CRT_SECURE_NO_WARNINGS 1  
      
    #include<stdio.h>  
    #include<stdlib.h>  
    #include<string.h>  
    typedef struct stu                    //定义一个学生信息的结构体类型  
    {  
        char name[20];  
        char sex[6];  
        int age;  
        char tele[20];  
        char address[40];  
      
    }stu;  
      
    typedef struct                                               //创建一个顺序表  
    {  
        stu data[1000];  
        int i;  
    }suquence;  
      
    int find(suquence *book, char *names)  
    {  
        int n = 0;  
        while (n < book->i)  
        {  
            if (strcmp(book->data[n].name, names) == 0)  
                break;  
            n++;  
        }  
        if (n != book->i)  
            return n;                       //如果找到则返回这个位置  
        return -1;                           //没找到返回-1  
    }  
      
      
    void Add(suquence *book)  
    {  
        if (book->i >= 1000)                                 //最多存储1000条信息  
        {  
            printf("通讯录已满\n");  
        }  
        else  
        {  
            printf("请输入名字:");  
            scanf("%s", book->data[book->i].name);  
            printf("请输入性别：");  
            scanf("%s", book->data[book->i].sex);  
            printf("请输入年龄：");  
            scanf("%d",&book->data[book->i].age);  
            printf("请输入电话：");  
            scanf("%s", book->data[book->i].tele);  
            printf("请输入地址：");  
            scanf("%s", book->data[book->i].address);  
            ++book->i;  
            printf("添加成功\n");  
        }  
    }  
      
      
    void delete(suquence *book,char *names)  
    {  
        if (book->i <= 0)                                
        {  
            printf("通讯录已空\n");  
        }  
        else  
        {  
            int n = 0;  
            n = find(book, names);                       //根据名字查找  
            if (n==0)          
            {  
                printf("没有此人\n");  
            }  
            else  
            {  
                while (n < book->i - 1)                           //如果找到，则进行删除，依次向前覆盖  
                {  
                    book->data[n] = book->data[n + 1];  
                }  
                book->i--;                     //删除一个，则记录位置的book->i也要减一  
                printf("删除成功\n");  
            }  
        }  
    }  
      
    void change(suquence *book , char *names)  
    {  
        int ret = 0;  
        ret = find(book,names);              //先找到这个人的位置  
        if (ret == -1)  
        {  
            printf("没有此人\n");  
        }  
        else  
        {  
            printf("请输入名字:");  
            scanf("%s", book->data[ret].name);  
            printf("请输入性别：");  
            scanf("%s", book->data[ret].sex);  
            printf("请输入年龄：");  
            scanf("%d", &book->data[ret].age);  
            printf("请输入电话：");  
            scanf("%s", book->data[ret].tele);  
            printf("请输入地址：");  
            scanf("%s", book->data[ret].address);  
            printf("修改成功\n");  
        }  
    }  
      
      
    void output(suquence *book)  
    {  
        if (book->i <=0)  
        {  
            printf("通讯录为空\n");  
        }  
        else  
        {  
            int n =0;  
            while (n < book->i)  
            {  
                printf("名字：%s 性别： %s 年龄： %d 电话： %s 地址： %s\n",   
                    book->data[n].name,   
                    book->data[n].sex,  
                    book->data[n].age,  
                    book->data[n].tele,  
                    book->data[n].address);  
                n++;  
            }  
      
        }  
    }  
      
      
    void init(suquence *book)  
    {  
        book->i = 0;            //只要将记录位置的book->i置0  
        printf("初始化成功\n");  
    }  
      
      
    void sort(suquence *book)  
    {  
        if (book->i >1)                  //当通讯录中有1个以上记录再进行排序  
        {  
            int i= 0;  
            int j = 0;  
            int flag = 0;  
            for (i = 0; i < book->i-1; i++)              
            {  
                flag = 1;  
                for (j = 0; j < book->i - i - 1; j++)  
                {  
                               if (strcmp(book->data[j].name, book->data[j + 1].name) < 0)  //根据名字进行排序  
                    {  
                    char arr[50];  
                    strcpy(arr, book->data[j].name);  
                    strcpy(book->data[j].name, book->data[j + 1].name);  
                    strcpy(book->data[j + 1].name, arr);  
      
                    strcpy(arr, book->data[j].sex);  
                    strcpy(book->data[j].sex, book->data[j + 1].sex);  
                    strcpy(book->data[j + 1].sex, arr);  
      
                    int tmp = book->data[j].age;  
                    book->data[j].age = book->data[j + 1].age;  
                    book->data[j + 1].age = tmp;  
      
                    strcpy(arr, book->data[j].tele);  
                    strcpy(book->data[j].tele, book->data[j + 1].tele);  
                    strcpy(book->data[j + 1].tele, arr);  
      
                    strcpy(arr, book->data[j].address);  
                    strcpy(book->data[j].address, book->data[j + 1].address);  
                    strcpy(book->data[j + 1].address, arr);  
      
                        flag = 0;  
                    }        //if 结束  
                }  
                if (flag)     //如果已经有序，则flag为真  
                break;  
            }  
        }  
        printf("排序成功\n");  
    }  
      
      
      
    void execute(suquence book)  
    {  
        int n = 0;  
        char name[20];  
        while (1)  
        {  
            printf("请选择：");  
            scanf("%d", &n);  
            switch (n)  
            {  
            case 0:  
                exit(1);  
                break;  
            case 1:  
                Add(&book);  
                break;  
            case 2:  
                printf("请输入姓名：");  
                scanf("%s", name);  
                delete(&book, name);  
                break;  
            case 3:  
                printf("请输入姓名：");  
                scanf("%s", name);  
                change(&book, name);  
                break;  
            case 4:  
                printf("请输入姓名：");  
                scanf("%s", name);  
                int ret = find(&book, name);  
                if (ret ==-1)  
                    printf("查询无果\n");  
                else  
                    printf("名字：%s 性别： %s 年龄： %d 电话： %s 地址： %s\n",  
                    book.data[ret].name,  
                    book.data[ret].sex,  
                    book.data[ret].age,  
                    book.data[ret].tele,  
                    book.data[ret].address);  
                break;  
            case 5:  
                init(&book);  
                break;  
            case 6:  
                output(&book);  
                break;  
            case 7:  
                sort(&book);  
                break;  
            default:  
                printf("选择无效\n");  
                break;  
            }  
        }  
          
    }  
      
      
      
    int main()  
    {  
        printf("*******************************\n");  
        printf("*0.exit              1.Add    *\n");  
        printf("*2.deletel           3.change *\n");  
        printf("*4.find              5.init   *\n");  
        printf("*6.output            7.sort   *\n\n");  
        suquence book;  
        book.i = 0;  
        execute(book);  
        system("pause");  
        return 0;  
    }  
