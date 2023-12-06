/**
* @author James Huston [huston@uleth.ca]
* @date 2023-11
*/

#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <list>

#include "Item.h"
#include "Character.h"



Character::Character(std::string name) {
  if (name != "") {
    this->name = name;
  }
}

Character::~Character() {}

std::string Character::getName() {
  return name;
}

NPC::NPC(std::string name, std::string dialogue) : Character(name) {
  if (dialogue != "") {
    this->dialogue = dialogue;
  }
}

NPC::NPC(const NPC &fella) {
  this->name = fella.name;
  this->dialogue = fella.dialogue;
}

NPC::~NPC() {}

void NPC::display() const {
  std::ostringstream stringReader;
  stringReader << std::setw(25);
  stringReader << "Hello detective, my name is "
   << name << "!" << '\n';
  stringReader << dialogue << std::endl;
  std::cout << stringReader.str() << std::endl;
}

Player::Player(std::string name, const Item& item)
  : Character(name) {
  itemList.push_back(new Item("NullItem", "Null", "Null"));
  itemList.push_back(new Item(item));
}

Player::~Player() {
  for (auto it : itemList) {
    if (it != nullptr)
      delete it;
  }
  itemList.clear();
}

void Player::pickUp(const Item& item) {
  if (findItem(item)) {
    std::cout << "Item already exists in inventory!" << std::endl;
  } else {
      itemList.push_back(new Item(item));
      std::cout << "Item added to inventory!" << std::endl;
  }
}

void Player::drop() {
  std::string itemName;
  std::cout << "Enter the name of the item you'd like to drop,\n"
               "Otherwise enter q to quit!" << std::endl;
  std::cin >> itemName;
  if (!findItem(itemName) && itemName != "q") {
    while (findItem(itemName) == false && itemName != "q") {
        std::cout << "Enter the name of the item you'd like to drop,\n"
                     "Otherwise enter q to quit!" << std::endl;
        std::cin >> itemName;
    }
  }
  if (itemName != "q") {
    for (auto it : itemList) {
      if (it->getName() == itemName) {
        itemList.remove(it);
        std::cout << "Item dropped!" << std::endl;
      }
    }
  }
}

void Player::InspectItem() const {
  std::string itemName;
  std::cout << "Enter the name of the item you'd like to inspect,\n"
               "Otherwise enter q to quit!" << std::endl;
  std::cin >> itemName;
  if (!findItem(itemName) && itemName != "q") {
    while (findItem(itemName) == false && itemName != "q") {
        std::cout << "Enter the name of the item you'd like to inspect,\n"
               "Otherwise enter q to quit!" << std::endl;
        std::cin >> itemName;
    }
  }
  if (itemName != "q") {
    for (auto it : itemList) {
      if (it->getName() == itemName) {
        std::cout << it->toString() << std::endl;
      }
    }
  }
}

void Player::listInventory() const {
  for (auto it : itemList) {
    std::cout << it->toString() << std::endl;
  }
}

Item& Player::useItem() {
  std::string itemName;
  std::cout << "Enter the name of the item you'd like to use,\n"
               "Otherwise enter q to quit!" << std::endl;
  std::cin >> itemName;
  if (!findItem(itemName) && itemName != "q") {
    while (findItem(itemName) == false && itemName != "q") {
        std::cout << "Enter the name of the item you'd like to use\n"
               "Otherwise enter q to quit!" << std::endl;
        std::cin >> itemName;
    }
  }
  if (itemName != "q") {
      for (auto it : itemList) {
        if (it->getName() == itemName) {
          return *it;
      }
    }
  }
  return *itemList.front();
}

bool Player::findItem(const Item& item) const {
  for (auto it : itemList) {
    if (it->equals(item))
      return true;
  }
  return false;
}

bool Player::findItem(std::string itemName) const {
  for (auto it : itemList) {
    if (it->getName() == itemName)
      return true;
  }
  return false;
}
