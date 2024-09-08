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

long gcd(long a, long b) {
	long temp = min(a, b);

	for (long i = temp; i >= 1; i--) {
		if (a % i == 0 && b % i == 0)
			return i;
	}

}

long long solution(int w, int h) {
	long long answer = 1;

	answer = (long long)w * (long long)h - ((w + h) - gcd(w, h));

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long w = 8;
	long long h = 12;

	cout << solution(w, h);
}

// https://school.programmers.co.kr/learn/courses/30/lessons/67259
// 패턴 : x + y - 1 만큼의 못 쓰는 사각형이 최대공약수 만큼 나타남