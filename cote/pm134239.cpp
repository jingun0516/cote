#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <set>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;

    vector<int> vec;

    vec.push_back(k);

    while (k > 1) {
        if (k % 2 == 0) {
            k /= 2;
        }
        else {
            k = k * 3 + 1;
        }
        vec.push_back(k);
    }

    vector<double> area;
    area.push_back(0.0);

    for (int i = 0; i < vec.size() - 1; i++) {
        area.push_back((vec[i] + vec[i + 1]) / 2.0);
    }
    for (int i = 1; i < area.size(); i++) {
        area[i] += area[i - 1];
    }

    int n = vec.size() - 1;

    for (int i = 0; i < ranges.size(); i++) {
        int start = ranges[i][0];
        int end = ranges[i][1];

        if (start == 0 && end == 0) {
            end = n;
        }
        else {
            end = n + end;
        }

        if (start == end) {
            answer.push_back(0.0);
            continue;
        }

        if (start > end) {
            answer.push_back(-1.0);
            continue;
        }

        double temp_area = area[end] - area[start];

        answer.push_back(temp_area);
    }

    for (auto k : answer) {
        cout << k << "\n";
    }

    return answer;
}

int main()
{
    int k = 5;
    vector<vector<int>> ranges =
    { {0, 0}, {0, -1}, {2, -3}, {3, -3} };

    solution(k, ranges);
}
