#include "controllers/WeatherController.hpp"
#include "services/WeatherService.hpp"

void WeatherController::registerRoutes() {
  static WeatherService service;

  drogon::app().registerHandler(
      "/api/weather",
      [&service](
          const drogon::HttpRequestPtr &,
          std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
        auto weather = service.getWeather("Chicago");

        Json::Value response;

        response["city"] = weather.city;
        response["temperatureF"] = weather.temperatureF;
        response["feelsLikeF"] = weather.feelsLikeF;
        response["humidity"] = weather.humidity;
        response["windSpeedMph"] = weather.windSpeedMph;
        response["condition"] = weather.condition;

        auto resp = drogon::HttpResponse::newHttpJsonResponse(response);

        callback(resp);
      });
}
