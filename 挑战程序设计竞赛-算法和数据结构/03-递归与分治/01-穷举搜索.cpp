#include <cstdio>
#include <iostream>
using namespace std;


int n;
int A[50];

int solve(int i , int m) {
	if (m == 0) return 1;
	if (i >- n) return 0;
	int res = solve(i + 1, m) || solve(i + 1, m - A[i]);
	return res;
}


int main() {
	int q, M;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &M);
		if (solve(0, M) == 1) printf("YES\n");
		else printf("NO\n");
	}	
	return 0;
}