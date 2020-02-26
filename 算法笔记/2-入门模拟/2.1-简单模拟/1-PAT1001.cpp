#include <iostream>
#include <cstdio>
using namespace std;


/*

PAT B1001 害死人不偿命的3n+1猜想
输入：
3
输出：
5


*/

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int count = 0;
		while (n != 1) {
			if (n % 2 == 0) {
				 n = n / 2;
				count++;
			} else {
				n = (3 * n + 1);
				n = n / 2;
				count++;
			}
			
		}
		printf("%d\n", count);
	}
}