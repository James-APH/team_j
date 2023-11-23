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
  Item();

  Item(std::string name, std::string fileName);

  template<class T>
  virtual ostream& createOstream(ostream& out, const T&);
  
  void setDescription();

  virtual void inspectItem();

  protected:
  std::string name;
  std::string description;
};


class clueItem : Item {
  public:

  clueItem();

  ostream& createOstream(ostream& out, const clueItem&);

  friend ostream& operator<<(ostream& os, const clueItem&);

  void inspectItem();  
};

class secretItem : Item {
  public:

  clueItem();

  ostream& createOstream(ostream& out, const secretItem&);

  friend ostream& operator<<(ostream& os, const secretItem&);

  void inspectItem();
};

#endif
