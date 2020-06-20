#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	char ch;
	while ((ch=getchar()) != '.') {
		int a = 0, b = 0;
		int flag = 0; //关键步骤 
		if (ch == '\n') {
			a++;
		}else if (ch == 'a') {
			flag = 1;
		}else if (ch == 't' && flag == 1) {
			b++;
		} else {
			flag = 0;
		}
		printf("%d %d", a, b);
		getchar(); //回收换行符
	}
}