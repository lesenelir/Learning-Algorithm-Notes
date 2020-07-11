#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 100001;
const int NIL = -1;

struct Node {
	int p, l, r;
} T[maxn];

int n;


void preOrder(int u) {
	if (u == NIL) return;
	printf(" %d", u);
	preOrder(T[u].l);
	preOrder(T[u].r);
}

void inOrder(int u) {
	if (u == NIL) return;
	inOrder(T[u].l);
	printf(" %d", u);
	inOrder(T[u].r);
}

void postOrder(int u) {
	if (u == NIL) return;
	postOrder(T[u].l);
	postOrder(T[u].r);
	printf(" %d", u);
}


int main() {
	int v, l, r, root;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) { // 初始化
			T[i].p = NIL;
		}	
		
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &v, &l, &r);
			T[v].l = l;
			T[v].r = r;
			if (l != NIL) T[l].p = v;
			if (r != NIL) T[r].p = v;
		}
		
		for (int i = 0; i < n; i++) {
			if (T[i].p == NIL) root = i;
		}
		printf("PreOrder\n");
		preOrder(root);
		printf("\n");
		
		printf("InOrder\n");
		inOrder(root);
		printf("\n");
		
		printf("PostOrder\n");
		postOrder(root);
		printf("\n");
	}
	return 0;
}