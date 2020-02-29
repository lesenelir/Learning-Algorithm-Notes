#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


/*
对于一个m行m列的（1<m<10）的方阵，求其每一行，每一列及主对角线元素之和，最后按照从大到小的顺序依次输出。


*/

const int maxn = 1010;

bool cmp(int a, int b) {
	return a > b;
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[maxn][maxn];
		for (int i = 0; i < n; i++) { // 输入
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		int sum[maxn], num = 0;
		for (int i = 0; i < n; i++) { // 此循环遍历求得行相加值和列相加值
			int temp1 = 0; // 存储行
			int temp2 = 0; // 存储列
			for (int j = 0; j < n; j++) {
				temp1 = temp1 + a[i][j];
				temp2 = temp2 + a[j][i];
			}
			sum[num++] = temp1;
			sum[num++] = temp2;
		}
		
		int temp_x = 0; // 主对角线
		int temp_y = 0; // 副对角线
		for (int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if (i == j) { // if在每一次内循环只可能执行一次
					temp_x = temp_x + a[i][j];
				}
				if (j == n-i-1) {
					temp_y = temp_y + a[i][j];
				}
			}
		}
		sum[num++] = temp_x;
		sum[num++] = temp_y;
		
		sort(sum, sum+num, cmp);
		
		for (int i = 0; i < num; i++) {
			printf("%d ", sum[i]);
		}
		
		
	}
}