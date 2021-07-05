#include <iostream>
#include <mutex> //mutual exclusion
#include <thread>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

int thread_create(); //thread create
mutex mtx;
int sum = 0;
int mutex_example();
int main()
{
    //    thread_create();
    mutex_example();
    return 0;
}

int mutex_example() // ?? thread가 번갈아가면서 WORK_FUNC가 작동되야할 것 같은데, 그냥 THREAD1에서만 진행된다...? mutex safe가 이미 적용이 된 것일까
{
    auto work_func = []() {
        for (int i = 0; i < 100; i++)
        {
            //            mtx.lock();
            sum++;
            cout << std::this_thread::get_id << " " << sum << endl;
            //cout이 이상하게 나오는것은 proper 하다. 중간에 thread가 바뀔 수 있기 때문
            //            mtx.unlock();
        }
    };
    std::thread t1 = std::thread(work_func);
    std::thread t2 = std::thread(work_func);
    t1.join();
    t2.join();
    return 1;
}
int thread_create()
{
    cout << "thread creating started" << endl;
    const int num_pro = std::thread::hardware_concurrency();
    cout << std::this_thread::get_id() << endl;
    std::thread t1 = std::thread([]() {
        cout << std::this_thread::get_id() << endl;
    });
    t1.join();
    cout << "thread creating ended" << endl;
    return 1;
}

//이외에도 download project 등이 있다!
//https://github.com/gyoogle/tech-interview-for-developer/blob/master/Computer%20Science/Operating%20System/%5BOS%5D%20System%20Call%20(Fork%20Wait%20Exec).md
//위의 링크처럼, fork, exec, wait을 이해할 수 있게 되었다!
