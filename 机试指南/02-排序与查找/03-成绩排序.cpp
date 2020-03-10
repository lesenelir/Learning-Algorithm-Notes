#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

成绩排序 P33

*/

struct student {
	char name[100];
	int score;
	int id;
}stu[100];


bool cmp0(student a, student b) { // 降序
	if (a.score != b.score) return a.score > b.score;
	else return a.id < b.id;
}

bool cmp1(student a, student b) { // 升序
	if (a.score != b.score) return a.score < b.score;
	else return a.id < b.id;
}

int main(int argc, char *argv[]) {
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%s %d", stu[i].name, &stu[i].score);
			stu[i].id = i;
		}
		if (k == 0) sort(stu, stu + n, cmp0);
		if (k == 1) sort(stu, stu + n, cmp1);
		for (int i = 0; i < n; i++) {
			printf("%s %d\n", stu[i].name, stu[i].score);
		}
	}
}