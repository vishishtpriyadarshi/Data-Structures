//
// Created by Vishisht Priyadarshi on 07-09-2019.
//

#include <iostream>
#include <stack>

using namespace std;

int comp(char c1)                               // Finds Precedence of the operators
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
    string ans = "";                            // stores final Postfix Expression
    stack <char> a;
    int f = 0;                                  // Flag to denote presence of ( in Stack
    for(int i = 0; i < l; i++)
    {
        char c = s.at(i);
        if(c == '^' || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
        {
            if( f == 1 || c == '(')              // if ( is stored in stack OR ( is encountered first time 
            {
                if(c == '(')
                {
                    f = 1;
                    a.push(c);
                }

                else if(c != ')')                 // Orders the operands inside parantheses
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
                else                                // encountered )
                {
                    while(a.top() != '(')
                    {
                        ans+=a.top();
                        a.pop();
                    }
                    a.pop();
                    f = 0;                           // Resest to 0 as no parantheses left
                }


            }
            else                                     // Orders the elements which are not inside parantheses
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
            ans+=c;                                   // Adding Operands
    }
    while(!a.empty())
    {
        ans+=a.top();                                 // Emptying stack of left operations
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
