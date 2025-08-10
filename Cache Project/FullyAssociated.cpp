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
    
    /*
    
   //  UNIT TEST DISPLAYING ALL ADDRESS COMPONENTS
    for(int i = 0; i < cacheStorage.size(); i++)
    {
        std::cout << "\nAddress = " << cacheStorage[i].address << std::endl;
        std::cout << "\nHash Code = " << cacheStorage[i].addressHashCode << std::endl;
        std::cout << "\nBlock = " << cacheStorage[i].blockSize << std::endl;
        std::cout << "\nOffset = " << cacheStorage[i].offset << std::endl;
        std::cout << "\nTag = " << cacheStorage[i].tag << std::endl;
        std::cout << "\nWord Size = " << cacheStorage[i].wordSize << std::endl << std::endl;
        std::cout << "\nWord Characters = " << cacheStorage[i].wordCharacters << std::endl << std::endl;
        std::cout << "\nInstruction = " << cacheStorage[i].instruction << std::endl << std::endl;
        
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
    Table();
    
    
    
    std::cout << console.str();
    
    file write("testFile.csv");
    
    write << spreadsheet.str();
    
    write.close();

    /*
     
     
     
     // Unit Test for Address List
     for(int i = 0; i < addressList.size(); i++)
         std::cout << "\nAddressList[" << i << "]: " << addressList[i] << std::endl;
     
     // Unit Test for hash code
    for(int i = 0; i < cacheStorage.size(); i++)
        std::cout << "\nAddress[" << i << "]: " << cacheStorage[i].address << ' ' << "Hash Code: " << cacheStorage[i].hashCode << '\n';
     
     // Unit Test for Address List
     for(int i = 0; i < addressList.size(); i++)
         std::cout << "\nAddressList[" << i << "]: " << addressList[i] << std::endl;
     
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
     
     // UNIT TEST FOR ADRESS TABLE
     for(hashAddress :: size_type i = 0; i < addressTable.size(); i++)
         if(!addressTable[i].first.empty() && !addressTable[i].second.empty())
         {
             std::cout << "\nINDEX = " << i << ' ' << "TAG = " << addressTable[i].first << ' ' << "ADDRESS = " << addressTable[i].second << std::endl;
         }
     */



        
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
    
    this -> tagTable.resize(addressList.size() * 2);
}

// -------------------------------------------------------------------------------------------

// Assign hash index to addressTable or tagTable
void FullyAssociated :: AssignHashIndex(HASH_TABLE table)
{
    switch(table)
    {
        case ADDRESS_TABLE:
        {
            // Retrieve hashed index and assign it to addressTable
            int hashIndex = GetHashIndex(table,cacheStorage[global_iterator].addressHashCode);
            
            // Assign data to designated hashed subscript of addressTable
            if(addressTable[hashIndex].first.empty() &&  addressTable[hashIndex].second.empty())
            {
                addressTable[hashIndex] = {cacheStorage[global_iterator].tag,cacheStorage[global_iterator].address};
                
                this -> hitOrMiss = false;
            }
            
            else
                this -> hitOrMiss = true;
            
            break;
            
        }
            
        case TAG_TABLE:
        {
            
            // Retrieve hashed index and assign it to addressTable
            this -> hashIndex = GetHashIndex(table,cacheStorage[global_iterator].tagHashCode);
            
            if(tagTable[hashIndex].first.empty() && tagTable[hashIndex].second.empty())
            {
                // Declare queue using to store binary addresses
                std::queue<binary> binaryQueue;
                
                // Insert address into binaryQueue
                binaryQueue.push(cacheStorage[global_iterator].address);
                
                // Insert tag and queue pair to tagTable
                tagTable[hashIndex] = { cacheStorage[global_iterator].tag, binaryQueue };
                
                //wayQueue = tagTable[hashIndex].second;
            }
            
            else if(tagTable[hashIndex].first == cacheStorage[global_iterator].tag)
            {
                // Declare temporary queue used for traversing
                std::queue <binary> binaryQueue(tagTable[hashIndex].second);
                
                // Declare temporary queue used for storage
                std::queue <binary> storageQueue;
                
                // Declare string that is inserted to the back of the binary queue
                binary lastString = "";
                
                // Determine if address was found in queue
                boolean addressFound = false;
                
                
                // Traverse through queue
                while(!binaryQueue.empty())
                {
                    if(binaryQueue.front() == cacheStorage[global_iterator].address)
                    {
                        lastString = binaryQueue.front();
                        
                        binaryQueue.pop();
                        
                        addressFound = true;
                    }
                    
                    else
                    {
                        storageQueue.push(binaryQueue.front());
                        
                        binaryQueue.pop();
                    }
                }
                
                if(!addressFound)
                {
                    
                    if(storageQueue.size() >= this -> ways)
                    {
                        // Collect evicted address
                        cacheStorage[global_iterator].addressEvicted = storageQueue.front();
                        
                        // remove front node from storageQueue
                        storageQueue.pop();
                    }
                    
                    else
                        cacheStorage[global_iterator].addressEvicted = "";
                 
                    storageQueue.push(cacheStorage[global_iterator].address);
                        
                    tagTable[hashIndex].second = storageQueue;
                }
                
                else
                {
                    storageQueue.push(lastString);
                    
                    tagTable[hashIndex].second = storageQueue;
                    
                    // wayQueue = tagTable[hashIndex].second;
                }
            }
            
            break;
        }
            
        case HASH_TABLE_ERROR:
        {
            throw std::invalid_argument("\n\nError - Invalid table, please re-enter option.\n");
        }
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
    console << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t------------------------------------------------------------------------------\n";
    console <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tFully Associative Placement Policy\n";
    console <<"\t\t\t\t\t\t\t\t\t\t------------------------------------------------------------------------------\n";
    
    //spreadsheet << "                                    Fully Associative Placement Policy                                  \n";
    spreadsheet << "---------------------------------------------------- Fully Associative Placement Policy ----------------------------------------------------\n\n";
    
    consoleToFile << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t------------------------------------------------------------------------------\n";
    consoleToFile <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tFully Associative Placement Policy\n";
    consoleToFile <<"\t\t\t\t\t\t\t\t\t\t------------------------------------------------------------------------------\n";

}
// -------------------------------------------------------------------------------------------
// Create Data
void FullyAssociated :: Data()
{
    
        console << "\n\t\t\t\t\t\t\t\t\t\tCache Size = "          << this -> cacheSize                    << " Bytes\t\tBlock Size = "  << this -> blockSize    << " Bytes"
        
        << "\t\t# of Blocks = "                   << this -> blockQuantity                << " Bytes"
        
        << "\n\n\t\t\t\t\t\t\t\t\t\t# of Ways = "         << this -> ways                         << " Bytes\t\t\tOffset Size = " << this -> offsetSize  << " Bits"
        
        << "\t\tRam Size = "                      << this -> mainMemorySize               << " Bytes" << "\n\n\t\t\t\t\t\t\t\t\t\tWord Size  = "
        
        << this -> wordSize                       << " Bytes\t\t# of Words = "            << this -> wordQuantity
        
        << " Bytes"                               << "\t\tTag Size = "                    << this -> addressSize - std::floor(log2(blockSize)) << " Bytes\n\n";
        
        
    
        spreadsheet << "\nCache Size," << "Block Size," << "# of Blocks," << "# of Ways," << "Offset Size,"  << "Ram Size," << "Word Size," << "# of Words," << "Tag Size\n";
    
        spreadsheet << this -> cacheSize << " Bytes" << ',' << this -> blockSize << " Bytes"  << ',' << this -> blockQuantity << " Bytes" << ',' << this -> ways << " Bytes" << ','
    
                << this -> offsetSize << " Bits" << ',' << this -> mainMemorySize << " Bytes" << ',' << this -> wordSize << " Bytes" << ',' << this -> wordQuantity << " Bytes"
    
                << ',' << this -> addressSize - std::floor(log2(blockSize)) << " Bytes" << "\n\n";
                                                                                                                                                                                
                                                
        consoleToFile << "\n\t\t\t\t\t\t\t\t\t\tCache Size = "          << this -> cacheSize                    << " Bytes\t\tBlock Size = "  << this -> blockSize    << " Bytes"
        
        << "\t\t# of Blocks = "                         << this -> blockQuantity                << " Bytes"
        
        << "\n\n\t\t\t\t\t\t\t\t\t\t# of Ways = "               << this -> ways                         << " Bytes\t\t\tOffset Size = " << this -> offsetSize  << " Bits"
        
        << "\t\tRam Size = "                            << this -> mainMemorySize               << " Bytes" << "\n\n\t\t\t\t\t\t\t\t\t\tWord Size  = "
        
        << this -> wordSize                             << " Bytes\t\t# of Words = "            << this -> wordQuantity
        
        << " Bytes"                                     << "\t\tTag Size = "                    << this -> addressSize - std::floor(log2(blockSize)) << " Bytes\n\n";
  
}
// -------------------------------------------------------------------------------------------
// Create Header
void FullyAssociated :: Header()
{
    // Predefine header
    std::string header[] = { "Address", "Way", "Tag", "Offset", "Hit_Miss", "Word", "instruction", "Evictions" };
    
    // Display Header banner
    console << "\n\t\t------------------------------------------------------------ Fully Associative Cache Table ------------------------------------------------------------\n\n";
    //spreadsheet << "                                        Fully Associative Cache Table                                       \n\n";
    spreadsheet << "------------------------------------------------------ Fully Associative Cache Table ------------------------------------------------------\n\n";
    
    
    consoleToFile << "\n\t\t------------------------------------------------------------ Fully Associative Cache Table ------------------------------------------------------------\n\n";
    
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
            
            if(this -> mainMemorySize == 8)
            {
                
                console << "\t\tAddress";
                
                spreadsheet << "Address,";
                
                consoleToFile << "\tAddress";
            }
            
            break;
            
        case WAY :
            
            // Display each way
            
            
            if(this -> mainMemorySize == 8)
            {
                for(int i = 0; i < this -> ways; i++)
                {
                    console << "\t\tData[" << i << "]  ";
                    
                    spreadsheet << "Data[" << i << "],";
                    
                    consoleToFile << "\t\tData[" << i << "]  ";
                }
            }
            
            break;
            
        case TAG :
            
            // Display each tag
            
            if(this -> mainMemorySize == 8)
            {
                console << "\t\t Tag";
                
                spreadsheet << "Tag,";
                
                consoleToFile << "\t\t Tag";
            }
            
            break;
            
        case OFFSET :
            
            // Display each offset
            
            if(this -> mainMemorySize == 8)
            {
                console << "\t\tOffset";
                
                spreadsheet << "Offset,";
                
                consoleToFile << "\t\tOffset";
            }
            
            break;
            
        case HIT_MISS :
            
            // Display whether each address has a hit or miss
            
            if(this -> mainMemorySize == 8)
            {
                console << "\t\tH/M\t";
                
                spreadsheet << "H/M,";
                
                consoleToFile << "\t\tH/M\t";
            }
            
            break;
            
        case WORD :
            
            // Skip if there is only one word present
            
            if(this -> mainMemorySize == 8)
            {
                if(wordVector.size() != 1)
                {
                    if(this -> wordQuantity == 2)
                    {
                        // Display each individual word in binary format
                        
                        for(binaryVector :: size_type i = 0; i < wordVector.size(); i++)
                        {
                            console << "\t\t" << wordVector[i] << "  ";
                            
                            spreadsheet << "=\""  << wordVector[i] << "\",";
                            
                            consoleToFile << "\t\t" << wordVector[i] << "  ";
                        }
                    }
                    
                    else
                    {
                        for(binaryVector :: size_type i = 0; i < wordVector.size(); i++)
                        {
                            if(i == 0)
                            {
                                console << "\t\t" << wordVector[i] << "\t\t";
                                
                                spreadsheet << "=\""  << wordVector[i] << "\",";
                                
                                consoleToFile << "\t\t" << wordVector[i] << "\t\t";
                            }
                            else
                            {
                                console << wordVector[i] << "\t\t ";
                                
                                spreadsheet << "=\""  << wordVector[i] << "\",";
                                
                                consoleToFile << wordVector[i] << "\t\t ";
                            }
                        }
                    }
                }
            }
            
            break;
            
        case INSTRUCTION_RETREIVED :
            
            // Display which instruction was retreived
            
            if(this -> mainMemorySize == 8)
            {
                if(this -> wordQuantity == 1 || this -> wordQuantity == 2)
                {
                    console << "\t\t   Instruction";
                    
                    spreadsheet << "Instruction,";
                    
                    consoleToFile << "\t\t   Instruction";
                }
                else
                {
                    console << "\t\tInstruction";
                    
                    spreadsheet << "Instruction,";
                    
                    consoleToFile << "\t\tInstruction";
                }
            }
            
            break;
            
        case EVICTIONS :
            
            // Display if there were any evictions
            
            if(this -> mainMemorySize == 8)
            {
                console << "\t\t\tAddress(es) Evicted\n\n";
                
                spreadsheet << "Address(es) Evicted\n";
                
                consoleToFile << "\t\t\tAddress(es) Evicted\n\n";
            }
            break;
            
        case COLUMN_ERROR :
            throw std::invalid_argument("\n\nError - incorrect column header\n\nPlease correct command\n\n");
    }
}

// -------------------------------------------------------------------------------------------
// Display table
void FullyAssociated :: Table()
{
    // Predefine table
    std::string table[] = { "Address", "Way", "Tag", "Offset", "Hit_Miss", "Word", "instruction", "Evictions" };
    
    // Traverse through each category for each individual subscript of cacheStorage
    for(this -> global_iterator = 0; this -> global_iterator < cacheStorage.size(); this -> global_iterator++)
        for(int j = 0; j < sizeof(table) / sizeof(table[0]); j++)
            CreateTable(FindColumn(table[j]));
}

// -------------------------------------------------------------------------------------------
// Produce rows and columns in table
void FullyAssociated :: CreateTable(COLUMNS columns)
{
        switch(columns)
        {
            case ADDRESS :
            {
                // Assign each address to its designated hash index
                AssignHashIndex(FindTable("Address"));
                
                // Insert address data to each ostringstream variable
                console << "\t\t" << cacheStorage[global_iterator].address << " | ";
                
                spreadsheet << "=\""  << cacheStorage[global_iterator].address << "\",";
                
                consoleToFile << "\t\t" << cacheStorage[global_iterator].address << " | ";
                
                break;
            }
                
            case WAY :
                
                // Assign each tag queue and address to its designated hash index
                AssignHashIndex(FindTable("Tag Table"));
                
                // Declare queue to hold data for each way
                wayQueue = tagTable[hashIndex].second;

                // Display data stored in each individual way (LRU)
                for(int i = 0; i < this -> ways; i++)
                {
                    if(!tagTable[hashIndex].second.empty())
                    {
                        console << "\t" << tagTable[hashIndex].second.front() << "\t|";
                        
                        spreadsheet << "=\""  << tagTable[hashIndex].second.front() << "\",";
                        
                        consoleToFile << "\t" << tagTable[hashIndex].second.front() << "\t|";
                        
                        tagTable[hashIndex].second.pop();
                    }
                    
                    else
                    {
                        console << "\t\t" << '-' << "\t\t|";
                        
                        spreadsheet << "=\""  << '-' << "\",";
                        
                        consoleToFile << "\t\t" << '-'  << "\t\t|";
                    }
                }
                
                tagTable[hashIndex].second = wayQueue;
                 
                break;
                
            case TAG :
            {
                console << "\t" << this -> cacheStorage[global_iterator].tag << "\t|";
                
                spreadsheet << "=\""   << this -> cacheStorage[global_iterator].tag << "\",";
                
                consoleToFile << "\t" << this -> cacheStorage[global_iterator].tag << "\t|";
            }

                break;
                
            case OFFSET :
            {
                
                console << "\t  " << this -> cacheStorage[global_iterator].offset << " \t| ";
                
                spreadsheet << "=\""  << this -> cacheStorage[global_iterator].offset << "\",";
                
                consoleToFile << "\t  " << this -> cacheStorage[global_iterator].offset << " \t| ";
            }
                
                break;
                
            case HIT_MISS :
            {
                if(hitOrMiss)
                {
                    console << "\tHit \t| ";
                    
                    spreadsheet << "=\""  << "Hit" << "\",";
                    
                    consoleToFile << "\tHit\t| ";
                    
                    hitOrMiss = false;
                }
                
                else
                {
                    console << "\tMiss\t| ";
                    
                    spreadsheet << "=\""  << "Miss" << "\",";
                    
                    consoleToFile << "\tMiss\t| ";
                    
                }
            }
                
                break;
                
            case WORD :
            {
                if(wordVector.size() != 1)
                {
                    // Display each individual instruction in hexadecimal format
                    
                    for(binaryVector :: size_type i = 0; i < wordVector.size(); i++)
                    {
                        console << cacheStorage[global_iterator].instructionMap[wordVector[i]] << " | ";
                        
                        spreadsheet << "=\"" << cacheStorage[global_iterator].instructionMap[wordVector[i]] << "\",";
                        
                        consoleToFile << cacheStorage[global_iterator].instructionMap[wordVector[i]] << " | ";
                    }
                }
            }
                
                break;
                
            case INSTRUCTION_RETREIVED :
            {
                console << "      " << this -> cacheStorage[global_iterator].instruction << "\t\t|";
                
                spreadsheet << "=\""  << this -> cacheStorage[global_iterator].instruction << "\",";
                
                consoleToFile << "      " << this -> cacheStorage[global_iterator].instruction << "\t\t|";
            }

                break;
                
            case EVICTIONS :
                
                if(!this -> cacheStorage[global_iterator].addressEvicted.empty())
                {
                    console  << '\t' << '\t' << this -> cacheStorage[global_iterator].addressEvicted << '\n';
                    
                    spreadsheet << this -> cacheStorage[global_iterator].addressEvicted << ',';
                    
                    consoleToFile  << '\t' << '\t' << this -> cacheStorage[global_iterator].addressEvicted << '\n';
                    
                }
                
                else
                {
                    console << '\t' << '\t' << '\t' << '\t' << '-' << '\n';
                    
                    spreadsheet << '-' << '\n';
                    
                    consoleToFile << '\t' << '\t' << '\t' << '\t' << '-' << '\n';
                }
                

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

// Find addressTable or tagTag hashing formula
HASH_TABLE FullyAssociated :: FindTable (std::string table)
{
   if(toLower(table) == "address" || toLower(table) == "address table")
      return HASH_TABLE :: ADDRESS_TABLE;
    
    else if(toLower(table) == "tag" || toLower(table) == "tag table")
       return HASH_TABLE :: TAG_TABLE;
    
    return HASH_TABLE :: HASH_TABLE_ERROR;
}

// -------------------------------------------------------------------------------------------

// Retreive hash index
FullyAssociated :: index FullyAssociated :: GetHashIndex(HASH_TABLE table, hashValue hashCode)
{
    switch(table)
    {
        case ADDRESS_TABLE:
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
            
            break;
        }
            
        case TAG_TABLE:
        {
            // Declare hash code
            hashCode %= this -> tagTable.size();
            
            // Create copy of hashCode
            hashValue hashCopy = hashCode;
            
            // Iterator used to resolve any potential collisions
            index iterator = 0;
            
            while(true)
            {
                // Determine if subscript of tagTable[hashCode] is empty
                if(( this -> tagTable[hashCode].first.empty() && this -> tagTable[hashCode].second.empty() ) ||
                     tagTable[hashCode].first == cacheStorage[global_iterator].tag)
                    return hashCode;
                
        
                else
                {
                    // Assign value of modified hash code
                    hashCode = (hashCopy + static_cast<index>(pow(iterator,2))) % this -> tagTable.size();
                    
                    // Increment iterator
                    iterator += 1;
                }
                
            }
            
            
            break;
        }
            
        case HASH_TABLE_ERROR:
        {
            throw std::invalid_argument("\n\nError - Invalid table, please re-enter option.\n");
        }
            
            
    }
    
    return hashCode;
}
