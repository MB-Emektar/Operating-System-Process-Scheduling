#include <iostream>
#include <fstream>
#include "Data.h"
#include "LinkedList.h"
#include "BSTree.h"

using namespace std;

/*//////////////////////////////////// COMMENTS ///////////////////////////////
        The results of the program can be shown from the .txt files or in the
    capture.png(capture.png shows decreasing order of process case up to bottom.
    The left side is for LL and the right is for the BST).
        The deletion and searching counts for LL is the same since the list is already
    sorted in the descending priority order.
        It seems from the results that the BST is much more efficient than the
    LL especially in higher amounts of data. In "1000 processes" case, the BST
    had total of ~30k visits, however LL made ~159k visits.
        The one advantage of LL is that, it does not spend much time to delete a
    process from the list. Because the processes are already sorted.
*/

//The Linked List Process Scheduler function is declared
void processSchedulerLinkedlist(int numProcesses, Data* process );
//The Binary Search Tree Process Scheduler function is declared
void processSchedulerBST(int numProcesses, Data* process );

int main(){

//////////////////////////////////// READ DATA FROM FILE ///////////////////////////////
ifstream processesFile;
processesFile.open ("processes.txt");
int numProcesses;
processesFile >> numProcesses;

//The processes are classified as Data to avoid confusion.
//Because LL and BST classes also use "node" name as a class.
Data process[numProcesses];
int processID, arrivalTime, runTime, priority;
for(int i=0; i<numProcesses; ++i){
        processesFile >> processID >> arrivalTime >> runTime >> priority;
        process[i] = Data(processID, arrivalTime, runTime, priority);
}
processesFile.close();

//////////////////////////////////// CALL PROCESS SCHEDULER FUNCTIONS ////////////////////////////////
//choose one of the process: LL or BST

processSchedulerLinkedlist(numProcesses,process);
//processSchedulerBST(numProcesses,process);

    return 0;
}

//////////////////////////////////// PROCESS SCHEDULER FUNCTIONS ////////////////////////////////

void processSchedulerLinkedlist(int numProcesses,Data* process ){
Linkedlist RQ; //Create a Linkedlist named as RQ, to store processes

int time = 0;
bool CPUBusy = false;
Data* currentProcess = NULL ;

int processIndex = 0;
Data tempData;
    cout<< "Linked List RQ Implementation"<< endl;cout<< endl;
while ( processIndex < numProcesses || RQ.isEmpty()!=1 || CPUBusy == true){
    //RQ.printList();
    if (processIndex < numProcesses){
        if (process[processIndex].getArrivalTime() == time){
            RQ.insertNode(process[processIndex]);
            processIndex = processIndex + 1;}}

    if (CPUBusy == true){
        currentProcess->setRunTime(  currentProcess->getRunTime() -1);}

    if (currentProcess!=NULL && currentProcess->getRunTime() == 0){
        CPUBusy = false;
          cout<<currentProcess->getProcessID()<< endl;//prints the finished process
        }
    if (CPUBusy == false && RQ.isEmpty()!=1){

        tempData = RQ.deleteNode();// delete the highest priority process and delete it from Linkedlist
        currentProcess = &(tempData);

        CPUBusy = true;
        }


    time++;

    }

    cout<< endl;cout<<RQ.del_count_LL<< " nodes visited for searching"<< endl;
    cout<<RQ.ins_count_LL<< " nodes visited for insertion"<< endl;
    cout<<RQ.del_count_LL<< " nodes visited for deletion"<< endl;

    cout<< endl;cout<< "Linked List RQ Implementation"<< endl;

}

void processSchedulerBST(int numProcesses,Data* process ){

BSTree RQ;//Create a Binary Search Tree named as RQ, to store processes

int time = 0;
bool CPUBusy = false;
Data* currentProcess = NULL ;

int processIndex = 0;
Data tempData;
    cout<< "Binary Search Tree RQ Implementation"<< endl;cout<< endl;
while ( processIndex < numProcesses || RQ.isEmpty()!=1 || CPUBusy == true){
    if (processIndex < numProcesses){
        if (process[processIndex].getArrivalTime() == time){
            RQ.insertNode(process[processIndex]);
            processIndex = processIndex + 1;}}

    if (CPUBusy == true){
        currentProcess->setRunTime(  currentProcess->getRunTime() -1);}

    if (currentProcess!=NULL && currentProcess->getRunTime() == 0){
        CPUBusy = false;
          cout<<currentProcess->getProcessID()<< endl;//prints the finished process
        }
    if (CPUBusy == false && RQ.isEmpty()!=1){

        tempData = RQ.deleteNode();
        currentProcess = &(tempData);// delete the highest priority process and delete it from BST

        CPUBusy = true;
        }

    time++;

    }

    cout<< endl;cout<<RQ.search_count_BST<< " nodes visited for searching"<< endl;
    cout<<RQ.ins_count_BST<< " nodes visited for insertion"<< endl;
    cout<<RQ.del_count_BST<< " nodes visited for deletion"<< endl;

    cout<< endl;cout<< "Binary Search Tree RQ Implementation"<< endl;

}
