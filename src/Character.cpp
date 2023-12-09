/**
* @author James Huston [huston@uleth.ca]
* @author Raven Huery [raven.huery@uleth.ca]
* @date 2023-11
*/

#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <list>
#include <fstream>
#include <limits>

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
  std::string fileName;
  if (name == "Craig" || name == "Craig2") {
    fileName = "src/GameText/people/craig.txt";
  } else if (name == "Stephanie" || name == "stephanie") {
    fileName = "src/GameText/people/stephanie.txt";
  } else if (name == "Rose" || name == "rose") {
    fileName = "src/GameText/people/rose.txt";
  } else if (name == "Brent" || name == "brent") {
    fileName = "src/GameText/people/brent.txt";
  }

  std::ifstream fs;
  fs.open(fileName);
  std::string line;
  std::string temp;
  while (!fs.eof()) {
    getline(fs, line);
    temp += line;
    temp.push_back('\n');
  }
  this->dialogue = temp;

  fs.close();
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
    std::cout << "\nItem already exists in inventory!" << std::endl;
  } else {
      itemList.push_back(new Item(item));
      std::cout << "\nItem added to inventory!" << std::endl;
  }
}

void Player::drop() {
  std::string itemName;
  std::cout << "Enter the name of the item you'd like to drop,\n"
               "Otherwise enter q to quit!" << std::endl;
  std::getline(std::cin, itemName);
  if (!findItem(itemName) && itemName != "q") {
    while (findItem(itemName) == false && itemName != "q") {
        std::cout << "Enter the name of the item you'd like to drop,\n"
                     "Otherwise enter q to quit!" << std::endl;
        std::getline(std::cin, itemName);
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
  std::cout << "\nEnter the name of the item you'd like to inspect,\n"
               "Otherwise enter q to quit!" << std::endl;
  std::getline(std::cin, itemName);
  if (!findItem(itemName) && itemName != "q") {
    while (findItem(itemName) == false && itemName != "q") {
        std::cout << "\nEnter the name of the item you'd like to inspect,\n"
               "Otherwise enter q to quit!" << std::endl;
        std::getline(std::cin, itemName);
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
  std::cout << "\nYou have the following itmes: \n\n";
    for (auto it : itemList) {
      std::cout << it->toString() << "\n" <<std::endl;  
    }
}

Item* Player::useItem() {
  std::string itemName = "";
  std::cout << "Enter the name of the item you'd like to use\n"
               "Otherwise enter q to quit" << std::endl;
  std::cin >> itemName;
  while (!findItem(itemName)) {
      std::cout << "Enter the name of the item you'd like to use\n"
             "Otherwise enter q to quit!" << std::endl;


      std::cout << "hey little man" << std::endl;       
        std::cin >> itemName;
      if (itemName == "q")
        break;
  }
  if (itemName != "q") {
      for (auto it : itemList) {
        if (it->getName() == itemName) {
          return it;
      }
    }
  }
  return nullptr;
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
