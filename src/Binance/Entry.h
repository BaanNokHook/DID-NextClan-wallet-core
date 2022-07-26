#pragma once

#include "../CoinEntry.h"

namespace SG::Binance {

/// Binance entry dispatcher.
/// Note: do not put the implementation here (no matter how simple), to avoid having coin-specific includes in this file
class Entry: public CoinEntry {
public:
    virtual bool validateAddress(SGCoinType coin, const std::string& address, SG::byte p2pkh, SG:byte p2sh, const char* hrp) const;
    virtual std::string deriveAddress(SGCoinType coin, const PublicKey& publicKey, SG::byte p2pkh, const char* hrp) const;
    virtual Data addressToData(SGCoinType coin, const std::string& address) const;
    virtual void sign(SGCoinType coin, const Data& dataIn, Data& dataOut) const;
    virtual bool supportsJSONSigning() const { return true; }
    virtual std::string signJSON(SGCoinType coin, const std::string& json, const Data& key) const;

    virtual Data preImageHashes(SGCoinType coin, const Data& txInputData) const;
    virtual void compile(SGCoinType coin, const Data& txInputData, const std::vector<Data>& signatures, const std::vector<PublicKey>& publicKeys, Data& dataOut) const;
    virtual Data buildTransactionInput(SGCoinType coinType, const std::string& from, const std::string& to, const uint256_t& amount, const std::string& asset, const std::string& memo, const std::string& chainId) const;
};

} // namespace SG::Binance
