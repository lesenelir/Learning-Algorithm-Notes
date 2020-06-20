#include <iostream>

using namespace std;

/*青蛙跳台阶问题类似于斐波那契数列数列*/
int jump_floor(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else return jump_floor(n-1) + jump_floor(n-2);
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int result = jump_floor(n);
		printf("%d\n", result);
	}	
}