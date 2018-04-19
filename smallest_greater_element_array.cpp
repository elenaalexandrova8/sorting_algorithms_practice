/*
https://practice.geeksforgeeks.org/problems/smallest-greater-elements-in-whole-array/0#ExpectOP
Smallest greater elements in whole array
Given an array of n length, and we need to calculate the next greater element for each element in given array. If next greater element is not available in given array then we need to fill ‘_’ at that index place.

Input:
The first line contains an integer T, the number of test cases. For each test case, the first line contains an integer n, the size of the array. Next line contains n space separated integers denoting the elements of the array.

Output:
For each test case, the output is an array that displays next greater element to element at that index.

Constraints:
1<=T<=100
1<=n<=100
1<=Ai<=10^6

Example:
Input
2
9
6 3 9 8 10 2 1 15 7
4
13 6 7 12
Output
7 6 10 9 15 3 2 _ 8
_ 7 12 13
*/
#include <iostream>
#include <string>
using namespace std;

int min_element_index(int * arr, int start, int end);
void swap(int * arr, int index1, int index2);
void selection_sort(int * arr, int s);
void print(int * arr, int s);
void cpy_array(int * arr1, int * arr2, int s);
int find_index(int * arr, int s, int key);
void smallest_greatest(int * arr1, int * arr2, int s);
void string_to_arr(string str, int *ptr);
int num_elements(string str);


int min_element_index(int * arr, int start, int end) {
	int min_index = start;
	if (start < end) {
		for (int i = start + 1; i < end; i++) {
			if (*(arr + i) < *(arr + min_index))
				min_index = i;
		}
	}
	//cout << "Min index " << min_index << endl;
	return min_index;
}

void swap(int * arr, int index1, int index2) {
	int temp = *(arr + index1);
	*(arr + index1) = *(arr + index2);
	*(arr + index2) = temp;
}

void selection_sort(int * arr, int s) {
	for (int i = 0; i < s; i++) {
		swap(arr, i, min_element_index(arr, i, s));
	}
}

void print(int * arr, int s) {
	for (int i = 0; i < s; i++) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

void cpy_array(int * arr1, int * arr2, int s) {
	for (int i = 0; i < s; i++) {
		*(arr2) = *(arr1);
		arr1++;
		arr2++;
	}
}

int find_index(int * arr, int s, int key) {
	int index = -1;
	for (int i = 0; i < s; i++) {
		if (*(arr + i) == key) {
			index = i;
			break;
		}
	}
	return index;
}

void smallest_greatest(int * arr1, int * arr2, int s) {
	cpy_array(arr1, arr2, s);
	print(arr2, s);
	selection_sort(arr2, s);
	print(arr2, s);
	for (int i = 0; i < s; i++) {
			int index = find_index(arr2, s, *(arr1 + i));
			if (index != -1) {
				while (index < (s - 1) && ((*(arr2 + index + 1) <= *(arr2 + index)))/* || (*(arr2 + index + 1)<1))*/) {
					index++;
				}
				if (index < (s - 1) /* && *(arr1 + i) <= 1000000 */)
					cout << *(arr2 + index + 1) << " ";
				else
					cout << "_ ";
			}
	}
	cout << endl;
}

void string_to_arr(string str, int *ptr) {
	string substr;
	int j = 0;
	for (string::iterator it = str.begin(); it < str.end(); ++it) {
		if (((*it >= 48 && *it <= 57) || (*it == 45)) && *it != 32) {
			substr += *it;
		}
		if (((it + 1) == str.end() || *it == 32) && substr != "") {
			int element = stoi(substr);
			*ptr = element;
			ptr++;
			j++;
			substr.clear();
		}
	}
}

int num_elements(string str) {
	int num_elements = 0;
	bool flag = true;
	for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
		if (*it < 48 && *it > 57 && *it != 32) {
			flag = false;
		}
		else if ((*it == 32) || ((it + 1) == str.end())) {
			num_elements++;
			flag = true;
		}
	}
	return num_elements;
}

int main() {
	int T, n;

	cin >> T;										// get #testcases

	while (T >= 1 && T <= 100) {
		cin >> n;
		if (n >= 1 && n <= 100) {
			string str;									// get array
			while (str.length() == 0)
				getline(cin, str);

			int num_el = num_elements(str);				// get number of elements

			int * arr1;
			arr1 = new int[num_el];
			int * arr2;
			arr2 = new int[num_el];

			string_to_arr(str, arr1);

			print(arr1, num_el);

			smallest_greatest(arr1, arr2, num_el);
			delete[] arr1;
			delete[] arr2;
		}
		T--;
	}
	getchar();
	return 0;
}
