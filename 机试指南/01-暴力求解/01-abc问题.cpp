#include <iostream>
#include <cstdio>
using namespace std;

/*

abc问题：
abc + bcc = 532 求满足所有的a b c 值

*/


int main(int argc, char *argv[]) {
	for (int a = 0; a <= 9; a++) { 
		for (int b = 0; b <= 9; b++) {
			for (int c = 0; c <= 9; c++) {
				if (a * 100 + b * 10 + c + b * 100 + c * 10 + c == 532) {
					printf("%d %d %d\n", a, b, c);
				}
			}
		}
	}
}