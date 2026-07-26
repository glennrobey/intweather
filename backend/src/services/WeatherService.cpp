#include "services/WeatherService.hpp"

Weather WeatherService::getWeather(const std::string &city) {
  auto location = geocodingClient.getCoordinates(city);

  return weatherClient.fetchWeather(location.latitude, location.longitude);
}
