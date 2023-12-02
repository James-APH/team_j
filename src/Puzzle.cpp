/* @Authors - James Huston | jamzhuston@gmail.com |
 *          - 
 *          -
 * Created 10/30/2023
 *
*/

#include <iostream>
#include <string>

#include "Puzzle.h"
#include "Item.h"


Puzzle::Puzzle(std::string description) {
    this->description = description;
}


Puzzle::~Puzzle() {}



//-------------------------------------------------------------


DialoguePuzzle::DialoguePuzzle(std::string description
                             , std::string expectedInput) : Puzzle(description) {
                            this->expectedInput = expectedInput;
                            }


DialoguePuzzle::~DialoguePuzzle() {
}

void DialoguePuzzle::getInput(std::string answer) {
}

bool DialoguePuzzle::wasSolved() {
}

void DialoguePuzzle::display() {
}

std::string DialoguePuzzle::toString() {
}




ItemPuzzle::ItemPuzzle(std::string description, const Item &item) : Puzzle(description) {
}

ItemPuzzle::~ItemPuzzle() {
}

void ItemPuzzle::checkItem(const Item &item) {
}

bool ItemPuzzle::wasSolved() {
}

void ItemPuzzle::display() {
}

std::string ItemPuzzle::toString() {
}
