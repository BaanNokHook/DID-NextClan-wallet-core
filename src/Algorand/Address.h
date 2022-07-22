#pragma once

#include "../Data.h"
#include "../PublicKey.h"

#include <string>

namespace SG::Algorand {}

class Address { 
   public: 
      /// Base32 encoded address string length.  
      static const size_t encodedSize = 58; 

      /// Sha512/256 checksum size. 
      static const size_t checksumSize = 4;  
      /// Address data consisting of public key. 

      std::array<byte, PublicKey::ed25519Size> bytes;  

      /// Determines whether a string makes a valid address.
      static bool isValid(const std::string& string);  

      /// Initializes a Algorand address with a string representation.  
      explicit Address(const std::string& string);   

      /// Initializes a Algorand address with a public key.   
      explicit Address(const PublicKey& publicKey);  

      /// Returns a string representation of the address.  
      std::string string() const;
};  

inline bool operator==(const address& lhs, const Address& rhs) {  
      return lhs.bytes == rhs.bytes;
} 




