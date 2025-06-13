#include <time.h>
#include "Cache.h"
#include "FullyAssociated.hpp"
#include "Enums.h"
#include <vector>

// -------------------------------------------------------------------------------------------

FullyAssociated :: ~FullyAssociated() = default;

// Configure binary data
void FullyAssociated :: Router()
{
    
    // Determine word quantity binary words used
    ConfigureWord();

    // Insert CacheData properties into cacheStorage vector
    for(int i = 0; i < this -> slots; i++)
        cacheStorage.push_back(CacheData(*this));
}

// -------------------------------------------------------------------------------------------

// Execute binary data
void FullyAssociated :: Controller()
{
    HashTable();
}

// -------------------------------------------------------------------------------------------

void FullyAssociated :: HashTable()
{
    this -> addressTable.resize(addressList.size() * 2);
    
    /*
    for(std::vector<CacheData> :: size_type i = 0; i < cacheStorage.size(); i++)
        addressTable[AssignHashIndex(cacheStorage[i])]
     */
        
}

// -------------------------------------------------------------------------------------------
void FullyAssociated :: Print()
{
    std::cout << "\nPrint Fully Associated Cache\n\n";
}

// -------------------------------------------------------------------------------------------

void FullyAssociated::PrintFile()
{
    
}


// -------------------------------------------------------------------------------------------

void FullyAssociated :: LRU()
{
   
}

// -------------------------------------------------------------------------------------------

void FullyAssociated :: FIFO()
{
  
}

// -------------------------------------------------------------------------------------------

void FullyAssociated :: LFU()
{
  
}

// -------------------------------------------------------------------------------------------
FullyAssociated :: index FullyAssociated :: AssignHashIndex(hashValue hashCode)
{
    // Declare hash code
    hashCode %= this -> addressTable.size();
    
    // Iterator used to resolve any potential collisions
    index iterator = 0;
    
    // Determine if probing is forward or backward
    bool isForward = true;
   
    while(true)
    {
        if(this -> addressTable[hashCode].empty())
            return hashCode;
        
        else
        {
            if(isForward)
            {
                hashCode = static_cast<int>(pow(++iterator,2)) % this -> addressTable.size();
                
                isForward = false;
            }
            
            else
            {
                index negativeIndex = -1 * static_cast<int>(pow(iterator,2));
                
                hashCode -= negativeIndex;
                
                if(hashCode < 0)
                    hashCode *= -1;
                
                hashCode %= this -> addressTable.size();
                
                isForward = false;
            }
        }
    }
   
}
