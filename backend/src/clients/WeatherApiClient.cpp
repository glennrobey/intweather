#include "clients/WeatherApiClient.hpp"

Weather WeatherApiClient::fetchWeather(double latitude, double longitude) {
  (void)latitude;
  (void)longitude;

  Weather weather;

  weather.city = "Unknown";
  weather.temperatureF = 75.0;
  weather.feelsLikeF = 76.0;
  weather.humidity = 45.0;
  weather.windSpeedMph = 10.0;
  weather.condition = "Sunny";

  return weather;
}
