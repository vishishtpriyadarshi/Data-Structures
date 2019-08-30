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
  
  Node* fast_Transpose(Node *mat, int size);
  
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

Node* Sparse::fast_Transpose(Node *mat, int size)
{
  Node *transpose = new Node[size];
  int *rowSize = new int[size];
  int *rowStart = new int[size];
  
  for(int i =0; i < size; i++)
    rowSize[i] = 0;
  
  for(int i =0; i < size; i++)
    rowSize[mat[i].c]++;
  
  
  rowStart[0] = 0;
  for(int i =0; i < size; i++)
    rowStart[i] = rowStart[i-1] + rowSize[i - 1];
  
  for(int i =0; i < size; i++)
  {
    int j = rowStart[mat[i].c];
    transpose[j].r = mat[i].c;
    transpose[j].c = mat[i].r;
    transpose[j].v = mat[i].v;
    rowStart[mat[i].c]++;
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
  
  Node *transpose = obj.fast_Transpose(mat,size);

  obj.print(mat,size);
  cout << "\n\n";
  obj.print(transpose,size);
  
  return 0;
  
}







