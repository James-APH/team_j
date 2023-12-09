/**
 * @author James Huston [huston@uleth.ca]
 * @author Raven Huery [raven.huery@uleth.ca]
 * @author Parker Regier [tyre.regier@uleth.ca]
 * @date 2023-11
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
  * @param [in] dialogue the dialogue of the NPC
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
  * @param [in] item the default starting item of the character
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
  */
  void pickUp(const Item& item);

  /**
   * @brief function to allow user to drop items
   */
  void drop();

  /**
  * @brief function to allow user to inspect a specific item
  */
  void InspectItem() const;

  /**
  * @brief function to allow user to see all of the items in their inventory
  */
  void listInventory() const;


  /**
  * @brief function to allow the user to use an item
  */
  Item* useItem();

 private:
  std::list<Item*> itemList;

  /**
  * @brief function to find if an item is in the player's inventory
  * based off of the name of the item.
  * @param [in] item a refernece to the item
  */
  bool findItem(const Item& item) const;


  /**
  * @brief function to find if an item is in the player's inventory
  * based off of the name of the item.
  * @param [in] itemName the name of the item
  * @throw de_trop_nullptr if itemName is nullptr
  */
  bool findItem(std::string itemName) const;
};

#endif
