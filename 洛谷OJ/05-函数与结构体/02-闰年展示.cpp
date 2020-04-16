#include <cstdio>
#include <iostream>
using namespace std;

const int  maxn = 2000;
int c[maxn], num = 0;

bool isLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int x, y;
	while (scanf("%d %d", &x, &y) != EOF) {
		int count = 0;
		for (int i = x; i <= y; i++) {
			if (isLeapYear(i) == true) {
				count++;
				c[num++] = i;
			}
		}
		printf("%d\n", count);
		for (int i = 0; i < num; i++) {
			printf("%d ", c[i]);
		}
		printf("\n");
	}
	
	return 0;
}