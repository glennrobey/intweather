#include <drogon/drogon.h>

#include <cstdlib>
#include <iostream>

#include "config/EnvLoader.hpp"
#include "controllers/HealthController.hpp"
#include "controllers/WeatherController.hpp"

int main() {

  EnvLoader::load(".env");

  auto key = std::getenv("PIRATE_WEATHER_API_KEY");

  if (key) {
    std::cout << "[INFO] API key loaded!" << std::endl;
  } else {
    std::cout << "[ERROR] API key missing!" << std::endl;
  }

  // Register API routes
  HealthController::registerRoutes();
  WeatherController::registerRoutes();

  std::cout << "[INFO] Server started on 0.0.0.0:8080" << std::endl;

  drogon::app().addListener("0.0.0.0", 8080).run();

  return 0;
}
