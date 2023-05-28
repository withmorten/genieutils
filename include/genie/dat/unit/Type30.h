/*
    geniedat - A library for reading and writing data files of genie
               engine games.
    Copyright (C) 2011 - 2013  Armin Preiml
    Copyright (C) 2011 - 2021  Mikko "Tapsa" P

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GENIE_TYPE30_H
#define GENIE_TYPE30_H

#include "genie/file/ISerializable.h"

namespace genie
{

namespace unit
{

/// Attributes for Unit of type >= Moving.
class Moving : public ISerializable
{
public:
  Moving();
  virtual ~Moving();
  virtual void setGameVersion(GameVersion gv);

  int16_t WalkingGraphic = -1; // move_sprite
  int16_t RunningGraphic = -1; // run_sprite
  float RotationSpeed = 0; // turn_speed
  uint8_t OldSizeClass = 0; // size_class
  int16_t TrackingUnit = -1; // obj_trail_id
  uint8_t TrackingUnitMode = 0; // obj_trail_options
  float TrackingUnitDensity = 0; // obj_trail_spacing
  uint8_t OldMoveAlgorithm = 0; // move_algorithem

  // All can change while playing
  float TurnRadius = 0; // mTurnRadius
  float TurnRadiusSpeed = 3.402823466e+38f; // mTurnRadiusSpeed
  float MaxYawPerSecondMoving = 3.402823466e+38f; // mMaximumYawPerSecondMoving
  float StationaryYawRevolutionTime = 0; // mStationaryYawRevolutionTime
  float MaxYawPerSecondStationary = 3.402823466e+38f; // mMaximumYawPerSecondStationary
  float MinCollisionSizeMultiplier = 1.0f;

protected:
  virtual void serializeObject(void);
};

}

}

#endif // GENIE_TYPE30_H
