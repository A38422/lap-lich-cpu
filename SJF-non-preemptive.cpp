#include <iostream>
#include <fstream>
using namespace std;

struct Process {
    string name_process;
    float arrival_time;
    float burst_time;
};

int main() {
    ifstream file;
    file.open("Process2.dat");
    int number_process;
    file >> number_process;
    Process a[number_process];
    for (int i = 0; i < number_process; i++) {
        file >> a[i].name_process;
        file >> a[i].arrival_time;
        file >> a[i].burst_time;
    }
    cout << "Thu tu thuc hien tien trinh: ";
    float sum = a[0].burst_time;
    for (int i = 1; i < number_process - 1; i++) {
        for (int j = i + 1; j < number_process; j++) {
            if (a[i].burst_time > a[j].burst_time && 
                a[j].arrival_time < sum) {
                swap(a[i], a[j]);
            }
        }
        sum += a[i].burst_time;
    }
    for (int i = 0; i < number_process; i++) {
        cout << a[i].name_process;
        if (i < number_process - 1) {
            cout << " -> ";
        }
    }
    cout << "\nThoi gian cho: ";
    float waiting_time = 0;
    float sum_time = 0;
    for (int i = 0; i < number_process; i++) {
        cout << a[i].name_process << " = " 
            << waiting_time - a[i].arrival_time;
        sum_time += (waiting_time - a[i].arrival_time);
        waiting_time += a[i].burst_time;
        if (i < number_process - 1) {
            cout << "; ";
        }
    }
    cout << "\nThoi gian cho trung binh cua cac tien trinh: "
        << sum_time / number_process << endl;
}