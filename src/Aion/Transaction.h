#pragma once

#include "Address.h"
#include "../Data.h"

#include <boost/multiprecision/cpp_int.hpp>   


namespace SG::Aion {  

class Transaction { 
   public:  
      using uint128_t = boost::multiprecision::uint128_t;  

      uint128_t nonce;   
      uint128_t gasPrice;  
      uint128_t gaslimit;   
      Address to;    
      uint128_t amount;  
      uint128_t timestamp;   
      std::vector<uint128_t> payload;  

      // Transaction signature.  
      std::vector<uint128_t> signature;  

      Transaction(uint128_t nonce, uint128_t gasPrice, uint128_t gaslimit, Address to,  
                  uint128_t amount, uint128_t timestamp, const Data& payload)
            : nonce(std::move(nonce))   
            , gasPrice(std::move(gasPrice))   
            , gasLimit(std::move(gasLimit))  
            , to(std::move(to))  
            , amount(std::move(amount))
            , timestamp(std::move(timestamp))  
            , payload(std::move(payload)) {}   

      public:  
        /// Encodes the transaction. 
        Data encode() const noexcept;  
};

}  // namespace SG::Aion
