#include <iostream>
#include <string>
#include <list>
 
  using namespace std;
  
  class House {   //Composition
    class Room {
        std::string name;
    public:
        Room(std::string n) : name(n) {}
    };
    std::list<Room*> rooms;
  public:
    void AddRoom(std::string name) {
          rooms.push_back(new Room(name));
      }
    ~House() { 
          for(auto& e: rooms) 
              delete e;
    }
  };
  
  class Student;    //Association
  class College; 
  
  class Student {
      std::list<College*> colleges;
  public:
      void AddCollege(College* college) {
          colleges.push_back(college);
      }
  };
  
  class College {
      std::list<Student*> students;
  public:
      void AddStudent(Student* student) {
          students.push_back(student);
      }
  };
  
  class Duck {};    //Aggregation
  class Pond {
      std::list<Duck> ducks;
  public:
      void AddDuck(Duck duck)
      {
          ducks.push_back(duck);
      }
  };
  
  int main() {
      House myHouse;
      myHouse.AddRoom("kitchen");
      myHouse.AddRoom("dining room");
      myHouse.AddRoom("bedroom");
      myHouse.AddRoom("bathroom");
      myHouse.AddRoom("basement");
      
      College Seneca;
      College Centennial;
      College Sheridan;
      
      Student Tom;
      Student Dick;
      Student Jane;
      Student Mary;
      
      Tom.AddCollege(&Seneca);
      Tom.AddCollege(&Sheridan);

      Seneca.AddStudent(&Tom);
      Sheridan.AddStudent(&Tom);

      Dick.AddCollege(&Seneca);
      Seneca.AddStudent(&Dick);
  
      Jane.AddCollege(&Seneca);
      Seneca.AddStudent(&Jane);
  
      Mary.AddCollege(&Centennial);
      Centennial.AddStudent(&Mary);
      
      Pond golden;
      Pond oxbow;

      Duck donald;
      Duck ronald;
      Duck daffy;
      Duck black;
      Duck bad;
      Duck good;
      Duck evil;
      Duck neutral;

      golden.AddDuck(donald);
      golden.AddDuck(ronald);
      golden.AddDuck(daffy);
      golden.AddDuck(black);
      golden.AddDuck(good);
      golden.AddDuck(neutral);

      oxbow.AddDuck(bad);
      oxbow.AddDuck(evil);
  }
