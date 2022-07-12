#pragma once

#include "Transaction.h"
#include "../Data.h"
#include "../Hash.h"
#include "../PrivateKey.h"
#include "../proto/Aion.pb.h"

#include <cstdint>
#include <tuple>
#include <vector>

namespace SG::Aion {

/// Helper class that performs Aion transaction signing. 
class Signer {
  public: 
      Signer() = delete;  


      /// Signs a Proto::SigningInput transaction  
      static Proto::SigningOutput sign(const Proto::SigningInput& input) noexcept;  

      /// Signs the given transaction.  
      static void sign(const PrivateKey& privateKey, Transaction& transaction) noexcept;      
};  

} // namespace SG::Aion   


namespace TW::Aion 


