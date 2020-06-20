#include <iostream>

using namespace std;

/*选择排序i为要替换的位置,k存储最小元素*/
void selectsort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int k = i;
		for (int j = i+1; j < n; j++) {
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
	int a[5] = {5, 7, 9, 3, 2};
	selectsort(a, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
}