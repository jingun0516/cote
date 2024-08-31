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

	sort(st.begin(), st.end(), compare);   // 시작 시간을 우선으로 정렬
	priority_queue<int, vector<int>, greater<int>> pq;	// 내림차순 pq

	for (auto s : st) {
		pq.push(s.second);
		if (pq.top() <= s.first) {		// 전의 종료시간이 시작시간보다 작거나 같다면
			pq.pop();
		}
	}

	cout << pq.size();

}
// https://www.acmicpc.net/problem/11000

/*
수강신청의 마스터 김종혜 선생님에게 새로운 과제가 주어졌다.
김종혜 선생님한테는 Si에 시작해서 Ti에 끝나는 N개의 수업이 주어지는데, 최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다.
참고로, 수업이 끝난 직후에 다음 수업을 시작할 수 있다. (즉, Ti ≤ Sj 일 경우 i 수업과 j 수업은 같이 들을 수 있다.)
수강신청 대충한 게 찔리면, 선생님을 도와드리자!

중복되는 강의실 최대 개수

*/