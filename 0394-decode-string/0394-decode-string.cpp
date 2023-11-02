#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> letStack;
        stack<int> numStack;
        
        string curnum = "";
        string curlets = "";
            

        for (auto& let : s)
        {
            if (isdigit(let))
            {
                curnum += let;
            }
            else if (let == '[')
            {
                numStack.push(stoi(curnum));
                curnum = "";
                letStack.push(curlets);
                curlets = "";
            }
            else if (let == ']')
            {
                int repeat = numStack.top();
                numStack.pop();
                string temp = curlets;
                curlets = letStack.top();
                letStack.pop();
                for (int i = 0; i < repeat; i++)
                {
                    curlets += temp;
                }
            }
            else
            {
                curlets += let;
            }
        }
        return curlets;
    }
};