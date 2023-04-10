#include <iostream>
#include <stack>
#include <string>
using namespace std;

class CheckBorders
{
private:

    stack<char> _stack;
    string _str1;


public:

    CheckBorders(string str)
    {
        this->_str1 = str;
    }

    bool Check() 
    {
        for (char ch : _str1) 
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                _stack.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']')
            {
                if (_stack.empty()) 
                {
                    return false;
                }

                char top = _stack.top();
                _stack.pop();

                if (ch == ')' && top != '(' || 
                    ch == '}' && top != '{' || 
                    ch == ']' && top != '[')
                {
                    return false; 
                }
            }
        }
        return _stack.empty(); 
    }

};

int main()
{
    CheckBorders obj("{x + y - z} * [x + y - z}");

    if (obj.Check())
    {
        cout << "String is correct\n";
    }
    else
    {
        cout << "String is incorrect\n";
    }
}
