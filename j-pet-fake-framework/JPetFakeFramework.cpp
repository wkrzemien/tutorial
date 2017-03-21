/**
 *  @copyright Copyright 2016 The J-PET Framework Authors. All rights reserved.
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
 *  @file JPetFakeFramework.cpp
 */

#include "./JPetFakeFramework.h"
#include <random>
#include <algorithm>

using namespace fake_framework;

std::vector<JPetSignal> fake_framework::performExperiment(int nevents)
{
  const double kMaxTime = 10;
  std::vector<JPetSignal> result;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> detectors(1, 2);
  std::uniform_int_distribution<> time_window(1, 5);
  std::uniform_real_distribution<> time(0, 10);

  for (auto i = 0; i < nevents; i++) {
    auto det = detectors(gen);
    auto t = time(gen);
    auto tw = time_window(gen);
    result.push_back(JPetSignal(t, (det+1)%2 + 1, tw));
    result.push_back(JPetSignal(kMaxTime -t, det, tw));
  }
  std::shuffle(result.begin(), result.end(), gen);
  return result;
}

JPetSignal::JPetSignal(float time, int detector, int timeW):
  fTime(time), fDetectorId(detector), fTimeWindowId(timeW)
{
}

JPetHit::JPetHit(const JPetSignal& sigA, const JPetSignal& sigB):
  fSignalA (sigA),
  fSignalB(sigB)
{
  const double kVelocity = 3;
  fTime = (sigA.fTime + sigB.fTime) / 2;
  fTimeDifference = sigA.fTime - sigB.fTime;
  fPosZ = kVelocity * (sigA.fTime - sigB.fTime);
}
