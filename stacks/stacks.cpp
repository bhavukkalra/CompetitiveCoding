#include <iostream>
#include <stack>
using namespace std;

// no method in stack to iterate through it

void printstack(stack<int> s)
{
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    s.push(13);
    s.push(40);
    s.push(56);
    printstack(s);
    s.pop();
    printstack(s);
    cout << "size is: " << s.size();





}