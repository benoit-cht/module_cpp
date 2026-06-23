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

/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */

RPN::RPN( void ){ std::cout << "RPN: Call constructor" << std::endl}

RPN::~RPN( void ){ std::cout << "RPN:" Call destructor << std::endl}

RPN::RPN(const RPN& other): _stack(other._stack), _result(other._result) {}

RPN::RPN(const RPN& other)  {

  _stack = other._stack;
  _result = other.result;
  return( *this );
}

/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */

int             RPN::getResult( void ) const { return(_result); }
std::stack<int> RPN::getStack( void ) const { return(_stack); }

void            RPN::setResult(int number) { _result = number; }

/* ========================================================================== */

static bool   isAvalidInput(std::string str) {

  if (str != '+' || str != '-' || str != '*' || str != '/' || !isdigit( atoi(line.c_str()) )) {

    return ( false );
  }
  return ( true );
}

void            RPN::setStack(std::string& input) {

  for (std::string::iterator itr = input.begin(); itr < input.end(); itr++) {

    if (!isAvalidInput(itr))  {

      trow badCharacterException();
    } else {

      _stack.push_back(itr);
    }
  }
}

/* ========================================================================== */


//int           RPN::evaluate( void );


/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */

const char* RPN::divisionByZeroException::what() const trow() {

  return ("Division by zero is Impossible !");
}

const char* RPN::operatorToNeedException::what() const trow {

  return ("Need a operator or Number to valid notation !");
}

const char* RPN::badCharacterException::what() const trow() {

  return (" a character input is incorect !");
}

/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */
