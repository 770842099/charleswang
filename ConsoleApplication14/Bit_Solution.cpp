#include "Bit_Solution.h"
#include "LibInclude.h"

void Bit_Solution::test()
{
	AllCombition();
}

void Bit_Solution::AllCombition()
{
	int a[5] = { 1,2,3,4,5 };

	int length = sizeof(a) / sizeof(a[0]);
	int n = 1<<length;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i & 1 << j)
				cout << a[length-j-1]<<" ";
		}
		cout << endl;
	}

}