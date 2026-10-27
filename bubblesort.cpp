#include<iostream>
using namespace std;
void bubblesort (int a[],int n)
{
    int temp;
    for (int i = 0; i<n-1; i++)
    {
        for (int j = 0 ; j<n-1; j++)
        {
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    int a[10];
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << " Enter " << n << " integers in any order: " << endl;
    for (int i = 0; i<n ; i++)
    {
        cin >> a[i];

    }
    bubblesort (a,n);
    cout << " Sorted array: ";
    for (int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    
    }
    cout << endl;

    return 0 ;

}
/*
PS D:\Darade Aditi 121> & "D:\Darade Aditi 121\bubblesort.exe"
Enter the size of the array: 10
 Enter 10 integers in any order: 
50 20 10 30 60 70 90 80 40 100
 Sorted array: 10 20 30 40 50 60 70 80 90 100 
PS D:\Darade Aditi 121> 
*/