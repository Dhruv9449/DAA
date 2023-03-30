// Dhruv Rajeshkumar Shah
// 21BCE0611

// Maximum sum of the subarray

// Import
#include <bits/stdc++.h>
using namespace std;


// Function to find the maximum of two numbers
int max(int a,int b)
{
	return a>b?a:b;
}

// Function to find cross sum of the array
int crosssum(int a[],int l,int mid,int h)
{
	int s=0; int left=INT_MIN;
	for(int i=mid;i>=l;i--)
	{
		s+=a[i];
		if(s>left)
		  left=s;
	}
	s=0;int right=INT_MIN;
	for(int i=mid+1;i<=h;i++)
	{
		s+=a[i];
		if(s>right)
		  right=s;
	}
	return(left+right);
}

// Main function to find the maximum sum of the subarray
int maxsum(int a[], int l,int h)
{
	if(l==h)
	  return a[l];
	else
	{
		int mid=(l+h)/2;
		int temp=max(maxsum(a,l,mid),maxsum(a,mid+1,h));
		return max(temp,crosssum(a,l,mid,h));
	}
}

// Main function
int main()
{   
    // Taking input from the user
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
      cin>>arr[i];
    
    // Printing the maximum sum of the subarray
    cout<<"The maximum sum of the subarray is: ";
	cout<<maxsum(arr,0,7)<<endl;
}