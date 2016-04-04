//
//  main.cpp
//  BinaryTree
//
//  Created by Artyom Linnik on 15/02/16.
//  Copyright © 2016 Artyom Linnik. All rights reserved.
//

#include <iostream>

struct Node
{
    int d;
    Node *left;
    Node *right;
};

Node * first (int d);
Node * search_insert(Node *root, int d);
void print_tree(Node *root, int l);

//-----------------------------------------------------

int main(int argc, const char * argv[]) {
    int b[] = {10, 25, 6, 21, 8, 1, 30};
    Node *root = first(b[0]);
    for (int i=0; i<8; i++ ) search_insert(root, b[i]);
    print_tree(root, 0);
    return 0;
}

//-----------------------------------------------------
// form first element of tree
Node * first(int d)
{
    Node *pv = new Node;
    pv->d = d;
    pv->left = 0;
    pv->right = 0;
    return pv;
}

//-----------------------------------------------------
// search with insert
Node * search_insert(Node *root, int d)
{
    Node *pv = root, *prev = nullptr;
    bool found = false;
    while (pv && !found) {
        prev = pv;
        if (d == pv->d) found = true;
        else if (d< pv->d) pv = pv->left;
        else pv = pv->right;
    }
    if (found) return pv;
    // create new node
    Node *pnew = new Node;
    pnew->d = d;
    pnew->left = 0;
    pnew->right = 0;
    if (d < prev->d)
        // add to left
        prev->left = pnew;
    else
        // add to right
        prev->right = pnew;
    return pnew;
}

//-----------------------------------------------------
//around tree
void print_tree(Node *p, int level)
{
    if (p)
    {
        print_tree(p->left, level + 1);  //print left subtree
        for (int i=0; i<level; i++) std::cout << "   ";
        std::cout << p->d << std::endl;     //print root
        print_tree(p->right, level + 1);  // print right subtree
    }
}