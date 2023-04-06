#include "WeatherForecast.h"
#include "OpenWeatherMapService.h"
#include <iostream>

WeatherForecast::WeatherForecast(WeatherService* service) {
    this->service = service;
}

void WeatherForecast::setWeatherService(WeatherService* service) {
    this->service = service;
}

WeatherData WeatherForecast::getCurrentWeather(const Location& location) {
    return service->getWeatherData(location);
}

WeatherForecastData WeatherForecast::getWeatherForecast(const Location& location) {
    WeatherForecastData forecastData;
    WeatherData currentWeather = service->getWeatherData(location);
    forecastData.setCurrentWeather(currentWeather);

    // Use the current weather location and the service to get hourly forecast
    Location currentLocation = currentWeather.getLocation();
    std::vector<WeatherData> hourlyForecast = service->getHourlyWeatherForecast(currentLocation);
    forecastData.setHourlyForecast(hourlyForecast);

    return forecastData;
}
