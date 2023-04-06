/*
 WeatherService:
Abstract class that defines a common interface for different weather services.
Defines functions such as getWeatherData() that will be implemented by concrete weather services.
Has a relationship with OpenWeatherMapService as it is the concrete implementation of the WeatherService used in this program.
*/


#ifndef WEATHERSERVICE_H
#define WEATHERSERVICE_H

#include <iostream>
#include "WeatherData.h"
#include "Location.h"
#include <vector>

class WeatherService
{
private: 
	double lonitude;
	double latitude;
public: 
	virtual WeatherData getWeatherData(const Location& location) = 0;
};

#endif 