#include <fcntl.h>
#include <iostream>
#include <unistd.h>

using namespace std;

/*
* class for handling writes.
*/
class FileWriteLockFree {
    public:
        FileWriteLockFree(const char * writePath);
        ~FileWriteLockFree();

        // Function to write a block of data into the file in the given offset
        bool WriteToOffset(const char * buffer, size_t offset);

    private:
        int fdWrite;
        size_t bufferSize;
};

/*
* class for handling reads.
*/
class FileReadLockFree {
    public:
        FileReadLockFree(string readPath);
        ~FileReadLockFree();

        // Function to read a block of data from file in the given offset
        char * ReadFromOffset(size_t offset);

    private:
        int fdRead;
        size_t bufferSize;
};