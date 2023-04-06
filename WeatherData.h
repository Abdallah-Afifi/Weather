/*
WeatherData:
Represents the current weather data and includes temperature, humidity, pressure, and other relevant information.
May also include historical weather data for the location.
Has a relationship with WeatherForecast as it provides the current weather information that will be used to provide the weather forecast.
*/


#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <iostream>

class WeatherData
{
private: 
	double humidity; 
	double windspeed; 
	double temperature;
public: 
	WeatherData() {
		humidity = 0.0; windspeed = 0.0; temperature = 0.0;
	}
	WeatherData(double hum, double wind, double temp) : humidity(hum), windspeed(wind), temperature(temp) {}
	void setHumidity(double hum) {
		humidity = hum;
	}
	void setWindSpeed(double wind) {
		windspeed = wind;
	}
	void setTemperature(double temp) {
		temperature = temp;
	}
	
	double getHumidity() const {
		return humidity;
	}
	double getWindSpeed() const {
		return windspeed;
	}
	double getTemperature() const {
		return temperature;
	}
};

#endif 