#include "ops.hh"

class OpsCount : public Ops {
  long swapcount;
  long comparecount;

public:
  
  OpsCount() : swapcount(0), comparecount(0){}
  
  int compare(int a, int b){
    comparecount++;
    return this->Ops::compare(a, b);
  }
  
  void swap(int a[], int i, int j){
    this->Ops::swap(a, i, j);
    swapcount++;
  }
  int getSwapCount(){
    return swapcount;
  }
  
  int getCompareCount(){
    return comparecount;
  }
};
