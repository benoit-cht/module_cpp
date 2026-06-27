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

  char *endA;
  char *endM;
  char *endD;
  double	doub;
  std::string date;
  std::string year;
  std::string moth;
  std::string day;
  
  std::cout << str << std::endl;
  size_t pos = str.find(',');
  if(pos == std::string::npos)  {

    return(false);
  }
  date = str.substr( 0, pos - 1);
  std::cout << date << std::endl;

  size_t posFT = date.find_first_of('-');
  if(pos == std::string::npos)  {

    return(false);
  }
  year = str.substr( 0, posFT);
  std::cout << year << std::endl;
  doub = strtod(year.c_str(), &endA);
  if ( !year.length() || *endA != '\0' && (doub < 0 || doub > __INT_MAX__) && doub < 2000 || doub > 2026) {

      return(false);
  }

  moth = str.substr( posFT + 1, posFT - 2);
  std::cout << moth << std::endl;
  doub = strtod(moth.c_str(), &endM);
  if ( !moth.length() || *endM != '\0' && (doub < 0 || doub > __INT_MAX__) && doub < 1 || doub > 12) {

      return(false);
  }

  day = str.substr( posFT + 4, posFT - 2);
  std::cout << day << std::endl;
  doub = strtod(day.c_str(), &endD);
  if ( !year.length() || *endD != '\0' && (doub < 0 || doub > __INT_MAX__) && doub < 1 || doub > 31) {

      return(false);
  }
	
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

  if (!checkDate(str)){// || !checkRate(str)) {

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

void    AFile::setMapFile( void ) {
 
  char         *end;
  double      doub;
  std::string date;
  std::string line;
  std::string rate;

  while (std::getline(getFile(), line))
  {
    size_t pos = line.find(',');
    rate = line.substr(pos + 1, line.length());
	  doub = strtod(rate.c_str(), &end);

    date = line.substr( 0, pos);
    std::cout << date <<": " << doub << "  ->" <<line << std::endl;
    _mapFile[date] = doub;

    std::cout << _mapFile["2022-03-29"] <<  "test " << std::endl;
  }


    
}

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
  std::cout << "input line: " << line << std::endl;

  return ( true );
}

void InputFile::setPath(std::string path)
{ AFile::setPath(path);}
