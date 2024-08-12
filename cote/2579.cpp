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

	// dp[i] => i ���� �ִ� ����
	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];
	for (int i = 3; i <= N; i++)
	{
		dp[i] = max(dp[i - 3] + stairs[i - 1] + stairs[i], dp[i - 2] + stairs[i]);
		// i-2�������� �� + i , i-3�������� �� + i-1 + i �� �ִ�
	}
	/*for (auto k : dp)
		cout << k << "\n";*/

	cout << dp[N];

}

// �� ���� �Ѱ�� or �ΰ��
// ���ӵ� �� ���� ��� X
// ������ ��ܿ� ���� X
// ������ ��� �ݵ��