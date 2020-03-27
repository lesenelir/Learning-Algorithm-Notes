#include <iostream>
#include <cstdio>
using namespace std;

/*

A1019 General Palindromic number P53
判断输入n和b 问在n进制下十进制数b是否为回文

*/
const int maxn = 1010;
int a[maxn], num = 0;

// 判断是否为回文串
bool Judge(int a[], int len) {
	for (int i = 0; i < len / 2; i++) {
		if (a[i] != a[len - i - 1]) return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	int n, b;
	while (scanf("%d %d", &n, &b) != EOF) {
		num = 0; // 对数组进行重置，不设置下次一输入是在上一次输入基础上进行输出
		do {
			a[num++] = n % b;
			n = n / b;
		} while (n != 0);
		
		bool flag = Judge(a, num);
		if (flag == true) {
			printf("YES\n");
			for (int i = num - 1; i >= 0; i--) {
				printf("%d ", a[i]);
			}
		} else {
			printf("NO\n");
			for (int i = num - 1; i >= 0; i--) {
				printf("%d ", a[i]);
			}
		}
		printf("\n");
	}
}