#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 10001;
int a[maxn];
int flag[maxn]; // 标记数组排除重复的元素

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			flag[i] = 1;
		}
		int count = 0;
		for (int i = 0; i < n; i++) { // 对于数组a的i个元素
			for (int j = i+1; j < n; j++) { // 与i元素后面相结合
				for (int k = 0; k < n; k++) { // 从头遍历数组看是否在内
					if (a[k] == a[i] + a[j] && flag[k] == 1) {
						count++;
						flag[k] = 0;
					}
				}
			}
		}
		printf("%d\n", count);
	}
	
	return 0;
}