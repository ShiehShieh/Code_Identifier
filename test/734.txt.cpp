#include <iostream>

using namespace std;

unsigned add(unsigned nA, unsigned nB)
{
	return unsigned(nA + nB);
	
}

int main()
{
	unsigned nInput1, nInput2;

	cin >> nInput1 >> nInput2;

	if (nInput1 < 0 || nInput1 >32767 || nInput2 < 0 || nInput2 >32767)
	{
		exit(1);
	}

	unsigned result = add(nInput1,nInput2);

	cout << result << endl;

	return 0;
}


