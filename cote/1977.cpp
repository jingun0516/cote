#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <math.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M;
	cin >> N;

	int minV = N + 1;
	int sum = 0;

	for (int i = M; i <= N; i++) {
		int sqrtNum = (int)(sqrt(i));
		if (i == sqrtNum * sqrtNum) {
			sum += i;
			if (minV == N + 1) {
				minV = i;
			}
		}
	}

	if (sum == 0) {
		cout << -1;
		return 0;
	}

	cout << sum << "\n";
	cout << minV;



}

// https://www.acmicpc.net/problem/1977
/*
ȭ�鿡 A�� ����Ѵ�.
Ctrl-A: ȭ���� ��ü �����Ѵ�
Ctrl-C: ��ü ������ ������ ���ۿ� �����Ѵ�
Ctrl-V: ���۰� ������� ���� ��쿡�� ȭ�鿡 ��µ� ���ڿ��� �ٷ� �ڿ� ������ ������ �ٿ��ִ´�.
*/
