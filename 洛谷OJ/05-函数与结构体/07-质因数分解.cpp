#include <cstdio>
#include <iostream>
using namespace std;


/*

找质因子数所得乘积最大的

*/

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = n-1; i >= 2; i--) {
			if (n % i == 0) {
				printf("%d\n", i);
				break;
			}
		}		
	}
	return 0;
}