#ifndef FullyAssociated_hpp
#define FullyAssociated_hpp

#include <stdio.h>
#include <time.h>
#include <queue>
#include "Cache.h"
#include "Enums.h"

class FullyAssociated : public Cache
{
    
    // -------------- Typedef used for organizational purposes -------------
    
    // unit = unit of measurements
    // input = variables uesd to select data
    // iterator = traverses through data set
    // index = represents the index of a data set
    // hashValue = used as hash value for hash table algorithm
    typedef int unit, input, iterator, index, hashValue;
    
    // binary = binary data stored in each cache block
    // hex = hex data stored in each cache block
    // menu = consist of entire menu
    typedef std::string binary, hex, menu;
    
    // inputSet = Stores input values, binaryVector = Stores binary values
    typedef std::vector<std::string> inputSet, binaryVector;
    
    // Key = Address, Value = Hash Value
    typedef std::vector <std::pair<binary, binary>> hashAddress;
    
    // Write file
    typedef std::ofstream file;
    
    // Key = binary word, hexidecimal instruction
    typedef std::map<binary,hex> wordMap;
    
    // binaryHexMap = Represents a map inside a map
    typedef std::map<binary, std::map<binary,hex>> multiMap;
    
    // Condenses string into a single variable
    typedef std::ostringstream condensedString;
    
private:

    // Stores each column per row
    struct CacheData
    {
        // Constructor
        CacheData(FullyAssociated & f) :
        blockSize (f.blockSize), wordSize(f.wordSize),
        address (f.addressList[std::rand() % f.addressList.size()]),
        tag (address.substr(0, address.size() - std::floor(log2(f.blockSize)))),
        offset (address.substr(address.size() - std::floor(log2(f.blockSize)), address.size())),
        instructionMap (getInstructions(address,f.addressMap)), addressHashCode(GenerateHashCode(this -> address))
        {}
        
        // ----------------------------------------------------------------
        // Ensure the same address contains identical instructions
        std::map <binary,hex> getInstructions (binary addr, multiMap addressMap)
        {
            std::map <binary,hex> instructions;
            
            if(addressMap.find(addr) != addressMap.end())
            {
                std::map <binary,hex> tempMap = addressMap[address];
                
                for(auto & t : tempMap)
                    instructions[t.first] = t.second;
            }
   
            return instructions;
        }
        
        // ----------------------------------------------------------------
        // Generate hash code for each address
        hashValue GenerateHashCode(binary binaryValue)
        {
            hashValue hashCode = 0;
            
            for(iterator i = 0; i < binaryValue.size(); i++)
            {
                if(binaryValue[i] ==  '1')
                    hashCode += pow(2,binaryValue.size() - i - 1);
            }
            
            return hashCode;
        }
        
        // ------------------------- Binary Data --------------------------
        
         binary address,          // Binary address
        
                tag,              // Tag in binary form
        
                offset;           // Offset in binary form
        
      hashValue tagHashCode,      // hash code of each tag
        
                addressHashCode;  // hash code of each address
        
           unit blockSize,        // Size of each block (Bytes)
        
                wordSize;         // Word count = (block size / word size)
        
        wordMap instructionMap;   // Key = binary value of word, value = Hex value of each instruction
                
    };

    // -------------------------- Binary datasets ---------------------------
    
    // Stores all properties located in CacheData structure
    std::vector <CacheData> cacheStorage;
    
    // Store address in hash table
    hashAddress addressTable;
    
    

public:
    
    FullyAssociated(PLACEMENT_POLICY policy) : Cache(policy)
    {
        Router();
        
        Controller();
    }
    
    ~FullyAssociated() override;
    
    // ------------------- Router & Controller functions  --------------------
    
     void Router();                     // Configure binary data
    
     void Controller();                 // Execute binary data
    
    // ----------------------- Hash Table Algorithms -------------------------
    
     void HashTable();                  // Performs implementation on hash table
    
     void AssignHashIndex();            // Assign addresses to their designated index
    
     index GetHashIndex                 // Retreive hash index
     (hashValue hashCode);
    
    // ------------------- Cache Replacements Algorithms  --------------------
    
     void LRU();                        // Last Recently Used
    
     void FIFO();                       // First in First Out
    
     void LFU();                        // Least Frequently Used
    
    // ---------------------------- Print Results  -----------------------------
    
     void Print() override;             // Print report
    
     void PrintFile();                  // Output results in file
    
     void PrintConsole();               // Output results in console
    
    // --------------------------- Misc Functions  -----------------------------

     void Title();                       // Display Title
   
     void Data();                        // Display data
    
     void Header();                      // Display header
    
     void CreateHeader                   // Produce column header
     (COLUMNS c);
    
     void Chart();                       // Display chart
    
     void CreateChart                    // Produce rows and columns in chart
     (COLUMNS c);
    
     std::string toLower                 // Make each string lower case
     (std::string header);
    
     COLUMNS FindHeader                  // Find header for each column
     (std::string header);
    
     COLUMNS FindColumn                  // Find column for each row
     (std::string column);
    
};

#endif 
