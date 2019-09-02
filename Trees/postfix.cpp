#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool check(char c1)
{
  if(c1 == '/' || c1 == '*')
    return 1;
  else
    return 0;
}
int main()
{
  string s;
  cin >> s;
  stack <char> st;
  
  string postfix = "";
  
  for(int i = 0; i < s.length(); i++)
  {
    if(s.at(i) == '+' || s.at(i) == '-' || s.at(i) == '*' || s.at(i) == '/')
    {
      if(st.empty())
        st.push(s.at(i));
      else
      {
        if(check(st.top()) >= check(s.at(i)))
        {
          while(!st.empty())
            {
              //cout << postfix << i << endl;
              postfix += (st.top());
              st.pop();
            }
        }
          st.push(s.at(i));
      }
    } 
    else
      postfix += s.at(i);
      //cout <<"\n" << postfix << endl;
  }
  while(!st.empty())
  {
    postfix += st.top();
    st.pop();
    //cout << "HI" << "\n";
  }
  //cout << "\n\n" << st.top() << endl;
  cout << postfix;
  
  return 0;
  
    
}
