#include "read_write.hpp"

/** 
 * Constructor: The constructor for the FileWriteLockFree, 
 * creates the file descriptor for the file for the given path. 
 * Terminates if the file cant be opened.
 *                           
 * @param   writePath      The path of the file to be write.
 */

FileWriteLockFree :: FileWriteLockFree(const char * writePath) {
    fdWrite = open(writePath, O_WRONLY | O_APPEND);
    
    if (fdWrite == -1) {
        cerr << "Failed to open the file\n";
        exit(0);
    }

    bufferSize = 8192;
}

/** 
 * Destructor: closes the file descriptor assiciated with the object.
 */
FileWriteLockFree :: ~FileWriteLockFree() {
    close(fdWrite);
}

/**
 * This function writes the given block of the data into the given offset in the file.
 * If the write is not successful or not complete the correct error message is shown.
 * 
 * @param buffer  The buffer block which needs to be written
 * @param offset  Offset which tells the offset of the block to be read
 * 
 *  
 * @return bool    Returns true if the write was succesful else false.
 */
bool FileWriteLockFree :: WriteToOffset(const char * buffer, size_t offset) {
    if(strlen(buffer) != bufferSize) {
        cerr << "buffer size should be equal to 8192, but current buffer size is : " << buffer.size() <<" and offset is : " << offset << endl;
        return false;
    }
    size_t pos = offset * bufferSize; // actual position is equal to 8K * offset

    size_t bytes_written = pwrite(fdWrite, buffer, bufferSize, pos);

    if (bytes_written == -1) {
        cerr << "Failed to write to file" << endl;
        return false;
    } else if(bytes_written != bufferSize){
        cerr << "Could write only : "<< bytes_written << endl;
        return false;
    } else {
        cout << "Successfully wrote " << bytes_written << " bytes at offset " << offset << endl;
        return true;
    }
}



/** 
 * Constructor: The constructor for the FileReadLockFree, 
 * creates the file descriptor for the file for the given path. 
 * Terminates if the file cant be opened.
 *                           
 * @param   readPath      The path of the file to be read.
 */
FileReadLockFree :: FileReadLockFree(string readPath) {
    fdRead = open(readPath.c_str(), O_RDONLY);
    
    if (fdRead == -1) {
        cerr << "Failed to open the file\n";
        exit(0);
    }

    bufferSize = 8192;
}

/** 
 * Destructor: closes the file descriptor assiciated with the object.
 */
FileReadLockFree :: ~FileReadLockFree() {
    close(fdRead);
}

/**
 * This function reads 8192 bytes from the given offset and returns the value.
 * If the bytes read is not equal to 8192 or read is not posssible then the correct error is 
 * displayed.
 * 
 * @param offset  Offset which tells the offset of the block to be read
 * 
 *  
 * @return char *    The 8192 bytes of the memory read(block) if succesful. 
 */
char*  FileReadLockFree :: ReadFromOffset(size_t offset) {
    size_t pos = offset * bufferSize; // actual position is equal to 8K * offset

    char buffer[bufferSize + 1];  // +1 for null terminator
    memset(buffer, 0, bufferSize + 1);  // Initialize buffer

    size_t bytes_read = pread(fdRead, buffer, bufferSize, pos);

    if (bytes_read == -1) {
        cerr << "Failed to write to file" << endl;
        return NULL;
    } else if(bytes_read != bufferSize){
        cerr << "Could write only : "<< bytes_read << endl;
        return buffer;
    } else {
        cout << "Successfully wrote " << bytes_read << " bytes at offset " << offset << endl;
        return buffer;
    }
}