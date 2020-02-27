#include <iostream>
#include <cstdio>
using namespace std;

/*

编写一个日期类，要求按xxxx-xx-xx 的格式输出日期，实现加一天的操作。
输入第一行表示测试用例的个数m，接下来m行每行有3个用空格隔开的整数，分别表示年月日。测试数据不会有闰年。
输出m行。按xxxx-xx-xx的格式输出，表示输入日期的后一天的日期。

输入：
2
1999 10 20
2001 1 31
输出：
1999-10-21
2001-02-01

*/

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 不考虑闰年

int main(int argc, char *argv[]) {
	int T;
	while (scanf("%d", &T) != EOF) {
		while (T--) {
			int y, m, d;
			scanf("%d %d %d", &y, &m, &d);
			if (m == 12 && d == 31) { // 必须放在else if 条件之前，因为优先级更高
				y++;
				m = 1;
				d = 1;
			} else if ((d+1) > month[m]) { // 此时前面没有d++操作，所以这里要有d+1 > month[m]
				d = 1;
				m++;
			} else {
				d++;
			}
			printf("%04d-%02d-%02d\n", y, m, d);
		}
	}
}