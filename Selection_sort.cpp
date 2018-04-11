#include <iostream>
using namespace std;

//find min element within specific boundaries of an array
int min(int arr[], int s, int e);

//print array
void print(int arr[], int s);

//swap array elements
void swap(int arr[], int s, int index1, int index2);

//selection sort
void selection_sort(int arr[], int s);

int min(int arr[], int s, int e) {
	int min = arr[s];
	int index = -1;
	if (s < e) {
		for (int i = s + 1; i < e; i++) {
			if (arr[i] < min){
				min = arr[i];
				index = i;
			}
		}
	}
	return index;
}

void print(int arr[], int s) {
	for (int i = 0; i < s; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int arr[], int s, int index1, int index2) {
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

void selection_sort(int arr[], int s) {
	int index = 0;

	for (int i = 0; i < s; i++) {
		index = min(arr, i, s);
		if (!(index == -1)) {
			swap(arr, s, i, index);
		}
		print(arr, s);
	}
}

//Driver
int main() {
	int arr[5] = { 64, 25, 12, 22, 11 };

	selection_sort(arr, 5);

	getchar();
}