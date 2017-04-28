///�ļ����ƶȷ���

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

///�˵�
void menu()
{
    printf("\n ================================================================\n");
    printf("�U\t\t\t���ж������ļ������ƶȡ�\t\t�U\n");
    printf("�U--------------------------------------------------------------�U\n");
    printf("�U\t\t\t(1):ѡ���ļ�1&&�ļ�2\t\t\t�U     \n");
    printf("�U\t\t\t(2):�ж��ļ�������\t\t\t�U          \n");
    printf("�U\t\t\t(3):�ļ�1����Ϣ\t\t\t\t�U          \n");
    printf("�U\t\t\t(4):�ļ�2����Ϣ\t\t\t\t�U          \n");
    printf("�U\t\t\t(5):��ʾ�ļ�1 \t\t\t\t�U          \n");
    printf("�U\t\t\t(6):��ʾ�ļ�2 \t\t\t\t�U          \n");
    printf("�U\t\t\t(7):�˳�      \t\t\t\t�U          \n");
    printf(" ================================================================\n");
    printf("��ѡ��:\t");
}

///�������ļ��Ĳ�������һ��
void File_0()
{
    File_1();
    File_2();
}

///���ļ�1
void File_1()
{
    int i=0;
    printf("������Ҫ�򿪵��ļ��� 1����·����: ");
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
            printf("�ɹ����ļ�%s��\n\n",file1);
            for(i=0;(a[i]=fgetc(pa))!=EOF;i++)
                ;
            a[i]='\0';
        }
    fclose(pa);
}

///���ļ�2
void File_2()
{
    int i=0;
    printf("������Ҫ�򿪵��ļ��� 2����·����: ");
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
            printf("�ɹ����ļ�%s��\n\n",file2);
            for(i=0;(b[i]=fgetc(pb))!=EOF;i++)
                ;
            b[i]='\0';
        }
    fclose(pb);
}

///ѡ��������˳��ĺ�����
void Deal()
{
    char i;
    printf("����������y,�˳�������n\t:");
    i=getchar();
    while(getchar()!='\n')
        continue;
    while(i!='y')
    {
        if(i=='n') exit(0);
        else
            {
                printf("Error!@*#!  ����������y,�˳�������n :");
                i=getchar();
                while(getchar()!='\n')
                    continue;
            }
    }
}

///���ļ��������ƶȷ���
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
    printf("�������ļ���ͬ�ĵ�����:%d\n",t);
    double N=(1.0*t/num)*100.0;
    printf("���ƶ�Ϊ:%5.2lf%%\n",N);
    if(N>=80)
        printf("���ļ����ƶȴ���80%%�����������ļ�:   ��ͬ!!\n");
    else printf("���ļ����ƶ�С��80%%�����������ļ�:   ��ͬ!!\n");
    Deal();
}

///�������ļ��е��ܵ�����
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
    printf("�ļ�%s����%d�����ʣ��ļ�%s����%d�����ʣ���%d�����ʡ�\n",file1,num1,file2,num2,num);
}



///���ļ�1���е���Ϣ�Ĵ���
void Fileline1()
{
    FILE *fp;
    int i=0,j=1,t=0;
    int chars=0,words=0,space=0,lines=1;
    char c;
    if((fp=fopen(file1,"r"))==NULL)
    {
        printf("���ļ�%sʧ�ܣ�\n",file1);
        exit(0);
    }
    printf("\n�ļ�%s:\n",file1);
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
            printf("��%d��:\t������%d;\t �ַ�����%d\n",lines,words,chars);
            lines++;
        }
        if(c==EOF)
            j=0;
    }
    printf("��%d��:\t������%d;\t �ַ�����%d\n",lines,words,chars);
    printf("��������%d\n\n",lines);
    fclose(fp);
    Deal();
}

///���ļ�2���е���Ϣ�Ĵ���
void Fileline2()
{
    FILE *fp;
    int i=0,j=1,t=0;
    int chars=0,words=0,space=0,lines=1;
    char c;
    if((fp=fopen(file2,"r"))==NULL)
    {
        printf("���ļ�%sʧ�ܣ�\n",file2);
        exit(0);
    }
    printf("\n�ļ�%s:\n",file2);
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
            printf("��%d��:\t������%d;\t �ַ�����%d\n",lines,words,chars);
            lines++;
        }
        if(c==EOF)
            j=0;
    }
    printf("��%d��:\t������%d;\t �ַ�����%d\n",lines,words,chars);
    printf("��������%d\n\n", lines);
    fclose(fp);
    Deal();
}

///����ļ�1������
void Showfile1()
{
    FILE *fp;
    char ch;
    if((fp=fopen(file1,"r"))==NULL)
    {
        printf("���ļ�%sʧ�ܣ�\n",file1);
        exit(0);
    }
    printf("\n�ļ�%s:\n",file2);
    while((ch=fgetc(fp))!=EOF)
        printf("%c",ch);
    printf("\n\n\n");
    fclose(fp);
    Deal();
}

///����ļ�2������
void Showfile2()
{
    FILE *fp;
    char ch;
    if((fp=fopen(file2,"r"))==NULL)
    {
        printf("���ļ�%sʧ�ܣ�\n",file2);
        exit(0);
    }
    printf("\n�ļ�%s:\n",file2);
    while((ch=fgetc(fp))!=EOF)
        printf("%c",ch);
    printf("\n\n\n");
    fclose(fp);
    Deal();
}
