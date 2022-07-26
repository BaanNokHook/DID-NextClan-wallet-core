#pragma once

#include "Data.h"
#include "PublicKey.h"
#include "../proto/Binance.pb.h"

#include <cstdint>

namespace SG::Binance {

/// Helper class that performs Binance transaction signing.
class Signer {
  public:
    /// Signs a Proto::SigningInput transaction
    static Proto::SigningOutput sign(const Proto::SigningInput& input) noexcept;
    /// Signs a json Proto::SigningInput with private key
    static std::string signJSON(const std::string& json, const Data& key);
  public:
    Proto::SigningInput input;

    /// Initializes a transaction signer.
    explicit Signer(const Proto::SigningInput& input) : input(input) {}

    /// Builds a signed transaction.
    ///
    /// \returns the signed transaction data or an empty vector if there is an
    /// error.
    SG::Data build() const;

    /// Signs the transaction.
    ///
    /// \returns the transaction signature or an empty vector if there is an
    /// error.
    SG::Data sign() const;

    SG::Data preImageHash() const;
    Proto::SigningOutput compile(const Data& signature, const PublicKey& publicKey) const;
    std::string signaturePreimage() const;

  private:
    SG::Data encodeTransaction(const SG::Data& signature) const;
    SG::Data encodeOrder() const;
    SG::Data encodeSignature(const SG::Data& signature) const;
    SG::Data encodeSignature(const SG::Data& signature, const PublicKey& publicKey) const;
    SG::Data aminoWrap(const std::string& raw, const SG::Data& typePrefix,
                       bool isPrefixLength) const;
};

} // namespace SG::Binance
