#include <iostream>

using namespace std;
/*此题类似于codeup中的剩下的树问题*/
int main(int argc, char *argv[]) {
	int L, m;
	while (scanf("%d %d", &L, &m) != EOF) {
		int a[100];
		int x, y;
		//当a[i]中数组元素值为1的时候表示树的数量
		for (int i = 0; i <= L; i++) { //种树
			a[i] = 1; 
		}
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			for (int j = x; j <= y; j++) { //去树
				a[j] = 0;
			}
		}
		int count = 0;
		for (int i = 0; i <= L; i++) {
			if (a[i] != 0) {
				count++;
			}
		}
		printf("%d\n", count);
	}
	system("pause");
	return 0;
}