#include <iostream>
#include <cstdio>
using namespace std;

/*

PAT 1023 组个最小数

测试用例每一行有十个数字，分别表示所拥有数字的个数， 编写程序尽可能的使得组合的数字最小

输入：
2 2 0 0 0 3 0 0 1 0
输出：
10015558

*/


int main(int argc, char *argv[]) {
	int a[10]; // 数组a[i]的值表示下标为i的数字出现了多少次
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 1; i < 10; i++) { // 从1~9找出一个最小的出现过的放在首位
		if (a[i] != 0) {
			printf("%d", i);
			a[i]--; // 出现数字减一
			break; // 找到一个推出循环
		}
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < a[i]; j++) { // 对于每一个下标为i的遍历数组a[i]
			printf("%d", i);
		}
	}
	
}