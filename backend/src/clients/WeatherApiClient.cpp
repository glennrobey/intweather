#include "clients/WeatherApiClient.hpp"

#include <cmath>
#include <cstdlib>
#include <drogon/drogon.h>
#include <iostream>
#include <mmeapi.h>
#include <sstream>
#include <stdexcept>

WeatherApiClient::WeatherApiClient() {
  const char *key = std::getenv("PIRATE_WEATHER_API_KEY");

  if (!key) {
    throw std::runtime_error(
        "Missing PIRATE_WEATHER_API_KEY environment variable");
  }

  apiKey = key;
}

Weather WeatherApiClient::fetchWeather(const std::string &city, double latitude,
                                       double longitude) {

  std::ostringstream path;

  path << "/forecast/" << apiKey << "/" << latitude << "," << longitude;

  auto client =
      drogon::HttpClient::newHttpClient("https://api.pirateweather.net");

  auto request = drogon::HttpRequest::newHttpRequest();

  request->setMethod(drogon::Get);
  request->setPath(path.str());

  auto [result, response] = client->sendRequest(request);

  if (result != drogon::ReqResult::Ok) {
    throw std::runtime_error("Failed to contact Pirate Weather API");
  }

  auto json = response->getJsonObject();

  if (!json) {
    throw std::runtime_error("Invalid JSON response");
  }

  // Debug API response (remove later)
  std::cout << json->toStyledString() << std::endl;

  auto current = (*json)["currently"];

  Weather weather;

  weather.city = city;

  weather.temperatureF =
      std::round(current["temperature"].asDouble() * 10) / 10.0;

  weather.feelsLikeF =
      std::round(current["apparentTemperature"].asDouble() * 10) / 10.0;

  weather.humidity = std::round(current["humidity"].asDouble() * 100);

  weather.windSpeedMph =
      std::round(current["windSpeed"].asDouble() * 10) / 10.0;

  weather.condition = current["summary"].asString();

  return weather;
}
