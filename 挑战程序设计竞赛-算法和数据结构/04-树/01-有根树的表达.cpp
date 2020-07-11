#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 100001;
const int NIL = -1;


struct Node {
	int p, l, r;
} T[maxn];

int n;
int D[maxn]; // 深度数组

void print(int u) {
	printf("node %d: parent = %d, depth = %d, ", u, T[u].p, D[u]);
	
	if (T[u].p == NIL) printf("root, ");
	else if (T[u].l == NIL) printf("leaf, "); // 不存在最左侧的结点
	else printf("internal node, ");
	
	printf("[");
	for (int i = 0, c = T[u].l; c != NIL; i++, c = T[c].r) {
		if (i) printf(", ");
		printf("%d", c);
	}
	printf("]\n");
}

// 递归求深度，保存在D数组中
int setDepth(int u, int p) {
	D[u] = p;
	if (T[u].r != NIL) setDepth(T[u].r, p); // 右侧兄弟设置相同深度
	if (T[u].l != NIL) setDepth(T[u].l, p + 1); // 左侧子结点深度设置为自己深度+1
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) { // 初始化 
			T[i].p = T[i].l = T[i].r = NIL;
		}
		int v, d, c, l, r;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &v, &d);
			for (int j = 0; j < d; j++) {
				scanf("%d", &c);
				if (j == 0) T[v].l = c; // j==0叶子结点设置它的最左结点
				else T[l].r = c;
				l = c;
				T[c].p = v;
			}
		}
		for (int i = 0; i < n; i++) {
			if (T[i].p == NIL) r = i;
		}
		
		setDepth(r, 0);
		for (int i = 0; i < n; i++) {
			print(i);
		}
	}
	return 0;
}