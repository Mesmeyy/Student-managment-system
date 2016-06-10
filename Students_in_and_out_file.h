/*************************************************************************
	> File Name: Students_in_and_out_file.c
	> Author:zhuziyu 
	> Mail: 
	> Created Time: 2016年06月01日 星期三 14时10分52秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "str.h"
/*
struct grades
{
    int chinese;
    int math;
    int picture;
    int C_language;
};
struct student
{
    char snum[9];
    char sname[20];
    struct grades grade;
    char  level;
    struct student *next;
    
};
*/
/****************************************************************************************************************
 
函数作用:数据写入文件，给她的参数是链表头节点
 
 ** *************************************************************************************************************/
void in_file(struct  student *phead)
{
  FILE *f;
  int cou=0; 
  char path_name[50];
   memset(path_name,50,0);
  struct student *psearch=phead;
  do
    {
        cou++;
        printf("请输入文件路径和名称!\n");
        scanf("%s",path_name);
        if(cou>=2)
        printf("文件路径和名称不对,请重新输入!\n");
    }while((f=fopen(path_name,"wt+"))==NULL);
    while(psearch!=NULL)
    {
        fwrite(psearch,sizeof(struct student),1,f);
        psearch=psearch->next;
    }
    printf("数据已经全部写入文件!\n");
    fclose(f);
   
}
/**********************************************************************************************************************
 
 函数作用:把一个文件的内容读出，你需要输入文件的路径和名称

**********************************************************************************************************************/
void out_file()
{
    FILE *fp;
    struct student buffer;
    char path_name[20];
    memset(path_name,20,0);
    printf("开始输入文件路径和名称!\n\n");
    do{
        scanf("%s",path_name);
        fp=fopen(path_name,"r");
    }while(fp==NULL);
    printf("学号　　姓名　　语文　高数　工图　c语言　等级\n");
    while( fread(&buffer,sizeof(struct student),1,fp)!=0)
    printf("%s  %s  %d  %d  %d  %d  %c\n",buffer.snum,buffer.sname,buffer.grade.chinese,buffer.grade.math,buffer.grade.picture,buffer.grade.C_language,buffer.level);
    
}
/********************************************************************************************************************************
 
函数作用: 将文件内容导入链表方便后面的操作

********************************************************************************************************************************/
struct student *daoin()
{
    struct student *phead=NULL;
    struct student *pnew,*pend;
    FILE *fp;
    int daoshu=1;
    char path_name[30];
    printf("请输入要打开的文件路径和名称!\n\n");
    scanf("%s",path_name);
    while((fp=fopen(path_name,"r"))==NULL)
    {
        printf("请输入要打开的文件路径和名称!\n\n");
        scanf("%s",path_name);

    }
    printf("打开文件成功!\n\n");
    pnew=(struct student *)malloc(sizeof(struct student));
    
    while(fread(pnew,sizeof(struct student ),1,fp)!=0)
    {
        if(daoshu==1)
        {
            phead=pnew;
            pend=pnew;
            pnew->next=NULL;
        }
        else{
            pend->next=pnew;
            pnew->next=NULL;
            pend=pnew;
        }
        pnew=(struct student *)malloc(sizeof(struct student));
        daoshu++;
    }
    return phead;

}
/****************************************************************************************************************************
*
*
*
* 测试的主函数:
*
* 
******************************************************************************************************************************/
/*int main()
{
    struct student *s;
    s=(struct student *)malloc(sizeof(struct student));
    printf("kaishishuru !\n");
    scanf("%s",s->snum);
    scanf("%s",s->sname);
    scanf("%d %d %d %d",&s->grade.chinese,&s->grade.math,&s->grade.picture,&s->grade.C_language);
    getchar();
    scanf("%c",&s->level);
    s->next=NULL;
    in_file(s);
    out_file(  );
}
*/
