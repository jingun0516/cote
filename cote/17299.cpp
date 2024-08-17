#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> vec(N, 0);
	vector<int> answer(N, -1);
	vector<int> maps(1000001, 0);
	//map<int, int> maps;
	stack<int> st;

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
		maps[vec[i]]++;
	}

	for (int i = 0; i < N; i++)
	{
		while (!st.empty() && maps[vec[i]] > maps[vec[st.top()]])
		{
			answer[st.top()] = vec[i];
			st.pop();
		}
		st.push(i);
	}

	for (auto ans : answer)
		cout << ans << " ";
}

/*
ũ�Ⱑ N�� ���� A = A1, A2, ..., AN�� �ִ�. 
������ �� ���� Ai�� ���ؼ� ����ū�� NGF(i)�� ���Ϸ��� �Ѵ�.

Ai�� ���� A���� ������ Ƚ���� F(Ai)��� ���� ��, 
Ai�� ����ū���� �����ʿ� �����鼭 ���� A���� ������ Ƚ���� F(Ai)���� ū �� �߿��� ���� ���ʿ� �ִ� ���� �ǹ��Ѵ�. 
�׷��� ���� ���� ��쿡 ����ū���� -1�̴�.

���� ���, A = [1, 1, 2, 3, 4, 2, 1]�� ��� 
F(1) = 3, F(2) = 2, F(3) = 1, F(4) = 1�̴�. 
A1�� �����ʿ� �����鼭 ������ Ƚ���� 3���� ū ���� ���� ������, 
NGF(1) = -1�̴�. 
A3�� ��쿡�� A7�� �����ʿ� �����鼭 F(A3=2) < F(A7=1) �̱� ������, 
NGF(3) = 1�̴�. NGF(4) = 2, NGF(5) = 2, NGF(6) = 1 �̴�.
*/