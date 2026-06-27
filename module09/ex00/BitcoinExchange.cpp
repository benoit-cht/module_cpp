/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ton_utilisateur_42 <ton_email@student.42.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:29:45 by ton_utilisate     #+#    #+#             */
/*   Updated: 2025/11/21 09:29:48 by ton_utilisate    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ========================================================================== */
/*                             CLASS AFILE                                    */
/* ========================================================================== */

/*                        ~~ Constructeur/Destructeur ~~                      */

AFile::AFile( void ) 
{
  std::cout << "default constructor of AFile" << std::endl;
  
  setFile(PATH);
  if ( !_file.is_open())  {
    
    throw ErrorOpenFileException();
  }
  std::cout << " file is open " << std::endl;

}

AFile::AFile(std::string path) {

  std::cout << "constructor of AFile witch path" << std::endl;
  
  setFile(path);
  if( !_file.is_open())  {
    
    throw ErrorOpenFileException();
  }
  std::cout << " file is open " << std::endl;

}

AFile::~AFile( void )  {

  std::cout << "Call destructor file status: ";

  _file.close();
  if (_file.is_open())  {

    std::cout << "Error close file" << std::endl;

  } else  {

    std::cout << "file is close" << std::endl;

  }

}

/*                               ~~ other Methode ~~                          */

static bool checkDate(std::string& str)  {

  return(true);
}

static bool checkRate(std::string& str)  {
  
  char	*end;
  double	doub;
  std::string rate;

  size_t pos = str.find(',');
  if(pos == std::string::npos)  {

    return(false);
  }
  rate = str.substr(pos + 1,str.length());
  //std::cout << rate << std::endl;
	doub = strtod(str.c_str(), &end);
  if ( !rate.length() || *end != '\0' && (doub < 0 || doub > __INT_MAX__)) {

      return(false);
  }
  return(true);
}

bool    AFile::checkLine(std::string& str)  {

  if (!checkDate(str) || !checkRate(str)) {

    throw ErrorBadLineException();
  }

  return(true);
}


bool    AFile::parseFile( void )  {

  std::string line;

  std::getline(getFile(), line);
  if (line != "date,exchange_rate")  {
    
    throw ErrorBadLineException();
  }

  while (std::getline(getFile(), line))
  {
    checkLine(line);
  }
  //std::getline(getFile(), line);
  //checkLine(line);
  std::cout << "line: " << line << std::endl;

  return ( true );
}

/*                                ~~ get Methode ~~                           */

/*double          AFile::getExchangeRate(const std::string& date) const {


}*/

std::string     AFile::getPath(void) const { return( _path ); }

std::ifstream&   AFile::getFile( void ) {return( _file );}


/*                                ~~ set Methode ~~                           */

/*void    AFile::setMapFile( void ) {

    
}*/

void AFile::setFile(std::string path) {

    _path = path;
 
    _file.open(path, std::ios::in);
    if (!_file.is_open()) {

      throw ErrorOpenFileException();
    }
}

void    AFile::setPath(std::string path)  { 

  _path = path;
}

/*                                ~~ Exception ~~                             */

const char* AFile::ErrorOpenFileException::what() const throw() {
  
  return ("open file failure !");
}

const char* AFile::ErrorBadLineException::what() const throw()  {

  return ("line in the file wrong format !");
}

const char* AFile::ErrorFindLineException::what() const throw() {

  return ("Non-existent or incorrectly written line !");
}

/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */

DataFile::DataFile():AFile() {}
DataFile::DataFile(std::string path):AFile(path) {}
DataFile::~DataFile(){}

bool    DataFile::parseFile( void )  {

  std::string line;

  std::getline(getFile(), line);
  if (line != "date,exchange_rate")  {
    
    throw ErrorBadLineException();
  }

  while (std::getline(getFile(), line))
  {
    checkLine(line);
  }
  //std::getline(getFile(), line);
  //checkLine(line);
  std::cout << "data line: " << line << std::endl;

  return ( true );
}

void DataFile::setPath(std::string path)
{ AFile::setPath(path);}

/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */

InputFile::InputFile(std::string path):AFile(path){}
InputFile::~InputFile(){}
bool    InputFile::parseFile( void )  {

  std::string line;

  while (std::getline(getFile(), line))
  {
    checkLine(line);
  }
  //std::getline(getFile(), line);
  //checkLine(line);
  std::cout << "data line: " << line << std::endl;

  return ( true );
}

void InputFile::setPath(std::string path)
{ AFile::setPath(path);}
