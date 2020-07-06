#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 10010;
int A[maxn];

int bubbleSort(int A[], int n) {
	int count = 0;
	bool flag = true;
	for (int i = 0; flag; i++) {
		flag = false;
		for (int j = n-1; j >= i+1; j--) {
			if (A[j] < A[j-1]) {
				swap(A[j], A[j-1]);
				flag = true;
				count++;
			}
		}
	}
	return count;
}


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}	
		int res = bubbleSort(A, n);
		for (int i = 0; i < n; i++) {
			if (i > 0) printf(" ");
			printf("%d", A[i]);
		}
		printf("\n");
		printf("%d\n", res);
	}
	return 0;
}