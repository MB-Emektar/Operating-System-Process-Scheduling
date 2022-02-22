#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED


class Data {
protected:

    int mprocessID;
    int marrivalTime;
    int mrunTime;
    int mpriority;

public:
    Data(int processID, int arrivalTime, int runTime, int priority);
    //~Data();
    int getProcessID();
    int getArrivalTime();
    int getRunTime();
    int getPriority();

    void setRunTime(int runTime);
};

//Create a Data from necessary elements such as processID, arrivalTime, runTime, priority
Data::Data(int processID=0, int arrivalTime=0, int runTime=0, int priority=0):mprocessID{processID},marrivalTime{arrivalTime},mrunTime{runTime},mpriority{priority}{};

//Create getter methods for all elements of a data
int Data::getProcessID(){return mprocessID;};
int Data::getArrivalTime(){return marrivalTime;};
int Data::getRunTime(){return mrunTime;};
int Data::getPriority(){return mpriority;};

//Also a setter for run time is required, due to calculation of cpu time or next process etc.
void Data::setRunTime(int runTime){ mrunTime=runTime;};


#endif // DATA_H_INCLUDED
