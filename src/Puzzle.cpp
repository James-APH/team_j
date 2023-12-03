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

bool Puzzle::wasSolved() const {
    return solved;
}

//-------------------------------------------------------------


DialoguePuzzle::DialoguePuzzle(std::string description, std::string expectedInput)
                        : Puzzle(description), expectedInput(expectedInput){
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

void DialoguePuzzle::display() {
    std::cout << "Puzzle: " << description << "\n";
    std::cout << "Input: " << expectedInput << "\n\n";
}

std::string DialoguePuzzle::toString() {
    return "Puzzle: " + description + "\nInput: " + expectedInput;
}




ItemPuzzle::ItemPuzzle(std::string description, const Item &item) : 
                Puzzle(description) {
                    expectedItem = new Item(item);
}

ItemPuzzle::~ItemPuzzle() {
}

void ItemPuzzle::checkItem(const Item &item) {
    if (expectedItem->equals(item)) {
        std::cout << "Correct!\n";
        solved = true;
        } else {
            std::cout << "Incorrect.\n";
    }
}

void ItemPuzzle::display() {
    std::cout << "Puzzle: " << description << "\n";
    std::cout << "Item: " << expectedItem->getName() << "\n\n";
}

std::string ItemPuzzle::toString() {
    return "Puzzle: " + description + "\nItem: " + expectedItem->getName();
}
