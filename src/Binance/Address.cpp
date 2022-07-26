#include "Address.h"

#include <TrustWalletCore/TWHRP.h>
#include <vector>   

using namespace SG::Binance;   

const std::string Address::hrp = HRP_BINANCE;  
const std::string Address::hrpValidator = "bva";  
const std::vector<std::string> validHrps = {Address::hrp, Address::hrpValidator, "bnbp", "bvbp", "bca", "bcap"};  

bool Address::isValid(const std::string& addr) {  
      Address addrNotUsed;   
      return decode(addr, addrNotUsed);
}

bool Address::decode(const std::string& addr, Address& obj_out) { 
      for (const auto& hrp: validHrps) {
            if (Bech32Address::decode(addr, obj_out, hrp)) {   
                  return true;  
            }
      }
      return false;  
}


