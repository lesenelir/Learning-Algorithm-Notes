#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/*

去掉最高分最低分 分别排序

*/

const int maxn = 21;
double c[maxn]; // 保存平均分
int num = 0; 

struct student {
	int score[maxn];
}stu[100];


int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &stu[i].score[j]);
			}
		}
		for (int i = 0; i < n; i++) { // 时间复杂度高，排序次数多
			sort(stu[i].score, stu[i].score + m);
		}
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 1; j < m-1; j++) { // 最小存储在0最大存储在m-1
				sum = sum + stu[i].score[j];
			}
			double avg = sum * 1.0 / (m-2) * 1.0;
			c[num++] = avg;
		}
		sort(c, c + num);
		printf("%0.2f\n", c[num-1]);
	}
	return 0;
}