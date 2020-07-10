#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 100010;
int S[maxn];
int T[maxn];
int n;

int binarySearch(int key) {
	int left = 0;
	int right = n;
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (key == S[mid]) return 1;
		if (key > S[mid]) left = mid + 1;
		else if (key < S[mid]) right = mid;
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &S[i]);
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &T[i]);
	}
	int count = 0;
	for (int i = 0; i < q; i++) {
		if (binarySearch(T[i]) == 1) count++;
	}
	printf("%d\n", count);
	return 0;
}