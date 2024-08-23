#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <limits.h>

using namespace std;

bool isNumber(string str)
{
	try {
		stol(str);
	}
	catch(exception& e){
		return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> str(3, "");
	vector<bool> isNum(3, false);

	long long num = 0;
	int index = 0;

	for (int i = 0; i < 3; i++)
	{
		cin >> str[i];
		if (isNumber(str[i]))
		{
			num = stol(str[i]);
			index = i;
		}
	}

	num += (long long)(3 - index);

	if (num % 3 == 0 && num % 5 == 0) {
		cout << "FizzBuzz";
	}
	else if (num % 3 == 0)	{
		cout << "Fizz";
	}
	else if (num % 5 == 0) {
		cout << "Buzz";
	}
	else {
		cout << num;
	}




}