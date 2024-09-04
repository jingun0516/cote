#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <limits.h>

using namespace std;

bool endsWith(string str, string inStr) {
	if (inStr.length() > str.length()) return false;

	return str.compare(str.length() - inStr.length(), inStr.length(), inStr) == 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> pizza(n);
	for (int i = 0; i < n; i++) {
		cin >> pizza[i];
	}

	set<string> strSet;
	for (auto pz : pizza) {
		if (endsWith(pz, "Cheese"))
			strSet.insert(pz);

		if (strSet.size() >= 4) {
			cout << "yummy";
			return 0;
		}
	}
	cout << "sad";
}

// 서로 다른 치즈가 네 개 이상 들어가면 yummy, 아니면 sad 
// compare => == 0 일 때 일치하는 것