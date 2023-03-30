// Dhruv Rajeshkumar Shah
// 21BCE0611

// A dynamic programming based

// Import
#include <bits/stdc++.h>
using namespace std;


// Main function
int main()
{
    // Taking input from user
    string s1, s2;

    cout << "Enter the first string: ";
    cin >> s1;

    cout << "Enter the second string: ";
    cin >> s2;

    // Getting the length of the strings
    int m = s1.size();
    int n = s2.size();

    int dp[m + 1][n + 1];
    int seq[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
        for (int j = 0; j < n + 1; j++)
        {
            dp[i][j] = 0;
            seq[i][j] = 0;
        }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1.at(i - 1) == s2.at(j - 1))
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                // To denote diagonal
                seq[i][j] = 3;
            }
            else
            {
                int first = dp[i][j - 1];
                int second = dp[i - 1][j];
                // To denote left and top
                dp[i][j] = first > second ? first : second;
                seq[i][j] = first > second ? 1 : 2; 
            }                                      
        }
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "seq\n";
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << seq[i][j] << " ";
        }
        cout << "\n";
    }
    int last = seq[m][n];
    string substring = "";
    int i = m, j = n;
    while (i != 0 && j != 0)
    {
        if (last == 3)
        {
            substring.append(s1.substr(i - 1, 1)); 
            i--;
            j--; 
        }
        else if (last == 1) 
            j--;            
        else if (last == 2) 
            i--;            
        last = seq[i][j];   
    }
    cout << "The common subsequence before reversing is    " << substring << endl;
    reverse(substring.begin(), substring.end());
    cout << "The common subsequence after reversing is    " << substring << endl;
}
