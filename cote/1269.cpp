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
�ڿ����� ���ҷ� ���� �������� �ƴ� �� ���� A�� B�� �ִ�. 
�̶�, �� ������ ��Ī �������� ������ ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
�� ���� A�� B�� ���� ��, (A-B)�� (B-A)�� �������� A�� B�� ��Ī �������̶�� �Ѵ�.

���� ���, A = { 1, 2, 4 } �̰�, B = { 2, 3, 4, 5, 6 } ��� �� ��,  
A-B = { 1 } �̰�, B-A = { 3, 5, 6 } �̹Ƿ�, ��Ī �������� ������ ������ 1 + 3 = 4���̴�.

*/
