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

/*                                ~~ get Methode ~~                           */

/*double          AFile::getExchangeRate(const std::string& date) const {


}*/

std::string     AFile::getPath(void) const { return( _path ); }

std::ofstream&   AFile::getFile( void ) {return( _file );}


/*                                ~~ set Methode ~~                           */

/*void    AFile::setMapFile( void ) {

    
}*/

//void    AFile::setFile(const char* path)  { _file = std::ofstream file(path) }
void AFile::setFile(std::string path) {
    _path = path; // Met à jour _path
    _file.open(path, std::ios::in); // Ouvre le fichier
    if (!_file.is_open()) {
        throw ErrorOpenFileException();
    }
}
void    AFile::setPath(std::string path)  { _path = path;}

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

void DataFile::setPath(std::string path)
{ AFile::setPath(path);}

InputFile::InputFile(std::string path):AFile(path){}
InputFile::~InputFile(){}

void InputFile::setPath(std::string path)
{ AFile::setPath(path);}
