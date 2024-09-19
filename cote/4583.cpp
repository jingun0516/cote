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

	string str = "";
	vector<char> alpha = { 'b','d','p','q', 'i', 'o','v','w','x' };
	// b와 d나 p와 q는 서로 거울상 관계이다. 또한 i,o,v,w와 x
	while (1) {
		cin >> str;
		if (str == "#") break;

		bool check = false;
		for (auto s : str) {
			if (find(alpha.begin(), alpha.end(), s) == alpha.end()) {
				check = true;
				break;
			}
		}

		if (check) {
			cout << "INVALID\n";
			continue;
		}

		reverse(str.begin(), str.end());

		for (auto& t : str) {
			if (t == 'b') t = 'd';
			else if (t == 'd') t = 'b';
			else if (t == 'p') t = 'q';
			else if (t == 'q') t = 'p';
		}

		cout << str << "\n";

	}

}
