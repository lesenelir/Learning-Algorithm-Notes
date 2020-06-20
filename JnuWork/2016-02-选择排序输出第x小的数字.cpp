#include <iostream>

using namespace std;

//选择排序
void selectsort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int k = i; //k存储变量最小值下标
		for (int j = i; j < n; j++) {
			if (a[j] < a[k]) {
				k = j;
			}
		}
		int temp = a[i];
		a[i] = a[k];
		a[k] = temp;
	}
}

int main(int argc, char *argv[]) {
	int n, x;
	while(scanf("%d %d", &n, &x) != EOF) {
		int a[1000];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		selectsort(a, n);
		printf("%d\n", a[x-1]);
	}
}