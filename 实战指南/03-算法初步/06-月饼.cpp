#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

B1020 月饼

*/
struct mooncake {
	double store;
	double sell;
	double price; // 单价
}cake[1010];

bool cmp(mooncake a, mooncake b) {
	return a.price > b.price;
}


int main(int argc, char *argv[]) {
	int n;
	double D;
	while (scanf("%d %lf", &n, &D) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%lf", &cake[i].store);
		}
		for (int i = 0; i < n; i++) {
			scanf("%lf", &cake[i].sell);
			cake[i].price = cake[i].sell / cake[i].store;
		}
		sort(cake,  cake + n, cmp);
		double ans = 0; // 收益
		for (int i = 0; i < n; i++) {
			if (cake[i].store <= D) {
				D = D - cake[i].store;
				ans = ans + cake[i].sell;
			} else { // 月饼库存高于需求量
				ans = ans + cake[i].price * D;
				break;
			}
		}
		printf("%.2f", ans);
	}
}