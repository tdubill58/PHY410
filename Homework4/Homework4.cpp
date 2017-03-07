#include "StudentRecord.h"


StudentRecord::StudentRecord( std::string last , std::string first, float score ) {


  last_ = last; first_ = first; score_ = score;


}







StudentRecord::~StudentRecord(){}







float StudentRecord::score() const { return score_; }







std::string StudentRecord::first() const { return first_; }







std::string StudentRecord::last() const { return last_; }







bool StudentRecord::input ( std::istream & in ) {  


  std::string line;  


  std::getline( in, line, ',');  


  last_ = line;  


  std::getline( in, line, ',');  


  first_ = line;  


  std::getline( in, line );  


  score_ = std::atof( line.c_str() );  


  if ( line == "")     


    return false;  


  else    


    return true;


}

Problem_1.cc


#include <iostream>

#include "StudentRecord.h"

#include <vector>

#include <fstream>

StudentRecord rec;

std::vector<StudentRecord> vec;

float calculate_average( std::vector<StudentRecord> *pvec );

int main(int argc, char * argv[]) {


  std::ifstream in( argv[1] );


  while(rec.input(in)){   

    vec.push_back(rec);


  }

  float average =  calculate_average( &vec);


  std::cout << "Average is: " << average << std::endl;


  return 0;


}







float calculate_average( std::vector<StudentRecord> *pvec ) {


  float avg = 0.0;


  for( unsigned int i = 0; i < pvec->size(); i++ ){


    avg = avg + pvec->at(i).score();   


  }


  


  avg = avg/(pvec->size());


  return avg;

}

Problem2.cc


#include <iostream>

#include "StudentRecord.h"

#include <vector>

#include <fstream>

StudentRecord rec;


std::vector<StudentRecord> vec;







int main(int argc, char * argv[]) {


  std::ifstream in( argv[1] );


  while(rec.input(in)){


    vec.push_back(rec);


  }


  int index = atoi(argv[2]);


  if ( index > vec.size()) {


    std::cout << "Whoah there buddy, there aren't that many kids. There are only " << vec.size() << " members of the record. Try again!" << std::endl;


  } else {


    std::cout << "Full name: " << vec[index].first() << " " <<  vec[index].last() << "\nScore: " << vec[index].score()  << std::endl;


  }


}Header StudentRecord.h
(idk why its so tabbed over)

#ifndef StudentRecord_h

#define StudentRecord_h

#include <iostream>

  class StudentRecord{


  public:


    StudentRecord( std::string first = "" , std::string last = "" , float score = 0.);


    ~StudentRecord();


    float score() const;  


    std::string first() const;


    std::string last() const;


    bool input( std::istream & in );


  private:


    std::string first_;


    std::string last_;


    float score_;

  };


#endif




