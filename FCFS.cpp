#include <iostream>
#include <fstream>
using namespace std;

struct Process {
    string name_process;
    float burst_time;
};

int main() {
    ifstream file;
    file.open("Process.dat");
    int number_process;
    file >> number_process;
    Process p[number_process];
    for (int i = 0; i < number_process; i++) {
        file >> p[i].name_process;
        file >> p[i].burst_time;
    }
    cout << "Thu tu thuc hien tien trinh: ";
    for (int i = 0; i < number_process; i++) {
        cout << p[i].name_process;
        if (i < number_process - 1) {
            cout << " -> ";
        }
    }
    cout << "\nThoi gian cho: ";
    float waiting_time = 0;
    float sum_time = 0;
    for (int i = 0; i < number_process; i++) {
        cout << p[i].name_process << " = " << waiting_time;
        sum_time += waiting_time;
        waiting_time += p[i].burst_time;
        if (i < number_process - 1) {
            cout << "; ";
        }
    }
    cout << "\nThoi gian cho trung binh cua cac tien trinh: "
        << sum_time / number_process << endl;
}