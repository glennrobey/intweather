#pragma once

#include "models/Weather.hpp"
#include <string>

class WeatherApiClient {
public:
  WeatherApiClient();

  Weather fetchWeather(const std::string &city, double latitude,
                       double longitude);

private:
  std::string apiKey;
};
