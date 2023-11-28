/* @Authors - James Huston | jamzhuston@gmail.com |
 *          - 
 *          -
 * Created 10/30/2023
 *
*/

#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>


/**
 * @class Item in Item.h "Item.h"
 * @brief Abstract superclass for different item types:
 */ 
class Item {
 public:
  /**
  * @brief Constructor initializes name, and image of item
  * @ param[in] name the name of the item
  * @ param[in] description the description of the item
  */
  Item(std::string name, std::string description);

  /**
  * @brief copy constructor
  * @param[in] item, the item that is being copied
  */
  Item(const Item &item);

  /**
  * @brief Default Destructor
  */
  ~Item();

  /**
  * @brief gets the name of the item
  * @return string the name of the item
  */
  std::string getName();

  /**
  * @brief gets the description of the item
  * @return string the description of the item
  */
  std::string getDescription();

  /**
  * @brief checks if two items are equivalent
  * @return true if the items are equivalent
  */ 
  bool operator==(const Item item&);

 private:
  std::string name;
  std::string description;

  /**
  * @brief puts the information in from item into a string
  * @return string string of item details
  */
  std::string toString();
};

#endif
