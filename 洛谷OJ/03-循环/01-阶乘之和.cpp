#include <cstdio>
#include <iostream>
using namespace std;

/*

阶乘之和
S=1!+2!+3!+…+n!(n≤50)
*/


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int num = 1;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			num = 1; // num在每一次i的循环的时候都要重新赋值为1【易错】
			for (int j = 1; j <= i; j++) {
				num = num * j;
			}
			sum = sum + num;
		}	
		printf("%d\n", sum);	
	}
	return 0;
}