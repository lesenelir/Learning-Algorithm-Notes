#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int n, a;
	printf("请输入游戏数字范围:\n");
	scanf("%d", &n);
	printf("请输入你的数字范围：\n");
	scanf("%d", &a);
	int left = 1, right = n;
	int count = 0;
	int mid = (left + right) / 2;
	while (a != mid) {
		if (mid > a) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
		mid = (left + right) / 2;
		count++;
	}
	printf("至少需要%d才能找到A的数字", count);
}