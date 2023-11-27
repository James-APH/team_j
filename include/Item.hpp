/* @Authors - James Huston | jamzhuston@gmail.com |
 *          - 
 *          -
 * Created 10/30/2023
 *
*/

#ifndef ITEM.HPP
#define ITEM.HPP

#include <iostream>
#include <string>
#include <fstream>


/**
 * @class Item in Item.hpp "Item.hpp"
 * @brief Abstract superclass for different item types:
 */ 
class Item {
  public:
  /**
  * @brief Default Constructor
  */
  Item();

  /**
  * @brief Constructor initializes name, and image of item
  * @ param[in] name the name of the item
  * @ param[in] itemImage the name of the itemImage file
  */
  Item(std::string name, std::string itemImage);

  /**
  * @brief Default Destructor
  */
  virtual ~Item();

  


  virtual void setDescription();

  /**
  * @brief shows the image of the item;
  */
  virtual void inspectItem();

  protected:
  std::string name;
  std::string description;
};


/**
 * @class ClueItem in Item.hpp "Item.hpp"
 * @brief Item type for hints and evidence
 * related to solving the murder in the game.
 */
class ClueItem : Item {
  public:
  /**
  * @brief Default Constructor
  */
  ClueItem();
  
  /**
  * @brief Default Destructor
  */
  ~SecretItem();
  
  /**
   *
   *
   */
  void toString();

  /**
  * @brief
  *
  */
  void getDescription();

  /**
  * @brief
  *
  */
  void inspectItem();  
};


/**
 * @class SecretItem in Item.hpp "Item.hpp"
 * @brief Item type for secrets not related 
 * to finishing the game
 */
class SecretItem : Item {
  public:

  SecretItem();

  ~SecretItem();

  ostream& createOstream(ostream& out, const SecretItem&);

  friend ostream& operator<<(ostream& os, const SecretItem&);

  void setDescription();

  void inspectItem();
};

#endif
