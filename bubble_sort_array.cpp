/*
Bubble sort implementation as nested loops plus implementation with a flag to reduce number of passes if array is sorted.
*/
#include <iostream>
using namespace std;

void bubble_sort(int arr[], int s);			// implemented with a flag
void bubble_sort1(int arr[], int s);		// implemented as nested loop
void bubble_sort2(int arr[], int s);		// reduced number of passes through array
void swap(int arr[], int in1, int in2);
void print(int arr[], int s);

void swap(int arr[], int in1, int in2) {
	int temp = arr[in1];
	arr[in1] = arr[in2];
	arr[in2] = temp;
}

void print(int arr[], int s) {
	for (int i = 0; i < s; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void bubble_sort(int arr[], int s) {
	bool flag = false;
	int counter = 0;
	while (!flag){
		flag = true;
		cout << "Pass " << counter << endl;
		for (int i = 1; i < s; i++) {
			if (arr[i - 1] > arr[i]){
				swap(arr, i - 1, i);
				flag = false;
			}
			print(arr, s);
		}
		counter++;
	}
}

void bubble_sort1(int arr[], int s){
	int counter = 1; 
	for (int i = 1; i < s; i++) {
		cout << "Pass " << counter << endl;
		for (int j = 1; j < s - i; j++) {
			if (arr[j - 1] > arr[j]) {
				swap(arr, j - 1, j);
			}
			print(arr, s);
		}
		counter++;
	}
}

void bubble_sort2(int arr[], int s) {
	int counter = 1;
	bool flag = false;
	for (int i = 1; i < s; i++) {
		cout << "Pass " << counter << endl;
		for (int j = 1; j < s - i; j++) {
			if (arr[j - 1] > arr[j]) {
				swap(arr, j - 1, j);
				flag = true;
			}
			print(arr, s);
		}
		counter++;
		if (!flag)
			break;
	}
}

//Driver method
int main() {
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Array" << endl;
	print(arr, size);
	cout << "Bubble sort:" << endl;
	bubble_sort(arr, size);
	cout << endl;

	int arr1[] = { 11, 12, 22, 25, 34, 64, 90 };
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	cout << "Array" << endl;
	print(arr1, size1);
	cout << "Bubble sort1:" << endl;
	bubble_sort1(arr1, size1);
	cout << endl;

	int arr2[] = { 11, 12, 22, 25, 34, 64, 90 };
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	cout << "Array" << endl;
	print(arr2, size2);
	cout << "Bubble sort2:" << endl;
	bubble_sort2(arr2, size2);
	cout << endl;
	getchar();
	return 0;
}