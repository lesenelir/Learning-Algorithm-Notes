#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

PAT 1032 挖掘技术哪家强
输入：
6 
3 65
2 80
1 100
2 70
3 40
3 0
输出：
2 150

备注：要加强创建数组来统计结果的思想
*/

const int maxn = 1000;

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int school[maxn];
		memset(school, 0, sizeof(school)); // 定义数组一定要初始化
		int schoolID = 1, score = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &schoolID, &score);
			school[schoolID] += score;
		}
		int k = 0, max = 0;
		for (int i = 0; i < n; i++) {
			if (school[i] > max) {
				k = i;
				max = school[i];
			}
		}
		printf("%d %d", k, max);
		
	}
}