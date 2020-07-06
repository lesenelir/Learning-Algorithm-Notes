#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 10010;
int A[maxn];

void trace(int A[], int n) {
	for (int i = 0; i < n; i++) {
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}

void insertionSort(int A[], int n) {
	for (int i = 1; i < n; i++) {
		int temp = A[i];
		int j = i - 1; // j从i往前枚举
		while (j >= 0 && A[j] > temp) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = temp;
		trace(A, n);
	}
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}	
		trace(A, n);
		insertionSort(A, n);
	}
	
	return 0;
}



