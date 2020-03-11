#include <iostream>
#include <cstdio>
using namespace std;

/*

组合的输出
排列与组合是常用的数学方法，其中组合就是从n个元素中抽出r个元素(不分顺序且r < ＝ n)，我们可以简单地将n个元素理解为自然数1，2，…，n，从中任取r个数。 
现要求你不用递归的方法输出所有组合。 
例如n ＝ 5 ，r ＝ 3 ，所有组合为： 
1 2 3 
1 2 4 
1 2 5 
1 3 4 
1 3 5 
1 4 5 
2 3 4 
2 3 5 
2 4 5 
3 4 5 

*/

int n, r;
int P[22]; // P为当前排列
bool hashTable[22] = {false};

void DFS(int index, int nowR) {
	if (nowR == r) { // 递归边界 正好选取到r个数字 结束
		for (int i = 0; i < r-1; i++) {
			printf("%d ", P[i]);
		}
		printf("%d\n", P[r-1]);
		return;
	}
	if (nowR > r) return; // 递归边界 选取数字超过r 结束
	for (int i = index + 1; i <= n; i++) {
		P[nowR] = i;
		DFS(i, nowR + 1);
	}
}


int main(int argc, char *argv[]) {
	while (scanf("%d %d", &n, &r) != EOF) {
		DFS(0, 0);
	}
}