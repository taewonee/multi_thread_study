#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <chrono>
#include <string>

using namespace std;
//thread create
int main()
{
    cout << "started" << endl;
    const int num_pro = std::thread::hardware_concurrency();
    cout << std::this_thread::get_id() << endl;
    std::thread t1 = std::thread([]() {
        cout << std::this_thread::get_id() << endl;
    });
    t1.join();
    return 0;
}