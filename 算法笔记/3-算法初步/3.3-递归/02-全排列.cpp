#include <iostream>
#include <cstdio>
using namespace std;

/*

全排列递归

*/

const int maxn = 1010;

int n, P[maxn], hashTable[maxn] = {0}; // P为当前排列，hashTable记录整数x是否已经在P中


void generateP(int index) {
	if (index == n + 1) { // 递归边界，已经处理完排列的1~n位
		for (int i = 1; i <= n; i++) {
			printf("%d", P[i]); // 输出当前排列
		}
		printf("\n");
		return;
	}
	for (int x = 1; x <= n; x++) {
		if (hashTable[x] == 0) { // x不在P[0] 到 p[index-1]中
			P[index] = x;
			hashTable[x] = true;
			generateP(index + 1); // 处理下一位
			hashTable[x] = 0; // 已处理完P[index]为x的子问题，复原状态
		}
	}
}


int main(int argc, char *argv[]) {
	n = 3;
	generateP(1); // 从p[1]开始填写
}