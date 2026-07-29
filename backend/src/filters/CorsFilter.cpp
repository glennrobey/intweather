#include "filters/CorsFilter.hpp"

void CorsFilter::doFilter(const drogon::HttpRequestPtr &req,
                          drogon::FilterCallback &&callback,
                          drogon::FilterChainCallback &&chainCallback) {
  auto response = drogon::HttpResponse::newHttpResponse();

  response->addHeader("Access-Control-Allow-Origin", "http://localhost:5173");

  response->addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");

  response->addHeader("Access-Control-Allow-Headers", "Content-Type");

  if (req->method() == drogon::HttpMethod::Options) {
    callback(response);
    return;
  }

  chainCallback();
}
