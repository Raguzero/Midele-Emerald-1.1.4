Route101_MapScripts:: @ 81EBCBA
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnTransition: @ 81EBCC5
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnFrame: @ 81EBCCB
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

Route101_EventScript_HideMapNamePopup:: @ 81EBCD5
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE101_STATE, 1
	end

Route101_EventScript_StartBirchRescue:: @ 81EBCDE
	lockall
	playbgm MUS_EVENT0, 1
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
	closemessage
	setobjectxy 2, 0, 15
	setobjectxy 4, 0, 16
	applymovement EVENT_OBJ_ID_PLAYER, Route101_Movement_EnterScene
	applymovement 2, Route101_Movement_BirchRunAway1
	applymovement 4, Route101_Movement_PoochyenaChase1
	waitmovement 0
	applymovement 4, Route101_Movement_PoochyenaChaseInCircles
	applymovement 2, Route101_Movement_BirchRunInCircles
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement 4, Route101_Movement_PoochyenaFaceBirch
	applymovement 2, Route101_Movement_BirchFacePoochyena
	waitmovement 0
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE101_STATE, 2
	releaseall
	end

Route101_EventScript_PreventExitSouth:: @ 81EBD4E
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Route101_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitWest:: @ 81EBD64
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Route101_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitNorth:: @ 81EBD7A
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Route101_Movement_PreventExitNorth
	waitmovement 0
	releaseall
	end

Route101_Movement_PreventExitSouth: @ 81EBD90
	walk_up
	step_end

Route101_Movement_PreventExitWest: @ 81EBD92
	walk_right
	step_end

Route101_Movement_PreventExitNorth: @ 81EBD94
	walk_down
	step_end

Route101_Movement_PoochyenaChaseInCircles: @ 81EBD96
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_PoochyenaChase1: @ 81EBDB5
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_PoochyenaFaceBirch: @ 81EBDBD
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route101_Movement_EnterScene: @ 81EBDC2
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_fastest_left
	step_end

Route101_Movement_BirchRunInCircles: @ 81EBDC8
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_BirchRunAway1: @ 81EBDE7
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_BirchFacePoochyena: @ 81EBDEF
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Route101_Movement_Unused1: @ 81EBDF4
	walk_up
	walk_up
	step_end

Route101_Movement_Unused2: @ 81EBDF7
	walk_up
	walk_left
	walk_up
	step_end

Route101_EventScript_Youngster:: @ 81EBDFB
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end
	
Route101_EventScript_LevelCap::
	lockall
	speakername CommonName_Text_Desconocido
	msgbox Route101_Text_Ragu, MSGBOX_DEFAULT
	closemessage
	applymovement 7, Route101_Movement_Ragu
	waitmovement 0
	speakername CommonName_Text_Ragu
	msgbox Route101_Text_Ragu2, MSGBOX_DEFAULT
	speakername NULL
	giveitem ITEM_LEVEL_CAP, 1
	speakername CommonName_Text_Ragu
	msgbox Route101_Text_Ragu3, MSGBOX_DEFAULT
	closemessage
	applymovement 7, Route101_Movement_Ragu3
	waitmovement 0
	removeobject 7
	setvar VAR_LEVEL_CAP_RECEIVED, 2
	setflag FLAG_HIDE_RAGU_ROUTE_101
	releaseall
	end
	
Route101_EventScript_LevelCap2::
	lockall
	speakername CommonName_Text_Desconocido
	msgbox Route101_Text_Ragu, MSGBOX_DEFAULT
	closemessage
	applymovement 7, Route101_Movement_Ragu2
	waitmovement 0
	speakername CommonName_Text_Ragu
	msgbox Route101_Text_Ragu2, MSGBOX_DEFAULT
	speakername NULL
	giveitem ITEM_LEVEL_CAP, 1
	speakername CommonName_Text_Ragu
	msgbox Route101_Text_Ragu3, MSGBOX_DEFAULT
	closemessage
	applymovement 7, Route101_Movement_Ragu3
	waitmovement 0
	removeobject 7
	setvar VAR_LEVEL_CAP_RECEIVED, 2
	setflag FLAG_HIDE_RAGU_ROUTE_101
	releaseall
	end
	
Route101_Movement_Ragu:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_fast_down
	step_end

Route101_Movement_Ragu2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fast_down
	step_end
	
Route101_Movement_Ragu3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route101_EventScript_Boy:: @ 81EBE04
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_RouteSign:: @ 81EBE0D
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_BirchsBag:: @ 81EBE16
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	removeobject 4
	setobjectxy EVENT_OBJ_ID_PLAYER, 6, 13
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	special ChooseStarter
	waitstate
	applymovement 2, Route101_Movement_BirchApproachPlayer
	waitmovement 0
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
	special HealPlayerParty
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	setvar VAR_LEVEL_CAP_RECEIVED, 1
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Route101_EventScript_HideMayInBedroom
	compare VAR_RESULT, FEMALE
	call_if_eq Route101_EventScript_HideBrendanInBedroom
	clearflag FLAG_HIDE_RAGU_ROUTE_101
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 255, 6, 5
	waitstate
	release
	end

Route101_EventScript_HideMayInBedroom:: @ 81EBE85
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom:: @ 81EBE89
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Movement_BirchApproachPlayer: @ 81EBE8D
	walk_right
	step_end

Route101_Text_HelpMe: @ 81EBE8F
	.string "H-help me!$"

Route101_Text_PleaseHelp: @ 81EBE9A
	.string "Hello! You over there!\n"
	.string "Please! Help!\p"
	.string "In my BAG!\n"
	.string "There's a POKé BALL!$"

Route101_Text_DontLeaveMe: @ 81EBEDF
	.string "Wh-Where are you going?!\n"
	.string "Don't leave me like this!$"

Route101_Text_YouSavedMe: @ 81EBF12
	.string "PROF. BIRCH: Whew…\p"
	.string "I was in the tall grass studying wild\n"
	.string "POKéMON when I was jumped.\p"
	.string "You saved me.\n"
	.string "Thanks a lot!\p"
	.string "Oh?\p"
	.string "Hi, you're {PLAYER}{KUN}!\p"
	.string "This is not the place to chat, so come\n"
	.string "by my POKéMON LAB later, okay?$"

Route101_Text_TakeTiredPokemonToPokeCenter: @ 81EBFDD
	.string "If POKéMON get tired, take them to\n"
	.string "a POKéMON CENTER.\p"
	.string "There's a POKéMON CENTER in OLDALE\n"
	.string "TOWN right close by.$"

Route101_Text_WildPokemonInTallGrass: @ 81EC04A
	.string "Wild POKéMON will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch POKéMON, you have\n"
	.string "to go into the tall grass and search.$"

Route101_Text_RouteSign: @ 81EC0C8
	.string "ROUTE 101\n"
	.string "{UP_ARROW} OLDALE TOWN$"
	
Route101_Text_Ragu:
	.string "¡ALTO AHÍ!$"
	
Route101_Text_Ragu2:
	.string "¡Hola! Mi nombre es RAGU, y estoy\n"
	.string "buscando entrenadores que tengan\l"
	.string "potencial para afrontar un gran reto.\p"
	
	.string "Y este es el momento típico en el que\n"
	.string "te elogio diciéndote que eres genial,\l"
	.string "que tienes un potencial increíble,\l"
	.string "y te doy 20 REVIVEs por la cara,\l"
	.string "pero no, no va a ser así, ya que\l"
	.string "solo eres un NOOB...\l"
	.string "Al menos por ahora.\p"
	
	.string "¿Sabes? La gente siempre se queja\n"
	.string "de que POKéMON es muy fácil, de\l"
	.string "que se pasa el juego con los ojos\l"
	.string "cerrados a la pata coja con cualquier\l"
	.string "POKéMON overlevel, por malo que sea.\p"
	
	.string "Así que, ¿por qué no complicamos todo\n"
	.string "un poquito? ¿No te gustan los retos?\l"
	.string "¡A mí me gustan los retos!\p"
	
	.string "¡No digas nada!, te haré entrega de un\n"
	.string "objeto clave autolimitante de nivel, del\l"
	.string "que no te podrás desprender hasta que\l"
	.string "te puedas liberar tú mismo de las\l"
	.string "cadenas que te limitan.$"
	
Route101_Text_Ragu3:
	.string "Con el objeto LEVEL CAP podrás saber el\n"
	.string "límite de nivel que pueden alcanzar tus\l"
	.string "POKéMON en ese momento de la aventura.\p"
	
	.string "Normalmente podrás romper ese límite\n"
	.string "por cada medalla que consigas, pero no\l"
	.string "siempre será así. ¡El objeto te avisará\l"
	.string "cuando se rompa ese límite!\p"

	.string "Ahora mismo tus POKéMON no pueden\n"
	.string "superar el nivel 15 hasta que consigas\l"
	.string "derrotar al primer líder de GYM.\p"
	
	.string "Si tienes alguna duda sobre la limitación\n"
	.string "de nivel, solo tienes que usar el objeto\l"
	.string "que te acabo de dar.\p"
	
	.string "¡Adiós! Seguro que nos volveremos a ver.$"

CommonName_Text_Desconocido:
	.string "???$"

CommonName_Text_Ragu:
	.string "RAGU$"
