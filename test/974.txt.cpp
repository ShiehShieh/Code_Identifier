#include<iostream>
using namespace std;	
char s[1000],x;
int main()
{

	int i,l,t=0;
	scanf("%s",s); 
	l=strlen(s);
	for(i=0;i<l;i++)
	{ if(s[i]=='.')break;if(s[i]!='0')t=1;}
		  l=i;
		  i=0;
		  if(s[0]=='-'){printf("F");i=1;l--;}
		  if(s[0]=='+'){i=1;l--;}
		  while(s[i]=='0'){i++;l--;}
		  if(t==1)
		  {
			  if(l>=9)
			  {
				  if(l>9){printf("%cS",s[i++]);l--;}
				  if(s[i]!='0')printf("%c",s[i++]);l--;
				  printf("Y");
			  }
			  if(l>4)
			  {
				  if(s[i]=='0'){while(s[i]=='0'&&l>4){i++;l--;}if(l>4)printf("0");}
				  if(l==8&&s[i]!='0'){printf("%cQ",s[i++]);l--;}
				  if(s[i]=='0'&&l>4){while(s[i]=='0'&&l>4){i++;l--;}if(l>4)printf("0");if(l==4)printf("W");}
				  if(l==7&&s[i]!='0'){printf("%cB",s[i++]);l--;}
				  if(s[i]=='0'&&l>4){while(s[i]=='0'&&l>4){i++;l--;}if(l>4)printf("0");if(l==4)printf("W");}
				  if(l==6&&s[i]!='0'){printf("%cS",s[i++]);l--;}
				  if(s[i]=='0'&&l>4){while(s[i]=='0'&&l>4){i++;l--;}if(l>4)printf("0");if(l==4)printf("W");}
				  if(l==5&&s[i]!='0'){printf("%cW",s[i++]);l--;}
			  }
			  if(l>=1)
			  {
				  if(s[i]=='0'){while(s[i]=='0'&&l>0){i++;l--;}if(l>0)printf("0");}
				  if(l==4&&s[i]!='0'){printf("%cQ",s[i++]);l--;}
				  if(s[i]=='0'){while(s[i]=='0'){i++;l--;}if(l>0)printf("0");}
				  if(l==3&&s[i]!='0'){printf("%cB",s[i++]);l--;}
				  if(s[i]=='0'){while(s[i]=='0'){i++;l--;}if(l>0)printf("0");}
				  if(l==2&&s[i]!='0'){printf("%cS",s[i++]);l--;}
				  if(s[i]=='0'){while(s[i]=='0'){i++;l--;}if(l>0)printf("0");}
				  if(l==1&&s[i]!='0'){printf("%c",s[i++]);l--;}
			  }
		  }
		  else {printf("0");}
		  if(s[i]=='.'&&s[i+1]!='\0'){printf("D");i++;}
		  if(s[i]=='.'&&s[i+1]=='\0')return 0;
		  while(s[i]!='\0'){printf("%c",s[i++]);}
		  printf("\n");
		  return 0;
}

