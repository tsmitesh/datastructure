/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: GS-1237
 *
 * Created on 13 February 2020, 1:09 PM
 */

#include <iostream>

using namespace std;

// node of the linked list
struct stNode{
    int data;
    stNode *m_pNext;
};

class SingleList{
private:
    stNode *m_pHead;
    int m_nSize;
    
    void deleteAll();
public:
    
    SingleList():m_pHead(NULL),m_nSize(0){ }
    ~SingleList();
    
    void insert(int data);
    void addAtBegin(int data);
    void addAtPos(int data, int pos);    
    void print();
    void reverse();
    void eraseAll();
    int size();
    
};

SingleList::~SingleList(){    
    deleteAll();
}

void SingleList::eraseAll(){
    deleteAll();
}

void SingleList::deleteAll()
{
    while(m_pHead != NULL){
        stNode *pNode = m_pHead;
        m_pHead = m_pHead->m_pNext;
        delete pNode;
        m_nSize--;
    }
}

int SingleList::size()
{
    return m_nSize;
}

void SingleList::insert(int data){
    
    //if list empty
    if(m_pHead == NULL){
        m_pHead = new stNode();
        m_pHead->data = data;
        m_pHead->m_pNext = NULL;
        m_nSize++;
    }
    else
    {
        // store head node to temp
        stNode *pTempNode = m_pHead;
        
        while(pTempNode->m_pNext != NULL){
            pTempNode = pTempNode->m_pNext;
        }
        
        //create new node 
        stNode *pNode = new stNode();
        pNode->data = data;
        pNode->m_pNext = NULL;
        
        //attached new node at end
        pTempNode->m_pNext = pNode;    
        m_nSize++;
                
    }
    
}

void SingleList::addAtBegin(int data)
{
    // create node and attach to head
    stNode *pNode = new stNode();
    pNode->data = data;
    pNode->m_pNext = m_pHead;
    
    //reset head
    m_pHead = pNode;
    m_nSize++;
            
}

void SingleList::addAtPos(int data, int pos)
{
    //if pos < 0 
    if(pos < 0)
    {
        cout<<"invalid position"<<endl;
    }
    else if(pos == 0)
    {
        addAtBegin(data);
    }
    else if(pos > m_nSize)
    {
        cout<<"insert at end"<<endl;
        insert(data);
    }
    else
    {
        //iterate list to position
        int counter = 0;
        stNode *pNode = m_pHead;
        
        while( counter < (pos - 1)){
            pNode = pNode->m_pNext;
            counter++;
        }
        
        //create node
        stNode *p = new stNode();
        p->data = data;
        p->m_pNext = pNode->m_pNext;   // 1 2 3-> data 5->  6    
        pNode->m_pNext = p; // 3 -> 5
        m_nSize++;
    }
}

void SingleList::print()
{
    stNode *pNode = m_pHead;
    
    while(pNode != NULL){
        cout<<pNode->data<<endl;
        pNode = pNode->m_pNext;
    }
}

void SingleList::reverse(){
    stNode *pCurr = m_pHead;
    stNode *pPrev = NULL;
    
    while(pCurr != NULL){
        stNode *pNext = pCurr->m_pNext;
        pCurr->m_pNext = pPrev;
        pPrev = pCurr;
        pCurr = pNext;    
    }
    
    m_pHead = pPrev;
}



int main(int argc, char** argv) {
    
    SingleList l1;
    l1.insert(10);
    l1.insert(20);
    l1.insert(30);
    l1.insert(40);
    l1.insert(50);
    l1.addAtBegin(0);
    l1.addAtPos(25,3);
    l1.print();
    cout<<"===================="<<endl;
    l1.reverse();
    l1.print();
    cout<<"===================="<<endl;
    l1.reverse();
    l1.print();
    cout<<"===================="<<endl;
    
    l1.eraseAll();
    cout<<l1.size();
    
    return 0;
}

