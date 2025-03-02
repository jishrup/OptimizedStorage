#include "files.hpp"
#include <thread>

using namespace std;

/*
* class for handling writes, multiple thread handles writes.
* Each thread is assigned to a core to handle writes. Writes are handled considering
* the NUMA aware architecture of the system avoiding multiple switch between the RAM and the Cache.
*/
class WriteHandler {
    public:
        WriteHandler(const char * filePath, size_t numThreads);
        ~WriteHandler();

        // Function to add the a write buffer into the queue
        bool AddBufferIntoQueue(char * buffer, size_t offset);

        // Function to check if the offset is there in the queue
        bool IsOffsetInQueue(size_t offset);

        // Function return the buffer for the given offset
        char * BufferFromOffset(size_t offset);

    private:
        // The function which handles the writes, the thread runs on these function
        void WriterFunction(int threadId);


        vector<thread> threads;                          // vector of threads to handle write
        vector<unique_ptr<FileWriteLockFree>> filobj;    // vector of Lock Free file object to handle write for each write threads
        unordered_map<size_t, char *> writmap;           // map to hold the pending write task
        deque<size_t> writequeue;                        // queue to manage the write operations
};