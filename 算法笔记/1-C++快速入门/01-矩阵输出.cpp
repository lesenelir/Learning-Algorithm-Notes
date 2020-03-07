#include <iostream>
#include <cstdio>
using namespace std;

/*

输出矩形，每个数字占3个字符，右对齐
1  2  3  4  5
2  4  6  8 10
3  6  9 12 15
4  8 12 16 20

*/

int main(int argc, char *argv[]) {	
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 5; j++) {
			printf("%3d", i * j);
		}
		printf("\n");
	}	
}