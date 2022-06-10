#include "Filesystem.h"

// includes STL
#include <fstream>


namespace Filesystem {
  
    // simple read text function
    std::string readText(CString filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            return std::string("");
        }
        return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    }
  
  
  
}
