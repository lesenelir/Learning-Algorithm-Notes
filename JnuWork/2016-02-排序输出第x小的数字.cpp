#include <iostream>
#include <algorithm>
using namespace std;

//利用sort()来排序
int main(int argc, char *argv[]) {
	int n, x;
	while (scanf("%d %d", &n, &x) != EOF) {
		int a[1000];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		printf("%d", a[x-1]);
	}	
}