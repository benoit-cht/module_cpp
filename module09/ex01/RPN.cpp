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

/*                             ~~ CANONIC FORM ~~                             */

RPN::RPN(void)  {

  //std::cout << "Call Constructeurs" << std::endl;
}

RPN::~RPN(void) {

  //std::cout << "Call Destructeur" << std::endl;
}

RPN::RPN(const RPN& other) : _stack(other._stack) {

  //std::cout << " call constructeur of copy" << std::endl;
}

RPN& RPN::operator=(const RPN& other) {

    if (this != &other) _stack = other._stack;

    return( *this );
}

/*                             ~~ -- ~~                                     */

static bool isOperator(const std::string& token) {

    return ( token == "+" || token == "-" || token == "*" || token == "/" );
}

// Vérifie si un token est un nombre valide
static bool isNumber(const std::string& token) {

    size_t i = 0;

    if (token.empty())  {

      return( false );
    }
    if (token[0] == '-')  {

        if (token.size() == 1)  {

          return( false );
        }
        i = 1;
    }
    while (i < token.size())
    {

        if (!std::isdigit(static_cast<unsigned char>(token[i])))  {
 
          return( false);
        }
        i++;
    }
    return( true );
}

void RPN::setStack(const std::string& input) {

    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        if (isNumber(token)) {
            
          _stack.push(std::atoi(token.c_str()));
        } else if (isOperator(token)) {
            
          if (_stack.size() < 2) throw invalidExpressionException();
          int b = _stack.top(); _stack.pop();
          int a = _stack.top(); _stack.pop();
          if (token == "+") {

            _stack.push(a + b);
          
          } else if (token == "-") {

            _stack.push(a - b);
          
          } else if (token == "*") {

            _stack.push(a * b);
          
          } else if (token == "/") {
            
            if (b == 0) throw divisionByZeroException();
            
            _stack.push(a / b);
          }
        } else {
     
          throw badCharacterException();
        }
    }

    if (_stack.size() != 1) {

        throw invalidExpressionException();
    }
}

int RPN::evaluate( void ) {

    if (_stack.empty()) {
    
      throw invalidExpressionException();
    }
    return( _stack.top() );
}

/*                             ~~ EXCEPTION ~~                             */

const char* RPN::divisionByZeroException::what() const throw()  {
    
    return( "" );                           //"Division by zero";
}

const char* RPN::badCharacterException::what() const throw()  {

    return( "" );                         //"Invalid character in input";
}
const char* RPN::invalidExpressionException::what() const throw() {

    return( "" );                       //"Invalid RPN expression";
}

/* ====================================================================== */
/*                                                                        */
/* ====================================================================== */
