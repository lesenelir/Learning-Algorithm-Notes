#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

设N是一个四位数，它的9倍恰好是其反序数（例如：1234的反序数是4321）
求N的值

*/

int main(int argc, char *argv[]) {
	for (int n = 1000; n < 10000; n++) {
		int a[10], num = 0;
		memset(a, 0, sizeof(a));
		
		for (int i = 0; i < 4; i++) { // a[0]存储个位
			a[num++] = n % 10;
			n = n / 10;
		}
		
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			sum = sum * 10 + a[i];
		}
		
		if (sum == n * 9) {
			printf("%d\n", n);
		}
		
	}
}