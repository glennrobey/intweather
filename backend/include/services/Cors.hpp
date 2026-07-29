#pragma once

#include <drogon/drogon.h>

namespace Cors {

inline void addHeaders(const drogon::HttpResponsePtr &resp) {
  resp->addHeader("Access-Control-Allow-Origin",
                  "https://intweather.vercel.app");

  resp->addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");

  resp->addHeader("Access-Control-Allow-Headers", "Content-Type");
}

} // namespace Cors
