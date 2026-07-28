#pragma once

#include "models/Location.hpp"
#include <string>
#include <vector>

class GeocodingClient {
public:
  Location getCoordinates(const std::string &city);

  std::vector<std::string> searchCities(const std::string &query);
};
