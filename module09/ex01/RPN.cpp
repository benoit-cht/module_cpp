/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ton_utilisateur_42 <ton_email@student.42.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:24:32 by ton_utilisate     #+#    #+#             */
/*   Updated: 2025/11/21 09:24:36 by ton_utilisate    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */

RPN::RPN( void ){ std::cout << "RPN: Call constructor" << std::endl; }

RPN::~RPN( void ){ std::cout << "RPN: Call destructor" << std::endl; }

RPN::RPN(const RPN& other): _stack(other._stack), _result(other._result) {}

RPN& RPN::operator=(const RPN& other)  {

  _stack = other._stack;
  _result = other._result;
  return( *this );
}

/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */

int                     RPN::getResult( void ) const { return(_result); }
std::stack<std::string> RPN::getStack( void ) const { return(_stack); }

void            RPN::setResult(int number) { _result = number; }

/* ========================================================================== */
/*
static bool   isAvalidInput(std::string str) {

  if (str != "+" || str != "-" || str != "*" || str != "/" || !std::isdigit( std::atoi(str.c_str()) )) {

    return ( false );
  }
  return ( true );
}
*/
static bool isOperator(char c)  {

    return (c == ' ' || c == '+' || c == '-' || c == '*' || c == '/');
}

static bool isDigit(char c) {

    return std::isdigit(static_cast<unsigned char>(c));
}

void            RPN::setStack(std::string& input) {

  for (std::string::iterator itr = input.begin(); itr < input.end(); itr++) {

    if ( !isOperator(*itr) && !isDigit(*itr))  {

      throw badCharacterException();
    } else {
      
      std::string pop(1, *itr);
      _stack.push(pop);
    }
  }
}

/* ========================================================================== */


//int           RPN::evaluate( void );


/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */

const char* RPN::divisionByZeroException::what() const throw() {

  return ("Division by zero is Impossible !");
}

const char* RPN::operatorToNeedException::what() const throw() {

  return ("Need a operator or Number to valid notation !");
}

const char* RPN::badCharacterException::what() const throw() {

  return (" a character input is incorect !");
}

/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */
