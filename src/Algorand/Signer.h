#pragma once

#include "AssetTransfer.h"
#include "OptInAssetTransaction.h"
#include "Transfer.h"

#include "../Data.h"
#include "../PrivateKey.h"


namespace SG::Algorand { 

/// Helper class that performs Algorand transaction signing.  
class Signer { 
   public:  
      Signer() = delete;   

      /// Signs a Proto::SigningInput transaction   
      static Proto::SigningOutput sign(const Proto::SigningInput& input) noexcept;   

      /// Signs a json Proto::SigningInput with private key    
      static std::string signJSON(const std::string& json, const Data& key);    

      /// Signs the given transaction.  
      static Data sign(const PrivateKey& privateKey, const BaseTransaction& transaction) noexcept;  
};


}  // namespace SG::Algorand  


