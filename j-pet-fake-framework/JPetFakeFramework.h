/**
 *  @copyright Copyright 2017 The J-PET Framework Authors. All rights reserved.
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may find a copy of the License in the LICENCE file.
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  @file JPetFakeFramework.h
 */

#ifndef JPETFAKEFRAMEWORK_H
#define JPETFAKEFRAMEWORK_H
#include <vector>

namespace fake_framework
{


struct JPetSignal {
  JPetSignal(float time, int detector, int timeW);
  JPetSignal(){};
  float fTime = 0; /// 0.0 to 10.
  int fDetectorId = -1;   /// from 1 to 2
  int fTimeWindowId = -1; /// from 1 to 5
};

struct JPetHit {
  JPetHit(const JPetSignal& signalA, const JPetSignal& signalB);
  float fTime = 0;  ///  tA+tB/2
  float fTimeDifference = 0; /// tA -tB
  float fPosZ = 0; // (tA-tB) * c
  JPetSignal fSignalA;
  JPetSignal fSignalB;
};

std::vector<JPetSignal> performExperiment(int nevents);

}
#endif /*  !JPETFAKEFRAMEWORK_H */
