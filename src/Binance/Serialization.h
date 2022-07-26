#pragma once

#include "../proto/Binance.pb.h"
#include <nlohmann/json.hpp>

namespace SG::Binance {

nlohmann::json signatureJSON(const Proto::SigningInput& input);
nlohmann::json orderJSON(const Proto::SigningInput& input);
nlohmann::json inputsJSON(const Proto::SendOrder& order);
nlohmann::json outputsJSON(const Proto::SendOrder& order);
nlohmann::json tokenJSON(const Proto::SendOrder_Token& token, bool stringAmount = false);
nlohmann::json tokensJSON(const ::google::protobuf::RepeatedPtrField<Proto::SendOrder_Token>& tokens);

} // namespace SG::Binance
