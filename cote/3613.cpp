#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "";
    cin >> str;

    string language = "None";

    if ((str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_' || str[str.length()-1] == '_')
    {
        cout << "Error!";
        return 0;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (!(str[i] == '_' || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
        {
            cout << "Error!";
            return 0;
        }
        if (str[i] == '_')
        {
            if (str[i + 1] == '_')
            {
                cout << "Error!";
                return 0;
            }
            if (language == "JAVA")
            {
                cout << "Error!";
                return 0;
            }
            language = "C++";
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            if (language == "C++")
            {
                cout << "Error!";
                return 0;
            }
            language = "JAVA";
        }
    }
    if (language == "None")
    {
        cout << str;
        return 0;
    }
    string answer = "";
    if (language == "JAVA")
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                answer += "_";
                answer += str[i] + 32;
            }
            else {
                answer += str[i];
            }
        }
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '_')
            {
                if (i + 1 < str.length() && str[i + 1] >= 'a' && str[i + 1] <= 'z')
                {
                    answer += str[i + 1] - 32;
                    i++;
                }
            }
            else {
                answer += str[i];
            }
        }
    }
    cout << answer;
}