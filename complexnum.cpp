#include<iostream>
using namespace std;
class complex {
    private:
    float real;
    float imag;

    public:
    complex()
    {
        real = 0;
        imag = 0;
    }
    complex( float r,float i)
    {
        real = r;
        imag = i;

    }
    
    ~complex() {}

    void  display(void){
     cout << real << "+" << imag << "i" <<endl; 
}

complex operator+(complex c){
    return complex(real + c.real, imag + c.imag);
}

complex operator-(complex c){
    return complex (real - c.real, imag - c.imag);
}

complex operator*(complex c){
    float r = real*c.real - imag*c.imag;
    float i = real*c.imag + imag*c.real;
    return complex (r,i);
}

};



int main()
{
    complex c1(4,5), c2(2,3);
    cout << "First complex number : ";
    c1.display();
    cout <<"Second complex number:" ;
    c2.display();

    complex sum = c1+c2;
    cout << "\nsum :";
    sum.display();

    complex diff = c1-c2;
    cout << "difference:";
    diff.display();

    complex prod = c1*c2;
    cout << "product:";
    prod.display();
    

    

    return(0);

    

}
/*
PS D:\Darade Aditi 121> & "D:\Darade Aditi 121\complexnum.exe"
First complex number : 4+5i
Second complex number:2+3i

sum :6+8i
difference:2+2i
product:-7+22i
PS D:\Darade Aditi 121> 
*/