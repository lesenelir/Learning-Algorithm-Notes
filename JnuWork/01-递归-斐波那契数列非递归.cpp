#include <cstdio>
#include <iostring>

using namespace std;

int main(int argc, char *argv[]) {
	int temp1 = 1, temp2 = 1, temp3;
	int n;
	scanf("%d", &n);
	if (n <= 2) {
		temp3 = 1;
	} else {
		for (int i = 3; i <= n; i++) {
			temp3 = temp1+ temp2;
			temp1 = temp2;
			temp2 = temp3;
		}
	}
	printf("%d", temp3);
}