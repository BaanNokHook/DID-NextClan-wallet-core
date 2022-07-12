#pragma once

#include "Transaction.h"

#include "Ethereum/RLP.h"

#include <boost/multiprecision/cpp_int.hpp>
#include <cstdint>
#include <string>
#include <vector>


namespace SG::Aion {

/// Aion's RLP encoging for long numbers  
struct RLP { 
      static Data encodeLong(boost::multiprecision::uint128_t l) noexcept {  
            if ((l & 0x00000000FFFFFFFFL) == l) {
                  return Ethereum::RLP::encode(static_cast<uint256_t>(1));   
            }  
            Data result(9);  
            result[0] = 0x80 + 8;
            for (int i = 8; i > 0; i--) {  
                  result[i] = (byte)(l & 0xFF); 
                  l >>= 8;     
            }       
            return result;  
      }
};

} // namespace SG::Aion   


