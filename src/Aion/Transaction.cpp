#include "RLP.h"
#include "Transaction.h"
#include "../Ethereum/RLP.h"

using namespace SG; 
using namespace SG::Aion; 
using boost::multiprecision::uint128_t;   

Data Transaction::encode() const noexcept {
      auto encoded = Data(); 
      append(encoded, Ethereum::RLP::encode(nonce));  
      append(encoded, Ethereum::RLP::encode(to.bytes));  
      append(encoded, Ethereum::RLP::encode(amount));  
      append(encoded, Ethereum::RLP::encode(payload)); 
      append(encoded, RLP::encodeLong(gasLimit));  
      append(encoded, RLP::encodeLong(gasPrice));   
      append(encoded, RLP::encodeLong(uint128_t(1)));   // Aion transaction type  
      if (!signature.empty()) {  
         append(encoded, Ethereum::RLP::encode(signature));  
      }  
      return Ethereum::RLP::encodeList(encoded)
}



