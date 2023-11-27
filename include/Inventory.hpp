/* @Author: James Huston | jamzhuston@gmail.com
*  Created: 10/30/2023
*
*/

#ifndef INVENTORY.HPP
#define INVENTORY.HPP

#include <iostream>
#include <vector>

#include "Item.hpp"


class Inventory {
  public:

  Inventory();


  Inventory(std::vector<Item> itemList);


  void Inspect(std::string itemName);


  void addItem(std::string itemName);


  void deleteItem(std::string itemName);


  bool hasItem(std::string itemName);


  Item& getItem(std::string itemName);

  
  private:
  std::vector<Item> itemList;
  int size;

  std::toString();

  void addItemDescription(std::string fileName);


};

#endif
