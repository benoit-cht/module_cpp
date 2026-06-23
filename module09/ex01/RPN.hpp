/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ton_utilisateur_42 <ton_email@student.42.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:24:42 by ton_utilisate     #+#    #+#             */
/*   Updated: 2025/11/21 09:24:44 by ton_utilisate    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <stack>

class RPN {

  public:
    RPN( void );
    RPN(const RPN& other) const;
    RPN(const RPN& other) const;
    ~RPM( void );

  public:
    int                     getResulte( void ) const;
    std::stack<std::string> getStack( void ) const

  public:
    void          setResulte(int number);
    void          setStack(std::string& input);
  
  public:
    int           evaluate( void );

  public:
    class divisionByZeroException : public std::exception {

      const char* what() const trow();
    };

    class operatorToNeedException : public std::exception {

      const char* what() const trow();
    };

    class badCharacterException : public std::exception {

      const char* what() const trow();
    };
      
  private:
    int                     _result;
    std::stack<std::string> _stack;
};


/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */
