#include <iostream>
#include <math.h>

using namespace std;

#define M_PI 3.14159265358979323846 

int main()
{
	int num;
	float r;

	cin>>num>>r;

	float** coList = new float*[num];
	for(int i=0; i<num; i++)
	{
		coList[i] = new float[2];
		coList[i][0] = 0;
		coList[i][1] = 0;
	}

	for(int j=0; j<num; j++)
	{
		cin>>coList[j][0]>>coList[j][1];
	}
	
	cout<<endl;
	float length = 0;
	for(int k=0; k<num; k++)
	{
		if(k != num - 1)
		{
			length += sqrt(pow(coList[k][0] - coList[k + 1][0], 2) + pow(coList[k][1] - coList[k + 1][1], 2));
		}
		else
		{
			length += sqrt(pow(coList[k][0] - coList[0][0], 2) + pow(coList[k][1] - coList[0][1], 2));
		}
	}

	length += 2 * M_PI * r;
	
	printf("%.2f\n", length);

	return 0;
}
