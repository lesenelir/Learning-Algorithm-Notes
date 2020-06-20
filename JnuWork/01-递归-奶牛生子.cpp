#include <iostream>

using namespace std;

int cow_number(int n) {
	if (n <= 4) return n;
	else return cow_number(n-1) + cow_number(n-3); 
}


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		int result = 0;
		result = cow_number(n);
		printf("%d\n", result);	
	}
}