#include <iostream>
#include <algorithm>
#include <map>
#include "j-pet-fake-framework/JPetFakeFramework.h"

using namespace std;
using namespace fake_framework;
int main()
{
  int nevents = 10;
  auto vecOfSignals = performExperiment(nevents);
  
  return 0;
}
