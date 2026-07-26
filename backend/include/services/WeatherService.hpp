#pragma once

#include "clients/WeatherApiClient.hpp"
#include "models/Weather.hpp"

#include <string>

class WeatherService {
public:
  Weather getWeather(const std::string &city);

private:
  WeatherApiClient client;
};
