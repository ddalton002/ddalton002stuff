/*
 * Name        : temperature.cpp
 * Author      : David Dalton
 * Description : Program to convert function between various temperatures
 */
 
#include "temperature.h"

  /*
   * Sets kelvin_ to 0
   */
  Temperature::Temperature()
  {
      kelvin_ = 0;
  }

  /*
   * Sets kelvin_ to the supplied value using the SetTempFromKelvin() function
   */
  Temperature::Temperature(double kelvin) 
  {
      SetTempFromKelvin(kelvin);
  }

  /*
   * Converts the supplied temperature to kelvin using the appropriate function
   * and internally stores it.
   * Uses an if statement to check the unit to convert to the correct
   * temperature unit type
   */
  Temperature::Temperature(double temp, char unit) 
  {
      unit = toupper(unit);
      if(unit == 'F') 
      {
          SetTempFromFahrenheit(temp);
      } else if(unit == 'C') 
      {
          SetTempFromCelsius(temp);
      } else 
      {
          SetTempFromKelvin(temp);
      }
  }

  /*
   * The temperature will come in as kelvin and this function will set the
   * internal temp to this value
   */
  void Temperature::SetTempFromKelvin(double kelvin) 
  {
      kelvin_ = kelvin;
  }


  /*
   * Converts the value from Celsius to kelvin then sets
   * the temperature to the converted value
   */
  void Temperature::SetTempFromCelsius(double celsius) 
  {
      kelvin_ = (celsius + 273.15);
  }


  /*
   *Converts the value from Fahrenheit to kelvin then sets
   *the temperature to the converted value
   */
  void Temperature::SetTempFromFahrenheit(double fahrenheit) 
  {
      kelvin_ = (5.0 * (fahrenheit - 32) /9) + 273.15;
  }

  /*
   * Gets the internal temperature in Kelvin and returns it.
   */
  double Temperature::GetTempAsKelvin() const 
  {
      return kelvin_;
  }

  /*
   * Converts the internal temperature from kelvin to celsius using the
   * GetTempAsCelsius() function then returns the value
   */
  double Temperature::GetTempAsCelsius() const 
  {
      return (kelvin_ - 273.15);
      
  }

  /*
   * Converts the internal temperature from kelvin to fahrenheit using the
   * GetTempAsFahrenheit() function then returns the value

   */
  double Temperature::GetTempAsFahrenheit() const 
  {
      double temperature = GetTempAsCelsius();
      return ((temperature * 9.0 / 5 ) + 32);
      
  }

  /*
   * Get a string representation of the temperature.
   * Uses an if statement to check which unit is needed then call the 
   * appropriate conversion function to convert the temperature as needed and
   * stores it into a temporary value.
   * Uses stringstream to return the converted value plus the appropriate
   * unit type.
   */
  string Temperature::ToString(char unit) const 
  {
      stringstream temp;
      temp.setf(std::ios::fixed|std::ios::showpoint);
      temp.precision(2);
      double current_temp;
      string current_temp_unit;
      unit = toupper(unit);
      if(unit == 'K') 
      {
        current_temp_unit = "Kelvin";
        current_temp = GetTempAsKelvin();
      } else if(unit == 'C') 
      {
          current_temp_unit = "Celsius";
          current_temp = GetTempAsCelsius();
      } else if(unit == 'F')
      {
        current_temp_unit = "Fahrenheit";
        current_temp = GetTempAsFahrenheit();
      } else 
      {
          return "Invalid Unit";
      }
      temp << current_temp << " " << current_temp_unit;
      return temp.str();
  }