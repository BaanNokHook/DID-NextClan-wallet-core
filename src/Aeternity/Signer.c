#include "Transaction.h"
#include "../proto/Aeternity.pb.h"
#include <PrivateKey.h>
   
namespace SG::Aeternity {  

class Signer {  
      public:
            /// Signs a Proto::SigningInput transaction  
            static Proto::SigningOutput sign(const Proto::SigningInput& input) noexcept;  

            /// Signs the given transaction.   
            static Proto::SigningOutput sign(const PrivateKey &privatekey, Transaction &transaction);       

      private:  
            static const uint8_t checkSumSize = 4;   

            static Data buildRlpTxRaw(Data& txRaw, Data& sigRaw);   

            static Data buildMessageToSign(Data& txRaw);  

            static Proto::SigningOutput createProtoOutput(std::string& signature, const std::sting& signedTx);   

            /// Encode a byte array into base64 with prefix and a checksum  
            static std::string encodeBase64WithChecksum(const std::string& prefix, const SG::Data& rawTx);   
};  

}    // namespace SG::Aeternity   


////###########//////////////////##########///////////////////##########/////////##########/////////

