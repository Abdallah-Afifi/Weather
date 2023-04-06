#include "OpenWeatherMapService.h"
#include "WeatherData.h"
#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <iostream>

using json = nlohmann::json;

OpenWeatherMapService::OpenWeatherMapService() {}

size_t OpenWeatherMapService::write_callback(char* ptr, size_t size, size_t nmemb, void* userdata) {
    ((std::string*)userdata)->append(ptr, size * nmemb);
    return size * nmemb;
}

WeatherData OpenWeatherMapService::getWeatherData(const Location& location) {
    CURL* curl;
    CURLcode res;
    std::string read_buffer;
    std::string url = "https://api.open-meteo.com/v1/forecast?";
    url += "latitude=" + std::to_string(location.getLatitude());
    url += "&longitude=" + std::to_string(location.getLongitude());
    url += "&current_weather=true&hourly=temperature_2m,relativehumidity_2m,windspeed_10m";
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &read_buffer);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    json j = json::parse(read_buffer);
    WeatherData weather_data;
    if (j.contains("current_weather")) {
        auto current = j["current_weather"];
        weather_data.setTemperature(current["temperature"]);
        weather_data.setHumidity(current["relativehumidity_2m"]);
        weather_data.setWindSpeed(current["windspeed_10m"]);
    }
    return weather_data;
}
