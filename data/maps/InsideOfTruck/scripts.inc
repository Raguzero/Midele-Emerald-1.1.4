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
	setflag FLAG_ITEM_SECRET_POTION
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
    additem ITEM_SWEET_HEART, 1
	additem ITEM_ABILITY_CAPSULE, 1
	additem ITEM_SECRET_POTION, 1
    additem ITEM_PP_MAX, 99
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
    //additem ITEM_EVERSTONE, 6
    additem ITEM_THICK_CLUB, 6
    //additem ITEM_METAL_POWDER, 6
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
	givecustommon SPECIES_UNOWN, 65, ITEM_NONE, ITEM_LUXURY_BALL, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE, TRUE, 0
	givecustommon SPECIES_UNOWN, 65, ITEM_NONE, ITEM_LUXURY_BALL, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	givecustommon SPECIES_UNOWN, 65, ITEM_NONE, ITEM_LUXURY_BALL, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	givecustommon SPECIES_UNOWN, 65, ITEM_NONE, ITEM_LUXURY_BALL, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	givecustommon SPECIES_UNOWN, 65, ITEM_NONE, ITEM_LUXURY_BALL, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	givecustommon SPECIES_UNOWN, 65, ITEM_NONE, ITEM_LUXURY_BALL, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	
	message InsideOfTruck_Text_PC_Config4
	waitmessage
	givemon SPECIES_BULBASAUR, 65, ITEM_NONE
    givemon SPECIES_CHARMANDER, 65, ITEM_NONE
    givemon SPECIES_SQUIRTLE, 65, ITEM_NONE
    givemon SPECIES_CATERPIE, 65, ITEM_NONE
    givemon SPECIES_WEEDLE, 65, ITEM_NONE
    givemon SPECIES_PIDGEY, 65, ITEM_NONE
    givemon SPECIES_RATTATA, 65, ITEM_NONE
    givemon SPECIES_ALOLAN_RATTATA, 65, ITEM_NONE
    givemon SPECIES_SPEAROW, 65, ITEM_NONE
    givemon SPECIES_EKANS, 65, ITEM_NONE
    givemon SPECIES_PICHU, 65, ITEM_THUNDER_STONE
    givemon SPECIES_PICHU, 65, ITEM_SHINY_STONE
    givemon SPECIES_PIKACHU, 65, ITEM_LIGHT_BALL
    givemon SPECIES_SANDSHREW, 65, ITEM_NONE
    givemon SPECIES_ALOLAN_SANDSHREW, 65, ITEM_ICE_STONE
    givemon SPECIES_NIDORAN_F, 65, ITEM_MOON_STONE
    givemon SPECIES_NIDORAN_M, 65, ITEM_MOON_STONE
    givemon SPECIES_CLEFFA, 65, ITEM_MOON_STONE
    givemon SPECIES_VULPIX, 65, ITEM_FIRE_STONE
    givemon SPECIES_ALOLAN_VULPIX, 65, ITEM_ICE_STONE
    givemon SPECIES_IGGLYBUFF, 65, ITEM_MOON_STONE
    givemon SPECIES_ZUBAT, 65, ITEM_NONE
    givemon SPECIES_ODDISH, 65, ITEM_LEAF_STONE
    givemon SPECIES_ODDISH, 65, ITEM_SUN_STONE
    givemon SPECIES_PARAS, 65, ITEM_BIG_MUSHROOM
    givemon SPECIES_VENONAT, 65, ITEM_NONE
    givemon SPECIES_DIGLETT, 65, ITEM_NONE
    givemon SPECIES_ALOLAN_DIGLETT, 65, ITEM_NONE
    givemon SPECIES_MEOWTH, 65, ITEM_NUGGET
    givemon SPECIES_ALOLAN_MEOWTH, 65, ITEM_NONE
	
	message InsideOfTruck_Text_PC_Config5
	waitmessage
    givemon SPECIES_GALAR_MEOWTH, 65, ITEM_NONE
    givemon SPECIES_PSYDUCK, 65, ITEM_NONE
    givemon SPECIES_MANKEY, 65, ITEM_DAWN_STONE
    givemon SPECIES_GROWLITHE, 65, ITEM_FIRE_STONE
    givemon SPECIES_GROWLITHE_HISUIAN, 65, ITEM_FIRE_STONE
    givemon SPECIES_POLIWAG, 65, ITEM_WATER_STONE
    givemon SPECIES_POLIWAG, 65, ITEM_KINGS_ROCK
    givemon SPECIES_ABRA, 65, ITEM_NONE
    givemon SPECIES_MACHOP, 65, ITEM_NONE
    givemon SPECIES_BELLSPROUT, 65, ITEM_LEAF_STONE
    givemon SPECIES_TENTACOOL, 65, ITEM_NONE
    givemon SPECIES_GEODUDE, 65, ITEM_NONE
    givemon SPECIES_ALOLAN_GEODUDE, 65, ITEM_NONE
    givemon SPECIES_PONYTA, 65, ITEM_NONE
    givemon SPECIES_GALAR_PONYTA, 65, ITEM_NONE
    givemon SPECIES_SLOWPOKE, 65, ITEM_NONE
    givemon SPECIES_SLOWKING, 65, ITEM_NONE
    givemon SPECIES_SLOWPOKE_GALARIAN, 65, ITEM_NONE
    givemon SPECIES_SLOWKING_GALARIAN, 65, ITEM_NONE
    givemon SPECIES_MAGNEMITE, 65, ITEM_THUNDER_STONE
    givemon SPECIES_MAGNESANDS, 65, ITEM_NONE
    givemon SPECIES_FARFETCHD, 65, ITEM_STICK
    givemon SPECIES_GALAR_FARFETCH, 65, ITEM_STICK
    givemon SPECIES_DODUO, 65, ITEM_NONE
    givemon SPECIES_SEEL, 65, ITEM_NONE
    givemon SPECIES_GRIMER, 65, ITEM_NONE
    givemon SPECIES_ALOLAN_GRIMER, 65, ITEM_NONE
    givemon SPECIES_SHELLDER, 65, ITEM_WATER_STONE
    givemon SPECIES_GASTLY, 65, ITEM_NONE
    givemon SPECIES_ONIX, 65, ITEM_METAL_COAT
	
	message InsideOfTruck_Text_PC_Config6
	waitmessage
    givemon SPECIES_DROWZEE, 65, ITEM_NONE
    givemon SPECIES_KRABBY, 65, ITEM_NONE
    givemon SPECIES_VOLTORB, 65, ITEM_NONE
    givemon SPECIES_VOLTORB_HISUIAN, 65, ITEM_LEAF_STONE
    givemon SPECIES_EXEGGCUTE, 65, ITEM_LEAF_STONE
    givemon SPECIES_EXEGGCUTE, 65, ITEM_SUN_STONE
    givemon SPECIES_CUBONE, 65, ITEM_THICK_CLUB
    givemon SPECIES_ALOLAN_MAROWAK, 65, ITEM_THICK_CLUB
    givemon SPECIES_LICKITUNG, 65, ITEM_NONE
    givemon SPECIES_KOFFING, 65, ITEM_NONE
    givemon SPECIES_GALAR_WEEZING, 65, ITEM_NONE
    givemon SPECIES_RHYHORN, 65, ITEM_NONE
    givemon SPECIES_TANGELA, 65, ITEM_NONE
    givemon SPECIES_KANGASKHAN, 65, ITEM_NONE
    givemon SPECIES_HORSEA, 65, ITEM_DRAGON_SCALE
    givemon SPECIES_GOLDEEN, 65, ITEM_NONE
	givemon SPECIES_STARYU, 65, ITEM_WATER_STONE
    givemon SPECIES_SCYTHER, 65, ITEM_NONE
    givemon SPECIES_SCIZOR, 65, ITEM_NONE
    givemon SPECIES_KLEAVOR, 65, ITEM_NONE
    givemon SPECIES_PINSIR, 65, ITEM_NONE
    givemon SPECIES_TAUROS, 65, ITEM_NONE
    givemon SPECIES_TAUROS_PALDEAN_FIGHT, 65, ITEM_NONE
    givemon SPECIES_TAUROS_PALDEAN_AQUA, 65, ITEM_NONE
    givemon SPECIES_TAUROS_PALDEAN_BLAZE, 65, ITEM_NONE
    givemon SPECIES_MAGIKARP, 65, ITEM_NONE
    givemon SPECIES_LAPRAS, 65, ITEM_NONE
	givecustommon SPECIES_DITTO, 65, ITEM_NONE, ITEM_MASTER_BALL, 0, 0, 252, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE, TRUE, 0
	givecustommon SPECIES_DITTO, 65, ITEM_NONE, ITEM_MASTER_BALL, 0, 0, 252, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
   	givecustommon SPECIES_DITTO, 65, ITEM_NONE, ITEM_MASTER_BALL, 0, 0, 252, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	
	message InsideOfTruck_Text_PC_Config7
	waitmessage
	givecustommon SPECIES_DITTO, 65, ITEM_NONE, ITEM_MASTER_BALL, 0, 0, 252, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	givecustommon SPECIES_DITTO, 65, ITEM_NONE, ITEM_MASTER_BALL, 0, 0, 252, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	givecustommon SPECIES_DITTO, 65, ITEM_NONE, ITEM_MASTER_BALL, 0, 0, 252, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0, 0
	givemon SPECIES_EEVEE, 65, ITEM_EVERSTONE
    givemon SPECIES_VAPOREON, 65, ITEM_NONE
    givemon SPECIES_JOLTEON, 65, ITEM_NONE
    givemon SPECIES_FLAREON, 65, ITEM_NONE
    givemon SPECIES_ESPEON, 65, ITEM_NONE
    givemon SPECIES_UMBREON, 65, ITEM_NONE
    givemon SPECIES_LEAFEON, 65, ITEM_NONE
    givemon SPECIES_GLACEON, 65, ITEM_NONE
    givemon SPECIES_SYLVEON, 65, ITEM_NONE
    givemon SPECIES_PORYGON, 65, ITEM_UP_GRADE
    givemon SPECIES_PORYGON2, 65, ITEM_UP_GRADE
    givemon SPECIES_OMANYTE, 65, ITEM_NONE
    givemon SPECIES_KABUTO, 65, ITEM_NONE
    givemon SPECIES_AERODACTYL, 65, ITEM_NONE
    givemon SPECIES_DRATINI, 65, ITEM_NONE
    givemon SPECIES_CHIKORITA, 65, ITEM_NONE
    givemon SPECIES_CYNDAQUIL, 65, ITEM_NONE
    givemon SPECIES_TYPHLOSION_HISUIAN, 65, ITEM_NONE
    givemon SPECIES_TOTODILE, 65, ITEM_NONE
    givemon SPECIES_SENTRET, 65, ITEM_FLUFFY_TAIL
    givemon SPECIES_HOOTHOOT, 65, ITEM_NONE
    givemon SPECIES_LEDYBA, 65, ITEM_LUCKY_PUNCH
    givemon SPECIES_SPINARAK, 65, ITEM_NONE
    givemon SPECIES_CHINCHOU, 65, ITEM_NONE
    givemon SPECIES_TOGEPI, 65, ITEM_SHINY_STONE
    givemon SPECIES_NATU, 65, ITEM_NONE
    givemon SPECIES_MAREEP, 65, ITEM_NONE
	
	message InsideOfTruck_Text_PC_Config8
	waitmessage
    givemon SPECIES_HOPPIP, 65, ITEM_NONE
    givemon SPECIES_AIPOM, 65, ITEM_NONE
    givemon SPECIES_SUNKERN, 65, ITEM_SUN_STONE
    givemon SPECIES_YANMA, 65, ITEM_NONE
    givemon SPECIES_WOOPER, 65, ITEM_NONE
    givemon SPECIES_WOOPER_PALDEAN, 65, ITEM_NONE
    givemon SPECIES_MURKROW, 65, ITEM_DUSK_STONE
    givemon SPECIES_MISDREAVUS, 65, ITEM_DUSK_STONE
    givemon SPECIES_GIRAFARIG, 65, ITEM_NONE
    givemon SPECIES_FARIGIRAF, 65, ITEM_NONE
    givemon SPECIES_PINECO, 65, ITEM_NONE
    givemon SPECIES_DUNSPARCE, 65, ITEM_NONE
    givemon SPECIES_GLIGAR, 65, ITEM_NONE
    givemon SPECIES_SNUBBULL, 65, ITEM_NONE
    givemon SPECIES_QWILFISH, 65, ITEM_NONE
    givemon SPECIES_QWILFISH_HISUIAN, 65, ITEM_NONE
    givemon SPECIES_SHUCKLE, 65, ITEM_BERRY_JUICE
    givemon SPECIES_HERACROSS, 65, ITEM_NONE
    givemon SPECIES_SNEASEL, 65, ITEM_NONE
    givemon SPECIES_SNEASEL_HISUIAN, 65, ITEM_NONE
    givemon SPECIES_TEDDIURSA, 65, ITEM_DAWN_STONE
    givemon SPECIES_SLUGMA, 65, ITEM_NONE
    givemon SPECIES_SWINUB, 65, ITEM_NONE
    givemon SPECIES_CORSOLA, 65, ITEM_NONE
    givemon SPECIES_GALAR_CORSOLA, 65, ITEM_NONE
    givemon SPECIES_REMORAID, 65, ITEM_NONE
    givemon SPECIES_DELIBIRD, 65, ITEM_BLUE_FLUTE
    givemon SPECIES_SKARMORY, 65, ITEM_NONE
    givemon SPECIES_HOUNDOUR, 65, ITEM_NONE
    givemon SPECIES_PHANPY, 65, ITEM_NONE
	
	message InsideOfTruck_Text_PC_Config9
	waitmessage
    givemon SPECIES_STANTLER, 65, ITEM_NONE
    givemon SPECIES_WYRDEER, 65, ITEM_NONE
    givemon SPECIES_SMEARGLE, 65, ITEM_NONE
    givemon SPECIES_TYROGUE, 65, ITEM_NONE
    givemon SPECIES_HITMONLEE, 65, ITEM_NONE
    givemon SPECIES_HITMONCHAN, 65, ITEM_NONE
    givemon SPECIES_HITMONTOP, 65, ITEM_NONE
    givemon SPECIES_SMOOCHUM, 65, ITEM_NONE
    givemon SPECIES_ELEKID, 65, ITEM_THUNDER_STONE
    givemon SPECIES_MAGBY, 65, ITEM_FIRE_STONE
    givemon SPECIES_MILTANK, 65, ITEM_NONE
    givemon SPECIES_LARVITAR, 65, ITEM_NONE
    givemon SPECIES_TREECKO, 65, ITEM_NONE
    givemon SPECIES_TORCHIC, 65, ITEM_NONE
    givemon SPECIES_MUDKIP, 65, ITEM_NONE
    givemon SPECIES_POOCHYENA, 65, ITEM_NONE
    givemon SPECIES_ZIGZAGOON, 65, ITEM_NONE
    givemon SPECIES_GALAR_ZIGZAGOON, 65, ITEM_NONE
    givemon SPECIES_WURMPLE, 65, ITEM_NONE
    givemon SPECIES_SILCOON, 65, ITEM_SMOKE_BALL
    givemon SPECIES_CASCOON, 65, ITEM_SMOKE_BALL
    givemon SPECIES_LOTAD, 65, ITEM_WATER_STONE
    givemon SPECIES_SEEDOT, 65, ITEM_LEAF_STONE
    givemon SPECIES_TAILLOW, 65, ITEM_NONE
    givemon SPECIES_WINGULL, 65, ITEM_NONE
    givemon SPECIES_RALTS, 65, ITEM_NONE
    givemon SPECIES_GALLADE, 65, ITEM_NONE
    givemon SPECIES_SURSKIT, 65, ITEM_NONE
    givemon SPECIES_SHROOMISH, 65, ITEM_NONE
    givemon SPECIES_SLAKOTH, 65, ITEM_NONE

	message InsideOfTruck_Text_PC_Config10
	waitmessage
    givemon SPECIES_VIGOROTH, 65, ITEM_NONE
    givemon SPECIES_NINCADA, 65, ITEM_NONE
    givemon SPECIES_NINJASK, 65, ITEM_NONE
    givemon SPECIES_SHEDINJA, 65, ITEM_NONE
    givemon SPECIES_WHISMUR, 65, ITEM_NONE
    givemon SPECIES_MAKUHITA, 65, ITEM_NONE
    givemon SPECIES_AZURILL, 65, ITEM_NONE
    givemon SPECIES_NOSEPASS, 65, ITEM_THUNDER_STONE
    givemon SPECIES_SKITTY, 65, ITEM_MOON_STONE
    givemon SPECIES_SABLEYE, 65, ITEM_NONE
    givemon SPECIES_MAWILE, 65, ITEM_NONE
    givemon SPECIES_ARON, 65, ITEM_NONE
    givemon SPECIES_MEDITITE, 65, ITEM_NONE
    givemon SPECIES_ELECTRIKE, 65, ITEM_NONE
    givemon SPECIES_PLUSLE, 65, ITEM_NONE
    givemon SPECIES_MINUN, 65, ITEM_NONE
    givemon SPECIES_VOLBEAT, 65, ITEM_RED_FLUTE
    givemon SPECIES_ILLUMISE, 65, ITEM_RED_FLUTE
    givemon SPECIES_GULPIN, 65, ITEM_NONE
    givemon SPECIES_CARVANHA, 65, ITEM_NONE
    givemon SPECIES_WAILMER, 65, ITEM_NONE
    givemon SPECIES_NUMEL, 65, ITEM_NONE
    givemon SPECIES_NUMEL_LUCKY, 65, ITEM_NONE
    givemon SPECIES_TORKOAL, 65, ITEM_NONE
    givemon SPECIES_SPOINK, 65, ITEM_NONE
    givemon SPECIES_SPINDA, 65, ITEM_YELLOW_FLUTE
    givemon SPECIES_TRAPINCH, 65, ITEM_EVERSTONE
    givemon SPECIES_VIBRAVA, 65, ITEM_NONE
    givemon SPECIES_CACNEA, 65, ITEM_NONE
    givemon SPECIES_SWABLU, 65, ITEM_NONE
	
	message InsideOfTruck_Text_PC_Config11
	waitmessage
    givemon SPECIES_ZANGOOSE, 65, ITEM_NONE
    givemon SPECIES_SEVIPER, 65, ITEM_NONE
    givemon SPECIES_LUNATONE, 65, ITEM_NONE
    givemon SPECIES_SOLROCK, 65, ITEM_NONE
    givemon SPECIES_BARBOACH, 65, ITEM_NONE
    givemon SPECIES_CORPHISH, 65, ITEM_NONE
    givemon SPECIES_BALTOY, 65, ITEM_NONE
    givemon SPECIES_LILEEP, 65, ITEM_NONE
    givemon SPECIES_ANORITH, 65, ITEM_NONE
	givecustommon SPECIES_FEEBAS, 65, ITEM_NONE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, 0, 100
    givemon SPECIES_CASTFORM, 65, ITEM_NONE
    givemon SPECIES_KECLEON, 65, ITEM_NONE
    givemon SPECIES_SHUPPET, 65, ITEM_NONE
    givemon SPECIES_DUSKULL, 65, ITEM_NONE
    givemon SPECIES_TROPIUS, 65, ITEM_NONE
    givemon SPECIES_ABSOL, 65, ITEM_NONE
    givemon SPECIES_WYNAUT, 65, ITEM_NONE
    givemon SPECIES_SNORUNT, 65, ITEM_NONE
    givemon SPECIES_FROSLASS, 65, ITEM_NONE
    givemon SPECIES_SPHEAL, 65, ITEM_NONE
    givemon SPECIES_CLAMPERL, 65, ITEM_NONE
    givemon SPECIES_GOREBYSS, 65, ITEM_NONE
    givemon SPECIES_HUNTAIL, 65, ITEM_NONE
    givemon SPECIES_RELICANTH, 65, ITEM_NONE
    givemon SPECIES_LUVDISC, 65, ITEM_HEART_SCALE
    givemon SPECIES_BAGON, 65, ITEM_NONE
    givemon SPECIES_BELDUM, 65, ITEM_NONE
    givemon SPECIES_YAMASK, 65, ITEM_NONE
    givemon SPECIES_GALAR_YAMASK, 65, ITEM_NONE
    givemon SPECIES_SNOVER, 65, ITEM_NONE
	
	message InsideOfTruck_Text_PC_Config12
	waitmessage
    givemon SPECIES_GROOKEY, 65, ITEM_NONE
    givemon SPECIES_GOLETT, 65, ITEM_NONE
    givemon SPECIES_TYRUNT, 65, ITEM_NONE
    givemon SPECIES_AMAURA, 65, ITEM_NONE
    givemon SPECIES_DEINO, 65, ITEM_NONE
    givemon SPECIES_JANGMO_O, 65, ITEM_NONE
    givemon SPECIES_DREEPY, 65, ITEM_NONE
    givemon SPECIES_SKORUPI, 65, ITEM_NONE
    givemon SPECIES_WOOLOO, 65, ITEM_NONE
    givemon SPECIES_RIOLU, 65, ITEM_NONE
    givemon SPECIES_TYNAMO, 65, ITEM_THUNDER_STONE
    givemon SPECIES_GRUBBIN, 65, ITEM_THUNDER_STONE
    givemon SPECIES_LITWICK, 65, ITEM_NONE
    givemon SPECIES_ROWLET, 65, ITEM_NONE
    givemon SPECIES_DECIDUEYE_HISUIAN, 65, ITEM_NONE
    givemon SPECIES_POPPLIO, 65, ITEM_NONE
    givemon SPECIES_SOBBLE, 65, ITEM_NONE
    givemon SPECIES_TURTWIG, 65, ITEM_NONE
    givemon SPECIES_PIPLUP, 65, ITEM_NONE
    givemon SPECIES_DHELMISE, 65, ITEM_NONE
    givemon SPECIES_PAWNIARD, 65, ITEM_NONE
    givemon SPECIES_IMPIDIMP, 65, ITEM_NONE
    givemon SPECIES_SALANDIT, 65, ITEM_NONE
    givemon SPECIES_SALAZZLE, 65, ITEM_NONE
    givemon SPECIES_SANDYGAST, 65, ITEM_NONE
    givemon SPECIES_FERROSEED, 65, ITEM_NONE
    givemon SPECIES_SANDILE, 65, ITEM_NONE
    givemon SPECIES_CROAGUNK, 65, ITEM_NONE
    givemon SPECIES_LILLIPUP, 65, ITEM_NONE
    givemon SPECIES_SIZZLIPEDE, 65, ITEM_NONE
	
	message InsideOfTruck_Text_PC_Config13
	waitmessage
    givemon SPECIES_ROOKIDEE, 65, ITEM_NONE
    givemon SPECIES_HAWLUCHA, 65, ITEM_NONE
    givemon SPECIES_DURANT, 65, ITEM_NONE
    givemon SPECIES_SNOM, 65, ITEM_NONE
    givemon SPECIES_TOXEL, 65, ITEM_NONE
    givemon SPECIES_TOXTRICITY_LK, 65, ITEM_NONE
    givemon SPECIES_TOXTRICITY, 65, ITEM_NONE
    givemon SPECIES_APPLIN, 65, ITEM_NONE
    givemon SPECIES_FLAPPLE, 65, ITEM_NONE
    givemon SPECIES_APPLETUN, 65, ITEM_NONE
    givemon SPECIES_DIPPLIN, 65, ITEM_NONE
    givemon SPECIES_DIPPLIN, 65, ITEM_DRAGON_SCALE
    givemon SPECIES_DURALUDON, 65, ITEM_DAWN_STONE
    givemon SPECIES_COTTONEE, 65, ITEM_NONE
    givemon SPECIES_HIPPOPOTAS, 65, ITEM_NONE
    givemon SPECIES_SILICOBRA, 65, ITEM_NONE
    givemon SPECIES_COMBEE, 65, ITEM_NONE
    givemon SPECIES_VESPIQUEN, 65, ITEM_NONE
    givemon SPECIES_PANCHAM, 65, ITEM_NONE
    givemon SPECIES_SKRELP, 65, ITEM_NONE
    givemon SPECIES_STUFFUL, 65, ITEM_NONE
    givemon SPECIES_PUMPKABOO, 65, ITEM_NONE
    givemon SPECIES_FRILLISH, 65, ITEM_NONE
    givemon SPECIES_ROCKRUFF, 65, ITEM_SUN_STONE
    givemon SPECIES_ROCKRUFF, 65, ITEM_MOON_STONE
    givemon SPECIES_ROCKRUFF, 65, ITEM_DUSK_STONE
    givemon SPECIES_SNIVY, 65, ITEM_NONE
    givemon SPECIES_MILCERY, 65, ITEM_NONE
    givemon SPECIES_BUDEW, 65, ITEM_SHINY_STONE
    givemon SPECIES_CHINGLING, 65, ITEM_CLEANSE_TAG
	
	message InsideOfTruck_Text_PC_Config14
	waitmessage
    givemon SPECIES_BONSLY, 65, ITEM_NONE
    givemon SPECIES_MIMEJR, 65, ITEM_NONE
    givemon SPECIES_GALAR_MRMIME, 65, ITEM_NONE
    givemon SPECIES_HAPPINY, 65, ITEM_SHINY_STONE
    givemon SPECIES_MUNCHLAX, 65, ITEM_NONE
    givemon SPECIES_MANTYKE, 65, ITEM_NONE
    givemon SPECIES_CHESPIN, 65, ITEM_NONE
    givemon SPECIES_CHIMCHAR, 65, ITEM_NONE
    givemon SPECIES_WINTASS, 65, ITEM_NONE
    givemon SPECIES_GOOMY, 65, ITEM_NONE
    givemon SPECIES_SLIGGOO_HISUIAN, 65, ITEM_NONE
    givemon SPECIES_STUNFISK, 65, ITEM_NONE
    givemon SPECIES_GALAR_STUNFISK, 65, ITEM_NONE
    givemon SPECIES_SOLOSIS, 65, ITEM_NONE
    givemon SPECIES_VULLABY, 65, ITEM_NONE
    givemon SPECIES_DRILBUR, 65, ITEM_NONE
    givemon SPECIES_PRINPAWN, 65, ITEM_NONE
    givemon SPECIES_KINCURS, 65, ITEM_NONE
    givemon SPECIES_COUREEN, 65, ITEM_NONE
    givemon SPECIES_POSORD, 65, ITEM_NONE
    givemon SPECIES_TRUBBISH, 65, ITEM_METAL_COAT
    givemon SPECIES_PANSAGE, 65, ITEM_LEAF_STONE
    givemon SPECIES_WATTREL, 65, ITEM_NONE
    givemon SPECIES_FLOETTE, 65, ITEM_NONE
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
	.string "POKéMON nivel 65 para afrontar este\l"
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

