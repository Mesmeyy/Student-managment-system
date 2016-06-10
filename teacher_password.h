/*************************************************************************
	> File Name: teacher_password.c
	> Author:zhuziyu 
	> Mail: 
	> Created Time: 2016年06月05日 星期日 21时26分43秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
struct pa
{
    char pass[7];
};

int  infile()
{
    struct pa *password;
    //password=(struct pa *)malloc(sizeof(struct pa));
    char passw[7];
    char pass1[7];
    char pass2[7];
    int i=1;
    char path[50];
    FILE *fp;
    int num;
    printf("如果您已经修改过密码,请按1!没有修改过,请按2\n\n");
    scanf("%d",&num);
    if(num==1)
    {
      return 1;
    }
    for(i=1;i<=3;i++)
    {
        printf("请修改密码,默认密码是111111\n\n\n");
        printf("请输入密码\n\n");
        scanf("%s",passw);
        if(strcmp(passw,"111111")==0)
        {
            printf("请输新密码\n\n");
            scanf("%s",pass1);
            printf("请再次确定新密码\n\n");
            scanf("%s",pass2);
            if(strcmp(pass1,pass2)==0)
            {
                password=(struct pa *)malloc(sizeof(struct pa));
                strcpy(password->pass,pass2);
                //printf("所输入的数据如下!\n\n");
                //printf("%s",password->pass);
                printf("现在将数据写入文件!\n\n");
                printf("请输入文件路径或名称!\n\n");
                //printf("所输入的数据如下!\n\n");
                scanf("%s",path);
                while((fp=fopen(path,"wb"))==NULL)
                {
                    printf("文件路径错误或者文件名称错误!请从新尝试!\n\n");
                    scanf("%s",path);
                    printf("%s\n\n",path);                
                }
                
                fwrite(password,sizeof(struct pa),1,fp);
                fclose(fp);
                printf("所输入的数据如下!\n\n");
                printf("%s\n\n",password->pass);
                printf("数据写入完毕!\n\n");
                return 1;

            }
            else
            printf("两次输入内容不一致,没有效果,请重新尝试!\n\n\n");
        
        }
    }
   return 1;
}
int  outfile()
{
    char  duiying[7];
    FILE *fp;
    char  p[50];
    int i=1;
    printf("请输入查找是否与您信息匹配的文件路径或名称!\n\n");

    do
    {
        if(i>=2)
        printf("请再次输该文件的路径和信息!\n\n");
        scanf("%s",p);
        printf("您所输入的路径是: %s\n\n",p);
        fp=fopen(p,"r");
        i++;
    }while(fp==NULL);
    struct pa *napath;
    napath=(struct pa *)malloc(sizeof(struct pa));
    printf("lalala");
    while(fread(napath,sizeof(struct pa),1,fp)!=0)
    {
        int i=1;
        for(i=1;i<=3;i++)
            {
                printf("请输入密码!\n\n");
                scanf("%s",duiying);
                if(strcmp(duiying,napath->pass)==0)
                {
                    return 1;
                }
            }
        printf("3次密码均错误!\n\n");
        return 0;
    }
    
    printf("文件打开失败!\n\n");
    return 0;

}

