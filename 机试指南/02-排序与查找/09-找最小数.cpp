#include <iostream>
#include <cstdio>
using namespace std;

/*

查找最小数（北邮）

*/

struct number {
	int x;
	int y;
}num[1000];

bool cmp(number a, number b) {
	if (a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &num[i].x, &num[i].y);
		}
		sort(num, num + n, cmp);
		printf("%d %d\n", num[0].x, num[0].y);
	}
}