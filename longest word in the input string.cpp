/*
Given a string, we have to find the longest word in the input string and then calculate the number of characters in this word.

Input:
The first line of input contains an integer T,  number of test cases. For each test case, there is a string s.

Output:
For each test case, the output is an integer denoting the length of the longest word in the sentence.

Constraints:
1<=T<=100

Example:
Input:
2
A computer science portal for geeks
I am an intern at geeksforgeeks
Output
8
13
*/

#include <iostream>
#include <string>
using namespace std;

#define N_LETTERS 100

int longest_word(string s, char * ptr) {
	int counter = 0;
	int counter_max = -1;
	for (string::iterator it = s.begin(); it < s.end(); it++){
		if (*it >= 33 && *it <= 126)
			counter++;
		if (*it == 32 && counter_max == -1) {
			counter_max = counter;
			counter = 0;
		}
		else if (((*it == 32) || ((it+1) == s.end())) && counter_max < counter) {
			counter_max = counter;
			counter = 0;
		}
		else if (*it == 32)
			counter = 0;
	}
	return counter_max;
}

int main() {
	int T = 0;
	cin >> T;
	while (T > 0) {
		string s;
		while (!s.length())
			getline(cin, s);
		char * ptr = new char [N_LETTERS];				// a char array to hold separate words
		cout << longest_word(s, ptr) <<endl;
		T--;
	}
	getchar();
	return 0;
}