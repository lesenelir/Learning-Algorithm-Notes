#include <iostream>

using namespace std;

int paration(int a[], int left, int right) {
	int temp = a[left];
	while (left < right) {
		while (left < right && a[right] > temp) right--;
		a[left] = a[right];
		while (left < right && a[left] < temp) left++;
		a[right] = a[left];
	}
	//此时left与right相遇
	a[left] = temp;
	return left;
}

void quicksort(int a[], int left, int right) {
	if (left < right) {
		int pos = paration(a, left, right);
		quicksort(a, left, pos-1);
		quicksort(a, pos+1, right);
	}
}

int main(int argc, char *argv[]) {
	int a[5] = {5, 7, 9, 3, 2};
	quicksort(a, 0, 4);
	for (int i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}	
}