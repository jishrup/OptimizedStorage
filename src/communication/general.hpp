#include <iostream>
#include <cstring>

enum ReqType {
    REQ_DEFAULT,
    REQ_READ,
    REQ_WRITE
};

struct Request {
    size_t req_id;
    ReqType req_type;
    char* data;

    // Constructor to initialize request
    Request() {
        req_id = 0;
        req_type = REQ_DEFAULT;
        data = NULL;
    }
    
    Request(size_t id, ReqType type, const char* input_data) 
        : req_id(id), req_type(type) {
        
        // Allocate memory for data and copy input string
        data = new char[strlen(input_data) + 1];
        strcpy(data, input_data);
    }

    // Destructor to free allocated memory
    ~Request() {
        delete[] data;
    }

    /*
    * To Add : communication data
    */
};