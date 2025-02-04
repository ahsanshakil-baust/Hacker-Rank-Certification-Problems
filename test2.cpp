#include <iostream>
#include <string>
#include <vector>

using namespace std;

string decryptPassword(string s)
{
    vector<char> digits;
    int i = 0;

    while (i < s.size() && isdigit(s[i]) && s[i] != '0')
    {
        digits.push_back(s[i]);
        i++;
    }

    int digit_index = digits.size() - 1;
    for (int j = i; j < s.size(); ++j)
    {
        if (s[j] == '0' && digit_index >= 0)
        {
            s[j] = digits[digit_index--];
        }
    }

    string result;
    for (int j = i; j < s.size(); ++j)
    {
        if (s[j] == '*')
        {
            swap(result[result.size() - 1], result[result.size() - 2]);
        }
        else
        {
            result.push_back(s[j]);
        }
    }

    return result;
}

int main()
{
    string s;
    getline(cin, s);

    string result = decryptPassword(s);
    cout << result << endl;

    return 0;
}
