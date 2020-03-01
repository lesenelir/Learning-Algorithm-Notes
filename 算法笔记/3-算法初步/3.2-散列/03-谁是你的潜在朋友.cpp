#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

把N个读者依次编号为1,2,…,N，把M本书依次编号为1,2,…,M。和你喜欢读同一本书的人，就是你的潜在朋友。
你现在的任务是从这份借阅记录中计算出每个人有几个潜在朋友。

每个案例第一行两个整数N,M，2 <= N ，M<= 200。接下来有N行，第i(i = 1,2,…,N)行每一行有一个数，
表示读者i-1最喜欢的图书的编号P(1<=P<=M)

每个案例包括N行，每行一个数，第i行的数表示读者i有几个潜在朋友。如果i和任何人都没有共同喜欢的书，则输出“BeiJu”

输入：
4 5
2
3
2
1
输出：
1
BeiJu
1
BeiJu

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		int hashTable[m+1]; // 从1开始编号，hashTable[i] 读此书的人
		memset(hashTable, 0, sizeof(hashTable));// hashTable一定要赋初值0
		int a[maxn]; // 第i个读者，a[i]对应书号
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			hashTable[a[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			if (hashTable[a[i]] > 1) {
				printf("%d\n", hashTable[a[i]] - 1);
			} else {
				printf("BeiJu\n");
			}
			
		}
	}
	
}