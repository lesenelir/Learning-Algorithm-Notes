#include <iostream>

using namespace std;

void bubble(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i; j++) {
			if (a[j] > a[j+1]) { //从小到大排序
				int temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	int a[1000];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	bubble(a, n);
	for (int i = 0; i < n; i++) {
		if (a[i] != a[i+1]) { //去重
			printf("%d ", a[i]);
		}
	}
	system("pause");
	return 0;
}