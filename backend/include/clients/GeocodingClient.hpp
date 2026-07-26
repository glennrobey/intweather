#pragma once

#include "models/Location.hpp"
#include <string>

class GeocodingClient {
public:
  Location getCoordinates(const std::string &city);
};
