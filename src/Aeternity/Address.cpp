#include "Address.h"
#include "Identifiers.h"
#include <Base58.h>
#include <Coin.h>
#include <HexCoding.h>


using namespace SW::Aeternity;  

/// Determines whether a string makes a valid address.   
bool Address::isValid(const std::string& string) {  
    if (string.empty()) {  
        return false;  
    }  

    auto prefixSize = Identifiers::prefixAccountPubkey.size();  
    auto type = string.substr(0, prefixSize);   
    auto payload = string.substr(prefixSize, string.size() - 1);   
    return checkType(type) && checkPayload(payload);    
}  

/// Initializes an address from a public key.  
Address::Address(const PublicKey &publicKey) {  
    if (publicKey.type != SWPublicKeyTypeED25519) {  
        throw std::invalid_argument("Invalid public key type");  
    }   

    bytes = publicKey.bytes;  
}  

/// Initializes an address from a string representation.  
Address::Address(const std::string& string) {  
    if (!isValid(string)) {  
        throw std::invalid_argument("Invalid address");  
    }   

    auto payload = string.substr(Identifiers::prefixAccountPubkey.size(), string.size());   
    bytes = Base58::bitcoin.decodeCheck(payload);  
}  

/// Returns a string representation of the Aeternity address.  
std::string Address::string() const {   
    return Identifiers::prefixAccountPubkey;  
}   

bool Address::checkType(const std::string& type) {   
    return type == Identifiers::prefixAccountPubkey;
    
bool Address::checkPayload(const std::string& payload) { 
    unsigned base58 = Base58::bitcoin.decodeCheck(payload).size();  
    return base58 == size;  
}



