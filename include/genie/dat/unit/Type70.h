/*
    geniedat - A library for reading and writing data files of genie
               engine games.
    Copyright (C) 2011 - 2013  Armin Preiml
    Copyright (C) 2011 - 2022  Mikko "Tapsa" P

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

#ifndef GENIE_TYPE70_H
#define GENIE_TYPE70_H

#include "genie/file/ISerializable.h"
#include "../ResourceUsage.h"

namespace genie
{

namespace unit
{

class Tribe_Combat : public ISerializable
{
public:
  Tribe_Combat();
  virtual ~Tribe_Combat();
  virtual void setGameVersion(GameVersion gv);

  std::vector<ResourceCost> ResourceCosts; // build_inventory
  int16_t TrainTime = 0; // build_pts_required
  int16_t TrainLocationID = -1; // id_of_building_obj
  uint8_t ButtonID = 0; // button_location
  float RearAttackModifier = 0; // rear_attack_modifier
  float FlankAttackModifier = 0; // flank_attack_modifier
  uint8_t CreatableType = 0; // tribe_unit_type
  uint8_t HeroMode = 0; // hero_flag
  int32_t GarrisonGraphic = -1; // garrison_sprite
  float TotalProjectiles = 0; // volley_fire_amount
  uint8_t MaxTotalProjectiles = 0; // max_attacks_in_volley

  /// The area from which projectiles spawn. Size and randomness.
  float ProjectileSpawningAreaX = 0; // volley_x_spread
  float ProjectileSpawningAreaY = 0; // volley_y_spread
  float ProjectileSpawningAreaAdjustment = 0; // volley_start_spread_adjustment

  int32_t SecondaryProjectileUnit = -1; // volley_missile_id
  int32_t SpecialGraphic = -1; // special_attack_sprite_id

  //TODO:
  /*
   * 1.Determines adjacent unit graphics
    2.Enter 0 or 1
    3.If “1”, the building will have the capability to change graphics depending
    on the buildings adjacent to it. For instance, a single wall will be a
    wall end piece, but if a wall is placed between two other walls, it will
    have a different graphic.
   */
  uint8_t SpecialAbility = 0; // special_attack_flag
  int16_t DisplayedPierceArmour = 0; // orig_pierce_armor
  int16_t SpawningGraphic = -1;
  int16_t UpgradeGraphic = -1;
  int16_t HeroGlowGraphic = -1;

  float MaxCharge = 0;
  float RechargeRate = 0;
  int16_t ChargeEvent = 0;
  int16_t ChargeType = 0;

  float MinConversionTimeMod = 0;
  float MaxConversionTimeMod = 0;
  float ConversionChanceMod = 0;

protected:
  virtual void serializeObject(void);

};

}

}

#endif // GENIE_TYPE70_H
