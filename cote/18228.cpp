#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<long> ice(N);
	int penguin = 0;

	for (int i = 0; i < N; i++) {
		cin >> ice[i];
		if (ice[i] == -1) {
			penguin = i;
		}
	}

	long answer = 0;
	long left = 1000000001;
	for (int i = 0; i < penguin; i++) {
		if (ice[i] < left) {
			left = ice[i];
		}
	}

	long right = 1000000001;
	for (int i = N - 1; i > penguin; i--) {
		if (ice[i] < right) {
			right = ice[i];
		}
	}
	answer = left + right;

	cout << answer;
}
