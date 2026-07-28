#include "services/WeatherService.hpp"
#include "clients/GeocodingClient.hpp"

#include <cctype>

Weather WeatherService::getWeather(const std::string &city) {
  auto formattedCity = capitalizeCity(city);

  auto location = geocodingClient.getCoordinates(formattedCity);

  return weatherClient.fetchWeather(formattedCity, location.latitude,
                                    location.longitude);
}

std::string WeatherService::capitalizeCity(std::string city) {
  bool capitalizeNext = true;

  for (char &c : city) {
    if (std::isspace(c)) {
      capitalizeNext = true;
    } else if (capitalizeNext) {
      c = std::toupper(c);
      capitalizeNext = false;
    } else {
      c = std::tolower(c);
    }
  }

  return city;
}
