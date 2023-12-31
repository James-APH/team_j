/**
 * @author James Huston [huston@uleth.ca]
 * @author Raven Huery [raven.huery@uleth.ca]
 * @author Parker Regier [tyre.regier@uleth.ca]
 * @date 2023-11
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
  * @param [in] description the description of the puzzle
  * @throw empty_string is description is an empty string
  */
  Puzzle(std::string description = "No puzzle");

  /**
  * @brief destructor
  */
  virtual ~Puzzle();

  /**
  * @brief getter for solved
  * @return true if puzzle is solved, false otherwise
  */
  bool wasSolved() const;

  /**
  * @brief creates string of all attributes of the puzzle
  * @return string string of all attributes of the puzzle
  */
  std::string toString();

 protected:
  std::string description;
  bool solved;
};


/**
 * @class DialoguePuzzle in Puzzle.h "Puzzle.h"
 * @brief derived class of Puzzle, for puzzles that require
 * dialogue answers
 */
class DialoguePuzzle : public Puzzle {
 public:
  /**
  * @brief constructor
  * @param [in] description the description of the puzzle
  * @param [in] expectedInput the input required to solve the puzzle
  * @throw empty_string if description string is empty
  * @throw empty_string if expectedInput string is empty
  */
  DialoguePuzzle(std::string description
               , std::string expectedInput);

  /**
   * @brief copy constructor
   * @param [in] dp the DialoguePuzzle that is being copied
  */
  DialoguePuzzle(const DialoguePuzzle& dp);

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

 private:
  std::string expectedInput;
};

/**
 * @class ItemPuzzle in Puzzle.h "Puzzle.h"
 * @brief derived class of Puzzle for puzzles that require
 * Items to solve them.
 */
class ItemPuzzle : public Puzzle {
 public:
  /**
  * @brief default constructor
  * @param [in] description the description of the
  * puzzle
  * @param [in] item the item needed to solve the
  * puzzle
  * @throw empty_string if description is an empty string
  */
  ItemPuzzle(std::string description, const Item &item);

  /**
   * @brief copy constructor
   * @param [in] itemPuzzle the itempuzzle being copied
   * 
   */
  ItemPuzzle(const ItemPuzzle& itemPuzzle);

  /**
   * @brief gets the name of the item
  */
  std::string getExpectedItemName() const;


  /**
  * @brief destructor for ItemPuzzle
  */
  ~ItemPuzzle();

  /**
  * @brief checks if the item the user uses
  * solves the puzzle.
  * @param [in] item the item that the user enters
  * @details if the item is correct solved will be
  * set to true and the item will be removed from 
  * the players inventory
  */
  void checkItem(const Item &item);


 private:
  Item* expectedItem;
};

#endif
