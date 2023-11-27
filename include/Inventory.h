/* @Author: James Huston | jamzhuston@gmail.com
*  Created: 10/30/2023
*
*/

#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

#include "Item.h"

/**
* @class Inventory in Inventory.h "Inventory.h"
* @brief class for monitoring and maintaining the items
* any user has access to.
*/
class Inventory {
 public:
  /**
  * @brief default constructor
  */
  Inventory();

  /**
  * @brief construction from vector
  */
  Inventory(std::vector<Item> itemList);

  /**
  * @brief destructor
  */
  ~Inventory();

  /**
  * @brief outputs the description of one item
  * @param[in] itemName the name of the item
  */
  void Inspect(std::string itemName);

  /**
  * @brief allows user to accept items from npcs and take items from rooms
  * @param[in] itemName the name of the item
  */
  void addItem(std::string itemName);

  /**
  * @brief removes item from list
  * @param[in] itemName the name of the item
  */
  void deleteItem(std::string itemName);

  /**
  * @brief checks if item exists in list
  * @param[in] itemName the name of the item
  * @return true if item is in list false otherwise
  */
  bool hasItem(std::string itemName);


  /**
  * @brief returns an item that exists in the list
  * @param[in] itemName the name of the item
  * @return A reference to an item
  */
  Item& getItem(std::string itemName);

  /**
  * @brief outputs the information created in
  * the toString function.
  */
  void display();


 private:
  std::vector<Item> itemList;
  int size;

  /**
  * @brief creates a string formatted to list
  * all the items in inventory in a nice way
  * @return string, string of items
  */
  std::string toString();

  /**
  * @brief adds a description to a newly added item
  */
  void addItemDescription(std::string fileName);
};

#endif
