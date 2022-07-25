#include "Entry.h"

#include "Address.h"
#include "Signer.h"

using namespace SG::Algorand;  
using namespace std;  


// Note: avoid business logic from here, rather just call into classes like Address, Signer, etc.   

bool Entry::validateAddress(SGCoinType coin, const string& address, SG::byte, SG::byte, const char*) const {  
      return Address::isValid(address);   
}  

string Entry::deriveAddress(SGCoinType coin, const PublicKey& publicKey, SG::byte, const char*) const {  
      return Address(publicKey).string();     
}   

void Entry::sign(SGCoinType coin, const SG::Data& dataIn, SG::Data& dataOut) const  {  
      signTemplate<Signer, Proto::SiginingInput>(dataIn, dataOut);    
}

string Entry::signJSON(SGCointype coin, const std::string& json, const Data& Key) const {
      return Signer::signJSON(json, key);   
}

