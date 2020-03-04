#include <iostream>
#include <cstdio>
using namespace std;

/*

编写程序，读入一个整数N。若N为非负数，则计算N 到2N 之间的整数和；若N为一个负数，则求2N 到N 之间的整数和。
第一行表示样例数m，接下来m行每行一个整数N

输入：
2
2
-1
输出：
9
-3

*/

int add(int n) {
	int sum = 0;
	for (int i = n; i <= 2*n; i++) {
		sum = sum + i;
	}
	return sum;
}


int main(int argc, char *argv[]) {
	int m;
	scanf("%d", &m);
	while (m--) {
		int n;		
		scanf("%d", &n);
		int sum = 0;
		if (n > 0) {
			sum = add(n);
			printf("%d\n", sum);
		} else if (n < 0) {
			sum = add(-n);
			printf("-%d\n", sum);
		} else {
			printf("0\n");
		}
	}
}