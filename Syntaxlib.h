#ifndef SYNTAXLIB_H
#define SYNTAXLIB_H

<<<<<<< HEAD
using namespace std;

#include "Tokenlib.h"

template <class T, int max_size > class stack{
	T s[max_size];
	int top;
public:
	stack(){top = 0;}
	void reset() { top = 0; }
	void push(T i);
	T pop();
	bool is_empty(){ return top == 0; }
	bool is_full() { return top == max_size; }
};

template <class T, int max_size >
void stack <T, max_size >::push(T i){
	if ( !is_full() ){
		s[top] = i;
		++top;
	}
	else
		throw "Stack_is_full";
	}
template <class T, int max_size >
T stack <T, max_size >::pop(){
	if ( !is_empty() ){
		--top;
		return s[top];
	}
	else
		throw "Stack_is_empty";
}	
=======
#include "interpretlib.h"	
#include <stack>

using namespace std;
struct error_msg{
	string message;
	Lexem error_lex;
	error_msg(string msg,Lexem& er_l){
		message=msg;
		error_lex=er_l;
	}
};
>>>>>>> 0bd43bae762e9a9c6bf26f932c1ff743a7ac05df

class Parser{
	Lexem current_lexem;
	int cur_value;
	Scanner scan;
	stack<int,10> st_int;
	stack<type_of_lexem,10> st_lex;

	//procedures of recursive descent parser//
	void sentence(); //syntax
	void function();
	void operat();
	void block();
	void var_definition();
	void expression();
	void simple_expression();
	void prefix();
	void infix();
	void condition();
	void cycle();
	void transition();

	void dec (type_of_lexem type); //semantic
	void check_id ();
	void check_op ();
	void eq_type ();
	void eq_bool ();
	// void check_id_in_read ();

 public:
 	int cur_string_number;
 	type_of_lexem cur_type;
	void get_lexem(){
		current_lexem = scan.get_lex(&cur_string_number);
		cur_type = current_lexem.get_type();
		cur_value = current_lexem.get_value();
	}
<<<<<<< HEAD
	// Poliz prog;
 	Parser(const char* program): scan(program) {}
=======

 	Parser(const char* program):scan(program){
 		cur_string_number=0;
 	}
>>>>>>> 0bd43bae762e9a9c6bf26f932c1ff743a7ac05df
 	void analyze();
};
#endif