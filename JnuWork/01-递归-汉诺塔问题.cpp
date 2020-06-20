#include <iostream>

using namespace std;

void Hanoi(int n, char a, char b, char c) {
	if (n == 1) printf("%c ---> %c\n", a, c);
	else {
		Hanoi(n-1, a, c, b);//不止一个盘子借助c把n-1盘子移到b
		printf("%c ---> %c\n", a, c);
		Hanoi(n-1, b, a, c);
	}
}



int main(int argc, char *argv[]) {
	printf("汉诺塔移动步骤：\n");
	Hanoi(3, 'a', 'b', 'c');
}