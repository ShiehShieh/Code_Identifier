#include<iostream.h>
#include<string.h>
int main(){
int N=0;
int n=0,award=0;
int maxaward=0;
char name[21];
char maxname[21];
char * point;
float termscore;
float gradescore;
char title;
char address;
int papernumbers;

cin>>N;
for(int i=1;i<=N;i++){
award=0;
cin>>name;
cin>>termscore;
cin>>gradescore;
cin>>title;
cin>>address;
cin>>papernumbers;
if(termscore>80 && papernumbers>=1){
award=award+8000;

} if(termscore>85 && gradescore>80){
award=award+4000;

} if (termscore>90){
award=award+2000;

} if(termscore>85 && (address=='Y')){
award=award+1000;

} if(gradescore>80 && (title=='Y')){
award=award+850;

}
if(award>maxaward){
maxaward=award;
strcpy(maxname,name);
}
n=n+award;
}

point=&maxname[0];
cout<<point<<endl;
cout<<maxaward<<endl;
cout<<n<<endl;
return 0;
}
