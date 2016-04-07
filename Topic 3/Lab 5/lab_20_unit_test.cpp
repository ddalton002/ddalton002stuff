/*
 * Name        : lab_20_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #20 Functionality
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// For NULL
#include <cstddef>
#include <sstream>

#include "sl_list.h"
// To test for Header guards
#include "sl_list.h"
#include "sl_node.h"
#include "sl_node.h"

TEST_CASE("Default Constructor for SLNode") {
  SLNode node, node2;
  SLNode* p_node2 = &node2;
  SECTION("Accessor for Contents") {
    CHECK(node.contents() == 0);
  }

  SECTION("Accessor for Next Node") {
    CHECK(node.next_node() == NULL);
  }

  SECTION("Mutator for Contents") {
    node.set_contents(100);
    CHECK(node.contents() == 100);
  }

  SECTION("Mutator for Next Node") {
    node.set_next_node(&node2);
    CHECK(node.next_node() == p_node2);
  }
}

TEST_CASE("Overloaded Constructor for SLNode") {
  SLNode node(1), node2;
  SLNode* p_node2 = &node2;
  SECTION("Accessor for Contents") {
    CHECK(node.contents() == 1);
  }

  SECTION("Accessor for Next Node") {
    CHECK(node.next_node() == NULL);
  }

  SECTION("Mutator for Contents") {
    node.set_contents(100);
    CHECK(node.contents() == 100);
  }

  SECTION("Mutator for Next Node") {
    node.set_next_node(&node2);
    CHECK(node.next_node() == p_node2);
  }
}

TEST_CASE("Testing Pointers for SLNode") {
  SLNode* node = new SLNode(1);
  SLNode* node2 = new SLNode();
  node->set_next_node(node2);
  node2->set_next_node(node);
  // node and node2 now connect each to the other -- not something you should
  // ever do outside of a testing situation
  SECTION("Node 1 Points to Node 2") {
    CHECK(node->next_node() == node2);
  }

  SECTION("Node 2 Points to Node 1") {
    CHECK(node2->next_node() == node);
  }

  SECTION("Node 1 Points to NULL") {
    node->set_next_node(NULL);
    CHECK(node->next_node() == NULL);
  }

  SECTION("Node 2 Points to NULL") {
    node2->set_next_node(NULL);
    CHECK(node2->next_node() == NULL);
  }
}


TEST_CASE("Default Constructor for SLList") {
  SLList list;
  SECTION("Accessor for Size") {
    CHECK(list.size() == 0);
  }

  SECTION("ToString()") {
    CHECK(list.ToString() == "");
  }

  SECTION("GetHead()") {
    CHECK(list.GetHead() == 0);
  }

  SECTION("GetTail()") {
    CHECK(list.GetTail() == 0);
  }

  SECTION("RemoveFirstOccurence(0) on an Empty List") {
    list.RemoveFirstOccurence(0);
    CHECK(list.size() == 0);
    CHECK(list.ToString() == "");
  }
}

TEST_CASE("Building your Linked List") {
  SLList list;
  list.Insert(10);
  SECTION("Insert(10) (As the first Node)") {
    CHECK(list.size() == 1);
    CHECK(list.ToString() == "10");
    CHECK(list.GetHead() == 10);
    CHECK(list.GetTail() == 10);
  }

  list.Insert(50);
  SECTION("Insert(50) (As the last Node)") {
    CHECK(list.size() == 2);
    CHECK(list.ToString() == "10, 50");
    CHECK(list.GetHead() == 10);
    CHECK(list.GetTail() == 50);
  }

  list.Insert(30);
  SECTION("Insert(30) (As the middle Node)") {
    CHECK(list.size() == 3);
    CHECK(list.ToString() == "10, 30, 50");
    CHECK(list.GetHead() == 10);
    CHECK(list.GetTail() == 50);
  }

  list.Insert(5);
  SECTION("Insert(5) (As the first Node)") {
    CHECK(list.size() == 4);
    CHECK(list.ToString() == "5, 10, 30, 50");
    CHECK(list.GetHead() == 5);
    CHECK(list.GetTail() == 50);
  }

  list.Insert(55);
  SECTION("Insert(55) (As the last Node)") {
    CHECK(list.size() == 5);
    CHECK(list.ToString() == "5, 10, 30, 50, 55");
    CHECK(list.GetHead() == 5);
    CHECK(list.GetTail() == 55);
  }

  list.Insert(20);
  SECTION("Insert(20) (As the third (middle) Node)") {
    CHECK(list.size() == 6);
    CHECK(list.ToString() == "5, 10, 20, 30, 50, 55");
    CHECK(list.GetHead() == 5);
    CHECK(list.GetTail() == 55);
  }

  list.Insert(40);
  SECTION("Insert(40) (As the fifth (middle) Node)") {
    CHECK(list.size() == 7);
    CHECK(list.ToString() == "5, 10, 20, 30, 40, 50, 55");
    CHECK(list.GetHead() == 5);
    CHECK(list.GetTail() == 55);
  }

  list.Insert(30);
  SECTION("Insert(40) (As the third/fourth (middle) Node)") {
    CHECK(list.size() == 8);
    CHECK(list.ToString() == "5, 10, 20, 30, 30, 40, 50, 55");
    CHECK(list.GetHead() == 5);
    CHECK(list.GetTail() == 55);
  }

  list.Insert(5);
  SECTION("Insert(5) (As the first/second Node)") {
    CHECK(list.size() == 9);
    CHECK(list.ToString() == "5, 5, 10, 20, 30, 30, 40, 50, 55");
    CHECK(list.GetHead() == 5);
    CHECK(list.GetTail() == 55);
  }

  list.Insert(55);
  SECTION("Insert(55) (As the last/second to last Node)") {
    CHECK(list.size() == 10);
    CHECK(list.ToString() == "5, 5, 10, 20, 30, 30, 40, 50, 55, 55");
    CHECK(list.GetHead() == 5);
    CHECK(list.GetTail() == 55);
  }

  SECTION("RemoveFirstOccurence(1)") {
    CHECK(list.RemoveFirstOccurence(1) == false);
  }

  bool result = false;
  result = list.RemoveFirstOccurence(5);
  SECTION("RemoveFirstOccurence(5) (Front of the list)") {
    CHECK(result == true);
    CHECK(list.size() == 9);
    CHECK(list.ToString() == "5, 10, 20, 30, 30, 40, 50, 55, 55");
    CHECK(list.GetHead() == 5);
    CHECK(list.GetTail() == 55);
  }

  result = false;
  result = list.RemoveFirstOccurence(30);
  SECTION("RemoveFirstOccurence(30) (Middle of the list)") {
    CHECK(result == true);
    CHECK(list.size() == 8);
    CHECK(list.ToString() == "5, 10, 20, 30, 40, 50, 55, 55");
    CHECK(list.GetHead() == 5);
    CHECK(list.GetTail() == 55);
  }

  result = false;
  result = list.RemoveFirstOccurence(30);
  SECTION("RemoveFirstOccurence(30) (Middle of the list)") {
    CHECK(result == true);
    CHECK(list.size() == 7);
    CHECK(list.ToString() == "5, 10, 20, 40, 50, 55, 55");
    CHECK(list.GetHead() == 5);
    CHECK(list.GetTail() == 55);
  }

  result = false;
  result = list.RemoveFirstOccurence(55);
  SECTION("RemoveFirstOccurence(55) (Last/Second to Last of the list)") {
    CHECK(result == true);
    CHECK(list.size() == 6);
    CHECK(list.ToString() == "5, 10, 20, 40, 50, 55");
    CHECK(list.GetHead() == 5);
    CHECK(list.GetTail() == 55);
  }

  result = false;
  result = list.RemoveFirstOccurence(55);
  SECTION("RemoveFirstOccurence(55) (Last Node in the list)") {
    CHECK(result == true);
    CHECK(list.size() == 5);
    CHECK(list.ToString() == "5, 10, 20, 40, 50");
    CHECK(list.GetHead() == 5);
    CHECK(list.GetTail() == 50);
  }

  result = false;
  result = list.RemoveFirstOccurence(10);
  SECTION("RemoveFirstOccurence(10) (Middle of the list)") {
    CHECK(result == true);
    CHECK(list.size() == 4);
    CHECK(list.ToString() == "5, 20, 40, 50");
    CHECK(list.GetHead() == 5);
    CHECK(list.GetTail() == 50);
  }

  list.Clear();
  SECTION("Clear()") {
    CHECK(list.size() == 0);
    CHECK(list.ToString() == "");
    CHECK(list.GetHead() == 0);
    CHECK(list.GetTail() == 0);
  }

  std::stringstream full_head_list, half_head_list, full_tail_list,
      half_tail_list;
  int count = -1;
  for (int i = 0; i < 999; i++) {
    if (i % 100 == 0)
      count++;
    full_head_list << count << ", ";
  }
  full_head_list << 9;

  count = -1;
  for (int i = 0; i < 499; i++) {
    if (i % 50 == 0)
      count++;
    half_head_list << count << ", ";
  }
  half_head_list << 9;

  for (unsigned int i = 0; i < 1000; i++) {
    list.Insert(i % 10);
  }
  SECTION("Insert() \"HIGH LOAD\"") {
    CHECK(list.size() == 1000);
    CHECK(list.ToString() == full_head_list.str());
  }

  for (unsigned int i = 0; i < 500; i++) {
    list.RemoveFirstOccurence(i % 10);
  }
  SECTION("RemoveFirstOccurence() \"HIGH LOAD\" 1/2") {
    CHECK(list.size() == 500);
    CHECK(list.ToString() == half_head_list.str());
  }

  for (unsigned int i = 0; i < 600; i++) {
    list.RemoveFirstOccurence(i % 10);
  }
  SECTION("RemoveFirstOccurence() \"HIGH LOAD\" 2/2") {
    CHECK(list.size() == 0);
    CHECK(list.ToString() == "");
  }
}
