#include <iostream>

using namespace std;
/*

题目描述
	用小于等于n元去买100只鸡，大鸡5元/只，小鸡3元/只,还有1/3元每只的一种小鸡，分别记为x只,y只,z只。编程求解x,y,z所有可能解。
输入描述:
	测试数据有多组，输入n。
输出描述:
	对于每组输入,请输出x,y,z所有可行解，按照x，y，z依次增大的顺序输出。
	
输入：
40
输出：
x=0,y=0,z=100
x=0,y=1,z=99
x=0,y=2,z=98
x=1,y=0,z=99
x=1,y=1,z=98

*/
int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for(int x = 0; x <= 100; x++)
			for(int y = 0; y <= 100 - x; y++)
				if(n >= 5 * x + 3 * y + (100 - x - y) / 3)
					printf("x=%d,y=%d,z=%d\n", x, y, 100 - x - y);
	}
}