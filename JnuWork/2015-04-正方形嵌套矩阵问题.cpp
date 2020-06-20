#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n, m, a;
	scanf("%d %d %d", &n, &m, &a);
	int result;
	//默认n > m
	if (a > n) {
		result = 1;
	} else if (m < a < n) {
		result = n / a + 1;
	} else { // a < m
		result = (n / a + 1) * (m / a + 1);
	}
	printf("%d", result);
	system("pause");
	return 0;
}