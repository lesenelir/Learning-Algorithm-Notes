#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

小白鼠排序

*/

struct mices{
	int weight;
	char color[10];
}mice[100];

bool cmp(mices a, mices b) {
	return a.weight > b.weight;
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d %s", &mice[i].weight, mice[i].color);
		}
		sort(mice, mice + n, cmp);
		for (int i = 0; i < n; i++) {
			printf("%s\n", mice[i].color);
		}
	}
}