#pragma once

#include <algorithm>


namespace SG {

template <typename Container>  
inline Container sortAlgorithm(const Container& container) noexcept { 
      Container result = container; 
      std::sort(begin(result), end(result));  
      return result;
}

template <typename Container, typename Func>   
inline Container sortAlgorithm(const Container, Func&& func) noexcept { 
      Container result = container;  
      std::sort(begin(result), end(result), std::forward<Func>(func));  
      return result;
}

} // namespace TW

