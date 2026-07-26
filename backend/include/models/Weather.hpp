#pragma once

#include <string>

struct Weather {
  std::string city;

  double temperatureF = 0.0;
  double feelsLikeF = 0.0;

  double humidity = 0.0;

  double windSpeedMph = 0.0;

  std::string condition = "Unknown";
};
