#include "buffer_management.hpp"

/** 
 * Constructor
 *                           
 * @param   capacity      Capacity of the cache
 */

LRUCache :: LRUCache(size_t capacity) {
    cap = capacity;
}

/** 
 * Destructor
 *                           
 */
LRUCache :: ~LRUCache() {
    for(auto p : mp) {
        delete(p.second.first);
    }
}

/**
 * This function returns the block if its present in the buffer cache, else return
 * NULL
 * 
 * @param block_id  The requested block id
 *  
 * @return char *    Returns the block if its present in the buffer else NULL
 */
char * LRUCache :: get(size_t block_id) {
    if(!mp.count(block_id)) {
        return NULL;
    }

    pair<char *, list<size_t>::iterator> cur = mp[block_id];
    ls.erase(cur.second);
    ls.push_back(block_id);
    cur.second = prev(ls.end());
    mp[block_id] = cur;

    return cur.first;
}

/**
 * This function inserts the given block into the buffer, if buffer is full we evict the 
 * lease recently used block and replace them with this
 * 
 * @param block_id  The block id to be inserted
 * @param value     The block data
 * 
 */
void LRUCache :: put(size_t block_id, char * value) {
    if(mp.count(block_id)) {
        pair<char *, list<size_t>::iterator> cur = mp[block_id];
        ls.erase(cur.second);
        ls.push_back(block_id);
        cur.second = prev(ls.end());
        cur.first = value;
        mp[block_id] = cur;
        return;
    }

    if(ls.size() < cap) {
        ls.push_back(block_id);
        mp[block_id] = pair<char *, list<size_t>::iterator>({value, prev(ls.end())});
    } else {
        int cur = ls.front();
        ls.pop_front();

        char * block = mp[cur].first;
        delete(block);

        mp.erase(cur);
        ls.push_back(block_id);
        mp[block_id] = pair<char *, list<size_t>::iterator>({value, prev(ls.end())});
    }
}