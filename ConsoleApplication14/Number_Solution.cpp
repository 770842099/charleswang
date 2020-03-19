#include "Number_Solution.h"
#include "LibInclude.h"

void Number_Solution::test()
{
	allPossibleFactor();
}


void Number_Solution::allPossibleFactor()
{
	int n = 56*3;
	vector<int> result;
	allPossibleFactorDetails(n, 2, result);
}

void Number_Solution::allPossibleFactorDetails(int remaining, int last, vector<int> result)
{
	if (!result.empty() && remaining >= result[result.size() - 1])
	{
		for (int v : result)
		{
			cout << v << " ";
		}
		cout << remaining << endl;
	}


	for (int divided = last; divided <= remaining; divided++)
	{
		if (remaining%divided == 0)
		{
			if (remaining / divided >= last)
			{
				result.push_back(divided);
				allPossibleFactorDetails(remaining / divided, divided, result);
				result.pop_back();
			}
		}
	}
}

