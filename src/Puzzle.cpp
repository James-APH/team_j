/**
 * @author James Huston [jamzhuston@gmail.com]
 * @date 11/2023 12/2023
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
                        : Puzzle(description) {
                            this->expectedInput = expectedInput;
                            }

DialoguePuzzle::DialoguePuzzle(const DialoguePuzzle& dialoguePuzzle) {
    this->description = dialoguePuzzle.description;
    this->expectedInput = dialoguePuzzle.expectedInput;
}

DialoguePuzzle::~DialoguePuzzle() {}

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

ItemPuzzle::ItemPuzzle(const ItemPuzzle& itemPuzzle) {
    this->description = itemPuzzle.description;
    this->expectedItem = new Item(*itemPuzzle.expectedItem);
}


ItemPuzzle::~ItemPuzzle() {
    delete expectedItem;
}

std::string ItemPuzzle::getExpectedItemName() const {
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
