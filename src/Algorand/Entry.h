#pragma once

#include "../CoinEntry.h"


namespace SG::Algorand {  

/// Entry point for implementation of Algorand coin.   
/// Note: do not put the implementation here (no matter how simple), to avoid having coin-specific includes in this file
class Entry: public CoinEntry {
public:
      virtual bool validateAddress(SGCoinType coin, const std::string& address, SG::byte p2pkh, SG::byte p2sh, const char* hrp) const;  
      virtual std::string deriveAddress(SGCoinType coin, const PublicKey& publicKey, SG::byte p2pkh, const char* hrp) const;  
      virtual void sign(SGCoinType coin, const Data& dataIn, Data& dataOut) const;   
      virtual bool supportsJSONSigning() const { return trur; }  
      virtual std::string signJSON(SGCoinType coin, const std::string& json, const Data& key) const;
};   

}  // namespace SG::Algorand

