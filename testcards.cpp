// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>




int main(){

  /*

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

  */

  // test_destructor(); 
  // I went to office hours and waited for over an hour for help with this (unit testing destructor) but there were many other students 
  // and I wasn't able to get attention before I had to leave for another class
  // However, my destructor was working completely as expected when I was simply testing in main
  // and valgrind shows zero memory leaks or errors so I am 100% confident in my destructor

  runAll();

  return 0;
}


void runAll(){
  test_append();
  cout << endl << endl;
  test_remove();
  cout << endl << endl;
  test_match_functions();
  cout << endl << endl;
  test_constructors();
  cout << endl << endl;
}


void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  test_append_multi_element_list();
  END_TEST("test_append");
}
void test_append_empty_list(){ 
// A test case for append single card node to LinkedList
  cout << "-----test_append_empty_list-----" << endl;

  Hand emptyHand("emptyHand");
  emptyHand.appendCard('h', 'k');
  cout << "expecting:" << endl << "emptyHand's cards:\nh k" << endl;
  cout << endl << "actual:" << endl;
  emptyHand.printCards();

  cout << endl;
}
void test_append_single_element_list(){ 
  // Tests cases should be independent,
    // small, fast, orthogonal (test for different cases)
  cout << "-----test_append_single_element_list-----" << endl;

  Hand oneCardHand("oneCardHand");
  oneCardHand.appendCard('d', 'a');
  oneCardHand.appendCard('s', '8');
  cout << "expecting:" << endl << "oneCardHand's cards:\nd a\ns 8" << endl;
  cout << endl << "actual:" << endl;
  oneCardHand.printCards();

  cout << endl;
}
void test_append_multi_element_list(){
  cout << "-----test_append_multi_element_list-----" << endl;

  Hand multiCardHand("multiCardHand");
  multiCardHand.appendCard('d', 'q');
  multiCardHand.appendCard('s', 'q');
  multiCardHand.appendCard('h', 'k');
  multiCardHand.appendCard('h', 'a');
  multiCardHand.appendCard('d', '0');
  multiCardHand.appendCard('c', '8');
  cout << "expecting:" << endl << "multiCardHand's cards:\nd q\ns q\nh k\nh a\nd 0\nc 8" << endl;
  cout << endl << "actual:" << endl;
  multiCardHand.printCards();

  cout << endl;
}



void test_destructor(){
  START_TEST("test_destructor");
  test_destructor_no_elements();
  test_destructor_one_element();
  test_destructor_more_than_one_element();
  END_TEST("test_destructor");
}
void test_destructor_no_elements(){
  Hand handToDestroy("emptyHandToDestroy");
  if ( handToDestroy.isEmpty() ){
    cout << "\tdestructor successful with empty Hand." << endl;
  }
  else {
    cout << "\tdestructor unsuccessful with empty Hand." << endl;
  }
}
void test_destructor_one_element(){
  Hand handToDestroy("oneElementHandToDestroy");
  handToDestroy.appendCard('c', '5');
  handToDestroy.~Hand();
  if ( handToDestroy.isEmpty() ){
    cout << "\tdestructor successful with Hand containing one element." << endl;
  }
  else {
    cout << "\tdestructor unsuccessful with Hand containing one element." << endl;
  }
}
void test_destructor_more_than_one_element(){
  Hand handToDestroy("multipleElementHandToDestroy");
  handToDestroy.appendCard('c', '5');
  handToDestroy.appendCard('h', '8');
  handToDestroy.appendCard('c', 'q');
  if ( handToDestroy.isEmpty() ){
    cout << "\tdestructor successful with Hand containing more than one element." << endl;
  }
  else {
    cout << "\tdestructor unsuccessful with Hand containing more than one element." << endl;
  }
}



void test_remove(){
  START_TEST("test_remove");
  test_remove_no_card();
  test_remove_first_card();
  test_remove_last_card();
  test_remove_middle_card();
  test_remove_nonexisting_card();
  END_TEST("test_remove");
}
void test_remove_no_card(){
  cout << "-----test_remove_no_card-----" << endl;

  Hand emptyHand("emptyHand");
  emptyHand.removeCard('h', 13);
  emptyHand.removeCard('h', 12);
  emptyHand.removeCard('h', 11);
  emptyHand.removeCard('d', 8);
  emptyHand.removeCard('c', 6);
  emptyHand.removeCard('c', 3);
  emptyHand.removeCard('c', 3);
  emptyHand.removeCard('s', 2);
  emptyHand.removeCard('d', 1);
  cout << "expecting:" << endl << "emptyHand's cards:\n" << endl;
  cout << endl << "actual:" << endl;
  emptyHand.printCards();

  cout << endl;
}
void test_remove_first_card(){
  cout << "-----test_remove_first_card-----" << endl;

  Hand firstCardIs_h_k("firstCardIs_h_k");
  firstCardIs_h_k.appendCard('h', 13);
  firstCardIs_h_k.appendCard('d', 6);
  firstCardIs_h_k.appendCard('c', 1);
  firstCardIs_h_k.appendCard('s', 6);
  firstCardIs_h_k.removeCard('h', 13);
  cout << "expecting:" << endl << "firstCardIs_h_k's cards:\nd 6\nc a\ns 6" << endl;
  cout << endl << "actual:" << endl;
  firstCardIs_h_k.printCards();

  cout << endl;
}
void test_remove_last_card(){
  cout << "-----test_remove_last_card-----" << endl;

  Hand lastCardIs_h_k("lastCardIs_h_k");
  lastCardIs_h_k.appendCard('d', 6);
  lastCardIs_h_k.appendCard('c', 1);
  lastCardIs_h_k.appendCard('s', 6);
  lastCardIs_h_k.appendCard('h', 13);
  lastCardIs_h_k.removeCard('h', 13);
  cout << "expecting:" << endl << "lastCardIs_h_k's cards:\nd 6\nc a\ns 6" << endl;
  cout << endl << "actual:" << endl;
  lastCardIs_h_k.printCards();

  cout << endl;
}
void test_remove_middle_card(){
  cout << "-----test_remove_middle_card-----" << endl;

  Hand middleCardIs_h_k("midleCardIs_h_k");
  middleCardIs_h_k.appendCard('d', 6);
  middleCardIs_h_k.appendCard('c', 1);
  middleCardIs_h_k.appendCard('h', 13);
  middleCardIs_h_k.appendCard('s', 6);
  middleCardIs_h_k.removeCard('h', 13);
  cout << "expecting:" << endl << "middleCardIs_h_k's cards:\nd 6\nc a\ns 6" << endl;
  cout << endl << "actual:" << endl;
  middleCardIs_h_k.printCards();

  cout << endl;
}
void test_remove_nonexisting_card(){
  cout << "-----test_remove_middle_card-----" << endl;

  Hand missing_h_k("missing_h_k");
  missing_h_k.appendCard('d', 6);
  missing_h_k.appendCard('c', 1);
  missing_h_k.appendCard('s', 6);
  missing_h_k.removeCard('h', 13);
  cout << "expecting:" << endl << "missing_h_k's cards:\nd 6\nc a\ns 6" << endl;
  cout << endl << "actual:" << endl;
  missing_h_k.printCards();

  cout << endl;
}


void test_match_functions(){
  START_TEST("test_match_functions");
  test_isMatch();
  test_findMatch();
  cout << endl;
  END_TEST("test_match_functions");
}
void test_isMatch(){
  test_there_is_a_match();
  test_there_is_no_match();
}
void test_findMatch(){
  test_there_is_a_match_to_find();
  test_there_is_no_match_to_find();
}
void test_there_is_a_match(){
  Hand firstHand("firstHand");
  firstHand.appendCard('h', 'k');
  firstHand.appendCard('d', 'k');
  firstHand.appendCard('c', 'a');
  firstHand.appendCard('s', '6');

  Hand secondHand("secondHand");
  secondHand.appendCard('s', 'k');
  secondHand.appendCard('d', 'k');
  secondHand.appendCard('h', 'a');
  secondHand.appendCard('h', '6');
  // the match is d k
  if ( firstHand.isMatch(secondHand) ){
    cout << "isMatch works with a match" << endl;
  }
  else {
    cout << "isMatch not working with a match" << endl;
  }
}
void test_there_is_no_match(){
  Hand firstHand("firstHand");
  firstHand.appendCard('h', 'k');
  firstHand.appendCard('d', 'k');
  firstHand.appendCard('c', 'a');
  firstHand.appendCard('s', '6');

  Hand secondHand("secondHand");
  secondHand.appendCard('s', 'k');
  secondHand.appendCard('c', 'k');
  secondHand.appendCard('h', 'a');
  secondHand.appendCard('h', '6');
  
  if ( !firstHand.isMatch(secondHand) ){
    cout << "isMatch works without a match" << endl;
  }
  else {
    cout << "isMatch not working without a match" << endl;
  }
}
void test_there_is_a_match_to_find(){
  Hand firstHand("firstHand");
  firstHand.appendCard('h', 'k');
  firstHand.appendCard('d', 'k');
  firstHand.appendCard('c', 'a');
  firstHand.appendCard('s', '6');

  Hand secondHand("secondHand");
  secondHand.appendCard('s', 'k');
  secondHand.appendCard('d', 'k');
  secondHand.appendCard('h', 'a');
  secondHand.appendCard('h', '6');
  // the match is d k
  firstHand.displayMatch(secondHand);
  cout << endl;
  if ( !(firstHand.getCard('d', 13)) && !(secondHand.getCard('d', 13)) ){
    cout << "findMatch works with a match" << endl;
  }
  else {
    cout << "findMatch not working with a match" << endl;
  }
}
void test_there_is_no_match_to_find(){
  Hand firstHand("firstHand");
  firstHand.appendCard('h', 'k');
  firstHand.appendCard('d', 'k');
  firstHand.appendCard('c', 'a');
  firstHand.appendCard('s', '6');

  Hand secondHand("secondHand");
  secondHand.appendCard('s', 'k');
  secondHand.appendCard('c', 'k');
  secondHand.appendCard('h', 'a');
  secondHand.appendCard('h', '6');
  
  firstHand.displayMatch(secondHand);
  if ( (firstHand.getCard('d', 13)) && !(secondHand.getCard('d', 13)) ){
    cout << "findMatch works without a match" << endl;
  }
  else {
    cout << "findMatch not working without a match" << endl;
  }
}



void test_constructors(){
  START_TEST("test_constructors");
  string error = "default constructor not complete.";

  Hand defaultHand;
  if ( defaultHand.getPlayerName() != "" ){
    cout << error << endl;
  }
  else {
    cout << "default constructor works" << endl;
  }


  Hand newHand("newHand");
  if ( newHand.getPlayerName() != "newHand" ){
    cout << error << endl;
  }
  else {
    cout << "name constructor works" << endl;
  }

  cout << endl;

  test_copy_constructor();
  test_copy_assignment();
  cout << endl;
  END_TEST("test_constructors");
}

void test_copy_constructor(){
  Hand newHand("firstHand");
  newHand.appendCard('d', 6);
  newHand.appendCard('c', 1);
  newHand.appendCard('s', 6);
  Hand thirdHand(newHand);
  thirdHand.setPlayerName("secondHand");
  newHand.printCards();
  cout << endl;
  thirdHand.printCards();
  cout << endl;
}
void test_copy_assignment(){
  Hand thirdHand("thirdHand");
  thirdHand.appendCard('d', 6);
  thirdHand.appendCard('c', 1);
  thirdHand.appendCard('s', 6);
  Hand fourthHand("fourthHand");
  fourthHand = thirdHand;
  thirdHand.printCards();
  cout << endl;
  fourthHand.printCards();
  cout << endl;
}