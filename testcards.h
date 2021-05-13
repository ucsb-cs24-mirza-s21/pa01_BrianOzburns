// testcards.h
//Authors: Brian Ozawa Burns, 05/09/2021
//All test declarations go here

// This is not exhaustive list of tests. You can remove / edit tests if it doesn't suit your design but you should definitelty add more
// You should test all possible cornere cases of your public functions

#ifndef TESTCARDS_H
#define TESTCARDS_H

#include <iostream>

using namespace std;
void runAll();
void test_constructors();
void test_copy_constructor();
void test_copy_assignment();

void test_equal();
void test_card();


void test_destructor();
void test_destructor_no_elements();
void test_destructor_one_element();
void test_destructor_more_than_one_element();


void test_remove();
void test_remove_no_card();
void test_remove_first_card();
void test_remove_last_card();
void test_remove_middle_card();
void test_remove_nonexisting_card();


void test_match_functions();
void test_isMatch();
void test_there_is_a_match();
void test_there_is_no_match();
void test_findMatch();
void test_there_is_a_match_to_find();
void test_there_is_no_match_to_find();


void test_search();


void test_append();
void test_append_empty_list(); // A test case for append
void test_append_single_element_list(); // Tests cases should be independent,
            // small, fast, orthogonal
void test_append_multi_element_list();
void test_equal_empty_list();
void test_card_operator_double_equal();


void START_TEST(string testname){
  cout<<"_____START "<<testname<<"_____"<<endl;
}

void END_TEST(string testname) {
  cout<<"_____END "<<testname<<"_____"<<endl<<endl;
}

void assertEquals(string expected, string actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(int expected, int actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(Hand *expected, Hand *actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

/*
void assertEquals(Hand::Card *expected, Hand::Card *actual, string testDescription){
  if ( (expected->suit == actual->suit) && (expected->rank == actual->rank) ){
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}
*/


#endif
