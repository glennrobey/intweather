#pragma once

#include "models/Weather.hpp"
#include <string>

class WeatherApiClient {
public:
  Weather fetchWeather(const std::string &city);
};
