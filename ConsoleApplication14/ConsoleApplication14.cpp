// ConsoleApplication14.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#
#include "LibInclude.h"
#include "string_solution1.h"
#include "Tree_Solution.h"
#include "Greedy_Solution.h"
#include "Recursive_Solution.h"
#include "DP_Solution.h"
#include "Puzzle_Solution.h"
#include "DFS_Solution.h"
#include "Bit_Solution.h"
#include "Array_Solution.h"
#include "Schedule_Solution.h"
#include "Number_Solution.h"
#include "Stradegy_Solution.h"
#include "Map_Solution.h"
#include "Stack_Solution.h"
#include "Sort_Solution.h"
#include "SegmentTree.h"
#include "RangeModule.h"
#include "BFS_Solution.h"
#include "LinkedList_Solution.h"
#include "Hashing.h"
#include "lintcode944.cpp"
#include "GraphSolution.h"
#include "XiongyaliAlgorithm.h"
//
//void print_priority_queue(priority_queue<int>& q)
//{
//	while (!q.empty())
//	{
//		cout << q.top() << endl;
//		q.pop();
//	}
//}
//
////struct compare
////{
////	bool operator()(const int& l, const int& r)
////	{
////		return l > r;
////	}
////};
//
//struct people
//{
//	int age, salary;
//	people(int _age, int _salary)
//	{
//		age = _age; 
//		salary = _salary;
//	}
//
//	bool operator< (const people& e) const
//	{
//		//return (age > e.age && salary > e.salary);
//		return (age < e.age) || ((age==e.age)&&(salary<e.salary));
//	}
//};
//
//struct compare {
//	bool operator()(const people & a, const people & b)
//	{
//		if (a.salary == b.salary)
//		{
//			return a.age > b.age;
//		}
//		else
//		{
//			return a.salary < b.salary;
//		}
//	}
//};
//
//struct compare_priority
//{
//	bool operator()(const people & a, const people & b)
//	{
//		if (a.age == b.age)
//			return a.salary > b.salary;
//		else
//			return a.age > b.age;
//	}
//};
//
//void test_priority_queue()
//{
//	priority_queue<int> q;
//	for (auto i : { 1,1,8,5,6,3,4,0,9,7,2 })
//		q.push(i);
//	print_priority_queue(q);
//
//	priority_queue<int, vector<int>, greater<int>> q2;
//	for (auto i2 : { 1,8,5,6,3,4,0,9,7,2 })
//		q2.push(i2);
//	while (!q2.empty())
//	{
//		cout << q2.top() << endl;
//		q2.pop();
//	}
//
//	//priority_queue<people, vector<people>, compare> p;
//	cout << endl;
//	priority_queue<people, vector<people>, compare_priority> p;
//	p.push(people(25, 2000));
//	p.push(people(28, 3000));
//	p.push(people(29, 4000));
//	p.push(people(30, 4000));
//	p.push(people(30, 5000));
//	p.emplace(34, 444);
//	while (!p.empty())
//	{
//		cout <<p.top().age<<" "<< p.top().salary << endl;
//		p.pop();
//	}
//}
//
//void test_string()
//{
//	string a("12345");
//	string b("28888");
//	
//	cout << atoi(a.c_str())<<endl;
//	cout << stoi(a)<<endl;
//
//	cout << (int)a.at(1) << endl;
//	int k = 333;
//	string c = std::to_string(k);
//	//cout<< stoi(a.at(0))+ ctoi(b.at(0));
//
//	a.append("df");
//	cout << a << endl;
//}
//
//void test_vector()
//{
//	vector<people> v;
//	v.emplace_back(1, 11);
//	v.emplace_back(2, 22);
//	v.emplace_back(3, 33);
//	v.emplace_back(4, 44);
//	cout << v.back().salary << endl;
//
//	for (people& p : v)
//	{
//		cout << p.salary << endl;
//		p.salary += 1000;
//	}
//
//	for (people& p : v)
//	{
//		cout << p.salary << endl;
//	}
//
//	vector<vector<int>> init(32, vector<int>(32,10));
//	init[31][31] = 3;
//}
//
//void test_set()
//{
//	set<int> i;
//	i.insert(1);
//	i.insert(23);
//	i.insert(3);
//	i.insert(4);
//	i.erase(4);
//	for (auto k: i)
//	{
//		cout << k<<endl;
//	}
//	//cout << *(--i.end())<<endl;
//	//cout << *(i.begin())<<endl;
//
//	cout << endl;
//	set<int, std::greater<int>> ibig;
//	ibig.insert(1);
//	ibig.insert(23);
//	ibig.insert(3);
//	ibig.insert(4);
//	for (auto k : ibig)
//	{
//		cout << k << endl;
//	}
//
//
//	set<people> ipeople;
//	people s(33, 333);
//	people s1(44, 333);
//	people s2(441, 222);
//	people s3(442, 222);
//	people s4(443, 222);
//	people s5(444, 222);
//
//	//ipeople.emplace(1, 22);
//	
//	ipeople.insert(s4);
//	ipeople.insert(s1);
//	ipeople.insert(s2);
//	ipeople.insert(s3);
//	ipeople.insert(s);
//	ipeople.insert(s5);
//	//ipeople.erase(s);
//
//	cout << endl;
//	for (auto& k1 : ipeople)
//	{
//		cout << k1.age<< " "<<k1.salary << endl;
//	}
//}
//
//void test_mulitiset()
//{
//	multiset<int> s;
//	cout << endl << "test multiset" << endl;
//	s.insert(1);
//	s.insert(1);
//	s.insert(1);
//	s.insert(2);
//	s.erase(1);
//	for (auto& k : s)
//	{
//		cout << k << endl;
//	}
//
//	cout << endl;
//	multiset<people> a;
//	a.emplace(1, 2);
//	a.emplace(1, 2);
//	a.emplace(1, 2);
//	a.emplace(1, 3);
//	a.erase(people(1,2));
//	for (auto&k2 : a)
//	{
//		cout << k2.salary << endl;
//	}
//}
//
//void test_map()
//{
//	cout << endl;
//	cout << "test map:" << endl;
//	map<string, int, greater<string>> a;
//	a["aaa"] = 1;
//	a["abb"] = 2;
//	a["acc"] = 3;
//	a["acd"] = 4;
//	a["ace"] = 5;
//	cout << a["acc"] << endl;	
//	a.insert(make_pair("dff", 1));
//
//	for (auto& item : a)
//	{
//		cout << item.first<<" "<<item.second<< endl;
//	}
//
//	bool valuefind= a.find("aaa") != a.end();
//	cout << valuefind<<endl;
//
//	bool valuefind2 = a.find("aaa44") != a.end();
//	cout << valuefind2 << endl;
//
//
//	map<int, int> a1;
//	a1[0] = 0;
//	a1[1] = 1;
//	a1[2] = 2;
//	a1[3] = 3;
//	a1[4] = 4;
//	a1[5] = 5;
//	a1[6] = 7;
//	a1[7] = 7;
//	a1[8] = 8;
//	
//	cout << (*a1.lower_bound(7)).second << endl;
//	cout << (*a1.upper_bound(7)).second << endl;
//
//	//cout << (*lower_bound(a1.begin(), a1.end(), 7)).second<<endl;
//	//cout << (*upper_bound(a1.begin(), a1.end(), 7)).second << endl;
//
//}
//
//void test_sort()
//{
//	cout << endl<<"test sort"<<endl;
//	int arr[] = { 10,3,34,434,444,7,6,10 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	sort(arr, arr + n);
//	for (int item : arr)
//	{
//		cout << item << endl;
//	}
//
//	cout << unique(arr, arr + n) - arr<<endl;
//
//	for (int item : arr)
//	{
//		cout << item << endl;
//	}
//
//	sort(arr, arr + n, std::greater<int>());
//	for (int item : arr)
//	{
//		cout << item << endl;
//	}
//	sort(arr, arr + n);
//
//	cout<<binary_search(arr, arr + n, 333)<<endl;
//	cout << binary_search(arr, arr + n, 3) << endl;
//
//	cout << lower_bound(arr, arr + n, 10)-arr<<endl;
//	cout << upper_bound(arr, arr + n, 10) - arr<<endl;
//}
//
//bool cmpGreedyData(GreedyData& first, GreedyData& second)
//{
//	if (first.a == second.a)
//		return first.b < second.b;
//	else
//		return first.a < second.a;
//}
//
//void testcmp()
//{
//	int a[7] = { 1,2,3,4,5,6,7 };
//	int b[7] = { 2,4,6,7,8,9,10 };
//	GreedyData d[7];
//	for (int i = 0; i < 7; i++)
//	{
//		d[i].a = a[i];
//		d[i].b = b[i];
//	}
//	sort(d, d + 7, cmpGreedyData);
//	for (auto& v : d)
//	{
//		cout << v.a << endl;
//	}
//}

int isValid(vector<int> &a) {
	
	// Write your code here
	unordered_set<int> set;

	for (int& i : a)
	{
		if (set.count(i))
			set.erase(i);
		else
			set.insert(i);
	}

	if (set.size() == 1)
		return *set.begin();
	else
		return -1;
}



int main()
{

	//vector<vector<int>> v = { {4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30} };



	//LibHelper::coutVector(nextGreaterElements(input));

	//test_priority_queue();
	//test_string();
	//test_vector();
	//test_set();

	//test_mulitiset();
	//test_map();

	//test_sort();

	//string_solution s_solution;
	//s_solution.leetCode267_CurcleString();
	//s_solution.run();

	//Tree_Solution s;
	//s.test();

	//s.midTraverse(s.init());
	//s.priorMidRecreation();
	//s.NLConstruction();

	//GraphSolution s;
	//s.test();

	//Greedy_Solution s;
	//s.multipleLinksSort();
	//s.testcmp();

	//testcmp();

	//Recursive_Solution s;
	//s.test();

   // DP_Solution dp;
	//dp.test();

    //Puzzle_Solution puzzle;
    //puzzle.test();

	//DFS_Solution dfs;
	//dfs.test();

	//Bit_Solution s;
	//s.test();

	//TrieTree t;
	//t.test();

	//Array_Solution s;
	//s.test();
	//s.kthLargerNumber();

	//Schedule_Solution s;
	//s.test();

	//Number_Solution s;
	//s.test();

	//Stradegy_Solution s;
	//s.test();

	//Map_Solution map;
    //map.test();

	//Stack_Solution s;
	//s.test();

	//Array_Solution s;
	//s.test();

	//Sort_Solution s;
	//s.test();

	//SegmentTree t;
	//t.test();

	//RangeModule m;
	//m.test();

	//BFS_Solution s;
	//s.test();

	//LinkedList_Solution s;
	//s.test();

	//lintcode944 s;
	//s.test();

	//lintcode1456
	//XiongyaliAlgorithm s;
	//string target = "ally";
	//vector<string> words = { "buy", "discard", "lip", "yep" };
	//cout << s.matchFunction(target, words);
}




