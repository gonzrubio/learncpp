#include <iostream>
#include <string>
#include <stack>

/*
    All operations on stacks are of complexity O(1).
    Operations:
                - stack.push()
                - stack.pop()
                - stack.top()
                - stack.empty()
                - stack.size()
*/

using namespace std;

string getResponse()
{
    cout << "What you say??" << endl;
    string response ;
    getline(cin,response) ;

    return response ;
}

stack<char> reverseResponse(string s)
{
    stack<char> myStack ;

    for (int ii = 0 ; ii < s.length() ; ii++)
    {
        myStack.push(s[ii]) ;
    }
    return myStack ;

}

void printStack(stack<char> stacc)
{
        cout << "That backwards is: " ;

        while (! stacc.empty())
    {
        cout << stacc.top() ;
        stacc.pop() ;
    }
    cout << endl ;
}

int main()
{
    string response = getResponse() ;
    printStack( reverseResponse(response) ) ;

    return 0;
}
