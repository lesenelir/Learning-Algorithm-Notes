#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct student {
	char name[9];
	int chinese;
	int math;
	int english;
	int id;
	int sum;
}stu[1001];

bool cmp(student a, student b) {
	if (a.sum != b.sum) {
		return a.sum > b.sum;
	} else {
		return a.id < b.id;
	}
}


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%s %d %d %d", stu[i].name, &stu[i].chinese, &stu[i].math, &stu[i].english);
			stu[i].id = i;
			stu[i].sum = stu[i].chinese + stu[i].math + stu[i].english;
		}
		sort(stu, stu + n, cmp);
		printf("%s %d %d %d\n", stu[0].name, stu[0].chinese, stu[0].math, stu[0].english);
		
	}
	
	return 0;
}