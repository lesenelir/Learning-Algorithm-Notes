#include <iostream>
#include <cstdio>
using namespace std;

/*

有一个长度为整数L(1<=L<=10000)的马路，可以想象成数轴上长度为L的一个线段，起点是坐标原点，在每个整数坐标点有一棵树，即在0,1,2，...，L共L+1个位置上有L+1棵树。
	现在要移走一些树，移走的树的区间用一对数字表示，如 100 200表示移走从100到200之间（包括端点）所有的树。
	可能有M(1<=M<=100)个区间，区间之间可能有重叠。现在要求移走所有区间的树之后剩下的树的个数。

输入（多组）：0 0 结束
4 2
1 2
0 2
11 2
1 5
4 7
0 0
输出：
2
5

备注：要加强创建数组来统计结果的思想
*/




int main(int argc, char *argv[]) {
	int L, M;
	while (scanf("%d %d", &L, &M) != EOF) {
		if (L == 0 && M == 0) break;
		int a[255]; // 树数组
		for (int i = 0; i <= L; i++) { // 种树
			a[i] = 1;
		}
		int begin, end;
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &begin, &end);
			for (int j = begin; j <= end; j++) { // 移树
				a[j] = 0;
			}
		}
		int count = 0; // 统计最后还有多少树
		for (int i = 0; i <= L; i++) {
			if (a[i] == 1) {
				count++;
			}
		}
		printf("%d\n", count);
	}
}