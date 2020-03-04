#include <iostream>
#include <cstdio>
using namespace std;

/*

设a、b、c均是0到9之间的数字，abc、bcc是两个三位数，且有：abc+bcc=532。求满足条件的所有a、b、c的值。

*/



int main(int argc, char *argv[]) {
	int a, b, c;
	//a,b不能为0所以要从1开始计数
	for (int a = 1; a < 10; a++) {
		for (int b = 1; b < 10; b++) {
			for (int c = 0; c < 10; c++) {
				if (a*100+b*10+c+b*100+c*10+c == 532) {
					printf("%d %d %d\n", a, b, c);
				}
			}
		}
	}
}