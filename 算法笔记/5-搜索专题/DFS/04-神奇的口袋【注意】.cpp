#include <iostream>
#include <cstdio>
using namespace std;

/*
有一个神奇的口袋，总的容积是40，用这个口袋可以变出一些物品，这些物品的总体积必须是40。John现在有n个想要得到的物品，每个物品的体积分别是a1，a2……an。John可以从这些物品中选择一些，如果选出的物体的总体积是40，那么利用这个神奇的口袋，John就可以得到这些物品。现在的问题是，John有多少种不同的选择物品的方式。

输入的第一行是正整数n (1 <= n <= 20)，表示不同的物品的数目。接下来的n行，每行有一个1到40之间的正整数，分别给出a1，a2……an的值。

输出不同的选择物品的方式的数目。

输入：
2
12
28
3
21
10
5
输出：
1
0



*/

const int maxn = 21;
int num;
int N;
int nowremnant = 40; // 剩余货物
int goods[maxn]; 

void DFS(int index) {
	if (nowremnant < 0) return;
	else if (nowremnant == 0) {
		num++;
		return;
	}
	if (index == N) return;
	for (int i = index; i < N; i++) {
		nowremnant = nowremnant - goods[i];
		DFS(index + 1); // 接着需要回退到上一步去继续寻找下一个包含a的可能组合
		nowremnant = nowremnant + goods[i];
	}
}


int main(int argc, char *argv[]) {
	while(scanf("%d",&N) != EOF) {
		num = 0;
		for(int i = 0; i < N; i++) scanf("%d",&goods[i]);
		DFS(0);
		printf("%d\n",num);
	}
}