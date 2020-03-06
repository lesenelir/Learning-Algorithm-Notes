#include <iostream>
#include <cstdio>
using namespace std;

/*

求1-n内的完数，所谓的完数是这样的数，它的所有因子相加等于它自身，比如6有3个因子1,2,3,1+2+3=6，那么6是完数。即完数是等于其所有因子相加和的数。

输入：
6
输出：
6

*/

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j < i; j++) {
				if (i % j == 0) sum = sum + j;
			}
			if (sum == i) printf("%d ", i);
		}
		printf("\n");
	}
}