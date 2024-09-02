#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	long long S;
	cin >> N >> S;

	vector<long long> vecs(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> vecs[i];
	}

	int left = 0;
	int right = 0;

	long long sum = 0;
	int answer = 100001;
	int cnt = 0;

	while (left < N) {
		if (sum < S) {
			if (right >= N) break;

			sum += vecs[right];
			cnt++;
			right++;
		}
		else {
			answer = min(answer, cnt);
			sum -= vecs[left];
			cnt--;
			left++;
		}
	}

	if (answer == 100001) answer = 0;
	cout << answer;

}

// 10,000 ������ �ڿ����� �̷���� ���� N¥�� ������ �־�����. 
// �� �������� ���ӵ� ������ �κ��� �߿� �� ���� S �̻��� �Ǵ� �� ��, 
// ���� ª�� ���� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// https://www.acmicpc.net/problem/1806