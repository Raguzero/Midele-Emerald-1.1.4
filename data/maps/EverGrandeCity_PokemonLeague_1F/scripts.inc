EverGrandeCity_PokemonLeague_1F_MapScripts:: @ 82295D2
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition

	.byte 0

EverGrandeCity_PokemonLeague_1F_OnTransition: @ 82295DD
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_2
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	call_if_unset FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor:: @ 82295ED
	setobjectxyperm 3, 9, 2
	setobjectxyperm 4, 10, 2
	return

@ VAR_0x800B is the Nurse's object event id
EverGrandeCity_PokemonLeague_1F_EventScript_Nurse:: @ 82295FC
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_Clerk:: @ 822960A
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EverGrandeCity_PokemonLeague_1F_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
EverGrandeCity_PokemonLeague_1F_Pokemart: @ 8229624
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ELIXIR
	.2byte ITEM_MAX_ELIXIR
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

@ The door guards only check for FLAG_BADGE06_GET because Winonas badge is the only one that can be skipped
@ Its assumed the player has the remaining badges
EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard:: @ 8229636
	lockall
	goto_if_set FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GoForth
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 11
	call_if_ge EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight
	compare VAR_TEMP_0, 8
	call_if_le EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft
	message EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges
	waitmessage
	delay 120
	goto_if_unset FLAG_BADGE06_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
	closemessage
	applymovement 3, EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay
	applymovement 4, EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay
	waitmovement 0
	delay 10
	playfanfare MUS_ME_BACHI
	message EverGrandeCity_PokemonLeague_1F_Text_GoForth
	waitmessage
	waitfanfare
	closemessage
	copyobjectxytoperm 3
	copyobjectxytoperm 4
	setflag FLAG_ENTERED_ELITE_FOUR
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight:: @ 8229698
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft:: @ 82296A3
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges:: @ 82296AE
	playse SE_HAZURE
	msgbox EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges, MSGBOX_DEFAULT
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GoForth:: @ 82296BB
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox EverGrandeCity_PokemonLeague_1F_Text_GoForth, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight: @ 82296DA
	walk_down
	walk_left
	walk_in_place_fastest_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft: @ 82296DE
	walk_down
	walk_right
	walk_in_place_fastest_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay: @ 82296E2
	walk_left
	walk_in_place_fastest_down
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay: @ 82296E5
	walk_right
	walk_in_place_fastest_down
	step_end
	
Ryu_StartRandomBattle::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RANDOM_Batalla, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq NoBattle
	multichoicegrid 0, 0, MULTI_RANDOMBATTLE, 3, 0
	switch VAR_RESULT
	case 0, RANDOMINDIVIDUAL
	case 1, RANDOMDOBLES
	case 2, NoBattle
	case MULTI_B_PRESSED, NoBattle
	end

RANDOMINDIVIDUAL::	
	special HealPlayerParty
	setflag FLAG_RYU_RANDOMBATTLE
	msgbox StartingRandomBattleMsg
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE
    setvar VAR_0x8005, 0
	setvar VAR_0x800B, UPDATE_VICTORIES_NORMAL_INDIVIDUAL
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq BF_RandomBattleCleanupDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq BF_RandomBattleCleanupWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq BF_RandomBattleCleanupLOSS
    compare VAR_RESULT, B_OUTCOME_FORFEITED
    call_if_eq BF_RandomBattleCleanupLOSS
	end

RANDOMDOBLES::	
	special HealPlayerParty
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_perodeverdad
	compare VAR_RESULT, 1
	goto_if_le DoblesObligatorio2Pokes
	setflag FLAG_RYU_RANDOMBATTLE
	msgbox StartingRandomBattleMsg
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE_2
    setvar VAR_0x8005, 0
	setvar VAR_0x800B, UPDATE_VICTORIES_NORMAL_DOUBLES
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq BF_RandomBattleCleanupDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq BF_RandomBattleCleanupWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq BF_RandomBattleCleanupLOSS
    compare VAR_RESULT, B_OUTCOME_FORFEITED
    call_if_eq BF_RandomBattleCleanupLOSS
	end

StartingRandomBattleMsg:
	.string "Starting Random Battle...$"

BF_RandomBattleCleanupWIN::
	special HealPlayerParty
	clearflag FLAG_RYU_RANDOMBATTLE
	setvar VAR_0x800A, UPDATE_VICTORIES_OP_INCREMENT
	special UpdateRandomBattleVictories
	msgbox Enhorabuena
	goto Script_RandomPrizes
	end

BF_RandomBattleCleanupLOSS::
	special HealPlayerParty
	setvar VAR_0x800A, UPDATE_VICTORIES_OP_RESET
	special UpdateRandomBattleVictories
	msgbox BattleAgain
	clearflag FLAG_RYU_RANDOMBATTLE
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
BF_RandomBattleCleanupDRAW::
	special HealPlayerParty
	setvar VAR_0x800A, UPDATE_VICTORIES_OP_RESET
	special UpdateRandomBattleVictories
	msgbox Empate
	clearflag FLAG_RYU_RANDOMBATTLE
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
BF_NoBattle::
	msgbox BF_NoBattleMsg
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
DoblesObligatorio2Pokes::
	msgbox DoblesObligatorio2Pokes_Text
	closemessage
	release
	end	
	
Ryu_StartRandomBattleCC::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RANDOMCC_Batalla, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq NoBattle
	multichoicegrid 0, 0, MULTI_RANDOMBATTLECC, 1, 0
	switch VAR_RESULT
	case 0, RANDOMCCINDIVIDUAL
	case 1, RANDOMCCDOBLES
	case 2, RANDOMCCINDIVIDUALMETRO
	case 3, RANDOMCCDOBLESMETRO
	case 4, NoBattle
	case MULTI_B_PRESSED, NoBattle
	end

RANDOMCCINDIVIDUAL::
    special SavePlayerParty
	setflag FLAG_RYU_RANDOMBATTLECC
	msgbox StartingRandomBattleMsg
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE
    setvar VAR_0x8005, 0
	setvar VAR_0x800B, UPDATE_VICTORIES_CC_INDIVIDUAL
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq BF_RandomBattleCleanupDRAWCC
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq BF_RandomBattleCleanupWINCC
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq BF_RandomBattleCleanupLOSSCC
    compare VAR_RESULT, B_OUTCOME_FORFEITED
    call_if_eq BF_RandomBattleCleanupLOSSCC
	end

RANDOMCCDOBLES::
    special SavePlayerParty
	setflag FLAG_RYU_RANDOMBATTLECC
	msgbox StartingRandomBattleMsg
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE_2
    setvar VAR_0x8005, 0
	setvar VAR_0x800B, UPDATE_VICTORIES_CC_DOUBLES
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq BF_RandomBattleCleanupDRAWCC
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq BF_RandomBattleCleanupWINCC
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq BF_RandomBattleCleanupLOSSCC
    compare VAR_RESULT, B_OUTCOME_FORFEITED
    call_if_eq BF_RandomBattleCleanupLOSSCC
	end

RANDOMCCINDIVIDUALMETRO::
    special SavePlayerParty
	setflag FLAG_RYU_RANDOMBATTLECC
	setflag FLAG_RYU_RANDOMBATTLECCMETRO
	msgbox StartingRandomBattleMsg
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq BF_RandomBattleCleanupDRAWCCMetro
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq BF_RandomBattleCleanupWINCCMetro
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq BF_RandomBattleCleanupLOSSCCMetro
    compare VAR_RESULT, B_OUTCOME_FORFEITED
    call_if_eq BF_RandomBattleCleanupLOSSCCMetro
	end

RANDOMCCDOBLESMETRO::
    special SavePlayerParty
	setflag FLAG_RYU_RANDOMBATTLECC
	setflag FLAG_RYU_RANDOMBATTLECCMETRO
	msgbox StartingRandomBattleMsg
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE_2
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq BF_RandomBattleCleanupDRAWCCMetro
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq BF_RandomBattleCleanupWINCCMetro
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq BF_RandomBattleCleanupLOSSCCMetro
    compare VAR_RESULT, B_OUTCOME_FORFEITED
    call_if_eq BF_RandomBattleCleanupLOSSCCMetro
	end

NoBattle::
	msgbox BF_NoBattleMsg
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BF_RandomBattleCleanupWINCC::
	setvar VAR_0x800A, UPDATE_VICTORIES_OP_INCREMENT
	special UpdateRandomBattleVictories
BF_RandomBattleCleanupWINCCMetro:: @ en metro no se actualiza el contador de victorias
	special LoadPlayerParty
	clearflag FLAG_RYU_RANDOMBATTLECC
	clearflag FLAG_RYU_RANDOMBATTLECCMETRO
	msgbox Enhorabuena
	goto Script_RandomPrizes
	end
	
BF_RandomBattleCleanupLOSSCC::
	setvar VAR_0x800A, UPDATE_VICTORIES_OP_RESET
	special UpdateRandomBattleVictories
BF_RandomBattleCleanupLOSSCCMetro:: @ en metro no se actualiza el contador de victorias
	special LoadPlayerParty
	msgbox BattleAgain
	clearflag FLAG_RYU_RANDOMBATTLECC
	clearflag FLAG_RYU_RANDOMBATTLECCMETRO
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
BF_RandomBattleCleanupDRAWCC::
	setvar VAR_0x800A, UPDATE_VICTORIES_OP_RESET
	special UpdateRandomBattleVictories
BF_RandomBattleCleanupDRAWCCMetro:: @ en metro no se actualiza el contador de victorias
	special LoadPlayerParty
	msgbox Empate
	clearflag FLAG_RYU_RANDOMBATTLECC
	clearflag FLAG_RYU_RANDOMBATTLECCMETRO
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
Script_RandomPrizes::
	lock
	faceplayer
	random 8
	switch VAR_RESULT
	case 0, Script_RandomPrize1
	case 1, Script_RandomPrize2
	case 2, Script_RandomPrize3
	case 3, Script_RandomPrize4
	case 4, Script_RandomPrize5
	case 5, Script_RandomPrize6
	case 6, Script_RandomPrize7
	case 7, Script_RandomPrize8
	end

Script_RandomPrize1::
	giveitem ITEM_HEART_SCALE, 4
	compare VAR_RESULT, FALSE
	call_if_eq Script_RandomPrize1_BagFull
	closemessage
	goto Fin_RandomPrize
	end

Script_RandomPrize2::
	giveitem ITEM_PP_MAX, 2
	compare VAR_RESULT, FALSE
	call_if_eq Script_RandomPrize1_BagFull
	closemessage
	goto Fin_RandomPrize
	end

Script_RandomPrize3::
	giveitem ITEM_LUCKY_EGG, 1
	compare VAR_RESULT, FALSE
	call_if_eq Script_RandomPrize1_BagFull
	closemessage
	goto Fin_RandomPrize
	end
	
Script_RandomPrize4::
	giveitem ITEM_LEFTOVERS, 1
	compare VAR_RESULT, FALSE
	call_if_eq Script_RandomPrize1_BagFull
	closemessage
	goto Fin_RandomPrize
	end

Script_RandomPrize5::
	giveitem ITEM_FOCUS_SASH, 3
	compare VAR_RESULT, FALSE
	call_if_eq Script_RandomPrize1_BagFull
	closemessage
	goto Fin_RandomPrize
	end

Script_RandomPrize6::
	giveitem ITEM_NUGGET, 4
	compare VAR_RESULT, FALSE
	call_if_eq Script_RandomPrize1_BagFull
	closemessage
	goto Fin_RandomPrize
	end

Script_RandomPrize7::
	giveitem ITEM_PP_UP, 4
	compare VAR_RESULT, FALSE
	call_if_eq Script_RandomPrize1_BagFull
	closemessage
	goto Fin_RandomPrize
	end

Script_RandomPrize8::
	giveitem ITEM_RARE_CANDY, 4
	compare VAR_RESULT, FALSE
	call_if_eq Script_RandomPrize1_BagFull
	closemessage
	goto Fin_RandomPrize
	end
	
Script_RandomPrize1_BagFull::
	call Common_EventScript_BagIsFull
	msgbox Script_RandomPrize1_Text_NoRoomForThis, MSGBOX_DEFAULT
	return
	
Fin_RandomPrize::
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

EverGrandeCity_PokemonLeague_1F_Sign_VictoriasNormal::
	lock
	setvar VAR_0x8008, SHOW_VICTORIES_NORMAL
	special BufferRandomBattleVictories
	msgbox EverGrandeCity_PokemonLeague_1F_Text_VictoriasNormal, MSGBOX_SIGN
	release
	end

EverGrandeCity_PokemonLeague_1F_Sign_VictoriasCC::
	lock
	setvar VAR_0x8008, SHOW_VICTORIES_CC
	special BufferRandomBattleVictories
	msgbox EverGrandeCity_PokemonLeague_1F_Text_VictoriasCC, MSGBOX_SIGN
	release
	end
	
Script_RandomPrize1_Text_NoRoomForThis:
	.string "¿Así que no tienes espacio para esto?\n"
	.string "¿Pero cuántos objetos distintos\l"
	.string "llevas en la mochila?\p"

	.string "Bien, guardaré tu premio, pero tendrás\n"
	.string "que vencerme de nuevo.\p"
	
	.string "¡Recuerda dejar espacio en tu mochila!$"

RANDOMCC_Batalla:
	.string "¡Te doy la bienvenida al simulador de\n"
	.string "CHALLENGE CUP! Abreviado como CC.\p"
	
	.string "Esta simulación consiste\n"
	.string "en una batalla individual\l"
	.string "o dobles, con POKéMON con\l"
	.string "sets totalmente aleatorios.\p"
	
	.string "Tanto tu equipo como el\n"
	.string "de tu rival.\p"
	
	.string "Si consigues la victoria,\n"
	.string "podrás ganar un premio.\p"
	
	.string "¿Quieres participar?$"

RANDOM_Batalla:
	.string "¡Te doy la bienvenida al simulador de\n"
	.string "RANDOM BATTLE!\p"
	
	.string "Esta simulación consiste\n"
	.string "en una batalla individual\l"
	.string "o dobles, contra un rival\l"
	.string "que usará POKéMON con sets\l"
	.string "totalmente aleatorios.\p"
	
	.string "Si consigues la victoria,\n"
	.string "podrás ganar un premio.\p"
	
	.string "¿Quieres participar?$"

BattleAgain:
	.string "Vaya, ¡perdiste!\n"
    .string "¡Háblame de nuevo\l"
	.string "si quieres otra batalla!$"
	
Enhorabuena:
	.string "Ganaste, pero ha sido por muy poco.\p"

	.string "Te mereces este premio.$"
	
Empate:
	.string "Hemos empatado ¿Repetimos?$"
	
BF_NoBattleMsg:
    .string "Muy bien. ¡Háblame de nuevo\n"
    .string "si quieres una batalla!$"
	
DoblesObligatorio2Pokes_Text:
    .string "Lo siento, pero debes llevar\n"
	.string "al menos dos POKéMON en el equipo\l"
	.string "para participar en Batalla Dobles$"

EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges: @ 82296E8
	.string "Beyond this point, only those TRAINERS\n"
	.string "who have collected all the GYM BADGES\l"
	.string "are permitted to enter.\p"
	.string "TRAINER, let us confirm that you have\n"
	.string "all the GYM BADGES.$"

EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges: @ 8229787
	.string "You haven't obtained all the BADGES.\p"
	.string "If you're bound for the POKéMON\n"
	.string "LEAGUE, you must return with them.$"

EverGrandeCity_PokemonLeague_1F_Text_GoForth: @ 82297EF
	.string "TRAINER! Believe in yourself and your\n"
	.string "POKéMON, and go forth!$"

EverGrandeCity_PokemonLeague_1F_Text_VictoriasNormal:
	.string "---VICTORIAS BATALLAS NORMALES---\p"
	.string "---INDIVIDUALES---\p"
	.string "Racha actual: {STR_VAR_1}\n"
	.string "Racha máxima: {STR_VAR_2}\p"
	.string "---DOBLES---\p"
	.string "Racha actual: {STR_VAR_3}\n"
	.string "Racha máxima: {STR_VAR_5}$"

EverGrandeCity_PokemonLeague_1F_Text_VictoriasCC:
	.string "---VICTORIAS BATALLAS CC---\p"
	.string "---INDIVIDUALES---\p"
	.string "Racha actual: {STR_VAR_1}\n"
	.string "Racha máxima: {STR_VAR_2}\p"
	.string "---DOBLES---\p"
	.string "Racha actual: {STR_VAR_3}\n"
	.string "Racha máxima: {STR_VAR_5}$"
