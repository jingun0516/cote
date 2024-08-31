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
	
	vector<double> drink(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> drink[i];
	}

	sort(drink.begin(), drink.end(), greater<double>());

	double answer = drink[0];

	for (int i = 1; i < n; i++) {
		answer += drink[i] / 2.0;
	}
	cout << answer;
}

// https://www.acmicpc.net/problem/20115