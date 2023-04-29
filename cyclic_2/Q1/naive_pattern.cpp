// Dhruv Rajeshkumar Shah
// 21BCE0611

// Naive pattern matching

// Import
#include <bits/stdc++.h>
using namespace std;

// Function to find the pattern
void findPattern(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (text[i + j] != pattern[j])
                break;
        if (j == m)
            cout << "Pattern found at index " << i << ".\n";
    }
}

// Main function
int main()
{
    // Taking input from user
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;

    findPattern(text, pattern);
    return 0;
}

