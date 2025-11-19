InsideOfTruck_MapScripts:: @ 823BEDA
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0

InsideOfTruck_OnLoad: @ 823BEE5
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, 0
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, 0
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, 0
	end

InsideOfTruck_OnResume: @ 823BF01
	setstepcallback STEP_CB_TRUCK
	end

InsideOfTruck_EventScript_SetIntroFlags:: @ 823BF04
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq InsideOfTruck_EventScript_SetIntroFlagsMale
	compare VAR_RESULT, FEMALE
	goto_if_eq InsideOfTruck_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_EventScript_SetIntroFlagsMale:: @ 823BF20
	msgbox NombreVecino_Text, MSGBOX_DEFAULT
	special NameRival
	waitstate
	msgbox NombreVecino_Text2, MSGBOX_DEFAULT
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 3, 10
	releaseall
	end

InsideOfTruck_EventScript_SetIntroFlagsFemale:: @ 823BF46
	msgbox NombreVecino_Text, MSGBOX_DEFAULT
	special NameRival
	waitstate
	msgbox NombreVecino_Text2, MSGBOX_DEFAULT
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 12, 10
	releaseall
	end

InsideOfTruck_EventScript_MovingBox:: @ 823BF6C
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end
	
InsideOfTruck_EventScript_PC_Config::
	msgbox InsideOfTruck_Text_PC_Config, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MicolandiaMode
	releaseall
	end
	
MicolandiaMode::
	goto_if_set FLAG_SET_WALL_CLOCK, PlayersHouse_2F_EventScript_CheckWallClock
	msgbox InsideOfTruck_Text_PC_Config1, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	setflag FLAG_SET_WALL_CLOCK
	msgbox InsideOfTruck_Text_PC_Config2, MSGBOX_SIGN
	playbgm CRUELANGELSTHESIS, 1
	message InsideOfTruck_Text_PC_Config3
	waitmessage
	setvar VAR_MUSIC_PLAYER, MUSIC_PLAYER_STATE_LILYCOVE
    setflag FLAG_SYS_POKEMON_GET
    setflag FLAG_SYS_POKEDEX_GET
    setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_SYS_RIBBON_GET 
    setflag FLAG_SYS_B_DASH
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_SYS_DEXNAV_GET
	setflag FLAG_SYS_DETECTOR_MODE
    setflag FLAG_IS_CHAMPION
    setflag FLAG_BADGE01_GET
    setflag FLAG_BADGE02_GET
    setflag FLAG_BADGE03_GET
    setflag FLAG_BADGE04_GET
    setflag FLAG_BADGE05_GET
    setflag FLAG_BADGE06_GET
    setflag FLAG_BADGE07_GET
    setflag FLAG_BADGE08_GET
	setflag FLAG_EXPLANATION_MICOLANDIA
    setflag FLAG_RECEIVED_HM01
    setflag FLAG_RECEIVED_HM02
    setflag FLAG_RECEIVED_HM03
    setflag FLAG_RECEIVED_HM04
    setflag FLAG_RECEIVED_HM05
    setflag FLAG_RECEIVED_HM06
    setflag FLAG_RECEIVED_HM07
    setflag FLAG_RECEIVED_HM08
    
	addmoney 999999, 0
    additem ITEM_LEVEL_CAP, 1
    additem ITEM_MUSIC_PLAYER, 1
    additem ITEM_COIN_CASE, 1
    additem ITEM_ITEMFINDER, 1
    additem ITEM_OLD_ROD, 1
    additem ITEM_GOOD_ROD, 1
    additem ITEM_SUPER_ROD, 1
    additem ITEM_MACH_BIKE, 1
    additem ITEM_ACRO_BIKE, 1
    additem ITEM_G_HP_UP, 1
    additem ITEM_G_PROTEIN, 1
    additem ITEM_G_IRON, 1
    additem ITEM_G_CARBOS, 1
    additem ITEM_G_CALCIUM, 1
    additem ITEM_G_ZINC, 1
    additem ITEM_PP_MAX, 99
    additem ITEM_SWEET_HEART, 1
	additem ITEM_ABILITY_CAPSULE, 1
	// additem ITEM_SECRET_POTION, 1
    additem ITEM_EXP_SHARE, 6
    additem ITEM_AMULET_COIN, 6
    additem ITEM_LUCKY_EGG, 6
    additem ITEM_MACHO_BRACE, 6
    additem ITEM_BRIGHT_POWDER, 50
    additem ITEM_QUICK_CLAW, 50
    additem ITEM_SHELL_BELL, 50
    additem ITEM_KINGS_ROCK, 50
    additem ITEM_SILVER_POWDER, 50
    //additem ITEM_SOUL_DEW, 2
    additem ITEM_FOCUS_BAND, 50
    additem ITEM_SCOPE_LENS, 50
    additem ITEM_METAL_COAT, 50
    additem ITEM_LEFTOVERS, 50
    additem ITEM_DRAGON_SCALE, 50
    additem ITEM_SOFT_SAND, 50
    additem ITEM_HARD_STONE, 50
    additem ITEM_MIRACLE_SEED, 50
    additem ITEM_BLACK_GLASSES, 50
    additem ITEM_BLACK_BELT, 50
    additem ITEM_MAGNET, 50
    additem ITEM_MYSTIC_WATER, 50
    additem ITEM_SHARP_BEAK, 50
    additem ITEM_POISON_BARB, 50
    additem ITEM_NEVER_MELT_ICE, 50
    additem ITEM_SPELL_TAG, 50
    additem ITEM_TWISTED_SPOON, 50
    additem ITEM_CHARCOAL, 50
    additem ITEM_DRAGON_FANG, 50
    additem ITEM_SILK_SCARF, 50
    additem ITEM_PINK_PETAL, 50
   // additem ITEM_UP_GRADE, 50
    additem ITEM_SEA_INCENSE, 50
    additem ITEM_LAX_INCENSE, 50
    additem ITEM_CHOICE_BAND, 50
    additem ITEM_CHOICE_SCARF, 50
    additem ITEM_CHOICE_SPECS, 50
    additem ITEM_FOCUS_SASH, 50
    additem ITEM_MENTAL_HERB, 50
    additem ITEM_POWER_HERB, 50
    additem ITEM_WHITE_HERB, 50
    additem ITEM_LUCKY_PUNCH, 6
    additem ITEM_LIGHT_BALL, 6
    additem ITEM_SOOTHE_BELL, 6
    additem ITEM_TINY_MUSHROOM, 6
    additem ITEM_POKE_DOLL, 6
    additem ITEM_DEEP_SEA_TOOTH, 6
    additem ITEM_DEEP_SEA_SCALE, 6
    additem ITEM_SMOKE_BALL, 6
    additem ITEM_EVERSTONE, 6
    additem ITEM_THICK_CLUB, 6
    additem ITEM_METAL_POWDER, 6
    additem ITEM_CLEANSE_TAG, 6
    additem ITEM_STICK, 6
	additem ITEM_TM01, 1
	additem ITEM_TM02, 1
	additem ITEM_TM03, 1
	additem ITEM_TM04, 1
	additem ITEM_TM05, 1
	additem ITEM_TM06, 1
	additem ITEM_TM07, 1
	additem ITEM_TM08, 1
	additem ITEM_TM09, 1
	additem ITEM_TM10, 1
	additem ITEM_TM11, 1
	additem ITEM_TM12, 1
	additem ITEM_TM13, 1
	additem ITEM_TM14, 1
	additem ITEM_TM15, 1
	additem ITEM_TM16, 1
	additem ITEM_TM17, 1
	additem ITEM_TM18, 1
	additem ITEM_TM19, 1
	additem ITEM_TM20, 1
	additem ITEM_TM21, 1
	additem ITEM_TM22, 1
	additem ITEM_TM23, 1
	additem ITEM_TM24, 1
	additem ITEM_TM25, 1
	additem ITEM_TM26, 1
	additem ITEM_TM27, 1
	additem ITEM_TM28, 1
	additem ITEM_TM29, 1
	additem ITEM_TM30, 1
	additem ITEM_TM31, 1
	additem ITEM_TM32, 1
	additem ITEM_TM33, 1
	additem ITEM_TM34, 1
	additem ITEM_TM35, 1
	additem ITEM_TM36, 1
	additem ITEM_TM37, 1
	additem ITEM_TM38, 1
	additem ITEM_TM39, 1
	additem ITEM_TM40, 1
	additem ITEM_TM41, 1
	additem ITEM_TM42, 1
	additem ITEM_TM43, 1
	additem ITEM_TM44, 1
	additem ITEM_TM45, 1
	additem ITEM_TM46, 1
	additem ITEM_TM47, 1
	additem ITEM_TM48, 1
	additem ITEM_TM49, 1
	additem ITEM_TM50, 1
	additem ITEM_HM01, 1
	additem ITEM_HM02, 1
	additem ITEM_HM03, 1
	additem ITEM_HM04, 1
	additem ITEM_HM05, 1
	additem ITEM_HM06, 1
	additem ITEM_HM07, 1
	additem ITEM_HM08, 1
	additem ITEM_CHERI_BERRY, 99
	additem ITEM_CHESTO_BERRY, 99
	additem ITEM_PECHA_BERRY, 99
	additem ITEM_RAWST_BERRY, 99
	additem ITEM_ASPEAR_BERRY, 99
	additem ITEM_LEPPA_BERRY, 99
	additem ITEM_ORAN_BERRY, 99
	additem ITEM_PERSIM_BERRY, 99
	additem ITEM_LUM_BERRY, 99
	additem ITEM_SITRUS_BERRY, 99
	additem ITEM_FIGY_BERRY, 99
	additem ITEM_WIKI_BERRY, 99
	additem ITEM_MAGO_BERRY, 99
	additem ITEM_AGUAV_BERRY, 99
	additem ITEM_IAPAPA_BERRY, 99
	additem ITEM_RAZZ_BERRY, 99
	additem ITEM_BLUK_BERRY, 99
	additem ITEM_NANAB_BERRY, 99
	additem ITEM_WEPEAR_BERRY, 99
	additem ITEM_PINAP_BERRY, 99
	additem ITEM_POMEG_BERRY, 99
	additem ITEM_KELPSY_BERRY, 99
	additem ITEM_QUALOT_BERRY, 99
	additem ITEM_HONDEW_BERRY, 99
	additem ITEM_GREPA_BERRY, 99
	additem ITEM_TAMATO_BERRY, 99
	additem ITEM_CORNN_BERRY, 99
	additem ITEM_MAGOST_BERRY, 99
	additem ITEM_RABUTA_BERRY, 99
	additem ITEM_NOMEL_BERRY, 99
	additem ITEM_SPELON_BERRY, 99
	additem ITEM_PAMTRE_BERRY, 99
	additem ITEM_WATMEL_BERRY, 99
	additem ITEM_DURIN_BERRY, 99
	additem ITEM_BELUE_BERRY, 99
	additem ITEM_LIECHI_BERRY, 99
	additem ITEM_GANLON_BERRY, 99
	additem ITEM_SALAC_BERRY, 99
	additem ITEM_PETAYA_BERRY, 99
	additem ITEM_APICOT_BERRY, 99
	additem ITEM_LANSAT_BERRY, 99
	additem ITEM_STARF_BERRY, 99	
	givecustommon SPECIES_UNOWN, 60, ITEM_NONE, ITEM_LUXURY_BALL, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE, TRUE, 0
	givecustommon SPECIES_UNOWN, 60, ITEM_NONE, ITEM_LUXURY_BALL, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	givecustommon SPECIES_UNOWN, 60, ITEM_NONE, ITEM_LUXURY_BALL, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	givecustommon SPECIES_UNOWN, 60, ITEM_NONE, ITEM_LUXURY_BALL, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	givecustommon SPECIES_UNOWN, 60, ITEM_NONE, ITEM_LUXURY_BALL, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	givecustommon SPECIES_UNOWN, 60, ITEM_NONE, ITEM_LUXURY_BALL, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	
	message InsideOfTruck_Text_PC_Config4
	waitmessage
	givemon SPECIES_BULBASAUR, 60, ITEM_NONE
    givemon SPECIES_CHARMANDER, 60, ITEM_NONE
    givemon SPECIES_SQUIRTLE, 60, ITEM_NONE
    givemon SPECIES_CATERPIE, 60, ITEM_NONE
    givemon SPECIES_WEEDLE, 60, ITEM_NONE
    givemon SPECIES_PIDGEY, 60, ITEM_NONE
    givemon SPECIES_RATTATA, 60, ITEM_NONE
    givemon SPECIES_ALOLAN_RATTATA, 60, ITEM_NONE
    givemon SPECIES_SPEAROW, 60, ITEM_NONE
    givemon SPECIES_EKANS, 60, ITEM_NONE
    givemon SPECIES_PICHU, 60, ITEM_THUNDER_STONE
    givemon SPECIES_PICHU, 60, ITEM_SHINY_STONE
    givemon SPECIES_PIKACHU, 60, ITEM_LIGHT_BALL
    givemon SPECIES_SANDSHREW, 60, ITEM_NONE
    givemon SPECIES_ALOLAN_SANDSHREW, 60, ITEM_ICE_STONE
    givemon SPECIES_NIDORAN_F, 60, ITEM_MOON_STONE
    givemon SPECIES_NIDORAN_M, 60, ITEM_MOON_STONE
    givemon SPECIES_CLEFFA, 60, ITEM_MOON_STONE
    givemon SPECIES_VULPIX, 60, ITEM_FIRE_STONE
    givemon SPECIES_ALOLAN_VULPIX, 60, ITEM_ICE_STONE
    givemon SPECIES_IGGLYBUFF, 60, ITEM_MOON_STONE
    givemon SPECIES_ZUBAT, 60, ITEM_NONE
    givemon SPECIES_ODDISH, 60, ITEM_LEAF_STONE
    givemon SPECIES_ODDISH, 60, ITEM_SUN_STONE
    givemon SPECIES_PARAS, 60, ITEM_BIG_MUSHROOM
    givemon SPECIES_VENONAT, 60, ITEM_NONE
    givemon SPECIES_DIGLETT, 60, ITEM_NONE
    givemon SPECIES_ALOLAN_DIGLETT, 60, ITEM_NONE
    givemon SPECIES_MEOWTH, 60, ITEM_NUGGET
    givemon SPECIES_ALOLAN_MEOWTH, 60, ITEM_NONE
	
	message InsideOfTruck_Text_PC_Config5
	waitmessage
    givemon SPECIES_GALAR_MEOWTH, 60, ITEM_NONE
    givemon SPECIES_PSYDUCK, 60, ITEM_NONE
    givemon SPECIES_MANKEY, 60, ITEM_DAWN_STONE
    givemon SPECIES_GROWLITHE, 60, ITEM_FIRE_STONE
    givemon SPECIES_GROWLITHE_HISUIAN, 60, ITEM_FIRE_STONE
    givemon SPECIES_POLIWAG, 60, ITEM_WATER_STONE
    givemon SPECIES_POLIWAG, 60, ITEM_KINGS_ROCK
    givemon SPECIES_ABRA, 60, ITEM_NONE
    givemon SPECIES_MACHOP, 60, ITEM_NONE
    givemon SPECIES_BELLSPROUT, 60, ITEM_LEAF_STONE
    givemon SPECIES_TENTACOOL, 60, ITEM_NONE
    givemon SPECIES_GEODUDE, 60, ITEM_NONE
    givemon SPECIES_ALOLAN_GEODUDE, 60, ITEM_NONE
    givemon SPECIES_PONYTA, 60, ITEM_NONE
    givemon SPECIES_GALAR_PONYTA, 60, ITEM_NONE
    givemon SPECIES_SLOWPOKE, 60, ITEM_NONE
    givemon SPECIES_SLOWKING, 60, ITEM_NONE
    givemon SPECIES_SLOWPOKE_GALARIAN, 60, ITEM_NONE
    givemon SPECIES_SLOWKING_GALARIAN, 60, ITEM_NONE
    givemon SPECIES_MAGNEMITE, 60, ITEM_THUNDER_STONE
    givemon SPECIES_MAGNESANDS, 60, ITEM_NONE
    givemon SPECIES_FARFETCHD, 60, ITEM_STICK
    givemon SPECIES_GALAR_FARFETCH, 60, ITEM_STICK
    givemon SPECIES_DODUO, 60, ITEM_NONE
    givemon SPECIES_SEEL, 60, ITEM_NONE
    givemon SPECIES_GRIMER, 60, ITEM_NONE
    givemon SPECIES_ALOLAN_GRIMER, 60, ITEM_NONE
    givemon SPECIES_SHELLDER, 60, ITEM_WATER_STONE
    givemon SPECIES_GASTLY, 60, ITEM_NONE
    givemon SPECIES_ONIX, 60, ITEM_METAL_COAT
	
	message InsideOfTruck_Text_PC_Config6
	waitmessage
    givemon SPECIES_DROWZEE, 60, ITEM_NONE
    givemon SPECIES_KRABBY, 60, ITEM_NONE
    givemon SPECIES_VOLTORB, 60, ITEM_NONE
    givemon SPECIES_VOLTORB_HISUIAN, 60, ITEM_LEAF_STONE
    givemon SPECIES_EXEGGCUTE, 60, ITEM_LEAF_STONE
    givemon SPECIES_EXEGGCUTE, 60, ITEM_SUN_STONE
    givemon SPECIES_CUBONE, 60, ITEM_THICK_CLUB
    givemon SPECIES_ALOLAN_MAROWAK, 60, ITEM_THICK_CLUB
    givemon SPECIES_LICKITUNG, 60, ITEM_NONE
    givemon SPECIES_KOFFING, 60, ITEM_NONE
    givemon SPECIES_GALAR_WEEZING, 60, ITEM_NONE
    givemon SPECIES_RHYHORN, 60, ITEM_NONE
    givemon SPECIES_TANGELA, 60, ITEM_NONE
    givemon SPECIES_KANGASKHAN, 60, ITEM_NONE
    givemon SPECIES_HORSEA, 60, ITEM_DRAGON_SCALE
    givemon SPECIES_GOLDEEN, 60, ITEM_NONE
	givemon SPECIES_STARYU, 60, ITEM_WATER_STONE
    givemon SPECIES_SCYTHER, 60, ITEM_NONE
    givemon SPECIES_SCIZOR, 60, ITEM_NONE
    givemon SPECIES_KLEAVOR, 60, ITEM_NONE
    givemon SPECIES_PINSIR, 60, ITEM_NONE
    givemon SPECIES_TAUROS, 60, ITEM_NONE
    givemon SPECIES_TAUROS_PALDEAN_FIGHT, 60, ITEM_NONE
    givemon SPECIES_TAUROS_PALDEAN_AQUA, 60, ITEM_NONE
    givemon SPECIES_TAUROS_PALDEAN_BLAZE, 60, ITEM_NONE
    givemon SPECIES_MAGIKARP, 60, ITEM_NONE
    givemon SPECIES_LAPRAS, 60, ITEM_NONE
	givecustommon SPECIES_DITTO, 60, ITEM_NONE, ITEM_MASTER_BALL, 0, 0, 252, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE, TRUE, 0
	givecustommon SPECIES_DITTO, 60, ITEM_NONE, ITEM_MASTER_BALL, 0, 0, 252, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
   	givecustommon SPECIES_DITTO, 60, ITEM_NONE, ITEM_MASTER_BALL, 0, 0, 252, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	
	message InsideOfTruck_Text_PC_Config7
	waitmessage
	givecustommon SPECIES_DITTO, 60, ITEM_NONE, ITEM_MASTER_BALL, 0, 0, 252, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	givecustommon SPECIES_DITTO, 60, ITEM_NONE, ITEM_MASTER_BALL, 0, 0, 252, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	givecustommon SPECIES_DITTO, 60, ITEM_NONE, ITEM_MASTER_BALL, 0, 0, 252, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	givemon SPECIES_EEVEE, 60, ITEM_EVERSTONE
    givemon SPECIES_VAPOREON, 60, ITEM_NONE
    givemon SPECIES_JOLTEON, 60, ITEM_NONE
    givemon SPECIES_FLAREON, 60, ITEM_NONE
    givemon SPECIES_ESPEON, 60, ITEM_NONE
    givemon SPECIES_UMBREON, 60, ITEM_NONE
    givemon SPECIES_LEAFEON, 60, ITEM_NONE
    givemon SPECIES_GLACEON, 60, ITEM_NONE
    givemon SPECIES_SYLVEON, 60, ITEM_NONE
    givemon SPECIES_PORYGON, 60, ITEM_UP_GRADE
    givemon SPECIES_PORYGON2, 60, ITEM_UP_GRADE
    givemon SPECIES_OMANYTE, 60, ITEM_NONE
    givemon SPECIES_KABUTO, 60, ITEM_NONE
    givemon SPECIES_AERODACTYL, 60, ITEM_NONE
    givemon SPECIES_DRATINI, 60, ITEM_NONE
    givemon SPECIES_CHIKORITA, 60, ITEM_NONE
    givemon SPECIES_CYNDAQUIL, 60, ITEM_NONE
    givemon SPECIES_TYPHLOSION_HISUIAN, 60, ITEM_NONE
    givemon SPECIES_TOTODILE, 60, ITEM_NONE
    givemon SPECIES_SENTRET, 60, ITEM_FLUFFY_TAIL
    givemon SPECIES_HOOTHOOT, 60, ITEM_NONE
    givemon SPECIES_LEDYBA, 60, ITEM_LUCKY_PUNCH
    givemon SPECIES_SPINARAK, 60, ITEM_NONE
    givemon SPECIES_CHINCHOU, 60, ITEM_NONE
    givemon SPECIES_TOGEPI, 60, ITEM_SHINY_STONE
    givemon SPECIES_NATU, 60, ITEM_NONE
    givemon SPECIES_MAREEP, 60, ITEM_NONE
	
	message InsideOfTruck_Text_PC_Config8
	waitmessage
    givemon SPECIES_HOPPIP, 60, ITEM_NONE
    givemon SPECIES_AIPOM, 60, ITEM_NONE
    givemon SPECIES_SUNKERN, 60, ITEM_SUN_STONE
    givemon SPECIES_YANMA, 60, ITEM_NONE
    givemon SPECIES_WOOPER, 60, ITEM_NONE
    givemon SPECIES_WOOPER_PALDEAN, 60, ITEM_NONE
    givemon SPECIES_MURKROW, 60, ITEM_DUSK_STONE
    givemon SPECIES_MISDREAVUS, 60, ITEM_DUSK_STONE
    givemon SPECIES_GIRAFARIG, 60, ITEM_NONE
    givemon SPECIES_FARIGIRAF, 60, ITEM_NONE
    givemon SPECIES_PINECO, 60, ITEM_NONE
    givemon SPECIES_DUNSPARCE, 60, ITEM_NONE
    givemon SPECIES_GLIGAR, 60, ITEM_NONE
    givemon SPECIES_SNUBBULL, 60, ITEM_NONE
    givemon SPECIES_QWILFISH, 60, ITEM_NONE
    givemon SPECIES_QWILFISH_HISUIAN, 60, ITEM_NONE
    givemon SPECIES_SHUCKLE, 60, ITEM_BERRY_JUICE
    givemon SPECIES_HERACROSS, 60, ITEM_NONE
    givemon SPECIES_SNEASEL, 60, ITEM_NONE
    givemon SPECIES_SNEASEL_HISUIAN, 60, ITEM_NONE
    givemon SPECIES_TEDDIURSA, 60, ITEM_DAWN_STONE
    givemon SPECIES_SLUGMA, 60, ITEM_NONE
    givemon SPECIES_SWINUB, 60, ITEM_NONE
    givemon SPECIES_CORSOLA, 60, ITEM_NONE
    givemon SPECIES_GALAR_CORSOLA, 60, ITEM_NONE
    givemon SPECIES_REMORAID, 60, ITEM_NONE
    givemon SPECIES_DELIBIRD, 60, ITEM_BLUE_FLUTE
    givemon SPECIES_SKARMORY, 60, ITEM_NONE
    givemon SPECIES_HOUNDOUR, 60, ITEM_NONE
    givemon SPECIES_PHANPY, 60, ITEM_NONE
	
	message InsideOfTruck_Text_PC_Config9
	waitmessage
    givemon SPECIES_STANTLER, 60, ITEM_NONE
    givemon SPECIES_WYRDEER, 60, ITEM_NONE
    givemon SPECIES_SMEARGLE, 60, ITEM_NONE
    givemon SPECIES_TYROGUE, 60, ITEM_NONE
    givemon SPECIES_HITMONLEE, 60, ITEM_NONE
    givemon SPECIES_HITMONCHAN, 60, ITEM_NONE
    givemon SPECIES_HITMONTOP, 60, ITEM_NONE
    givemon SPECIES_SMOOCHUM, 60, ITEM_NONE
    givemon SPECIES_ELEKID, 60, ITEM_THUNDER_STONE
    givemon SPECIES_MAGBY, 60, ITEM_FIRE_STONE
    givemon SPECIES_MILTANK, 60, ITEM_NONE
    givemon SPECIES_LARVITAR, 60, ITEM_NONE
    givemon SPECIES_TREECKO, 60, ITEM_NONE
    givemon SPECIES_TORCHIC, 60, ITEM_NONE
    givemon SPECIES_MUDKIP, 60, ITEM_NONE
    givemon SPECIES_POOCHYENA, 60, ITEM_NONE
    givemon SPECIES_ZIGZAGOON, 60, ITEM_NONE
    givemon SPECIES_GALAR_ZIGZAGOON, 60, ITEM_NONE
    givemon SPECIES_WURMPLE, 60, ITEM_NONE
    givemon SPECIES_SILCOON, 60, ITEM_SMOKE_BALL
    givemon SPECIES_CASCOON, 60, ITEM_SMOKE_BALL
    givemon SPECIES_LOTAD, 60, ITEM_WATER_STONE
    givemon SPECIES_SEEDOT, 60, ITEM_LEAF_STONE
    givemon SPECIES_TAILLOW, 60, ITEM_NONE
    givemon SPECIES_WINGULL, 60, ITEM_NONE
    givemon SPECIES_RALTS, 60, ITEM_NONE
    givemon SPECIES_GALLADE, 60, ITEM_NONE
    givemon SPECIES_SURSKIT, 60, ITEM_NONE
    givemon SPECIES_SHROOMISH, 60, ITEM_NONE
    givemon SPECIES_SLAKOTH, 60, ITEM_NONE

	message InsideOfTruck_Text_PC_Config10
	waitmessage
    givemon SPECIES_VIGOROTH, 60, ITEM_NONE
    givemon SPECIES_NINCADA, 60, ITEM_NONE
    givemon SPECIES_NINJASK, 60, ITEM_NONE
    givemon SPECIES_SHEDINJA, 60, ITEM_NONE
    givemon SPECIES_WHISMUR, 60, ITEM_NONE
    givemon SPECIES_MAKUHITA, 60, ITEM_NONE
    givemon SPECIES_AZURILL, 60, ITEM_NONE
    givemon SPECIES_NOSEPASS, 60, ITEM_THUNDER_STONE
    givemon SPECIES_SKITTY, 60, ITEM_MOON_STONE
    givemon SPECIES_SABLEYE, 60, ITEM_NONE
    givemon SPECIES_MAWILE, 60, ITEM_NONE
    givemon SPECIES_ARON, 60, ITEM_NONE
    givemon SPECIES_MEDITITE, 60, ITEM_NONE
    givemon SPECIES_ELECTRIKE, 60, ITEM_NONE
    givemon SPECIES_PLUSLE, 60, ITEM_NONE
    givemon SPECIES_MINUN, 60, ITEM_NONE
    givemon SPECIES_VOLBEAT, 60, ITEM_RED_FLUTE
    givemon SPECIES_ILLUMISE, 60, ITEM_RED_FLUTE
    givemon SPECIES_GULPIN, 60, ITEM_NONE
    givemon SPECIES_CARVANHA, 60, ITEM_NONE
    givemon SPECIES_WAILMER, 60, ITEM_NONE
    givemon SPECIES_NUMEL, 60, ITEM_NONE
    givemon SPECIES_NUMEL_LUCKY, 60, ITEM_NONE
    givemon SPECIES_TORKOAL, 60, ITEM_NONE
    givemon SPECIES_SPOINK, 60, ITEM_NONE
    givemon SPECIES_SPINDA, 60, ITEM_YELLOW_FLUTE
    givemon SPECIES_TRAPINCH, 60, ITEM_EVERSTONE
    givemon SPECIES_VIBRAVA, 60, ITEM_NONE
    givemon SPECIES_CACNEA, 60, ITEM_NONE
    givemon SPECIES_SWABLU, 60, ITEM_NONE
	
	message InsideOfTruck_Text_PC_Config11
	waitmessage
    givemon SPECIES_ZANGOOSE, 60, ITEM_NONE
    givemon SPECIES_SEVIPER, 60, ITEM_NONE
    givemon SPECIES_LUNATONE, 60, ITEM_NONE
    givemon SPECIES_SOLROCK, 60, ITEM_NONE
    givemon SPECIES_BARBOACH, 60, ITEM_NONE
    givemon SPECIES_CORPHISH, 60, ITEM_NONE
    givemon SPECIES_BALTOY, 60, ITEM_NONE
    givemon SPECIES_LILEEP, 60, ITEM_NONE
    givemon SPECIES_ANORITH, 60, ITEM_NONE
	givecustommon SPECIES_FEEBAS, 60, ITEM_NONE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, 0, 100
    givemon SPECIES_CASTFORM, 60, ITEM_NONE
    givemon SPECIES_KECLEON, 60, ITEM_NONE
    givemon SPECIES_SHUPPET, 60, ITEM_NONE
    givemon SPECIES_DUSKULL, 60, ITEM_NONE
    givemon SPECIES_TROPIUS, 60, ITEM_NONE
    givemon SPECIES_ABSOL, 60, ITEM_NONE
    givemon SPECIES_WYNAUT, 60, ITEM_NONE
    givemon SPECIES_SNORUNT, 60, ITEM_NONE
    givemon SPECIES_FROSLASS, 60, ITEM_NONE
    givemon SPECIES_SPHEAL, 60, ITEM_NONE
    givemon SPECIES_CLAMPERL, 60, ITEM_NONE
    givemon SPECIES_GOREBYSS, 60, ITEM_NONE
    givemon SPECIES_HUNTAIL, 60, ITEM_NONE
    givemon SPECIES_RELICANTH, 60, ITEM_NONE
    givemon SPECIES_LUVDISC, 60, ITEM_HEART_SCALE
    givemon SPECIES_BAGON, 60, ITEM_NONE
    givemon SPECIES_BELDUM, 60, ITEM_NONE
    givemon SPECIES_YAMASK, 60, ITEM_NONE
    givemon SPECIES_GALAR_YAMASK, 60, ITEM_NONE
    givemon SPECIES_SNOVER, 60, ITEM_NONE
	
	message InsideOfTruck_Text_PC_Config12
	waitmessage
    givemon SPECIES_GROOKEY, 60, ITEM_NONE
    givemon SPECIES_GOLETT, 60, ITEM_NONE
    givemon SPECIES_TYRUNT, 60, ITEM_NONE
    givemon SPECIES_AMAURA, 60, ITEM_NONE
    givemon SPECIES_DEINO, 60, ITEM_NONE
    givemon SPECIES_JANGMO_O, 60, ITEM_NONE
    givemon SPECIES_DREEPY, 60, ITEM_NONE
    givemon SPECIES_SKORUPI, 60, ITEM_NONE
    givemon SPECIES_WOOLOO, 60, ITEM_NONE
    givemon SPECIES_RIOLU, 60, ITEM_NONE
    givemon SPECIES_TYNAMO, 60, ITEM_THUNDER_STONE
    givemon SPECIES_GRUBBIN, 60, ITEM_THUNDER_STONE
    givemon SPECIES_LITWICK, 60, ITEM_NONE
    givemon SPECIES_ROWLET, 60, ITEM_NONE
    givemon SPECIES_DECIDUEYE_HISUIAN, 60, ITEM_NONE
    givemon SPECIES_POPPLIO, 60, ITEM_NONE
    givemon SPECIES_SOBBLE, 60, ITEM_NONE
    givemon SPECIES_TURTWIG, 60, ITEM_NONE
    givemon SPECIES_PIPLUP, 60, ITEM_NONE
    givemon SPECIES_DHELMISE, 60, ITEM_NONE
    givemon SPECIES_PAWNIARD, 60, ITEM_NONE
    givemon SPECIES_IMPIDIMP, 60, ITEM_NONE
    givemon SPECIES_SALANDIT, 60, ITEM_NONE
    givemon SPECIES_SALAZZLE, 60, ITEM_NONE
    givemon SPECIES_SANDYGAST, 60, ITEM_NONE
    givemon SPECIES_FERROSEED, 60, ITEM_NONE
    givemon SPECIES_SANDILE, 60, ITEM_NONE
    givemon SPECIES_CROAGUNK, 60, ITEM_NONE
    givemon SPECIES_LILLIPUP, 60, ITEM_NONE
    givemon SPECIES_SIZZLIPEDE, 60, ITEM_NONE
	
	message InsideOfTruck_Text_PC_Config13
	waitmessage
    givemon SPECIES_ROOKIDEE, 60, ITEM_NONE
    givemon SPECIES_HAWLUCHA, 60, ITEM_NONE
    givemon SPECIES_DURANT, 60, ITEM_NONE
    givemon SPECIES_SNOM, 60, ITEM_NONE
    givemon SPECIES_TOXEL, 60, ITEM_NONE
    givemon SPECIES_TOXTRICITY_LK, 60, ITEM_NONE
    givemon SPECIES_TOXTRICITY, 60, ITEM_NONE
    givemon SPECIES_APPLIN, 60, ITEM_NONE
    givemon SPECIES_FLAPPLE, 60, ITEM_NONE
    givemon SPECIES_APPLETUN, 60, ITEM_NONE
    givemon SPECIES_DIPPLIN, 60, ITEM_NONE
    givemon SPECIES_DIPPLIN, 60, ITEM_DRAGON_SCALE
    givemon SPECIES_DURALUDON, 60, ITEM_DAWN_STONE
    givemon SPECIES_COTTONEE, 60, ITEM_NONE
    givemon SPECIES_HIPPOPOTAS, 60, ITEM_NONE
    givemon SPECIES_SILICOBRA, 60, ITEM_NONE
    givemon SPECIES_COMBEE, 60, ITEM_NONE
    givemon SPECIES_VESPIQUEN, 60, ITEM_NONE
    givemon SPECIES_PANCHAM, 60, ITEM_NONE
    givemon SPECIES_SKRELP, 60, ITEM_NONE
    givemon SPECIES_STUFFUL, 60, ITEM_NONE
    givemon SPECIES_PUMPKABOO, 60, ITEM_NONE
    givemon SPECIES_FRILLISH, 60, ITEM_NONE
    givemon SPECIES_ROCKRUFF, 60, ITEM_SUN_STONE
    givemon SPECIES_ROCKRUFF, 60, ITEM_MOON_STONE
    givemon SPECIES_ROCKRUFF, 60, ITEM_DUSK_STONE
    givemon SPECIES_SNIVY, 60, ITEM_NONE
    givemon SPECIES_MILCERY, 60, ITEM_NONE
    givemon SPECIES_BUDEW, 60, ITEM_SHINY_STONE
    givemon SPECIES_CHINGLING, 60, ITEM_CLEANSE_TAG
	
	message InsideOfTruck_Text_PC_Config14
	waitmessage
    givemon SPECIES_BONSLY, 60, ITEM_NONE
    givemon SPECIES_MIMEJR, 60, ITEM_NONE
    givemon SPECIES_GALAR_MRMIME, 60, ITEM_NONE
    givemon SPECIES_HAPPINY, 60, ITEM_SHINY_STONE
    givemon SPECIES_MUNCHLAX, 60, ITEM_NONE
    givemon SPECIES_MANTYKE, 60, ITEM_NONE
    givemon SPECIES_CHESPIN, 60, ITEM_NONE
    givemon SPECIES_CHIMCHAR, 60, ITEM_NONE
    givemon SPECIES_WINTASS, 60, ITEM_NONE
    givemon SPECIES_GOOMY, 60, ITEM_NONE
    givemon SPECIES_SLIGGOO_HISUIAN, 60, ITEM_NONE
    givemon SPECIES_STUNFISK, 60, ITEM_NONE
    givemon SPECIES_GALAR_STUNFISK, 60, ITEM_NONE
    givemon SPECIES_SOLOSIS, 60, ITEM_NONE
    givemon SPECIES_VULLABY, 60, ITEM_NONE
    givemon SPECIES_DRILBUR, 60, ITEM_NONE
    givemon SPECIES_PRINPAWN, 60, ITEM_NONE
    givemon SPECIES_KINCURS, 60, ITEM_NONE
    givemon SPECIES_COUREEN, 60, ITEM_NONE
    givemon SPECIES_POSORD, 60, ITEM_NONE
    givemon SPECIES_TRUBBISH, 60, ITEM_METAL_COAT
    givemon SPECIES_PANSAGE, 60, ITEM_LEAF_STONE
    givemon SPECIES_WATTREL, 60, ITEM_NONE
    givemon SPECIES_FLOETTE, 60, ITEM_NONE
    givemon SPECIES_ARTICUNO, 1, ITEM_NONE
    givemon SPECIES_ZAPDOS, 1, ITEM_NONE
    givemon SPECIES_MOLTRES, 1, ITEM_NONE
    givemon SPECIES_ENTEI, 1, ITEM_NONE
    givemon SPECIES_RAIKOU, 1, ITEM_NONE
    givemon SPECIES_SUICUNE, 1, ITEM_NONE
	
	message InsideOfTruck_Text_PC_Config15
	waitmessage
    givemon SPECIES_REGICE, 1, ITEM_NONE
    givemon SPECIES_REGIROCK, 1, ITEM_NONE
    givemon SPECIES_REGISTEEL, 1, ITEM_NONE
    givemon SPECIES_REGIELEKI, 1, ITEM_NONE
    givemon SPECIES_REGIDRAGO, 1, ITEM_NONE
    givemon SPECIES_REGIGIGAS, 1, ITEM_NONE
    givemon SPECIES_MEWTWO, 1, ITEM_NONE
    givemon SPECIES_MEW, 1, ITEM_NONE
    givemon SPECIES_CELEBI, 1, ITEM_NONE
    givemon SPECIES_JIRACHI, 1, ITEM_NONE
    givemon SPECIES_LUGIA, 1, ITEM_NONE
    givemon SPECIES_HO_OH, 1, ITEM_NONE
    givemon SPECIES_KYOGRE, 1, ITEM_NONE
    givemon SPECIES_GROUDON, 1, ITEM_NONE
    givemon SPECIES_RAYQUAZA, 1, ITEM_NONE
    givemon SPECIES_LATIAS, 1, ITEM_NONE
    givemon SPECIES_LATIOS, 1, ITEM_NONE
    givemon SPECIES_DEOXYS, 1, ITEM_NONE
    givemon SPECIES_DEOXYS_ATTACK, 1, ITEM_NONE
    givemon SPECIES_DEOXYS_DEFENSE, 1, ITEM_NONE
    givemon SPECIES_DEOXYS_SPEED, 1, ITEM_NONE
    givemon SPECIES_DARK_PIKACHU, 1, ITEM_NONE
    givemon SPECIES_HONEDGE_MONADO, 1, ITEM_NONE
    givemon SPECIES_ZARUDE, 1, ITEM_NONE
	
	setflag FLAG_MICOLANDIA_MODE // ACTIVA MODO MIDELE
	msgbox InsideOfTruck_Text_PC_ConfigFIN, MSGBOX_DEFAULT
	setrespawn HEAL_LOCATION_MICOLANDIA
	warp MAP_MICOLANDIA_HOUSE1, 2, 0, 0
	waitstate
	release	
	end
	
InsideOfTruck_Text_PC_Config:
	.string "Te doy la bienvenida al PC de\n"
	.string "configuración del MODO MIDELE.\p"
	.string "En este modo de juego, empezarás\n"
	.string "directamente el desafío de la MICOLIGA\l"
	.string "de MICOLANDIA.\p"
	.string "Se te suministrarán 12 cajas llenas de\n"
	.string "POKéMON nivel 60 para afrontar este\l"
	.string "desafío, pero ten en cuenta que en este\l"
	.string "modo no podrás ir a HOENN.\p"
	.string "¿Quieres jugar al MODO MIDELE?$"
	
InsideOfTruck_Text_PC_Config1:
	.string "Procede a elegir el horario.$"
	
InsideOfTruck_Text_PC_Config2:
	.string "Iniciando configuración del MODO MIDELE.\n"
	.string "Esto tardará alrededor de 5 minutos.$"
	
InsideOfTruck_Text_PC_Config3:
	.string "....Configurando todos los objetos....$"
	
InsideOfTruck_Text_PC_Config4:
	.string ".........Configurando CAJA 1...........$"
	
InsideOfTruck_Text_PC_Config5:
	.string ".........Configurando CAJA 2...........$"
	
InsideOfTruck_Text_PC_Config6:
	.string ".........Configurando CAJA 3...........$"
	
InsideOfTruck_Text_PC_Config7:
	.string ".........Configurando CAJA 4...........$"
	
InsideOfTruck_Text_PC_Config8:
	.string ".........Configurando CAJA 5...........$"
	
InsideOfTruck_Text_PC_Config9:
	.string ".........Configurando CAJA 6...........$"
	
InsideOfTruck_Text_PC_Config10:
	.string ".........Configurando CAJA 7...........$"
	
InsideOfTruck_Text_PC_Config11:
	.string ".........Configurando CAJA 8...........$"
	
InsideOfTruck_Text_PC_Config12:
	.string ".........Configurando CAJA 9...........$"
	
InsideOfTruck_Text_PC_Config13:
	.string "........Configurando CAJA 10...........$"
	
InsideOfTruck_Text_PC_Config14:
	.string "........Configurando CAJA 11...........$"
	
InsideOfTruck_Text_PC_Config15:
	.string "........Configurando CAJA 12...........$"
	
InsideOfTruck_Text_PC_ConfigFIN:
	.string "Configuración terminada. ¡Buena suerte!$"

InsideOfTruck_Text_BoxPrintedWithMonLogo: @ 823BF75
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"
	
NombreVecino_Text:
	.string "By the way, what was my\n"
	.string "new neighbor's name?$"
	
NombreVecino_Text2:
	.string "I remember, the name was {RIVAL}!$"

