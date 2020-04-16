#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct student {
	char name[9];
	int chinese;
	int math;
	int english;
	int sum;
}stu[1001];

bool same(int x, int y) {
	if (
		(abs(stu[x].chinese - stu[y].chinese)) <= 5 &&
		(abs(stu[x].math - stu[y].math)) <= 5 &&
		(abs(stu[x].english - stu[y].english)) <= 5 &&
		(abs(stu[x].sum - stu[y].sum)) <= 10 
	) {
		return true;
	}
	return false;
}

bool cmp(student a, student b) {
	return a.name > b.name;
}


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%s %d %d %d", stu[i].name, &stu[i].chinese, &stu[i].math, &stu[i].english);
			stu[i].sum = stu[i].chinese + stu[i].math + stu[i].english;
		}
		sort(stu, stu + n, cmp);
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (same(i, j) == true) {
					printf("%s %s\n", stu[i].name, stu[j].name);
				}
			}
		}
		
	}
	
	return 0;
}