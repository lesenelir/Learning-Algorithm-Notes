#include <iostream>
#include <cstdio>
using namespace std;

/*

二叉树（北京大学）P137

*/

int CountNodes (int n, int m) {
	if (m > n) return 0;
	// 把问题问分解成求左子树和右子树的结点数的合集
	else return CountNodes(n, m * 2) + CountNodes(n, m * 2 + 1) + 1;
}

int main(int argc, char *argv[]) {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		int res = CountNodes(n, m);
		printf("%d\n", res);
	}
}