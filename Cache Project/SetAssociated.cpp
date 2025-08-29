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
    
    
    std::cout << "\nAddress\t\t\tTag\t\t\tIndex\tOffset\n";
        for(int i = 0; i < Set_Associative_Vector.size(); i++)
        {
            std::cout << Set_Associative_Vector[i].address << "\t\t"
            << Set_Associative_Vector[i].tag << "\t\t"
            << Set_Associative_Vector[i].setIndex << "\t\t"
            << Set_Associative_Vector[i].offset << "\n\n";
        }
      
}

// -------------------------------------------------------------------------------------------
// Execute binary data
void SetAssociated :: Controller()
{
    // Display title
    Title();
    
    // Display data
    Data();
    
    // Display header
    Header();
    
    // Produce and display table
    //Table();
}

// -------------------------------------------------------------------------------------------
// Create hash table
void SetAssociated :: HashTable()
{
    this -> addressTable.resize(addressList.size() * 2);
    
    this -> tagTable.resize(addressList.size() * 2);
}

// -------------------------------------------------------------------------------------------
// Create Title
void SetAssociated :: Title()
{
    // Display Title
    console << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t------------------------------------------------------------------------------\n";

    if(placementPolicy == CACHING_ALGORITHM :: LRU)
        console <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tSet Associative Placement Policy - LRU\n";

    else if(placementPolicy == CACHING_ALGORITHM :: LFU)
        console <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tSet Associative Placement Policy - LFU\n";

    else if(placementPolicy == CACHING_ALGORITHM :: FIFO)
        console <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tSet Associative Placement Policy - FIFO\n";



    console <<"\t\t\t\t\t\t\t\t\t\t------------------------------------------------------------------------------\n";


    if(placementPolicy == CACHING_ALGORITHM :: LRU)
        spreadsheet <<"---------------------------------------------------- Set Associative Placement Policy - LRU ----------------------------------------------------\n";

    else if(placementPolicy == CACHING_ALGORITHM :: LFU)
        spreadsheet <<"---------------------------------------------------- Set Associative Placement Policy - LFU ----------------------------------------------------\n";

    else if(placementPolicy == CACHING_ALGORITHM :: FIFO)
        spreadsheet <<"---------------------------------------------------- Set Associative Placement Policy - FIFO ----------------------------------------------------\n";


    consoleToFile << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t------------------------------------------------------------------------------\n";

    if(placementPolicy == CACHING_ALGORITHM :: LRU)
        consoleToFile <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tSet Associative Placement Policy - LRU\n";

    else if(placementPolicy == CACHING_ALGORITHM :: LFU)
        consoleToFile <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tSet Associative Placement Policy - LFU\n";

    else if(placementPolicy == CACHING_ALGORITHM :: FIFO)
        consoleToFile <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tFully Associative Placement Policy - FIFO\n";

    consoleToFile <<"\t\t\t\t\t\t\t\t\t\t------------------------------------------------------------------------------\n";
}

// -------------------------------------------------------------------------------------------
// Produce and display metrics
void SetAssociated :: Data()
{
    
    console << "\n\t\t\t\t\t\t\t\t\t\tCache Size = "          << this -> cacheSize                    << " Bytes\t\tBlock Size = "  << this -> blockSize    << " Bytes"
    
    << "\t\t# of Blocks = "                   << this -> blockQuantity                << " Bytes"
    
    << "\n\n\t\t\t\t\t\t\t\t\t\t# of Ways = "         << this -> ways                         << " Bytes\t\t\tOffset Size = " << this -> offsetSize  << " Bits"
    
    << "\t\tRam Size = "                      << this -> mainMemorySize               << " Bytes" << "\n\n\t\t\t\t\t\t\t\t\t\tWord Size  = "
    
    << this -> wordSize                       << " Bytes\t\t# of Words = "            << this -> wordQuantity
    
    << " Bytes"                               << "\t\tTag Size = "                    << this -> addressSize - std::floor(log2(blockSize)) << " Bytes\n\n"
    
    << "\t\t\t\t\t\t\t\t\t\tIndex Size = "  << this -> indexSize << "\n\n";
    
    
    
    spreadsheet << "\nCache Size," << "Block Size," << "# of Blocks," << "# of Ways," << "Offset Size,"  << "Ram Size," << "Word Size," << "# of Words," << "Tag Size\n";
    
    spreadsheet << this -> cacheSize << " Bytes" << ',' << this -> blockSize << " Bytes"  << ',' << this -> blockQuantity << " Bytes" << ',' << this -> ways << " Bytes" << ','
    
    << this -> offsetSize << " Bits" << ',' << this -> mainMemorySize << " Bytes" << ',' << this -> wordSize << " Bytes" << ',' << this -> wordQuantity << " Bytes"
    
    << ',' << this -> addressSize - std::floor(log2(blockSize)) << " Bytes" << "\n\n";
    
    
    consoleToFile << "\n\t\t\t\t\t\t\t\t\t\tCache Size = "          << this -> cacheSize                    << " Bytes\t\tBlock Size = "  << this -> blockSize    << " Bytes"
    
    << "\t\t# of Blocks = "                         << this -> blockQuantity                << " Bytes"
    
    << "\n\n\t\t\t\t\t\t\t\t\t\t# of Ways = "               << this -> ways                         << " Bytes\t\t\tOffset Size = " << this -> offsetSize  << " Bits"
    
    << "\t\tRam Size = "                            << this -> mainMemorySize               << " Bytes" << "\n\n\t\t\t\t\t\t\t\t\t\tWord Size  = "
    
    << this -> wordSize                             << " Bytes\t\t# of Words = "            << this -> wordQuantity
    
    << " Bytes"                                     << "\t\tTag Size = "                    << this -> addressSize - std::floor(log2(blockSize)) << " Bytes\n\n"
    
    << "\t\t\t\t\t\t\t\t\t\tIndex Size = "  << this -> indexSize << "\n\n";
    
}

// -------------------------------------------------------------------------------------------
// Create Header
void SetAssociated :: Header()
{
    // Predefine header
    std::string header[] = { "Address", "Index", "Way", "Tag", "Offset", "Hit_Miss", "Word", "instruction", "Evictions" };
    
    // Display Header banner
    console << "\n\t\t------------------------------------------------------------ Set Associative Cache Table ------------------------------------------------------------\n\n";

    spreadsheet << "------------------------------------------------------ Set Associative Cache Table ------------------------------------------------------\n\n";
    
    consoleToFile << "\n\t\t------------------------------------------------------------ Set Associative Cache Table ------------------------------------------------------------\n\n";
    
    // Display header
    for(int i = 0; i < sizeof(header) / sizeof(header[0]); i++)
        CreateHeader(FindHeader(header[i]));
    
}

// -------------------------------------------------------------------------------------------
// Produce column header
void SetAssociated :: CreateHeader(COLUMNS c)
{
    switch(c)
    {
        case ADDRESS :
            
            // Display each address
            if(this -> mainMemorySize == 8)
            {
                
                console << "\t\tAddress";
                
                spreadsheet << "Address,";
                
                consoleToFile << "\t\tAddress";
            }
            
            else if(this -> mainMemorySize == 16)
            {
                console << "\t\t\tAddress\t";
                
                spreadsheet << "Address,";
                
                consoleToFile << "\t\t\tAddress\t";
            }
            else
                throw std::invalid_argument("\nError - Invalid memory size\n\n");
            
            
            break;
            
            
        case INDEX :
            
            // Display each address
            if(this -> mainMemorySize == 8)
            {
                
                console << "\t\tIndex";
                
                spreadsheet << "Index,";
                
                consoleToFile << "\t\tIndex";
            }
            
            else if(this -> mainMemorySize == 16)
            {
                console << "\t\t\tIndex\t";
                
                spreadsheet << "Index,";
                
                consoleToFile << "\t\t\tIndex\t";
            }
            else
                throw std::invalid_argument("\nError - Invalid memory size\n\n");
            
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
            
            else if(this -> mainMemorySize == 16)
            {
                for(int i = 0; i < this -> ways; i++)
                {
                    console << "\t\t\tData[" << i << "] ";
                    
                    spreadsheet << "Data[" << i << "],";
                    
                    consoleToFile << "\t\t\tData[" << i << "] ";
                }
            }
            
            else
                throw std::invalid_argument("\nError - Invalid memory size\n\n");
            
            break;
            
        case TAG :
            
            // Display each tag
            if(this -> mainMemorySize == 8)
            {
                console << "\t\t Tag";
                
                spreadsheet << "Tag,";
                
                consoleToFile << "\t\t Tag";
            }
            
            else if(this -> mainMemorySize == 16)
            {
                console << "\t\t\tTag";
                
                spreadsheet << "Tag,";
                
                consoleToFile << "\t\t\tTag";
            }
            
            else
                throw std::invalid_argument("\nError - Invalid memory size\n\n");
            
            
            break;
            
        case OFFSET :
            
            // Display each offset
            if(this -> mainMemorySize == 8)
            {
                console << "\t\tOffset";
                
                spreadsheet << "Offset,";
                
                consoleToFile << "\t\tOffset";
            }
            
            else if(this -> mainMemorySize == 16)
            {
                console << "\t\t\t\tOffset";
                
                spreadsheet << "Offset,";
                
                consoleToFile << "\t\t\t\tOffset";
            }
            
            else
                throw std::invalid_argument("\nError - Invalid memory size\n\n");
            
            break;
            
        case HIT_MISS :
            
            // Display whether each address has a hit or miss
            if(this -> mainMemorySize == 8)
            {
                console << "\t\tH/M\t";
                
                spreadsheet << "H/M,";
                
                consoleToFile << "\t\tH/M\t";
            }
            
            else if(this -> mainMemorySize == 16)
            {
                console << "\t\tH/M";
                
                spreadsheet << "H/M,";
                
                consoleToFile << "\t\tH/M";
            }
            
            else
                throw std::invalid_argument("\nError - Invalid memory size\n\n");
            
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
                            console << "\t\t" << wordVector[i];
                            
                            spreadsheet << "=\""  << wordVector[i] << "\",";
                            
                            consoleToFile << "\t\t" << wordVector[i];
                        }
                    }
                    
                    else
                    {
                        for(binaryVector :: size_type i = 0; i < wordVector.size(); i++)
                        {
                            if(i == 0)
                            {
                                console << "\t" << wordVector[i] << "\t\t\t\t";
                                
                                spreadsheet << "=\""  << wordVector[i] << "\",";
                                
                                consoleToFile << "\t" << wordVector[i] << "\t\t\t\t";
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
            
            else if(this -> mainMemorySize == 16)
            {
                if(wordVector.size() != 1)
                {
                    if(this -> wordQuantity == 2)
                    {
                        // Display each individual word in binary format
                        
                        for(binaryVector :: size_type i = 0; i < wordVector.size(); i++)
                        {
                            console << "\t\t  " << wordVector[i];
                            
                            spreadsheet << "=\""  << wordVector[i] << "\",";
                            
                            consoleToFile << "\t\t  " << wordVector[i];
                        }
                    }
                    
                    else
                    {
                        for(binaryVector :: size_type i = 0; i < wordVector.size(); i++)
                        {
                            if(i == 0)
                            {
                                console << "\t\t\t\t" << wordVector[i] << "\t";
                                
                                spreadsheet << "=\""  << wordVector[i] << "\",";
                                
                                consoleToFile << "\t\t\t\t" << wordVector[i]  << "\t";
                            }
                            else
                            {
                                console << wordVector[i] << "\t\t";
                                
                                spreadsheet << "=\""  << wordVector[i] << "\",";
                                
                                consoleToFile << wordVector[i] << "\t\t";
                            }
                        }
                    }
                }
            }
            
            
            else
                throw std::invalid_argument("\nError - Invalid memory size\n\n");
            
            break;
            
        case INSTRUCTION_RETREIVED :
            
            // Display which instruction was retreived
            if(this -> mainMemorySize == 8)
            {
                if(this -> wordQuantity == 1 || this -> wordQuantity == 2)
                {
                    console << "\t\tInstruction";
                    
                    spreadsheet << "Instruction,";
                    
                    consoleToFile << "\t\tInstruction";
                }
                else
                {
                    console << "\tInstruction";
                    
                    spreadsheet << "Instruction,";
                    
                    consoleToFile << "\tInstruction";
                }
            }
            
            else if(this -> mainMemorySize == 16)
            {
                if(this -> wordQuantity == 1 || this -> wordQuantity == 2)
                {
                    console << "\t\t\tInstruction";
                    
                    spreadsheet << "Instruction,";
                    
                    consoleToFile << "\t\t\tInstruction";
                }
                else
                {
                    console << "\t\t\tInstruction";
                    
                    spreadsheet << "Instruction,";
                    
                    consoleToFile << "\t\t\tInstruction";
                }
            }
            
            else
                throw std::invalid_argument("\nError - Invalid memory size\n\n");
            
            break;
            
        case EVICTIONS :
            
            // Display if there were any evictions
            if(this -> mainMemorySize == 8)
            {
                console << "\t\t\tAddress(es) Evicted\n\n";
                
                spreadsheet << "Address(es) Evicted\n";
                
                consoleToFile << "\t\t\tAddress(es) Evicted\n\n";
            }
            
            else if(this -> mainMemorySize == 16)
            {
                console << "\t\t\tAddress(es) Evicted\n\n";
                
                spreadsheet << "Address(es) Evicted\n";
                
                consoleToFile << "\t\t\tAddress(es) Evicted\n\n";
            }
            
            else
                throw std::invalid_argument("\nError - Invalid memory size\n\n");
            
            break;
            
        case COLUMN_ERROR :
            throw std::invalid_argument("\n\nError - incorrect column header\n\nPlease correct command\n\n");
    }
}

// -------------------------------------------------------------------------------------------
// Make each string lower case
std::string SetAssociated :: toLower(std::string header)
{
    for(int i = 0; i < header.size(); i++)
        header[i] = std::tolower(header[i]);
    
    return header;
}

// -------------------------------------------------------------------------------------------
// Find header for each column
COLUMNS SetAssociated :: FindHeader (std::string header)
{
    if(toLower(header) == "address")
        return COLUMNS :: ADDRESS;
    
    else if (toLower(header) == "index")
        return COLUMNS :: INDEX;
    
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

void SetAssociated::PrintFile()
{
    

}

void SetAssociated :: Print()
{
    std::cout << console.str();
}

