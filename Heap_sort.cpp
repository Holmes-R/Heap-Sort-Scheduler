#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Task{
    string name;
    int priority;

    Task(string n , int p) : name(n),priority(p){}

};

void heapify(vector<Task>& tasks,int n ,int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && tasks[left].priority > tasks[largest].priority)
        largest = left;
    if(right<n &&  tasks[left].priority > tasks[largest].priority)
        largest = right;

    if(largest!=i){
        swap(tasks[i],tasks[largest]);
        heapify(tasks,n,largest);
    }


}
void heapSort(vector<Task>& tasks){
    int n = tasks.size();
    for(int i = n/2 -1;i>=0;i--){
        heapify(tasks,n,i);
    }
    for(int i = n-1;i>=0;i--){
        swap(tasks[0],tasks[i]);
        heapify(tasks,i,0);
    }

}

void printTasks(const vector<Task>& tasks){
    for(const auto& task:tasks){
        cout<<"Task:"<<task.name<<", Priority: "<<task.priority<<endl;
    }


}


int main(){
    int n;
    cout<<"Enter the number of tasks :";
    cin>>n;
    vector<Task> tasks;
    for(int i=0;i<n;i++){
        string name;
        int priority;
        cout<<"Enter name for task :"<<i+1<<" : ";
        cin>>name;
        cout<<"Enter priority for task :"<<i+1<<" : ";
        cin>>priority;
        tasks.emplace_back(name,priority);
    }
    heapSort(tasks);

    cout<<"\nSorted tasks by priority :\n";
    printTasks(tasks);
    return 0;
}
