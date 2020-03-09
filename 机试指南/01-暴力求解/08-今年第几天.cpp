#include <iostream>
#include <cstdio>
using namespace std;

/*

今年的第几天 P16

*/

int month_n[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
int month_y[13] = {0, 31,29,31,30,31,30,31,31,30,31,30,31};

bool isLeap(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ) {
		return true;
	} else {
		return false;
	}
}


int main(int argc, char *argv[]) {
	int y, m, d;
	while (scanf("%d %d %d", &y, &m, &d) != EOF) {
		int sum = 0;
		bool flag = isLeap(y);
		if (flag == true) { // 闰年
			for (int i = 1; i < m; i++) { // 计算m月之前的天数
				sum = sum + month_y[i];
			}
		} else {
			for (int i = 1; i < m; i++) {
				sum = sum + month_n[i];
			}
		}
		sum = sum + d;
		printf("sum\n");
	}	
}