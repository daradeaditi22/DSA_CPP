#include <iostream>
using namespace std;

const int MAX = 5;

class stack
{
private:
    int a[MAX];
    int top;

public:
    stack()
    {
        top = -1;
    }

    int empty(void)
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int full(void)
    {
        if (top == MAX - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void push(int x)
    {
        if (full())
        {
            cout << "\nStack is full";
            return;
        }

        top++;
        a[top] = x;
    }

    int pop(void)
    {
        if (empty())
        {
            cout << "\nStack is empty";
            return -1;
        }

        int x = a[top];
        top--;

        return x;
    }

    int peek(void)
    {
        if (empty())
        {
            cout << "\nStack is empty";
            return -1;
        }

        return a[top];
    }

    void display(void)
    {
        if (empty())
        {
            cout << "\nStack is empty";
            return;
        }

        cout << "\nStack elements:";

        for (int i = top; i >= 0; i--)
        {
            cout << "\t" << a[i];
        }
    }
};

int main()
{
    int x;
    stack s;

    s.push(54);
    s.push(67);
    s.push(35);
    s.push(82);
    s.push(93);

    s.display();

    if (!s.empty())
    {
        x = s.pop();
        cout << "\nRemoved: " << x;
    }

    s.display();

    x = s.peek();
    cout << "\nTop element is: " << x;

    return 0;
}
/*
PS D:\Darade Aditi 121> & "D:\Darade Aditi 121\stackusingarray.exe"

Stack elements: 93      82      35      67      54
Removed: 93
Stack elements: 82      35      67      54
Top element is: 82
PS D:\Darade Aditi 121> 
*/