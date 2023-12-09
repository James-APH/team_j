/**
 * @author James Huston [huston@uleth.ca]
 * @author Raven Huery [raven.huery@uleth.ca]
 * @author Parker Regier [tyre.regier@uleth.ca]
 * @date 2023-11
 */




#include <iostream>
#include <string>
#include <sstream>

#include "Item.h"



Item::Item(std::string name, std::string useLocation,
  std::string description) {
    this->name = name;
    this->useLocation = useLocation;
    this->description = description;
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
  stringReader << " - ";
  stringReader << description;
  stringReader << " - ";
  stringReader << useLocation;
  //stringReader << "\n";
  return stringReader.str();
}
