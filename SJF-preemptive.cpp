#include <iostream>
#include <fstream>
using namespace std;
 
struct Process {
    int pid; 
    int arrival_time; 
    int burst_time; 
};

int main()
{
    ifstream file;
    file.open("Process.dat");
    int n;
    file >> n;
    Process proc[n];
    for (int i = 0; i < n; i++) {
        file >> proc[i].pid;
        file >> proc[i].arrival_time;
        file >> proc[i].burst_time;
    }
    int arr[n];
    int wt[n];
    cout << "Thu tu thuc hien tien trinh: ";
    for (int i = 0; i < n; i++) {
        arr[i] = proc[i].burst_time;
    }
    int complete = 0, time = 0, min = 10000000;
    int shortest = 0, finish_time;
    bool check = false;
    while (complete != n) {
        int temp = shortest;
        for (int i = 0; i < n; i++) {
            if ((proc[i].arrival_time <= time) &&
                (arr[i] < min) && arr[i] > 0) {
                min = arr[i];
                shortest = i;
                check = true;
            }
        }
        if (check == false) {
            time++;            
        }
        arr[shortest]--;
        min = arr[shortest];
        if (min == 0)
            min = 10000000;
        if (arr[shortest] == 0) {
            complete++;
            check = false;
            finish_time = time + 1;
            wt[shortest] = finish_time - proc[shortest].burst_time 
            - proc[shortest].arrival_time;
            if (wt[shortest] < 0) {
                wt[shortest] = 0;  
            }     
        }
        if (shortest != temp) {
            cout << "P" << temp + 1 << " -> ";
        }
        time++;
    }
    cout << "P" << shortest + 1;
    float sum_wt = 0;
    cout << "\nThoi gian cho: ";
    for (int i = 0; i < n; i++) {
        cout << "P" << proc[i].pid << " = " << wt[i];
        if (i < n - 1) {
            cout << "; ";
        }
        sum_wt = sum_wt + wt[i];
    }
    cout << "\nThoi gian cho trung binh cua cac tien trinh: " 
        << sum_wt / n << endl;
}