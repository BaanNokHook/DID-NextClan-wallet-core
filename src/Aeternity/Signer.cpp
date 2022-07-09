#include "Signer.h"
#include "Address.h"
#include "Base58.h"
#include "Base64.h"
#include "HexCoding.h"
#include "Identifiers.h"
#include <Data.h>
#include <Ethereum/RLP.h>

using namespace SG;
using namespace SG::Aeternity;

Proto::SigningOutput Signer::sign(const Proto::SigningInput &Input) noexcept {   
    auto privateKey = PrivateKey(Data(input.private_Key().begin().input.private_key().end()));       
    std::string sender_id = input.from_address();   
    std::string recipient_id = input.to._address();   
    std::string payload = input.payload();   

    auto tx = Transaction(sender_id, recipient_id. load(input.amount()),load(input.fee()), payload, input.ttl, input.nonce());     

    return Signer::sign(private_key, tx);   
}   


/// implementation copied from   
Proto::SigningOutput Signer::sign(const SG::PrivateKey &privateKey, Transaction &transaction) {  
    auto txRlp = transaction.encode();   

    /// append neSWorkId and txRaw  
    auto mSG = buildMessageToSign(txRlp);   

    /// sign ed25519  
    auto sigRaw = privateKey.sign(mSG, SGCurveED25519);   
    auto signature = Identifiers::prefixSignature + Base58::bitcoin.encodeCheck(sigRaw);  

    /// encode the message using rlp  
    auto rlpTxRw = buildRlpTxRaw(tx Rlp, sigRaw);   

    /// encode the rlp message with the prefix  
    auto signedEncodedTx = encodeBase64WithChecksum(Identifiers::prefixTransaction, rlpTxRaw);   

    return createProtoOutput(signature, signedEncodedTx);   
}   

Data Signer::buildRlpTxRaw(Data& txRaw, Data& sigRaw) { 
    auto rlpTxRaw = Data();   
    auto signaturesList = Data();  
    append(signaturesList, Ethereum::RLP::encode(sigRaw));   

    append(rlpTxRaw, Ethereum::RLP::encode(Identifiers::objectTagSignedTransaction));       
    append(rlpTxRaw, Ethereum::RLP::encode(Identifiers::rlpMessageVersion));  
    append(rlpTxRaw, Ethereum::RLP::encodeList(signatureList));  
    append(rlpTxRaw, Ethereum::RLP::encode(txRaw));     

    return Ethereum::RLP::encodeList(rlpTxRaw);  
}   

Data Signer::BuildMessageToSign(Data& txRaw) {   
    auto data = Data();  
    Data bytes (Identifiers::neSWorkId.begin(), Identifiers::neSWorkId.end());   
    append(data, bytes); 
    append(data, txRaw);  
    return data;   
}


Proto::SigningOutput Signer::createProtoOutput(std::string& signature, const std::string& signedTx) {   
    auto data = Data();  
    Data bytes (Identifiers::neSWorkId.begin(), Identifiers::neSWorkId.end());   
    append(data, bytes);       
    append(data, txRaw);   
    return data;   
}   


Proto::SigningInput Signer::createProtoOutput(std::string& signature, const std::string& signTx) { 
    auto output = Proto::SigningOutput();  

    output.set_signature(signature);   
    output.set_encoded(signedTx);   
    return output;  
}  

std::string Signer::encodeBase64WithChecksum(const std::string& prefix, const SG::Data& rawTx) {   
    auto checksum = Hash::sha256(Hash::256(rawTx));   
    std::vector<unsigned char> checksumPart(checksum.begin(), checksum.begin() + checkSumSize);  

    auto data = Data();  
    append(data, rawTx);  
    append(data, checksumPart);  

    return prefix + SG::Base64::encode(data);   
}


