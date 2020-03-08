#include <iostream>
#include <cstdio>
using namespace std;

/*

与7无关的数：n < 100
如果一个正整数能被7整除或者它的十进制表示法中某个位数上的数字为7则称为与7相关

输入第一行为T测试数据，下面T行输入一个n 输出所有<=n的与7无关的正整数平方和

输入：
5
4
5
6
7
8
输出：
30
55
91
91
155

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int T;
	while (scanf("%d", &T) != EOF) {
		while (T--) {
			int n;
			scanf("%d", &n);
			int sum = 0;
			for (int i = 1; i <= n; i++) { // 对于每一个小于n的数字来说
				if (i % 7 == 0) continue;
				else { // i不能被7整除
					bool flag = true;
					int temp = i;
					while (temp != 0) { // 利用反序数不知道位数思想，从个位开始判断并舍去
						if (temp % 10 == 7) flag = false;
						temp = temp / 10;
					}
					/*
					方法二：利用数组来存储各个位数来实现判断
					int a[maxn], num = 0;
					bool flag = true;
					int temp = i;
					while (temp != 0) { // 把i按位数进行拆解a[0]个位，a[1]十位，a[2]百位
						a[num++] = temp % 10;
						temp = temp / 10;
					}
					for (int j = 0; j < num; j++) {
						if (a[j] == 7) flag = false;
					}
					*/
					if (flag == false) continue; // 位数包含7
					else sum = sum + i * i;
				}			
			}
			printf("%d\n", sum);
		}
	}
}

