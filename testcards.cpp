// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>




int main(){



  Hand goodHand {"Tiger Woods"};
  goodHand.appendCard('h', 10);
  goodHand.appendCard('h', 'k');
  goodHand.appendCard('c', 5);
  goodHand.appendCard('s', 5);
  goodHand.appendCard('d', 5);

  Hand badHand;
  badHand = goodHand;
  badHand.setPlayerName("Sam Jackson");
  badHand.printCards();

  cout << endl;

  goodHand.printCards();

  cout << endl << endl;

  
  badHand.removeCard('c', 5);
  badHand.removeCard('d', 5);
  badHand.removeCard('h', 10);
  
  
  badHand.getPrevCard('d', 5);/////
  badHand.getPrevCard('s', 5);
  badHand.getPrevCard('c', 5);/////
  badHand.getPrevCard('h', 10);
  badHand.getPrevCard('h', 10);/////
  

  badHand.printCards();
  goodHand.displayMatch(badHand);
  goodHand.displayMatch(badHand);
  goodHand.displayMatch(badHand);
  goodHand.displayMatch(badHand);
  goodHand.displayMatch(badHand);

  
  //runAll();
  return 0;
}

/*
void runAll(){
  test_append();
  test_equal();
  test_card();
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_append");

}

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  //test_equal_single_element_list();
  END_TEST("test_equal");

}

void test_card(){
  START_TEST("test_card");
  test_card_operator_double_equal();
  //test_equal_single_element_list();
  END_TEST("test_card");
}


void test_append_empty_list(){ 
// A test case for append single card node to LinkedList
  //Hand amazingHand;
  //amazingHand.appendCard('h', 13)
}

void test_append_single_element_list(){ 
  // Tests cases should be independent,
    // small, fast, orthogonal (test for different cases)

}
void test_equal_empty_list(){ 
  string testname = "case 0: [], []";
  LinkedList l1, l2;
  assertEquals(l1.head,l2.head);
}

void test_card_operator_double_equal(){
  // Test to check if == is overloaded for card
}



*/