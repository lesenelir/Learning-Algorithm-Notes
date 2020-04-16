#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 11;
int c[maxn], num = 0;

// 用数组来判断回文串【多用于判断某个数字是否为回文】
bool judge1(int n) {
	while (n != 0) { // 拆解数字
		c[num++] = n % 10;
		n = n / 10;
	}
	for (int i = 0; i < num / 2; i++) {
		if (c[i] != c[n-i-1]) { // 前后不相等返回f
			return false;
		}
	}
	return true;
}

// 用后向乘积来判断回文串【多用于判断某个数字是否是回文】
bool judge(int n) {
	int temp = n;
	int sum = 0;
	while (temp != 0) { // 从后往前相乘累加
		sum = sum * 10 + temp % 10;
		temp = temp / 10;
	}
	if (sum == n) {
		return true;
	} else {
		return false;
	}
}


bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}


int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		for (int i = a; i <= b; i++) {
			bool flag = isPrime(i);
			if (flag == true) {
				bool flag_next = judge(i);
				if (flag_next == true) {
					printf("%d\n", i);
				}
				
			}
		}
	}
	return 0;
}