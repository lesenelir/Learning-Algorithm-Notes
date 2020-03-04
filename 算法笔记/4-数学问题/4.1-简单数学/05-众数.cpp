#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

输入20个数，每个数都在1-10之间，求1-10中的众数（众数就是出现次数最多的数，如果存在一样多次数的众数，则输出权值较小的那一个）。


输入：
8 9 6 4 6 3 10 4 7 4 2 9 1 6 5 6 2 2 3 8
输出：
6

*/


const int n = 20;

int main(int argc, char *argv[]) {
	int x;
	int a[11] = {0};
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		a[x]++; //数组下标代表数字，数组值代表这个数字出现的次数
	}
	//找众数即：找a数组元素值最大的数字，输出下标；若元素值相等，则
	int max = a[0], pos; // 关键是把下标保存在一个变量内
	for(int i = 0; i < 11; i++) {
		if(max < a[i]) {
			max = a[i];
			pos = i;
		}
	}
	printf("%d\n", pos);
}