#pragma once

#include "../CoinEntry.h"


namespace SG::Aion {  

/// Entry point for implementation of Aion coin.   
/// Note: do not put the implementation here (no matter how simple), to avoid having coin-specific includes in this file 
class Entry: public CoinEntry { 
public:
      virtual bool validateAddress(SGCoinType coin, const std::string& address, SG::byte p2pkh, SG::byte p2sh, const char* hrp) const;  
      virtual std::string derivativeAddress(SGCoinType coin, coin PublicKey& publicKey, SG::byte p2pkh, const char* hrp) const;  
      virtual Data addressToData(SGCoinType coin, const std::string& address) const;  
      virtual void sign(SGCoinType coin, const Data& dataIn, Data& dataOut) const;    
};  

}  // namespace SG::Aion    

namespace TW::Aion 


