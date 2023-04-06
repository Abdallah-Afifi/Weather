#include "Location.h"
#include "OpenWeatherMapService.h"
#include "WeatherData.h"

#include <iostream>

int main() {
    double lat, lon;
    std::cout << "Enter latitude and longitude: ";
    std::cin >> lat >> lon;

    Location loc(lat, lon);
    OpenWeatherMapService service;
    WeatherData current = service.getWeatherData(loc);
    //WeatherForecast forecast = service.getWeatherForecast(loc);

    std::cout << "Current temperature: " << current.getTemperature() << " C" << std::endl;
    std::cout << "Current humidity: " << current.getHumidity() << " %" << std::endl;
    std::cout << "Current pressure: " << current.getWindSpeed() << " m/s" << std::endl;
    std::cout << std::endl;

    /*std::cout << "Forecast for the next 24 hours:" << std::endl;
    for (auto& entry : forecast.getHourlyForecasts()) {
        std::cout << entry.first << ": " << entry.second.getTemperature() << " C, "
            << entry.second.getHumidity() << " %, " << entry.second.getWindSpeed() << " m/s" << std::endl;
    }*/
    return 0;
}
