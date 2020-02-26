#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*
给定两个整数A和B，其表示形式是：从个位开始，每三位数用逗号","隔开。
现在请计算A+B的结果，并以正常形式输出。

输入（多组）：
-234,567,890 123,456,789
1,234 2,345,678
输出：
-111111101
2346912

备注：
此处不能用sscanf来解决，因为ssacnf只能是字符数组中只有数组
若char str[20] = "1,222";
sscanf(str, "%d", &n);
此时得到的结果是1

备注：
a[i] - '0' 把字符型数据转换为整型
数组存储是从左到右存储
*/



int main(int argc, char *argv[]) {
	char str1[255], str2[255];
	while (scanf("%s %s", str1, str2) != EOF) {
		int len1 = strlen(str1), len2 = strlen(str2);
		
		int num1 = 0, num2 = 0;
		for (int i = 0; i < len1; i++) {
			if (str1[i] >= '0' && str1[i] <= '9') {
				num1 = num1 * 10 + (str1[i] - '0'); // num*10是为了每进一个数字，高位*1
			}
		}
		if (str1[0] == '-') { // 正负号
			num1 = num1 * (-1);
		}
		
		for (int i = l0; i < len2; i++) {
			if (str2[i] >= '0' && str2[i] <= '9') {
				num2 = num2 * 10 + (str2[i] - '0');
			}
		}
		if (str2[0] == '-') { // 正负号
			num2 = num2 * (-1); 
		}
		
		printf("%d\n", num1 + num2);
	}
}