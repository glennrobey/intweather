#include "controllers/WeatherController.hpp"

#include "clients/GeocodingClient.hpp"
#include "services/Cors.hpp"
#include "services/WeatherService.hpp"

#include <drogon/drogon.h>

void WeatherController::registerRoutes() {

  // Handle CORS preflight requests
  drogon::app().registerHandler(
      "/api/{path}",
      [](const drogon::HttpRequestPtr &req,
         std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
        auto resp = drogon::HttpResponse::newHttpResponse();

        Cors::addHeaders(resp);

        callback(resp);
      },
      {drogon::Options});

  drogon::app().registerHandler(
      "/api/cities",
      [](const drogon::HttpRequestPtr &req,
         std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
        static GeocodingClient client;

        auto query = req->getParameter("query");

        auto cities = client.searchCities(query);

        Json::Value response;

        for (const auto &city : cities) {
          response.append(city);
        }

        auto resp = drogon::HttpResponse::newHttpJsonResponse(response);

        Cors::addHeaders(resp);

        callback(resp);
      },
      {drogon::Get});

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

          Cors::addHeaders(resp);

          callback(resp);

          return;
        }

        try {

          auto weather = service.getWeather(city);

          Json::Value response;

          response["city"] = weather.city;
          response["temperatureF"] = weather.temperatureF;
          response["feelsLikeF"] = weather.feelsLikeF;
          response["humidity"] = weather.humidity;
          response["windSpeedMph"] = weather.windSpeedMph;
          response["condition"] = weather.condition;

          auto resp = drogon::HttpResponse::newHttpJsonResponse(response);

          Cors::addHeaders(resp);

          callback(resp);

        } catch (const std::exception &e) {

          Json::Value error;

          error["error"] = e.what();

          auto resp = drogon::HttpResponse::newHttpJsonResponse(error);

          resp->setStatusCode(drogon::k500InternalServerError);

          Cors::addHeaders(resp);

          callback(resp);
        }
      },
      {drogon::Get});
}
