/*************************************************************************
	> File Name: teacher.c
	> Author:zhuziyu 
	> Mail: 
	> Created Time: 2016年06月01日 星期三 15时21分15秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "student.h"
#include "teacher_password.h"


//这个头文件包含了文件的读入读出，还包含了一个包含结构体的头文件
struct student *create();
void print(struct student *phead);
void fixdata(struct student *phead);
void fixdata1(struct student *phead,char *s);
void fixdata2(struct student *phead,char *s);
void adddata(struct student *phead);
void adddata1(struct student *phead,int n);
void adddata2(struct student *phead,char *s);
void deldata(struct student *phead);
void deldata1(struct student *phead,char *num);
void deldata2(struct student *phead,char *name);
void deldata3(struct student *phead);
void sondeldata3(struct student *phead);
void paixu(struct student *phead);
void xuehaopai(struct student *phead);
void xingmingpai(struct student *phead);
void zongpai(struct student *phead);
void yuwenpai(struct student *phead);
void gaoshupai(struct student *phead);
void gongtupai(struct student *phead);
void Cpai(struct student *phead);
void nohegepai(struct student *phead);
int manager()
{

    int filei=1;
    char filepasspath[50];
    struct student *phead;
    int choice0=1;
    int choice2;
    infile();
    if(outfile()==0)
    {
       printf("操作无法进行!\n\n");
       return 0;
    }
    
    while(choice0)
    {
        printf("请教师选择数据的输入方式\n\n");
        printf("1->直接建立数据\n\n");
        printf("2->文件导入数据\n\n");
        printf("3->退出该界面\n\n");
        scanf("%d",&choice0);
        if(choice0==3)
        return 0;
        if(choice0==1)
        phead=create();
        if(choice0==2)
        phead=daoin();
        choice0=1;
        while(choice2)
        {
           printf("欢迎进入教师管理页面,请选择以下功能!\n");
           printf("         1->查看学生数据\n");
           printf("　　　　 2->修改写入的数据\n");
           printf("         3->添加学生数据\n");
           printf("　　　　 4->删除学生数据\n");
           printf("　　　　 5->对学生数据排序\n");
           printf("         6->把数据写入文件\n");
           printf("         7->查看文件中的数据\n");
           printf("         8->退出该界面\n");
           scanf("%d",&choice2);
           if(choice2==8)
           { 
               printf("感谢您使用,再见!\n");
               return  0;
           }
           switch(choice2)
           {
               case 1 : print(phead);break;
               case 2 : fixdata(phead);break;
               case 3 : adddata(phead);break;
               case 4 : deldata(phead);break;
               case 5 : paixu(phead);break; 
               case 6 : in_file(phead);break;
               case 7 : out_file();break;
               case 8 : printf("感谢您的使用!\n\n");return 0;
           }
        }

    }

}
struct student *create()
{
    struct student *phead=NULL;
    struct student *pnew,*pend;
    int jishu=0;
    pend=pnew=(struct student *)malloc(sizeof(struct student));
    printf("开始输入学生的数据,每输入学生的一个数据,请按enter,系统会提示你该项数据输入完毕!,如果你想终止输入,请在学号处输入stop\n");
    printf("开始输入第 %d 个学生的数据,开始输入学号\n\n",jishu+1);
    scanf("%s",pnew->snum);
    printf("学号输入完毕,开始输入姓名!\n\n");
    scanf("%s",pnew->sname);
    printf("姓名输入完毕!开始输入成绩,成绩和成绩之间用空格分隔!\n\n");
    scanf("%d %d %d %d",&pnew->grade.chinese,&pnew->grade.math,&pnew->grade.picture,&pnew->grade.C_language);
    printf("成绩输入完毕!\n\n");
    pnew->all=(pnew->grade.chinese+pnew->grade.math+pnew->grade.picture+pnew->grade.C_language);
    if(pnew->all>=350)
        pnew->level='A';
            else if(pnew->all>=300)
                pnew->level='B';
                    else if(pnew->all>=250)
                        pnew->level='C';
                            else
                                pnew->level='D';
    while(strcmp(pnew->snum,"stop")!=0)
    {
        jishu++;
        if(jishu==1)
        {
            phead=pnew;
            pend=pnew;
            pnew->next=NULL;
        }
        if(jishu!=1)
        {
            pend->next=pnew;
            pnew->next=NULL;
            pend=pnew;
        }
        pnew=(struct student *)malloc(sizeof(struct student ));
        printf("开始输入第 %d 个学生的数据,开始输入学号\n\n",jishu+1);
        scanf("%s",pnew->snum);
        if(strcmp(pnew->snum,"stop")==0)
        {
          printf("学生信息输入完毕!\n\n");
          return phead;
        }
        printf("学号输入完毕,开始输入姓名!\n\n");
        scanf("%s",pnew->sname);
        printf("姓名输入完毕!开始输入成绩,成绩和成绩之间用空格分隔!\n\n");
        scanf("%d %d %d %d",&pnew->grade.chinese,&pnew->grade.math,&pnew->grade.picture,&pnew->grade.C_language);
        printf("成绩输入完毕!\n\n");
        pnew->all=(pnew->grade.chinese+pnew->grade.math+pnew->grade.picture+pnew->grade.C_language);
        if(pnew->all>=350)
            pnew->level='A';
                else if(pnew->all>=300)
                    pnew->level='B';
                        else if(pnew->all>=250)
                            pnew->level='C';
                                else
                                    pnew->level='D';
    }
    free(pnew);
    return phead;
}
void print(struct student *phead)
{
    struct student *psearch=phead;
    printf("学号　　姓名　语文　　高数　工图　C语言  总成绩　　等级　\n\n");
    while(psearch!=NULL)
    {
        printf("%s  %s  %4d  %4d  %4d  %4d  %4d     %c\n\n",psearch->snum,psearch->sname,psearch->grade.chinese,psearch->grade.math,psearch->grade.picture,psearch->grade.C_language,psearch->all,psearch->level);
        psearch=psearch->next;
    }
    printf("\n信息已经全部展示完毕!\n");
}
void fixdata(struct student *phead)
{
    int choice1=1;
    while(choice1)
    {
        printf("     1->按学号修改:\n\n");
        printf("　　 2->按姓名修改:\n\n");
        printf("　　 3->退出\n\n");
        printf("请输入你的选择:\n\n");
        scanf("%d",&choice1);
        if(choice1==1)
            {
                char num[9];
                printf("请输入要修改的人的学号!\n");
                scanf("%s",num);
                printf("学号输入完毕!\n");
                fixdata1(phead,num);
                return ;
            }
        if(choice1==2)
            {
                char name[25];
                printf("请输入要修改人的姓名!\n");
                scanf("%s",name);
                printf("姓名输入完毕!\n");
                fixdata2(phead,name);
                return ;
            }
        if(choice1==3)
            return ;
    }
}
void fixdata1(struct student *phead,char *s)
{
    struct student *psearch=phead;
    while(psearch!=NULL)
    {
        if(strcmp(psearch->snum,s)==0)
        {
            char isdel[5];
            printf("该生成绩如下:\n\n");
            printf("学号　　姓名　　语文　高数　工图　C语言　总分　等级\n\n");
            printf("%s  %s  %d  %d  %d  %d  %d  %c\n\n",psearch->snum,psearch->sname,psearch->grade.chinese,psearch->grade.math,psearch->grade.picture,psearch->grade.C_language,psearch->all,psearch->level);
            printf("修改? yes or no:\n\n");
            scanf("%s",isdel);
            if(strcmp(isdel,"yes")==0)
            {
                printf("请输入该生的新指标,开始输入学号!\n");
                scanf("%s",psearch->snum);
                printf("学号输入完毕，开始输入姓名!\n");
                scanf("%s",psearch->sname);
                printf("姓名输入完毕,开始输入成绩!\n");
                scanf("%d %d %d %d",&psearch->grade.chinese,&psearch->grade.math,&psearch->grade.picture,&psearch->grade.C_language);
                psearch->all=(psearch->grade.chinese+psearch->grade.math+psearch->grade.picture+psearch->grade.C_language);
                if(psearch->all>=350)
                    psearch->level='A';
                    else if(psearch->all>=300)
                        psearch->level='B';
                            else if(psearch->all>=250)
                             psearch->level='c';
                                else
                                    psearch->level='D';
                printf("该生信息已经全部输入完毕!\n\n");
                return ;
            }
            
        }
        psearch=psearch->next;
    }
    printf("没有找到复合要求的内容!\n\n");
}
void fixdata2(struct student *phead,char *s)
{
    struct student *psearch=phead;
    while(psearch!=NULL)
    {
        if(strcmp(psearch->sname,s)==0)
        {
            char isdel[5];
            printf("该生成绩如下:\n\n");
            printf("学号　　姓名　　语文　高数　工图　C语言　总分　等级\n\n");
            printf("%s  %s  %d  %d  %d  %d  %d  %c\n\n",psearch->snum,psearch->sname,psearch->grade.chinese,psearch->grade.math,psearch->grade.picture,psearch->grade.C_language,psearch->all,psearch->level);
            printf("修改? yes or no:\n\n");
            scanf("%s",isdel);
            if(strcmp(isdel,"yes")==0)
            {
                printf("请输入该生的新指标,开始输入学号!\n");
                scanf("%s",psearch->snum);
                printf("学号输入完毕，开始输入姓名!\n");
                scanf("%s",psearch->sname);
                printf("姓名输入完毕,开始输入成绩!\n");
                scanf("%d %d %d %d",&psearch->grade.chinese,&psearch->grade.math,&psearch->grade.picture,&psearch->grade.C_language);
                psearch->all=(psearch->grade.chinese+psearch->grade.math+psearch->grade.picture+psearch->grade.C_language);
                if(psearch->all>=350)
                    psearch->level='A';
                    else if(psearch->all>=300)
                        psearch->level='B';
                            else if(psearch->all>=250)
                             psearch->level='c';
                                else
                                    psearch->level='D';
                printf("该生信息已经全部输入完毕!\n\n");
                return ;
            }
            
        }
        psearch=psearch->next;
    }
    printf("没有找到复合要求的内容!\n\n");
}
void adddata(struct student *phead)
{
    int choice1=1;
    while(choice1)
    {
        printf("请输入你的选择!\n");
        printf("1->在第n个人之后添加成员:\n");
        printf("2->在某个叫xxx的学生之后添加成员!\n");
        printf("3->退出该界面!\n");
        scanf("%d",&choice1);
        if(choice1==1)
        {
            int n;
            printf("请输入n值:\n");
            scanf("%d",&n);
            adddata1(phead,n);
        }
        if(choice1==2)
        {
            char name[25];
            printf("请输入这个人的名字!\n");
            scanf("%s",name);
            adddata2(phead,name);
        }
        if(choice1==3)
        return ;
    }
    
}
void adddata1(struct student *phead,int n)
{
    struct student *psearch=phead;
    struct student *pnew;
      if(n<0)
    {
        printf("您查找的用户不存在,请重新查找!\n\n");
        return ;
    }
    printf("有此学生!\n\n");
    pnew=(struct student *)malloc(sizeof(struct student));
    printf("开始添加学生的信息,请输入学号:\n");
    scanf("%s",pnew->snum);
    scanf("%s",pnew->sname);
    scanf("%d %d %d %d",&pnew->grade.chinese,&pnew->grade.math,&pnew->grade.picture,&pnew->grade.C_language);
    pnew->all=(pnew->grade.chinese+pnew->grade.math+pnew->grade.picture+pnew->grade.C_language);
    if(pnew->all>=350)
        pnew->level='A';
        else if(pnew->all>=300)
            pnew->level='B';
                else if(pnew->all>=250)
                    pnew->level='C';
                    else 
                        pnew->level='D';
    /*if(n>0)
    {
        int i=0;
        for(;i<n;i++)
            psearch=psearch->next;
        pnew->next=psearch->next;
        psearch->next=pnew;
        
    }
    */
    if(n==0)
    {
        pnew->next=phead;
        phead=pnew;
    }
    if(n>0)
    {
        int i=1;
        for(;i<n;i++)
        {
            psearch=psearch->next;
        }
        pnew->next=psearch->next;
        psearch->next=pnew;
    }
    printf("\n学生已经添加完毕!\n\n");
}
void adddata2(struct student *phead,char *name)
{
    struct student *psearch,*pnew;
    psearch=phead;
    while(psearch!=NULL)
    {
        if(strcmp(psearch->snum,name)==0)
        {
            printf("开始输入即将添加的学生的信息!开始输入学号!\n");
            pnew=(struct student *)malloc(sizeof(struct student));
            scanf("%s",pnew->snum);
            printf("学号输入完毕,开始输入姓名:\n\n");
            scanf("%s",pnew->sname);
            printf("姓名输入完毕,开始输入成绩:\n\n");
            scanf("%d %d %d %d",&pnew->grade.chinese,&pnew->grade.math,&pnew->grade.picture,&pnew->grade.C_language);
            printf("成绩输入完毕!\n\n");
            pnew->all=(pnew->grade.chinese+pnew->grade.math+pnew->grade.picture+pnew->grade.C_language);
            if(pnew->all>=350)
                 pnew->level='A';
                 else if(pnew->all>=300)
                    pnew->level='B';
                        else if(pnew->all>=250)
                            pnew->level='C';
                               else 
                                   pnew->level='D';
            pnew->next=psearch->next;
            psearch->next=pnew;
            return ;
        }
        psearch=psearch->next;
    }
    printf("您所查找的学生不存在!\n");

}
void deldata(struct student *phead)
{
    int choice1=1;
    while(choice1)
    {
        printf("请选则选项:\n\n");
        printf("1-按学号删除\n\n");
        printf("2->按姓名删除\n\n");
        printf("3->全部删除！\n\n");
        printf("4->退出这个界面\n\n");
        scanf("%d",&choice1);
        if(choice1==4)
            return ;
        if(choice1==1)
        {
            char num[9];
            printf("请输入学号!\n\n");
            scanf("%s",num);
            deldata1(phead,num);
        }
        if(choice1==2)
        {
            char name[25];
            printf("请输入姓名\n\n");
            scanf("%s",name);
            deldata2(phead,name);
        }
        if(choice1==3)
        {
            char iskong;
            printf("iskong? y or n:\n\n");
            scanf("%c",&iskong);
            if(iskong=='y')
            deldata3(phead);
        }

    }
}
void deldata1(struct student *phead,char *num)
{
    struct student *psearch=phead;
    struct student *pbefore=phead;
    while(psearch!=NULL)
    {  
        char isdel[5];
        if(strcmp(psearch->snum,num)==0&&(psearch==phead))
        {
            printf("isdel? yes or no!\n\n");
            scanf("%s",isdel);
            if(strcmp(isdel,"yes")==0)
            {
                phead=phead->next;
                printf("删除成功!\n\n");
            }
            return;
        }
        if(strcmp(psearch->snum,num)==0&&(psearch!=phead))
        {
            printf("isdel ? yes or no!\n\n");
            scanf("%s",isdel);
            if(strcmp(isdel,"yes")==0)
            {
                pbefore->next=psearch->next;
                free(psearch);
                printf("删除成功!\n\n");
            }
            return ;
        }
        pbefore=psearch;
        psearch=psearch->next;

    }
    printf("无法找到您的选项!请重新输入!\n\n");
}
void deldata2(struct student *phead,char *name)
{
   

    struct student *psearch=phead;
    struct student *pbefore=phead;
    while(psearch!=NULL)
    {   
        char isdel[5];
        if(strcmp(psearch->sname,name)==0&&(psearch==phead))
        {
            printf("isdel? yes or no!\n\n");
            scanf("%s",isdel);
            if(strcmp(isdel,"yes")==0)
            {
                phead=phead->next;
                printf("删除成功!\n\n");
            }
            return;
        }
        if(strcmp(psearch->sname,name)==0&&(psearch!=phead))
        {
            printf("isdel ? yes or no!\n\n");
            scanf("%s",isdel);
            if(strcmp(isdel,"yes")==0)
            {
                pbefore->next=psearch->next;
                free(psearch);
                printf("删除成功!\n\n");
            }
            return ;
        }
        pbefore=psearch;
        psearch=psearch->next;

    }
    printf("无法找到您的选项!请重新输入!\n\n");
}
void sondeldata3(struct student *phead)
{
    if(phead->next==NULL)
     {
         free(phead);
         return ;
     }
    else
        sondeldata3(phead->next);

}
void deldata3(struct student *phead)
{
    char isdelall[5];
    printf("isdelall? yes or no:\n\n\n");
    scanf("%s",isdelall);
    if(strcmp(isdelall,"yes")==0)
    {
        sondeldata3(phead);
        printf("现在信息已经全部删除了\n\n!");
        printf("您可以选择重新建立学生信息或者退出界面!\n\n");
        return ;
    }
    printf("您没有选择删除全部信息!\n\n");
    return ;
}
void paixu(struct student *phead)
{
    int choice1=1;
    while(choice1)
    {
        printf("请输入你的排序选择!\n\n");
        printf("1->按学号排序!\n\n");
        printf("2->按姓名排序\n\n");
        printf("3->按总成绩排序\n\n");
        printf("4->按语文成绩排序\n\n");
        printf("5->按高数成绩排序\n\n");
        printf("6->按工图成绩排序\n\n");
        printf("7->按C语言成绩排序\n\n");
        printf("8->统计总成绩不合格人数!\n\n");
        printf("9->退出该界面!\n\n");
        scanf("%d",&choice1);
        if(choice1==9)
        return ;
        if(choice1==1)
        {
            xuehaopai(phead);
             break;
        }
        if(choice1==2)
        {
            xingmingpai(phead);
            break ;
        }
        if(choice1==3)
        {
            zongpai(phead);
            break;
        }
        if(choice1==4)
        {
            yuwenpai(phead);
            break ;
        }
        if(choice1==5)
        {
            gaoshupai(phead);
            break ;
        }
        if(choice1==6)
        {
            gongtupai(phead);
            break ;
        }
        if(choice1==7)
        {
            Cpai(phead);
            break ;
        }
        if(choice1==8)
        {
            nohegepai(phead);
            break ;
        }

    }
}
void xuehaopai(struct student *phead)
{
    struct student stu[100];
    struct student *psearch=phead;
    struct student temp;

    int renshu=0;
    int i,j;
    for(;psearch!=NULL;)
    {
        stu[renshu++]=*psearch;
        psearch=psearch->next;
    }//renshu代表的就是当前的人数;
    for(i=0;i<renshu-1;i++)
        for(j=i+1;j<renshu;j++)
    {
        if(strcmp(stu[i].snum,stu[j].snum)>0)
        {
            temp=stu[i];
            stu[i]=stu[j];
            stu[j]=temp;
        }
        
    }
    printf("排学号如下!\n\n\n");
    printf("学号　　姓名　　语文　高数　工图　C语言　总成绩　等级\n\n");
    for(i=0;i<renshu;i++)
    printf("%s  %s  %d  %d  %d  %d  %d  %c\n\n",stu[i].snum,stu[i].sname,stu[i].grade.chinese,stu[i].grade.math,stu[i].grade.picture,stu[i].grade.C_language,stu[i].all,stu[i].level);
}
void xingmingpai(struct student *phead)
{
    struct student stu[100];
    struct student *psearch=phead;
    struct student temp;

    int renshu=0;
    int i,j;
    for(;psearch!=NULL;)
    {
        stu[renshu++]=*psearch;
        psearch=psearch->next;
    }//renshu代表的就是当前的人数;
    for(i=0;i<renshu-1;i++)
        for(j=i+1;j<renshu;j++)
           {
               if(strcmp(stu[i].sname,stu[j].sname)>0)
                  {
                      temp=stu[i];
                      stu[i]=stu[j];
                      stu[i]=temp;
                  }
           } 
           
    printf("排姓名如下!\n\n\n");
    printf("学号　　姓名　　语文　高数　工图　C语言　总成绩　等级\n\n");
    for(i=0;i<renshu;i++)
    printf("%s  %s  %d  %d  %d  %d  %d  %c\n\n",stu[i].snum,stu[i].sname,stu[i].grade.chinese,stu[i].grade.math,stu[i].grade.picture,stu[i].grade.C_language,stu[i].all,stu[i].level);
}
void zongpai(struct student *phead)
{
    struct student stu[100];
    struct student *psearch=phead;
    struct student temp;

    int renshu=0;
    int i,j;
    for(;psearch!=NULL;)
    {
        stu[renshu++]=*psearch;
        psearch=psearch->next;
    }//renshu代表的就是当前的人数;
    for(i=0;i<renshu-1;i++)
        for(j=i+1;j<renshu;j++)
    {
        if(stu[i].all<stu[j].all)
        {
            temp=stu[i];
            stu[i]=stu[j];
            stu[j]=temp;
        }
        
    }
    printf("排总成绩如下!\n\n\n");
    printf("学号　　姓名　　语文　高数　工图　C语言　总成绩　等级\n\n");
    for(i=0;i<renshu;i++)
    printf("%s  %s  %d  %d  %d  %d  %d  %c\n\n",stu[i].snum,stu[i].sname,stu[i].grade.chinese,stu[i].grade.math,stu[i].grade.picture,stu[i].grade.C_language,stu[i].all,stu[i].level);
}
void yuwenpai(struct student *phead)
{
    struct student stu[100];
    struct student *psearch=phead;
    struct student temp;

    int renshu=0;
    int i,j;
    for(;psearch!=NULL;)
    {
        stu[renshu++]=*psearch;
        psearch=psearch->next;
    }//renshu代表的就是当前的人数;
    for(i=0;i<renshu-1;i++)
        for(j=i+1;j<renshu;j++)
    {
        if(stu[i].grade.chinese<stu[j].grade.chinese)
        {
            temp=stu[i];
            stu[i]=stu[j];
            stu[j]=temp;
        }
        
    }
    printf("排语文成绩如下!\n\n\n");
    printf("学号　　姓名　　语文　高数　工图　C语言　总成绩　等级\n\n");
    for(i=0;i<renshu;i++)
    printf("%s  %s  %d  %d  %d  %d  %d  %c\n\n",stu[i].snum,stu[i].sname,stu[i].grade.chinese,stu[i].grade.math,stu[i].grade.picture,stu[i].grade.C_language,stu[i].all,stu[i].level);
}
void gaoshupai(struct student *phead)
{
    struct student stu[100];
    struct student *psearch=phead;
    struct student temp;

    int renshu=0;
    int i,j;
    for(;psearch!=NULL;)
    {
        stu[renshu++]=*psearch;
        psearch=psearch->next;
    }//renshu代表的就是当前的人数;
    for(i=0;i<renshu-1;i++)
        for(j=i+1;j<renshu;j++)
    {
        if(stu[i].grade.math<stu[j].grade.math)
        {
            temp=stu[i];
            stu[i]=stu[j];
            stu[j]=temp;
        }
        
    }
    printf("排高数成绩如下!\n\n\n");
    printf("学号　　姓名　　语文　高数　工图　C语言　总成绩　等级\n\n");
    for(i=0;i<renshu;i++)
    printf("%s  %s  %d  %d  %d  %d  %d  %c\n\n",stu[i].snum,stu[i].sname,stu[i].grade.chinese,stu[i].grade.math,stu[i].grade.picture,stu[i].grade.C_language,stu[i].all,stu[i].level);
}
void gongtupai(struct student *phead)
{
    struct student stu[100];
    struct student *psearch=phead;
    struct student temp;

    int renshu=0;
    int i,j;
    for(;psearch!=NULL;)
    {
        stu[renshu++]=*psearch;
        psearch=psearch->next;
    }//renshu代表的就是当前的人数;
    for(i=0;i<renshu-1;i++)
        for(j=i+1;j<renshu;j++)
    {
        if(stu[i].grade.picture<stu[j].grade.picture)
        {
            temp=stu[i];
            stu[i]=stu[j];
            stu[j]=temp;
        }
        
    }
    printf("排工图成绩如下!\n\n\n");
    printf("学号　　姓名　　语文　高数　工图　C语言　总成绩　等级\n\n");
    for(i=0;i<renshu;i++)
    printf("%s  %s  %d  %d  %d  %d  %d  %c\n\n",stu[i].snum,stu[i].sname,stu[i].grade.chinese,stu[i].grade.math,stu[i].grade.picture,stu[i].grade.C_language,stu[i].all,stu[i].level);
}
void Cpai(struct student *phead)
{
    struct student stu[100];
    struct student *psearch=phead;
    struct student temp;

    int renshu=0;
    int i,j;
    for(;psearch!=NULL;)
    {
        stu[renshu++]=*psearch;
        psearch=psearch->next;
    }//renshu代表的就是当前的人数;
    for(i=0;i<renshu-1;i++)
        for(j=i+1;j<renshu;j++)
    {
        if(stu[i].grade.C_language<stu[j].grade.C_language)
        {
            temp=stu[i];
            stu[i]=stu[j];
            stu[j]=temp;
        }
        
    }
    printf("排c语言如下!\n\n\n");
    printf("学号　　姓名　　语文　高数　工图　C语言　总成绩　等级\n\n");
    for(i=0;i<renshu;i++)
    printf("%s  %s  %d  %d  %d  %d  %d  %c\n\n",stu[i].snum,stu[i].sname,stu[i].grade.chinese,stu[i].grade.math,stu[i].grade.picture,stu[i].grade.C_language,stu[i].all,stu[i].level);
}
void nohegepai(struct student *phead)
{
    struct student stu[100];
    struct student *psearch=phead;
    struct student temp;
    struct student *t;
    t=(struct student *)malloc(sizeof(struct student)*50);
    int renshu=0,no=0;;
    int i,j;
    for(;psearch!=NULL;)
    {
        stu[renshu++]=*psearch;
        psearch=psearch->next;
    }//renshu代表的就是当前的人数;
    for(i=0;i<renshu;i++)
    {
      if(stu[i].all<250)
      {
       t[no++]=stu[i];
      }
      
    }
    if(no==0)
    {   
        printf("没有不合格的人数!\n\n");
        return ;
    }
    printf("排不合格人数如下!\n\n\n");
    printf("学号　　姓名　　语文　高数　工图　C语言　总成绩　等级\n\n");
    for(i=0;i<no;i++)
    printf("%s  %s  %d  %d  %d  %d  %d  %c\n\n",t[i].snum,t[i].sname,t[i].grade.chinese,t[i].grade.math,t[i].grade.picture,t[i].grade.C_language,t[i].all,t[i].level);
}







