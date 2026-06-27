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
#include <string>
#include <exception>
#include <stack>

class RPN {

  public:
    RPN( void );
    RPN(const RPN& other) ;
    RPN& operator=(const RPN& other) ;
    virtual ~RPN( void );

  public:
    int                     getResult( void ) const;
    std::stack<std::string> getStack( void ) const ;

  public:
    void          setResult(int number);
    void          setStack(std::string& input);
  
  public:
    int           calculator( void );
    int           microCalculator(int& value1, int& value2, std::string& ope);

  public:
    class divisionByZeroException : public std::exception {

      const char* what() const throw();
    };

    class operatorToNeedException : public std::exception {

      const char* what() const throw();
    };

    class badCharacterException : public std::exception {

      const char* what() const throw();
    };
    
    class negativeNumberForibenException : public std::exception {

      const char* what() const throw();
    };

  private:
    int                     _result;
    std::stack<std::string> _stack;
};


/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */
