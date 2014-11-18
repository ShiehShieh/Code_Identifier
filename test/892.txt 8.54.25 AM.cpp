#include <stdio.h>

__int64 x[100001];
__int64 y[100001],p[100001],v[100001];

void sortx(__int64 h,__int64 t)
{
	__int64 t1,t2,t3,t4;
	t1=h;
	t2=t;
	t3=x[(h+t)/2];
	while (t1<t2)
	{
		while (x[t1]<t3)
		{
			t1=t1+1;
		}
		while (x[t2]>t3)
		{
			t2=t2-1;
		}
		if (t1<=t2)
		{
			t4=x[t1];
			x[t1]=x[t2];
			x[t2]=t4;
			t4=y[t1];
			y[t1]=y[t2];
			y[t2]=t4;
			t4=p[t1];
			p[t1]=p[t2];
			p[t2]=t4;
			t4=v[t1];
			v[t1]=v[t2];
			v[t2]=t4;
			t1=t1+1;
			t2=t2-1;
		}
	}
	if (h<t2)
	{
		sortx(h,t2);
	}
	if (t1<t)
	{
		sortx(t1,t);
	}
}

void sorty(__int64 h,__int64 t)
{
	__int64 t1,t2,t3,t4;
	t1=h;
	t2=t;
	t3=y[(h+t)/2];
	while (t1<t2)
	{
		while (y[t1]<t3)
		{
			t1=t1+1;
		}
		while (y[t2]>t3)
		{
			t2=t2-1;
		}
		if (t1<=t2)
		{
			t4=x[t1];
			x[t1]=x[t2];
			x[t2]=t4;
			t4=y[t1];
			y[t1]=y[t2];
			y[t2]=t4;
			t4=p[t1];
			p[t1]=p[t2];
			p[t2]=t4;
			t4=v[t1];
			v[t1]=v[t2];
			v[t2]=t4;
			t1=t1+1;
			t2=t2-1;
		}
	}
	if (h<t2)
	{
		sorty(h,t2);
	}
	if (t1<t)
	{
		sorty(t1,t);
	}
}

int main()
{
	__int64 ax,ay;
	__int64 n;

	scanf("%I64d\n",&n);
	for (__int64 a=0; a<n; ++a)
	{
		scanf("%I64d %I64d %I64d %I64d\n",&x[a],&y[a],&p[a],&v[a]);
	}
	sortx(0,n-1);
	__int64 s=0;
	for (__int64 a=0; a<n; ++a)
	{
		s=s+p[a]*v[a];
	}
	s=(s+1)/2;
	__int64 s2=0;
	for (__int64 a=0; a<n; ++a)
	{
		s2=s2+p[a]*v[a];
		if (s2>=s)
		{
			ax=x[a];
			break;
		}
	}

	sorty(0,n-1);
	s=0;
	for (__int64 a=0; a<n; ++a)
	{
		s=s+p[a]*v[a];
	}
	s=(s+1)/2;
	s2=0;
	for (__int64 a=0; a<n; ++a)
	{
		s2=s2+p[a]*v[a];
		if (s2>=s)
		{
			ay=y[a];
			break;
		}
	}
	printf("%I64d %I64d\n",ax,ay);
	return 0;
}

