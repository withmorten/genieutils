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

#ifndef GENIE_TYPE40_H
#define GENIE_TYPE40_H

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

  int16_t DefaultTaskID = -1; // default_task
  float SearchRadius = 0; // search_radius
  float WorkRate = 0; // work_rate
  int16_t DropSite = -1; // drop_site
  int16_t BackupDropSite = -1; // backup_drop_site
  int16_t BackupDropSite2 = -1;

  /// If activated unit switches villager types
  uint8_t TaskSwapGroup = 0; // task_by_group
  int16_t AttackSound = -1; // command_sound
  int16_t MoveSound = -1; // move_sound
  uint32_t WwiseAttackSoundID = 0;
  uint32_t WwiseMoveSoundID = 0;
  /// Some animals have this.
  uint8_t RunPattern = 0; // run_pattern
  std::vector<Task> TaskList; // tasks, only in aoe/ror

protected:
  virtual void serializeObject(void);
};

}

}

#endif // GENIE_TYPE40_H
