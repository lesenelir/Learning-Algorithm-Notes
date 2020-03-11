#include <iostream>
#include <cstdio>
using namespace std;

/*

DFS搜索递归求解01 背包	

深度优先搜索——枚举所有完整路径以遍历所有情况。碰到死胡同才回退到最近的岔道口选择另一条岔路。

在这个问题中，对每件物品都有选和不选两种选择，这就是岔道口。

*/

const int maxn = 30;
int n, V, maxvalue = 0; //  物品数，背包容量，最大价值
int w[maxn], c[maxn]; // 每件物品的重量，每件物品的价值

void DFS(int index, int sumW, int sumC) { // index当前处理的序号
	// 递归边界
	if (index == n) { // 已经完成了对n件物品的选择 死胡同
		if (sumW <= V && sumC > maxvalue) {
			maxvalue = sumC;
		}
		return;
	}
	// 递归式
	DFS(index + 1, sumW, sumC); // 不选第index件物品
	DFS(index + 1, sumW + w[index], sumC + c[index]); // 选了第index件物品
}

void DFS_New(int index, int sumW, int sumV) {
	//已经把n件物品处理完毕（下标0-n-1），到达死胡同 
	if(index == n) return;
	//岔道口 
	DFS_New(index + 1, sumW, sumV); //不选择第index件物品 
	//只有加入第index件物品后未超过容量V才能选择index件物品 
	if(w[index] + sumW <= V) {
		//更新最大价值 
		if(c[index] + sumV > maxValue) maxValue = c[index] + sumV;
		DFS_New(index + 1, sumW + w[index], sumV + c[index]); //选择第index件物品 
	}
}


int main(int argc, char *argv[]) {
	while (scanf("%d %d", &n, &V) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &w[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &c[i]);
		}
		DFS(0, 0, 0);
		printf("%d\n", maxvalue);
	}
}