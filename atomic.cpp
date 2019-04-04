#include <thread>
#include <atomic>
#include <list>
#include <stdio.h>
std::atomic<bool> bIsReady{false};
std::atomic<int> iCount{100};
void threadfun1(int id)
{
    printf("thread %d wait...\n", id);
    if (!bIsReady) {
        //meaningless
        std::this_thread::yield();
    }
    printf("thread %d start...\n", id);
    while (iCount > 0)
    {
        printf("iCount:%d\r\n", iCount--);
    }
}

int main()
{
    std::atomic_bool b;
    std::list<std::thread> lstThread;
    for (int i = 0; i < 10; ++i)
    {
        lstThread.push_back(std::thread(threadfun1, i));
    }
    for (auto& th : lstThread)
    {
        th.join();
    }
}
