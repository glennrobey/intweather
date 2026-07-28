#include "config/EnvLoader.hpp"
#include "controllers/HealthController.hpp"
#include "controllers/WeatherController.hpp"

#include <drogon/drogon.h>

int main() {

  EnvLoader::load(".env");

  HealthController::registerRoutes();
  WeatherController::registerRoutes();

  drogon::app().addListener("127.0.0.1", 8080).run();

  return 0;
}
