/*
https://practice.geeksforgeeks.org/problems/reaching-the-heights/0/?ref=self
Teacher gives a mental ability question to Raju . The question is as follows:-

Raju is in an elevator. Given by his teacher is an array of size N which denotes the number of floors and has a 1 based indexing. The elevator starts from the ground and moves up and down, X and Y floors respectively. There is a code used in the elevator according to which it moves up X floors given at odd indexes of the array and moves down Y floors given at even indexes of the array. He is asked to go to the highest floor possible. Help him to sort the array such that he reaches the highest floor after traversing the whole array from starting till the end, without skipping any index.

He always prefers to move more number of floors up and less number of floors down. Once he gets into the elevator, the elevator should not reach the ground again, if it does print “Not Possible”.

Input:

The first line of input contains an integer T denoting the number of test cases. T test cases follow. The first line of each test case contains N denoting size of the array. The second line of each test case contains elements of the array separated by a single space.


Output:

For each test case, print the sorted array or “Not Possible”.


Constraints:

1 ? T ? 10

1 ? N ? 1000

1 ? X , Y ? 1000

Example:

Input:

2

4

2 3 4 5

2

1 1

Output:

5 2 4 3

Not Possible

Explanation:

Case 1:

Array can be arranged as {5,3,4,2} or {4,3,5,2} or {4,2,5,3} but it will get arranged as {5,2,4,3} because he always prefer to move more number of floors up and less number of floors down.

Case 2:

Not possible.
*/
#include <iostream>
#include <string>
using namespace std;

void print(int * ptr, int n);

void string_to_arr(string s, int *ptr) {
	string subs = "";
	for (string::iterator it = s.begin(); it < s.end(); it++){
		if (*it >= 48 && *it <= 57)
			subs += *it;
		if (*it == 32 || (it+1) == s.end()) {
			int element = stoi(subs);
			*ptr = element;
			subs.clear();
			ptr++;
		}
	}
}

void bubble_sort(int *ptr, int s) {
	print(ptr, s);
	bool flag = true;
	for (int j = 0; j < s; j++) {
		for (int i = 1; i < s - j; i++) {
			if (*(ptr + i - 1) > *(ptr + i)) {
				int temp = *(ptr + i - 1);
				*(ptr + i - 1) = *(ptr + i);
				*(ptr + i) = temp;
				flag = false;
			}
			if (flag)
				break;
		}
	}
	print(ptr, s);
}

/* sort in descending order */
void bubble_sort_r(int *ptr, int s) {
	//print(ptr, s);
	bool flag = true;
	for (int j = s-1; j >= 0; j--) {
		for (int i = s-j-1; i >= 1; i--) {
			if (*(ptr + i - 1) < *(ptr + i)) {
				int temp = *(ptr + i - 1);
				*(ptr + i - 1) = *(ptr + i);
				*(ptr + i) = temp;
				flag = false;
			}
			if (flag)
				break;
		}
	}
	//print(ptr, s);
}

void print(int * ptr, int s) {
	for (int i = 0; i < s; i++) {
		cout << *ptr << " ";
		ptr++;
	}
	cout << endl;
}

string elevator(int * ptr, int n) {
	string out = "";
	int num = 0;
	if (n % 2) {
		for (int i = 0; i <= (n /2); i++) {
			num += *(ptr + i);
			out += to_string(*(ptr + i)) + ' ';
			if ((num - *(ptr + n - 1 - i)) > 0 && i != n - 1 - i) {
				out += to_string(*(ptr + n - 1 - i)) + ' ';

				num -= *(ptr + n - 1 - i);
			}
			else if ((num - *(ptr + n - 1 - i)) == 0 && i != n - 1 - i) {
				out = "Not Possible";
				return out;
			}
		}
	}
	else {
		for (int i = 0; i < (n / 2); i++) {
			num += *(ptr + i);
			out += to_string(*(ptr + i)) + ' ';
			if (num - *(ptr + n - 1 - i) > 0 && i != n - 1 - i) {
				out += to_string(*(ptr + n - 1 - i)) + ' ';
				num -= *(ptr + n - 1 - i);
			}
			else if ((num - *(ptr + n - 1 - i)) == 0 && i != n - 1 - i) {
				out = "Not Possible";
				return out;
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
		int n = 0;
		string s = "";
		cin >> n;
		while (!s.length())
			getline(cin, s);

		if (n > 1) {
		int * ptr = new int[n];
		string_to_arr(s, ptr);
		//print(ptr, n);
		bubble_sort_r(ptr, n);
		cout << elevator(ptr, n) << endl;
		delete[] ptr;
		}
		else {
			cout << s << endl;
		}
		T--;
	}
	getchar();
	return 0;
}