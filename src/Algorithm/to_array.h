#pragma once

#include <algorithm> //< std::copy
#include <array>     //< std::array


namespace SG {

template <typename T, std::size_t N, typename Collection>   
constexpr std::array<T, N> to_array(Collection&& collection)  {  
      std::array<T, N> out{};  
      std::copy(begin(collection), end(collection), out.begin());   
      return out;  
}


}  // namespace SG


