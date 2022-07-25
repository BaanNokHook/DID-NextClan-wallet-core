#pragma once

#include "BinaryCoding.h"
#include "Data.h"

namespace SG::Algorand { 

class BaseTransaction { 
    public:  
        virtual Data serialize() const = 0;
        virtual Data serialize(const Data& signature) const { 
            /* Algorand transaction and signature are encoded with msgpack:  
            {  
                "sig": <signature bytes>  
                "txn": <encoded transaction object>,   
            }
            */  
           Data data;
           // encode map length 
           data.push_back(0x80 + 2);    
           // signature
           encodeString("sig", data);  
           encodeBytes(signature, data);  

           // transaction 
           encodeString("txn", data);  
           append(data, serialize());   
           return data;   
        }
    };  

}   // namespace SG::Algorand



