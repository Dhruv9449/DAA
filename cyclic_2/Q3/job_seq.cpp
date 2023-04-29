// Dhruv Rajeshkumar Shah
// 21BCE0611

// Job Sequencing Problem

// Import
#include <bits/stdc++.h>
using namespace std;

// Structure to store the job details
struct job
{
    int id;
    int deadline;
    int profit;
};

// Function to find the maximum profit
bool compare(job a, job b)
{
    return a.profit > b.profit;
}

// Main function
int main()
{
    // Taking input from user
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    struct job arr[n];
    cout << "Enter the job details: ";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the job id: ";
        cin >> arr[i].id;
        cout << "Enter the deadline: ";
        cin >> arr[i].deadline;
        cout << "Enter the profit: ";
        cin >> arr[i].profit;
    }

    // Sorting the jobs according to the profit
    sort(arr, arr + n, compare);

    // Finding the maximum deadline
    int max_deadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].deadline > max_deadline)
            max_deadline = arr[i].deadline;
    }

    // Creating a boolean array to check if the slot is empty or not
    bool slot[max_deadline + 1];
    for (int i = 0; i <= max_deadline; i++)
        slot[i] = false;

    // Creating an array to store the job sequence
    int job_sequence[max_deadline + 1];
    for (int i = 0; i <= max_deadline; i++)
        job_sequence[i] = -1;

    // Finding the job sequence
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline; j > 0; j--)
        {
            if (slot[j] == false)
            {
                slot[j] = true;
                job_sequence[j] = arr[i].id;
                profit += arr[i].profit;
                break;
            }
        }
    }

    // Printing the job sequence
    cout << "The job sequence is: ";
    for (int i = 1; i <= max_deadline; i++)
    {
        if (job_sequence[i] != -1)
            cout << job_sequence[i] << " ";
    }
    cout << endl;

    // Printing the profit
    cout << "The maximum profit is: " << profit << endl;
    return 0;
}