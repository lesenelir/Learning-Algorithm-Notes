#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

先输入一组数，然后输入其分组，按照分组统计出现次数并输出

输入第一行表示样例数m，对于每个样例，第一行为数的个数n，接下来两行分别有n个数，
第一行有n个数，第二行的n个数分别对应上一行每个数的分组，n不超过100。
输出m行，格式参见样例，按从小到大排。

输入：
1
7
3 2 3 8 8 2 3
1 2 3 2 1 3 1
输出：
1={2=0,3=2,8=1}
2={2=1,3=0,8=1}
3={2=1,3=1,8=0}

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int m;
	while (scanf("%d", &m) != EOF) {
		while (m--) {
			int n;
			scanf("%d", &n);
			int a[maxn]; // a[]数组存储有哪些数字
			for (int i = 0; i < n; i++) {
				scanf("%d", &a[i]);
			}
			int hashTable[maxn] = {0}; // hashTable[a[i]]表示a[i]元素的分组
			for (int i = 0; i < n; i++) {
				scanf("%d", &hashTable[a[i]]);
			}
			
			sort(hashTable, hashTable + n);
			// 遍历判断输出
			
		}
	}
}