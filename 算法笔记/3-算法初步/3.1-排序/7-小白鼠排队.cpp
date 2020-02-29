#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

N只小白鼠(1 <= N <= 100)，每只鼠头上戴着一顶有颜色的帽子。
现在称出每只白鼠的重量，要求按照白鼠重量从大到小的顺序输出它们头上帽子的颜色。

输入第一行为一个整数N，表示小白鼠的数目。
下面有N行，每行是一只白鼠的信息。第一个为不大于100的正整数，表示白鼠的重量
第二个为字符串，表示白鼠的帽子颜色，字符串长度不超过10个字符。

输入：
1
79 omi
9
46 lcg
92 cru
37 ceq
54 vhr
17 wus
27 tnv
13 kyr
95 wld
34 qox
输出：
omi
wld
cru
vhr
lcg
ceq
qox
tnv
wus
kyr

*/

const int maxn = 1010;

struct mouse {
	int weight;
	char color[maxn];
}m[maxn];

bool cmp(mouse a, mouse b) {
	return a.weight > b.weight;
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d %s", &m[i].weight, m[i].color);
		}
		sort(m, m+n, cmp);
		for (int i = 0; i < n; i++) {
			printf("%s\n", m[i].color);
		}
	}
}