/*
https://practice.geeksforgeeks.org/problems/divisor-product/0/?ref=self
Ishaan is playing with divisors of a number N. He is curious about the product of all these divisors. Given a number N, help him find the product of all the divisors of N (including N).
Since the products can be large, print the answer modulo (10^9 + 7).
Note : Since N takes large values, brute force won't work.

Input :
First line of input contains a single integer T denoting the number of test cases.
The only line of each test case contains an integer N.

Output :
For each test case, print the required answer in a new line.

Constraints :
1 <= T <= 200
1 <= N <= 10^9

Example :
Input :
3
6
9
12
Output :
36
27
1728

Explanation :
Case 1 :
Divisors of 6 : 1, 2, 3, 6
Product = 1*2*3*6 = 36

Case 2 :
Divisors of 9 : 1, 3, 9
Product = 1*3*9 = 27

Case 3 :
Divisors of 12 : 1, 2, 3, 4, 6, 12
Product = 1*2*3*4*6*12 = 1728
*/
#include <iostream>
#include <cmath> 
#include <math.h>
#define M 1000000007

using namespace std;

unsigned long long divisers(unsigned long num) {
	unsigned long long product = 1;
	for (long int i = 1; i <= sqrt(num); i++) {
		if (num%i == 0) {
			if (num / i == i)
				product =(product * i)% M;
			else {
				product = (product * i) % M;
				product = (product * (num/i)) % M;
			}
		}

	}
	return product;
}

int main() {
	int T = 0;
	cin >> T;
	while (T>0) {
		unsigned long num = 0;
		cin >> num;
		cout << divisers(num) << endl;
		T--;
	}
	getchar();
	return 0;
}