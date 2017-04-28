///文件相似度分析

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define M 1000000

void menu();
void File_0();
void File_1();
void File_2();
void Deal();
void Analyze( );
void Numbers();
void Fileline1();
void Fileline2();
void Showfile1();
void Showfile2();

FILE *pa,*pb;
char a[M],b[M],file1[100],file2[100];
int num;

int main()
{
    char w;
    while(w!='7')
    {
        menu();
        scanf("%c",&w);
        while(getchar()!='\n')
            continue;
        switch (w)
        {
            case '1':     File_0();break;
            case '2':     Analyze();break;
            case '3':     Fileline1();break;
            case '4':     Fileline2();break;
            case '5':     Showfile1();break;
            case '6':     Showfile2();break;
            case '7':     break;
            default:    printf("Error!@*#!\n");Deal();
        }
        continue;
    };
    return 0;
}

///菜单
void menu()
{
    printf("\n ================================================================\n");
    printf("║\t\t\t【判断两个文件的相似度】\t\t║\n");
    printf("║--------------------------------------------------------------║\n");
    printf("║\t\t\t(1):选择文件1&&文件2\t\t\t║     \n");
    printf("║\t\t\t(2):判断文件相似性\t\t\t║          \n");
    printf("║\t\t\t(3):文件1行信息\t\t\t\t║          \n");
    printf("║\t\t\t(4):文件2行信息\t\t\t\t║          \n");
    printf("║\t\t\t(5):显示文件1 \t\t\t\t║          \n");
    printf("║\t\t\t(6):显示文件2 \t\t\t\t║          \n");
    printf("║\t\t\t(7):退出      \t\t\t\t║          \n");
    printf(" ================================================================\n");
    printf("请选择:\t");
}

///将打开两文件的操作合在一起
void File_0()
{
    File_1();
    File_2();
}

///打开文件1
void File_1()
{
    int i=0;
    printf("请输入要打开的文件名 1（含路径）: ");
    scanf("%s",file1);
    while(getchar()!='\n')
        continue;
    if((pa=fopen(file1,"r"))==NULL)
    {
        printf("Error!@*#!\n\n");
        exit(0);
    }
    else
        {
            printf("成功打开文件%s！\n\n",file1);
            for(i=0;(a[i]=fgetc(pa))!=EOF;i++)
                ;
            a[i]='\0';
        }
    fclose(pa);
}

///打开文件2
void File_2()
{
    int i=0;
    printf("请输入要打开的文件名 2（含路径）: ");
    scanf("%s",file2);
    while(getchar()!='\n')
            continue;
    if((pb=fopen(file2,"r"))==NULL)
    {
        printf("Error!@*#!\n\n");
        exit(0);
    }
    else
        {
            printf("成功打开文件%s！\n\n",file2);
            for(i=0;(b[i]=fgetc(pb))!=EOF;i++)
                ;
            b[i]='\0';
        }
    fclose(pb);
}

///选择继续或退出的函数体
void Deal()
{
    char i;
    printf("继续请输入y,退出请输入n\t:");
    i=getchar();
    while(getchar()!='\n')
        continue;
    while(i!='y')
    {
        if(i=='n') exit(0);
        else
            {
                printf("Error!@*#!  继续请输入y,退出请输入n :");
                i=getchar();
                while(getchar()!='\n')
                    continue;
            }
    }
}

///对文件进行相似度分析
void Analyze()
{
    char str1[100],str2[100];
    int i=0,j=0,t=0,s1,s2;
    while(1)
    {
        for(s1=0;(a[i]!=32&&a[i]!=0);i++)
            if(isalpha(a[i]))
            {
                str1[s1]=a[i];
                s1++;
            }
        str1[s1]='\0';
        j=0;
        while(1)
        {
            for(s2=0;(b[j]!=32&&b[j]!=0);j++)
                if(isalpha(b[j]))
                {
                    str2[s2]=b[j];
                    s2++;
                }
            str2[s2]='\0';
            if(strcmp(str1,str2)==0)
            {
                t++;
                break;
            }
            j++;
            if(b[j]==0)
                break;
        }
        i++;
        if(a[i]==0)
            break;
    }
    Numbers();
    printf("其中两文件相同的单词数:%d\n",t);
    double N=(1.0*t/num)*100.0;
    printf("相似度为:%5.2lf%%\n",N);
    if(N>=80)
        printf("两文件相似度大于80%%，理论上两文件:   相同!!\n");
    else printf("两文件相似度小于80%%，理论上两文件:   不同!!\n");
    Deal();
}

///分析两文件中的总单词数
void Numbers()
{
    int num1=0,num2=0,i=0,j=0,t=0,length1,length2;

    length1=strlen(a);
    for (i=0;i<=length1;i++)
    {
        if(isalpha(a[i])&&t==0)
        {
            num1++;
            t=1;
        }
        if(!isalpha(a[i]))
                t=0;
    }
    t=0;
    length2=strlen(b);
    for(j=0;j<=length2;j++)
    {
        if(isalpha(b[j])&&t==0)
        {
            num2++;
            t=1;
        }
        if(!isalpha(b[j]))
            t=0;
    }
    num=num1+num2;
    printf("文件%s中有%d个单词，文件%s中有%d个单词，共%d个单词。\n",file1,num1,file2,num2,num);
}



///对文件1的行的信息的处理
void Fileline1()
{
    FILE *fp;
    int i=0,j=1,t=0;
    int chars=0,words=0,space=0,lines=1;
    char c;
    if((fp=fopen(file1,"r"))==NULL)
    {
        printf("打开文件%s失败！\n",file1);
        exit(0);
    }
    printf("\n文件%s:\n",file1);
    chars=words=space=0;
    while(j)
    {
        for(chars=0,words=0;(((c=getc(fp))!='\n')&&(c!=EOF));chars++,i++)
        {
            if(isalpha(c)&&t==0)
            {
                words++;
                t=1;
            }
            if(!isalpha(c))
                t=0;
        }
        if(c=='\n')
        {
            t=0;
            printf("第%d行:\t词数：%d;\t 字符数：%d\n",lines,words,chars);
            lines++;
        }
        if(c==EOF)
            j=0;
    }
    printf("第%d行:\t词数：%d;\t 字符数：%d\n",lines,words,chars);
    printf("总行数：%d\n\n",lines);
    fclose(fp);
    Deal();
}

///对文件2的行的信息的处理
void Fileline2()
{
    FILE *fp;
    int i=0,j=1,t=0;
    int chars=0,words=0,space=0,lines=1;
    char c;
    if((fp=fopen(file2,"r"))==NULL)
    {
        printf("打开文件%s失败！\n",file2);
        exit(0);
    }
    printf("\n文件%s:\n",file2);
    chars=words=space=0;
    while(j)
    {
        for(chars=0,words=0;(((c=getc(fp))!='\n')&&(c!=EOF));chars++,i++)
        {
            if(isalpha(c)&&t==0)
            {
                words++;
                t=1;
            }
            if(!isalpha(c))
                t=0;
        }
        if(c=='\n')
        {
            t=0;
            printf("第%d行:\t词数：%d;\t 字符数：%d\n",lines,words,chars);
            lines++;
        }
        if(c==EOF)
            j=0;
    }
    printf("第%d行:\t词数：%d;\t 字符数：%d\n",lines,words,chars);
    printf("总行数：%d\n\n", lines);
    fclose(fp);
    Deal();
}

///输出文件1的内容
void Showfile1()
{
    FILE *fp;
    char ch;
    if((fp=fopen(file1,"r"))==NULL)
    {
        printf("打开文件%s失败！\n",file1);
        exit(0);
    }
    printf("\n文件%s:\n",file2);
    while((ch=fgetc(fp))!=EOF)
        printf("%c",ch);
    printf("\n\n\n");
    fclose(fp);
    Deal();
}

///输出文件2的内容
void Showfile2()
{
    FILE *fp;
    char ch;
    if((fp=fopen(file2,"r"))==NULL)
    {
        printf("打开文件%s失败！\n",file2);
        exit(0);
    }
    printf("\n文件%s:\n",file2);
    while((ch=fgetc(fp))!=EOF)
        printf("%c",ch);
    printf("\n\n\n");
    fclose(fp);
    Deal();
}
