//
// Created by Vishisht Priyadarshi on 07-09-2019.
//

#include <iostream>
#include <stack>

using namespace std;

int comp(char c1)
{
    if (c1 == '^')
        return 3;
    else if(c1 == '/' || c1 == '*')
        return 2;
    else if(c1 == '+' || c1 == '-')
        return 1;
    else
        return 0;
}
string toPostfix(string s)
{
    int l = s.length();
    string ans = "";
    stack <char> a;
    int f = 0;
    for(int i = 0; i < l; i++)
    {
        char c = s.at(i);
        if(c == '^' || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
        {
            if( f == 1 || c == '(')
            {
                if(c == '(')
                {
                    f = 1;
                    a.push(c);
                }

                else if(c != ')')
                {
                    if(a.empty())
                        a.push(c);
                    else if(comp(c) > comp(a.top()))
                        a.push(c);
                    else if(comp(c) <= comp(a.top()))
                    {
                        while(a.top() != '(' && comp(c) <= comp(a.top()))
                        {
                            ans+=a.top();
                            a.pop();
                        }
                        a.push(c);
                    }
                }
                else
                {
                    while(a.top() != '(')
                    {
                        ans+=a.top();
                        a.pop();
                    }
                    a.pop();
                    f = 0;
                }


            }
            else
            {
                if(a.empty())
                    a.push(c);
                else if(comp(c) > comp(a.top()))
                    a.push(c);
                else if(comp(c) <= comp(a.top()))
                {
                    while(!(a.empty()) && comp(c) <= comp(a.top()))
                    {
                        ans+=a.top();
                        a.pop();
                    }
                    a.push(c);
                }
            }

        }
        else
            ans+=c;
    }
    while(!a.empty())
    {
        ans+=a.top();
        a.pop();
    }
    
    return ans;
}

int main()
{
    cout << "Enter String:\n\n";
    string s;
    cin >> s;
    cout << "Final Ans:\n" << toPostfix(s);

    return 0;
}
