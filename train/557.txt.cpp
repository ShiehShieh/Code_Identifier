#include<iostream>
#include<string>
using namespace std;
#define era_se era##se

string&cvt_st(string&s,int n,bool f) {
    int h=n/10%10,l=n%10,a;
    if(a=n/1000000000) cvt_st(s,a,false)+=" billion ",n%=1000000000;
    if(a=n/1000000%1000) cvt_st(s,a,true)+=" million ",n%=1000000;
    if(a=n/1000%1000) cvt_st(s,a,true)+=" thousand ",n%=1000;
    if(a=n/100%10) cvt_st(s,a,false)+=" hundred ",n%=100;
    if(f&&(h||l)&&s.length()) s+="and ";
    switch(h) {
    case 9: (s+="nine")+="ty";break;
    case 8: s+="eighty";break;
    case 7: s+="seventy";break;
    case 6: s+="sixty";break;
    case 5: s+="fifty";break;
    case 4: s+="forty";break;
    case 3: s+="thirty";break;
    case 2: s+="twenty";break;
    case 1: switch(l) {
            case 9: (s+="nine")+="teen";break;
            case 8: s+="eighteen";break;
            case 7: s+="seventeen";break;
            case 6: s+="sixteen";break;
            case 5: s+="fifteen";break;
            case 4: s+="fourteen";break;
            case 3: s+="thirteen";break;
            case 2: s+="twelve";break;
            case 1: s+="eleven";break;
            case 0: s+="ten";
            } break;
    case 0: switch(l) {
            case 9: s+="nine";break;
            case 8: s+="eight";break;
            case 7: s+="seven";break;
            case 6: s+="six";break;
            case 5: s+="five";break;
            case 4: s+="four";break;
            case 3: s+="three";break;
            case 2: s+="two";break;
            case 1: s+="one";
            }
    } if(h>=2&&l) cvt_st(s+='-',l,false);
    for(a=s.length()-1;s[a]==' ';s.era_se(a--,1));
    return s;
}

int main() {
    int n;
    string s;
    cin>>n;
    cout<<cvt_st(s,n,true);
    return 0;
}

