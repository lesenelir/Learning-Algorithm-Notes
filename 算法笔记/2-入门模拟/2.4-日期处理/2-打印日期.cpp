#include <iostream>
#include <cstdio>
using namespace std;

/*

给出年份y和一年中的第n天，算出第n天是几月几号。
输入包括两个整数y(1<=y<=3000)，n(1<=n<=366)。
可能有多组测试数据，对于每组数据，按 yyyy-mm-dd的格式将输入中对应的日期打印出来。

输入：
2013 60
2012 300
2011 350
2000 211
输出：
2013-03-01
2012-10-26
2011-12-16
2000-07-29

*/


int month[13][2] = {
	{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},
	{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}
};

bool isLeap(int year) {
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
		while (n > 0) {
			d++;
			if (d > month[m][isLeap(y)]) {
				m++;
				d = 1;
			}
//			if (m == 13) {
//				y++;
//				m = 1;
//			}		
			n--;
		}
		printf("%04d-%02d-%02d\n", y, m, d);
		m = 1, d = 0;
	}
}