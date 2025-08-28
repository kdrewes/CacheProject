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
    
    // Implement hash table
    HashTable();
    
    // Insert CacheData properties into Fully_Associative_Vector vector
    for(int i = 0; i < this -> blockQuantity; i++)
        Set_Associative_Vector.push_back(Set_Associative_Structure(*this));
    
    std::cout << "\n---------- Address: ----------\n";
    
    for(int i = 0; i < this -> blockQuantity; i++)
        std::cout << Set_Associative_Vector[i].address << ' ' << Set_Associative_Vector[i].tag <<std::endl;
    
    std::cout << std::endl;
}

// -------------------------------------------------------------------------------------------

// Create hash table
void SetAssociated :: HashTable()
{
    this -> addressTable.resize(addressList.size() * 2);
    
    this -> indexTable.resize(addressList.size() * 2);
}

// -------------------------------------------------------------------------------------------

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
