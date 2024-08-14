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
	stack<int> st;			// ��ū���� ã�� ���� �ε����� ����

	for (int i = 0; i < A; i++)
	{
		cin >> vec[i];

		while (!st.empty() && vec[st.top()] < vec[i])
		{
			answer[st.top()] = vec[i];
			st.pop();
		}
		st.push(i);		// ������ �ϴ� ���������� �����ϴϱ� push
	}
	
	for (auto ans : answer)
		cout << ans << " ";


}


/*
ũ�Ⱑ N�� ���� A = A1, A2, ..., AN�� �ִ�. 
������ �� ���� Ai�� ���ؼ� ��ū�� NGE(i)�� ���Ϸ��� �Ѵ�. 
Ai�� ��ū���� �����ʿ� �����鼭 Ai���� ū �� �߿��� ���� ���ʿ� �ִ� ���� �ǹ��Ѵ�. 
�׷��� ���� ���� ��쿡 ��ū���� -1�̴�.

���� ���, A = [3, 5, 2, 7]�� ��� 
NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1�̴�. 
A = [9, 5, 4, 8]�� ��쿡�� NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1�̴�.

A�� �ִ밡 1,000,000 �̹Ƿ� �ѹ��� ��ȸ�ؼ� ã�� �� �ִ� ��� ������ ��!
*/