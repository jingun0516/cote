#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> stairs(N + 1, 0);
	vector<int> dp(N + 1, 0);

	for (int i = 1; i <= N; i++)
		cin >> stairs[i];

	// dp[i] => i 까지 최대 점수
	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];
	for (int i = 3; i <= N; i++)
	{
		dp[i] = max(dp[i - 3] + stairs[i - 1] + stairs[i], dp[i - 2] + stairs[i]);
		// i-2번까지의 합 + i , i-3번까지의 합 + i-1 + i 중 최댓값
	}
	/*for (auto k : dp)
		cout << k << "\n";*/

	cout << dp[N];

}

// 한 번에 한계단 or 두계단
// 연속된 세 개의 계단 X
// 시작점 계단에 포함 X
// 마지막 계단 반드시