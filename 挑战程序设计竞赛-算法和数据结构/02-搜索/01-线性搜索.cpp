#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 10010;
int S[maxn];
int T[maxn];

bool lineSearch(int S[], int n, int key) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (S[i] == key) {
			flag = true;
			break;
		}
	}
	return flag;
}

int main() {
	int n;
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
		if (lineSearch(S, n, T[i]) == true) count++;
	}
	printf("%d\n", count);
	return 0;
}