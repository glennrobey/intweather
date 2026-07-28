#include "services/WeatherService.hpp"
#include "clients/GeocodingClient.hpp"

Weather WeatherService::getWeather(const std::string &city) {
  auto location = geocodingClient.getCoordinates(city);

  return weatherClient.fetchWeather(city, location.latitude,
                                    location.longitude);
}
