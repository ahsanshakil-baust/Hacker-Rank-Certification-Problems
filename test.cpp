#include <bits/stdc++.h>

using namespace std;

vector<string> possibleChanges(vector<string> usernames)
{
    vector<string> results;

    for (const string &username : usernames)
    {
        bool canChange = false;

        for (int i = 0; i < username.size(); i++)
        {
            for (int j = i + 1; j < username.size(); j++)
            {
                if (username[i] > username[j])
                {
                    canChange = true;
                    break;
                }
            }
            if (canChange)
                break;
        }

        results.push_back(canChange ? "YES" : "NO");
    }

    return results;
}

int main()
{
    int usernames_count;
    cin >> usernames_count;
    cin.ignore();

    vector<string> usernames(usernames_count);
    for (int i = 0; i < usernames_count; i++)
    {
        getline(cin, usernames[i]);
    }

    vector<string> result = possibleChanges(usernames);

    for (const string &res : result)
    {
        cout << res << endl;
    }

    return 0;
}
