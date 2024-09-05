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
화면에 A를 출력한다.
Ctrl-A: 화면을 전체 선택한다
Ctrl-C: 전체 선택한 내용을 버퍼에 복사한다
Ctrl-V: 버퍼가 비어있지 않은 경우에는 화면에 출력된 문자열의 바로 뒤에 버퍼의 내용을 붙여넣는다.
*/
