#include <iostream>
#include <cstdio>
using namespace std;

/*

选择排序：从后面乱序的数组中找到最小的插入a[i]中
插入排序：从待排序序列的第一个元素往前插入已排序好的序列中的特定位置
冒泡排序

*/

void selectSort(int a[], int n) {
	for (int i = 0; i < n; i++) { // 进行n趟
		int k = i;  // k存储最小元素的下标
		for (int j = i; j < n; j++) {
			if (a[j] < a[k]) {
				k = j;
			}
		}
		// 交换最小的k下标数组元素和a[i]
		int temp = a[i];
		a[i] = a[k];
		a[k] = temp;
	}
}

void insertSort(int a[], int n) {
	for (int i = 1; i < n; i++) { // 从第二个元素开始排序
		int temp = a[i]; 
		for (int j = i; j >= 0 && temp < a[j-1]; j--) { // temp小于a[j]前一个元素
			a[j] = a[j-1]; // a[j-1]后移
		}
		a[j] = temp;
	}
}

void bubbleSort(int a[], int n) {
	for (int i = 0; i < n-1; i++) { // n个数进行n-1趟
		for (int j = 0; j < n-i-1; j++) { // i趟 进行n-i次比较
			if (a[j] > a[j+1]) {
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}


int main(int argc, char *argv[]) {
	
}