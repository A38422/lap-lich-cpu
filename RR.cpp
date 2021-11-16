#include <iostream>
#include <fstream>
using namespace std;

struct Process {
    string name_process;
    int burst_time;
};
 
int main()
{
    ifstream file;
    file.open("Process.dat");
    int n;
    file >> n;
    Process proc[n];
    int q;
    file >> q;
    for (int i = 0; i < n; i++) {
        file >> proc[i].name_process;
        file >> proc[i].burst_time;
    }
    int bt[n]; //bien nho burst time
    int wt[n];
    for (int i = 0 ; i < n ; i++) {
        bt[i] = proc[i].burst_time;
    }
    int time = 0;
    cout << "Thu tu thuc hien tien trinh: ";
    while (true)
    {
        bool check = true;
        for (int i = 0 ; i < n; i++)
        {
            if (bt[i] > 0)
            {
                check = false;
                if (bt[i] > q)
                {
                    time += q;
                    bt[i] -= q;
                    cout << proc[i].name_process;
                }
                else
                {
                    time += bt[i];
                    wt[i] = time - proc[i].burst_time;
                    bt[i] = 0;
                    cout << proc[i].name_process;
                }
                cout << " ";
            }
        }
        if (check == true) {
            break;
        }
    }
    cout << "\nThoi gian cho: ";
    float sum_wt = 0;
    for (int i = 0; i < n; i++)
    {
        cout << proc[i].name_process << " = " << wt[i];
        if (i < n - 1) {
            cout << "; ";
        }
        sum_wt += wt[i];
    }
    cout << "\nThoi gian cho trung binh cua cac tien trinh: "
        << sum_wt / n << endl;
}