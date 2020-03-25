#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

成绩排名 P31

*/
const int maxn = 1010;
struct student {
	char name[maxn];
	char id[maxn];
	int score;
}stu[maxn];

bool cmp(student a, student b) {
	return a.score > b.score;
}


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].score);
		}
		sort(stu, stu + n, cmp);
		printf("%s %s\n", stu[0].name, stu[0].id);
		printf("%s %s\n", stu[n-1].name, stu[n-1].id);
	}
}