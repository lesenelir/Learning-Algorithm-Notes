#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int m;
	while (scanf("%d", &m) != EOF) {
		while (m != 0) {
			int n;
			scanf("%d", &n);
			int a[100][100], num = 1;
			for (int i = 0; i < n/2; i++) { //循环n/2层，若n为奇数时，最后一层单独输出
				//上
				for (int j = i; j < n-i-1; j++) {
					a[i][j] = num++;
				}
				//右
				for (int j = i; j < n-i-1; j++) {
					a[j][n-i-1] = num++;
				}
				//下
				for (int j = n-i-1; j > i; j--) {
					a[n-i-1][j] = num++;
				}
				//左
				for (int j = n-i-1; j > i; j--) {
					a[j][i] = num++;
				}
				
			}
			if (n % 2 != 0) a[n/2][n/2] = num;
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					printf("%d\t", a[i][j]);
				}
				printf("\n");
			}
			
			m--;
		}
	}
}