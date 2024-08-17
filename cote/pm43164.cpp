#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int num;
vector<vector<string>> temp_ans;
vector<string> answer;

bool compare(vector<string>& a, vector<string>& b)
{
	int minSize = min(a.size(), b.size());
	for (int i = 0; i < minSize; i++)
	{
		if (a[i] == b[i]) continue;

		return a[i] < b[i];
	}
	return false;
}

void dfs(map<string, vector<pair<string, bool>>>& maps, string start, vector<string>& ans)
{
	if (ans.size() == num + 1) // num은 '항공권'의 수
	{
		temp_ans.push_back(ans);
		return;
	}

	for (auto& m : maps[start])
	{
		if (!m.second)
		{
			ans.push_back(m.first);
			m.second = true;

			dfs(maps, m.first, ans);

			m.second = false;
			ans.pop_back();
		}
	}
}


vector<string> solution(vector<vector<string>> tickets) {;
	map<string, vector<pair<string,bool>>> maps;

	num = tickets.size();

	for (auto t : tickets)
	{
		maps[t[0]].push_back(make_pair(t[1], false));
	}

	vector<string> ans;
	ans.push_back("ICN");

	dfs(maps, "ICN", ans);
	
	sort(temp_ans.begin(), temp_ans.end(), compare);

	answer = temp_ans[0];

	for (auto m : answer)
		cout << m << " ";

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<string>> tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};

	solution(tickets);
}
