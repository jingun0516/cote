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

	vector<long long> muscle(n, 0);

	for (int i = 0; i < n; i++)
		cin >> muscle[i];

	sort(muscle.begin(), muscle.end());

	int start = 0;
	int end = n - 1;

	long long answer = 0;

	long long temp = 0;

	if (n % 2 == 0)
	{
		while (start < end)
		{
			temp = muscle[start++] + muscle[end--];
			answer = max(temp, answer);
		}
	}
	else
	{
		answer = muscle[n - 1];
		end--;
		while (start < end)
		{
			temp = muscle[start++] + muscle[end--];
			answer = max(temp, answer);
		}
	}
	cout << answer;

}
// ´Ù ÇÑ¹ø¾¿ °ñ¶úÀ» ¶§ (2°³¾¿) ÃÖ¼Ú°ª