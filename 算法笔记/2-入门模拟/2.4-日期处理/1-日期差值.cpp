#include <iostream>
#include <cstdio>
using namespace std;

/*

有两个日期，求两个日期之间的天数，如果这两个日期是连续的，则规定他们之间的天数为两天
输入：
20130101
20130105
输出：
5

思路：
第一个日期早于第二个日期，令日期天数不断增加，直到第一个日期等于第二个日期为止。
操作：
如果日期d+1超过了该月的天数，则m+1,d赋值为1
如果月份m为13则另年y+1，同时把m置为1


*/

int month[13][2] = {
	{0,0}, {31,31}, {28,29},{31,31},{30,30},{31,31},{30,30},
	{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}
};

bool isLeap(int year) { // 闰年能被四百整除，或者能被4整除且不能被100整除
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, char *argv[]) {
	int time1, y1, m1, d1;
	int time2, y2, m2, d2;
	while (scanf("%d %d", &time1, &time2) != EOF) {
		
		if (time1 > time2) { // 第一个日期晚于第二个日期则交换
			int temp = time1;
			time1 = time2;
			time2 = temp;
		}
		
		// %10000：取最后面四位, /10000：舍去最后四位
		y1 = time1 / 10000, m1 = time1 % 10000 / 100, d1 = time1 % 100;
		y2 = time2 / 10000, m2 = time2 % 10000 / 100, d2 = time2 % 100;
		
		int ans = 1; // 记录
		while (y1 < y2 || m1 < m2 || d1 < d2) {
			d1++;
			if (d1 > month[m1][isLeap(y1)]) {
				m1++;
				d1 = 1;
			}
			if (m1 == 13) {
				y1++;
				m1 = 1;
			}
			ans++;
		}
		printf("%d\n", ans);
	}
}