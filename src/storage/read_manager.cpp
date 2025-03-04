#include "read_manager.hpp"

/** 
 * Constructor: The constructor for the ReadHandler, 
 * creates the the threads specified as the number of threads, and allocates 
 * Read file object to each of the threads
 *                           
 * @param   filePath      The path of the file from we read.
 * @param   numThreads    The number of read threads to be created
 */

ReadHandler :: ReadHandler(const char * filePath, size_t numThreads) {
    
}

/** 
 * Destructor: makes sure all the read threads are joined.
 */
ReadHandler :: ~ReadHandler() {
}

/**
 * This function adds the offset into the read queue, wakes up the read threads if they are sleeping.
 * 
 * @param buffer  The request object where the data will be written and returned back
 * @param offset  Offset which tells the offset of the block to be read
 * 
 *  
 * @return bool    Returns true if the read was succeful else false.
 */
bool ReadHandler :: AddOffsetIntoQueue(shared_ptr<Request> req, size_t offset) {
    return false;
}

/**
 * This function is for each thread running on seperate cores to handle writes
 * 
 * @param threadId  The Id of the current thread being run
 */
void ReadHandler :: ReadFunction(int threadId) {
    
}

