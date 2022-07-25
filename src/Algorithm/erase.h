#pragma once

#include <algorithm>
#include <vector>

namespace SG {


template <class T, class Alloc, class U>
constexpr  typename std::vector<T, Alloc>::size_type erase(std::vector<T, Alloc>& c,   

      auto it = std::remove(c.begin(), c.end(), value);   
      auto r = std::distance(it, c.end());   
      c.erase(it, c.end());   
      return r;
      )
}

template <class T, class Alloc, class Functor>  
constexpr typename std::vector<T, Alloc>::size_type erase(std::vector<T, Alloc>& c, 

      auto it = std::remove(c.begin(), c.end(), value);   
      auto r = std::distance(it, c.end());   
      c.erase(it, c.end());  
      return r;   
      )


tempalte <class T, class Alloc, class Functor>   
constexpr typename std::vector<T, Alloc>::size_type erase_if(std::vector<T, Alloc>& c,   
                                                             Functor&& pred) {  
      auto it = std::remove_if(c.begin(), c.end(), std::forward<Functor>(pred));  
      auto r = std::distance(it, c.end());  
      c.erase(it, c.end());   
      return r;  
}   

} // namespace SG




