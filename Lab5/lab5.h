/*
    Name: Timothy Dea
    SID: 861176053
    Date: 5/9/15
*/

#ifndef BST_H
#define BST_H
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
using namespace std;
#define nil 0

// #define Value int // restore for testing.
template < typename Value >
class BST {
    
    class Node { // binary tree node
        public:
            bool selectedSum;
            bool selected; 
            Value value;
            Node* left;
            Node* right;
            Node( const Value v = Value() )
            : selectedSum(false), selected(false), value(v), left(nil), right(nil)
            {}
            Value& content() { return value; }
            bool isInternal() { return left != nil && right != nil; }
            bool isExternal() { return left != nil || right != nil; }
            bool isLeaf() { return left == nil && right == nil; }
            int height() {
            // returns the height of the subtree rooted at this node
                // FILL IN
                if(this==nil) return 0;
                int l=left->height() +1;
                int r=right->height() +1;
                if(l>r) return l;
                else return r;
            }   
            
            int size() {
            // returns the size of the subtree rooted at this node,
            // FILL IN
                if(this==nil) return 0;
                else{
                    int sz=1;
                    sz+=left->size();
                    sz+=right->size();
                    return sz;
                } 
            }
            
            
            
    }; // Node
    // const Node* nil; // later nil will point to a sentinel node.
    int count;
    //Node* root;
    int num=0;
    public:
        Node* root;
    
        bool search ( Value x ) { return search(x, root); }
        
        bool search(Value x, Node * T){
        // search for a Value in the BST and return true iff it was found
            if(T->value==x){
                return true;
            }
            if(T->isLeaf()) return false;
            else{
                if(x>T->value){
                    return search(x, T->right);                
                }
                else{
                    return search(x, T->left);
                }
            }
        // FILL IN
        }
        
        void minCover(){
            minCover(root->left);
            minCover(root->right);
        }
        
        void minCover(Node * T){
            
            if(T) {
                minCover(T->left);
                if((T->left && T->left->isLeaf()) || (T->right && 
                T->right->isLeaf())){
                    T->selected=true;
                }
                if(T->isInternal()){
                    if(!T->left->selected || !T->right->selected){
                        T->selected=true;
                    }
                }
                minCover(T->right);
            }
        }
        
        void displayMinCover(){
            cout << "Part 1" << endl;
            displayMinCover(root);
            cout << endl << num << endl;
        }
        
        void displayMinCover(Node * T){
            if(T){
                displayMinCover(T->left);
                if(T->selected){
                    num++;
                    cout << T->value << ' ';
                }
                displayMinCover(T->right);
            }
        }
        
        void findSumPath(Node* n, int sum, int buffer[]){
            cout << "Part 2" << endl;
            if(findSumPath(root,sum)){
                displaySumPath(root);
            }
            else{
                cout << "0";
            }
            cout << endl;
        } 
        
        bool findSumPath(Node *n, int &sum){
            if(!n){
                return (sum==0);
            }
            else if(n){
                if(n->value<=sum){
                    sum-=n->value;
                    n->selectedSum=true;
                }
                if(n->left && sum<n->right->value){
                    findSumPath(n->left, sum);
                }
                if(n->right && sum>=n->right->value){
                    findSumPath(n->right, sum);   
                }
            }
            return (sum==0);
        }
        
        void displaySumPath(Node * n){
            if(n){
                displaySumPath(n->left);
                if(n->selectedSum){
                    cout << n->value << ' ';
                }
                displaySumPath(n->right);
            }
        }
        
        void vertSum(Node* node, int hd, map<int, int>& m){
            cout << "Part 3" << endl;
            getVertSum(root, hd, m);
            for(auto& x: m){
                cout << x.second << ' ';
            }
            cout << endl;
        } 
        
        void getVertSum(Node *n, int hd, map<int,int> &m){
            if(!root) return;
            if(n){
                m[hd]+=n->value;
                getVertSum(n->left,hd-1,m);
                getVertSum(n->right,hd+1,m);
            }
        }
        
        void preorder() const { 
            preorder(root); 
            cout << endl;
        }
        
        void preorder (Node * T) const{
        // Traverse and print the tree one Value per line in preorder.
        // FILL IN
            if(T==nil) return;
            if(T!=nil){
                cout << T->value << ' ';
                preorder(T->left);
                preorder(T->right);
            }
        }
        void postorder() const { 
            postorder(root);
            cout << endl;
        }
        void postorder(Node * T) const{
        // Traverse and print the tree one Value per line in postorder
        // FILL IN
            if(T==nil) return;
            if(T!=nil){
                postorder(T->left);
                postorder(T->right);
                cout << T->value << ' ';
            }
        }
            
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
        void remove( Value X ) { root = remove( X, root ); }
        Node* remove( Value X, Node*& T ) {
            // The normal binary-tree removal procedure ...
            // Weiss’s code is faster but way more intricate.
            if ( T != nil ) {
                if ( X > T->value ) {
                    T->right = remove( X, T->right );
                } else if ( X < T->value ) {
                    T->left = remove( X, T->left );
                } else {
                // X == T->value
                    if ( T->right != nil ) {
                        Node* x = T->right;
                        while ( x->left != nil ) x = x->left;
                        T->value = x->value; // successor’s value
                        T->right = remove( T->value, T->right );
                    } else if ( T->left != nil ) {
                        Node* x = T->left;
                        while ( x->right != nil ) x = x->right;
                        T->value = x->value; // predecessor’s value
                        T->left = remove( T->value, T->left );
                    } else { // *T is external
                        delete T;
                        T = nil; // the only updating of T
                    }
                }
            }
            // later, rebalancing code will be installed here
            return T;
        }
        
    }; // BST
#endif