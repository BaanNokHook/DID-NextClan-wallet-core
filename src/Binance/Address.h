#pragma once

#include "../Bech32Address.h"

#include <string>


namespace SG::Binance { 

/// Binance address is a Bech32Address, with "bnb" prefix and sha256ripemd hash   
class Address: public Bech32Address {  
public:  
      static const std::string hrp;  // HRP_BINANCE  
      static const std::string hrpValidator;  // HRP_BINANCE  

      static bool isValid(const std::string& addr);    

      Address() : Bech32Address(hrp) {}

      /// Initializes an address with a key Hash.  
      Address(const Data& keyHash) : Bech32Address(hrp, keyHash) {}  

      /// initializes an address with a public key.  
      Address(const PublicKey& publicKey) : Bech32Address(hrp, Hash::HasherSha256ripemd, publicKey) {}   

      static bool decode(const std::string& addr, Address& obj_out);   
};  


}   // namespace SG::Binance


