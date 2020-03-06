#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

/*

分数的操作运算

分数化简规则：
1.down必须是非负数，如果分数是负数，则另up为负
2.如果分数是0，则规定分子是0，分母为1
3.分子和分母没有除了1以外的公约数（约分）

分数的输出规则：
1.输出分数要对其进行化简
2.如果分数的分母down为1，说明分数是整数，直接输出分子 忽略分数
3.如果分子up绝对值大于分子down，则是假分数，带分数形式输出：整数r.up/r.down，分子abs(r.up)%r.down
4.以上均不满足就是真分数，按照原样输出

*/

struct Fraction {
	int up, down; // 分子 分母
};

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

// 分数的化简
Fraction reduction(Fraction result) {
	if (result.down < 0) {
		result.up = -result.up;
		result.dowm = -result.down;
	}
	if (result.up == 0) {
		result.down = 1;
	} else { // 分子不为0进行约分
		int d = gcd(abs(result.up), abs(result.down)); // 分子分母的最大公约数
		result.up = result.up / d; // 去除分子的最大公约数
		result.down = result.down / d;
	}
	return result;
}

// 分数的加法
Fraction add(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result); // 返回分数 并化简
}

// 分数的减法
Fraction minu(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down - f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

// 分数的乘法
Fraction muli(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}

// 分数的除法
Fraction divide(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}

// 分数的输出
void showResult(Fraction r) {
	r = reduction(r);
	if (r.down == 1) printf("%lld", r.up);
	else if (abs(r.up) > r.down) {
		printf("%d %d/%d", r.up / r.down, abs(r.up) % r.down, r.down);
	} else {
		printf("%d/%d", r.up, r.down);
	}
}



int main(int argc, char *argv[]) {
	
}