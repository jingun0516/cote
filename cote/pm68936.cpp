#include <string>
#include <vector>
#include <iostream>

using namespace std;

int tempAns[2] = {0, };

void dfs(vector<vector<int>>& arr, int startX, int startY, int endX, int endY) {
    int temp = arr[startY][startX];

    bool checked = false;
    for (int i = startY; i < endY; i++) {
        for (int j = startX; j < endX; j++) {
            if (temp != arr[i][j]) {
                int midX = (startX + endX) / 2;
                int midY = (startY + endY) / 2;

                dfs(arr, startX, startY, midX, midY);
                dfs(arr, startX, midY, midX, endY);
                dfs(arr, midX, startY, endX, midY);
                dfs(arr, midX, midY, endX, endY);
                checked = true;
                break;
            }
        }
        if (checked) break;
    }
    if(!checked) tempAns[temp]++;
}



vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    int n = arr.size();
    int start = 0;
    int end = n;

    dfs(arr, start, start, end, end);

    for (auto a : tempAns)
        cout << a << " ";
    cout << "\n";

    return answer;
}

int main() {
    vector<vector<int>> arr =
    {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1, 1, 1, 1},
        {0, 1, 0, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 1, 1}
    };

    solution(arr);
}