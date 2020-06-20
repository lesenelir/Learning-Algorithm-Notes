#include <iostream>

using namespace std;

//插入排序
void insertsort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int temp = a[i], j = i-1; //temp是待排关键字,j是有序表的最后一个元素
		//循环待排关键字之前的有序表
		while (j>= 0 && temp < a[j]) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}


int main(int argc, char *argv[]) {
	int a[5] = {5, 7, 9, 3, 2};
	insertsort(a, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
}