/*************************************************************************
	> File Name: /home/zhuziyu/课程设计/disign.c
	> Author:zhuziyu 
	> Mail: 
	> Created Time: 2016年06月05日 星期日 06时16分56秒
 ************************************************************************/

#include<stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "teacher.h"
int main()
{
    int choice=1;
    while(choice)
    {
        printf("输入你的登录方式\n\n");
        printf("1->以教师身份登陆\n\n");
        printf("2->以学生身份登陆\n\n");
        printf("3->退出次界面\n\n");
        scanf("%d",&choice);
        if(choice==3)
        return 0;
        if(choice==1)
        manager();
        if(choice==2)
        student();
    }
    return 0;
}
