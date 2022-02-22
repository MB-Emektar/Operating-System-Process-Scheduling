#ifndef BSTREE_H_INCLUDED
#define BSTREE_H_INCLUDED
#include "Data.h"

using namespace std;

//node class of the BST, named as NodeBST due to avoid conflicts.
class NodeBST {
public:
    //A node consists of a data with left and right nodes.
    Data mdata;
    NodeBST* mleft,*mright;

    NodeBST(){mdata = 0;mleft = NULL;mright = NULL;}
    NodeBST(Data data){mdata = data;mleft = NULL;mright = NULL;}
};

class BSTree {
    //A BST is created with a root.
protected:
    NodeBST* root;
public:
    //Create some variables to calculate performances of the
    //methods in insertion, deletion, finding next node processes.
    int ins_count_BST=0,del_count_BST=0,search_count_BST=0;

    //Constructor
    BSTree() { root = NULL; }
    //Necessary methods for insertion, we need two of them for
    //method to call itself recursively due to complex processes.
    void insertNode(Data);
    NodeBST* insertNode(Data data,NodeBST* t);

    //Necessary methods for deletion, we need two of them for
    //method to call itself recursively due to complex processes.
    Data deleteNode();
    NodeBST* deleteNode(Data x, NodeBST* t);
    //findMin method is required for the deletion process
    //the above methods call the findMin method.
    NodeBST* findMin(NodeBST* t);

    //returns 1 if BST is empty
    int isEmpty();
};

void BSTree::insertNode(Data data) {
    root = insertNode(data, root);
}

NodeBST* BSTree::insertNode(Data x, NodeBST* t){
        ins_count_BST++;//Count how many node visited in the insertion process
        if(t == NULL)
        {
            t = new NodeBST;
            t->mdata = x;
            t->mleft = t->mright = NULL;
        }
        else if(x.getPriority() < t->mdata.getPriority())
            {t->mleft = insertNode(x, t->mleft);}
        else if(x.getPriority() > t->mdata.getPriority())
            {t->mright = insertNode(x, t->mright);}
        return t;
    }

Data BSTree::deleteNode() {
    NodeBST* temp = findMin(root);
    Data tempData =temp->mdata;
        root = deleteNode(temp->mdata, root);del_count_BST++;
        return tempData;
    }

NodeBST* BSTree::deleteNode(Data x, NodeBST* t) {
        del_count_BST++;//Count how many node visited in the deletion process
        NodeBST* temp;
        if(t == NULL)
            return NULL;
        else if(x.getPriority() < t->mdata.getPriority())
            {t->mleft = deleteNode(x, t->mleft);}
        else if(x.getPriority() > t->mdata.getPriority())
            {t->mright = deleteNode(x, t->mright);}
        else if(t->mleft && t->mright)
        {
            temp = findMin(t->mright);
            t->mdata = temp->mdata;
            t->mright = deleteNode(t->mdata, t->mright);

        }
        else
        {
            temp = t;
            if(t->mleft == NULL)
                {t = t->mright;}
            else if(t->mright == NULL)
                {t = t->mleft;}
            delete temp;
        }

        return t;
    }

NodeBST* BSTree::findMin(NodeBST* t){
    search_count_BST++;
        if(t == NULL)
            return NULL;
        else if(t->mleft == NULL)
            {return t;}
        else
            {return findMin(t->mleft);}
    }

int BSTree::isEmpty(){return(root == NULL);}



#endif // BSTREE_H_INCLUDED
