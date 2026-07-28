#include "controllers/WeatherController.hpp"
#include "clients/GeocodingClient.hpp"
#include "services/WeatherService.hpp"

#include <drogon/drogon.h>

void addCorsHeaders(const drogon::HttpResponsePtr &resp) {
  resp->addHeader("Access-Control-Allow-Origin", "http://localhost:5173");

  resp->addHeader("Access-Control-Allow-Methods", "GET, OPTIONS");

  resp->addHeader("Access-Control-Allow-Headers", "Content-Type");
}

void WeatherController::registerRoutes() {

  // Weather endpoint
  drogon::app().registerHandler(
      "/api/weather",
      [](const drogon::HttpRequestPtr &req,
         std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
        if (req->method() == drogon::Options) {
          auto resp = drogon::HttpResponse::newHttpResponse();

          addCorsHeaders(resp);

          callback(resp);
          return;
        }

        static WeatherService service;

        auto city = req->getParameter("city");

        if (city.empty()) {

          Json::Value error;

          error["error"] = "City parameter required";

          auto resp = drogon::HttpResponse::newHttpJsonResponse(error);

          resp->setStatusCode(drogon::k400BadRequest);

          addCorsHeaders(resp);

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

        addCorsHeaders(resp);

        callback(resp);
      });

  // City autocomplete endpoint
  drogon::app().registerHandler(
      "/api/cities",
      [](const drogon::HttpRequestPtr &req,
         std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
        if (req->method() == drogon::Options) {

          auto resp = drogon::HttpResponse::newHttpResponse();

          addCorsHeaders(resp);

          callback(resp);
          return;
        }

        static GeocodingClient client;

        auto query = req->getParameter("query");

        auto cities = client.searchCities(query);

        Json::Value response;

        for (const auto &city : cities) {
          response.append(city);
        }

        auto resp = drogon::HttpResponse::newHttpJsonResponse(response);

        addCorsHeaders(resp);

        callback(resp);
      });
}
