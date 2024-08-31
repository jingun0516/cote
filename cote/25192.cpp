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


	set<string> setStr;

	int answer = 0;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "ENTER") {
			setStr.clear();
			continue;
		}
		int befSize = setStr.size();
		setStr.insert(str);
		if (befSize != setStr.size()) {
			answer++;
		}
	}
	cout << answer;
}

// https://www.acmicpc.net/problem/25192