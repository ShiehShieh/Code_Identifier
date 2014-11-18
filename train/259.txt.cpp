#include<iostream>
using namespace std;
int main(){
	int a[10];
	int p1,p2,p3,p4,p5,p6,p7,p8,p9=0;
	for(int i=1;i<=9;i++){
		cin>>a[i];
	}
	for(p1=0;p1<=3;p1++)
	for(p2=0;p2<=3;p2++)
	for(p3=0;p3<=3;p3++)
	for(p4=0;p4<=3;p4++)
	for(p5=0;p5<=3;p5++)
	for(p6=0;p6<=3;p6++)
	for(p7=0;p7<=3;p7++)
	for(p8=0;p8<=3;p8++)
	for(p9=0;p9<=3;p9++){
	if(((p1+p2+p4)%4==((4-a[1])%4))&&
			((p1+p2+p3+p5)%4==((4-a[2])%4))&&
			((p2+p3+p6)%4==((4-a[3])%4))&&
			((p1+p5+p4+p7)%4==((4-a[4])%4))&&
			((p1+p3+p5+p7+p9)%4==((4-a[5])%4))&&
			((p3+p5+p6+p9)%4==((4-a[6])%4))&&
			((p4+p7+p8)%4==((4-a[7])%4))&&
			((p5+p7+p8+p9)%4==((4-a[8])%4))&&
			((p6+p8+p9)%4==((4-a[9])%4))==1){
			
			for(int ia=1;ia<=p1;ia++){
				cout<<"1"<<" ";
			}
			for(int ib=1;ib<=p2;ib++){
				cout<<"2"<<" ";
			}
			for(int ic=1;ic<=p3;ic++){
				cout<<"3"<<" ";
			}
			for(int id=1;id<=p4;id++){
				cout<<"4"<<" ";
			}
			for(int ie=1;ie<=p5;ie++){
				cout<<"5"<<" ";
			}
			for(int ig=1;ig<=p6;ig++){
				cout<<"6"<<" ";
			}
			for(int ih=1;ih<=p7;ih++){
				cout<<"7"<<" ";
			}
			for(int ik=1;ik<=p8;ik++){
				cout<<"8"<<" ";
			}
			for(int il=1;il<=p9;il++){
				cout<<"9"<<" ";
			}
		}
	}
	cout<<endl;
	return 0;
}


