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
    // Display title
    Title();
  
    // Display data
    Data();
    
}

// -------------------------------------------------------------------------------------------
// Create hash table
void DirectMapped :: HashTable()
{
    this -> addressTable.resize(addressList.size() * 2);
    
    this -> indexTable.resize(addressList.size() * 2);
}

// -------------------------------------------------------------------------------------------
// Create Title
void DirectMapped :: Title()
{
    // Display Title
    console << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t------------------------------------------------------------------------------\n";

    console <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tDirect Mapping Placement Policy\n";

    console <<"\t\t\t\t\t\t\t\t\t\t------------------------------------------------------------------------------\n";


    spreadsheet <<"---------------------------------------------------- Direct Mapping Placement Policy ----------------------------------------------------\n";


    consoleToFile << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t------------------------------------------------------------------------------\n";

    consoleToFile <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tDirect Mapping Placement Policy\n";

    consoleToFile <<"\t\t\t\t\t\t\t\t\t\t------------------------------------------------------------------------------\n";
}

// -------------------------------------------------------------------------------------------
// Produce and display metrics
void DirectMapped :: Data()
{
    
    console << "\n\t\t\t\t\t\t\t\t\t\tCache Size = "   << this -> cacheSize                    << " Bytes\t\tBlock Size = "  << this -> blockSize    << " Bytes"
    
    << "\t\t# of Blocks = "                            << this -> blockQuantity                << " Bytes"
    
    << "\n\n\t\t\t\t\t\t\t\t\t\tIndex Size = "         << this -> indexSize                    << " Bytes\t\tOffset Size = " << this -> offsetSize  << " Bits"
    
    << "\t\tRam Size = "                               << this -> mainMemorySize               << " Bytes" << "\n\n\t\t\t\t\t\t\t\t\t\tWord Size  = "
    
    << this -> wordSize                                << " Bytes\t\t# of Words = "            << this -> wordQuantity
    
    << " Bytes"                                        << "\t\tTag Size = "                    << this -> addressSize - this -> indexSize - std::floor(log2(blockSize)) << " Bytes\n\n";
    
    
    
    spreadsheet << "\nCache Size," << "Block Size," << "# of Blocks," << "Offset Size,"  << "Ram Size," << "Word Size," << "# of Words," << "Tag Size\n";
    
    spreadsheet << this -> cacheSize << " Bytes" << ',' << this -> blockSize << " Bytes"  << ',' << this -> blockQuantity << " Bytes" << ','
    
    << this -> offsetSize << " Bits" << ',' << this -> mainMemorySize << " Bytes" << ',' << this -> wordSize << " Bytes" << ',' << this -> wordQuantity << " Bytes"
    
    << ',' << this -> addressSize - this -> indexSize - std::floor(log2(blockSize)) << " Bytes" << "\n\n";
    
    
    consoleToFile << "\n\t\t\t\t\t\t\t\t\t\tCache Size = "   << this -> cacheSize                    << " Bytes\t\tBlock Size = "  << this -> blockSize    << " Bytes"
    
    << "\t\t# of Blocks = "                            << this -> blockQuantity                << " Bytes"
    
    << "\n\n\t\t\t\t\t\t\t\t\t\tIndex Size = "         << this -> indexSize                    << " Bytes\t\tOffset Size = " << this -> offsetSize  << " Bits"
    
    << "\t\tRam Size = "                               << this -> mainMemorySize               << " Bytes" << "\n\n\t\t\t\t\t\t\t\t\t\tWord Size  = "
    
    << this -> wordSize                                << " Bytes\t\t# of Words = "            << this -> wordQuantity
    
    << " Bytes"                                        << "\t\tTag Size = "                    << this -> addressSize - this -> indexSize - std::floor(log2(blockSize)) << " Bytes\n\n";
    
}

// -------------------------------------------------------------------------------------------

void DirectMapped :: Print()
{
    std::cout << console.str();
}
