#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct student {
	int id;
	int score;
}buf[1000];

bool cmp(student a, student b) {
	if (a.score != b.score) return a.score < b.score;
	else return a.id < b.id;
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &buf[i].id, &buf[i].score);
		}
		sort(buf, buf+n, cmp);
		for (int i = 0; i < n; i++) {
			printf("%d %d\n", buf[i].id, buf[i].score);
		}
	}
}