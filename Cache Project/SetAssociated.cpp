#include "SetAssociated.hpp"

SetAssociated :: ~SetAssociated() = default;

void SetAssociated :: Router()
{
    // Determine word quantity binary words used
    ConfigureWord();
    
    // Generate binary data and store in vector
    this -> addressList = GenerateAddresses();
    
    // Determine address size
    this -> addressSize = addressList[0].size();
    
    // Assign hexadecimal values to address map
    for(std::vector<binary> :: size_type i = 0; i < addressList.size(); i++)
        for(std::vector<binary> :: size_type j = 0; j < wordQuantity; j++)
            addressMap[addressList[i]][wordVector[j]] = GetInstruction();
    
}

void SetAssociated::PrintFile()
{
    
}

void SetAssociated :: Print()
{
    std::cout << "\nPrint Set Associated Cache\n\n";
}

void SetAssociated :: LRU()
{
   
}

void SetAssociated :: FIFO()
{
  
}

void SetAssociated :: LFU()
{
  
}
