#include <iostream>
#include <string>
using namespace std;
void swap(int ar[], int i1, int i2);
void merge(int ar[], int s, int b, int m, int e);
void print(int ar[], int s, int b, int e);

int mergesort(int ar[], int b, int e, int s) {
	if ((e - b) > 1) {
		int m = b + (e - b) / 2;
		mergesort(ar, b, m, s);
		mergesort(ar, m + 1, e, s);
		merge(ar, s, b, m, e);
	}
	else if ((e - b) == 1 && e < s) {
		if (ar[b] > ar[e])
			swap(ar, b, e);
		return b;
	}
}

void merge(int ar[], int s, int b, int m, int e) {
	//new pointer to store sorted array 
	int * ptr = new int[e - b];
	int k = 0;

	int i = b, j = m + 1;
	while (i <= m && j <= e && j < s) {
		if (ar[i] <= ar[j]) {
			*(ptr + k++) = ar[i];
			i++;
		}
		else if (ar[i] > ar[j]) {
			*(ptr + k++) = ar[j];
			j++;
		}
	}
	while (i <= m) {
		*(ptr + k++) = ar[i++];
	}

	while (j <= e && j < s) {
		*(ptr + k++) = ar[j++];
	}

	k = 0;
	for (int l = b; (l <= e && l < s); l++) {
		ar[l] = *(ptr + k++);
	}
}

void print(int ar[], int s, int b, int e) {
	for (int i = b; (i <= e && i < s); i++) {
		cout << ar[i] << " ";
	}
	cout << "\n";
}

void swap(int ar[], int i1, int i2) {
	int temp = ar[i2];
	ar[i2] = ar[i1];
	ar[i1] = temp;
}

int main() {
	int ar[] = { 38, 27, 43, 3, 9, 82, 10 };
	int s = sizeof(ar) / sizeof(ar[0]);
	mergesort(ar, 0, s - 1, s);
	print(ar, s, 0, s - 1);
	return 0;
}