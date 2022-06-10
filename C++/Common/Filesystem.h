#include "Defines.h"

// includes STL
#include <string>


namespace Filesystem {
  
    // simple read text function
    std::string readText(CString filePath);
  
    bool readBinary(CString filePath, std::vector<char>& buffer);

    template<typename T>
    bool readBinaryT(CString filePath, std::vector<T>& buffer);
 
  
}
