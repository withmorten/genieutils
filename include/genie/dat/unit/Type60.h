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

#ifndef GENIE_TYPE60_H
#define GENIE_TYPE60_H

#include "genie/file/ISerializable.h"

namespace genie
{

namespace unit
{

class Missile : public ISerializable
{
public:
  Missile();
  virtual ~Missile();
  virtual void setGameVersion(GameVersion gv);

  uint8_t ProjectileType = 0; // missile_type
  uint8_t SmartMode = 0; // targetting_type
  uint8_t HitMode = 0; // missile_hit_info

  /// Affects the graphics so that they pass through the target instead of stopping
  /// 1 allows the projectile to pass through, a value of 0 stops the projectile.
  /// Only affects graphic not pass through damage.
  uint8_t VanishMode = 0; // missile_die_info

  uint8_t AreaEffectSpecials = 0; // area_effect_specials

  /// Determines the arc a projectile follows.
  /// Enter a non-negative value.
  /// The higher the value, the higher the arc will be that the projectile travels.
  /// The graphics do not change, so a scorpion bolt will still always point forwards,
  /// even if it has a very high arc.
  float ProjectileArc = 0; // ballistics_ratio

protected:
  virtual void serializeObject(void);
};

}

}

#endif // GENIE_TYPE60_H
