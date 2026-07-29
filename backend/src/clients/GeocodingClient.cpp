#include "clients/GeocodingClient.hpp"

#include <drogon/HttpClient.h>
#include <json/json.h>

#include <iostream>
#include <string>
#include <vector>

Location GeocodingClient::getCoordinates(const std::string &city) {

  std::cout << "Searching coordinates for: [" << city << "]\n";

  auto client =
      drogon::HttpClient::newHttpClient("https://geocoding-api.open-meteo.com");

  auto request = drogon::HttpRequest::newHttpRequest();

  request->setPath("/v1/search");

  request->setParameter("name", city);
  request->setParameter("count", "1");
  request->setParameter("language", "en");
  request->setParameter("format", "json");

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

  auto request = drogon::HttpRequest::newHttpRequest();

  request->setPath("/v1/search");

  request->setParameter("name", query);
  request->setParameter("count", "10");
  request->setParameter("language", "en");
  request->setParameter("format", "json");

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
