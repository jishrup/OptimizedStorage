#include "read_write.hpp"
#include "../communication/general.hpp"
#include <thread>

using namespace std;

/*
* class for handling Reads, multiple thread handles reads.
* Each thread is assigned to a core to handle reads. Reads are handled considering
* the NUMA aware architecture of the system avoiding multiple switch between the RAM and the Cache.
*/
class ReadHandler {
    public:
        ReadHandler(const char * filePath, size_t numThreads);
        ~ReadHandler();

        // Function to add the a offset into the read queue
        bool AddOffsetIntoQueue(shared_ptr<Request> req, size_t offset);

    private:
        // The function which handles the writes, the thread runs on these function
        void ReadFunction(int threadId);


        vector<thread> threads;                                // vector of threads to handle reads
        vector<unique_ptr<FileReadLockFree>> filobj;           // vector of Lock Free file object to handle read for each requested reads
        unordered_map<size_t, shared_ptr<Request>> readmap;    // map to hold the pending read task
        deque<size_t> readqueue;                               // queue to manage the read operations
};