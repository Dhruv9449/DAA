// Dhruv Rajeshkumar Shah
// 21BCE0611

// Matrix Multiplication

// Import
#include <bits/stdc++.h>
using namespace std;

struct order
{
    int r1, c1, r2, c2;
};


int main()
{
    // taking input from user
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    int rank[n + 1];
    cout << "Enter the rank of the matrices: ";
    for (int i = 0; i <= n; i++)
        cin >> rank[i];
    order o[n][n];

    // Dynamic programming
    int c[n][n] = {0};
    int i, j, k, diff, q;
    for (i = 0; i < n; i++)
    {
        c[i][i] = 0;
        o[i][i].r1 = i;
        o[i][i].c1 = i;
        o[i][i].r2 = i;
        o[i][i].c2 = i;
    }
    for (diff = 2; diff <= n; diff++)
    {
        for (i = 0; i < n - diff + 1; i++)
        {
            j = i + diff - 1;
            int min = 999999;
            for (k = i; k <= j - 1; k++)
            {
                q = c[i][k] + c[k + 1][j] + rank[i] * rank[k + 1] * rank[j + 1];
                if (q < min)
                {
                    min = q;
                    o[i][j].r1 = i;
                    o[i][j].c1 = k;
                    o[i][j].r2 = k + 1;
                    o[i][j].c2 = j;
                }
            }
            c[i][j] = min;
        }
    }
    
    // Printing the dp table
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Printing the cost (number of multiplications)
    printf("The total cost is %d \n", c[0][n - 1]);

    // Printing the order
    printf("The order is \n");
    i = 0;
    j = n - 1;
    if (fabs(o[i][j].r1 - o[i][j].c1) <= 1)
        printf("(%d,%d)", o[i][j].r1, o[i][j].c1);
    while (fabs(o[i][j].r1 - o[i][j].c1) > 1)
    {
        printf("(");
        i = o[i][j].r1;
        j = o[i][j].c1;
        printf("(%d,%d),(%d,%d)", o[i][j].r1, o[i][j].c1, o[i][j].r2, o[i][j].c2);
    }
    printf(")");
    i = 0;
    j = n - 1;
    if (fabs(o[i][j].r2 - o[i][j].c2) <= 1)
        printf("(%d,%d)", o[i][j].r2, o[i][j].c2);
    while (fabs(o[i][j].r2 - o[i][j].c2) > 1)
    {
        printf("(");
        i = o[i][j].r2;
        j = o[i][j].c2;
        printf("(%d,%d),(%d,%d)", o[i][j].r1, o[i][j].c1, o[i][j].r2, o[i][j].c2);
    }
    printf(")\n");
}


