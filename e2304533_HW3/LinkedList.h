#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "Data.h"




using namespace std;
class Node {
public:
    Data mdata;
    Node* mnext;


    Node(){mdata = 0;mnext = NULL;}
    Node(Data data){mdata = data;mnext = NULL;}
};

class Linkedlist {
    Node* head;

public:
    //Create some variables to calculate performances of the
    //methods in insertion, deletion, finding next node processes.
    int ins_count_LL,del_count_LL,next_count_LL;

    //Constructor
    Linkedlist() { head = NULL;ins_count_LL=0;del_count_LL=0; }

    void insertNode(Data);
    Data deleteNode(void);
    //returns 1 if list is empty
    int isEmpty();

    void printList();//prints the whole list, used while debugging
};

void Linkedlist::insertNode(Data data){

    //create a new node from the given data
    Node* new_node = new Node();
    new_node->mdata = data;

    //we have 3 option
    //1-list could be empty
    if(head == NULL){
        new_node->mnext = head;
        head = new_node;
        return;
    }
    //2-list could be consist only of head
    else if (head->mnext== NULL){
            if (data.getPriority() < head->mdata.getPriority()){
                new_node->mnext = head;
                head = new_node;
                ins_count_LL++;return;
            }
            else {
                head->mnext = new_node;
                ins_count_LL++;return;
            }

    }
    //3-list could have more than 2 nodes
    else{
        Node* temp1=head,*prev=NULL;

        //travel through all the list
        while( temp1 != NULL){
            ins_count_LL++;
            if( prev==NULL || data.getPriority() >= prev->mdata.getPriority()  ){
                if ( data.getPriority() < temp1->mdata.getPriority()  ){
                    //if the given data has lower priority than the previous node
                    //and higher priority than the current node, insert it between
                    if(prev!=NULL){prev->mnext =new_node;new_node->mnext = temp1;}
                    else if(prev==NULL) {new_node->mnext = head;head = new_node;}
                    return;
                }
            }
            prev = temp1;
            temp1 = temp1->mnext;

        }
    //if the data has lower than all the processes in the queue:
    prev->mnext = new_node;
    return;
    }
 return;
    }


Data Linkedlist::deleteNode(void){
    //Delete the head of the list. The list is already sorted according to
    //priorities in the insertion process.
    Data tempData = head->mdata;
    if(head->mnext == NULL) head = NULL;
    else *head = *head->mnext;
    del_count_LL++;return tempData;
}


int Linkedlist::isEmpty(){
    return(head == NULL);
}

void Linkedlist::printList(){
    Node* temp = head;

    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL) {
        cout << temp->mdata.getProcessID() << endl;
        temp = temp->mnext;
    }

     cout << "////////////////////////////////" << endl;
    return;
}

#endif // LINKEDLIST_H_INCLUDED
