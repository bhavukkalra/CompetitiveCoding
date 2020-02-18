#include <iostream>
#include <queue>
using namespace std;

// no method to print the queue

void printqueue(queue<int> yq)
{
    while(!yq.empty())
    {
        cout << yq.front() << " ";
        yq.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> myq;
    myq.push(12);
    myq.push(44);
    myq.push(76);
    printqueue(myq);
    cout << "size is: " << myq.size() << endl;
    cout << "front is: " << myq.front() << endl;
    cout << "back is: " << myq.back() << endl;








}