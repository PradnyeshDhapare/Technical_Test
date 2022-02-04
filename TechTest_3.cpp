
#include <bits/stdc++.h>
using namespace std;




/* Function to print all combinations of
sum of perfect squares equal to N */
void Combination(
	vector<int> L1, int N,
	int ind, vector<int> PS)
{

	/* Sum of perfect squares exceeded N */
	if (N < 0 || ind == L1.size())
	{
		return;
	}

	/* Sum of perfect squares is equal to N
	therefore a combination is found */
	if (N == 0)
	{
		
		
		for (int i : PS)
		{
			cout << sqrt(i) << " ";
		}
		
		cout << endl;
		
		return;
		
	}
	/* Do not include the current element */
	Combination(L1, N,ind + 1, PS);

	/* Include the element at current index */
	PS.push_back(L1[ind]);

	Combination(L1, N - L1[ind],ind, PS);

	/* Remove the current element */
	PS.pop_back();
	
}
	

/* Function to check whether the
number is a perfect square or not */
void PerfectSquare(int N)
{

	/* Initialize an arrayL1 to store
	 all perfect squares less than N */
	vector<int> L1;
	int sqrtN = (int)(sqrt(N));

	/* Iterate till square root of N */
	for (int i = 2; i <= sqrtN; i++)
	{

		/* Add all perfect squares
		to the L1 */
		L1.push_back(i*i);
	}
	vector<int> PS;
	Combination(L1, N, 0,PS);
}

/* Driver code */
int main()
{
	
	int N = 255;

	/* Call the function */
	PerfectSquare(N);
	
	return 0;
}

