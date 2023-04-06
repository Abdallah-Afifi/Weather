/*
Location:
Represents the user's location and includes the latitude and longitude.
Can also include additional information such as city, state, country, zip code, etc.
Has a relationship with WeatherForecast as the user's location is used to obtain weather data and provide weather forecasts.
*/

#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>

class Location
{

private:
	double longitude;
	double latitude;

public: 
	Location (double lon, double lat) : longitude(lon), latitude (lat) {}

	double getLongitude() const {
		return longitude; 
	}

	double getLatitude() const {
		return latitude;
	}


};

#endif