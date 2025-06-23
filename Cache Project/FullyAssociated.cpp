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

    // Insert CacheData properties into cacheStorage vector
    for(int i = 0; i < this -> blockQuantity; i++)
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
    // Display title
    Title();
    
    // Display data
    Data();
    
    // Display header
    Header();
    
    // Produce and display table
    Chart();
  


    /*
     // Unit Test for hash code
    for(int i = 0; i < cacheStorage.size(); i++)
        std::cout << "\nAddress[" << i << "]: " << cacheStorage[i].address << ' ' << "Hash Code: " << cacheStorage[i].hashCode << '\n';
     
     
     // Unit Test for hash code
    for(int i = 0; i < cacheStorage.size(); i++)
        std::cout << "\nAddress[" << i << "]: " << cacheStorage[i].address << ' ' << "Hash Code: " << cacheStorage[i].addressHashCode << '\n';
    
     
    // Unit Test for Address List
    for(int i = 0; i < addressList.size(); i++)
        std::cout << "\nAddressList[" << i << "]: " << addressList[i] << std::endl;
    
    std::cout << std::endl;
    
     // Unit Test for hash code
    for(int i = 0; i < cacheStorage.size(); i++)
        std::cout << "\nAddress[" << i << "]: " << cacheStorage[i].address << ' ' << "Hash Code: " << cacheStorage[i].hashCode << '\n';
    
   // std::cout << console.str() << std::endl;
    
    
    // UNIT TEST FOR ADRESS LIST
    //for(int i = 0; i < addressList.size(); i++)
        //std::cout << "\naddressList[" << i << "] = " << addressList[i];
    
 std:::cout << std::endl;
    
    int occupiedSubscripts = 0;
    
    for(hashAddress :: size_type i = 0; i < addressTable.size(); i++)
        if(!addressTable[i].first.empty() && !addressTable[i].second.empty())
            occupiedSubscripts += 1;
    
    std::cout << "\noccupiedSubscripts = " << occupiedSubscripts << std::endl;
     */

    // UNIT TEST FOR ADRESS TABLE
    for(hashAddress :: size_type i = 0; i < addressTable.size(); i++)
        if(!addressTable[i].first.empty() && !addressTable[i].second.empty())
        {
            std::cout << "\nINDEX = " << i << ' ' << "TAG = " << addressTable[i].first << ' ' << "ADDRESS = " << addressTable[i].second << std::endl;
        }

        
    /*
    
    UNIT TEST
     
    std::cout << console.str();
    
    file write("testFile.csv");
    
    write << spreadsheet.str();
    
    write.close();
    
    */
    
}

// -------------------------------------------------------------------------------------------

// Create hash table
void FullyAssociated :: HashTable()
{
    this -> addressTable.resize(addressList.size() * 2);
}

// -------------------------------------------------------------------------------------------

// Assign hash index to addressTable or tagTable
void FullyAssociated :: AssignHashIndex()
{
    // Retrieve hashed index and assign it to addressTable
    int hashIndex = GetHashIndex(cacheStorage[global_iterator].addressHashCode);

    // Assign data to designated hashed subscript of addressTable
    if(addressTable[hashIndex].first.empty() &&  addressTable[hashIndex].second.empty())
    {
        addressTable[hashIndex] = {cacheStorage[global_iterator].tag,cacheStorage[global_iterator].address};
        
        std::cout << "\nAddress, " << addressTable[hashIndex].second << ", assigned on index " << hashIndex << " - iterator " << global_iterator << "\n\n";
        
        this -> hitOrMiss = false;
    }
    
    else
    {
        std::cout << "\nAddress, " << addressTable[hashIndex].second << ", already found on index " << hashIndex << " - iterator " << global_iterator << "\n\n";
        
        this -> hitOrMiss = true;
    }
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
    console << "\n\n\n\n\n\n\n\n\t\t\t*******************************************************************************\n";
    console <<"\t\t\t\t\t\t\t\t\tFully Associative Placement Policy\n";
    console <<"\t\t\t*******************************************************************************\n";
    
    spreadsheet << "                    Fully Associative Placement Policy                    \n";
    
    consoleToFile << "\n\n\n\n\n\n\n\n\t\t\t*******************************************************************************\n";
    consoleToFile <<"\t\t\t\t\t\t\t\t\tFully Associative Placement Policy\n";
    consoleToFile <<"\t\t\t*******************************************************************************\n";

}
// -------------------------------------------------------------------------------------------
// Create Data
void FullyAssociated :: Data()
{
    
          console << "\n\t\t\tCache Size = "    << this -> cacheSize                    << " Bytes\t\tBlock Size = "  << this -> blockSize    << " Bytes"
            
                  << "\t\t# of Blocks = "       << this -> blockQuantity                << " Bytes"
    
                  << "\n\n\t\t\t# of Ways = "   << this -> ways                         << " Bytes\t\t\tOffset Size = " << this -> offsetSize  << " Bits"
    
                  << "\t\tRam Size = "          << this -> mainMemorySize               << " Bytes" << "\n\n\t\t\tWord Size  = "
     
                  << this -> wordSize           << " Bytes\t\t# of Words = "            << this -> wordQuantity
     
                  << " Bytes"                   << "\t\tTag Size = "                    << this -> addressSize - std::floor(log2(blockSize)) << " Bytes\n";
    
    spreadsheet << this -> cacheSize << "," << this -> blockSize << "," << this -> ways << "," << this -> offsetSize << ","
    
                << wordSize << "," << this -> wordQuantity << "\n\n";
    
    consoleToFile << "\n\t\t\tCache Size = "    << this -> cacheSize                    << " Bytes\t\tBlock Size = "  << this -> blockSize    << " Bytes"
            
                  << "\t\t# of Blocks = "       << this -> blockQuantity                << " Bytes"
    
                  << "\n\n\t\t\t# of Ways = "   << this -> ways                         << " Bytes\t\t\tOffset Size = " << this -> offsetSize  << " Bits"
    
                  << "\t\tRam Size = "          << this -> mainMemorySize               << " Bytes" << "\n\n\t\t\tWord Size  = "
     
                  << this -> wordSize           << " Bytes\t\t# of Words = "            << this -> wordQuantity
     
                  << " Bytes"                   << "\t\tTag Size = "                    << this -> addressSize - std::floor(log2(blockSize)) << " Bytes\n";
}
// -------------------------------------------------------------------------------------------
// Create Header
void FullyAssociated :: Header()
{
    // Predefine header
    std::string header[] = { "Address", "Way", "Tag", "Offset", "Hit_Miss", "Word", "instruction", "Evictions" };
    
    // Display Header banner
    console << "\n\t\t\t------------------------ Fully Associated Cache Table -------------------------\n\n";
    spreadsheet << "                          Fully Associated Cache Table                          \n\n";
    consoleToFile << "\n\t\t\t------------------------ Fully Associated Cache Table -------------------------\n\n";
    
    // Display header
    for(int i = 0; i < sizeof(header) / sizeof(header[0]); i++)
        CreateHeader(FindHeader(header[i]));

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
            console << "Address(es) Evicted\n\n";
            spreadsheet << "Address(es) Evicted\n";
            consoleToFile << "Address(es) Evicted\n\n";
            
            break;
            
        case COLUMN_ERROR :
            throw std::invalid_argument("\n\nError - incorrect column header\n\nPlease correct command\n\n");
    }
}

// -------------------------------------------------------------------------------------------
// Display table
void FullyAssociated :: Chart()
{
    // Predefine table
    std::string chart[] = { "Address", "Way", "Tag", "Offset", "Hit_Miss", "Word", "instruction", "Evictions" };
    
    for(this -> global_iterator = 0; this -> global_iterator < cacheStorage.size(); this -> global_iterator++)
        for(int j = 0; j < sizeof(chart) / sizeof(chart[0]); j++)
            CreateChart(FindColumn(chart[j]));
}

// -------------------------------------------------------------------------------------------
// Produce rows and columns in table
void FullyAssociated :: CreateChart(COLUMNS c)
{
        switch(c)
        {
            case ADDRESS :
            {
                // Add address data to each ostringstream variable
                console << "\t\t" << cacheStorage[global_iterator].address << " | ";
                
                spreadsheet << cacheStorage[global_iterator].address << ',';
                
                consoleToFile << "\t\t" << cacheStorage[global_iterator].address << " | ";
                
                // Assign each tag and address to its designated hash index
                AssignHashIndex();
                
                break;
            }
                
            case WAY :
                
                /*
                if(tagQueueMap.find(cacheStorage[global_iterator].tag) != tagQueueMap.end())
                {
                    
                }
                else
                    tagQeueMap[cacheStorage[global_iterator].tag].push();
                 */
                
                break;
                
            case TAG :

                break;
                
            case OFFSET :
                
                break;
                
            case HIT_MISS :
                
                break;
                
            case WORD :
                
                break;
                
            case INSTRUCTION_RETREIVED :

                break;
                
            case EVICTIONS :

                break;
                
            case COLUMN_ERROR :
                
                std::cout << "\nCOLUMN_ERROR - iterator = " << this -> global_iterator;
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
// Find column for each row
COLUMNS FullyAssociated :: FindColumn (std::string column)
{
    if(toLower(column) == "address")
        return COLUMNS :: ADDRESS;
    
    else if (toLower(column) == "way")
        return COLUMNS :: WAY;
    
    else if(toLower(column) == "tag")
        return COLUMNS :: TAG;
    
    else if(toLower(column) == "offset")
        return COLUMNS :: OFFSET;
    
    else if(toLower(column) == "hit_miss")
        return COLUMNS :: HIT_MISS;
    
    else if(toLower(column) == "evictions")
        return COLUMNS :: EVICTIONS;
    
    else if(toLower(column) == "word")
        return COLUMNS :: WORD;
    
    else if(toLower(column) == "instruction_retreived" || toLower(column) == "instruction")
        return COLUMNS :: INSTRUCTION_RETREIVED;
    
    return COLUMNS :: COLUMN_ERROR;
}

// -------------------------------------------------------------------------------------------

// Retreive hash index
FullyAssociated :: index FullyAssociated :: GetHashIndex(hashValue hashCode)
{
    // Declare hash code
    hashCode %= this -> addressTable.size();
    
    // Create copy of hashCode
    hashValue hashCopy = hashCode;
    
    // Iterator used to resolve any potential collisions
    index iterator = 0;
   
    while(true)
    {
        // Determine if subscript of addressTable[hashCode] is empty
        if(this -> addressTable[hashCode].first.empty() && this -> addressTable[hashCode].second.empty())
            return hashCode;
        
        // Implement quadratic probing formula
        else
        {
            // Determine if address is currently stored in hash table
            if( (addressTable[hashCode].first == cacheStorage[global_iterator].tag) &&
                (addressTable[hashCode].second == cacheStorage[global_iterator].address) )
                return hashCode;
            
            // Assign value of modified hash code
            hashCode = (hashCopy + static_cast<index>(pow(iterator,2))) % this -> addressTable.size();
            
            // Increment iterator
            iterator += 1;
        
        }
    }

}
