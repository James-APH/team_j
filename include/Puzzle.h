/* @Authors - James Huston | jamzhuston@gmail.com |
 *          - 
 *          -
 * Created 10/30/2023
 *
*/


#ifndef PUZZLE_H_INCLUDED
#define PUZZLE_H_INCLUDED

#include <iostream>
#include <string>

#include "Item.h"
/**
 * @class Puzzle in Puzzle.h "Puzzle.h"
 * @brief Abstract superclass for different puzzle types
 */
class Puzzle {
 public:
  /**
  * @brief default constructor 
  */
  Puzzle();

  /**
  * @brief default constructor
  * @param [in] description the description of the puzzle
  */
  Puzzle(std::string description);

  /**
  * @brief destructor
  */
  virtual ~Puzzle();

  /**
  * @brief getter for solved
  * @return true if puzzle is solved, false otherwise
  */
  virtual bool wasSolved() = 0;

  /**
  * @brief display all details of the puzzle
  */
  virtual void display() = 0;

 private:
  std::string description;
  bool solved;

  /**
  * @brief creates string of all attributes of the puzzle
  * return string string of all attributes of the puzzle
  */
  virtual std::string toString() = 0;
};


/**
 * @class DialoguePuzzle in Puzzle.h "Puzzle.h"
 * @brief derived class of Puzzle, for puzzles that require
 * dialogue answers
 */
class DialoguePuzzle : Puzzle {
 public:
  /**
  * @brief constructor
  * @param [in] description the description of the puzzle
  * @param [in] expectedInput the input required to solve the
  * puzzle
  * @param [in] attemptLimit the amount of attempts allowed
  * to solve a puzzle.
  * @throw bad_input if description string is empty
  * @throw bad_input if expectedInput string is empty
  * @throw bad_input if attemptLimit is less than or
  * equal to zero.
  */
  DialoguePuzzle(std::string description
               , std::string expectedInput);

  /**
  * @brief gets the input from the user to compare with expectedInput
  * @detail gets the input from the user, checks if the user
  * still has attempts left, if they do increase the attempts by one
  * and compares their answer to the expectedInput, sets the variable 
  * solved accordingly.
  * @param[in] answer the users answer to the puzzle
  */
  void getInput(std::string answer);

  /**
  * @brief destructor
  */
  ~DialoguePuzzle();

  /*
  * @brief getter for solved variable
  * @return true if puzzle was solved, false otherwise
  */
  bool wasSolved();

  /*
  * @brief function to display puzzle information
  */
  void display();

 private:
  std::string expectedInput;

  /*
  * @brief function to check if the user still has attempts
  * left.
  * @return true if the user has attempts left, false otherwise
  */
  bool hasAttempts();

  /*
  * @brief function to convert all of the puzzle attributes into
  * a string
  * @return string string of all puzzle attributes
  */
  std::string toString();
};

/**
 * @class ItemPuzzle in Puzzle.h "Puzzle.h"
 * @brief derived class of Puzzle for puzzles that require
 * Items to solve them.
 */
class ItemPuzzle : Puzzle {
 public:
  /**
  * @brief default constructor
  * @param [in] description the description of the
  * puzzle
  * @param [in] item the item needed to solve the
  * puzzle
  * @throw bad_input if item is nullptr
  */
  ItemPuzzle(std::string description, const Item &item);

  /**
  * @brief destructor for ItemPuzzle
  */
  ~ItemPuzzle();

  /**
  * @brief checks if the item the user uses
  * solves the puzzle.
  * @param [in] item the item that the user enters
  * @detail if the item is correct solved will be
  * set to true and the item will be removed from 
  * the players inventory
  */
  void checkItem(const Item &item);

  /**
  * @brief getter for solved
  * @return true if puzzle was solved false otherwise
  */
  bool wasSolved();

  /**
  * @brief displays the information about the puzzle
  */
  void display();

 private:
  Item* expectedItem;

  /**
  * @brief puts all of the puzzle information into a string
  * @return string string of puzzle information
  */
  std::string toString();
};

#endif
