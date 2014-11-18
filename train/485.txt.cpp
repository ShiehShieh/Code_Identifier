#include <cstdio>
#include <algorithm>

using namespace std;

const int MaxN = 10000 + 10;
const int MaxT = 100000 + 10;
const int Inf = 0x7fffffff;

struct TPerson
{
	int Start, End, Cost;
};

bool operator < (const TPerson &A, const TPerson &B)
{
	if (A.Start != B.Start)
		return A.Start < B.Start;
	return A.End < B.End;
}

int N, S, E;
TPerson P[MaxN];
int DP[MaxT];
int Tree[MaxT * 4];

void Insert(int Node, int L, int R, int Pos, int To)
{
	Tree[Node] = min(Tree[Node], To);
	if (L == R)
		return;
	int Mid = (L + R) / 2;
	if (Pos <= Mid)
		Insert(Node * 2, L, Mid, Pos, To);
	else
		Insert(Node * 2 + 1, Mid + 1, R, Pos, To);
}

int Query(int Node, int L, int R, int l, int r)
{
	if (L == l && r == R)
		return Tree[Node];
	int Mid = (L + R) / 2;
	if (r <= Mid)
		return Query(Node * 2, L, Mid, l, r);
	else if (l > Mid)
		return Query(Node * 2 + 1, Mid + 1, R, l, r);
	else
		return min(Query(Node * 2, L, Mid, l, Mid), Query(Node * 2 + 1, Mid + 1, R, Mid + 1, r));
}

int main()
{
	scanf("%d%d%d", &N, &S, &E);
	S --;
	E -= S;
	int Pos = 0;
	for (int i = 0; i < N; i ++)
	{
		scanf("%d%d%d", &P[Pos].Start, &P[Pos].End, &P[Pos].Cost);
		P[Pos].Start -= S;
		P[Pos].End -= S;
		if (P[Pos].End < 1)
			continue;
		P[Pos].Start = max(P[Pos].Start, 1);
		P[Pos].End = min(P[Pos].End, E);
		Pos ++;
	}
	N = Pos;
	sort(P, P + N);
	for (int i = 0; i < MaxT; i ++)
		DP[i] = Inf;
	for (int i = 0; i < MaxT * 4; i ++)
		Tree[i] = Inf;
	
	DP[0] = 0;
	Insert(1, 0, E, 0, 0);
	for (int i = 0; i < N; i ++)
	{
		int New = Query(1, 0, E, P[i].Start - 1, E);
		if (New == Inf)
			continue;
		DP[P[i].End] = min(DP[P[i].End], New + P[i].Cost);
		Insert(1, 0, E, P[i].End, DP[P[i].End]);
	}
	printf("%d\n", DP[E] == 0x7fffffff ? -1 : DP[E]);
	//while (1);
	return 0;
}

