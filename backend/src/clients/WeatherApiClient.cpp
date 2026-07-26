#include "clients/WeatherApiClient.hpp"

Weather WeatherApiClient::fetchWeather(const std::string &city) {
  Weather weather;

  weather.city = city;
  weather.temperature = 75;
  weather.condition = "Sunny";
  weather.humidity = 45;

  return weather;
}
