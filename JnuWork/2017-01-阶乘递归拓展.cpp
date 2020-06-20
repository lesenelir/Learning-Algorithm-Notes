#include <iostream>

using namespace std;

int Function(int n) {
	if (n == 1) return 1;
	else return n * Function(n-1);
}

/*	y1=1!+3!+...m!(m是小于等于n的最大奇数）
	y2=2!+4!+...p!(p是小于等于n的最大偶数)
*/

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int y1 = 0, y2 = 0;
		for (int i = 1; i <= n; i = i+2) {
			y1 = y1 + Function(i);
		}
		for (int i = 2; i <= n; i = i+2) {
			y2 = y2 + Function(i);
		}
		printf("%d %d", y1, y2);
	}
}