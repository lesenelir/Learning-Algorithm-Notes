#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


/*

PAT 1020 月饼
输入第一行N为月饼种类数， D为市场最大需求总量数
第二行为N个整数 表示每个种类的月饼库存量
第三行为N个整数 表示每个种类的月饼总售价

输入：
3 20
18 15 10
75 72 45
输出：
94.50

思路：
计算出单价，从单价高到低开始卖出

备注：
很多贪心问题的存储都可以用结构体来存储

*/

const int maxn = 1010;

struct cakes{
	double store; // 库存
	double sell; // 总售价
	double price; // 单价
}cake[maxn];

bool cmp(cakes a, cakes b) {
	return a.price > b.price;
}


int main(int argc, char *argv[]) {
	int n;
	double D;
	while (scanf("%d %lf", &n, &D) != EOF) {
		for (int i = 0; i < n; i++) { 
			scanf("%lf", &cake[i].store); // 输入库存
		}
		for (int i = 0; i < n; i++) { 
			scanf("%lf", &cake[i].sell); // 输入总售价
			cake[i].price = cake[i].sell / cake[i].store; // 计算单价
		}
		
		sort(cake, cake+n, cmp);
		
		double ans = 0;
		
		for (int i = 0; i < n; i++) {
			if (cake[i].store <= D) { // 需求量高于月饼库存量
				D = D - cake[i].store; // 需求量减去当前单价最高的月饼所有库存量
				ans = ans + cake[i].sell; // 收益加上单价最高月饼的总售价
			} else { // 月饼库存高于需求量
				ans = ans + cake[i].price * D; // 只卖出需求量的月饼
				break;
			}
		}
		printf("%.2f\n", ans);	
	}
}