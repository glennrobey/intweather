#pragma once

#include "clients/WeatherApiClient.hpp"
#include "models/Weather.hpp"

class WeatherService {
public:
  Weather getWeather(const std::string &city);

private:
  WeatherApiClient client;
};
