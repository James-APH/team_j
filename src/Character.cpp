/**
* @Author James Huston [huston@uleth.ca]
* @date 2023-11
*/

#include <string>
#include <sstream>
#include <iomanip>

#include "Item.h"
#include "Inventory.h"
#include "Character.h"


Character::Character() {
  name = "undetermined";
}

Character::Character(std::string name) {
  if(name != "") {
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

Player::Player(std::string name) : Character(name) {

}

Player::~Player() {
  delete inventory;
}

void Player::pickUp(const Item &item) {
  inventory->addItem(item);
}

void Player::drop(std::string name) {
  if(inventory->hasItem(name)) {
    inventory->deleteItem(name);
    std::cout << "Item Dropped" << std::endl;
  }
  std::cout << "Item not in inventory" << std::endl;
}

Item& Player::useItem() {
  std::string itemName;
  do {
    std::cout << "What item would you like to use? " << std::endl;
    std::cout << inventory->toString() << std::endl;
    std::cin >> itemName;
  } while(!inventory->hasItem(itemName));
  return inventory->getItem(itemName);
}
