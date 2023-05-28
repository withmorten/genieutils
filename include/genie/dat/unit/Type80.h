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

#ifndef GENIE_TYPE80_H
#define GENIE_TYPE80_H

#include "genie/file/ISerializable.h"

namespace genie
{

namespace unit
{

class Tribe_Building : public ISerializable
{
public:
  Tribe_Building();
  virtual ~Tribe_Building();
  virtual void setGameVersion(GameVersion gv);

  int16_t ConstructionGraphicID = -1; // construction_sprite
  int16_t SnowGraphicID = -1; // snow_sprite, not in aok/aoe/ror
  int16_t DestructionGraphicID = -1;
  int16_t DestructionRubbleGraphicID = -1;
  int16_t ResearchingGraphic = -1;
  int16_t ResearchCompletedGraphic = -1;
  /// Enabler for annex units.
  uint8_t AdjacentMode = 0; // building_connect_flag
  int16_t GraphicsAngle = 0; // building_facet
  uint8_t DisappearsWhenBuilt = 0; // build_and_go_away

  /// These four (4) variables are used when building is created
  int16_t StackUnitID = -1; // on_build_make_obj
  int16_t FoundationTerrainID = -1; // on_build_make_tile
  /// ES forgot to remove this when AoE was still in its alpha stages
  int16_t OldOverlayID = -1; // on_build_make_overlay
  int16_t TechID = -1; // on_build_make_tech

  uint8_t CanBurn = 0; // can_burn

  static const unsigned short BUILDING_ANNEXES_SIZE = 4;
  // A building can hold annexes like the town center.
  std::vector<int16_t> AnnexUnitID; // linked_id
  std::vector<float> AnnexMisplacementX; // linked_x
  std::vector<float> AnnexMisplacementY; // linked_y
  int16_t HeadUnit = -1; // construction_id
  int16_t TransformUnit = -1; // open_close_id
  int16_t TransformSound = -1; // open_close_sound
  int16_t ConstructionSound = -1; // construction_sound
  uint32_t WwiseTransformSoundID = 0;
  uint32_t WwiseConstructionSoundID = 0;
  uint8_t GarrisonType = 0; // garrison_units
  float GarrisonHealRate = 0; // garrison_heal_rate
  float GarrisonRepairRate = 0; // garrison_repair_rate
  int16_t PileUnit = -1; // salvage_id

  /// Related to annexes in any way?
  /// Widespread usage in the AoK alpha 09.07.0222
  static const unsigned short LOOTABLE_RES_COUNT = 6;
  std::vector<uint8_t> LootingTable; // pillage_attr

protected:
  virtual void serializeObject(void);
};

}

}

#endif // GENIE_TYPE80_H
