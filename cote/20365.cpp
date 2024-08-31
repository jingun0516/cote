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

	string str;
	cin >> str;

	int answer = 1;

	int cnt = 0;
	for (int i = 1; i < str.length(); i++) {
		if (str[i] != str[0]) cnt++;
		if (cnt == 0) continue;
		if (str[i] == str[0] || i == str.length() - 1) {
			answer++;
			cnt = 0;
		}
	}

	cout << answer;
}

// https://www.acmicpc.net/problem/20365