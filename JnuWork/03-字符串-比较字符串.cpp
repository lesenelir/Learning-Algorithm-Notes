#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
	int m;
	scanf("%d", &m);
	while (m > 0) {
		char a[1000], b[1000];
		scanf("%s %s", a, b);
		int lena = strlen(a);
		int lenb = strlen(b);
		if (lena == lenb) {
			printf("%s is equal long to %s", a, b);
		} else if (lena < lenb) {
			printf("%s is shorter than to %s", a, b);
		} else {
			printf("%s is longer than to %s", a, b);
		}
		m--;
	}
}