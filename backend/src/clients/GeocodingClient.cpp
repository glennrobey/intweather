#include "clients/GeocodingClient.hpp"

#include <cctype>
#include <vector>

Location GeocodingClient::getCoordinates(const std::string &city) {
  Location location;

  location.city = city;

  if (city == "Chicago") {
    location.latitude = 41.8781;
    location.longitude = -87.6298;
  }

  return location;
}

std::vector<std::string>
GeocodingClient::searchCities(const std::string &query) {

  std::vector<std::string> cities;

  if (query.empty()) {
    return cities;
  }

  std::string lowerQuery = query;

  for (char &c : lowerQuery) {
    c = std::tolower(c);
  }

  if (std::string("chicago").find(lowerQuery) != std::string::npos) {
    cities.push_back("Chicago, IL, USA");
  }

  if (std::string("chicago heights").find(lowerQuery) != std::string::npos) {
    cities.push_back("Chicago Heights, IL, USA");
  }

  if (std::string("chico").find(lowerQuery) != std::string::npos) {
    cities.push_back("Chico, CA, USA");
  }

  return cities;
}
