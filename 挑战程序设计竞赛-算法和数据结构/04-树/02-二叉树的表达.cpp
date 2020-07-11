#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 100001;
const int NIL = -1;

struct Node {
	int parent, left, right;
} T[maxn];

int n, D[maxn], H[maxn]; // 深度数组，高度数组

void setDepth(int u, int d) {
	if (u == NIL) return;
	D[u] = d;
	setDepth(T[u].left, d + 1);
	setDepth(T[u].right, d + 1);
}

int setHeight(int u) {
	int h1 = 0, h2 = 0;
	if (T[u].left != NIL) h1 = setHeight(T[u].left) + 1;
	if (T[u].right != NIL) h2 = setHeight(T[u].right) + 1;
	return H[u] = (h1 > h2 ? h1 : h2);
}

// 返回结点u的兄弟结点
int getSibling(int u) {
	if (T[u].parent == NIL) return NIL;
	if (T[T[u].parent].left != u && T[T[u].parent].left != NIL) 
		return T[T[u].parent].left;
	if (T[T[u].parent].right != u && T[T[u].parent].right != NIL) 
		return T[T[u].parent].right;
	return NIL;
}


void print(int u) {
	printf("node %d: ", u);
	printf("parent = %d, ", T[u].parent);
	printf("sibling = %d, ", getSibling(u));
	int deg = 0; // 度数
	if (T[u].left != NIL) deg++;
	if (T[u].right != NIL) deg++;
	printf("degree = %d, ", deg);
	printf("depth = %d, ", D[u]);
	printf("height = %d, ", H[u]);
	
	if (T[u].parent == NIL) {
		printf("root\n");
	} else if (T[u].left == NIL && T[u].right == NIL) {
		printf("leaf\n");
	} else {
		printf("internal node\n");
	}
}


int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) T[i].parent = NIL;
		
		int v, l, r, root = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &v, &l, &r);
			T[v].left = l;
			T[v].right = r;
			if (l != NIL) T[l].parent = v;
			if (r != NIL) T[r].parent = v;
		}
		
		for (int i = 0; i < n; i++) {
			if (T[i].parent == NIL) root = i;
		}	
		
		setDepth(root, 0);
		setHeight(root);
		
		for (int i = 0; i < n; i++) {
			print(i);
		}
		
	}
	return 0;
}