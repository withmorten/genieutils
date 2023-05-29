/*
    genie/dat - A library for reading and writing data files of genie
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

#include "genie/dat/unit/Type80.h"

namespace genie
{

namespace unit
{

Tribe_Building::Tribe_Building() : //Tribe_Combat(),
  AnnexUnitID(BUILDING_ANNEXES_SIZE, -1),
  AnnexMisplacementX(BUILDING_ANNEXES_SIZE),
  AnnexMisplacementY(BUILDING_ANNEXES_SIZE),
  LootingTable(LOOTABLE_RES_COUNT)
{
}

Tribe_Building::~Tribe_Building()
{
}

//------------------------------------------------------------------------------
void Tribe_Building::setGameVersion(GameVersion gv)
{
  ISerializable::setGameVersion(gv);
}

void Tribe_Building::serializeObject(void)
{
  GameVersion gv = getGameVersion();

  serialize<int16_t>(ConstructionGraphicID);

  if (gv >= GV_TC) // 11.53
  {
    serialize<int16_t>(SnowGraphicID);

    if (gv <= GV_LatestDE2 && gv >= GV_C10)
    {
      serialize<int16_t>(DestructionGraphicID);

      if (gv >= GV_C12)
      {
        serialize<int16_t>(DestructionRubbleGraphicID);

        if (gv >= GV_C13)
        {
          serialize<int16_t>(ResearchingGraphic);
          serialize<int16_t>(ResearchCompletedGraphic);
        }
      }
    }
  }

  serialize<uint8_t>(AdjacentMode);
  serialize<int16_t>(GraphicsAngle);
  serialize<uint8_t>(DisappearsWhenBuilt);
  serialize<int16_t>(StackUnitID);
  serialize<int16_t>(FoundationTerrainID);
  serialize<int16_t>(OldOverlayID); // No longer used
  serialize<int16_t>(TechID);

  if (gv >= GV_AoKE3)
  {
    serialize<uint8_t>(CanBurn);
    for (unsigned i=0; i<BUILDING_ANNEXES_SIZE; i++)
    {
      serialize<int16_t>(AnnexUnitID[i]);
      serialize<float>(AnnexMisplacementX[i]);
      serialize<float>(AnnexMisplacementY[i]);
    }
    if (gv >= GV_AoKA)
      serialize<int16_t>(HeadUnit); // 9.89
    serialize<int16_t>(TransformUnit);
    serialize<int16_t>(TransformSound);
  }

  serialize<int16_t>(ConstructionSound);

  if (gv >= GV_AoKE3)
  {
    if (gv >= GV_C4 && gv <= GV_LatestDE2)
    {
      serialize<uint32_t>(WwiseTransformSoundID);
      serialize<uint32_t>(WwiseConstructionSoundID);
    }
    serialize<uint8_t>(GarrisonType);
    serialize<float>(GarrisonHealRate);
    serialize<float>(GarrisonRepairRate);
    {
      serialize<int16_t>(PileUnit); // 9.06
      // 9.06 - 9.25 -> 5 x 2 x int16_t
      serialize<uint8_t>(LootingTable, LOOTABLE_RES_COUNT); // 9.26
    }
  }
}

}

}
