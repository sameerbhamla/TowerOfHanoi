#include <iostream>
#include <vector>
using namespace std;

int main() {

  //assembling the three towers
  vector <int> tower[3];

  //Number of rings (Can be changed)
  int n = 6;

  //Candidate is smallest ring that has not been moved
  int candidate;
  int move = 0;
  int to, from;

  bool isOdd, isEven;

  //initializing the three towers
  for(int i = n + 1; i >= 1; i--){
    tower[0].push_back(i);
  }
  tower[1].push_back(n+1);
  tower[2].push_back(n+1);

  //Checking if number of rings is even
  if(n % 2 == 0){
    from = 0;
    to = 2;
    isEven = true;
  }

  //Checking if number of rings is odd
  if(n % 2 == 1){
    from = 0;
    to = 1;
    isOdd = true;
  }

  candidate = 1;

  //Printing each move 
  while(tower[1].size() < n + 1){
    cout << "Move number " << ++move << ": Transfer ring" << candidate << " from tower "
    << char(from + 65) << " to tower " << char(to + 65) << endl;

    tower[to].push_back(tower[from].back());
    tower[from].pop_back();

    //If num of rings is odd
    if(isOdd){

      if(tower[(to + 1) % 3].back() < tower[(to + 2) % 3].back()){
        from = (to + 1) % 3;  

      }else{
        from = (to + 2) % 3;
      }

      if(tower[from].back() < tower[(from + 1) % 3].back()){
        from = (to + 1) % 3;
      }else{
        to = (from + 2) % 3;
      }
    }

    //If num of rings is even

    if( isEven ){
      if(tower[(to + 1) % 3].back() < tower[(to + 2) % 3].back()){
        from = (to + 1) % 3;
      }else{
        from = (to + 2) % 3;
      }

      if(tower[from].back() < tower[(from + 2) % 3].back()){
        to = (from + 2) % 3;
      }else{
        to = (from + 1) % 3;
      }
    }

    candidate = tower[from].back();

  }
  return 0;

}
