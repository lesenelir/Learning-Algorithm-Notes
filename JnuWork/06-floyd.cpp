#include <iostream>

using namespace std;

int n, m;//n顶点数，m边数
int dis[100][100];

void Floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int u, v, w;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		dis[i][i] = 0;
	}	
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		dis[u][v] = w;//有向图
	}
	Floyd();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", dis[i][j]);
		}
		printf("\n");
	}
	
}