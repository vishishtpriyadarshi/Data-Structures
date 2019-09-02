#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node
{
  Node* left;
  Node* right;
  
  char data;
};

Node* newNode(char data)                                     // Creates a new Node
{ 
  Node* node = new Node; 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  return node; 
} 

bool check(char c1)
{
  if(c1 == '/' || c1 == '*')
    return 1;
  else
    return 0;
}


string convertToPostfix(string s)
{
  // ===================================================================
  // Finding PostFix Expression
  // ===================================================================
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
  return postfix;
  
}



Node* createExp(string s)
{
  int n = s.length();
  
  // ======================================================================
  // Building Expression Tree
  // ======================================================================
  
  string post = convertToPostfix(s);
  
  stack <Node*> st;
  
  Node *n1 = newNode(post.at(0));
  Node *n2 = newNode(post.at(1));
  
  st.push(n1);
  st.push(n2);
  
  for(int i = 2; i < n; i++)
  {
    if(post.at(i) == '+' || post.at(i) == '-' || post.at(i) == '/' || post.at(i) == '*')
    {
        Node *parent = newNode(post.at(i));
        parent->right = st.top();
        st.pop();
        parent->left = st.top();
        st.pop();
        
        st.push(parent);
    }
    else
    {
      Node *n = newNode(post.at(i));
      st.push(n);
    }
  }
  return st.top();
  
}



void inorder(Node* root)                                  //Inorder Traversal
{ 
  if (root != NULL) 
  { 
    inorder(root->left); 
    cout << root->data << " "; 
    inorder(root->right); 
  } 
} 

void preorder(Node* root)                                 // Preorder Traversal
{ 
  if (root != NULL) 
  { 
    
    cout << root->data << " "; 
    preorder(root->left);
    preorder(root->right); 
  } 
} 

void postorder(Node* root)                                // Postorder Traversal
{ 
  if (root != NULL) 
  { 
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
  } 
} 



int main()
{
  string s;
  cin >> s;
  Node *root = createExp(s);
  
  cout << "\n\nINORDER :\n";
  inorder(root);
  
  cout << "\n\nPREORDER :\n";
  preorder(root);
  
  cout << "\n\nPOSTORDER :\n";
  postorder(root);
  
  cout <<"\n\n";
  
  return 0;
}
