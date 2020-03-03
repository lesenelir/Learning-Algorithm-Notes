#include <iostream>
#include <cstdio>
using namespace std;


/*

某市出租车计价规则如下：起步4公里10元，即使你的行程没超过4公里；接下来的4公里，每公里2元；之后每公里2.4元。行程的最后一段即使不到1公里，也当作1公里计费。

一个乘客可以根据行程公里数合理安排坐车方式来使自己的打车费最小。
例如，整个行程为16公里，乘客应该将行程分成长度相同的两部分，每部分花费18元，总共花费36元。
如果坐出租车一次走完全程要花费37.2元。现在给你整个行程的公里数，请你计算坐出租车的最小花费。

n表示公里数

输入：
3
9
16
0
输出：
10
20.4
36

*/

// 车费计算函数
double fee(double l){
	int n = ceil(l);
	if(n <= 4){
		return 10;
	}else if(n <= 8){
		return 10 + 2 * (n - 4);
	}else{
		return 18 + 2.4 * (n - 8);
	}
} 


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		double total = 0.0;
		while(n > 0){
			if(n <= 12){
				total += fee(n);
				break;
			}else{
				total += fee(8);
				n -= 8;
			}
		}
		int temp = (int)total;
		if (temp - total){
			cout << fixed << setprecision(1) << total << endl;
		}else {
			cout << temp << endl;
		}
	}
}