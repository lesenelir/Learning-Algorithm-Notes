#include <iostream>
#include <cstdio>
using namespace std;

/*
	
	二分查找

*/

const int n = 10;

int binarySearch(int a[], int left, int right, int x) {
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (a[mid] == x) {
			return mid;
		} else if (a[mid] > x) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}


int main(int argc, char *argv[]) {
	int a[n] = {1, 3, 4, 6, 7, 8, 10, 11, 12, 15};
	printf("%d %d\n", binarySearch(a,0,n-1,6), binarySearch(a,0,n-1,9));
}