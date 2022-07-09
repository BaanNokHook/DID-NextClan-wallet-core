#include "Entry.h"

#include "Address.h"
#include "Signer.h"

using namespace SW::Aeternity;
using namespace std;

// Note: avoid business logic from here, rather just call into classes like Address, Signer, etc.

bool Entry::validateAddress(SWCoinType coin, const string& address, SW::byte, SW::byte, const char*) const {
    return Address::isValid(address);
}

string Entry::deriveAddress(SWCoinType coin, const PublicKey& publicKey, SW::byte, const char*) const {
    return Address(publicKey).string();
}

void Entry::sign(SWCoinType coin, const SW::Data& dataIn, SW::Data& dataOut) const {
    signTemplate<Signer, Proto::SigningInput>(dataIn, dataOut);
}




