#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*

全排列（北京大学） P135	

*/
const int maxn = 7;
int n;
char P[maxn];  // P为当前排列
bool hashTable[maxn] = {false}; // hashTable记录x是否已经在p中


void generateP(int index, char str[]) {
	if (index == n) {
		for (int i = 0; i < n; i++) {
			printf("%c", P[i]); // 输出当前排列
		}
		printf("\n");
		return;
	}
	for (int x = 0; x < n; x++) { // 枚举1 ~ n
		if (hashTable[x] == false) { // 如果x不在p[0]~p[index-1]中
			P[index] = str[x]; // 令p的index位为先，即把str[x]加入当前排列	
			hashTable[x] = true;
			generateP(index + 1, str); // 处理排列index + 1位
			hashTable[x] = false; // 处理完P[index]为x的子问题，还原状态
		}
	}
}


int main(int argc, char *argv[]) {
	char str[maxn];
	while (scanf("%s", str) != EOF) {
		n = strlen(str);
		sort(str, str + n);
		generateP(0, str);
		printf("\n");
	}
}