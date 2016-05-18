/*
 * Name        : lab_27_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #27 Functionality
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
using std::cout;
using std::endl;
#include "lab_27.h"

TEST_CASE("Treasure Chest Default Constructor") {
  TreasureChest chest;
  SECTION("GetSize()") {
    CHECK(chest.GetSize() == 0);
  }

  SECTION("Empty()") {
    CHECK(chest.Empty() == true);
  }

  SECTION("GetItem(0)") {
    CHECK(chest.GetItem(0) == NULL);
  }

  SECTION("RemoveItem(0)") {
    try {
      chest.RemoveItem(0);
      CHECK(false);
    } catch (string &s) {
      CHECK(s == "ERROR: Remove at invalid position");
    }
  }

  SECTION("ToString()") {
    CHECK(chest.ToString() == "Chest Empty!");
  }
  cout << "Chest Contents: " << chest << endl << endl;
}

TEST_CASE("Adding to the Chest") {
  TreasureChest chest;
  Item item;
  Item testItems[5] = { Item("ruby", 100, 1), Item("gold", 5, 100), Item(
      "emerald", 50, 2), Item("silver", 2, 200), Item() };

  chest.AddItem(testItems[0]);
  SECTION("AddItem(ruby)") {
    CHECK(chest.GetSize() == 1);
    CHECK(chest.Empty() == false);
    CHECK(chest.ToString() == "ruby");
  }
  cout << "Chest Contents: " << chest << endl << endl;

  chest.AddItem(testItems[1]);
  SECTION("AddItem(gold)") {
    CHECK(chest.GetSize() == 2);
    CHECK(chest.Empty() == false);
    CHECK(chest.ToString() == "ruby, gold");
  }
  cout << "Chest Contents: " << chest << endl << endl;

  chest.InsertItem(testItems[2], 1);
  SECTION("InsertItem(emerald, 1)") {
    CHECK(chest.GetSize() == 3);
    CHECK(chest.Empty() == false);
    CHECK(chest.ToString() == "ruby, emerald, gold");
  }
  cout << "Chest Contents: " << chest << endl << endl;

  chest.InsertItem(testItems[3], 2);
  SECTION("InsertItem(silver, 2)") {
    CHECK(chest.GetSize() == 4);
    CHECK(chest.Empty() == false);
    CHECK(chest.ToString() == "ruby, emerald, silver, gold");
  }
  cout << "Chest Contents: " << chest << endl << endl;

  chest.InsertItem(testItems[4], 10);
  SECTION("InsertItem(noname, 10)") {
    CHECK(chest.GetSize() == 5);
    CHECK(chest.Empty() == false);
    CHECK(chest.ToString() == "ruby, emerald, silver, gold, noname");
  }
  cout << "Chest Contents: " << chest << endl << endl;

  item = chest.RemoveItem(0);
  SECTION("RemoveItem(0)") {
    CHECK(item.name_ == "ruby");
    CHECK(item.value_ == 100);
    CHECK(item.quantity_ == 1);
    CHECK(chest.GetSize() == 4);
    CHECK(chest.Empty() == false);
    CHECK(chest.ToString() == "emerald, silver, gold, noname");
  }
  cout << "Chest Contents: " << chest << endl << endl;

  item = chest.RemoveItem(3);
  SECTION("RemoveItem(3)") {
    CHECK(item.name_ == "noname");
    CHECK(item.value_ == 0);
    CHECK(item.quantity_ == 0);
    CHECK(chest.GetSize() == 3);
    CHECK(chest.Empty() == false);
    CHECK(chest.ToString() == "emerald, silver, gold");
  }
  cout << "Chest Contents: " << chest << endl << endl;

  SECTION("RemoveItem(3)") {
    try {
      chest.RemoveItem(3);
      CHECK(false);
    } catch (string &s) {
      CHECK(s == "ERROR: Remove at invalid position");
    }
  }

  chest.Clear();
  SECTION("Clear()") {
    CHECK(chest.GetSize() == 0);
    CHECK(chest.Empty() == true);
    CHECK(chest.GetItem(0) == NULL);
    CHECK(chest.ToString() == "Chest Empty!");
  }

  for (unsigned int i = 0; i < 5; i++)
    chest.AddItem(testItems[i]);
  SECTION("Adding 5 Items") {
    CHECK(chest.GetSize() == 5);
    CHECK(chest.Empty() == false);
    CHECK(chest.ToString() == "ruby, gold, emerald, silver, noname");
  }
  cout << "Chest Contents: " << chest << endl << endl;

  chest.SortByName();
  SECTION("SortByName()") {
    CHECK(chest.GetSize() == 5);
    CHECK(chest.Empty() == false);
    CHECK(chest.ToString() == "emerald, gold, noname, ruby, silver");
  }
  cout << "Chest Contents: " << chest << endl << endl;

  const Item* ptr_item = chest.GetItem(0);
  SECTION("GetItem(0)") {
    CHECK(ptr_item->name_ == "emerald");
    CHECK(ptr_item->quantity_ == 2);
    CHECK(ptr_item->value_ == 50);
  }

  chest.SortByValue();
  SECTION("SortByValue()") {
    CHECK(chest.GetSize() == 5);
    CHECK(chest.Empty() == false);
    CHECK(chest.ToString() == "noname, silver, gold, emerald, ruby");
  }
  cout << "Chest Contents: " << chest << endl << endl;

  ptr_item = chest.GetItem(0);
  SECTION("GetItem(0)") {
    CHECK(ptr_item->name_ == "noname");
    CHECK(ptr_item->quantity_ == 0);
    CHECK(ptr_item->value_ == 0);
  }

  chest.SortByQuantity();
  SECTION("SortByQuantity()") {
    CHECK(chest.GetSize() == 5);
    CHECK(chest.Empty() == false);
    CHECK(chest.ToString() == "noname, ruby, emerald, gold, silver");
  }
  cout << "Chest Contents: " << chest << endl << endl;

  ptr_item = chest.GetItem(4);
  SECTION("GetItem(4)") {
    CHECK(ptr_item->name_ == "silver");
    CHECK(ptr_item->quantity_ == 200);
    CHECK(ptr_item->value_ == 2);
  }

  ptr_item = chest.GetItem(5);
  SECTION("GetItem(5)") {
    CHECK(ptr_item == NULL);
  }
}
