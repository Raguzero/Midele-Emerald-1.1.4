#ifndef __PROBABLE_MOVES_H__
#define __PROBABLE_MOVES_H__

#define MAX_PROBABLE_MOVES 8

static const u16 sProbablePowerfulOrNonSTABMoves[NUM_SPECIES][MAX_PROBABLE_MOVES] = {
    [SPECIES_CATERPIE] = {MOVE_TACKLE},
    [SPECIES_MAGIKARP] = {MOVE_TACKLE, MOVE_FLAIL},
    [SPECIES_METAPOD] = {MOVE_TACKLE},
    [SPECIES_SILCOON] = {MOVE_TACKLE},
    [SPECIES_CASCOON] = {MOVE_TACKLE},
    [SPECIES_MAKUHITA] = {MOVE_ROCK_SLIDE},
    [SPECIES_WHISMUR] = {MOVE_SHADOW_BALL},
    [SPECIES_ZIGZAGOON] = {MOVE_SHADOW_BALL},
    [SPECIES_ZUBAT] = {MOVE_LEECH_LIFE},
    [SPECIES_MARILL] = {MOVE_EGG_BOMB},
    [SPECIES_SLUGMA] = {MOVE_BODY_SLAM},
    [SPECIES_SWINUB] = {MOVE_ROCK_TOMB},
    [SPECIES_RATTATA] = {MOVE_SHADOW_BALL},
    [SPECIES_HOOTHOOT] = {MOVE_PSYCHIC},
    [SPECIES_DIGLETT] = {MOVE_SLASH, MOVE_ROCK_TOMB},
    [SPECIES_LEDYBA] = {MOVE_ICE_PUNCH, MOVE_KNOCK_OFF},
    [SPECIES_NIDORAN_F] = {MOVE_DOUBLE_KICK},
    [SPECIES_MEDITITE] = {MOVE_HI_JUMP_KICK, MOVE_SHADOW_BALL},
    [SPECIES_MEOWTH] = {MOVE_SHADOW_BALL},
    [SPECIES_TRAPINCH] = {MOVE_STONE_EDGE},
    [SPECIES_HORSEA] = {MOVE_ICE_BEAM},
    [SPECIES_DUSKULL] = {MOVE_SEISMIC_TOSS, MOVE_NIGHT_SHADE},
    [SPECIES_ELECTRIKE] = {MOVE_CRUNCH},
    [SPECIES_PIKACHU] = {MOVE_SURF},
    [SPECIES_SANDSHREW] = {MOVE_ROCK_TOMB},
    [SPECIES_POLIWAG] = {MOVE_ICE_BEAM},
    [SPECIES_DRATINI] = {MOVE_FLAMETHROWER},
    [SPECIES_SNUBBULL] = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
    [SPECIES_REMORAID] = {MOVE_ICE_BEAM, MOVE_ENERGY_BALL},
    [SPECIES_LARVITAR] = {MOVE_EARTHQUAKE},
    [SPECIES_BALTOY] = {MOVE_ANCIENT_POWER},
    [SPECIES_BAGON] = {MOVE_IRON_HEAD, MOVE_FLAMETHROWER},
    [SPECIES_BELDUM] = {MOVE_TAKE_DOWN, MOVE_FLAMETHROWER},
    [SPECIES_VENONAT] = {MOVE_PSYCHIC},
    [SPECIES_MANKEY] = {MOVE_ROCK_SLIDE},
    [SPECIES_MACHOP] = {MOVE_ROCK_SLIDE},
    [SPECIES_NUMEL] = {MOVE_ROCK_TOMB},
    [SPECIES_CHARMANDER] = {MOVE_CRUNCH},
    [SPECIES_CYNDAQUIL] = {MOVE_BODY_SLAM},
    [SPECIES_ABRA] = {MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH},
    [SPECIES_DODUO] = {MOVE_BRAVE_BIRD, MOVE_JUMP_KICK},
    [SPECIES_GASTLY] = {MOVE_NIGHT_SHADE},
    [SPECIES_SWABLU] = {MOVE_BODY_SLAM},
    [SPECIES_TREECKO] = {MOVE_QUICK_ATTACK},
    [SPECIES_TORCHIC] = {MOVE_QUICK_ATTACK},
    [SPECIES_SQUIRTLE] = {MOVE_BITE},
    [SPECIES_TOTODILE] = {MOVE_SLASH},
    [SPECIES_PSYDUCK] = {MOVE_PSYCHIC},
    [SPECIES_CUBONE] = {MOVE_ROCK_SLIDE},
    [SPECIES_GOLDEEN] = {MOVE_MEGAHORN},
    [SPECIES_SEEL] = {MOVE_BODY_SLAM},
    [SPECIES_KRABBY] = {MOVE_SLASH},
    [SPECIES_EEVEE] = {MOVE_SHADOW_BALL},
    [SPECIES_DROWZEE] = {MOVE_THUNDER_PUNCH},
    [SPECIES_CHINCHOU] = {MOVE_ICE_BEAM},
    [SPECIES_TEDDIURSA] = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
    [SPECIES_DELIBIRD] = {MOVE_WATER_PULSE, MOVE_BRAVE_BIRD},
    [SPECIES_LUVDISC] = {MOVE_ICE_BEAM},
    [SPECIES_UNOWN] = {MOVE_HIDDEN_POWER},
    [SPECIES_STARYU] = {MOVE_ICE_BEAM},
    [SPECIES_NUZLEAF] = {MOVE_EXTRASENSORY},
    [SPECIES_VIBRAVA] = {MOVE_ROCK_TOMB},
    [SPECIES_CLAMPERL] = {MOVE_ICE_BEAM},
    [SPECIES_GROWLITHE] = {MOVE_BITE},
    [SPECIES_ELEKID] = {MOVE_ICE_PUNCH},
    [SPECIES_LOUDRED] = {MOVE_SHADOW_BALL},
    [SPECIES_SPINDA] = {MOVE_SHADOW_BALL, MOVE_PSYCHIC, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
    [SPECIES_NIDORINA] = {MOVE_DOUBLE_KICK, MOVE_EGG_BOMB},
    [SPECIES_FLAAFFY] = {MOVE_FIRE_PUNCH},
    [SPECIES_NOSEPASS] = {MOVE_EARTHQUAKE},
    [SPECIES_BUTTERFREE] = {MOVE_PSYCHIC, MOVE_ENERGY_BALL},
    [SPECIES_BEEDRILL] = {MOVE_BRICK_BREAK},
    [SPECIES_POLIWHIRL] = {MOVE_PSYCHIC, MOVE_ICE_BEAM},
    [SPECIES_BEAUTIFLY] = {MOVE_ENERGY_BALL, MOVE_PSYCHIC},
    [SPECIES_DUSTOX] = {MOVE_ENERGY_BALL, MOVE_PSYCHIC},
    [SPECIES_YANMA] = {MOVE_ANCIENT_POWER},
    [SPECIES_DELCATTY] = {MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_MOONBLAST},
    [SPECIES_SABLEYE] = {MOVE_NIGHT_SHADE},
    [SPECIES_LICKITUNG] = {MOVE_BRICK_BREAK, MOVE_SHADOW_BALL, MOVE_EARTHQUAKE},
    [SPECIES_WEEPINBELL] = {MOVE_KNOCK_OFF},
    [SPECIES_GRAVELER] = {MOVE_BRICK_BREAK},
    [SPECIES_GLOOM] = {MOVE_SOLAR_BEAM},
    [SPECIES_PORYGON] = {MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_THUNDERBOLT},
    [SPECIES_KADABRA] = {MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH},
    [SPECIES_WAILMER] = {MOVE_BODY_SLAM},
    [SPECIES_VOLBEAT] = {MOVE_DAZZLING_GLEAM, MOVE_THUNDERBOLT, MOVE_ICE_PUNCH},
    [SPECIES_ILLUMISE] = {MOVE_THUNDERBOLT, MOVE_ICE_PUNCH},
    [SPECIES_CHARMELEON] = {MOVE_SLASH, MOVE_DRAGON_CLAW},
    [SPECIES_WARTORTLE] = {MOVE_BITE, MOVE_ICE_BEAM},
    [SPECIES_PARASECT] = {MOVE_BRICK_BREAK},
    [SPECIES_MACHOKE] = {MOVE_STONE_EDGE, MOVE_CROSS_CHOP},
    [SPECIES_HAUNTER] = {MOVE_PSYCHIC},
    [SPECIES_BAYLEEF] = {MOVE_BODY_SLAM},
    [SPECIES_QUILAVA] = {MOVE_BODY_SLAM, MOVE_EXTRASENSORY},
    [SPECIES_CROCONAW] = {MOVE_SLASH, MOVE_BITE},
    [SPECIES_MURKROW] = {MOVE_BRAVE_BIRD},
    [SPECIES_GROVYLE] = {MOVE_QUICK_ATTACK, MOVE_CRUNCH},
    [SPECIES_COMBUSKEN] = {MOVE_SLASH},
    [SPECIES_PONYTA] = {MOVE_LOW_KICK, MOVE_BODY_SLAM, MOVE_DOUBLE_KICK},
    [SPECIES_AZUMARILL] = {MOVE_BRICK_BREAK, MOVE_EGG_BOMB, MOVE_IRON_TAIL},
    [SPECIES_SUDOWOODO] = {MOVE_HEAD_SMASH, MOVE_EARTHQUAKE},
    [SPECIES_MAGCARGO] = {MOVE_EARTHQUAKE},
    [SPECIES_RATICATE] = {MOVE_SHADOW_BALL, MOVE_JUMP_KICK},
    [SPECIES_MASQUERAIN] = {MOVE_ICE_BEAM, MOVE_GIGA_DRAIN, MOVE_HYDRO_PUMP},
    [SPECIES_FURRET] = {MOVE_SHADOW_BALL, MOVE_BRICK_BREAK},
    [SPECIES_DUNSPARCE] = {MOVE_ROCK_SLIDE, MOVE_ICE_BEAM},
    [SPECIES_DRAGONAIR] = {MOVE_EGG_BOMB},
    [SPECIES_MIGHTYENA] = {MOVE_POISON_FANG, MOVE_MOONBLAST},
    [SPECIES_LINOONE] = {MOVE_SHADOW_BALL},
    [SPECIES_CASTFORM] = {MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_SOLAR_BEAM, MOVE_ICE_BEAM, MOVE_HYDRO_PUMP, MOVE_WEATHER_BALL},
    [SPECIES_SHELGON] = {MOVE_DOUBLE_EDGE, MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK},
    [SPECIES_METANG] = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
    [SPECIES_WIGGLYTUFF] = {MOVE_FLAMETHROWER, MOVE_KNOCK_OFF, MOVE_ICE_BEAM, MOVE_SHADOW_BALL},
    [SPECIES_SUNFLORA] = {MOVE_SOLAR_BEAM, MOVE_WEATHER_BALL, MOVE_HEAT_WAVE},
    [SPECIES_CHIMECHO] = {MOVE_DAZZLING_GLEAM, MOVE_KNOCK_OFF},
    [SPECIES_GLIGAR] = {MOVE_ROCK_SLIDE},
    [SPECIES_QWILFISH] = {MOVE_SHADOW_BALL},
    [SPECIES_SNEASEL] = {MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_AERIAL_ACE, MOVE_X_SCISSOR},
    [SPECIES_PELIPPER] = {MOVE_KNOCK_OFF, MOVE_ICE_BEAM},
    [SPECIES_SWELLOW] = {MOVE_BRAVE_BIRD, MOVE_STEEL_WING, MOVE_BOOMBURST},
    [SPECIES_LAIRON] = {MOVE_HEAD_SMASH, MOVE_EARTHQUAKE},
    [SPECIES_ARBOK] = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_IRON_TAIL},
    [SPECIES_PERSIAN] = {MOVE_THUNDERBOLT, MOVE_WATER_PULSE, MOVE_KNOCK_OFF, MOVE_SHADOW_BALL, MOVE_GUNK_SHOT},
    [SPECIES_SEADRA] = {MOVE_ICE_BEAM},
    [SPECIES_KECLEON] = {MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
    [SPECIES_VIGOROTH] = {MOVE_SHADOW_BALL},
    [SPECIES_LUNATONE] = {MOVE_MOONBLAST, MOVE_ICE_BEAM},
    [SPECIES_SOLROCK] = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL},
    [SPECIES_NOCTOWL] = {MOVE_NIGHT_SHADE, MOVE_PSYCHIC, MOVE_MOONBLAST},
    [SPECIES_SANDSLASH] = {MOVE_GUNK_SHOT, MOVE_ROCK_SLIDE, MOVE_LEECH_LIFE},
    [SPECIES_VENOMOTH] = {MOVE_PSYCHIC, MOVE_GIGA_DRAIN},
    [SPECIES_CHANSEY] = {MOVE_SEISMIC_TOSS},
    [SPECIES_SEAKING] = {MOVE_ICE_BEAM, MOVE_KNOCK_OFF, MOVE_MEGAHORN, MOVE_DRILL_RUN},
    [SPECIES_PILOSWINE] = {MOVE_ROCK_SLIDE, MOVE_BODY_SLAM},
    [SPECIES_GOLBAT] = {MOVE_STEEL_WING, MOVE_SHADOW_BALL},
    [SPECIES_PRIMEAPE] = {MOVE_EARTHQUAKE},
    [SPECIES_HITMONLEE] = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_HI_JUMP_KICK},
    [SPECIES_HITMONCHAN] = {MOVE_STONE_EDGE, MOVE_HI_JUMP_KICK},
    [SPECIES_GIRAFARIG] = {MOVE_DAZZLING_GLEAM},
    [SPECIES_HITMONTOP] = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_HI_JUMP_KICK},
    [SPECIES_BANETTE] = {MOVE_EGG_BOMB},
    [SPECIES_SEVIPER] = {MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_GIGA_DRAIN, MOVE_X_SCISSOR, MOVE_FLAMETHROWER, MOVE_GUNK_SHOT},
    [SPECIES_ZANGOOSE] = {MOVE_SHADOW_BALL, MOVE_BRICK_BREAK},
    [SPECIES_CAMERUPT] = {MOVE_ROCK_SLIDE},
    [SPECIES_SHARPEDO] = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE},
    [SPECIES_TROPIUS] = {MOVE_EARTHQUAKE, MOVE_SOLAR_BEAM, MOVE_BODY_SLAM},
    [SPECIES_MANTINE] = {MOVE_ICE_BEAM},
    [SPECIES_STANTLER] = {MOVE_SHADOW_BALL, MOVE_EARTHQUAKE, MOVE_JUMP_KICK},
    [SPECIES_ABSOL] = {MOVE_STONE_EDGE, MOVE_SHADOW_BALL, MOVE_IRON_TAIL, MOVE_SLASH},
    [SPECIES_SWALOT] = {MOVE_SHADOW_BALL, MOVE_EARTHQUAKE},
    [SPECIES_CRAWDAUNT] = {MOVE_ICE_BEAM, MOVE_SLUDGE_BOMB, MOVE_ROCK_SLIDE},
    [SPECIES_PIDGEOT] = {MOVE_HEAT_WAVE, MOVE_STEEL_WING},
	[SPECIES_GRUMPIG] = {MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
    [SPECIES_TORKOAL] = {MOVE_SOLAR_BEAM},
    [SPECIES_KINGLER] = {MOVE_KNOCK_OFF, MOVE_ROCK_SLIDE},
    [SPECIES_CACTURNE] = {MOVE_THUNDER_PUNCH},
    [SPECIES_BELLOSSOM] = {MOVE_SOLAR_BEAM, MOVE_MOONBLAST},
    [SPECIES_OCTILLERY] = {MOVE_ICE_BEAM, MOVE_ENERGY_BALL, MOVE_FLAMETHROWER},
    [SPECIES_HUNTAIL] = {MOVE_BODY_SLAM, MOVE_CRUNCH, MOVE_ICE_BEAM},
    [SPECIES_GOREBYSS] = {MOVE_PSYCHIC, MOVE_ICE_BEAM},
    [SPECIES_RELICANTH] = {MOVE_HEAD_SMASH, MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE},
    [SPECIES_OMASTAR] = {MOVE_ICE_BEAM, MOVE_KNOCK_OFF},
    [SPECIES_KABUTOPS] = {MOVE_LEECH_LIFE},
    [SPECIES_POLIWRATH] = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
    [SPECIES_SCYTHER] = {MOVE_BRICK_BREAK, MOVE_QUICK_ATTACK},
    [SPECIES_PINSIR] = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
    [SPECIES_POLITOED] = {MOVE_PSYCHIC, MOVE_ICE_BEAM},
    [SPECIES_DUGTRIO] = {MOVE_TRI_ATTACK, MOVE_ROCK_SLIDE, MOVE_AERIAL_ACE},
    [SPECIES_MEDICHAM] = {MOVE_HI_JUMP_KICK, MOVE_SHADOW_BALL, MOVE_ROCK_SLIDE},
    [SPECIES_MISDREAVUS] = {MOVE_PSYCHIC, MOVE_THUNDERBOLT},
    [SPECIES_FEAROW] = {MOVE_DRILL_RUN, MOVE_BRAVE_BIRD, MOVE_EXTREME_SPEED},
    [SPECIES_GRANBULL] = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SHADOW_BALL, MOVE_CROSS_CHOP},
    [SPECIES_JYNX] = {MOVE_ENERGY_BALL},
    [SPECIES_DUSCLOPS] = {MOVE_SEISMIC_TOSS, MOVE_NIGHT_SHADE},
    [SPECIES_DODRIO] = {MOVE_JUMP_KICK, MOVE_BRAVE_BIRD, MOVE_DRILL_RUN},
    [SPECIES_MR_MIME] = {MOVE_ENERGY_BALL, MOVE_DAZZLING_GLEAM, MOVE_THUNDERBOLT, MOVE_FIRE_PUNCH},
    [SPECIES_LANTURN] = {MOVE_ICE_BEAM, MOVE_DAZZLING_GLEAM},
    [SPECIES_BRELOOM] = {MOVE_ROCK_TOMB, MOVE_SLUDGE_BOMB},
    [SPECIES_FORRETRESS] = {MOVE_EARTHQUAKE},
    [SPECIES_WHISCASH] = {MOVE_ROCK_SLIDE, MOVE_EGG_BOMB},
    [SPECIES_XATU] = {MOVE_DAZZLING_GLEAM, MOVE_HEAT_WAVE},
    [SPECIES_SKARMORY] = {MOVE_BRAVE_BIRD},
    [SPECIES_MAROWAK] = {MOVE_ROCK_SLIDE, MOVE_HEADBUTT, MOVE_BRICK_BREAK},
    [SPECIES_QUAGSIRE] = {MOVE_ROCK_SLIDE},
    [SPECIES_CLEFABLE] = {MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_FLAMETHROWER, MOVE_PSYCHIC, MOVE_SHADOW_BALL},
    [SPECIES_HARIYAMA] = {MOVE_ROCK_SLIDE, MOVE_CROSS_CHOP, MOVE_EARTHQUAKE, MOVE_IRON_HEAD},
    [SPECIES_RAICHU] = {MOVE_SURF},
    [SPECIES_MANECTRIC] = {MOVE_CRUNCH, MOVE_OVERHEAT},
    [SPECIES_VILEPLUME] = {MOVE_SOLAR_BEAM},
    [SPECIES_VICTREEBEL] = {MOVE_KNOCK_OFF, MOVE_SOLAR_BEAM},
    [SPECIES_EXPLOUD] = {MOVE_SHADOW_BALL, MOVE_FIRE_BLAST, MOVE_SOLAR_BEAM, MOVE_ICE_BEAM, MOVE_THUNDER_PUNCH, MOVE_EXTRASENSORY, MOVE_EARTHQUAKE, MOVE_BRICK_BREAK},
    [SPECIES_SHIFTRY] = {MOVE_SOLAR_BEAM, MOVE_HEAT_WAVE, MOVE_EXTRASENSORY, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK},
    [SPECIES_GLALIE] = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL},
    [SPECIES_LUDICOLO] = {MOVE_THUNDER_PUNCH, MOVE_ICE_BEAM, MOVE_KNOCK_OFF},
    [SPECIES_HYPNO] = {MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_DAZZLING_GLEAM},
    [SPECIES_GOLEM] = {MOVE_DOUBLE_EDGE},
    [SPECIES_RHYDON] = {MOVE_MEGAHORN, MOVE_BRICK_BREAK, MOVE_DOUBLE_EDGE},
    [SPECIES_ALAKAZAM] = {MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_FIRE_PUNCH, MOVE_DAZZLING_GLEAM, MOVE_KNOCK_OFF},
    [SPECIES_WEEZING] = {MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT},
    [SPECIES_KANGASKHAN] = {MOVE_BRICK_BREAK, MOVE_SHADOW_BALL, MOVE_EARTHQUAKE},
    [SPECIES_ELECTABUZZ] = {MOVE_ICE_PUNCH, MOVE_CROSS_CHOP, MOVE_FIRE_PUNCH, MOVE_PSYCHIC},
    [SPECIES_TAUROS] = {MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE, MOVE_ROCK_SLIDE, MOVE_FIRE_BLAST, MOVE_BLIZZARD},
    [SPECIES_SLOWBRO] = {MOVE_ICE_BEAM, MOVE_FIRE_BLAST},
    [SPECIES_SLOWKING] = {MOVE_ICE_BEAM, MOVE_FIRE_BLAST},
    [SPECIES_MILTANK] = {MOVE_SHADOW_BALL},
    [SPECIES_ALTARIA] = {MOVE_FLAMETHROWER, MOVE_MOONBLAST, MOVE_EARTHQUAKE},
    [SPECIES_NIDOQUEEN] = {MOVE_BODY_SLAM, MOVE_ROCK_SLIDE, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_ICE_BEAM, MOVE_CRUNCH, MOVE_SHADOW_BALL},
    [SPECIES_NIDOKING] = {MOVE_STONE_EDGE, MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_ICE_BEAM, MOVE_SURF, MOVE_MEGAHORN, MOVE_THUNDERBOLT},
    [SPECIES_MAGMAR] = {MOVE_THUNDER_PUNCH, MOVE_CROSS_CHOP, MOVE_PSYCHIC, MOVE_IRON_TAIL},
    [SPECIES_CRADILY] = {MOVE_EARTHQUAKE},
    [SPECIES_ARMALDO] = {MOVE_KNOCK_OFF, MOVE_EARTHQUAKE},
    [SPECIES_GOLDUCK] = {MOVE_CROSS_CHOP, MOVE_ICE_BEAM, MOVE_PSYCHIC},
    [SPECIES_RAPIDASH] = {MOVE_DOUBLE_KICK, MOVE_EGG_BOMB, MOVE_SOLAR_BEAM},
    [SPECIES_DEWGONG] = {MOVE_DRILL_RUN, MOVE_DAZZLING_GLEAM},
    [SPECIES_MUK] = {MOVE_BODY_SLAM, MOVE_BRICK_BREAK, MOVE_FIRE_BLAST, MOVE_ICE_PUNCH, MOVE_SHADOW_BALL},
    [SPECIES_GENGAR] = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_GIGA_DRAIN, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH},
    [SPECIES_AMPHAROS] = {MOVE_FIRE_PUNCH, MOVE_DAZZLING_GLEAM},
    [SPECIES_SCIZOR] = {MOVE_SUPERPOWER},
    [SPECIES_HERACROSS] = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
    [SPECIES_URSARING] = {MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_FIRE_PUNCH, MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_ROCK_SLIDE},
    [SPECIES_HOUNDOOM] = {MOVE_SOLAR_BEAM},
    [SPECIES_DONPHAN] = {MOVE_ROCK_SLIDE, MOVE_GUNK_SHOT, MOVE_SUPERPOWER},
    [SPECIES_CLAYDOL] = {MOVE_ROCK_SLIDE, MOVE_SHADOW_BALL, MOVE_ICE_BEAM, MOVE_DAZZLING_GLEAM},
    [SPECIES_WAILORD] = {MOVE_IRON_HEAD, MOVE_ICE_BEAM},
    [SPECIES_NINETALES] = {MOVE_SOLAR_BEAM, MOVE_ENERGY_BALL, MOVE_EXTRASENSORY, MOVE_DARK_PULSE},
    [SPECIES_MACHAMP] = {MOVE_CROSS_CHOP, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_FIRE_BLAST},
    [SPECIES_STEELIX] = {MOVE_ROCK_SLIDE},
    [SPECIES_TENTACRUEL] = {MOVE_GIGA_DRAIN, MOVE_ICE_BEAM},
    [SPECIES_AERODACTYL] = {MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE},
    [SPECIES_PORYGON2] = {MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_SHADOW_BALL, MOVE_PSYCHIC},
    [SPECIES_GARDEVOIR] = {MOVE_KNOCK_OFF, MOVE_FIRE_PUNCH},
    [SPECIES_EXEGGUTOR] = {MOVE_SOLAR_BEAM, MOVE_ANCIENT_POWER, MOVE_EARTHQUAKE},
    [SPECIES_STARMIE] = {MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
    [SPECIES_FLYGON] = {MOVE_ROCK_SLIDE, MOVE_BOOMBURST, MOVE_SUPERPOWER, MOVE_FLAMETHROWER},
    [SPECIES_VENUSAUR] = {MOVE_WEATHER_BALL, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE},
    [SPECIES_VAPOREON] = {MOVE_ICE_BEAM, MOVE_BITE},
    [SPECIES_FLAREON] = {MOVE_SUPERPOWER, MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL, MOVE_QUICK_ATTACK},
    [SPECIES_MEGANIUM] = {MOVE_SOLAR_BEAM, MOVE_EARTHQUAKE},
    [SPECIES_ESPEON] = {MOVE_DAZZLING_GLEAM, MOVE_BITE},
    [SPECIES_UMBREON] = {MOVE_BODY_SLAM, MOVE_SHADOW_BALL},
    [SPECIES_BLASTOISE] = {MOVE_ICE_BEAM, MOVE_BRICK_BREAK, MOVE_EARTHQUAKE},
    [SPECIES_FERALIGATR] = {MOVE_ICE_BEAM, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
    [SPECIES_AGGRON] = {MOVE_HEAD_SMASH, MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE},
    [SPECIES_BLAZIKEN] = {MOVE_SOLAR_BEAM, MOVE_KNOCK_OFF, MOVE_THUNDER_PUNCH, MOVE_EARTHQUAKE, MOVE_HI_JUMP_KICK, MOVE_ROCK_SLIDE},
    [SPECIES_WALREIN] = {MOVE_EARTHQUAKE},
    [SPECIES_SCEPTILE] = {MOVE_CRUNCH, MOVE_THUNDER_PUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_X_SCISSOR},
    [SPECIES_CHARIZARD] = {MOVE_SOLAR_BEAM, MOVE_THUNDER_PUNCH, MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW, MOVE_CRUNCH, MOVE_BRICK_BREAK},
    [SPECIES_TYPHLOSION] = {MOVE_SOLAR_BEAM, MOVE_THUNDER_PUNCH, MOVE_EARTHQUAKE, MOVE_EXTRASENSORY},
    [SPECIES_LAPRAS] = {MOVE_THUNDERBOLT, MOVE_EARTHQUAKE, MOVE_PSYCHIC},
    [SPECIES_CROBAT] = {MOVE_BRAVE_BIRD, MOVE_SHADOW_BALL, MOVE_STEEL_WING},
    [SPECIES_SWAMPERT] = {MOVE_ROCK_SLIDE, MOVE_ICE_BEAM},
    [SPECIES_GYARADOS] = {MOVE_EGG_BOMB, MOVE_EARTHQUAKE, MOVE_BOUNCE},
    [SPECIES_SNORLAX] = {MOVE_SHADOW_BALL, MOVE_EARTHQUAKE, MOVE_BRICK_BREAK},
    [SPECIES_KINGDRA] = {MOVE_ICE_BEAM},
    [SPECIES_BLISSEY] = {MOVE_SEISMIC_TOSS, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_FLAMETHROWER},
    [SPECIES_MILOTIC] = {MOVE_ICE_BEAM},
    [SPECIES_ARCANINE] = {MOVE_EXTREME_SPEED, MOVE_CRUNCH, MOVE_SOLAR_BEAM},
    [SPECIES_SALAMENCE] = {MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_ROCK_SLIDE, MOVE_FLAMETHROWER, MOVE_CRUNCH, MOVE_HYDRO_PUMP},
    [SPECIES_METAGROSS] = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_THUNDER_PUNCH},
    [SPECIES_SLAKING] = {MOVE_SHADOW_BALL, MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_ICE_BEAM},
    [SPECIES_ARTICUNO] = {MOVE_WATER_PULSE, MOVE_EXTRASENSORY, MOVE_DOUBLE_EDGE, MOVE_ANCIENT_POWER},
    [SPECIES_ZAPDOS] = {MOVE_HEAT_WAVE},
    [SPECIES_MOLTRES] = {MOVE_BRAVE_BIRD, MOVE_ANCIENT_POWER, MOVE_SOLAR_BEAM},
    [SPECIES_RAIKOU] = {MOVE_EXTRASENSORY, MOVE_CRUNCH, MOVE_EXTREME_SPEED},
    [SPECIES_ENTEI] = {MOVE_SOLAR_BEAM, MOVE_STONE_EDGE, MOVE_SHADOW_BALL, MOVE_EXTREME_SPEED, MOVE_CRUNCH},
    [SPECIES_SUICUNE] = {MOVE_ICE_BEAM},
    [SPECIES_REGIROCK] = {MOVE_SUPERPOWER, MOVE_EARTHQUAKE, MOVE_BRICK_BREAK},
    [SPECIES_REGICE] = {MOVE_THUNDERBOLT},
    [SPECIES_REGISTEEL] = {MOVE_SUPERPOWER, MOVE_EARTHQUAKE, MOVE_SEISMIC_TOSS},
    [SPECIES_LATIAS] = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT},
    [SPECIES_LATIOS] = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL},
    [SPECIES_DRAGONITE] = {MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_SURF, MOVE_EXTREME_SPEED},
    [SPECIES_TYRANITAR] = {MOVE_EARTHQUAKE, MOVE_FLAMETHROWER, MOVE_ICE_BEAM, MOVE_THUNDERBOLT},
    [SPECIES_WINTASS] = {MOVE_THUNDERBOLT, MOVE_ENERGY_BALL, MOVE_ROCK_BLAST, MOVE_MUD_SHOT, MOVE_METEOR_MASH},
    [SPECIES_GROOKEY] = {MOVE_KNOCK_OFF},
    [SPECIES_SILICOBRA] = {MOVE_POISON_TAIL},
    [SPECIES_G_BUTTERFREE] = {MOVE_PSYCHIC, MOVE_ENERGY_BALL},
    [SPECIES_MEGA_BEEDRILL] = {MOVE_BRICK_BREAK, MOVE_DRILL_RUN},
    [SPECIES_MEGA_PIDGEOT] = {MOVE_BRAVE_BIRD, MOVE_HEAT_WAVE, MOVE_BLIZZARD},
    [SPECIES_ALOLAN_RATICATE] = {MOVE_SHADOW_BALL},
    [SPECIES_ALOLAN_RAICHU] = {MOVE_SURF},
    [SPECIES_ALOLAN_SANDSLASH] = {MOVE_EARTHQUAKE, MOVE_LEECH_LIFE},
    [SPECIES_ALOLAN_VULPIX] = {MOVE_MOONBLAST},
    [SPECIES_ALOLAN_NINETALES] = {MOVE_EXTRASENSORY, MOVE_DARK_PULSE},
    [SPECIES_ALOLAN_DIGLETT] = {MOVE_ROCK_TOMB},
    [SPECIES_ALOLAN_DUGTRIO] = {MOVE_SLUDGE_BOMB, MOVE_STONE_EDGE},
    [SPECIES_ALOLAN_MEOWTH] = {MOVE_THUNDERBOLT},
    [SPECIES_ALOLAN_PERSIAN] = {MOVE_THUNDERBOLT, MOVE_ICY_WIND},
    [SPECIES_GALAR_MEOWTH] = {MOVE_DIG},
    [SPECIES_PERSERKER] = {MOVE_SUPERPOWER, MOVE_SHADOW_BALL, MOVE_DOUBLE_EDGE},
    [SPECIES_ALOLAN_GEODUDE] = {MOVE_MAGNITUDE},
    [SPECIES_ALOLAN_GRAVELER] = {MOVE_MAGNITUDE},
    [SPECIES_ALOLAN_GOLEM] = {MOVE_EARTHQUAKE},
    [SPECIES_GALAR_PONYTA] = {MOVE_DAZZLING_GLEAM},
    [SPECIES_GALAR_FARFETCH] = {MOVE_SLASH, MOVE_BRAVE_BIRD, MOVE_SUPERPOWER},
    [SPECIES_SIRFETCH] = {MOVE_DOUBLE_EDGE, MOVE_BRAVE_BIRD, MOVE_SUPERPOWER, MOVE_STEEL_WING},
    [SPECIES_ALOLAN_MUK] = {MOVE_BRICK_BREAK, MOVE_SHADOW_BALL},
    [SPECIES_G_KINGLER] = {MOVE_ROCK_SLIDE, MOVE_DOUBLE_EDGE, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE},
    [SPECIES_ALOLAN_EXEGGUTOR] = {MOVE_FLAMETHROWER, MOVE_KNOCK_OFF},
    [SPECIES_ALOLAN_MAROWAK] = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
    [SPECIES_LICKILICKY] = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_KNOCK_OFF, MOVE_FLAMETHROWER},
    [SPECIES_GALAR_WEEZING] = {MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_DARK_PULSE},
    [SPECIES_RHYPERIOR] = {MOVE_MEGAHORN, MOVE_STONE_EDGE, MOVE_DOUBLE_EDGE},
    [SPECIES_TANGROWTH] = {MOVE_SOLAR_BEAM, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE, MOVE_SLUDGE_BOMB},
    [SPECIES_GALAR_MRMIME] = {MOVE_THUNDERBOLT, MOVE_DAZZLING_GLEAM},
    [SPECIES_MRRIME] = {MOVE_DAZZLING_GLEAM, MOVE_THUNDERBOLT},
    [SPECIES_ELECTIVIRE] = {MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_CROSS_CHOP, MOVE_ROCK_SLIDE, MOVE_PSYCHIC, MOVE_FLAMETHROWER},
    [SPECIES_MAGMORTAR] = {MOVE_THUNDERBOLT, MOVE_CROSS_CHOP, MOVE_EARTHQUAKE, MOVE_PSYCHIC, MOVE_SOLAR_BEAM},
    [SPECIES_LEAFEON] = {MOVE_KNOCK_OFF, MOVE_MUD_SHOT, MOVE_SHADOW_BALL, MOVE_X_SCISSOR, MOVE_EGG_BOMB},
    [SPECIES_GLACEON] = {MOVE_WATER_PULSE, MOVE_BITE},
    [SPECIES_SYLVEON] = {MOVE_MAGICAL_LEAF, MOVE_BITE, MOVE_PSYCHIC},
    [SPECIES_TOGEKISS] = {MOVE_FLAMETHROWER, MOVE_WATER_PULSE, MOVE_PSYCHIC},
    [SPECIES_AMBIPOM] = {MOVE_SHADOW_BALL, MOVE_BRICK_BREAK},
    [SPECIES_YANMEGA] = {MOVE_SHADOW_BALL, MOVE_ANCIENT_POWER, MOVE_GIGA_DRAIN, MOVE_PSYCHIC},
    [SPECIES_HONCHKROW] = {MOVE_BRAVE_BIRD, MOVE_SUPERPOWER, MOVE_SHADOW_BALL, MOVE_HEAT_WAVE, MOVE_PSYCHIC},
    [SPECIES_MISMAGIUS] = {MOVE_DAZZLING_GLEAM, MOVE_THUNDERBOLT, MOVE_PSYCHIC, MOVE_ENERGY_BALL},
    [SPECIES_GLISCOR] = {MOVE_ROCK_SLIDE},
    [SPECIES_WEAVILE] = {MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_AERIAL_ACE, MOVE_X_SCISSOR},
    [SPECIES_MAMOSWINE] = {MOVE_STONE_EDGE, MOVE_DOUBLE_EDGE},
    [SPECIES_GALAR_CORSOLA] = {MOVE_NIGHT_SHADE},
    [SPECIES_CURSOLA] = {MOVE_ICE_BEAM, MOVE_GIGA_DRAIN, MOVE_SURF, MOVE_PSYCHIC, MOVE_EARTHQUAKE, MOVE_STONE_EDGE},
    [SPECIES_MEGA_HOUNDOOM] = {MOVE_SOLAR_BEAM},
    [SPECIES_PORYGON_Z] = {MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_PSYCHIC, MOVE_DARK_PULSE},
    [SPECIES_CELEBI] = {MOVE_DAZZLING_GLEAM, MOVE_SHADOW_BALL, MOVE_ANCIENT_POWER, MOVE_SOLAR_BEAM},
    [SPECIES_OBSTAGOON] = {MOVE_CROSS_CHOP, MOVE_SHADOW_BALL},
    [SPECIES_PROBOPASS] = {MOVE_ICE_PUNCH, MOVE_THUNDERBOLT, MOVE_FIRE_PUNCH, MOVE_HEAD_SMASH, MOVE_EARTHQUAKE},
    [SPECIES_MEGA_SABLEYE] = {MOVE_NIGHT_SHADE, MOVE_DAZZLING_GLEAM, MOVE_BRICK_BREAK},
    [SPECIES_GALLADE] = {MOVE_SHADOW_BALL, MOVE_EARTHQUAKE, MOVE_STONE_EDGE},
    [SPECIES_MEGA_MAWILE] = {MOVE_BRICK_BREAK, MOVE_ROCK_SLIDE},
    [SPECIES_ROSERADE] = {MOVE_DAZZLING_GLEAM, MOVE_EXTRASENSORY, MOVE_SOLAR_BEAM},
    [SPECIES_MEGA_SHARPEDO] = {MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER},
    [SPECIES_MEGA_CAMERUPT] = {MOVE_ROCK_SLIDE, MOVE_SOLAR_BEAM},
    [SPECIES_MEGA_ALTARIA] = {MOVE_FIRE_BLAST, MOVE_EARTHQUAKE},
    [SPECIES_MEGA_BANETTE] = {MOVE_GUNK_SHOT, MOVE_LEECH_LIFE},
    [SPECIES_DUSKNOIR] = {MOVE_SEISMIC_TOSS, MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_ICE_BEAM, MOVE_THUNDER_PUNCH},
    [SPECIES_MEGA_ABSOL] = {MOVE_STONE_EDGE, MOVE_SHADOW_BALL, MOVE_SUPERPOWER, MOVE_IRON_TAIL, MOVE_ICE_BEAM, MOVE_THUNDERBOLT},
    [SPECIES_MEGA_GLALIE] = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_DARK_PULSE, MOVE_WATER_PULSE},
    [SPECIES_FROSLASS] = {MOVE_CRUNCH, MOVE_THUNDERBOLT, MOVE_WATER_PULSE},
    [SPECIES_REGIGIGAS] = {MOVE_ROCK_SLIDE},
    [SPECIES_REGIELEKI] = {MOVE_ANCIENT_POWER},
    [SPECIES_REGIDRAGO] = {MOVE_CRUNCH, MOVE_ANCIENT_POWER},
    [SPECIES_JIRACHI] = {MOVE_SHADOW_BALL, MOVE_ANCIENT_POWER, MOVE_BODY_SLAM, MOVE_THUNDERBOLT, MOVE_FIRE_PUNCH, MOVE_ENERGY_BALL, MOVE_ICE_PUNCH},
    [SPECIES_MUNCHLAX] = {MOVE_SHADOW_BALL},
    [SPECIES_MANTYKE] = {MOVE_ICE_BEAM},
    [SPECIES_FLOETTE] = {MOVE_LIGHT_OF_RUIN, MOVE_ENERGY_BALL, MOVE_PSYCHIC},
    [SPECIES_WOOLOO] = {MOVE_EARTHQUAKE},
    [SPECIES_YAMASK] = {MOVE_KNOCK_OFF},
    [SPECIES_COFAGRIGUS] = {MOVE_KNOCK_OFF, MOVE_NIGHT_SHADE, MOVE_ENERGY_BALL, MOVE_PSYCHIC},
    [SPECIES_RUNERIGUS] = {MOVE_STONE_EDGE},
    [SPECIES_ABOMASNOW] = {MOVE_EARTHQUAKE},
    [SPECIES_MEGA_ABOMASNOW] = {MOVE_EARTHQUAKE, MOVE_WATER_PULSE, MOVE_ROCK_SLIDE},
    [SPECIES_THWACKEY] = {MOVE_KNOCK_OFF},
    [SPECIES_RILLABOOM] = {MOVE_BOOMBURST, MOVE_EARTHQUAKE, MOVE_SUPERPOWER},
    [SPECIES_GOLETT] = {MOVE_DYNAMIC_PUNCH},
    [SPECIES_GOLURK] = {MOVE_DYNAMIC_PUNCH},
    [SPECIES_TYRUNT] = {MOVE_POISON_FANG},
    [SPECIES_TYRANTRUM] = {MOVE_EARTHQUAKE, MOVE_SUPERPOWER, MOVE_AERIAL_ACE, MOVE_HEAD_SMASH},
    [SPECIES_AMAURA] = {MOVE_THUNDERBOLT},
    [SPECIES_AURORUS] = {MOVE_THUNDERBOLT, MOVE_WATER_PULSE, MOVE_EARTHQUAKE, MOVE_IRON_HEAD},
    [SPECIES_DEINO] = {MOVE_SUPERPOWER, MOVE_HEAD_SMASH},
    [SPECIES_ZWEILOUS] = {MOVE_SUPERPOWER, MOVE_HEAD_SMASH},
    [SPECIES_HYDREIGON] = {MOVE_FLAMETHROWER, MOVE_SURF, MOVE_IRON_TAIL},
    [SPECIES_JANGMO_O] = {MOVE_BRICK_BREAK},
    [SPECIES_HAKAMO_O] = {MOVE_ROCK_TOMB},
    [SPECIES_KOMMO_O] = {MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_BOOMBURST, MOVE_FLAMETHROWER, MOVE_ICE_PUNCH},
    [SPECIES_DRAKLOAK] = {MOVE_STEEL_WING},
    [SPECIES_DRAGAPULT] = {MOVE_STEEL_WING, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT},
    [SPECIES_DRAPION] = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
    [SPECIES_RIOLU] = {MOVE_ROCK_TOMB},
    [SPECIES_LUCARIO] = {MOVE_HI_JUMP_KICK, MOVE_SHADOW_BALL, MOVE_EXTREME_SPEED, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
    [SPECIES_TYNAMO] = {MOVE_KNOCK_OFF, MOVE_GIGA_DRAIN},
    [SPECIES_EELEKTRIK] = {MOVE_GIGA_DRAIN, MOVE_KNOCK_OFF},
    [SPECIES_EELEKTROSS] = {MOVE_GIGA_DRAIN, MOVE_FLAMETHROWER, MOVE_KNOCK_OFF, MOVE_ROCK_SLIDE, MOVE_IRON_TAIL},
    [SPECIES_CHARJABUG] = {MOVE_CRUNCH},
    [SPECIES_VIKAVOLT] = {MOVE_ENERGY_BALL, MOVE_CRUNCH},
    [SPECIES_LITWICK] = {MOVE_NIGHT_SHADE},
    [SPECIES_LAMPENT] = {MOVE_ENERGY_BALL, MOVE_NIGHT_SHADE},
    [SPECIES_CHANDELURE] = {MOVE_ENERGY_BALL, MOVE_PSYCHIC, MOVE_SOLAR_BEAM},
    [SPECIES_ROWLET] = {MOVE_BRAVE_BIRD},
    [SPECIES_DARTRIX] = {MOVE_BRAVE_BIRD, MOVE_KNOCK_OFF},
    [SPECIES_DECIDUEYE] = {MOVE_BRAVE_BIRD, MOVE_KNOCK_OFF, MOVE_STEEL_WING},
    [SPECIES_POPPLIO] = {MOVE_ICE_BEAM},
    [SPECIES_BRIONNE] = {MOVE_ICE_BEAM},
    [SPECIES_PRIMARINA] = {MOVE_ICE_BEAM, MOVE_PSYCHIC},
    [SPECIES_SOBBLE] = {MOVE_ICE_BEAM},
    [SPECIES_DRIZZILE] = {MOVE_ICE_BEAM},
    [SPECIES_INTELEON] = {MOVE_ICE_BEAM, MOVE_DARK_PULSE},
    [SPECIES_TORTERRA] = {MOVE_ROCK_SLIDE, MOVE_IRON_TAIL},
    [SPECIES_PIPLUP] = {MOVE_ICY_WIND},
    [SPECIES_PRINPLUP] = {MOVE_ICY_WIND},
    [SPECIES_EMPOLEON] = {MOVE_KNOCK_OFF, MOVE_ICE_BEAM, MOVE_EARTHQUAKE},
    [SPECIES_DHELMISE] = {MOVE_IRON_HEAD, MOVE_EARTHQUAKE, MOVE_BRICK_BREAK},
    [SPECIES_BISHARP] = {MOVE_BRICK_BREAK, MOVE_STONE_EDGE, MOVE_X_SCISSOR},
    [SPECIES_GRIMMSNARL] = {MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_SUPERPOWER, MOVE_BODY_SLAM, MOVE_LEECH_LIFE},
    [SPECIES_SALAZZLE] = {MOVE_KNOCK_OFF, MOVE_DRAGON_CLAW, MOVE_LEECH_LIFE},
    [SPECIES_PALOSSAND] = {MOVE_GIGA_DRAIN, MOVE_PSYCHIC},
    [SPECIES_FERROTHORN] = {MOVE_REVENGE, MOVE_KNOCK_OFF},
    [SPECIES_KROOKODILE] = {MOVE_ROCK_SLIDE, MOVE_SLUDGE_BOMB, MOVE_SUPERPOWER},
    [SPECIES_TOXICROAK] = {MOVE_CROSS_CHOP, MOVE_SHADOW_BALL, MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
    [SPECIES_LILLIPUP] = {MOVE_SHADOW_BALL},
    [SPECIES_STOUTLAND] = {MOVE_SHADOW_BALL, MOVE_SUPERPOWER, MOVE_IRON_HEAD},
    [SPECIES_SIZZLIPEDE] = {MOVE_KNOCK_OFF},
    [SPECIES_CENTISKORCH] = {MOVE_KNOCK_OFF, MOVE_SOLAR_BEAM},
    [SPECIES_CORVISQUIRE] = {MOVE_BRAVE_BIRD},
    [SPECIES_CORVIKNIGHT] = {MOVE_BRAVE_BIRD},
    [SPECIES_HAWLUCHA] = {MOVE_HI_JUMP_KICK, MOVE_STONE_EDGE, MOVE_BRAVE_BIRD, MOVE_IRON_HEAD},
    [SPECIES_DURANT] = {MOVE_STONE_EDGE, MOVE_SUPERPOWER},
    [SPECIES_FROSMOTH] = {MOVE_GIGA_DRAIN, MOVE_DAZZLING_GLEAM},
    [SPECIES_TOXTRICITY] = {MOVE_BOOMBURST, MOVE_FIRE_PUNCH},
    [SPECIES_TOXTRICITY_LK] = {MOVE_BOOMBURST, MOVE_FIRE_PUNCH},
    [SPECIES_APPLIN] = {MOVE_ASTONISH},
    [SPECIES_FLAPPLE] = {MOVE_EGG_BOMB, MOVE_FLY},
    [SPECIES_APPLETUN] = {MOVE_EARTHQUAKE, MOVE_BODY_SLAM},
    [SPECIES_DURALUDON] = {MOVE_THUNDERBOLT, MOVE_DARK_PULSE, MOVE_BRICK_BREAK},
    [SPECIES_WHIMSICOTT] = {MOVE_PSYCHIC, MOVE_KNOCK_OFF},
    [SPECIES_SANDACONDA] = {MOVE_STONE_EDGE, MOVE_IRON_HEAD},
    [SPECIES_PANGORO] = {MOVE_GUNK_SHOT, MOVE_STONE_EDGE, MOVE_EARTHQUAKE},
    [SPECIES_SKRELP] = {MOVE_THUNDERBOLT},
    [SPECIES_DRAGALGE] = {MOVE_HYDRO_PUMP, MOVE_THUNDERBOLT, MOVE_SHADOW_BALL, MOVE_IRON_TAIL},
    [SPECIES_BEWEAR] = {MOVE_EARTHQUAKE, MOVE_IRON_HEAD},
    [SPECIES_GOURGEIST] = {MOVE_ROCK_SLIDE, MOVE_FIRE_BLAST, MOVE_MOONBLAST},
    [SPECIES_FRILLISH] = {MOVE_ICY_WIND, MOVE_NIGHT_SHADE},
    [SPECIES_JELLICENT] = {MOVE_ENERGY_BALL, MOVE_DAZZLING_GLEAM, MOVE_NIGHT_SHADE},
    [SPECIES_LYCANROC_DAY] = {MOVE_BRICK_BREAK},
    [SPECIES_LYCANROC_NIGHT] = {MOVE_STONE_EDGE, MOVE_DYNAMIC_PUNCH, MOVE_IRON_TAIL},
    [SPECIES_LYCANROC_DUSK] = {MOVE_BRICK_BREAK, MOVE_DRILL_RUN},
    [SPECIES_SERPERIOR] = {MOVE_KNOCK_OFF, MOVE_OUTRAGE},
    [SPECIES_ALCREMIE] = {MOVE_ENERGY_BALL, MOVE_PSYCHIC},
    [SPECIES_CHESPIN] = {MOVE_BRICK_BREAK},
    [SPECIES_CHESNAUGHT] = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
    [SPECIES_INFERNAPE] = {MOVE_ROCK_SLIDE, MOVE_THUNDER_PUNCH, MOVE_SOLAR_BEAM},
    [SPECIES_GOOMY] = {MOVE_SLUDGE_BOMB, MOVE_THUNDERBOLT},
    [SPECIES_GOODRA] = {MOVE_SLUDGE_BOMB, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_SUPERPOWER},
    [SPECIES_STUNFISK] = {MOVE_ROCK_SLIDE},
    [SPECIES_GALAR_STUNFISK] = {MOVE_ROCK_SLIDE},
    [SPECIES_SOLOSIS] = {MOVE_NIGHT_SHADE},
    [SPECIES_DUOSION] = {MOVE_NIGHT_SHADE},
    [SPECIES_REUNICLUS] = {MOVE_THUNDERBOLT, MOVE_ENERGY_BALL, MOVE_KNOCK_OFF, MOVE_ICE_PUNCH, MOVE_FIRE_PUNCH},
    [SPECIES_VULLABY] = {MOVE_ROCK_TOMB},
    [SPECIES_MANDIBUZZ] = {MOVE_HEAT_WAVE},
    [SPECIES_DRILBUR] = {MOVE_BRICK_BREAK, MOVE_SLUDGE_BOMB, MOVE_ROCK_TOMB},
    [SPECIES_EXCADRILL] = {MOVE_X_SCISSOR, MOVE_ROCK_SLIDE},
    [SPECIES_MEWTWO] = {MOVE_ICE_BEAM, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_SHADOW_BALL},
    [SPECIES_MEW] = {MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_DARK_PULSE},
    [SPECIES_LUGIA] = {MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_AEROBLAST, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL},
    [SPECIES_HO_OH] = {MOVE_THUNDERBOLT, MOVE_GIGA_DRAIN, MOVE_BRAVE_BIRD, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL},
    [SPECIES_KYOGRE] = {MOVE_WATER_SPOUT, MOVE_THUNDER, MOVE_ICE_BEAM},
    [SPECIES_GROUDON] = {MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK, MOVE_FLAMETHROWER, MOVE_SOLAR_BEAM},
    [SPECIES_RAYQUAZA] = {MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_SURF, MOVE_EARTHQUAKE, MOVE_EXTREME_SPEED},
    [SPECIES_DEOXYS] = {MOVE_PSYCHO_BOOST, MOVE_EXTREME_SPEED, MOVE_KNOCK_OFF, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_SUPERPOWER, MOVE_DARK_PULSE},
    [SPECIES_DEOXYS_ATTACK] = {MOVE_PSYCHO_BOOST, MOVE_EXTREME_SPEED, MOVE_KNOCK_OFF, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_SUPERPOWER, MOVE_DARK_PULSE},
    [SPECIES_DEOXYS_SPEED] = {MOVE_PSYCHO_BOOST, MOVE_EXTREME_SPEED, MOVE_KNOCK_OFF, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_SUPERPOWER, MOVE_DARK_PULSE},
    [SPECIES_DEOXYS_DEFENSE] = {MOVE_SEISMIC_TOSS},
    [SPECIES_WYRDEER]       = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_JUMP_KICK, MOVE_ENERGY_BALL, MOVE_THUNDERBOLT},
    [SPECIES_KLEAVOR]       = {MOVE_SUPERPOWER},
    [SPECIES_URSALUNA]      = {MOVE_CROSS_CHOP, MOVE_STONE_EDGE},
    [SPECIES_SNEASLER]      = {MOVE_SHADOW_BALL, MOVE_ROCK_SLIDE},
    [SPECIES_OVERQWIL]      = {MOVE_SHADOW_BALL},
    [SPECIES_GROWLITHE_HISUIAN] = {MOVE_IRON_HEAD, MOVE_HEAD_SMASH},
    [SPECIES_ARCANINE_HISUIAN] = {MOVE_EXTREME_SPEED, MOVE_IRON_HEAD, MOVE_HEAD_SMASH},
    [SPECIES_SLOWPOKE_GALARIAN] = {MOVE_FLAMETHROWER},
    [SPECIES_SLOWBRO_GALARIAN] = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_FLAMETHROWER, MOVE_EARTHQUAKE},
    [SPECIES_SLOWKING_GALARIAN] = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_FLAMETHROWER},
    [SPECIES_DECIDUEYE_HISUIAN] = {MOVE_BRAVE_BIRD, MOVE_KNOCK_OFF},
    [SPECIES_TYPHLOSION_HISUIAN] = {MOVE_SOLAR_BEAM, MOVE_THUNDER_PUNCH, MOVE_EXTRASENSORY},
    [SPECIES_SNEASEL_HISUIAN] = {MOVE_SHADOW_BALL},
    [SPECIES_QWILFISH_HISUIAN] = {MOVE_SHADOW_BALL},
    [SPECIES_GOODRA_HISUIAN] = {MOVE_THUNDERBOLT, MOVE_FIRE_BLAST, MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE},
    [SPECIES_KINGAMBIT] = {MOVE_BRICK_BREAK, MOVE_STONE_EDGE, MOVE_X_SCISSOR},
    [SPECIES_DUDUNSPARCE] = {MOVE_ROCK_SLIDE, MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_BOOMBURST},
    [SPECIES_TAUROS_PALDEAN_FIGHT] = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SUPERPOWER, MOVE_MEGAHORN},
    [SPECIES_TAUROS_PALDEAN_AQUA] = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SUPERPOWER, MOVE_MEGAHORN},
    [SPECIES_TAUROS_PALDEAN_BLAZE] = {MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_SUPERPOWER, MOVE_MEGAHORN},
    [SPECIES_ANNIHILAPE] = {MOVE_EARTHQUAKE, MOVE_GUNK_SHOT},
    [SPECIES_FARIGIRAF] = {MOVE_DAZZLING_GLEAM, MOVE_CRUNCH, MOVE_THUNDERBOLT},
    [SPECIES_COUREEN] = {MOVE_BOOMBURST, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_FIRE_PUNCH, MOVE_IRON_HEAD, MOVE_ENERGY_BALL, MOVE_MOONBLAST},
    [SPECIES_KINCURS] = {MOVE_STONE_EDGE},
    [SPECIES_POSORD] = {MOVE_GUNK_SHOT, MOVE_BRICK_BREAK},
    [SPECIES_NUMEL_LUCKY] = {MOVE_ROCK_TOMB},
    [SPECIES_CAMERUPT_LUCKY] = {MOVE_STONE_EDGE, MOVE_MUDDY_WATER},
    [SPECIES_MEGA_CAMERUPT_LUCKY] = {MOVE_STONE_EDGE, MOVE_MUDDY_WATER, MOVE_IRON_HEAD},
	[SPECIES_GARBODOR] = {MOVE_THUNDERBOLT},
	[SPECIES_GIGA_GARBODOR] = {MOVE_EARTHQUAKE, MOVE_THUNDERBOLT, MOVE_HEAT_WAVE, MOVE_PSYCHIC, MOVE_DARK_PULSE},
	[SPECIES_PANSAGE] = {MOVE_KNOCK_OFF},
	[SPECIES_SIMISAGE] = {MOVE_KNOCK_OFF, MOVE_SUPERPOWER, MOVE_GUNK_SHOT},
	[SPECIES_ZARUDE] = {MOVE_ROCK_SLIDE, MOVE_SUPERPOWER},
	[SPECIES_ARCHALUDON] = {MOVE_EARTHQUAKE, MOVE_THUNDERBOLT, MOVE_ROCK_SLIDE, MOVE_DARK_PULSE},
	[SPECIES_KILOWATTREL] = {MOVE_BRAVE_BIRD, MOVE_WEATHER_BALL},
	[SPECIES_HYDRAPPLE] = {MOVE_HYDRO_PUMP, MOVE_EARTHQUAKE},
};

#endif