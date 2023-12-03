/**
* @Author James Huston [huston@uleth.ca]
* @date 2023-11
*/

#include <string>

#include "Item.h"
#include "Inventory.h"
#include "Character.h"


Character::Character() {

}


Character::Character(std::string name) {

}

Character::~Character() {

}

void Character::display() {

}


std::string Character::toString() {

}






NPC::NPC(std::string name, std::string dialogue) {

}


NPC::~NPC() {

}



void NPC::display() {

}





std::string NPC::toString() {

}









Player::Player(std::string name) {

}


Player::~Player() {

}


void Player::pickUp(const Item &item) {

}


void Player::drop(std::string name) {

}


char Player::getMoveRoomChoice(std::string question,
                         const std::string options[]) {

                         }


char Player::getRoomActivityChoice(std::string question,
                             const std::string options[]) {

                             }


char Player::accuse(std::string question,
              const std::string options[]) {

              }


void Player::display() {

}



std::string Player::toString() {

}

