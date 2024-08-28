#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int dp[100001];
	
	int answer = 0;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 2;
	dp[5] = 1;
	dp[6] = 2;
	dp[7] = 1;

	for (int i = 8; i <= n; i++) {
		dp[i] = min({ dp[i - 1], dp[i - 2], dp[i - 5], dp[i - 7] }) + 1;
	}
	cout << dp[n];
}
// https://www.acmicpc.net/problem/17212
//  1원, 2원, 5원, 7원