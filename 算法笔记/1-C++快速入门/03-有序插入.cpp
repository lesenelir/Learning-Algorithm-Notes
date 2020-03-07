#include <iostream>
#include <cstdio>
using namespace std;

/*

有一个已排好序的数组，要求输入一个数后，按原来排序的规律将它插入到数组中。
假设数组长度为10。
输入：
1 11 21 31 41 51 61 71 81
45
输出：
1
11
21
31
41
45
51
61
71
81

*/


int main(int argc, char *argv[]) {
	int a[10];
	for (int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
	}
	int n;
	scanf("%d", &n);
	for (int i = 8; i >= 0; i--) { // 从数组后面往前比较，数组元素大的数字后移
		if (a[i] > n) {
			a[i+1] = a[i];
		} else if (a[i] < n) {
			a[i+1] = n; // 当i处于此处时，数组数字比n小，n放在该数字后面一位
			break; // 跳出循环防止，比他小的数字一直被赋值操作
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}

}