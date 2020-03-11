#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

/*

给定N个整数（可能有负数），从中选择K个数，使得这K个数之和恰好等于一个给定的整数X。如果有多种方案，选择它们中元素平方和最大的一个。数据保证这样的方案唯一

输入：
4 2 6
2 3 3 4
输出：
2 4

思想：
需要一个数组tmp，用以存放当前已选择的整数。这样当试图进入”选index号数“这条分支时，就把a[index]加入到tmp中；而当这条分支结束时，就把它从tmp中去除，使它不会影响”不选index号数“这条分支。接着，如果在某个时候发现当前已经选择了K个数，且这K个数之和恰好为x时，就去判断平方和是否比已有的最大平方和还要大，如果是，则更新最大值，并把tmp赋给用以存放最优方案的数组ans

*/

//平方和可能为0，所以初始值为-1 
int n, a[100], k, x, maxSumSqu = -1;
vector<int> temp, ans;

void DFS(int index, int nowX, int sum, int sumSqu) { // index 当前处理的整数编号 nowX当前选择数个数
	if (nowX == k && sum == x) {
		if (sumSqu > maxSumSqu) {
			maxSumSqu = sumSqu;
			ans = temp;
		}
		return;
	}	
	//这个判断不能放在第一步，因为index==n就return可能会错过最佳方案的更新 
	if(index == n || nowX > k || sum > x) return;
	//选index号
	temp.push_back(a[index]);  //记录当前数字a[index] 
	DFS(index + 1, nowX + 1, sum + a[index], sumSqu + a[index] * a[index]);
	//不选index号
	temp.pop_back(); //删除数字a[index] 
	DFS(index + 1, nowX, sum, sumSqu); //深度搜索不选index基本上都是在index上加1 其他参数不变
}



int main(int argc, char *argv[]) {
	scanf("%d %d %d", &n, &k, &x);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	DFS(0, 0, 0, 0);
	for(int i = 0;i < ans.size(); i++)
		printf("%d ",ans[i]);
}