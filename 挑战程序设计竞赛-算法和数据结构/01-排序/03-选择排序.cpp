#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 10010;
int A[maxn];

int selectSort(int A[], int n) {
	int count = 0;
	int temp;
	for (int i = 0; i < n-1; i++) {
		int k = i;
		for (int j = i; j < n; j++) {
			if (A[j] < A[k]) {
				k = j;
			}
		}
		temp = A[i];
		A[i] = A[k];
		A[k] = temp;
		if (i != k) count++;
	}
	return count;
}



int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}	
		int res = selectSort(A, n);
		for (int i = 0; i < n; i++) {
			if (i > 0) printf(" ");
			printf("%d", A[i]);
		}
		printf("\n");
		printf("%d\n", res);
		
	}
	return 0;
}