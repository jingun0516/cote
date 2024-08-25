#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

map<string, int> maps;

bool compare(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

void bfs(string& str, int index)
{
	queue<pair<string, int>> qu;

	string first(1, str[index]);
	qu.push(make_pair(first, index));

	while (!qu.empty())
	{
		string tempStr = qu.front().first;
		int cnt = qu.front().second;
		qu.pop();

		for (int i = cnt + 1; i < str.length(); i++)		{
			string tempStr2 = tempStr + str[i];
			qu.push(make_pair(tempStr2, i));
			maps[tempStr2]++;
		}
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	for (int i = 0; i < orders.size(); i++)	{
		sort(orders[i].begin(), orders[i].end());  // �κ� ���ڿ��� ���ĵ� ���·� �����ǵ��� �̸� ����

		for (int j = 0; j < orders[i].length(); j++) {
			bfs(orders[i], j);
		}
	}

	for (int len : course) {
		int maxCount = 2;  // �ּ� 2�� �̻� ������ ���ڿ��� ���
		vector<string> candidates;

		for (auto& m : maps) {
			if (m.first.length() == len) {
				if (m.second > maxCount) {
					maxCount = m.second;
					candidates.clear();
					candidates.push_back(m.first);
				}
				else if (m.second == maxCount) {
					candidates.push_back(m.first);
				}
			}
		}

		answer.insert(answer.end(), candidates.begin(), candidates.end());
	}

	sort(answer.begin(), answer.end());


	for (auto a : answer)
		cout << a << " ";


	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
	vector<int> course = { 2,3,4 };

	solution(orders, course);

}
