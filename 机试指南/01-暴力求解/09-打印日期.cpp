#include <iostream>
#include <cstdio>
using namespace std;

/*

打印日期 P18

*/

int month[13][2] = {
	{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},
	{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}
};


bool isLear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return true;
	} else {
		return false;
	}
}



int main(int argc, char *argv[]) {
	int y, n;
	while (scanf("%d %d", &y, &n) != EOF) {
		int m = 1, d = 0;
		for (int i = 1; i <= n; i++) {
			d++;
			if (d > month[m][isLear(y)]) {
				d = 1;
				m++;
			}
		}
		printf("%04d-%02d-%02d\n", y, m, d);
	}
}