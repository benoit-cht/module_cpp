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


#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>

class RPN {
public:
    RPN(void);
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    virtual ~RPN(void);

    void setStack(const std::string& input);
    int evaluate(void);

    class divisionByZeroException : public std::exception {
        const char* what() const throw();
    };
    class badCharacterException : public std::exception {
        const char* what() const throw();
    };
    class invalidExpressionException : public std::exception {
        const char* what() const throw();
    };

private:
    std::stack<int> _stack;  // Pile de int, pas de string
};

#endif

/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */
