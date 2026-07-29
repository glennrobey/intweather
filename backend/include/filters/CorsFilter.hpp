#pragma once

#include <drogon/drogon.h>

class CorsFilter : public drogon::HttpFilter<CorsFilter> {
public:
  void doFilter(const drogon::HttpRequestPtr &req,
                drogon::FilterCallback &&callback,
                drogon::FilterChainCallback &&chainCallback) override;
};
