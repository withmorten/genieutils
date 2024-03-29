/*
    geniedat - A library for reading and writing data files of genie
               engine games.
    Copyright (C) 2011 - 2013  Armin Preiml
    Copyright (C) 2011 - 2016  Mikko "Tapsa" P

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

#ifndef GENIE_RESOURCEUSAGE_H
#define GENIE_RESOURCEUSAGE_H
#include "genie/file/ISerializable.h"

namespace genie
{

//------------------------------------------------------------------------------
/// Class describing quantities of Resources.
//
class ResourceCost : public ISerializable
{
public:
  ResourceCost() {}

  virtual ~ResourceCost() {}

  virtual void setGameVersion(GameVersion gv)
  {
    ISerializable::setGameVersion(gv);
  }

  /// Resource ID
  int16_t Type = -1;

  /// Amount of the resource available/required/used
  int16_t Amount = 0;

  /// Bool that determines whether it is paid or only needed.
  uint8_t Flag = 0;

private:
  virtual void serializeObject(void)
  {
    serialize<int16_t>(Type);
    serialize<int16_t>(Amount);
    serialize<uint8_t>(Flag);
    uint8_t Nothing = 0;
    serialize<uint8_t>(Nothing);
  }
};

}

#endif // GENIE_RESOURCEUSAGE_H
