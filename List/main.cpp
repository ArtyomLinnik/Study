//
//  main.cpp
//  List
//
//  Created by Artyom Linnik on 13/02/16.
//  Copyright © 2016 Artyom Linnik. All rights reserved.
//

#include <iostream>

struct Node
{
    int d;
    Node *next;
    Node *prev;
};

//---------------------------------------------

Node * first(int d);
void add(Node **pend, int d);
Node * find(Node * const pbeg, int i);
bool remove(Node **pbeg, Node **pend, int key);
Node * insert(Node * const pbeg, Node **pend, int key, int d);
void add_sort(Node **pbeg, Node **pend, int d);

//---------------------------------------------

int main(int argc, const char * argv[])
{
    Node *pbeg = first(1);      // form 1st element
    Node *pend = pbeg;          // init end of lsit
    // add 4 elements:
    for (int i=2; i<6; i++) add(&pend, i);
    // insert element 200 after element 2:
    insert(pbeg, &pend, 2, 200);
    // delete element 5:
    if (!remove(&pbeg, &pend, 5)) std::cout << "cant find element" << std::endl;
    Node *pv = pbeg;
    while (pv)          // output list
    {
        std::cout << pv -> d << " ";
        pv = pv->next;
    }
    return 0;
}

//---------------------------------------------

// form list
Node * first(int d)
{
    Node *pv= new Node;
    pv->d = d;
    pv->next = 0;
    pv->prev = 0;
    return pv;
}

//---------------------------------------------

// add to the end
void add(Node **pend, int d)
{
    Node *pv = new Node;
    pv->d = d;
    pv->next = 0;
    pv->prev = *pend;
    (*pend)->next = pv;
    *pend = pv;
}

//---------------------------------------------

// search element
Node * find(Node * const pbeg, int d)
{
    Node *pv = pbeg;
    while (pv)
    {
        if(pv->d == d) break;
        pv = pv->next;
    }
    return pv;
}

//---------------------------------------------

// remove element
bool remove(Node **pbeg, Node **pend, int key)
{
    if(Node *pkey = find(*pbeg, key)) {                     // 1
        if(pkey == *pbeg) {                                 // 2
            *pbeg = (*pbeg)->next;
            (*pbeg)->prev = 0;}
        else if (pkey == *pend) {                           // 3
            *pend = (*pend)->prev;
            (*pend)->next = 0;}
        else {                                              // 4
            (pkey->prev)->next = pkey->next;
            (pkey->next)->prev = pkey->prev;}
        delete pkey;
        return true;                                        // 5
    }
    return false;                                           // 6
}

//---------------------------------------------

// insert element
Node * insert(Node * const pbeg, Node **pend, int key, int d)
{
    if (Node *pkey = find(pbeg, key)) {
        Node *pv = new Node;
        pv->d = d;
        // 1 - connect new node with next:
        pv->next = pkey->next;
        // 2 - connect new node with prev:
        pv->prev = pkey;
        // 3 - connect prev node with next:
        pkey->next = pv;
        // 4 - connect next node with new:
        if (pkey != *pend) (pv->next)->prev = pv;
        // pointer on the end,
        // if node insert in the end:
        else *pend = pv;
        return pv;
    }
    return 0;
}

//---------------------------------------------

// sort list
void add_sort(Node **pbeg, Node **pend, int d)
{
    Node *pv = new Node;
    pv->d = d;
    Node * pt = *pbeg;
    while (pt) {
        if (d< pt->d) { // before d elem
            pv->next = pt;
            if (pt == *pbeg) { // to the begining
                pv->prev = 0;
                *pbeg = pv;}
            else {       // in the middle
                (pt->prev)->next = pv;
                pv->prev = pt->prev;}
            pt->prev = pv;
            return;
        }
        pt=pt->next;
    }
    pv->next = 0; // in the end
    pv->prev = *pend;
    (*pend)->next = pv;
    *pend = pv;
}












