/**
 * @author - James Huston [jamzhuston@gmail.com]
 * @date 11/2023
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


std::string Item::getName() const {
  return name;
}


std::string Item::getDescription() const {
  return description;
}


std::string Item::getUselocation() const {
  return useLocation;
}

bool Item::equals(const Item& item) const {
  return this->name == item.name
      && this->useLocation == item.useLocation;
}


std::string Item::toString() const {
  std::ostringstream stringReader;
  stringReader << name;
  stringReader << '\n';
  stringReader << description;
  stringReader << '\n';
  stringReader << useLocation;
  stringReader << '\n';
  return stringReader.str();
}
