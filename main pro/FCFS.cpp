//FCFS.cpp

#include<bits/stdc++.h>
using namespace std;

struct processes{
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int process_id;
    int remaining_time;
    int turnarrount_time;
};

bool cmp(processes &a,processes &b){
    return a.arrival_time<b.arrival_time;
}
bool cmp_id(processes &a, processes &b){
    return a.process_id<b.process_id;
}
void FCFS(vector<processes>& process,int n){
    int currTime=0;
    for(int i=0;i<n;i++){
        process[i].completion_time=currTime+process[i].burst_time;
        currTime+=process[i].burst_time;
        process[i].turnarrount_time=process[i].completion_time-process[i].arrival_time;
        process[i].waiting_time=process[i].turnarrount_time-process[i].burst_time;
    }
    sort(process.begin(),process.end(),cmp_id);
    cout<<"PID"<<" \t "<<"AT"<<"\t"<<"BT"<<" \t"
        <<"CT"<<" \t"<<"TAT"<<"\t"<<"WT"<<endl;
    for(int i=0;i<n;i++){
        cout<<process[i].process_id<<" \t "<<process[i].arrival_time<<"\t"<<process[i].burst_time<<" \t"
        <<process[i].completion_time<<" \t"<<process[i].turnarrount_time<<"\t"<<process[i].waiting_time<<endl;
    }

}

int main(){
    int n;
    cout<<"Enter the no. of Processes : ";
    cin>>n;

    vector<processes> process(n);
    cout<<"Enter the aarival time and burst time : \n";
    for(int i=0;i<n;i++){
        process[i].process_id=i+1;
        cin>>process[i].arrival_time>>process[i].burst_time;
        cout<<"\n";
    }
    sort(process.begin(),process.end(),cmp);
    FCFS(process,n);
}
