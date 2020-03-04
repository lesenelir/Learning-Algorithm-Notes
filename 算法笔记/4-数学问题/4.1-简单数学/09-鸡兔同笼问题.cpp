#include <iostream>
#include <cstdio>
using namespace std;

/*

一个笼子里面关了鸡和兔子（鸡有2只脚，兔子有4只脚，没有例外）。
已经知道了笼子里面脚的总数a，问笼子里面至少有多少只动物，至多有多少只动物。

第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，每行一个正整数a (a < 32768)
输出包含n行，每行对应一个输入,包含两个正整数，第一个是最少的动物数，第二个是最多的动物数，两个正整数用一个空格分开
如果没有满足要求的答案，则输出两个0。

输入：
2
18
5
输出：
5 9
0 0

*/


int main(int argc, char *argv[]) {
	int m;
	while (scanf("%d", &m) != EOF) {
		while (m--) {
			int n;
			scanf("%d", &n);
			if (n % 2 != 0) printf("0 0\n"); //鸡兔同笼脚的个数必须是偶数
			else if (n % 4 == 0) printf("%d %d\n", n/4, n/2);//脚的个数是4的倍数，最少动物全是兔子，最多动物全是鸡
			else printf("%d %d\n", n/4+1,n/2);
		}
	}
	
}