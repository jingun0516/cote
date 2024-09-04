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
	
	vector<int> budgets(n);

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> budgets[i];
		sum += budgets[i];
	}

	sort(budgets.begin(), budgets.end());

	long long total;
	cin >> total;

	if (total >= sum) {
		cout << budgets[n - 1];
		return 0;
	}

	int start = 0;
	int end = budgets[n - 1];

	int answer = 0, temp = 0;
	while (start <= end) {
		temp = 0;
		int middle = (start + end) / 2;

		for (auto b : budgets) {
			temp += min(b, middle);
		}

		if (temp > total) {
			end = middle - 1;
		}
		else {
			answer = middle;
			start = middle + 1;
		}
	}
	cout << answer;

}
// https://www.acmicpc.net/problem/2512