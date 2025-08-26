#include<iostream>

void myFunction() 
{
    // static keyword means that this variable is intialized before the program starts
    // But unlike global variables, this variable is only accessible in myFunction()
    static int counter = 0;

   std::cout << "This is the " << ++counter << " time myFunction() is executed" << std::endl;
}
int main()
{
    myFunction();
    myFunction();
    myFunction();
}