/*
OpenWeatherMapService:
Concrete implementation of WeatherService that uses the OpenWeatherMap API to obtain weather data.
Implements the functions defined in the WeatherService abstract class, such as getWeatherData().
Has a relationship with WeatherForecast as it provides the weather data used to provide the weather forecast.
*/

#ifndef OPENWEATHERMAPSERVICE_H
#define OPENWEATHERMAPSERVICE_H

#include "WeatherService.h"

class OpenWeatherMapService : public WeatherService {
public:
    WeatherData getWeatherData(const Location& location) override;
private:
    static size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata);
};

#endif // OPENWEATHERMAPSERVICE_H
