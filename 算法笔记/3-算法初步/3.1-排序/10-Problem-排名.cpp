#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*

今天的上机考试虽然有实时的Ranklist，但上面的排名只是根据完成的题数排序，没有考虑每题的分值，所以并不是最后的排名.
请你写程序找出最后通过分数线的考生，并将他们的成绩按降序打印。

每场考试信息的第1行给出考生人数N ( 0 < N < 1000 )、考题数M ( 0 < M < = 10 )、分数线（正整数）G；
第2行排序给出第1题至第M题的正整数分值；以下N行，每行给出一名考生的准考证号（长度不超过20的字符串）、
该生解决的题目总数m、以及这m道题的题号（题目号由1到M）。
当读入的考生人数为0时，输入结束。

对每场考试，首先在第1行输出不低于分数线的考生人数n，随后n行按分数从高到低输出上线考生的考号与分数，其间用1空格分隔。
若有多名考生分数相同，则按他们考号的升序输出。

输入：
3 5 32
17 10 12 9 15
CS22003 5 1 2 3 4 5
CS22004 3 5 1 3
CS22002 2 1 5
0
输出：
3
CS22003 63
CS22004 44
CS22002 32


*/

const int maxn = 1010;

struct student {
	char id[maxn];
	int total; // 总共解决多少题目数量
	int work[maxn]; // 解决的题号
	int sum; // 总得分
}stu[maxn];

bool cmp(student a, student b) {	
	if (a.sum != b.sum) {
		return a.sum > b.sum;
	} else {
		return strcmp(a.id, b.id) < 0;
	}
}

int main(int argc, char *argv[]) {
	int N, M, G;
	while (scanf("%d", &N) != EOF) {
		if (N == 0) break;
		scanf("%d %d", &M, &G);
		int score[maxn]; // 每题所占分值
		score[0] = 0;
		for (int i = 1; i <= M; i++) {
			scanf("%d", &score[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%s %d", stu[i].id, &stu[i].total);
			for (int j = 1; j <= stu[i].total; j++) { 
				scanf("%d", &stu[i].work[j]); //遍历某个学生总解决题目数，把解决题号保存在stu[i].work[j]中
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 1; j<= stu[i].total; j++) { //遍历某学生解决题号数
				for (int k = 1; k <= M; k++) { //遍历每题所占分值，k即是题号，socre[k]是题号为k，所占分值
					if (k == stu[i].work[j]) {
						stu[i].sum = stu[i].sum + score[k];
					}
				}
			}
		}
		
		sort(stu, stu+N, cmp);
		
		int count = 0; // 统计及格人数（分数大于等于分数线人数）
		for (int i = 0; i < N; i++) {
			if (stu[i].sum >= G) {
				count++;
			}
		}
		
		// 输出
		printf("%d\n", count);
		for (int i = 0; i < N; i++) {
			printf("%s %d\n", stu[i].id, stu[i].sum);
		}
		
	}
}