#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	int A;
	cin >> A;

	vector<int> vec(A, 0);
	vector<int> answer(A, -1);
	stack<int> st;			// 오큰수를 찾지 못한 인덱스를 저장

	for (int i = 0; i < A; i++)
	{
		cin >> vec[i];

		while (!st.empty() && vec[st.top()] < vec[i])
		{
			answer[st.top()] = vec[i];
			st.pop();
		}
		st.push(i);		// 무조건 일단 오른쪽으로 가야하니까 push
	}
	
	for (auto ans : answer)
		cout << ans << " ";


}


/*
크기가 N인 수열 A = A1, A2, ..., AN이 있다. 
수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다. 
Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 
그러한 수가 없는 경우에 오큰수는 -1이다.

예를 들어, A = [3, 5, 2, 7]인 경우 
NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. 
A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

A의 최대가 1,000,000 이므로 한번만 순회해서 찾을 수 있는 방법 생각할 것!
*/