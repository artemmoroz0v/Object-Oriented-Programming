#ifndef TALLOCATORBLOCK_H
#define TALLOCATORBLOCK_H

#include "TLinkedList.h"
#include <memory>

class TAllocatorBlock {
    public:
        TAllocatorBlock(const size_t& size, const size_t count){
            this->size = size;
            for(int i = 0; i < count; ++i){
                unused_blocks.Insert(malloc(size));
            }
        }
        void* Allocate(const size_t& size){
            if(size != this->size){
                std::cout << "Error during allocation\n";
            }
            if(unused_blocks.Length()){
                for(int i = 0; i < 5; ++i){
                    unused_blocks.Insert(malloc(size));
                }
            }
            void* tmp = unused_blocks.GetItem(1);
            used_blocks.Insert(unused_blocks.GetItem(1));
            unused_blocks.Remove(0);
            return tmp;
        }
        void Deallocate(void* ptr){
            unused_blocks.Insert(ptr);
        }
    ~TAllocatorBlock(){
        while(used_blocks.size()){
            try{
                free(used_blocks.GetItem(1);)
                used_blocks.Remove(0);
            } catch(...){
                used_blocks.Remove(0);
            }
        }
        while(unused_blocks.size()){
            try{
                free(unused_blocks.GetItem(1);
                unused_blocks.Remove(0);
            } catch(...){
                unused_blocks.Remove(0);
            }
        }
    }

    private:
        size_t size;
        TLinkedList <void*> used_blocks;
        TLinkedList <void*> unused_blocks;
};

#endif