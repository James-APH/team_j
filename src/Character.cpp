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
}


Character::Character(std::string name) {
}

Character::~Character() {
}

std::string Character::getName() {
  return name;
}


void Character::display() {
}


std::string Character::toString() {
}






NPC::NPC(std::string name, std::string dialogue) : Character(name) {
  if (dialogue != "") {
    this->dialogue = dialogue;
  }
}


NPC::~NPC() {

}



void NPC::display() {
  std::ostringstream stringReader;
  stringReader << std::setw(25);
  stringReader << "Hello detective, my name is "
   << name << "." << '\n';
  stringReader << dialogue << std::endl;
  std::cout << stringReader.str() << std::endl;
}









Player::Player(std::string name) {
}


Player::~Player() {
}


void Player::pickUp(const Item &item) {
}


void Player::drop(std::string name) {
}

Item& Player::useItem() {
  std::cout << "What item would you like to use? " << std::endl;
}

void Player::display() {
}
