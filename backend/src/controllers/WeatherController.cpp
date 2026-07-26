#include "controllers/WeatherController.hpp"
#include "services/WeatherService.hpp"

void WeatherController::registerRoutes() {

  drogon::app().registerHandler(
      "/api/weather",
      [](const drogon::HttpRequestPtr &req,
         std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
        static WeatherService service;

        auto city = req->getParameter("city");

        if (city.empty()) {
          Json::Value error;

          error["error"] = "City parameter required";

          auto resp = drogon::HttpResponse::newHttpJsonResponse(error);

          resp->setStatusCode(drogon::k400BadRequest);

          callback(resp);
          return;
        }

        auto weather = service.getWeather(city);

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
