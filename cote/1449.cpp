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

	int N, L;
	cin >> N >> L;

	int water[1001] = { 0, };

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		water[temp] = 1;
	}

	int answer = 0;
	for (int i = 1; i <= 1000; i++) {
		if (water[i] == 1) {
			answer++;
			for (int j = i; j < i + L; j++) {
				if (j > 1000) break;
				water[j] = 0;
			}
		}
	}

	cout << answer;

}
// https://www.acmicpc.net/problem/1449