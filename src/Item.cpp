/* @Authors - James Huston | jamzhuston@gmail.com |
 *          - 
 *          -
 * Created 10/30/2023
 *
*/




#include <iostream>
#include <string>
#include <sstream>

#include "Item.h"



Item::Item(std::string name, std::string useLocation,
  std::string description) {
}


Item::Item(const Item& item) {
  this->name = item.name;
  this->useLocation = item.useLocation;
  this->description = item.description;
}


Item::~Item() {}


std::string Item::getName() {
  return name;
}


std::string Item::getDescription() {
  return description;
}


std::string Item::getUselocation() {
  return useLocation;
}

bool Item::equals(const Item& item) {
  return this->name == item.name
      && this->useLocation == item.useLocation;
}


std::string Item::toString() {
  std::ostringstream stringReader;
  stringReader << name;
  stringReader << '\n';
  stringReader << description;
  stringReader << '\n';
  stringReader << useLocation;
  stringReader << '\n';
  return stringReader.str();
}
