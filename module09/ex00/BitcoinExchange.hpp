/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ton_utilisateur_42 <ton_email@student.42.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:29:55 by ton_utilisate     #+#    #+#             */
/*   Updated: 2025/11/21 09:29:56 by ton_utilisate    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HTTP_INCLUDED
#define BITCOINEXCHANGE_HTTP_INCLUDED

#define PATH "data.csv"

#include <iostream>
#include <fstream> 
#include <map>
#include <string>
#include <exception>
#include <algorithm>
#include <cctype>

class AFile  {

  public:
    AFile( void );
    AFile(std::string path);
    virtual ~AFile( void );

  public:
    int     openFile( void );
    bool    parseFile( void );
    bool    checkLine(std::string& str);

  public:
    double          getExchangeRate(const std::string& date) const;
    std::string     getPath(void) const ;
    const std::ifstream&   getFile( void ) const ;

  public:
    void            setMapFile( void );
    void            setFile(std::string path);
    virtual void    setPath(std::string path) = 0;
  
  public:
    class ErrorOpenFileException : public std::exception  {

      const char* what() const throw();
    };

    class ErrorBadLineException : public std::exception  {

      const char* what() const throw();
    };

    class ErrorFindLineException : public std::exception  {

      const char* what() const throw();
    };


  protected:
    std::ifstream                 _file;
    std::string                   _path;
    std::map<std::string, double> _mapFile;

};

class DataFile: public AFile {

  public:
    DataFile( void );
    DataFile(std::string path);
    virtual ~DataFile( void );
    virtual void    setPath(std::string path);
    bool    parseFile( void );

};

class InputFile: public AFile {

  public:
    InputFile( void );
    InputFile(std::string path);
    virtual ~InputFile( void );
    virtual void    setPath(std::string path);
    bool    parseFile( void );

  public:
    void  be_calculator_value(std::string& input, DataFile& data);

};

class BitcoinExchange {
  
  public:
    BitcoinExchange( void );
    virtual ~BitcoinExchange( void );

  private:
    DataFile  _dataFile;
    InputFile _inputFile;

};

#endif // !BITCOINEXCHANGE_HTTP_INCLUDED

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

