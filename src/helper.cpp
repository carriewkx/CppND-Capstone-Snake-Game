#include <iostream>
#include <string>
#include "helper.h"


void Helper::ReadUserInput(double &diff_num){
  std::string diffculity;
  std::cout << "Please pick a difficulty (1:Easy, 2:Medium, 3:Hard):\n"; 
  std::cin >> diffculity; 
  std::cout << diffculity<<"\n";
  while(!(diffculity=="1" || diffculity=="2" || diffculity=="3")){
      std::cout << "Please input correct input (1:Easy, 2:Medium, 3:Hard):\n"; 
      std::cin >> diffculity; 
  };
  if(diffculity=="1"){
    diff_num = 0.0;
  }
  else if(diffculity =="2"){
    diff_num = 0.05;
  }
  else if(diffculity=="3"){
    diff_num = 0.1;
  }
  else{
    diff_num = 0;
  }
  return;
}