/*
Given an array of n distinct integers. The problem is to find the sum of minimum absolute difference of each array element. 
For an element x present at index i in the array its minimum absolute difference is calculated as:
Min absolute difference (x) = min(abs(x – arr[j])), where 1 <= j <= n and j != i and abs is the absolute value.
Input Constraint: 2 <= n
*/

#include <iostream>
using namespace std;

int element_min_abs_difference(int arr[], int s);

int element_min_abs_difference_sort(int arr[], int s);

int min(int arr[], int start, int end);

void swap(int arr[], int index1, int index2);

void print(int arr[], int s);

int element_min_abs_difference(int arr[], int s) {
	int sum_min_diff = 0;
	for (int i = 0; i < s; i++) {
		int difference = -1;
		for (int j = 0; j < s; j++) {
			if (difference == -1 && j != i)
				difference = abs(arr[i] - arr[j]);
			else if (j != i && difference > abs(arr[i] - arr[j])) {
				difference = abs(arr[i] - arr[j]);
			}		
		}
		//cout << difference << " ";
		sum_min_diff += difference;
	}
	return sum_min_diff;
}

int element_min_abs_difference_sort(int arr[], int s) {
	// selection sort an array first
	int min_index = 0;
	for (int i = 0; i < s; i++) {
		min_index = min(arr, i, s);
		if (!(i == min_index))
			swap(arr, i, min_index);
		//print(arr, s);
	}


	// find min difference for every element 
	int min_diff = 0;
	min_diff = abs(arr[0] - arr[1]) + abs(arr[s-1] - arr[s - 2]);
	for (int i = 1; i < (s - 1); i++) {
		if (abs(arr[i] - arr[i - 1]) > abs(arr[i] - arr[i + 1]))
			min_diff += abs(arr[i] - arr[i + 1]);
		else
			min_diff += abs(arr[i] - arr[i - 1]);
	}
	return min_diff;
}

int min(int arr[], int start, int end) {
	int index = start;
	if (start < end) {
		int temp = arr[start];
		for (int i = (start+1); i < end; i++) {
			if (arr[i] < temp) {
				index = i;
				temp = arr[i];
			}
		}
	}
	return index;
}

void swap(int arr[], int index1, int index2) {
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

void print(int arr[], int s) {
	for (int i = 0; i < s; i++) {
		cout << arr[i] << " ";
	}
	cout << ";" << endl;
}

//Driver method
int main() {
	int arr[] = { 12, 10, 15, 22, 21, 20, 1, 8, 9 };
	cout << element_min_abs_difference(arr, 9) << endl;

	cout << element_min_abs_difference_sort(arr, 9) << endl;
	getchar();
}