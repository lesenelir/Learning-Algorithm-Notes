#include <iostream>
#include <cstdio>
using namespace std;

/*

考试座位号 P29

*/
struct student {
	long long id;
	int Seat; // 试机座位
	int examSeat; // 考试座位
}stu[100];


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%lld %d %d", &stu[i].id, &stu[i].Seat, &stu[i].examSeat);
		}
		int m;
		scanf("%d", &m);
		int x;
		for (int i = 0; i < m; i++) {
			scanf("%d", &x);
			for (int j = 0; j < n; j++) {
				if (stu[j].Seat == x) {
					printf("%lld %d\n", stu[j].id, stu[j].examSeat);
					break;
				}
			}
		}
	}
}