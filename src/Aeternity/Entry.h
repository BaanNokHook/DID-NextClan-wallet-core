#pragma once

#include "../CoinEntry.h"

namespace SW::Aeternity {

/// Entry point for implementation of Aeternity coin.
/// Note: do not put the implementation here (no matter how simple), to avoid having coin-specific includes in this file
class Entry: public CoinEntry {
public:
    virtual bool validateAddress(SWCoinType coin, const std::string& address, SW::byte p2pkh, SW::byte p2sh, const char* hrp) const;
    virtual std::string deriveAddress(SWCoinType coin, const PublicKey& publicKey, SW::byte p2pkh, const char* hrp) const;
    virtual void sign(SWCoinType coin, const Data& dataIn, Data& dataOut) const;
};

} // namespace SW::Aeternity
