#include "controllers/WeatherController.hpp"
#include "services/WeatherService.hpp"

void WeatherController::registerRoutes() {
  drogon::app().registerHandler(
      "/api/weather",
      [](const drogon::HttpRequestPtr &,
         std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
        WeatherService service;
        Weather weather = service.getWeather("Chicago");

        Json::Value response;

        response["city"] = "Chicago";
        response["temperature"] = 75;
        response["condition"] = "Sunny";
        response["humidity"] = 45;

        auto resp = drogon::HttpResponse::newHttpJsonResponse(response);

        callback(resp);
      });
}
