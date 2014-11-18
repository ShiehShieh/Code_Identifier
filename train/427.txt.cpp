#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int count;
    cin>>count;
    char nameList[count][21];
    int mark1[count];
    int mark2[count];
    char isCadre[count + 1];
    char isWest[count + 1];
    int  paperNum[count];
    int award[count];
    int awardCount = 0;
    
    for(int i=0; i < count; i++)
    {
        cin>>nameList[i]>>mark1[i]>>mark2[i]>>isCadre[i]>>isWest[i]>>paperNum[i];
    }

    for(int j=0; j < count; j++)
    {
        award[j] = 0;
        if(mark1[j] > 80 && paperNum[j] >= 1)
        {
            award[j] = award[j] + 8000;
        }
        if(mark1[j] > 85 && mark2[j] > 80)
        {
            award[j] = award[j] + 4000;
        }
        if(mark1[j] > 90)
        {
            award[j] = award[j] + 2000;
        }
        if(mark1[j] > 85 && isWest[j] == 'Y')
        {
            award[j] = award[j] + 1000;
        }
        if(mark2[j] > 80 && isCadre[j] == 'Y')
        {
            award[j] = award[j] + 850;
        }
        awardCount = awardCount + award[j];
    }

    int indexOfBest = 0;
    int highestAward = 0;
    for(int k=0; k < count; k++)
    {
        if(highestAward < award[k])
        {
            indexOfBest = k;
            highestAward = award[k];
        }
    }

    cout<<nameList[indexOfBest]<<endl<<award[indexOfBest]<<endl<<awardCount<<endl;

    return 0;
}
