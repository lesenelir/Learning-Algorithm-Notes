#include <iostream>
#include <cstdio>
using namespace std;

/*

B1038 统计同成绩学生 P131

*/
const int maxn = 1010;
int A[maxn];
int B[maxn];

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int hashTable[100] = {0}; // 散列思想，数组数值存储下标i出现的次数
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
			hashTable[A[i]]++; // 散列有一种，通常在输入的时候就统计次数
		}
		int k;
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &B[i]);
			printf("%d ", hashTable[B[i]]);
		}
		printf("\n");
		
	}
}