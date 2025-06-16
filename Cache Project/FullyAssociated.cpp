#include <time.h>
#include "Cache.h"
#include "FullyAssociated.hpp"
#include "Enums.h"
#include <vector>
#include <cstdlib>

// -------------------------------------------------------------------------------------------
// Deconstructor
FullyAssociated :: ~FullyAssociated() = default;

// Configure binary data
void FullyAssociated :: Router()
{
    // Initialize slot size
    this -> slots = this -> cacheSize / this -> blockSize;
    
    // Determine word quantity binary words used
    ConfigureWord();

    // Insert CacheData properties into cacheStorage vector
    for(int i = 0; i < this -> slots; i++)
        cacheStorage.push_back(CacheData(*this));
    
    
   //  UNIT TEST
    
    /*
    for(int i = 0; i < cacheStorage.size(); i++)
    {
        std::cout << "\nAddress = " << cacheStorage[i].address << std::endl;
        std::cout << "\nHash Code = " << cacheStorage[i].hashCode << std::endl;
        std::cout << "\nBlock = " << cacheStorage[i].blockSize << std::endl;
        std::cout << "\nOffset = " << cacheStorage[i].offset << std::endl;
        std::cout << "\nTag = " << cacheStorage[i].tag << std::endl;
        std::cout << "\nWord Size = " << cacheStorage[i].wordSize << std::endl << std::endl;
        
        for(auto & [binary,hex] : cacheStorage[i].instructionMap)
        {
            std::cout << "binary = " << binary << ", hex = " << hex << std::endl;
        }
        
        std::cout << "\n----------------------------------------------------------\n";
    }
     */
}

// -------------------------------------------------------------------------------------------
// Execute binary data
void FullyAssociated :: Controller()
{
    // Display Title
    Title();
    
    // Display Metadata
    Data();
    
    // Display Header
    Header();
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

// Create Title
void FullyAssociated :: Title()
{
    // Display Title
    console << "\n\n\n\n\t\t\t*******************************************************************************\n";
    console <<"\t\t\t\t\t\t\t\t\tFully Associative Placement Policy\n";
    console <<"\t\t\t*******************************************************************************\n";
    
    spreadsheet << "                    Fully Associative Placement Policy                    \n";
    
    consoleToFile << "\n\n\n\n\t\t\t*******************************************************************************\n";
    consoleToFile <<"\t\t\t\t\t\t\t\t\tFully Associative Placement Policy\n";
    consoleToFile <<"\t\t\t*******************************************************************************\n";

}
// -------------------------------------------------------------------------------------------
// Create Data
void FullyAssociated :: Data()
{
    
    // Display Data banner
   // console << "\n\n\t\t\t\t--------------------------------- Data ---------------------------------";
    //spreadsheet << "\n                                 Data                                 ";
    //consoleToFile << "\n\n\n\n\t\t\t\t--------------------------------- Data ---------------------------------";
    
    // Display table
   // console << "\n\n\t\t\t\tCache Size | Block Size | # of Ways | Offset Size | Word Size | # of Words\n";
   // spreadsheet << "\n\n,,,,Cache Size (Bytes),Block Size (Bytes),# of Ways,Offset Size (Bytes),Word Size,# of Words\n";
   // consoleToFile << "\n\n\t\t\tCache Size (Bytes) | Block Size (Bytes) | # of Ways | Offset Size (Bytes) | Word Size | # of Words\n";
    
    // Display data
   // console << "\t\t\t\t\t\t" << this -> cacheSize << "\t\t\t" << this -> blockSize << "\t\t\t" << this -> ways << "\t\t\t" << this -> offsetSize << "\t\t\t" << wordSize << "\t\t\t" << this -> wordQuantity << "\n\n";
    
    spreadsheet << ",,,," << this -> cacheSize << "," << this -> blockSize << "," << this -> ways << "," << this -> offsetSize << "," << wordSize << "," << this -> wordQuantity << "\n\n";
    
  //  consoleToFile << "\t\t\t\t\t\t" << this -> cacheSize << "\t\t\t" << this -> blockSize << "\t\t\t" << this -> ways << "\t\t\t" << this -> offsetSize << "\t\t\t" << wordSize << "\t\t\t" << this -> wordQuantity << "\n\n";
    
    console << "\n\t\t\tCache Size = "    << this -> cacheSize                << " Bytes\t\tBlock Size = "  << this -> blockSize    << " Bytes"
            
            << "\t\t# of Blocks = "               << this -> cacheSize / this -> blockSize   << " Bytes"
    
            << "\n\n\t\t\t# of Ways = "   << this -> ways                     << " Bytes\t\t\tOffset Size = " << this -> offsetSize  << " Bits"
    
            << "\t\tRam Size = "                  << this -> mainMemorySize       << " Bytes" << "\n\n\t\t\tWord Size  = "
     
            << this -> wordSize                   << " Bytes\t\t# of Words = "    << this -> wordQuantity
     
            << " Bytes"                       << "\t\tTag Size = "            << this -> addressSize - std::floor(log(blockSize)) << " Bytes\n";
    
    
    spreadsheet << ",,,," << this -> cacheSize << "," << this -> blockSize << "," << this -> ways << "," << this -> offsetSize << ","
    
                << wordSize << "," << this -> wordQuantity << "\n\n";
    
    consoleToFile << "\n\t\t\tCache Size = "    << this -> cacheSize                << " Bytes\t\tBlock Size = "  << this -> blockSize    << " Bytes"
            
                  << "\t\t# of Blocks = "               << this -> cacheSize / this -> blockSize   << " Bytes"
    
                  << "\n\n\t\t\t# of Ways = "   << this -> ways                     << " Bytes\t\t\tOffset Size = " << this -> offsetSize  << " Bits"
    
                  << "\t\tRam Size = "                  << this -> mainMemorySize       << " Bytes" << "\n\n\t\t\tWord Size  = "
     
                  << this -> wordSize                   << " Bytes\t\t# of Words = "    << this -> wordQuantity
     
                  << " Bytes"                       << "\t\tTag Size = "            << this -> addressSize - std::floor(log(blockSize)) << " Bytes\n";
    
    
    
    
    
        
              
}
// -------------------------------------------------------------------------------------------
// Create Header
void FullyAssociated :: Header()
{
    // Predefine header
    std::string header[] = { "Address", "Way", "Tag", "Offset", "Hit_Miss", "Word", "instruction", "Evictions"};
    
    // Display Header banner
    console << "\n\t\t\t------------------------ Fully Associated Cache Table -------------------------\n\n";
    spreadsheet << "                          Fully Associated Cache Table                          \n\n";
    consoleToFile << "\n\t\t\t------------------------ Fully Associated Cache Table -------------------------\n\n";
    
    // Display header
    for(int i = 0; i < sizeof(header) / sizeof(header[0]); i++)
        CreateHeader(FindHeader(header[i]));
    
    std::cout << console.str();
}
// -------------------------------------------------------------------------------------------
// Produce column header
void FullyAssociated :: CreateHeader(COLUMNS c)
{
    switch(c)
    {
        case ADDRESS :
            
            // Display each address
            console << "\t\tAddress | ";
            spreadsheet << "Address,";
            consoleToFile << "\tAddress | ";
            
            break;
            
        case WAY :
            
            // Display each way
            for(int i = 0; i < this -> ways; i++)
            {
                console << "Data[" << i << "] | ";
                spreadsheet << "Data[" << i << "],";
                consoleToFile << "Data[" << i << "] | ";
            }
            
            break;
            
        case TAG :
            
            // Display each tag
            console << "Tag | ";
            spreadsheet << "Tag,";
            consoleToFile << "Tag | ";
            
            break;
            
        case OFFSET :
            
            // Display each offset
            console << "Offset | ";
            spreadsheet << "Offset,";
            consoleToFile << "Offset | ";
            
            break;
            
        case HIT_MISS :
            
            // Display whether each address has a hit or miss
            console << "H/M | ";
            spreadsheet << "H/M,";
            consoleToFile << "H/M | ";
            
            break;
            
        case WORD :
            
            // Skip if there is only one word present
            if(wordVector.size() != 1)
            {
                // Display each individual word in binary format
                for(binaryVector :: size_type i = 0; i < wordVector.size(); i++)
                {
                    console << wordVector[i] << " | ";
                    spreadsheet << wordVector[i] << ",";
                    consoleToFile << wordVector[i] << " | ";
                }
            }
            
            
            break;
            
        case INSTRUCTION_RETREIVED :
            
            // Display which instruction was retreived
            console << "Instruction (Hex) | ";
            spreadsheet << "Instruction (Hex),";
            consoleToFile << "Instruction (Hex) | ";
            
            break;
            
        case EVICTIONS :
            
            // Display if there were any evictions
            console << "Address(es) Evicted\n";
            spreadsheet << "Address(es) Evicted\n";
            consoleToFile << "Address(es) Evicted\n";
            
            break;
            
        case COLUMN_ERROR :
            throw std::invalid_argument("\n\nError - incorrect column header\n\nPlease correct command\n\n");
    }
}

// -------------------------------------------------------------------------------------------
// Make each string lower case
std::string FullyAssociated :: toLower(std::string header)
{
    for(int i = 0; i < header.size(); i++)
        header[i] = std::tolower(header[i]);
    
    return header;
}

// -------------------------------------------------------------------------------------------
// Find header for each column
COLUMNS FullyAssociated :: FindHeader (std::string header)
{
    if(toLower(header) == "address")
        return COLUMNS :: ADDRESS;
    
    else if (toLower(header) == "way")
        return COLUMNS :: WAY;
    
    else if(toLower(header) == "tag")
        return COLUMNS :: TAG;
    
    else if(toLower(header) == "offset")
        return COLUMNS :: OFFSET;
    
    else if(toLower(header) == "hit_miss")
        return COLUMNS :: HIT_MISS;
    
    else if(toLower(header) == "evictions")
        return COLUMNS :: EVICTIONS;
    
    else if(toLower(header) == "word")
        return COLUMNS :: WORD;
    
    else if(toLower(header) == "instruction_retreived" || toLower(header) == "instruction")
        return COLUMNS :: INSTRUCTION_RETREIVED;
    
    return COLUMNS :: COLUMN_ERROR;
    
        
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
