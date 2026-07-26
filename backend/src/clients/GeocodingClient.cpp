#include "clients/GeocodingClient.hpp"

Location GeocodingClient::getCoordinates(const std::string &city) {
  Location location;

  location.city = city;

  if (city == "Chicago") {
    location.latitude = 41.8781;
    location.longitude = -87.6298;
  }

  return location;
}
