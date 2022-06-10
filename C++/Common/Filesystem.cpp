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
  
  
  	bool readBinary(CString filePath, std::vector<char>& buffer) {
		std::ifstream file(filePath, std::ios::binary | std::ios::in | std::ios::ate);


		if (file.is_open()) { // !file.fail()
			size_t size = file.tellg();
			file.seekg(0, std::ios::beg);

			buffer.resize(size);

			file.read((char*)buffer.data(), size);
			file.close();

			return true;
		}

		return false;
	}


	template<typename T>
	bool readBinaryT(CString filePath, std::vector<T>& buffer) {
		std::ifstream file(filePath, std::ios::binary | std::ios::in | std::ios::ate);


		if (file.is_open()) { // !file.fail()
			size_t size = file.tellg();
			file.seekg(0, std::ios::beg);

			buffer.resize(size / sizeof(T));

			file.read((char*)buffer.data(), size);
			file.close();

			return true;
		}

		return false;
	}

  
}
