cmake_minimum_required(VERSION 3.20)

project(IntWeather)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Drogon CONFIG REQUIRED)

add_executable(intweather
    src/main.cpp
    src/controllers/HealthController.cpp
    src/controllers/WeatherController.cpp
    src/services/WeatherService.cpp
    src/clients/WeatherApiClient.cpp
    src/clients/GeocodingClient.cpp
    src/config/EnvLoader.cpp
    src/filters/CorsFilter.cpp
)

target_include_directories(intweather PRIVATE
    include
)

target_link_libraries(intweather PRIVATE
    Drogon::Drogon
)
