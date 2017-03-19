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

namespace fake_framework
{

class JPetSignal {
  float fTime = 0;
  int fDetectorId = -1;   /// from 1 to 10
  int fTimeWindowId = -1; /// from 1 to 100
};

struct JPetHit{
  JPetHit(const JPetSignal& signalA, const JPetSignal& signalB);
  float fEnergy = 0;
  float fTime = 0;  ///  tA+tB/2
  float fTimeDifference = 0; /// tA -tB
  float fPosZ = 0; // (tA-tB) * c
  JPetSignal fSignalA;
  JPetSignal fSignalB;
};

}
#endif /*  !JPETFAKEFRAMEWORK_H */