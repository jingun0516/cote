#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	cin >> S;

	vector<vector<int>> psum(26, vector<int>(S.length() + 1, 0));

	for (int i = 0; i < S.length(); i++)
	{
		psum[S[i] - 'a'][i]++;
	}

	for (int i = 0; i < 26; i++)
	{
		for (int j = 1; j < S.length(); j++)
		{
			psum[i][j] += psum[i][j-1];
		}
	}
	

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		char a;
		int b, c;
		cin >> a >> b >> c;

		if (b == 0)
			cout << psum[a - 'a'][c] << "\n";
		else
			cout << psum[a - 'a'][c] - psum[a - 'a'][b - 1] << "\n";
	}
}
