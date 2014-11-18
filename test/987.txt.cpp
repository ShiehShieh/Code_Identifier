#include <queue>
//#include <string>
#include <iostream>
#define MAXSIZE 362880
using namespace std;

bool T[MAXSIZE];
struct Status{
	int state;
	int step;
	Status(){ state = 0; step = 0; }
};

long long ZeroToNine( long long num )
{
	long long result = 0;
	long long i = 0, digit = 10;
	for ( i = 0; i < 9; i++ )
	{
		if ( num%10 == 0 )
		{
			result += 9*(digit/10);
		}
		else
		{
			result += (num%10)*(digit/10);
		}
		digit *= 10;
		num /= 10;
	}
	return result;
}

int Fac(int n)
{
	int result = 1;
	for ( ; n >= 2; n-- )
		result *= n;
	return result;
}
int Cantor( long long num )
{
	bool Hash[10];
	int result = 0;
	int digit = 100000000;
	int t = 0, p = 0;
	int i = 0, j = 0;
	for ( i = 8; i > 0; i-- )
	{
		t = num/digit;
		num-=t*digit;
		digit/=10;

		for ( j = 1, p = t-1; j <= t-1; j++ )
			if ( Hash[j] == true )
				p--;
		Hash[t] = true;

		result += p*Fac(i);
	}
	return result;
}
long long OPA( long long num, int Pos )
{
	long long result = 0;
	long long dig = 1, i = 0;
	for ( i = 0; i < Pos; i++ )
		dig *= 10;
	int a = (num/(dig*1000))%10;
	int b = (num/(dig))%10;
	result = num + (b-a)*(dig*1000) + (a-b)*dig;
	return result;
}
long long OPB( long long num, int Pos )
{
	long long result = 0;
	long long dig = 1, i = 0;
	for ( i = 0; i < Pos; i++ )
		dig *= 10;
	int a = (num/(dig*10))%10;
	int b = (num/(dig))%10;
	result = num + (b-a)*(dig*10) + (a-b)*dig;
	return result;
}
long long OPC( long long num, int Pos )
{
	int result = 0;
	int dig = 1, i = 0;
	for ( i = 0; i < Pos; i++ )
		dig *= 10;
	int a = (num/(dig/10))%10;
	int b = (num/(dig))%10;
	result = num + (b-a)*(dig/10) + (a-b)*dig;
	return result;
}
long long OPD( long long num, int Pos )
{
	int result = 0;
	int dig = 1, i = 0;
	for ( i = 0; i < Pos; i++ )
		dig *= 10;
	int a = (num/(dig/1000))%10;
	int b = (num/(dig))%10;
	result = num + (b-a)*(dig/1000) + (a-b)*dig;
	return result;
}

int main()
{
	int N = 0;
	int i = 0;
//	scanf("%d", &N);
//	for ( i = 0; i < N; i++ )
//	{
		queue<Status> Q1;
		//queue<Status> Q2;
		long long target = 0;
		int  j = 0, k = 0;
		bool solvable = false;
		int Buf[10];
	//	for ( j = 0; j < 9; j++ )
	//		scanf("%d", &Buf[j]);
		//int d = 1;
	//	for ( j = 8; j >= 0; j-- )
		//{
	//		target += Buf[j]*d;
	//		d *= 10;
		//}
		scanf("%lld", &target);
		Status front1, front2, New;
		long long temp = 0, index = 0;

		for ( j = 0; j < MAXSIZE; j++ )
			T[j] = false;
		front1.state = 123894765;
		Q1.push(front1);
		target = ZeroToNine( target );
	//	front2.state = target;
	//	Q2.push(front2);
		T[Cantor(123894765)] = true;
		while ( !Q1.empty() /*&& !Q2.empty()*/ )
		{
			front1 = Q1.front();
		//	front2 = Q2.front();
			if ( front1.state == target/*== front2.state*/ )
			{
				printf("%d\n", front1.step /*+ front2.step*/);
				solvable = true;
				break;
			}

			for ( j = 0, temp = front1.state; j < 9; j++ )
			{
				if ( temp%10 == 9 )
					break;
				temp/=10;
			}
			
			if ( j <= 5 )
			{
				New.state = OPA( front1.state, j );
				index = Cantor(New.state);
				if ( T[index] == false )
				{
					New.step = front1.step + 1;
					Q1.push(New);
					T[index] = true;
				}
			}
			
			if ( j != 8 && j != 5 && j != 2 )
			{
				New.state = OPB( front1.state, j );
				index = Cantor(New.state);
				if ( T[index] == false )
				{
					New.step = front1.step + 1;
					Q1.push(New);
					T[index] = true;
				}
			}

			if ( j != 6 && j != 3 && j != 0 )
			{
				New.state = OPC( front1.state, j );
				index = Cantor(New.state);
				if ( T[index] == false )
				{
					New.step = front1.step + 1;
					Q1.push(New);
					T[index] = true;
				}
			}

			if ( j >= 3 )
			{
				New.state = OPD( front1.state, j );
				index = Cantor(New.state);
				if ( T[index] == false )
				{
					New.step = front1.step + 1;
					Q1.push(New);
					T[index] = true;
				}
			}

			/*for ( j = 0, temp = front2.state; j < 9; j++ )
			{
				if ( temp%10 == 9 )
					break;
				temp/=10;
			}
			
			if ( j <= 5 )
			{
				New.state = OPA( front2.state, j );
				index = Cantor(New.state);
				if ( T[index] == false )
				{
					New.step = front2.step + 1;
					Q1.push(New);
					T[index] = true;
				}
			}
			
			if ( j != 8 && j != 5 && j != 2 )
			{
				New.state = OPB( front2.state, j );
				index = Cantor(New.state);
				if ( T[index] == false )
				{
					New.step = front2.step + 1;
					Q1.push(New);
					T[index] = true;
				}
			}

			if ( j != 6 && j != 3 && j != 0 )
			{
				New.state = OPC( front2.state, j );
				index = Cantor(New.state);
				if ( T[index] == false )
				{
					New.step = front2.step + 1;
					Q1.push(New);
					T[index] = true;
				}
			}

			if ( j >= 3 )
			{
				New.state = OPD( front2.state, j );
				index = Cantor(New.state);
				if ( T[index] == false )
				{
					New.step = front2.step + 1;
					Q1.push(New);
					T[index] = true;
				}
			}*/

			Q1.pop();
		//	Q2.pop();
		}
		if ( solvable == false )
			printf("-1\n");
//	}
	return 0;
}


