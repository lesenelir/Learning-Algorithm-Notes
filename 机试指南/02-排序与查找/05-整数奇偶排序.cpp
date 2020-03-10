#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

整数奇偶排序

*/

bool cmp(int a, int b) {
	return a > b;
}


int main(int argc, char *argv[]) {
	int a[10];
	while (scanf("%d", &a[0]) != EOF) {
		for (int i = 1; i < 10; i++) {
			scanf("%d", &a[i]);
		}
		int odd[10], num_odd = 0; // 奇
		int even[10], num_even = 0; // 偶
		for (int i = 0; i < 10; i++) {
			if (a[i] % 2 == 0) {
				even[num_even++] = a[i];
			} else {
				odd[num_odd++] = a[i];
			}
		}
		sort(odd, odd + num_odd, cmp);
		sort(even, even + num_even);
		for (int i = 0; i < num_odd; i++) {
			printf("%d ", odd[i]);
		}
		for (int i = 0; i < num_even; i++) {
			printf("%d ", even[i]);
		}
	}
	
}