/*
 * Name        : lab_1.cpp
 * Author      : David Dalton
 * Description : Building a Spaceship Class
 */
#include "lab_1.h"

  /*
   * Set the name of this Spaceship.
   * @param string name - The name for this Spaceship
   */
  void Spaceship::set_name(string name) 
  {
      name_ = name;
  }

  /*
   * Set the top speed of this Spaceship.
   * @param double top_speed - The top speed for this Spaceship in warp
   */
  void Spaceship::set_top_speed(double top_speed) 
  {
      top_speed_ = top_speed;
  }

  /*
   * Set the fuel source of this Spaceship.
   * @param string fuel_source - A fuel source for this Spaceship
   */
  void Spaceship::set_fuel_source(string fuel_source) 
  {
      fuel_source_ = fuel_source;
  }

  /*
   * Set the crew capacity of this Spaceship.
   * @param int crew_capacity - A crew capacity for this Spaceship
   */
  void Spaceship::set_crew_capacity(int crew_capacity) 
  {
      crew_capacity_ = crew_capacity;
  }

  /*
   * Get the name of this Spaceship.
   * @return string - The name of this Spaceship
   */
  string Spaceship::name() const 
  {
      return name_;
  }

  /*
   * Get the top speed of this Spaceship.
   * @return double - The top speed of this Spaceship
   */
  double Spaceship::top_speed() const 
  {
      return top_speed_;
  }

  /*
   * Get the fuel source of this Spaceship.
   * @return string - The fuel source of this Spaceship
   */
  string Spaceship::fuel_source() const 
  {
      return fuel_source_;
  }

  /*
   * Get the crew capacity of this Spaceship.
   * @return int - The crew capacity of this Spaceship
   */
  int Spaceship::crew_capacity() const 
  {
      return crew_capacity_;
  }

  /*
   * Get a string representation of this Spaceship's specifications.
   * The string will be formatted as
   * "NAME\n
   *  Top Speed:     Warp TOP_SPEED\n
   *  Fuel Source:   FUEL_SOURCE\n
   *  Crew Capacity: CREW_CAPACITY"
   * where NAME, TOP_SPEED (to two decimal places), FUEL_SOURCE, and
   * CREW_CAPACITY contain the values of the associated member variables.
   * @uses stringstream
   * @return string - A representation of this Spaceship's specifications
   */
  string Spaceship::ToString() const 
  {
    /*
    *Uses stringstream to retrieve all of the class variables and stores them
    *into the stream along with additional descriptive strings.  Once they are
    *all combined in the stringstream it then retrieves the combined string and
    *returns it.
    */
    stringstream ship_description;
    ship_description.setf(std::ios::fixed|std::ios::showpoint);
    ship_description.precision(2);
    ship_description << name_ << "\n" << "Top Speed:     Warp "
                  << top_speed_ << "\n" << "Fuel Source:   " 
                  << fuel_source_ << "\n" << "Crew Capacity: " 
                  << crew_capacity_;
    return ship_description.str();
  }