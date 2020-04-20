#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000001;
int a[maxn];


int main() {
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		bool flag = false;
		for (int i = 0; i < n; i++) { // 查看数组是否有0元素
			if (a[i] == 0) {
				flag = true;
				break;
			}
		}
		if (flag == true) { // 有0元素
			printf("%d\n", a[k-1]);
		} else {
			printf("%d\n", a[k]);
		}
		
	}
	
	
	return 0;
}