/*
https://practice.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays/0/?ref=self

Given two arrays and a number x, find the pair whose sum is closest to x and the pair has an element from each array.

Input:
The first line consists of a single integer T, the number of test cases. For each test case, the first line contains 2 integers n & m denoting the size of two arrays. Next line contains n- space separated integers denoting the elements of array A and next lines contains m space separated integers denoting the elements of array B followed by an integer x denoting the number whose closest sum is to find.

Output:
For each test case, the output is 2 space separated integers whose sum is closest to x.

Constraints:
1<=T<=100
1<=n,m<=50
1<=A[i],B[i]<=500

Example:
Input:
2
4 4
1 4 5 7
10 20 30 40
32
4 4
1 4 5 7
10 20 30 40
50
Output:
1 30
7 40
*/
#include <iostream>
#include <string>
#include <cmath>        // std::abs
using namespace std;

void print(int * ptr, int n);
int max_index(int * ptr, int start, int end);
void swap(int * ptr, int in1, int in2);

void string_to_arr(string s, int *ptr) {
	string subs = "";
	for (string::iterator it = s.begin(); it < s.end(); it++) {
		if (*it >= 48 && *it <= 57)
			subs += *it;
		if (*it == 32 || (it + 1) == s.end()) {
			int element = stoi(subs);
			*ptr = element;
			subs.clear();
			ptr++;
		}
	}
}

void print(int * ptr, int s) {
	for (int i = 0; i < s; i++) {
		cout << *ptr << " ";
		ptr++;
	}
	cout << endl;
}

void selection_sort(int * ptr, int n) {
	for (int i = 0; i < n; i++) {
		int index = max_index(ptr, i, n);
		if (index != -1)
			swap(ptr, i, index);
	}
}

int max_index(int * ptr, int start, int end) {
	int max = *(ptr + start);
	int index = start;
	if (start < end) {
		for (int i = start; i < end; i++) {
			if (*(ptr + i) > max) {
				index = i;
				max = *(ptr + i);
			}
		}
	}
	return index;
}

void swap(int * ptr, int in1, int in2) {
	int temp = *(ptr + in1);
	*(ptr + in1) = *(ptr + in2);
	*(ptr + in2) = temp;
}

string find_elements(int * ptr1, int * ptr2, int n1, int n2, int key) {
	selection_sort(ptr1, n1);
	print(ptr1, n1);
	int num = (*(ptr1 + 0) + *(ptr2 + 0)) - key;
	string out = to_string(*(ptr1 + 0)) + " " + to_string(*(ptr2 + 0));
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; ++j) {
			int delta = (*(ptr1 + i) + *(ptr2 + j)) - key;
			if (abs(delta) <= abs(num)) {
				out.clear();
				out += to_string(*(ptr1 + i)) + " " + to_string(*(ptr2 + j));
				num = delta;
			}
		}
	}
	return out;
}

int main() {
	int T;
	string s;

	cin >> T;
	while (T > 0) {
		int n1 = 0, n2 = 0;
		int key = 0;
		string s1 = "";
		string s2 = "";
		cin >> n1 >> n2;

		while (!s1.length())
			getline(cin, s1);

		while (!s2.length())
			getline(cin, s2);

		cin >> key;

		int * ptr1 = new int[n1];
		int * ptr2 = new int[n2];
		string_to_arr(s1, ptr1);
		string_to_arr(s2, ptr2);

		cout << find_elements(ptr1, ptr2, n1, n2, key) << endl;

		delete[] ptr1;
		delete[] ptr2;
		T--;
	}
	int f;
	cin >> f;
	return 0;
}