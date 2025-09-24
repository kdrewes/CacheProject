#include "DirectMapped.hpp"

DirectMapped :: ~DirectMapped() = default;

void DirectMapped :: Router()
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
        Direct_Mapping_Vector.push_back(Direct_Mapping_Structure(*this));
    
    std::cout << "\nAddress\t\t\tTag\t\t\tIndex\tOffset\n";
    
    for(int i = 0; i < Direct_Mapping_Vector.size(); i++)
    {
        std::cout << Direct_Mapping_Vector[i].address << "\t\t"
        << Direct_Mapping_Vector[i].tag << "\t\t"
        << Direct_Mapping_Vector[i].setIndex << "\t\t"
        << Direct_Mapping_Vector[i].offset << "\n\n";
    }
    
}

void DirectMapped :: Controller()
{
    
}

// -------------------------------------------------------------------------------------------
// Create hash table
void DirectMapped :: HashTable()
{
    this -> addressTable.resize(addressList.size() * 2);
    
    this -> indexTable.resize(addressList.size() * 2);
}


void DirectMapped :: Print()
{
    std::cout << "\nPrint Console for Direct Mapped\n\n";
}
