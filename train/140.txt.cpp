#include<stdio.h>
#include<string.h>
char dic[27];
int chrcmp(char ch1,char ch2)
{
  int i;
  if(ch1==ch2)return 0;
  if(ch1==0)return 1;
  if(ch2==0)return -1;
  for(i=0;i<26;++i)
  {
    if(dic[i]==ch1)return 1;
    if(dic[i]==ch2)return -1;
  }
  return -2;
}
int cmp(char* str1,char* str2)
{
  int i=0;
  while(i<256&&!chrcmp(str1[i],str2[i])){i++;}
  return chrcmp(str1[i],str2[i]);
}
int main()
{
  scanf("%s",dic);
  int n;
  scanf("%d",&n);
  int i,j;
  char tmp[256];
  char res[1000][256]={0};
  for(i=0;i<n;++i)
  {
    scanf("%s",tmp);
    for(j=0;j<n;++j)
    {
      if(!res[j][0])
      {
        strcpy(res[j],tmp);
        break;
      }
      if(cmp(res[j],tmp)!=1)
      {
        memmove(res[j+1],res[j],sizeof(char)*(999-j)*256);
        strcpy(res[j],tmp);
        break;
      }
    }
  }
  int st;
  scanf("%d",&st);
  if(st)
    for(i=0;i<n;printf("%s\n",res[i++]));
  else
    for(i=n;i;printf("%s\n",res[--i]));
  return 0;
}

