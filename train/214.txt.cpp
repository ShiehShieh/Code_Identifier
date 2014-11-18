#include<iostream>
using namespace std;
long a[50010],c[50010],s[50010];
void sort(long l,long r)
{
 if (l>=r) return;
 long mid=(l+r)/2;
 sort(l,mid);sort(mid+1,r);
 long ll=l,rr=mid+1;
 while (ll<=mid&&rr<=r)
 if (a[s[ll]]>a[s[rr]]) {c[ll+rr-mid-1]=s[ll];ll++;} else if (a[s[ll]]==a[s[rr]]&&s[ll]<s[rr]) {c[ll+rr-mid-1]=s[ll];ll++;} else {c[ll+rr-mid-1]=s[rr];rr++;}
 while (ll<=mid) {c[ll+rr-mid-1]=s[ll];ll++;}
 while (rr<=r) {c[ll+rr-mid-1]=s[rr];rr++;}
 for (long i=l;i<=r;i++) s[i]=c[i];
 return;
}
main()
{
long n,k;
cin>>n>>k;
long e[11];
for (long i=1;i<=10;i++) cin>>e[i];
for (long i=1;i<=n;i++) {cin>>a[i];s[i]=i;}
sort(1,n);
for (long i=1;i<=n;i++) a[s[i]]+=e[(i-1)%10+1];
sort(1,n);
for (long i=1;i<=k;i++) cout<<s[i]<<' ';
cout<<endl;
return 0;
} 
