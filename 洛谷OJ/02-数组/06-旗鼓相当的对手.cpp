#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

struct student {
	int chinese;
	int math;
	int english;
	int sum;
}stu[1001];

bool same(int x, int y) {
	if (
		(abs(stu[x].chinese - stu[y].chinese)) <= 5 &&
		(abs(stu[x].math - stu[y].math)) <= 5 &&
		(abs(stu[x].english - stu[y].english)) <= 5 &&
		(abs(stu[x].sum - stu[y].sum)) <= 10 
	) {
		return true;
	}
	return false;
}



int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &stu[i].chinese, &stu[i].math, &stu[i].english);
			stu[i].sum = stu[i].chinese + stu[i].math + stu[i].english;
		}
		int count = 0;
		for (int i = 0; i < n; i++) { // 从i的下一位开始遍历有去重功能
			for (int j = i + 1; j < n; j++) {
				if (same(i, j) == true) {
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}