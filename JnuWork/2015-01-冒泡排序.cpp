#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	int a[1000];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n-1; i++) { //进行n-1趟比较
		for (int j = 0; j < n-i; j++) { //每趟进行n-i次比较
			if(a[j] > a[j+1]) {
				int temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}