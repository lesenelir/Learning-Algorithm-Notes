#include <cstdio>

/* 冒泡排序等排序都是要定义数组 */
int main(int argc, char *argv[]) {
	int a[10];
	// 输入数据
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	// 冒泡排序过程，i从0开始到n-1，j从0开始到n-i
	int temp;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10 - i; j++) {
			if (a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	// 遍历输出数组
	for (int i = 0; i < 10; i++) {
		printf("%d\n"、, a[i]);
	}
}