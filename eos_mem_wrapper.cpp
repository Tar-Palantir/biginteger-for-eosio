/** 
 * BigInteger for EOS.IO smart contract by Mithrilcoin.io .
 */
#include <eosiolib/memory.hpp>

// new/delete operator overloading for eos smart contract by mithrilcoin.io
void* operator new (unsigned int size){
    return malloc( size );
}

void* operator new[] (unsigned int size){
    return malloc( size );
}

void operator delete (void* ptr){
    free( ptr);
}

void operator delete[] (void* ptr) {
    free( ptr);
}