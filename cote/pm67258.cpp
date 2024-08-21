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

int solution(string s) {
    int answer = INT_MAX;
    int len = s.length();
    if (len == 1) return 1;         // ���ڿ� ���̰� 1�� ��� for���� ������� ������ ����ó��
    for (int i = 1; i <= len / 2; i++)
    {
        string temp = "";
        string comp = s.substr(0, i);
        int cnt = 1;
        for (int j = i; j < len; j = j+i)
        {
            string tempStr = s.substr(j, i);
            if (tempStr == comp) cnt++;
            else {
                if (cnt != 1)
                {
                    temp += to_string(cnt) + comp;
                }
                else
                {
                    temp += comp;
                }
                comp = tempStr;
                cnt = 1;
            }
            if (j + i >= len)   // ������ �� �̻� ������� ���� �ÿ� ���� ���ڿ� �߰�
            {
                if (cnt != 1)       
                {
                    temp += to_string(cnt) + comp;
                }
                else
                {
                    temp += comp;
                }
            }
        }

        int strSize = temp.size();
        answer = min(answer, strSize);
    }

    return answer;
}

int main()
{
    string s = "abcabcabcabcdededededede";
    
    cout << solution(s);
}

// https://school.programmers.co.kr/learn/courses/30/lessons/67258