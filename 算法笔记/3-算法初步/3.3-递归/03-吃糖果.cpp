#include <iostream>
#include <cstdio>
using namespace std;

/*

名名的妈妈带了一盒好吃又精美的巧克力给名名（盒内共有 N 块巧克力，20 > N >0）
妈妈告诉名名每天可以吃一块或者两块巧克力。假设名名每天都吃巧克力，问名名共有多少种不同的吃完巧克力的方案。
如果N=1，则名名第1天就吃掉它，共有1种方案；
如果N=2，则名名可以第1天吃1块，第2天吃1块，也可以第1天吃2块，共有2种方案；
如果N=3，则名名第1天可以吃1块，剩2块，也可以第1天吃2块剩1块，所以名名共有2+1=3种方案；
如果N=4，则名名可以第1天吃1块，剩3块，也可以第1天吃2块，剩2块，共有3+2=5种方案。
现在给定N，请你写程序求出名名吃巧克力的方案数目。

输入：
1
2
4
输出：
1
2
5

*/

int Function(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else {
		return Function(n-1) + Function(n-2);
	}
}



int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int res = Function(n);
		printf("%d\n", res);
	}
}