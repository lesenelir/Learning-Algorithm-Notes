#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
/*
国王将金币作为工资，发放给忠诚的骑士。第一天，骑士收到一枚金币；之后两天（第二天和第三天），每天收到两枚金币；之后三天（第四、五、六天），每天收到三枚金币；之后四天（第七、八、九、十天），每天收到四枚金币……；这种工资发放模式会一直这样延续下去：当连续N天每天收到N枚金币后，骑士会在之后的连续
N
+
1
N+1天里，每天收到
N
+
1
N+1枚金币。

请计算在前
K
K天里，骑士一共获得了多少金币。
*/
int day = 1, j = 1; // day 日薪 ；j 日薪持续天数


int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		int res = 0;
		for (int i = 1; i <= N; i++) {
			res = res + day;
			if (day == j) {
				day++; // 日薪加1
				j = 0; // 发放新一天的薪水天数归0
			}
			j++; // 某日薪发放薪水的次数加1
		}
		printf("%d\n", res);
	}
	return 0;
}