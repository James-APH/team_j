/**
 * @author James Huston [huston@uleth.ca]
 * @date 11/2023 12/2023
 */

#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <string>
#include <list>

#include "Item.h"

/**
 * @class Character in character.h "character.h"
 * @brief superclass for different character types
 */
class Character {
 public:
  /**
  * @brief constructor
  * @param [in] name the name of the character
  * @throw bad_input if name is empty
  */
  Character(std::string name = "anonymous");


  virtual std::string getName();

  /**
  * @brief destructor
  */
  virtual ~Character();

 protected:
  std::string name;
  std::string dialogue;
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
  virtual ~NPC();

  /**
  * @brief outputs all attributes of a character
  */
  void display() const;
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
  Player(std::string name, const Item& item);

  /**
  * @brief destructor
  */
  virtual ~Player();

  /**
  * @brief function to allow user to pickUp items
  * from ground and NPC's
  * @param [in] &item the item that is being picked up
  * @throw bad_input if the item reference is a
  * nullptr
  */
  void pickUp(const Item& item);

  /**
   * @brief function to allow user to drop items
   * @param [in] name the name of the item that 
   * the user would like to drop
   * @throw bad_input if the name is empty
   */
  void drop();

  /**
   * 
   * 
   * 
  */
  void InspectItem() const;

  /**
   * 
   * 
   * 
  */
  void listInventory() const;


  /**
   * @brief function to allow the user to use an item
   * 
   * 
  */
  Item* useItem();

 private:
  std::list<Item*> itemList;

  /**
   * 
   * 
  */
  bool findItem(const Item& item) const;


  /**
   * 
   * 
  */
  bool findItem(std::string itemName) const;
};

#endif
