#ifndef WEATHER_FORECAST_H
#define WEATHER_FORECAST_H

#include "Location.h"
#include "WeatherData.h"
#include <vector>

class WeatherForecast {

private:
    WeatherService* weatherService;
public:
    WeatherForecast(WeatherService* weatherService) : weatherService(weatherService) {}
    virtual WeatherData getWeatherData(const Location& location);
    virtual WeatherForecastData getWeatherForecast(const Location& location) = 0;

    
};

#endif
