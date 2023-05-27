/*
    genie/dat - A library for reading and writing data files of genie
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

#include "genie/dat/unit/Type70.h"

namespace genie
{

namespace unit
{

Tribe_Combat::Tribe_Combat() : //Combat(),
  ResourceCosts(3)
{
}

Tribe_Combat::~Tribe_Combat()
{
}

//------------------------------------------------------------------------------
void Tribe_Combat::setGameVersion(GameVersion gv)
{
  ISerializable::setGameVersion(gv);
}

unsigned short Tribe_Combat::getResourceCostsSize()
{
  return 3;
}

void Tribe_Combat::serializeObject(void)
{
  GameVersion gv = getGameVersion();

  serializeSub<ResourceCost>(ResourceCosts, 3);
  serialize<int16_t>(TrainTime);
  serialize<int16_t>(TrainLocationID);
  serialize<uint8_t>(ButtonID);

  if (gv >= GV_AoEB) // 7.01
  {
    if (gv >= GV_AoKE3) // 9.07
    {
      serialize<float>(RearAttackModifier);
      serialize<float>(FlankAttackModifier);
      serialize<uint8_t>(CreatableType);

      if (gv >= GV_AoKB)
      {
        serialize<uint8_t>(HeroMode); // 10.49
        serialize<int32_t>(GarrisonGraphic); // 10.73

        if (gv <= GV_LatestDE2 && gv >= GV_C13)
        {
          serialize<int16_t>(SpawningGraphic);
          serialize<int16_t>(UpgradeGraphic);

          if (gv >= GV_C16)
          {
            if (gv >= GV_C17)
            {
              serialize<int16_t>(HeroGlowGraphic);
            }
            serialize<float>(MaxCharge);
            serialize<float>(RechargeRate);
            serialize<int16_t>(ChargeEvent);
            serialize<int16_t>(ChargeType);

            if (gv >= GV_C19)
            {
              serialize<float>(MinConversionTimeMod);
              serialize<float>(MaxConversionTimeMod);
              serialize<float>(ConversionChanceMod);
            }
          }
        }
      }

      serialize<float>(TotalProjectiles);
      serialize<uint8_t>(MaxTotalProjectiles);
      serialize<float>(ProjectileSpawningArea, 3);
      serialize<int32_t>(SecondaryProjectileUnit); // 9.08
      // 9.2
      {
        serialize<int32_t>(SpecialGraphic);
        serialize<uint8_t>(SpecialAbility);
      }
    }
    serialize<int16_t>(DisplayedPierceArmour);
  }
}

}

}
