#include <iostream>
#include <string>
#include <queue>

/*
    All operations on queues are of complexity O(1).
    Operations:
                - queue.push()
                - queue.pop()
                - queue.front()
                - queue.front()
                - queue.empty()
                - queue.size()
*/

using namespace std;

void manageQueue()
{
    queue<string> inquiryQueue ;

    while (true)
    {
        cout << "Press enter to exit, 'next' to see next inquiry or enter a new inquiry." << endl ;
        string inquiry ;
        getline(cin,inquiry) ;

        if (inquiry == "") break ;
        else if (inquiry == "next")
        {
            if (inquiryQueue.empty()) cout << "No wait!" << endl ;
            else
            {
                cout << "Handle: " << inquiryQueue.front() << endl ;
                inquiryQueue.pop() ;
            }
        }
        else
        {
            inquiryQueue.push(inquiry) ;
            cout << "Add " << inquiry << " ." << endl ;
        }
    }
}

int main()
{
    manageQueue() ;
    return 0;
}
