/*
    Name: Timothy Dea
    SID: 861176053
    Date: 4/24/15
*/

#include <iostream>
using namespace std;
#define nil 0

template < typename Value >
class BST{
    class Node { // binary tree node
            public:
                Value value;
                Node* left;
                Node* right;
                Node( const Value v = Value() )
                : value(v), left(nil), right(nil)
                {}
    };
    int count;
    Node * root;
    
    BST() : count(0), root(nil) {}
    
    void insert( Value X ) { root = insert( X, root ); }
        Node* insert( Value X, Node* T ) {
            // The normal binary-tree insertion procedure ...
            if ( T == nil ) {
                T = new Node( X ); // the only place that T gets updated.
            } else if ( X < T->value ) {
                T->left = insert( X, T->left );
            } else if ( X > T->value ) {
                T->right = insert( X, T->right );
            } else {
                T->value = X;
            }
            // later, rebalancing code will be installed here
            return T;
        }
};


void printNode(const int m, const int n, const int k){
    if(m+n<k){
        cout << m << ' ' << n << endl;
    }
}

void preorder(int m,int n, int k){
    printNode(m,n,k);
    preorder(2*m-n,m,k);
    preorder(2*m+n,m,k);
    preorder(m+2*n,n,k);
}

void postorder(int m,int n, int k){
    preorder(2*m-n,m,k);
    preorder(2*m+n,m,k);
    preorder(m+2*n,n,k);
    printNode(m,n,k);
}



