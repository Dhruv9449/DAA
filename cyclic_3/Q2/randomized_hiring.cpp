// Dhruv Rajeshkumar Shah
// 21BCE0611

// Randomized Hiring Algorithm

// Import
#include <bits/stdc++.h>
using namespace std;

// Structure to store the rank and interview status of a candidate
struct candidate
{
    int rank, interview_status;
};

// Main function
int main()
{
    // Taking input from user
    int n, no_hired = 0;
    cout << "Enter the number of candidates: ";
    cin >> n;
    struct candidate cand[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the rank of candidate " << i + 1 << ": ";
        cin >> cand[i].rank;
        cand[i].interview_status = 0;
    }

    int best = -1;
    srand(time(0));
    int index;
    for (int i = 0; i < n; i++)
    {
        do
        {
            index = rand() % n; // since upper-lower=n-0=n
        } while (cand[index].interview_status == 1);
        // if the same number which was generated already is generated again, call rand() again
        cand[index].interview_status = 1;
        if (best == -1)
        {
            best = index;
            no_hired += 1;
        }
        else if (cand[index].rank > cand[best].rank)
        {
            best = index;
            no_hired += 1;
        }
    }
    cout << "Number of hired candidates is " << no_hired << endl;
    cout << "Best candidate index and rank " << best << ", " << cand[best].rank << endl;
    return 0;
}