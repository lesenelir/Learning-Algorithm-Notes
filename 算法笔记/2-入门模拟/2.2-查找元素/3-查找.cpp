#include <iostream>
#include <cstdio>
using namespace std;


/*

输入数组长度 n 
输入数组      a[1...n] 
输入查找个数m 
输入查找数字b[1...m] 
输出 YES or NO  查找有则YES 否则NO 。

输入：
6
3 2 5 4 7 8
2
3 6
输出：
YES
NO
*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[maxn], b[maxn];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &b[i]);
		}
		for (int i = 0; i < m; i++) {
			int flag = 0; // 标记对于b数组的某个元素，遍历a能找到该数字，则修改标记为1
			for (int j = 0; j < n; j++) { // 对于b数组的某个元素，要从a数组中遍历找是否存在该元素
				if (b[i] == a[j]) {
					flag = 1;
				}
			}
			if (flag == 1) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
		
	}
}