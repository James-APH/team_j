/**
* @Author James Huston [huston@uleth.ca]
* @date 2023-11
*/

#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <string>

#include "Item.h"
#include "Inventory.h"
/**
 * @class Character in character.h "character.h"
 * @brief superclass for different character types
 */
class Character {
 public:
  /**
   * @brief default constructor
   */
  Character();

  /**
  * @brief constructor
  * @param [in] name the name of the character
  * @throw bad_input if name is empty
  */
  Character(std::string name);



  virtual std::string getName();

  /**
  * @brief destructor
  */
  virtual ~Character();

  /**
  * @brief outputs all attributes of a character
  */
  virtual void display() = 0;

 protected:
  std::string name;
  std::string dialogue;

  /**
  * @brief puts all of the information from
  * character into a string
  */
  virtual std::string toString() = 0;
};

/**
 * @class NPC in character.h "character.h"
 * @brief class for npc character type
 */
class NPC : public Character {
 public:
  /**
  * @brief constructor
  * @param [in] name the name of the NPC
  * @param [in] &item an item the NPC is holding
  * @throw bad_input if name is empty
  * @throw bad_input if the item is a nullptr
  */
  NPC(std::string name, std::string dialogue);

  /**
   * @brief copy constructor
   * @param [in] fella the npc that is being copied
  */
  NPC(const NPC &fella);

  /**
  * @brief destructor
  */
  ~NPC();


  /**
  * @brief outputs all attributes of a character
  */
  void display();


 private:
  /**
  * @brief puts all of the information from
  * character into a string
  */
  std::string toString();
};

/**
 * @class Player in character.h "character.h"
 * @brief class for player character type
 */
class Player : public Character {
 public:
  /**
  * @brief constructor
  * @param [in] name the name of the character
  * @throw bad_input if name is empty
  */
  Player(std::string name);

  /**
  * @brief destructor
  */
  ~Player();

  /**
  * @brief function to allow user to pickUp items
  * from ground and NPC's
  * @param [in] &item the item that is being picked up
  * @throw bad_input if the item reference is a
  * nullptr
  */
  void pickUp(const Item &item);

  /**
   * @brief function to allow user to drop items
   * @param [in] name the name of the item that 
   * the user would like to drop
   * @throw bad_input if the name is empty
   */
  void drop(std::string name);

  /**
   * @brief function to allow the user to use an item
   * 
   * 
  */
  Item& useItem();

  /**
  * @brief outputs all attributes of a character
  */
  void display();

 private:
  Inventory* inventory;

};

#endif
