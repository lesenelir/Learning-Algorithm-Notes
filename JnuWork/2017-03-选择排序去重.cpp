#include <iostream>

using namespace std;
/*
	去重思路：
		1.遍历数组，相邻不一样的元素a[i]输出
		2.遍历数组，相邻不一样的元素a[i]读入新的数组
*/
const int N = 10;

void selectsort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int k = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[k]) {
				k = j;
			}
		}
		int temp = a[k];
		a[k] = a[i];
		a[i] = temp;
	}
}

int main(int argc, char *argv[]) {
	int a[1000];
	while (scanf("%d", &a[0]) != EOF) {
		for (int i = 1; i < N; i++) {
			scanf("%d", &a[i]);
		}
		selectsort(a, N);
//		for (int i = 0; i < N; i++) {
//			if (a[i] != a[i+1]) {
//				printf("%d ", a[i]);
//			}
//		}
		int b[100], num = 0;
		for (int i = 0; i < N; i++) {
			if (a[i] != a[i+1]) {
				b[num++] = a[i];
			}
		}
		for (int i = 0; i < num; i++) {
			printf("%d ", b[i]);
		}		
	}
}