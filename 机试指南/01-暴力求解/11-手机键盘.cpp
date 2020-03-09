#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

手机键盘

*/

int alpha[26] = {         
	1, 2, 3,    // a, b, c         
	1, 2, 3,    // d, e, f         
	1, 2, 3,    // g, h, i         
	1, 2, 3,    // j, k, l         
	1, 2, 3,    // m, n, o         
	1, 2, 3, 4, // p, q, r, s         
	1, 2, 3,    // t, u, v         
	1, 2, 3, 4 // w, x, y, z         
}; //存储输入每个小写字母时需要的时间         

int keys[26] = {         
	1, 1, 1, // a, b, c         
	2, 2, 2, // d, e, f         
	3, 3, 3, // g, h, i         
	4, 4, 4, // j, k, l         
	5, 5, 5, // m, n, o         
	6, 6, 6, 6, // p, q, r, s         
	7, 7, 7, // t, u, v         
	8, 8, 8, 8// w, x, y, z         
}; // 对字母进行分组，以确定在一个按键上面的字母         


int main(int argc, char *argv[]) {
	char str[100];
	while (scanf("%s", str) != EOF) {
		int count = 0;
		char pre = '#'; // 存储前一个字母
		for (int i = 0; i < strlen(str); i++) {
			if (keys[pre - 'a'] == keys[str[i] - 'a']) {
				count = count + 2;
			}
			count = count + alpha[str[i] - 'a'];
			pre = str[i];
		}
		printf("%d\n", count);
	}
}