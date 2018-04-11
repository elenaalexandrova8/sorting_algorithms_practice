/*
Given an array of strings, sort the array using Selection Sort.
*/

#include <iostream>
#include <string>
using namespace std;

void selection_sort(string arr[], int s);

int min(string arr[], int start, int end);

void swap(string arr[], int index1, int index2);

void print_array(string arr[], int s);

void print_array(string arr[], int s) {
	for (int i = 0; i < s; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(string arr[], int index1, int index2) {
	string temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

int min(string arr[], int start, int end) {
	int min_index = start;
	if (start < end){
		for (int i = (start + 1); i < end; i++) {
			if (arr[min_index].compare(arr[i]) > 0) {
				min_index = i;
			}
		}
	}
	return min_index;
}

void selection_sort(string arr[], int s) {
	int index = 0;
	
	for (int i = 0; i < s; i++) {
		index = min(arr, i, s);
		if (index != i) {
			swap(arr, i, index);
		}
		print_array(arr, s);
	}
}

//Driver
int main() {
	string arr[] = { "paper", "true", "soap", "floppy", "flower" };
	print_array(arr, 5);
	selection_sort(arr, 5);

	string arr1[] = { "GeeksforGeeks", "Practice.GeeksforGeeks", "GeeksQuiz" };
	print_array(arr1, 3);
	selection_sort(arr1, 3);
	getchar();
}