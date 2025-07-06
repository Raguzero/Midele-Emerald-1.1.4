MauvilleRuins_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleRuins_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleRuins_OnTransition
	.byte 0

MauvilleRuins_OnLoad:
	call_if_unset FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, MauvilleRuins_EventScript_HideRegiEntrance
	end

MauvilleRuins_EventScript_HideRegiEntrance:: 
	setmetatile 7, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 8, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 9, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	return

MauvilleRuins_OnTransition: 
	setflag FLAG_LANDMARK_MAUVILLE_RUINS
	call_if_unset FLAG_VADER_MAUVILLE_RUINS_ANTESDEABRIR, MauvilleRuins_Vader_BlockDoor
	end
	
MauvilleRuins_Vader_BlockDoor::
	setobjectxyperm 5, 8, 0
	return

MauvilleRuins_EventScript_OpenRegiEntrance:: 
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, 1
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, 1
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, 1
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, 1
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, 0
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, 1
	special DrawWholeMapView
	playse SE_BAN
	setflag FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED
	return

MauvilleRuins_EventScript_CaveEntranceMiddle::
	lockall
	goto_if_set FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, MauvilleRuins_EventScript_BigHoleInWall
	braillemessage MauvilleRuins_Braille_RegielekiPuzzle
	waitbuttonpress
	closebraillemessage
	specialvar VAR_RESULT, CheckRegielekiPuzzle
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleRuins_EventScript_CaveEntranceMiddle_End
	call MauvilleRuins_EventScript_OpenRegiEntrance
MauvilleRuins_EventScript_CaveEntranceMiddle_End:
	releaseall
	end

MauvilleRuins_EventScript_BigHoleInWall:: 
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

MauvilleRuins_EventScript_CaveEntranceSide::
	lockall
	braillemessage MauvilleRuins_Braille_RegielekiPuzzle
	goto_if_set FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, MauvilleRuins_EventScript_CloseBrailleMsg
	braillemessage MauvilleRuins_Braille_RegielekiPuzzle
	waitbuttonpress
	closebraillemessage
	specialvar VAR_RESULT, CheckRegielekiPuzzle
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleRuins_EventScript_CaveEntranceSide_End
	call MauvilleRuins_EventScript_OpenRegiEntrance
MauvilleRuins_EventScript_CaveEntranceSide_End:
	releaseall
	end

MauvilleRuins_EventScript_CloseBrailleMsg::
	waitbuttonpress
	closebraillemessage
	releaseall
	end
	
MauvilleRuins_EventScript_Regieleki_Robado::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIELEKI, 2
	delay 40
	waitmoncry
	addobject 3
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, MauvilleRuins_Avader2_Movement
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, MauvilleRuins_Movement_Player2
	waitmovement 0
	msgbox MauvilleRuins_Text_Vader2, MSGBOX_NPC
	// ANIMACION DE POKEBALL
	waitse
	playse SE_REGI
	removeobject 1
	delay 40
	clearflag FLAG_VADER_MAUVILLE_RUINS_ANTESDEABRIR
	addobject 4
	delay 80
	removeobject 4
	msgbox MauvilleRuins_Text_Vader3, MSGBOX_NPC
	applymovement 3, MauvilleRuins_Avader3_Movement
	waitmovement 0
	removeobject 3
	setflag FLAG_VADER_MAUVILLE_RUINS_ROBO
	setflag FLAG_VADER_MAUVILLE_RUINS_ANTESDEABRIR
	release
	end

MauvilleRuins_EventScript_Vader::
	lock
	faceplayer
	goto_if_set FLAG_VADER_MAUVILLE_RUINS_ANTESDEABRIR, MauvilleRuins_EventScript_Vader2
	goto_if_set FLAG_REGI_DOORS_OPENED, MauvilleRuins_EventScript_Vader2Extra
	msgbox MauvilleRuins_Text_Vader, MSGBOX_NPC
	switch VAR_FACING
	case DIR_EAST, MauvilleRuins_EventScript_East
	applymovement 2, MauvilleRuins_Avader_Movement
	waitmovement 0
	setflag FLAG_VADER_MAUVILLE_RUINS_ANTESDEABRIR
	releaseall
	end

MauvilleRuins_EventScript_East::
	applymovement EVENT_OBJ_ID_PLAYER, MauvilleRuins_Movement_Player
	waitmovement 0
	applymovement 2, MauvilleRuins_Avader_Movement
	waitmovement 0
	setflag FLAG_VADER_MAUVILLE_RUINS_ANTESDEABRIR
	releaseall
	end
	
MauvilleRuins_EventScript_Vader2Extra::
	goto_if_set FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, MauvilleRuins_EventScript_Vader3
	msgbox MauvilleRuins_Text_VaderExtra, MSGBOX_NPC
	switch VAR_FACING
	case DIR_EAST, MauvilleRuins_EventScript_East
	applymovement 2, MauvilleRuins_Avader_Movement
	waitmovement 0
	setflag FLAG_VADER_MAUVILLE_RUINS_ANTESDEABRIR
	releaseall
	end
	
MauvilleRuins_EventScript_Vader2::
	goto_if_set FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, MauvilleRuins_EventScript_Vader3
	msgbox MauvilleRuins_Text_Vader4, MSGBOX_NPC
	release
	end
	
MauvilleRuins_EventScript_Vader3::
	msgbox MauvilleRuins_Text_Vader5, MSGBOX_NPC
	release
	end
	
MauvilleRuins_Movement_Player:
	walk_down
	walk_in_place_fastest_up
	step_end
	
MauvilleRuins_Movement_Player2:
	walk_in_place_fastest_down
	step_end

MauvilleRuins_Avader_Movement:
	walk_left
	walk_in_place_fastest_right
	step_end
	
MauvilleRuins_Avader2_Movement:
	walk_up
	walk_up
	walk_up
	step_end
	
MauvilleRuins_Avader3_Movement:
	walk_down
	walk_down
	step_end
	
MauvilleRuins_MauvilleMewVader::
	lock
	faceplayer
	playmoncry SPECIES_MEW, 2
	waitmoncry
	msgbox MauvilleRuins_MauvilleMewVader_Text_1, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq MauvilleRuins_MauvilleMewVader2
	release
	end
MauvilleRuins_MauvilleMewVader2:
	setflag FLAG_AVADER_MAUVILLE_RUINS_MEW_BYE
	warp MAP_MICOLO_HIDEOUT_MEETING_ROOM, 0, 0, 0
	waitstate
	release
	end
	
MauvilleRuins_MauvilleMewVader_Text_1:
	.string "El MEW de A.VADER puede llevarte\n"
	.string "de vuelta hasta MICOLANDIA.\p"
	.string "¿Quieres que te lleve hacia allí?$"

	
MauvilleRuins_Text_Vader:
	.string "A.VADER: Este taladro de ANTHONY\n"
	.string "ha sido lo suficientemente\l"
	.string "poderoso para derribar la entrada\l"
	.string "de estas ruinas, pero ha quedado\l"
	.string "hecho trizas, ya no sirve para nada\l"
	.string "este cacharro.\p"

	.string "Vaya, ¡Pero si es {PLAYER}!\p"
	.string "No me había dado cuenta de que\n"
	.string "estabas justo ahí.\p"
	
	.string "Por cierto, si mis calculos son\n"
	.string "correctos...\p"
	
	.string "Esta es la cueva donde me tiré a\n"
	.string "tu MADRE, quiero decir... donde\l"
	.string "reside el poderoso POKéMON eléctrico\l"
	.string "con el nombre de REGIELEKI.\p"
	
	.string "Llevo mucho tiempo investigando a\n"
	.string "a estos seres llamados REGIS.\p"
	
	.string "Toda mi investigación era consistente\n"
	.string "en cuanto a que REGICE, REGIROCK y\l"
	.string "REGISTEEL deberían despertar al\l"
	.string "temido REGIGIGAS...\p" 
	
	.string "Pero...\p"
	
	.string "¿De dónde han salido REGIDRAGO y\n"
	.string "REGIELEKI? ¿Por qué existen?\p"
	
	.string "¡Por más que investigo no tiene sentido\n"
	.string "que existan estos últimos!\p"
	
	.string "¡Es como si los hubiesen inventado solo\n"
	.string "para intentar vendernos el DLC de\l"
	.string "POKéMON ESPADA y POKéMON ESCUDO!\p"
	
	.string "Ni siquiera tienen la habilidad CLEAR BODY\n"
	.string "de REGICE, REGIROCK y REGISTEEL.\p"
	
	.string "Tampoco se parecen sus Movepool a los\n"
	.string "suyos, al no poder aprender CURSE,\l" 
	.string "ni SUPERPOWER.\p"
	
	.string "¡Maldito MASUDA!, ¿Por qué te cargaste el\n"
	.string "LORE de HOENN y SINNOH?\p"
	
	.string "...\p"

	.string "EJEM...\p"
	
	.string "Dejemos de lado todo este brote autista\n"
	.string "y vayamos a lo importante de\l"
	.string "este asunto.\p"
	
	.string "¿Quieres abrir esta puerta para atrapar a\n"
	.string "REGIELEKI?\p"
	
	.string "Pues para abrir esta puerta tendrás que\n"
	.string "leer el código braille, así que para ello\l"
	.string "prueba a arrancarte los ojos, así serás\l"
	.string "ciego y no te quedará más remedio que\l" 
	.string "aprender BRAILLE.\p"
	
	.string "¡JAJAJAJAJAJAJA!\p"
	
	.string "Bueno, te ayudaré esta vez.\p"
	
	.string "El CÓDIGO BRAILLE dice:\p"
	.string "PRESENTA AL ELECTRICO\n"
	.string "QUE ILUMINA UN FARO.\p"
	
	.string "En mi viaje por JOHTO, me suena haber\n"
	.string "oído algo sobre cierto POKéMON que\l"
	.string "iluminaba un faro. ¿Cuál sería?\p"
	
	.string "¡Eso ya tendrás que descubrirlo usando\n"
	.string "tu cerebro de mosquito!\p"
	
	.string "Háblame de nuevo si quieres escuchar de\n"
	.string "nuevo toda mi autistada, y el cómo abrir\l"
	.string "esta puerta.$"
	
MauvilleRuins_Text_VaderExtra:
	.string "A.VADER: Que extraño. Vine a demoler la\n"
	.string "entrada de estas ruinas con el taladro\l"
	.string "que le robé a ANTHONY, pero la entrada\l"
	.string "ya estaba abierta.\p"

	.string "Vaya, ¡Pero si es {PLAYER}!\p"
	.string "No me había dado cuenta de que\n"
	.string "estabas justo ahí.\p"
	
	.string "Por cierto, si mis calculos son\n"
	.string "correctos...\p"
	
	.string "Esta es la cueva donde me tiré a\n"
	.string "tu MADRE, quiero decir... donde\l"
	.string "reside el poderoso POKéMON eléctrico\l"
	.string "con el nombre de REGIELEKI.\p"
	
	.string "Llevo mucho tiempo investigando a\n"
	.string "a estos seres llamados REGIS.\p"
	
	.string "Toda mi investigación era consistente\n"
	.string "en cuanto a que REGICE, REGIROCK y\l"
	.string "REGISTEEL deberían despertar al\l"
	.string "temido REGIGIGAS...\p" 
	
	.string "Pero...\p"
	
	.string "¿De dónde han salido REGIDRAGO y\n"
	.string "REGIELEKI? ¿Por qué existen?\p"
	
	.string "¡Por más que investigo no tiene sentido\n"
	.string "que existan estos últimos!\p"
	
	.string "¡Es como si los hubiesen inventado solo\n"
	.string "para intentar vendernos el DLC de\l"
	.string "POKéMON ESPADA y POKéMON ESCUDO!\p"
	
	.string "Ni siquiera tienen la habilidad CLEAR BODY\n"
	.string "de REGICE, REGIROCK y REGISTEEL.\p"
	
	.string "Tampoco se parecen sus Movepool a los\n"
	.string "suyos, al no poder aprender CURSE,\l" 
	.string "ni SUPERPOWER.\p"
	
	.string "¡Maldito MASUDA!, ¿Por qué te cargaste el\n"
	.string "LORE de HOENN y SINNOH?\p"
	
	.string "...\p"

	.string "EJEM...\p"
	
	.string "Dejemos de lado todo este brote autista\n"
	.string "y vayamos a lo importante de\l"
	.string "este asunto.\p"
	
	.string "¿Quieres abrir esta puerta para atrapar a\n"
	.string "REGIELEKI?\p"
	
	.string "Pues para abrir esta puerta tendrás que\n"
	.string "leer el código braille, así que para ello\l"
	.string "prueba a arrancarte los ojos, así serás\l"
	.string "ciego y no te quedará más remedio que\l" 
	.string "aprender BRAILLE.\p"
	
	.string "¡JAJAJAJAJAJAJA!\p"
	
	.string "Bueno, te ayudaré esta vez.\p"
	
	.string "El CÓDIGO BRAILLE dice:\p"
	.string "PRESENTA AL ELECTRICO\n"
	.string "QUE ILUMINA UN FARO.\p"
	
	.string "En mi viaje por JOHTO, me suena haber\n"
	.string "oído algo sobre cierto POKéMON que\l"
	.string "iluminaba un faro. ¿Cuál sería?\p"
	
	.string "¡Eso ya tendrás que descubrirlo usando\n"
	.string "tu cerebro de mosquito!\p"
	
	.string "Háblame de nuevo si quieres escuchar de\n"
	.string "nuevo toda mi autistada, y el cómo abrir\l"
	.string "esta puerta.$"
	
MauvilleRuins_Text_Vader4:
	.string "A.VADER: Si mis calculos son\n"
	.string "correctos...\p"
	
	.string "Esta es la cueva donde me tiré a\n"
	.string "tu MADRE, quiero decir... donde\l"
	.string "reside el poderoso POKéMON eléctrico\l"
	.string "con el nombre de REGIELEKI.\p"
	
	.string "Llevo mucho tiempo investigando a\n"
	.string "a estos seres llamados REGIS.\p"
	
	.string "Toda mi investigación era consistente\n"
	.string "en cuanto a que REGICE, REGIROCK y\l"
	.string "REGISTEEL deberían despertar al\l"
	.string "temido REGIGIGAS...\p" 
	
	.string "Pero...\p"
	
	.string "¿De dónde han salido REGIDRAGO y\n"
	.string "REGIELEKI? ¿Por qué existen?\p"
	
	.string "¡Por más que investigo no tiene sentido\n"
	.string "que existan estos últimos!\p"
	
	.string "¡Es como si los hubiesen inventado solo\n"
	.string "para intentar vendernos el DLC de\l"
	.string "POKéMON ESPADA y POKéMON ESCUDO!\p"
	
	.string "Ni siquiera tienen la habilidad CLEAR BODY\n"
	.string "de REGICE, REGIROCK y REGISTEEL.\p"
	
	.string "Tampoco se parecen sus Movepool a los\n"
	.string "suyos, al no poder aprender CURSE,\l" 
	.string "ni SUPERPOWER.\p"
	
	.string "¡Maldito MASUDA!, ¿Por qué te cargaste el\n"
	.string "LORE de HOENN y SINNOH?\p"
	
	.string "...\p"

	.string "EJEM...\p"
	
	.string "Dejemos de lado todo este brote autista\n"
	.string "y vayamos a lo importante de\l"
	.string "este asunto.\p"
	
	.string "¿Quieres abrir esta puerta para atrapar a\n"
	.string "REGIELEKI?\p"
	
	.string "Pues para abrir esta puerta tendrás que\n"
	.string "leer el código braille, así que para ello\l"
	.string "prueba a arrancarte los ojos, así serás\l"
	.string "ciego y no te quedará más remedio que\l" 
	.string "aprender BRAILLE.\p"
	
	.string "¡JAJAJAJAJAJAJA!\p"
	
	.string "Bueno, te ayudaré esta vez.\p"
	
	.string "El CÓDIGO BRAILLE dice:\p"
	.string "PRESENTA AL ELECTRICO\n"
	.string "QUE ILUMINA UN FARO.\p"
	
	.string "En mi viaje por JOHTO, me suena haber\n"
	.string "oído algo sobre cierto POKéMON que\l"
	.string "iluminaba un faro. ¿Cuál sería?\p"
	
	.string "¡Eso ya tendrás que descubrirlo usando\n"
	.string "tu cerebro de mosquito!\p"
	
	.string "Háblame de nuevo si quieres escuchar de\n"
	.string "nuevo toda mi autistada, y el cómo abrir\l"
	.string "esta puerta.$"

MauvilleRuins_Text_Vader2:
	.string "A.VADER: Gracias por hacerme el\n"
	.string "trabajo sucio.\p"

	.string "Ahora voy a llevarme lo que\n"
	.string "me pertenece.\p"
	
	.string "“A.VADER usa una MASTER BALL”$"

MauvilleRuins_Text_Vader3:
	.string "¿Qué habría sido más divertido?\p"
	
	.string "¿Abrir la puerta sellada yo mismo?\p"

	.string "O... ¿Dejar que un NOOB como tú lo\n"
	.string "hiciera por mí para después trolearle\l"
	.string "robándole a REGIELEKI delante de sus\l"
	.string "narices?\p"
	
	.string "¡Está claro que lo segundo! ¡JAJAJAJA!\p"
	
	.string "¡Adios PRINGAO, nos vemos en MICOLANDIA!$"
	
MauvilleRuins_Text_Vader5:
	.string "A.VADER: ¡Today, We Use Our Power To Fell\n"
	.string "A God, And Then... Seize Our Destiny!!$"
