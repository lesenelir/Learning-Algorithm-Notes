#include <iostream>
#include <cstdio>
using namespace std;

/*

设计一个程序能计算一个日期加上若干天后是什么日期。 
输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数。 
输出m行，每行按yyyy-mm-dd的个数输出。

输入:
1 
2008 2 3 100 
输出:
2008-05-13

*/

bool isLeap(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return true;
	} else {
		return false;
	}
}

int month[13][2] = {
	{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},
	{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}
};


int main(int argc, char *argv[]) {
	int T;
	while (scanf("%d", &T) != EOF) {
		int y, m, d, n;
		scanf("%d %d %d %d", &y, &m, &d, &n);
		while (n--) {
			d++;
			if(m == 12 && d == 31) {
				y++;
				m = 1; 
				d = 1;
			} else if (d > month[m][isLeap(y)]) {
				d = 1;
				m++;
			}
		}
		printf("%04d-%02d-%02d\n", y, m, d);
	}
}