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

RPN::RPN( void ){ /*std::cout << "RPN: Call constructor" << std::endl;*/ }

RPN::~RPN( void ){ /*std::cout << "RPN: Call destructor" << std::endl;*/ }

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

static bool isSpace(const char* c)  {

  return (*c == ' ');
}

static bool isOperator(const char* c)  { 

    return (*c == '+' || *c == '-' || *c == '*' || *c == '/');
}

static bool isDigit(const char* c) {

    return std::isdigit(static_cast<unsigned char>(*c));
}

void    RPN::setStack(std::string& input) {
  
  
  //for (size_t itr = input.size() - 1; itr <= 0; itr--) {
  for (int itr = input.size() - 1; itr != -1; itr--) {
    
    if ( !isOperator(&input[itr] ) && !isDigit(&input[itr]) && !isSpace(&input[itr]) )  {

      throw badCharacterException();

    }else if (isDigit(&input[itr]))  {
      
        std::string op(1, input[itr]);
        _stack.push(op);

    }else if (isOperator(&input[itr])) {

      std::string op(1, input[itr]);
      _stack.push(op);
    }
    //std::cout << "top = " << _stack.top() << std::endl;
  }
  

}

/* ========================================================================== */

int     RPN::microCalculator(int& value1, int& value2, std::string& ope)  {

  if (ope == "*") {
  
    _stack.push(std::to_string(value1 * value2));
  }
  else if (ope == "+") {
 
    _stack.push(std::to_string(value1 + value2));
  }
  else if (ope == "-"){

    _stack.push(std::to_string(value1 - value2));
  }
  else if (ope == "/")  {
    
    if (value2 == 0)
      throw divisionByZeroException();
    
    _stack.push(std::to_string(value1 / value2));
  }

  value1  = -1;
  value2  = -1;
  ope     = "";
  return (1);

}

int     RPN::calculator( void ) {

  int         number_1 = -1 ;
  int         number_2 = -1 ;
  std::string operation = "";

  //std::cout << "init-> "<< number_1 << operation << number_2 << _stack.size() << ":" <<_stack.top() << std::endl;
  if (_stack.size() == 0)
    throw operatorToNeedException();
  for (size_t itr = (_stack.size() * 4)-1; itr != 0; itr--)  { // rique de arret une iteration trop tot 
      
      //std::cout << itr << "-> "<< number_1 << operation << number_2 << std::endl;
      if ( number_1 != -1 && number_2 != -1 && operation != "" ) {

          RPN::microCalculator(number_1, number_2, operation);
          //std::cout << "stack.top = "<<_stack.top() << std::endl;

      } else if ( !_stack.empty() && isDigit(_stack.top().c_str()) && number_1 == -1) {

          number_1 = atoi(_stack.top().c_str());  
          if  ( number_1 < 0 ) throw negativeNumberForibenException();
          _stack.pop();
      
      } else if ( !_stack.empty() && isDigit(_stack.top().c_str()) && number_2 == -1) {

          number_2 = atoi(_stack.top().c_str());
          if  ( number_2 < 0 ) throw negativeNumberForibenException();
          _stack.pop();

      } else if (!_stack.empty() && isOperator(_stack.top().c_str()) && operation == "") {

          operation = _stack.top();
          _stack.pop();

      } else if (!_stack.empty() && number_1 != -1 && number_2 != -1 && isDigit(_stack.top().c_str()) ) {

          throw operatorToNeedException();

      } else if ((number_1 == -1 || number_2 == -1) && operation != "" ) {
          
          throw operatorToNeedException();
      }
  }
  

  _stack.push(std::to_string(number_1));
  if (!_stack.empty())
    std::cout <<_stack.top() << std::endl;
  return (0);
}
/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */

const char* RPN::divisionByZeroException::what() const throw() {

  return ("");//"Division by zero is Impossible !");
}

const char* RPN::operatorToNeedException::what() const throw() {

  return ("");//"Need a operator or Number to valid notation !");
}

const char* RPN::badCharacterException::what() const throw() {

  return ("");//" a character input is incorect !");
}

const char* RPN::negativeNumberForibenException::what() const throw() {

  return ("");//" a negative number is foriben !");
}
/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */
