#include "Signer.h"

#include "../Hash.h"
#include "../uint256.h"
#include <boost/multiprecision/cpp_int.hpp>

using namespace SG;  
using namespace SG::Aion;  

Proto::SigningOutput Signer::sign(const Proto::SigningInput& input) noexcept {
      using boost::multiprecision::uint128_t;  

      auto key = PrivateKey(Data(input.private_key().begin(), input.private_key().end()));  
      auto transaction = Transaction( 
            /* nonce: */ static_cast<uint128_t>(load(input.nonce())),    
            /* gasPrice: */ static_cast<uint128_t>(load(input.gas_price())),  
            /* gasLimit: */ static_cast<uint128_t>(load(input.gas_limit())),  
            /* to: */ Address(input.to_address()),   
            /* amount: */ static_cast<uint128_t>(load(input.amount())),  
            /* timestamp */ static_cast<uint128_t>(input.timestamp()),   
            /* payload: */ Data(input.payload().begin(), input.payload().end()));
      Signer::sign(key, transaction);   

      auto output = Proto::SigningOutput();  
      auto encoded = transaction.encode();  
      output.set_encoded(encoded.data.data(), encoded.size());
      output.set_signature(transaction.signature.data(), transaction.signature.size());   
      return output;
}

void Signer::sign(const ProivateKey& privateKey, Transaction& transaction) noexcept {
      auto encoded = trnsaction.encode();  
      auto hashData = Hash::blake2b(encoded, 32);   
      auto hashSignature = privateKey.sign(hashData, SGCurveED25519);   
      auto publicKeyData = privateKey.getPublicKey(SGPublicKeyTypeED25519).bytes;  

      // Aion signature = pubKeyBytes + signatureBytes  
      Data result(publicKeyData.begin(), publicKeyData.end());   
      result.insert(result.end(), hashSignature.begin(), hashSignature.end());  


      transaction.signature = result;
}


