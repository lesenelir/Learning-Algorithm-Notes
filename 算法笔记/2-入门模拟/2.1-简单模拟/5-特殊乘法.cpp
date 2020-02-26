#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

写个算法，对2个小于1000000000的输入，求结果。特殊乘法举例：123 * 45 = 1*4 +1*5 +2*4 +2*5 +3*4+3*5
输入：
24 65
42 66666
3 67
输出：
66
180
39

备注：
a[i]-'0'是把字符数组中的字符（本质是数字）转换为int类型的数字
*/


int main(int argc, char *argv[]) {
	char s1[20], s2[20];
	while (scanf("%s %s", s1, s2) != EOF) {
		int len1 = strlen(s1), len2 = strlen(s2);
		
		int res = 0;
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				res += (s1[i] - '0') * (s2[j] - '0');
			}
		}
		printf("%d\n", res);
	}
	
}