#include "controllers/HealthController.hpp"

void HealthController::registerRoutes() {
  drogon::app().registerHandler(
      "/api/health",
      [](const drogon::HttpRequestPtr &,
         std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
        Json::Value response;

        response["status"] = "ok";
        response["message"] = "IntWeather backend running";

        auto resp = drogon::HttpResponse::newHttpJsonResponse(response);

        callback(resp);
      });
}
