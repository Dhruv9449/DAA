// Dhruv Rajeshkumar Shah
// 21BCE0611

// Randomized Quick Sort

// Import
#include <bits/stdc++.h>
using namespace std;

// Function to sort array using randomized quick sort
void quick(int a[], int left, int right)
{
    int temp;
    if (left >= right)
        return;

    // Randomizing the pivot
    srand(time(NULL));
    int pivot = (rand() % (right - left + 1)) + left;

    temp = a[left];
    a[left] = a[pivot];
    a[pivot] = temp;
    pivot = left;
    int l = left;
    int r = right;
    while (l < r)
    {
        while (a[r] > a[pivot])
            r--;
        while (a[l] <= a[pivot])
            l++;
        if (l < r)
        {
            temp = a[l];
            a[l] = a[r];
            a[r] = temp;
        }
    }
    temp = a[pivot];
    a[pivot] = a[r];
    a[r] = temp;
    quick(a, left, r - 1);
    quick(a, r + 1, right);
}

// Main function
int main()
{
    // Taking input from user
    int n, i;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
        cin >> a[i];

    // Calling quick sort function
    quick(a, 0, n - 1);

    // Printing the sorted array
    cout << "\nSorted array is \n";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout<<endl;
    return 0;
}