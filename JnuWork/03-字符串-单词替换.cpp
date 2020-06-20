#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
	char s[100];
	while (gets(s) != NULL) {
		int len = strlen(s);
		char a[100], b[100];
		char ans[100][100];
		int r = 0, h = 0; //r行，h列，行
		for (int i = 0; i < len; i++) {
			if (s[i] != ' ') {
				ans[r][h++] = s[i];
			} else {
				ans[r][h] = '\0';
				r++;
				h = 0;
			}
		}
		gets(a);
		gets(b);
		for (int i = 0; i <= r; i++) {
			if (strcmp(ans[i], a) == 0) {
				strcpy(ans[i], b);
			}
			printf("%s", ans[i]);
			if (i < r) printf(" ");
			else printf("\n");
		}
	}
}