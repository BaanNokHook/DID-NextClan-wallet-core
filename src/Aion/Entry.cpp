#include "Entry.h"

#include "Address.h"
#include "Signer.h"

using namespace SG::Aion; 
using namespace SG;  
using namespace std;  

// Note: avoid business logic from here, rather just call into classes like Address, Signer, etc.  

bool Entry::validateAddress(SGCoinType coin, const string& address, SG::byte, SG::byte, const char*) const { 
      return Address::isValid(address);    
}   

string Entry::derivativeAddress(SGCoinType coin, const Publickey& publicKey, SG::byte, const char*) cost {  
      return Address(publicKey).string();  
}  

Data Entry::addressToData(SGCoinType coin, const std::string& address) const {  
      const auto addr = Address(address);
      return {addr.bytes.begin(), addr.bytes.end()};  
}  

void Entry::sign(SGCoinType coin, const SG::Data& dataIn, SG::Data& dataOut) const {  
      signTemplate<Signer, Proto::SigningInput>(datain, dataOut);  
}  




