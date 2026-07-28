#include "config/EnvLoader.hpp"

#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

void EnvLoader::load(const std::string &path) {

  std::ifstream file(path);

  if (!file.is_open()) {
    throw std::runtime_error("Could not open .env file");
  }

  std::string line;

  while (std::getline(file, line)) {

    // Ignore empty lines
    if (line.empty()) {
      continue;
    }

    // Ignore comments
    if (line[0] == '#') {
      continue;
    }

    auto separator = line.find('=');

    if (separator == std::string::npos) {
      continue;
    }

    std::string key = line.substr(0, separator);
    std::string value = line.substr(separator + 1);

#ifdef _WIN32
    _putenv_s(key.c_str(), value.c_str());
#else
    setenv(key.c_str(), value.c_str(), 1);
#endif
  }
}
