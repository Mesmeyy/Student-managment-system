/*************************************************************************
	> File Name: /home/zhuziyu/课程设计/student.c
	> Author:zhuziyu 
	> Mail: 
	> Created Time: 2016年06月05日 星期日 05时54分55秒
 ************************************************************************/

#include<stdio.h>
#include"Students_in_and_out_file.h"
void xuehaocha(struct student *phead);
void mingcha(struct student *phead);
void student()
{
    struct student *phead=daoin();
    int choice0=1;
    while(choice0)
    {
        printf("请输入选项搜索排名\n\n");
        printf("1->按姓名查询\n\n");
        printf("2->按学号查询\n\n");
        printf("3->退出该界面\n\n");
        scanf("%d",&choice0);
        if(choice0==3)
        return ;
        if(choice0==1)
        mingcha(phead);
        if(choice0==2)
        xuehaocha(phead);
    }
 return ; 
}
void xuehaocha(struct student *phead)
{
    char num[9];
    struct student *psearch=phead;
    struct student stu;
    int ci[5]={1,1,1,1,1};
    printf("请输入自己的学号\n\n");
    fflush(stdin);
    scanf("%s",num);
    printf("%s",num);
    while(psearch!=NULL)
    {
        if(strcmp(psearch->snum,num)==0)
        {
            stu=*psearch;
            psearch=phead;
            printf("已经找到此人!\n\n");
            while(psearch!=NULL)
            {
                if(psearch->grade.chinese>stu.grade.chinese)
                ci[0]++;
                if(psearch->grade.math>stu.grade.math)
                ci[1]++;
                if(psearch->grade.picture>stu.grade.picture)
                ci[2]++;
                if(psearch->grade.C_language>stu.grade.C_language)
                ci[3]++;
                if(psearch->all>stu.all)
                ci[4]++;
                psearch=psearch->next;
            }
                printf("学号　　姓名　　语文　语文名次　高数　高数名次　工图　工图名次　c语言　c语言名次　总分数　\n\n");
                printf("%s  %s  %d   %d   %d   %d   %d   %d   %d   %d   %d    \n\n",stu.snum,stu.sname,stu.grade.chinese,ci[0],stu.grade.math,ci[1],stu.grade.picture,ci[2],stu.grade.C_language,ci[3],stu.all,ci[4]);
                return ;
        }
        
        psearch=psearch->next;
    }
    printf("查找错误!\n\n");
}
void mingcha(struct student *phead)
{
    char name[9];
    struct student *psearch=phead;
    struct student stu;
    int ci[5]={0,0,0,0,0};
    printf("请输入自己的姓名\n\n");
    scanf("%s",name);
    while(psearch!=NULL)
    {
        if(strcmp(psearch->sname,name)==0)
        {
            stu=*psearch;
            psearch=phead;
            printf("已经找到此人!\n\n");
            while(psearch!=NULL)
            {
                if(psearch->grade.chinese>stu.grade.chinese)
                ci[0]++;
                if(psearch->grade.math>stu.grade.math)
                ci[1]++;
                if(psearch->grade.picture>stu.grade.picture)
                ci[2]++;
                if(psearch->grade.C_language>stu.grade.C_language)
                ci[3]++;
                if(psearch->all>stu.all)
                ci[4]++;
                psearch=psearch->next;
            }
                printf("学号　　姓名　　语文　语文名次　高数　高数名次　工图　工图名次　c语言　c语言名次　总名次　\n\n");
                printf("%s  %s  %d   %d   %d   %d   %d   %d   %d   %d   %d  \n\n",stu.snum,stu.sname,stu.grade.chinese,ci[0],stu.grade.math,ci[1],stu.grade.picture,ci[2],stu.grade.C_language,ci[3],stu.all,ci[4]);
                return ;
        }
        
        psearch=psearch->next;
    }
    printf("WRong!\n\n");
}


