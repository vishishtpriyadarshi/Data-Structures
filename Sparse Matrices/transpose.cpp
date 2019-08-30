//
// Created by Vishisht Priyadarshi on 30-08-2019
//

#include <iostream>
#include <string.h>

using namespace std;

struct Node
{
  int r;
  int c;
  int v;
};

class Sparse
{
public:
  void createMatrix(Node *mat, int size);
  
  Node* transpose(Node *mat, int size);
  
  void print(Node *mat, int size);
  
};

// ***********************************
//       Helper function
// ***********************************

void Sparse::createMatrix(Node *mat, int size)
{
  
  
  for(int i = 0;i < size; i++)
  {
    cin >> mat[i].r >> mat[i].c >> mat[i].v;
  }
  
  cout << "Sparse Matrix Created\n\n";
  
}

Node* Sparse::transpose(Node *mat, int size)
{
  Node *transpose = new Node[mat[0].v];
  /*int totr = mat[0].r;
  int totc = mat[0].c;
  
  int terms = mat[0].v;
  */
  
  int currIndex = 0;
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      if(mat[j].c == i)
      {
        transpose[currIndex].r = i;
        transpose[currIndex].c = mat[j].r;
        transpose[currIndex++].v = mat[j].v;
      }
    }
  }
  
  return transpose;
}

void Sparse::print(Node* mat, int size)
{
  cout << "ROW    COLUMN    VALUE\n";
  for(int i = 0;i < size; i++)
  {
    
    cout << mat[i].r << "   " << mat[i].c << "    " << mat[i].v;
    cout << "\n";
  }
}
// *************************************
//            Main Function
// *************************************

int main()
{
  int size = 0;
  cout << "Enter total no of non-zero values";
  cin >> size;
  Sparse obj;
  Node *mat = new Node[size];
  obj.createMatrix(mat, size);
  
  Node *transpose = obj.transpose(mat,size);
  
  obj.print(mat,size);
  cout << "\n\n";
  obj.print(transpose,size);
  
  return 0;
  
}







