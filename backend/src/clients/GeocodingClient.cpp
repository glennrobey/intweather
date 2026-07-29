#include "clients/GeocodingClient.hpp"

#include <drogon/HttpClient.h>
#include <json/json.h>

#include <cctype>
#include <sstream>
#include <vector>
Location GeocodingClient::getCoordinates(const std::string &city) {
  auto client =
      drogon::HttpClient::newHttpClient("https://geocoding-api.open-meteo.com");

  std::ostringstream path;

  path << "/v1/search?name=" << drogon::utils::urlEncode(city)
       << "&count=1&language=en&format=json";

  auto request = drogon::HttpRequest::newHttpRequest();

  request->setPath(path.str());

  auto result = client->sendRequest(request);

  if (result.first != drogon::ReqResult::Ok) {
    throw std::runtime_error("Failed to contact Open-Meteo geocoding API");
  }

  auto response = result.second;

  auto json = response->getJsonObject();

  if (!json || !(*json).isMember("results") || (*json)["results"].empty()) {
    throw std::runtime_error("City not found");
  }

  const auto &first = (*json)["results"][0];

  Location location;

  location.city = first["name"].asString();
  location.latitude = first["latitude"].asDouble();
  location.longitude = first["longitude"].asDouble();

  return location;
}

std::vector<std::string>
GeocodingClient::searchCities(const std::string &query) {
  std::vector<std::string> cities;

  if (query.empty()) {
    return cities;
  }

  auto client =
      drogon::HttpClient::newHttpClient("https://geocoding-api.open-meteo.com");

  std::ostringstream path;

  path << "/v1/search?name=" << drogon::utils::urlEncode(query)
       << "&count=10&language=en&format=json";

  auto request = drogon::HttpRequest::newHttpRequest();
  request->setPath(path.str());

  auto result = client->sendRequest(request);

  if (result.first != drogon::ReqResult::Ok) {
    return cities;
  }

  auto json = result.second->getJsonObject();

  if (!json || !(*json).isMember("results")) {
    return cities;
  }

  for (const auto &city : (*json)["results"]) {
    std::string display = city["name"].asString();

    if (city.isMember("admin1")) {
      display += ", " + city["admin1"].asString();
    }

    if (city.isMember("country")) {
      display += ", " + city["country"].asString();
    }

    cities.push_back(display);
  }

  return cities;
}
