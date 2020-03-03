#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

小智去超市买东西，买了不超过一百块的东西。收银员想尽量用少的纸币来找钱。
纸币面额分为50 20 10 5 1 五种。请在知道要找多少钱n给小明的情况下，输出纸币数量最少的方案。 1<=n<=99;

输入：
25
32
输出：
20*1+5*1
20*1+10*1+1*2

类似于月饼题目 上题是单价，一块面币下这题是最多可以兑换几张

*/

struct money {
	int value;
	int count;
};


bool cmp(money a,money b) { // 纸币面值按递减排序
	return a.value > b.value;
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		money m[5]={{50,0},{20,0},{10,0},{5,0},{1,0}};
		for (int i = 0; i < 5; i++) { // 计算在n数字下 每张纸币做单个来兑换n最多需要几张
			if (n >= m[i].value) {
				m[i].count = n / m[i].value;
				n = n % m[i].value;
			}
		}
		sort(m, m+5, cmp); // 按照面值递减排序
		int ans = 0; // 记录值
		for (int i = 0; i < 5; i++) {
			if (m[i].count != 0) {
				printf("%d*%d", m[i].value, m[i].count);
				ans = ans + (m[i].value * m[i].count);
				if (ans != n) printf("+");
				else break;
			}
		}
		printf("\b"); // 输出退格符
		printf("\n");
	}
}