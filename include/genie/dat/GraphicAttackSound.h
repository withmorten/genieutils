/*
    geniedat - A library for reading and writing data files of genie
               engine games.
    Copyright (C) 2011  Armin Preiml <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef GENIE_GRAPHICATTACKSOUND_H
#define GENIE_GRAPHICATTACKSOUND_H
#include "genie/file/ISerializable.h"

namespace genie
{

class GraphicAttackSound : public ISerializable
{

public:
  GraphicAttackSound();
  virtual ~GraphicAttackSound();
  
  virtual void serializeObject(void);
  
  //TODO: Vector
  short SoundDelay;
  short SoundID;
  short SoundDelay2;
  short SoundID2;
  short SoundDelay3;
  short SoundID3;
};

}

#endif // GENIE_GRAPHICATTACKSOUND_H