#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

成绩排序 P31

*/

struct student {
	int id;
	int score;
}stu[100];

bool cmp(student a, student b) {
	if (a.score != b.score) return a.score < b.score;
	else return a.id < b.id;
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &stu[i].id, &stu[i].score);
		}
		sort(stu, stu + n, cmp);
		for (int i = 0; i < n; i++) {
			printf("%d %d\n", stu[i].id, stu[i].score);
		}
	}
}