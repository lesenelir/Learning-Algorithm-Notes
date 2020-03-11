#include <iostream>
#include <cstdio>
using namespace std;

/*

全排列
输入一个整数n(1<=n<=10)输出所有全排列,按字典序输出
输入：
3
输出：
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

*/

const int maxn = 11;
int n, P[maxn]; // P为当前排列
bool hashTable[maxn] = {false}; // hashTable记录整数x是否已经在P中

// 当前处理排列的第index号元素
void DFS(int index) {
	// 递归边界，已经处理完排列的0~n-1位
	if (index == n + 1) {
		for (int i = 1; i <= n; i++) {
			printf("%d ", P[i]);
		}
		printf("\n");
		return;
	}
	// 枚举1~n，试图将x填入P[maxn]
	for (int x = 1; x <= n; x++) { // x从0开始就是从0开始全排列
		if (hashTable[x] == false) { // x不在p数组中
			P[index] = x;
			hashTable[x] = true;
			DFS(index + 1); // 处理第index + 1号元素
			hashTable[x] = false; // 处理完P[index]为x的子问题，还原状态
		}
	}	
}

int main(int argc, char *argv[]) {
	while (scanf("%d", &n) != EOF) {
		DFS(1); // p[i]从1开始
	}
}