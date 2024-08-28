#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long fact(long long num) {
    long long factNum = 1;

    for (int i = 1; i <= num; i++)
        factNum *= i;

    return factNum;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<bool> check(n + 1, false);

    int temp = n;
    while (answer.size() < temp) {
        long long next = fact(n - 1);

        for (int i = 1; i <= temp; i++) {
            if (check[i]) continue;

            if (k <= next) {          
                answer.push_back(i);
                check[i] = true;
                break;
            }
            else {                      // 단위보다 작을 때 까지 빼주면 k의 위치가 나옴
                k -= next;
            }
        }

        n--;
    }

    for (auto a : answer)
        cout << a << " ";

    return answer;
}


int main()
{
    int n = 3;
    long long k = 6;

    solution(n, k);
}