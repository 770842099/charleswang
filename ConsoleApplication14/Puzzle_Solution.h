#pragma once
#include "LibInclude.h"
class Puzzle_Solution
{
public:
	void test();
	void cal24();
	void calcDetail(float a[], int num, string s[]);

	void hannuoTa();
	void hannuoTaDetail(char start, char b, char s[], int length, int n);

	//leetcode 243
	void allCalculationByBrace();

	//leetcode 659
	void isPossible();

	   //  1  2  3  4  5  6
	   // 20 21 22 23 24  7
	   // 19 32 33 34 25  8
	   // 18 31 36 35 26  9
	   // 17 30 29 28 27 10
	   // 16 15 14 13 12 11
	void printRectangle();

	void getRectangleIndex();
};

