#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <list>

using namespace std;

/*
* class for handling buffer swaps to avoid going to the storage each time for reads.
* Method of caching : Least Recently Used
*/
class LRUCache {
public:
    LRUCache(size_t capacity);
    ~LRUCache();
    
    // Function to return the Block contents if present in the buffer
    char * get(size_t block_id);
    // Function to add a block into the buffer
    void put(size_t block_id, char * value);

    private:
        size_t cap;                                                         // specify the size of the LRU cache size
        unordered_map<size_t, pair<char *, list<size_t>::iterator>> mp;     // map to hold the buffer value for a block id
        list<size_t> ls;                                                    // list to hold the block id
};  