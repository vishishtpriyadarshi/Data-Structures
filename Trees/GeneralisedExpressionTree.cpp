//
// Created by Vishisht Priyadarshi on 07-09-2019.
//

//
// Created by Vishisht Priyadarshi on 07-09-2019.
//

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

int comp(char c1)                              // Finds Precedence of the operators
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
            if( f == 1 || c == '(')             // if ( is stored in stack OR ( is encountered first time
            {
                if(c == '(')
                {
                    f = 1;
                    a.push(c);
                }

                else if(c != ')')                // Orders the operands inside parantheses
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
                else                             // encountered )
                {
                    while(a.top() != '(')
                    {
                        ans+=a.top();
                        a.pop();
                    }
                    a.pop();
                    f = 0;                       // Resest to 0 as no parantheses left
                }


            }
            else                                 // Orders the elements which are not inside parantheses
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
            ans+=c;                               // Adding Operands
    }
    while(!a.empty())
    {
        ans+=a.top();                             // Emptying stack of left operations
        a.pop();
    }

    return ans;
}




Node* createExp(string s)
{
    int n = s.length();

    // ======================================================================
    // Building Expression Tree
    // ======================================================================

    string post = toPostfix(s);

    stack <Node*> st;

    Node *n1 = newNode(post.at(0));
    Node *n2 = newNode(post.at(1));

    st.push(n1);
    st.push(n2);

    for(int i = 2; i < n; i++)
    {
        if(post.at(i) == '+' || post.at(i) == '-' || post.at(i) == '/' || post.at(i) == '*' || post.at(i) == '^')
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
            Node *no = newNode(post.at(i));
            st.push(no);
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
    cout << "Enter Infix Expression:\n";
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
