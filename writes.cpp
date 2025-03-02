#include "write.hpp"

/** 
 * Constructor: The constructor for the WriteHandler, 
 * creates the the threads specified as the number of threads, and allocates 
 * write file object to each of the threads
 *                           
 * @param   filePath      The path of the file to be write.
 * @param   numThreads    The number of write threads to be created
 */

WriteHandler :: WriteHandler(const char * filePath, size_t numThreads) {
    
}

/** 
 * Destructor: makes sure all the write threads are joined.
 */
WriteHandler :: ~WriteHandler() {
}

/**
 * This function adds the buffer into the write queue, wakes up the writes threads if they are sleeping.
 * 
 * @param buffer  The buffer block which needs to be written
 * @param offset  Offset which tells the offset of the block to be read
 * 
 *  
 * @return bool    Returns true if the write was succeful else false.
 */
bool WriteHandler :: AddBufferIntoQueue(char * buffer, size_t offset) {
    return false;
}

/**
 * This function returns true if the given offset in waiting in the writing queue
 * 
 * @param offset  Offset to check if its waiting in the write queue
 * 
 * @return bool    Returns true the offset present in the write queue
 */
bool WriteHandler :: IsOffsetInQueue(size_t offset) {
    return false;
}

/**
 * This function returns the buffer for the given offset.
 * Note : this function to be called only if the offset is waiting in the write queue.
 * 
 * @param offset  Offset to check if its waiting in the write queue
 *  
 * @return char *  Returns the buffer for the offset
 */
char * WriteHandler :: BufferFromOffset(size_t offset) {
    return NULL;
}

/**
 * This function is for each thread running on seperate cores to handle writes
 * 
 * @param threadId  The Id of the current thread being run
 */
void WriteHandler :: WriterFunction(int threadId) {
    
}

