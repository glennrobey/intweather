#include "controllers/HealthController.hpp"
#include <drogon/drogon.h>

int main() {
  HealthController::registerRoutes();

  drogon::app().addListener("127.0.0.1", 8080).run();
}
