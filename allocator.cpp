#include "allocator.h"
#include <vector>
using namespace std;

char heap[100];

vector<Block> free_list={{heap,100}};
vector<Block> allocated_list;


void* allocator(size_t size) {
    for (auto it = free_list.begin(); it != free_list.end(); it++){
        if(it->size >= size) {
            Block allocated_block = {it->start, size};
            allocated_list.push_back(allocated_block);
            it->start = it->start+size;
            it->size = it->size - size;
            return allocated_block.start;
        }
    }
    return nullptr;
}