#pragma once

#include "models/Weather.hpp"

class WeatherService {
public:
  Weather getWeather(const std::string &city);
};
