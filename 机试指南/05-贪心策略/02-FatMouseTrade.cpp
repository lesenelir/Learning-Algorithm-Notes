#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

FatMouse' Trade P119

备注：
简单贪心重有类似于性价比的问题，即要求出物品的单价问题，优先选取单价最高的物品
这种题，类似于月饼的贪心问题

*/
const int maxn = 1010;

struct JavaBean {
	double weight;
	double cost;
	double price; // 单价 性价比
} arr[maxn];

bool cmp(JavaBean a, JavaBean b) {
	return a.price > b.price;
}


int main(int argc, char *argv[]) {
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {
		if (m == -1 && n == -1) break;
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &arr[i].weight, &arr[i].cost);
			arr[i].price = arr[i].weight / arr[i].cost;
		}
		sort(arr, arr + n, cmp);
		double ans = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i].cost <= m) { // 全部买下
				m = m - arr[i].cost;
				ans = ans + arr[i].weight;
			} else {
				ans = ans + arr[i].price * m;
				break; // 【不能省略】	
			}
		}
		printf("%.3f\n", ans);
	}
}