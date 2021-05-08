#include<stdio.h>
#include<string.h>

int main(int n, char *t[])
{
	FILE *fp;
	int count=0;
	if ((fp=fopen(t[2], "r")) == NULL)
    {
        puts("error!\n");
        return 0;
    }
	if(t[1][1]=='w')
	{
		char s[1000];
		while(fscanf(fp,"%s",s) != EOF)
		{
			count++;
			for(int i=0;i<strlen(s)-1;i++)
			{
				if (s[i]==',' && s[i-1] != ',' && s[i+1] != ',')
				{
					count++;
				}
			}
		}
		printf("单词数=%d\n",count);
	}
	else if(t[1][1]=='c')
	{
		char c;
		while((c=fgetc(fp))!= EOF)
		{
			count++;
		}
		printf("单词数=%d\n",count);
	}
	
	fclose(fp);
	return 0;
} 
