#pragma once
#include "LibInclude.h"

class lintcode944 {
public:

	/**
	 * @param matrix: the given matrix
	 * @return: the largest possible sum
	 */
	//int maxSubmatrix(vector<vector<int>> &matrix) {
	int maxSubmatrix() {
		vector<vector<int>> matrix = {
			{1,3,-1},
			{2,3,-2},
			{-1,-2,-3}
		};
		// write your code here
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}
		int result = 0;

		for (int i = 0; i < matrix.size(); ++i) {
			vector<int> sum(matrix[0].size());
			for (int j = i; j < matrix.size(); ++j) {
				for (int k = 0; k < matrix[0].size(); ++k) {
					sum[k] += matrix[j][k];
				}
				int temp = maxSubarray(sum);
				result = max(result, temp);
			}
		}
		return result;
	}
	int maxSubarray(vector<int> &array) {
		int res = 0, sum = 0;
		for (int i = 0; i < array.size(); ++i) {
			sum += array[i];
			res = max(res, sum);
			sum = max(sum, 0);
		}
		return res;
	}

	void test()
	{
		cout << maxSubmatrix();
	}
};
