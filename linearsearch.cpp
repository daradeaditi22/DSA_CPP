#include<iostream>
using namespace std;
int linear_search(int a[], int n, int x)
{
    for(int i=0; i<n; i++){
        if(a[i] == x)
            return(i);
        
    }return(-1);
}


int main()
{
    int a[20];
    int n;
    cout << "how many elements: ";
    cin >> n;
    cout << "Enter "<< n  << " elements: ";
    
    for (int i=0; i<n; i++){
        cin >> a[i];

    }

    int x;
    cout << "Enter Element to search: ";
    cin >> x;

    int location = linear_search (a,n,x);
    
    if (location == -1){
        cout << " Element not found ";
    }else{
        cout << " Element found at index " << location;
    }
    return (0);
}
/*
PS D:\Darade Aditi 121> & "D:\Darade Aditi 121\linearsearch.exe"
how many elements: 5
Enter 5 elements: 10 20 30 40 50
Enter Element to search: 50  
 Element found at index 4
PS D:\Darade Aditi 121> 
*/