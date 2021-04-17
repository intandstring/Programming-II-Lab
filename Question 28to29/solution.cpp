#include <iostream>
using namespace std;

//Q28 
class Set
{
  private:
  	int element[100];
  	int count;

  public:
    Set(){
      for (int i = 0; i < 100; i++){
        element[i] = 0;
      }
      count = 0;
    }

    Set(const Set &s) {
      for(int i = 0; i < 100; i++){
        element[i] = s.element[i];
        count = s.count;
      }
    }

    int add(const int num){
      bool numFound = false;
      int oldCount = count;
      for(int i = 0; i < count; i++){
        if (element[i] == num){
          numFound = true;
          break;
        }
      }
      if(!numFound){
        element[count] = num;
        count++;
      }
      return count - oldCount;
    }

    int add(const Set s){
      bool numFound = false;
      int oldCount = count;
      for(int i = 0; i < s.count; i++){
        for(int j = 0; j < count; j++){
          if (element[j] == s.element[i]){
            numFound = true;
            break;
          }
        }
        if(!numFound){
          element[count] = s.element[i];
          count++;
        }
        numFound = false;
      }
      return count - oldCount;
    }

  	void display()
    {
      int j;
      for(j = 0; j < count; j ++)
        cout<<element[j]<<" ";
    }
    
    //Q29
    Set operator+ (Set s){
      Set combo;
      for(int i = 0; i < count; i++){
        combo.element[i] = element[i];
      }
      combo.count = count;
      combo.add(s);
      return combo;
    }

    Set operator- (Set s){
      int overlap[100] = {0};
      int amount = 0;
      bool isContained = false;
      for(int i = 0; i < count; i++){
        for(int j = 0; j < s.count; j++){
          if(s.element[j] == element[i]){
            isContained = true;
            break;
          }
        }
        if(isContained){
          overlap[amount] = element[i];
          amount++;
        }
      }
      Set intersect;
      for(int i = 0; i < amount; i++){
        intersect.add(overlap[i]);
      }
      intersect.count = amount;
      
      return intersect;
    }
};
