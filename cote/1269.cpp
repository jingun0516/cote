#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	vector<int> A(a, 0);
	vector<int> B(b, 0);

	for (int i = 0; i < a; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < b; i++) {
		cin >> B[i];
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	vector<int> result1;
	vector<int> result2;
	set_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(result1));
	set_difference(B.begin(), B.end(), A.begin(), A.end(), back_inserter(result2));

	cout << result1.size() + result2.size();
}

/*
자연수를 원소로 갖는 공집합이 아닌 두 집합 A와 B가 있다. 
이때, 두 집합의 대칭 차집합의 원소의 개수를 출력하는 프로그램을 작성하시오. 
두 집합 A와 B가 있을 때, (A-B)와 (B-A)의 합집합을 A와 B의 대칭 차집합이라고 한다.

예를 들어, A = { 1, 2, 4 } 이고, B = { 2, 3, 4, 5, 6 } 라고 할 때,  
A-B = { 1 } 이고, B-A = { 3, 5, 6 } 이므로, 대칭 차집합의 원소의 개수는 1 + 3 = 4개이다.

*/
