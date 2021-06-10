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

int mutex_example() // ?? thread�� �����ư��鼭 WORK_FUNC�� �۵��Ǿ��� �� ������, �׳� THREAD1������ ����ȴ�...? mutex safe�� �̹� ������ �� ���ϱ�
{
    auto work_func = []() {
        for (int i = 0; i < 100; i++)
        {
            //            mtx.lock();
            sum++;
            cout << std::this_thread::get_id << " " << sum << endl;
            //cout�� �̻��ϰ� �����°��� proper �ϴ�. �߰��� thread�� �ٲ� �� �ֱ� ����
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

//�̿ܿ��� download project ���� �ִ�!