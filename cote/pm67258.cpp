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

vector<int> solution(vector<string> gems) {
    vector<int> answer;


    set<string> gemsSet(gems.begin(), gems.end());
    int gemsSize = gemsSet.size();
    int left = 0, right = 0;
    map<string, int> gemCount;

    // [left, right] �� �� ��������� left�� �ٿ��� �ּ� ���� �����
    // �ƴϸ� right�� �÷��� ���Խ�Ű��
    gemCount[gems[0]] = 1;

    set<string> tempSet;
    while (right < gems.size()) {
        if (gemCount.size() == gemsSize) {
            if (answer.empty() || (right - left < answer[1] - answer[0])) {
                answer = { left + 1, right + 1 };
            }
            if (gemCount[gems[left]] == 1) {
                gemCount.erase(gems[left]);
            }
            else {
                gemCount[gems[left]]--;
            }

            left++;
        }
        else {
            right++;
            if (right < gems.size()) {
                gemCount[gems[right]]++;
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
    
    solution(gems);
}

// https://school.programmers.co.kr/learn/courses/30/lessons/67258