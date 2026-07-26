#include "services/WeatherService.hpp"

Weather WeatherService::getWeather(const std::string &city) {
  return client.fetchWeather(city);
}
