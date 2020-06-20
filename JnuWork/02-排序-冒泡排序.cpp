#include <iostream>

using namespace std;

/*冒泡排序第一个for村还[1,n),第二个for循环[0,n-i)*/
void bubblesort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n-i; j++) {
			if (a[j] > a[j+1]) {
				int temp;
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int a[9] = {5, 7, 9, 3, 2, 5, 9, 1, 2};
//	char a[10]={'i','l','o','v','e','y','o','u','y','x'};
	bubblesort(a, 9);
	for (int i = 0; i < 9; i++) {
		if (a[i] != a[i+1]) { //数组去重
			printf("%d ", a[i]);
		}
	}
}