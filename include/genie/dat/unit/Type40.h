/*
    geniedat - A library for reading and writing data files of genie
               engine games.
    Copyright (C) 2011 - 2013  Armin Preiml
    Copyright (C) 2011 - 2020  Mikko "Tapsa" P

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

#ifndef GENIE_BIRD_H
#define GENIE_BIRD_H

#include "genie/file/ISerializable.h"
#include "../UnitCommand.h"

namespace genie
{

namespace unit
{

class Action : public ISerializable
{
public:
  Action();
  virtual ~Action();
  virtual void setGameVersion(GameVersion gv);
  unsigned short getDropSiteCount(void);

  int16_t DefaultTaskID = -1;
  float SearchRadius = 0;
  float WorkRate = 0;
  std::vector<int16_t> DropSites;

  /// If activated unit switches villager types
  int8_t TaskSwapGroup = 0;
  int16_t AttackSound = -1;
  int16_t MoveSound = -1;
  uint32_t WwiseAttackSoundID = 0;
  uint32_t WwiseMoveSoundID = 0;
  /// Some animals have this.
  int8_t RunPattern = 0;
  std::vector<Task> TaskList;//only in aoe/ror

protected:
  virtual void serializeObject(void);
};

}

}

#endif // GENIE_BIRD_H