#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}

	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> st(n, make_pair(0, 0));

	for (int i = 0; i < n; i++) {
		cin >> st[i].first >> st[i].second;
	}

	sort(st.begin(), st.end(), compare);   // ���� �ð��� �켱���� ����
	priority_queue<int, vector<int>, greater<int>> pq;	// �������� pq

	for (auto s : st) {
		pq.push(s.second);
		if (pq.top() <= s.first) {		// ���� ����ð��� ���۽ð����� �۰ų� ���ٸ�
			pq.pop();
		}
	}

	cout << pq.size();

}
// https://www.acmicpc.net/problem/11000

/*
������û�� ������ ������ �����Կ��� ���ο� ������ �־�����.
������ ���������״� Si�� �����ؼ� Ti�� ������ N���� ������ �־����µ�, �ּ��� ���ǽ��� ����ؼ� ��� ������ �����ϰ� �ؾ� �Ѵ�.
�����, ������ ���� ���Ŀ� ���� ������ ������ �� �ִ�. (��, Ti �� Sj �� ��� i ������ j ������ ���� ���� �� �ִ�.)
������û ������ �� �񸮸�, �������� ���͵帮��!

�ߺ��Ǵ� ���ǽ� �ִ� ����

*/