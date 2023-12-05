/* @Authors - James Huston | jamzhuston@gmail.com |
 *          - 
 *          -
 * Created 10/30/2023
 *
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>


#include "Puzzle.h"
#include "Item.h"



Puzzle::Puzzle(std::string description) {
    this->description = description;
}


Puzzle::~Puzzle() {}

bool Puzzle::wasSolved() const {
    return solved;
}

std::string Puzzle::toString() {
    std::ostringstream stringReader;
    stringReader << description;
    return stringReader.str();
}

//-------------------------------------------------------------


DialoguePuzzle::DialoguePuzzle(std::string description,
                        std::string expectedInput)
                        : Puzzle(description), expectedInput(expectedInput) {
                            this->expectedInput = expectedInput;
                            }


DialoguePuzzle::~DialoguePuzzle() {
}

void DialoguePuzzle::getInput(std::string answer) {
    if (answer == expectedInput) {
        std::cout << "Correct!\n";
        solved = true;
    } else {
        std::cout << "Incorrect.\n";
    }
}

ItemPuzzle::ItemPuzzle(std::string description, const Item &item) :
                Puzzle(description) {
                    expectedItem = new Item(item);
}

ItemPuzzle::~ItemPuzzle() {
}

std::string ItemPuzzle::getExpectedItemName() {
    return expectedItem->getName();
}

void ItemPuzzle::checkItem(const Item &item) {
    if (expectedItem->equals(item)) {
        std::cout << "Correct!\n";
        solved = true;
        } else {
            std::cout << "Incorrect.\n";
    }
}
