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

#ifndef GENIE_UNIT_H
#define GENIE_UNIT_H
#include "genie/file/ISerializable.h"
#include "unit/DamageGraphic.h"
#include "UnitCommand.h"
#include "unit/AttackOrArmor.h"
#include "unit/Type30.h"
#include "unit/Type40.h"
#include "unit/Type50.h"
#include "unit/Type60.h"
#include "unit/Type70.h"
#include "unit/Type80.h"

namespace genie
{

/// Available unit types
enum UnitType
{
  /// Basic units like rubble and flares.
  UT_Static = 10,

  /// Trees, used to be 90?
  UT_Tribe_Tree = 15,

  /// With Speed but mostly flags.
  UT_Animated = 20,

  /// Only one unit has this type. AOK, DOPL (id 243) same properties as UT_Animated
  UT_Doppleganger = 25,

  /// Dead and fish units. It seems to be unused in SWGB as units just explode
  /// and do not leave carcasses.
  UT_Moving = 30,

  /// Only birds in aoe and ror are of this type.
  UT_Action = 40,

  /// Shared class inherited by combat objects.
  UT_Combat = 50,

  /// Projectiles
  UT_Missile = 60,

  /// Units that can be created or trained like Army, Villagers and Ships.
  UT_Tribe_Combat = 70,

  /// Buildings
  UT_Tribe_Building = 80,

  /// Trees in aoe and ror are of this type
  UT_Tribe_Tree_Old = 90
};

//------------------------------------------------------------------------------
/// Stores properties of genie units.
//
class Unit : public ISerializable
{
public:
  Unit();
  virtual ~Unit();
  virtual void setGameVersion(GameVersion gv);

  /// See enum UnitType
  uint8_t Type = 10; // master_type

  int16_t ID = -1; // id

  union
  {
     /// ID of the name string stored in the language.dll file
     int32_t LanguageDLLName = 5000; // string_id
     int16_t LanguageDLLNameU16;
  };
  union
  {
     /// ID of the name string stored in the language.dll file
     int32_t LanguageDLLCreation = 6000; // string_id2
     int16_t LanguageDLLCreationU16;
  };

  /// Class that gives certain properties
  int16_t Class = -1; // object_group

  /// Default standing graphic
  int16_t StandingGraphic = -1; // sprite
  int16_t StandingGraphic2 = -1; // sprite2

  /// Graphic shown while the units is dying.
  int16_t DyingGraphic = -1; // death_sprite
  int16_t UndeadGraphic = -1; // undead_sprite

  /// Enables undead state
  uint8_t UndeadMode = 0; // undead_flag

  /// Unit's hit points
  int16_t HitPoints = 1; // hp

  /// Default line of sight measured in tiles
  float LineOfSight = 2; // los

  /// Maximum number of units that can be garrisonned at the same time.
  uint8_t GarrisonCapacity = 0; // obj_max

  /// Collision detection area taken by the unit.
  /// No other unit can move into this area except flying units.
  float CollisionSizeX = 0; // radius_x
  float CollisionSizeY = 0; // radius_y
  float CollisionSizeZ = 0; // radius_z

  /// Sound played when the unit is created
  int16_t TrainSound = -1; // created_sound
  int16_t DamageSound = -1; // damage_sound
  uint32_t WwiseTrainSoundID = 0;
  uint32_t WwiseDamageSoundID = 0;

  /// ID of the unit to change to when this one dies.
  int16_t DeadUnitID = -1; // death_spawn_obj_id
  int16_t BloodUnitID = -1;

  uint8_t SortNumber = 0; // sort_number

  uint8_t CanBeBuiltOn = 0; // can_be_built_on

  /// ID of the icon shown at the bottom when selected or when building
  int16_t IconID = -1; // button_pict

  /// If true, unit can not be placed in the editor
  uint8_t HideInEditor = 0; // hide_in_scenario_editor

  int16_t OldPortraitPict = -1; // portrait_pict, Always -1

  uint8_t Enabled = 1; // available
  uint8_t Disabled = 0; // disabled
  int16_t PlacementSideTerrain1; // tile_req1
  int16_t PlacementSideTerrain2; // tile_req2
  int16_t PlacementTerrain1; // center_tile_req1
  int16_t PlacementTerrain2; // center_tile_req2
  float ClearanceSizeX; // construction_radius_x
  float ClearanceSizeY; // construction_radius_y
  uint8_t HillMode = 0; // elevation_flag
  uint8_t FogVisibility = 0; // fog_flag

  /// ID of terrain restrictions that are imposed on the unit.
  int16_t TerrainRestriction = 0; // terrain

  /// Bool which determines wheter the unit can fly.
  uint8_t FlyMode = 0; // movement_type

  /// How much resources this unit is able to carry
  int16_t ResourceCapacity = 0; // attribute_max_amount

  float ResourceDecay = 0; // attribute_rot
  uint8_t BlastDefenseLevel = 0; // area_effect_object_level
  uint8_t CombatLevel = 0; // combat_level
  uint8_t InteractionMode = 0; // select_level

  /**
   * \brief Defines if and how a unit is shown on the minimap.
   *
   * Following values are known to work:
   *
   * - 0 does not place a dot on the mini-map. Eye candy, resources,
   *     fish traps, OUTLWs, and farms have this value
   * - 1 places a square dot on the min-map for the unit. When the unit is
   *     selected, the dot will turn white
   * - 2 places a diamond-shaped dot on the mini-map for the unit. When the unit
   *     is selected, the dot will turn white
   * - 3 places a diamond-shaped dot on the mini-map for the unit. When the unit
   *     is selected, the dot remains the player's color.
   * - 4 places a larger black spot on the minimap which does not follow the
   *     unit. Whenever you open the chat box (enter) and close it, the black
   *     spots will move to the unit on the minimap. No blinking occurs when
   *     the unit is attacked. Both allied and enemy units are visible in the
   *     black area on the minimap. CLF units have this value and a brown spot
   *     is placed instead.
   * - 5 does the same thing as “4”
   * - 6 does not place a dot on the minimap
   * - 7-9 does the same thing as “6”
   * - 10 does the same thing as “6”. Hawks, macaws, and flying dogs have
   *      this value.
   */
  uint8_t MinimapMode = 0; // map_draw_level

  // Page for Build button: 2 = Page 1, 10 = Page 2, ?11 = Page 3?
  uint8_t InterfaceKind = 0; // unit_level
  float MultipleAttributeMode = 0; // multiple_attribute_mod
  uint8_t MinimapColor = 0; // map_color
  int32_t LanguageDLLHelp = 105000; // help_string_id
  int32_t LanguageDLLHotKeyText = 155000; // help_page_id
  int32_t HotKey = 16000; // hotkey_id
  uint8_t Recyclable = 0; // recyclable
  uint8_t EnableAutoGather = 0; // track_as_resource
  uint8_t CreateDoppelgangerOnDeath = 0; // create_doppleganger_on_death
  uint8_t ResourceGatherGroup = 0; // resource_group
  uint8_t OcclusionMode = 0; // occlusion_flag

  /// values for ObstructionType
  /// 0 farm, gate, dead bodies, town center
  /// 2 buildings, gold mine
  /// 3 berserk, flag x
  /// 5 units
  /// 10 mountain(matches selction mask)
  uint8_t ObstructionType = 0; // obstruction_type

  /// 0 default, 1+ above
  uint8_t ObstructionClass = 0; // obstruction_class
  uint8_t Trait = 0; // object_flags
  /// Seems to be used only in SWGB/CC
  uint8_t Civilization = 0; // object_flags
  uint16_t TraitUnused = 0; // object_flags

  /**
   * 1.HP Bar on, selection shadow (permanent darker outline in editor only, disappears in game)
   * 2.HP Bar on, normal outline
   * 3.HP Bar off, selection shadow
   * 4.HP Bar off, normal outline
   * Note: this doe not work with all units
   */
  uint8_t SelectionEffect = 1; // draw_flag
  uint8_t EditorSelectionColour = 52; // draw_color
  float OutlineSizeX = 0; // outline_radius_x
  float OutlineSizeY = 0; // outline_radius_y
  float OutlineSizeZ = 0; // outline_radius_z

  /// Resource cost of a unit
  std::vector<int16_t> ResourceStoragesType; // attribute_type_held
  std::vector<float> ResourceStoragesAmount; // attribute_amount_held
  std::vector<uint8_t> ResourceStoragesFlag; // attribute_flag

  std::vector<unit::DamageGraphic> DamageGraphics; // damage_sprites

  /// Sound that is played when this unit is selected
  int16_t SelectionSound = -1; // selected_sound
  int16_t DyingSound = -1; // death_sound
  uint32_t WwiseSelectionSoundID = 0;
  uint32_t WwiseDyingSoundID = 0;
  uint8_t OldAttackReaction = 0; // attack_reaction
  uint8_t ConvertTerrain = 0; // convert_terrain_flag
  std::string Name = ""; // name
  std::string Name2 = "";

  /// MinGameVersion: SWGB
  int16_t Unitline = -1;

  /// MinGameVersion: SWGB
  uint8_t MinTechLevel = -1;

  int16_t CopyID = -1; // copy_id
  int16_t BaseID = -1; // base_id, not in aoe/ror
  int16_t TelemetryID = -1;

//      Type 20+

  float Speed = 0; // speed

  unit::Moving Moving;

  unit::Action Action;

  unit::Combat Combat;

  unit::Missile Missile;

  unit::Tribe_Combat Tribe_Combat;

  unit::Tribe_Building Tribe_Building;

protected:
  virtual void serializeObject(void);
};

}

#endif // GENIE_UNIT_H
