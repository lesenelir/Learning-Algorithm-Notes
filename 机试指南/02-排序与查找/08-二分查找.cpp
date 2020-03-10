#include <iostream>
#include <cstdio>
using namespace std;

/*

查找 （二分查找） P38

*/

const int maxn = 1010;

int BinarySearch(int a[], int n, int x) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == x) {
			return mid;
		} else if (a[mid] > x) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1; // 查找失败
}


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[maxn];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			if (BinarySearch(a, n, x) != -1) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
		
	}
}