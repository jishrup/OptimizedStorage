#include <iostream>
#include <thread>
#include <vector>
#include <pthread.h>
#include <mach/thread_policy.h>
#include <mach/mach.h>

void setThreadAffinity(int core_id) {
    thread_affinity_policy_data_t policy = {core_id};
    thread_policy_set(mach_thread_self(), THREAD_AFFINITY_POLICY,
                      (thread_policy_t)&policy, 1);
}

void task(int thread_id) {
    setThreadAffinity(thread_id);  
    std::cout << "Thread " << thread_id << " running on CPU core: " << thread_id << std::endl;
}

int main() {
    int num_cores = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    for (int i = 0; i < num_cores; i++) {
        threads.emplace_back(task, i);
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
