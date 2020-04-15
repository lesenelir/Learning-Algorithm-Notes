#include <cstdio>
#include <iostream>
using namespace std;

/*

神奇的魔方
关键点就是存储上一个点坐标的值
类似于 螺旋矩阵

*/
const int maxn = 41;
int a[maxn][maxn] = {0};

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int num = 1;
		int posx, posy; // 上一个点的坐标
		while (num <= n * n) {
			if (num == 1) {
				a[1][n/2 + 1] = num++;
				posx = 1;
				posy = n/2 + 1;
			} else if (posx == 1 && posy != n) {
				a[n][posy + 1] = num++;
				posx = n;
				posy = posy + 1;
			} else if (posx != 1 && posy == n) {
				a[posx-1][1] = num++;
				posx = posx - 1;
				posy = 1;
			} else if (posx == 1 && posy == n) {
				a[posx+1][posy] = num++;
				posx = posx + 1;
				posy = posy;
			} else if (posx != 1 && posy != n) {
				if (a[posx-1][posy+1] == 0) {
					a[posx-1][posy+1] = num++;
					posx = posx - 1;
					posy = posy + 1;
				} else {
					a[posx+1][posy] = num++;
					posx = posx + 1;
					posy = posy;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}	
	}	
	return 0;
}