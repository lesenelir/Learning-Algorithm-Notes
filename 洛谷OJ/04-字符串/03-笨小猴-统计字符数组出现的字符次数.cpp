#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*

哈希思想 统计出现过的次数通常用一个数组来记录数值

*/

const int maxN = 101;
char str[maxN];
int c[26] = {0}; // 下标代表英文字母的ascii字母，数组值代表出现次数

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	while (scanf("%s", str) != EOF) {
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			c[str[i] - 'a']++; // str[i]的ascii码减去a的ascii码在0~25之间
		}
		sort(c, c + 26);
		int maxn = c[25];
		int minn;
		for (int i = 0; i < 25; i++) { // 遍历寻找不是0的最小值
			if (c[i] != 0) {
				minn = c[i];
				break;
			}
		}
		int num = maxn - minn;
		bool flag = isPrime(num);
		if (flag == true) {
			printf("Lucky Word\n");
			printf("%d\n", num);	
		} else {
			printf("No Answer\n");
			printf("0\n");
		}	
	}
	return 0;
}