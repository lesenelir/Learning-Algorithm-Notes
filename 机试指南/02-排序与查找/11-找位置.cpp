#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

找位置（华科）
从头开始遍历字符串，对于第一个字符，找到后面和它相等的所有字符串的位置，并记录、标记，如果总数大于1则输出
对于a字符来说：
b[0] = 0, b[1] = 3, b[2] = 4, 

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	char str[maxn];
	while (scanf("%s", str) != EOF) {
		int len = strlen(str);
		int flag[maxn]; // 标记数组
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < len; i++) {
			if (flag[i] == 1) continue; // 该字符已经统计过了
			int b[maxn], num = 0; // b数组存放与str[i]字符相同的下标
			b[num++] = i;
			for (int j = i + 1; j < len; j++) {
				if (str[i] == str[j]) {
					flag[j] = 1; // 标记数组后面元素j的标记数组为1
					b[num++] = j; // 存放下标
				}
			}
			if (num > 1) { // b数组元素大于1 则代表有重复的数字
				for (int j = 0; j < num; j++) {
//					if (j != 0) printf(",");
					printf("%c:%d,", str[i], b[j]);
				}
				printf("\b");
				printf("\n");
			}
		}
	}
}