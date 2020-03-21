#include <iostream>
#include <cstdio>
using namespace std;

/*

汉诺塔问题III至少移动多少次P133

区别在于：
此时只能通过第二根杆子移动，不能直接由第一根杆子移动到第三根杆子

*/
int move(int n) {
	if (n == 1) return 2;
	// n-1个盘子先由a 经过b移动到c，最大的盘子移动到b + 1， 再将n-1由c经b移动到a，最大盘子由b移动到c 再加1，最后把n-1盘子由a经过b移动到c 总共经历3次的n-1移动盘子数
	else return 3 * move(n-1) + 2; 
}



int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int res = move(n);
		printf("%d\n", res);
	}
}