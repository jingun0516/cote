#include <iostream>
#include <vector>
#include <string>

using namespace std;

void hanoi(vector<vector<int>>& answer, int n, int start, int goal, int sub) {
    if (n == 1) {
        answer.push_back({ start, goal });

        return;
    }

    hanoi(answer, n - 1, start, sub, goal);
    answer.push_back({ start, goal });
    hanoi(answer, n - 1, sub, goal, start);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;

    hanoi(answer, n, 1, 3, 2);

    return answer;
}


int main() {
    int n;
    cin >> n;

    solution(n);

    return 0;
}
