#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入：
3862767 6 13530293 3
3862767 1 13530293 8
输出：
399
0

备注：
有时候需要遍历一较长的数字的时候，通常用字符型来存储数字
*/


const int maxn = 1010;

int main(int argc, char *argv[]) {
	char A[maxn], B[maxn];
	int DA, DB;
	while (scanf("%s %d %s %d", A, &DA, B, &DB) != EOF) {
		int lenA = strlen(A), lenB = strlen(B);
		
		int numA = 0, numB = 0;
		for (int i = 0; i < lenA; i++) {
			if ((A[i] - '0') == DA) {
				numA = numA * 10 + DA; // num累加每增加一个数，高位进一
			}
		}
		for (int i = 0; i < lenB; i++) {
			if ((B[i] - '0') == DB) {
				numB = numB * 10 + DB;
			}
		}
		
		printf("%d\n", numA + numB);
	}
}