#include <iostream>
#include <cstdio>
using namespace std;

/*

快速排序

*/

int Parition(int A[], int left, int right) {
	int temp = A[left];
	while (left < right) {
		while (left < right && A[right] > temp) right--;
		A[left] = A[right];
		while (left < right && A[left] <= temp) left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}

void quickSort(int A[], int left, int right) {
	if (left < right) {
		int pos = Parition(A, left, right);
		quickSort(A, left, pos - 1);
		quickSort(A, pos + 1, right);
		
	}
}


int main(int argc, char *argv[]) {
	
}