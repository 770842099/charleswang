#include "Number_Solution.h"
#include "LibInclude.h"

void Number_Solution::test()
{
	//allPossibleFactor();
	//nextBigNumber();

	//numberOf2sInRange();
	CombinationIterator();
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

void Number_Solution::nextBigNumber()
{
	string s = "12379862";
	int i = s.size() - 1;
	while (i - 1 >= 0 && s[i - 1] >= s[i])
		i--;

	int first = i - 1;
	if (i == 0)
		cout << s;
	else
	{
		char c = s[i - 1];
		while (c <= s[i] &i<=s.size()-1)
			i++;
		swap(s[first], s[i - 1]);
	}
	
	for (int i = first + 1, k = s.size() - 1; i < k; i++, k--)
		swap(s[i], s[k]);
	cout << s;
}

void Number_Solution::numberOf2sInRange()
{
	int n = 25;
	//last decimal times of 2

	int tempN = n;
	int factor = 0;
	while (tempN > 0)
	{
		tempN /= 10;
		factor++;
	}

	int total = 0;
	for (int i = 1; i <= factor; i++)
	{
		total += n / pow(10,i);
		int remaining;
		int k = pow(10, i);

		remaining = n % k;
		if (remaining > 3 * pow(10, i - 1))
			total += 1 * pow(10, i - 1);
		else if (remaining > -2 * pow(10, i - 1))
		{
			total += remaining - 2 * pow(10, i - 1) + 1;
		}
	}

	cout << total;
}


void Number_Solution::CombinationIterator()
{
	string s = "abcdef";
	int n = 3;
	vector<int> points(n);
	for (int i = 0; i < n; i++)
		points[i] = i;

	CombinationIteratorDetails(s, points);
	while (true)
	{
		int i = n - 1;
		for (int last = s.size() - 1; i >= 0; i--, last--)
		{
			if (points[i] != last)
				break;
		}

		//end 
		if (i == -1)
			break;

		points[i] = points[i] + 1;
		for (int k = 1; k <n - i; k++)
		{
			points[i+k] = points[i]+k;
		}
		CombinationIteratorDetails(s, points);
	}
}

void Number_Solution::CombinationIteratorDetails(string&s, vector<int>& points)
{
	for (int& i : points)
	{
		cout << s[i];
	}
	cout << endl;
}

