/*
    geniedat - A library for reading and writing data files of genie
               engine games.
    Copyright (C) 2011 - 2013  Armin Preiml
    Copyright (C) 2011 - 2021  Mikko "Tapsa" P
    Copyright (C) 2023  Manuel Winocur

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

#ifndef GENIE_TYPE50_H
#define GENIE_TYPE50_H

#include "genie/file/ISerializable.h"
#include "AttackOrArmor.h"

namespace genie
{

namespace unit
{

class Combat : public ISerializable
{
public:
  Combat();
  virtual ~Combat();
  virtual void setGameVersion(GameVersion gv);

  union
  {
     int16_t BaseArmor = 1000; // base_armor
     uint8_t BaseArmorU8;
  };
  std::vector<unit::AttackOrArmor> Attacks; // weapon
  std::vector<unit::AttackOrArmor> Armours; // armor
  int16_t DefenseTerrainBonus = -1; // defense_terrain_bonus
  float BonusDamageResistance = 0;
  float MaxRange = 0; // weapon_range
  float BlastWidth = 0; // area_effect_range
  float ReloadTime = 0; // speed_of_attack
  int16_t ProjectileUnitID = -1; // missile_id

  /// Percentage value determining the probability of an attack hiting
  int16_t AccuracyPercent = 0; // base_hit_chance

  /// Used in AoE/RoR for towers.
  uint8_t BreakOffCombat = 0; // break_off_combat
  int16_t FrameDelay = 0; // fire_missile_at_frame

  float GraphicDisplacementX = 0; // weapon_offset_x
  float GraphicDisplacementY = 0; // weapon_offset_y
  float GraphicDisplacementZ = 0; // weapon_offset_z

  uint8_t BlastAttackLevel = 0; // area_effect_level
  float MinRange = 0; // minimum_weapon_range
  float AccuracyDispersion = 0; // missed_missile_spread
  int16_t AttackGraphic = -1; // fight_sprite
  int16_t DisplayedMeleeArmour = 0; // orig_armor
  int16_t DisplayedAttack = 0; // orig_weapon
  float DisplayedRange = 0; // orig_weapon_range
  float DisplayedReloadTime = 0; // orig_speed_of_attack
  float BlastDamage = 0;

protected:
  virtual void serializeObject(void);
};

}

}

#endif // GENIE_TYPE50_H
