#include <iostream>

using namespace std;

#define MAX_INT_LEN	 256

 void mult(char a[], char b[], char s[])

      {

          int i,j,k=0,alen,blen,sum=0,res[MAX_INT_LEN + 1][MAX_INT_LEN + 1]={0},flag=0;

          char result[MAX_INT_LEN + 1];

          alen=strlen(a);blen=strlen(b); 

          for (i=0;i<alen;i++)

          for (j=0;j<blen;j++) res[i][j]=(a[i]-'0')*(b[j]-'0');

          for (i=alen-1;i>=0;i--)

              {

                  for (j=blen-1;j>=0;j--) sum=sum+res[i+blen-j-1][j];

                  result[k]=sum%10;

                  k=k+1;

                  sum=sum/10;

              }

          for (i=blen-2;i>=0;i--)

              {

                  for (j=0;j<=i;j++) sum=sum+res[i-j][j];

                  result[k]=sum%10;

                  k=k+1;

                  sum=sum/10;

              }

          if (sum!=0) {result[k]=sum;k=k+1;}

          for (i=0;i<k;i++) result[i]+='0';

          for (i=k-1;i>=0;i--) s[i]=result[k-1-i];

          s[k]='\0';

          while(1)

              {

              if (strlen(s)!=strlen(a)&&s[0]=='0') 

                  strcpy(s,s+1);

              else

                  break;

              }

      }


int main(int argc, char* argv[])
{
	int n;
	cin>>n;
	int* num = new int[n];
	for(int k=0; k<n; k++)
	{
		num[k] = 0;
	}

	int i = 0;

	int count = 0;
	while(1)
	{
		num[i] = i + 2;
		num[i + 1] = (n - count) - num[i];
		if(num[i] >= num[i + 1])
		{
			break;
		}
		count = count + num[i];
		i++;
	}

    int res = 0;
	if(i == 0)
	{
		res = 2;
		if(num[0] > num[1])
		{
			int temp = num[0];
			num[0] = num[1];
			num[1] = temp;
		}
	}
	else if(num[i + 1] == 0)
	{
		res = i + 1;
	}
	else
	{
		res = i + 1;
		count = num[i + 1];
		while(count > 0)
		{
			num[i]++;
			count--;
			i--;
			if(i < 0)
			{
				i = res - 1;
			}
		}
	}

    int j = 0;
	char resBuff[MAX_INT_LEN + 1];
	char buff1[MAX_INT_LEN + 1];
	char buff2[MAX_INT_LEN + 1];
	memset(buff1, 0x00, sizeof(buff1));
	memset(buff2, 0x00, sizeof(buff2));
	memset(resBuff, 0x00, sizeof(resBuff));	

	while(j < res)
	{
		if(j == 0)
		{
		    sprintf(resBuff, "%d", num[j]);
		}
		else
		{
			strcpy(buff1, resBuff);
			sprintf(buff2, "%d", num[j]);
		
			mult(buff1, buff2, &resBuff[0]);
		}
		cout<<num[j]<<" ";
		j++;
	}
	cout<<endl<<resBuff<<endl;

	return 0;
}
