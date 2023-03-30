// Dhruv Rajeshkumar Shah
// 21BCE0611

// Karatsuba algorithm

// Import
#include <bits/stdc++.h>
using namespace std;

// Main karatsuba function
int karat(int a,int b)
{
    // Converting the numbers to string
	string as=to_string(a);
	string bs=to_string(b);

    // Finding the length of the numbers
	int alen=as.length();
	int blen=bs.length();

    // Base case
	if (alen==1 && blen==1)
	  return a*b;
	else
	{   
        // Padding the smaller number with 0s
		int n=alen>blen?alen:blen;
		while(alen!=n)
		{
			as="0"+as;
			alen=as.length();
		}
		while(blen!=n)
		{
			bs="0"+bs;
			blen=bs.length();
		}

        // Dividing the numbers into two halves
		int aL=stoi(as.substr(0,n/2));
		int aR=stoi(as.substr(n/2,n-(n/2)));
		int bL=stoi(bs.substr(0,n/2));
		int bR=stoi(bs.substr(n/2,n-(n/2)));

        // Recursively calling the function
		int x1=karat(aL,bL);
		int x2=karat(aL+aR,bL+bR);
		int x3=karat(aR,bR);

		int m=ceil(n/2.0);

        // Calculating and returning the final answer
		return(x1*pow(10,m*2)+(x2-x1-x3)*pow(10,m)+x3);
	} 
}
int main()
{   
    // Taking input from the user
    int a,b;
    cout<<"Enter the first number: ";
    cin>>a;
    cout<<"Enter the second number: ";
    cin>>b;

    // Printing the answer
    cout<<"The product of the two numbers is: ";
    cout<<karat(a,b)<<endl;
}

