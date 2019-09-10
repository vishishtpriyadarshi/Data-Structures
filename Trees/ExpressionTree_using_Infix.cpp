//
// Created by Vishisht Priyadarshi on 10-09-2019.
//

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

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


int highest(string s)
{
    int no = 0;
    int ind = 0;

    for(int i = 0; i < s.length(); i++)
    {
        char c = s.at(i);
        if(c == '^' || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
            no++;
    }


    reverse(s.begin(), s.end());

    int fa = 0, fm = 0;

    for(int i = 0; i < s.length(); i++)
    {
        char c = s.at(i);
        if((c == '+' || c == '-') && (fa == 0))
        {
            ind = i;
            fa = 1;
        }
        if((c == '*' || c == '/') && (fm == 0) && (fa == 0))
        {
            ind = i;
            fm = 1;
        }
    }

    return s.length() - ind - 1;
}

Node *create(string s, Node* root)
{
    Node *temp = newNode(s.at(highest(s)));
    root = temp;

    string sub1 = s.substr(0,highest(s));
    //cout << sub1 <<endl;

    if(sub1.length() > 1)
        root->left = create(sub1,root->left);
    else
        root->left = newNode(sub1.at(0));

    string sub2 = s.substr(highest(s) + 1);
    //cout << sub2 <<endl;

    if(sub2.length() > 1)
        root->right = create(sub2,root->right);
    else
        root->right = newNode(sub2.at(0));


    return root;
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
stack <string> st;

string to_String(char x)
{
    // string class has a constructor
    // that allows us to specify size of
    // string as first parameter and character
    // to be filled in given size as second
    // parameter.
    string s(1, x);

    return s;
}

void operate(Node* root)
{

    if (root != NULL)
    {
        operate(root->left);
        operate(root->right);

        string c = to_String(root->data);
        //cout << c << " ";
        st.push(c);
        //cout << "Pushed :" << c << endl;
        if(c == "^" || c == "+" || c == "-" || c == "*" || c == "/" || c == "(" || c == ")")
        {
            st.pop();

            string c2 = st.top();
            st.pop();
            string c1 = st.top();
            st.pop();

            int n1=0,n2=0;


            n1 = stoi(c1);
            n2 = stoi(c2);



            if(c == "*")
                st.push((to_string)(n1*n2));
            if(c == "/")
                st.push((to_string)(n1/n2));
            if(c == "+")
                st.push((to_string)(n1+n2));
            if(c == "-")
                st.push((to_string)(n1-n2));
            if(c == "^")
                st.push((to_string)(n1^n2));
            //cout << " == Operated == :" << st.top() << "\n";

        }

    }

}


int main()
{
    cout << "Enter Expression:\n";
    string s;
    cin >> s;

    Node *root = new Node;
    root = create(s,root);

    cout << "\n\nINORDER :\n";
    inorder(root);

    cout << "\n\nPREORDER :\n";
    preorder(root);

    cout << "\n\nPOSTORDER :\n";
    postorder(root);

    cout <<"\n\n";

    cout << "Value:\n";
    operate(root);
    cout << st.top() << "\n";
    return 0;
}   
