#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

输入两个字符串，比较两字符串的长度大小关系。
输入第一行表示测试用例的个数m，接下来m行每行两个字符串A和B

输出m行。若两字符串长度相等则输出A is equal long to B；
若A比B长，则输出A is longer than B；
否则输出A is shorter than B。

输入：
2
abc xy
bbb ccc
输出：
abc is longer than xy
bbb is equal long to ccc

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int m;
	while (scanf("%d", &m) != EOF) {
		while (m--) {
			char A[maxn], B[maxn];
			scanf("%s %s", A, B);
			int lenA = strlen(A);
			int lenB = strlen(B);
			if (lenA > lenB) {
				printf("%s is longer than %s\n", A, B);
			} else if (lenA < lenB) {
				printf("%s is shorter than %s\n", A, B);
			} else {
				printf("%s is equal long to %s\n", A, B);
			}
		}
	}
}