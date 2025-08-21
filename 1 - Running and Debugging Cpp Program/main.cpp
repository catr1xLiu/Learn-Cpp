#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() 
{
    vector<string> msg{"Hello", "World"};

    for (string &word : msg) 
    {
        cout << word << " "; // The red dot shows a breaking point
    }

    cout<<endl;

    return 0;
}
