#include "services/WeatherService.hpp"

Weather WeatherService::getWeather(const std::string &city) {
  Weather weather;

  weather.city = city;
  weather.temperature = 75;
  weather.condition = "Sunny";
  weather.humidity = 45;

  return weather;
}
