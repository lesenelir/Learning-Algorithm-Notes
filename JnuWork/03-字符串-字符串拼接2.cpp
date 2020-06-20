#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
	char str1[100];
	char str2[100];
	scanf("%s", str1);
	scanf("%s", str2);
	strcat(str1, str2);
	puts(str1);
}