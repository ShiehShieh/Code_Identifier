#include <cstdio>
#include <cstring>

const int MaxLen = 100;
const int Base = 1000000000;

struct TBigInt
{
	int Len;
	int Data[MaxLen];
	TBigInt (int _Data = 0)
	{
		Len = (_Data != 0);
		Data[0] = _Data;
	}
	TBigInt& operator = (const TBigInt &T)
	{
		Len = T.Len;
		memcpy(Data, T.Data, Len * sizeof(int));
		return *this;
	}
};

bool operator == (const TBigInt &A, const TBigInt &B)
{
	if (A.Len != B.Len)
		return 0;
	for (int i = A.Len - 1; i >= 0; i --)
		if (A.Data[i] != B.Data[i])
			return 0;
	return 1;
}

bool operator != (const TBigInt &A, const TBigInt &B)
{
	if (A.Len != B.Len)
		return 1;
	for (int i = A.Len - 1; i >= 0; i --)
		if (A.Data[i] != B.Data[i])
			return 1;
	return 0;
}

bool operator < (const TBigInt &A, const TBigInt &B)
{
	if (A.Len != B.Len)
		return A.Len < B.Len;
	for (int i = A.Len - 1; i >= 0; i --)
		if (A.Data[i] != B.Data[i])
			return A.Data[i] < B.Data[i];
	return 0;
}

bool operator <= (const TBigInt &A, const TBigInt &B)
{
	if (A.Len != B.Len)
		return A.Len < B.Len;
	for (int i = A.Len - 1; i >= 0; i --)
		if (A.Data[i] != B.Data[i])
			return A.Data[i] < B.Data[i];
	return 1;
}

bool operator > (const TBigInt &A, const TBigInt &B)
{
	if (A.Len != B.Len)
		return A.Len > B.Len;
	for (int i = A.Len - 1; i >= 0; i --)
		if (A.Data[i] != B.Data[i])
			return A.Data[i] > B.Data[i];
	return 0;
}

bool operator >= (const TBigInt &A, const TBigInt &B)
{
	if (A.Len != B.Len)
		return A.Len > B.Len;
	for (int i = A.Len - 1; i >= 0; i --)
		if (A.Data[i] != B.Data[i])
			return A.Data[i] > B.Data[i];
	return 1;
}

TBigInt operator + (const TBigInt &A, const TBigInt &B)
{
	TBigInt Ans;
	int i, Carry = 0;
	for (i = 0; i < A.Len || i < B.Len || Carry; i ++)
	{
		if (i < A.Len)
			Carry += A.Data[i];
		if (i < B.Len)
			Carry += B.Data[i];
		Ans.Data[i] = Carry;
		Carry = 0;
		if (Ans.Data[i] > Base)
		{
			Ans.Data[i] -= Base;
			Carry = 1;
		}
	}
	Ans.Len = i;
	return Ans;
}

TBigInt operator - (const TBigInt &A, const TBigInt &B) // A > B
{
	TBigInt Ans;
	int i, Carry = 0;
	Ans.Len = A.Len;
	for (i = 0; i < Ans.Len; i ++)
	{
		Ans.Data[i] = A.Data[i] - Carry;
		if (i < B.Len)
			Ans.Data[i] -= B.Data[i];
		if (Ans.Data[i] < 0)
		{
			Carry = 1;
			Ans.Data[i] += Base;
		}
		else
			Carry = 0;
	}
	while (Ans.Len && Ans.Data[Ans.Len - 1] == 0)
		Ans.Len --;
	return Ans;
}

TBigInt operator * (const TBigInt &A, const int B)
{
	if (B == 0)
		return 0;
	TBigInt Ans;
	int i;
	long long Carry = 0;
	for (i = 0; i < A.Len || Carry; i ++)
	{
		if (i < A.Len)
			Carry += A.Data[i] * (long long) B;
		Ans.Data[i] = Carry % Base;
		Carry /= Base;
	}
	Ans.Len = i;
	return Ans;
}

TBigInt operator * (const TBigInt &A, const TBigInt &B)
{
	if (B.Len == 0)
		return 0;
	TBigInt Ans;
	long long Carry = 0;
	for (int i = 0; i < A.Len; i ++)
	{
		Carry = 0;
		for (int j = 0; j < B.Len || Carry; j ++)
		{
			if (j < B.Len)
				Carry += A.Data[i] * (long long) B.Data[j];
			if (i + j < Ans.Len)
				Carry += Ans.Data[i + j];
			Ans.Data[i + j] = Carry % Base;
			if (i + j == Ans.Len)
				Ans.Len ++;
			Carry /= Base;
		}
	}
	return Ans;
}

TBigInt operator / (const TBigInt &A, const int B)
{
	TBigInt Ans;
	long long Carry = 0;
	for (int i = A.Len - 1; i >= 0; i --)
	{
		Carry = Carry * Base + A.Data[i];
		Ans.Data[i] = Carry / B;
		Carry %= B;
	}
	Ans.Len = A.Len;
	while (Ans.Len && Ans.Data[Ans.Len - 1] == 0)
		Ans.Len --;
	return Ans;
}

TBigInt operator / (const TBigInt &A, const TBigInt &B)
{
	TBigInt Ans, Carry;
	int Left, Right, Mid;
	for (int i = A.Len - 1; i >= 0; i --)
	{
		Carry = Carry * Base + A.Data[i];
		Left = 0;
		Right = Base - 1;
		while (Left < Right)
		{
			Mid = (Left + Right + 1) >> 1;
			if (B * Mid <= Carry)
				Left = Mid;
			else
				Right = Mid - 1;
		}
		Ans.Data[i] = Left;
		Carry = Carry - B * Left;
	}
	Ans.Len = A.Len;
	while (Ans.Len && Ans.Data[Ans.Len - 1] == 0)
		Ans.Len --;
	return Ans;
}

TBigInt operator % (const TBigInt &A, const TBigInt &B)
{
	TBigInt Ans, Carry;
	int Left, Right, Mid;
	for (int i = A.Len - 1; i >= 0; i --)
	{
		Carry = Carry * Base + A.Data[i];
		Left = 0;
		Right = Base - 1;
		while (Left < Right)
		{
			Mid = (Left + Right + 1) >> 1;
			if (B * Mid <= Carry)
				Left = Mid;
			else
				Right = Mid - 1;
		}
		Ans.Data[i] = Left;
		Carry = Carry - B * Left;
	}
	return Carry;
}

char Buf[1000];

void Input(TBigInt &A)
{
	TBigInt Ans;
	scanf("%s", &Buf);
	for (int i = 0; Buf[i]; i ++)
		Ans = Ans * 10 + (Buf[i] - '0');
	A = Ans;
}

void Print(const TBigInt &A)
{
	printf("%d", A.Data[A.Len - 1]);
	for (int i = A.Len - 2; i >= 0; i --)
		printf("%09d", A.Data[i]);
}

TBigInt Gcd(TBigInt A, TBigInt B)
{
	return (A.Len == 0) ? B : Gcd(B % A, A);
}

TBigInt Lcm(TBigInt A, TBigInt B)
{
	TBigInt GCD = Gcd(A, B);
	TBigInt Mul = A * B;
	return (A * B) / GCD;
}

int main()
{
	TBigInt A, B;
	Input(A);
	Input(B);
	Print(Lcm(A, B));
	printf("\n");
	return 0;
}

