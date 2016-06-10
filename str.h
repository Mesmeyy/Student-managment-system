/*************************************************************************
	> File Name: Students_in_and_out_file.c
	> Author:zhuziyu 
	> Mail: 
	> Created Time: 2016年06月01日 星期三 14时10分52秒
 ************************************************************************/

#include<stdio.h>


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
    int all;
    struct student *next;
    
};


