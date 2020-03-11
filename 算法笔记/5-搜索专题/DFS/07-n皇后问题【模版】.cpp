#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

/*

会下国际象棋的人都很清楚：皇后可以在横、竖、斜线上不限步数地吃掉其他棋子。如何将8个皇后放在棋盘上（有8 * 8个方格），使它们谁也不能被吃掉！这就是著名的八皇后问题。 

一个整数n（ 1 < = n < = 10 ) 
每行输出对应一种方案，按字典序输出所有方案。每种方案顺序输出皇后所在的列号，相邻两数之间用空格隔开。如果一组可行方案都没有，输出“no solute!”

输入：
4
输出：
2 4 1 3
3 1 4 2

index为x轴坐标， p[index]为y轴坐标. 即坐标点为(index, p[index])
显然每个点不在同一行同一列，枚举index+1时只需当前的坐标与前面已经填入的坐标是否构成对角线。

*/

int n;
int P[22];
bool hashTable[22] = {false};
int cnt = 0;

void DFS(int index) {
	if (index == n + 1) { // 递归边界 生成了一个排列
		bool flag = true; // flag 为true 表示当前方案合法
		for (int i = 1; i <= n; i++) { // 遍历两个皇后
			for (int j = i + 1; j <= n; j++) {
				if (abs(i - j) == abs(P[j] - P[i])) {
					flag = false; // 如果在一条对角线上，也就是正方形相对的两个端点
				}
			}
		}
		if (flag == true) {
			cnt++;
			for (int i = 1; i <= n; i++) { // 输出格式
				printf("%d", P[i]);
				if (i <= n - 1) printf(" ");
			}
			printf("\n");
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (hashTable[i] == false) {
			P[index] = i;
			hashTable[i] = true;
			DFS(index + 1);
			hashTable[i] = false;
		}
	}
	
}


int main(int argc, char *argv[]) {
	while (scanf("%d", &n) != EOF) {
		DFS(1);
		if (cnt == 0) printf("no solute!\n");
	}
}