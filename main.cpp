#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
using std::thread;
bool isStop = false;
int g_num = 0;
mutex g_m;
void func1() {
    for(; !isStop;) {
        g_m.lock();
        cout << "Thread 1 is running(" << g_num++ << ")" << endl;
        g_m.unlock();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}
void func2() {
    for(; !isStop;) {
        g_m.lock();
        cout << "Thread 2 is running(" << g_num++ << ")" << endl;
        g_m.unlock();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}
void func3() {
    for(; !isStop;) {
        g_m.lock();
        cout << "Thread 3 is running(" << g_num++ << ")" << endl;
        g_m.unlock();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}
void func4() {
    for(; !isStop;) {
        int num;
        cin >> num;
        if(num == 0) isStop = true;
    }
}
int main()
{
    thread t1(func1);
    thread t2(func2);
    thread t3(func3);
    thread t4(func4);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
