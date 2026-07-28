#pragma once

#include "clients/GeocodingClient.hpp"
#include "clients/WeatherApiClient.hpp"
#include "models/Weather.hpp"

#include <string>

class WeatherService {
public:
  Weather getWeather(const std::string &city);

private:
  std::string capitalizeCity(std::string city);
  WeatherApiClient weatherClient;
  GeocodingClient geocodingClient;
};
