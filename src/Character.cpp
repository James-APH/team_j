/**
* @Author James Huston [huston@uleth.ca]
* @date 2023-11
*/

#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>

#include "Item.h"
#include "Character.h"


Character::Character() {
  name = "undetermined";
}

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

NPC::~NPC() {}

void NPC::display() {
  std::ostringstream stringReader;
  stringReader << std::setw(25);
  stringReader << "Hello detective, my name is "
   << name << "!" << '\n';
  stringReader << dialogue << std::endl;
  std::cout << stringReader.str() << std::endl;
}

Player::Player(std::string name, const Item& item)
  : Character(name) {
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
  if (std::find(itemList.begin(), itemList.end(), item) == itemList.end()) {
    itemList.push_back(new Item(item));
    std::cout << "Item added to inventory" << std::endl;
    return;
  }
  std::cout << "Item already in inventory" << std::endl;
}

void Player::drop() {
  std::string itemName;
  std::cout << "What item would you like to drop?" << std::endl;
  for (auto it : itemList) {
    if (it->getName() == itemName) {
      itemList.remove(it);
      std::cout << "Item dropped" << std::endl;
      return;
    }
    std::cout << "Item not found!" << std::endl;
  }
}

void Player::InspectItem() {
  std::string itemName;
  std::cout << "What item would you like to inspect?" << std::endl;
  for (auto it : itemList) {
    if (it->getName() == itemName) {
      std::cout << it->toString() << std::endl;
      return;
    }
  }
  std::cout << "Item not found!" << std::endl;
}

void Player::listInventory() {
  for (auto it : itemList) {
    std::cout << it->toString() << std::endl;
  }
}


Item& Player::useItem() {
  std::string itemName;
  std::cout << "What item would you like to use?" << std::endl;
  std::cin >> itemName;
  for (auto it : itemList) {
    if (it->getName() == itemName) {
      return *it;
    }
  }
  std::cout << "Item not found!" << std::endl;
  return;
}
