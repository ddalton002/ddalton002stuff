/*
 * Name        : lab_19_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #19 Functionality
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

  SECTION("RemoveHead() on an Empty List") {
    list.RemoveHead();
    CHECK(list.size() == 0);
    CHECK(list.ToString() == "");
  }

  SECTION("RemoveTail() on an Empty List") {
    list.RemoveTail();
    CHECK(list.size() == 0);
    CHECK(list.ToString() == "");
  }
}

TEST_CASE("Building your Linked List") {
  SLList list;
  list.InsertHead(1);
  SECTION("InsertHead(1)") {
    CHECK(list.size() == 1);
    CHECK(list.ToString() == "1");
  }

  list.RemoveHead();
  SECTION("RemoveHead()") {
    CHECK(list.size() == 0);
    CHECK(list.ToString() == "");
  }

  list.InsertTail(5);
  SECTION("InsertTail(5)") {
    CHECK(list.size() == 1);
    CHECK(list.ToString() == "5");
  }

  list.RemoveTail();
  SECTION("RemoveTail()") {
    CHECK(list.size() == 0);
    CHECK(list.ToString() == "");
  }

  SECTION("InsertHead(1) && RemoveTail()") {
    list.InsertHead(1);
    list.RemoveTail();
    CHECK(list.size() == 0);
    CHECK(list.ToString() == "");
  }

  SECTION("InsertTail(1) && RemoveHead()") {
    list.InsertTail(1);
    list.RemoveHead();
    CHECK(list.size() == 0);
    CHECK(list.ToString() == "");
  }

  list.InsertHead(10), list.InsertHead(20);
  SECTION("InsertHead(10), InsertHead(20)") {
    CHECK(list.size() == 2);
    CHECK(list.ToString() == "20, 10");
  }

  list.RemoveHead();
  SECTION("RemoveHead()") {
    CHECK(list.size() == 1);
    CHECK(list.ToString() == "10");
  }

  list.InsertHead(20);
  list.RemoveTail();
  SECTION("InsertHead(20) && RemoveTail()") {
    CHECK(list.size() == 1);
    CHECK(list.ToString() == "20");
  }

  list.InsertHead(5);
  SECTION("InsertHead(5)") {
    CHECK(list.size() == 2);
    CHECK(list.ToString() == "5, 20");
  }

  list.Clear();
  SECTION("Clear()") {
    CHECK(list.size() == 0);
    CHECK(list.ToString() == "");
  }

  list.InsertHead(10);
  list.InsertHead(5);
  list.InsertTail(20);
  list.InsertTail(25);
  SECTION("InsertHead(10), InsertHead(5), InsertTail(20), InsertTail(25)") {
    CHECK(list.size() == 4);
    CHECK(list.ToString() == "5, 10, 20, 25");
  }

  SECTION("GetHead()") {
    CHECK(list.GetHead() == 5);
  }

  SECTION("GetTail()") {
    CHECK(list.GetTail() == 25);
  }

  list.RemoveHead();
  list.RemoveTail();
  list.RemoveHead();
  list.RemoveTail();
  SECTION("RemoveHead(), RemoveTail(), RemoveHead(), RemoveTail()") {
    CHECK(list.size() == 0);
    CHECK(list.ToString() == "");
  }

  std::stringstream full_head_list, half_head_list, full_tail_list,
      half_tail_list;
  for (int i = 999; i > 0; i--) {
    full_head_list << i << ", ";
    if (i < 500)
      half_head_list << i << ", ";
  }
  full_head_list << 0;
  half_head_list << 0;

  for (int i = 0; i < 999; i++) {
    full_tail_list << i << ", ";
    if (i < 499)
      half_tail_list << i << ", ";
  }
  full_tail_list << 999;
  half_tail_list << 499;

  for (unsigned int i = 0; i < 1000; i++)
    list.InsertHead(i);
  SECTION("InsertHead() \"HIGH LOAD\"") {
    CHECK(list.size() == 1000);
    CHECK(list.ToString() == full_head_list.str());
  }

  for (unsigned int i = 0; i < 500; i++) {
    list.RemoveHead();
  }
  SECTION("RemoveHead() \"HIGH LOAD\" 1/2") {
    CHECK(list.size() == 500);
    CHECK(list.ToString() == half_head_list.str());
  }

  for (unsigned int i = 0; i < 600; i++) {
    list.RemoveHead();
  }
  SECTION("RemoveHead() \"HIGH LOAD\" 2/2") {
    CHECK(list.size() == 0);
    CHECK(list.ToString() == "");
  }

  for (unsigned int i = 0; i < 1000; i++)
    list.InsertTail(i);
  SECTION("InsertTail() \"HIGH LOAD\"") {
    CHECK(list.size() == 1000);
    CHECK(list.ToString() == full_tail_list.str());
  }

  for (unsigned int i = 0; i < 500; i++) {
    list.RemoveTail();
  }
  SECTION("RemoveTail() \"HIGH LOAD\" 1/2") {
    CHECK(list.size() == 500);
    CHECK(list.ToString() == half_tail_list.str());
  }

  for (unsigned int i = 0; i < 600; i++) {
    list.RemoveTail();
  }
  SECTION("RemoveTail() \"HIGH LOAD\" 2/2") {
    CHECK(list.size() == 0);
    CHECK(list.ToString() == "");
  }
}
