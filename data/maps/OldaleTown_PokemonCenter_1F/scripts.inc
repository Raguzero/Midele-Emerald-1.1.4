OldaleTown_PokemonCenter_1F_MapScripts:: @ 81FC006
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition

	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition: @ 81FC011
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	call_if_unset FLAG_OLDALE_TOWN_PC_OCUPADO, OldaleTown_PokemonCenter_1F_EventScript_BlockPC
	end
	
OldaleTown_PokemonCenter_1F_EventScript_BlockPC::
	setobjectxyperm 6, 10, 2
	return

@ VAR_0x800B is the Nurse's object event id
OldaleTown_PokemonCenter_1F_EventScript_Nurse:: @ 81FC01A
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman:: @ 81FC028
	goto_if_set FLAG_OLDALE_TOWN_PC_OCUPADO, OldaleTown_PokemonCenter_1F_EventScript_Gentleman2
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCantUsePC, MSGBOX_NPC
	end
	
OldaleTown_PokemonCenter_1F_EventScript_Gentleman2::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy:: @ 81FC031
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl:: @ 81FC03A
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable:: @ 81FC04F
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_PokemonCenter_1F_EventScript_PCOcupado::
	lockall
	speakername CommonName_Text_a_vader
	goto_if_set FLAG_OLDALE_TOWN_PC_OCUPADO, OldaleTown_PokemonCenter_1F_EventScript_GoPC
	playse SE_PIN
	applymovement 6, Common_Movement_ExclamationMark
	msgbox OldaleTown_PokemonCenter_1F_Text_PCOcupado, MSGBOX_DEFAULT
	closemessage
	delay 120
	speakername CommonName_Text_a_vader
	msgbox OldaleTown_PokemonCenter_1F_Text_PCOcupado2, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 11
	call_if_ge OldaleTown_PokemonCenter_1F_EventScript_PlayerMoveToFrontFromRight
	applymovement 6, OldaleTown_PokemonCenter_1F_Movement_NPCPCOcupado
	waitmovement 0
	removeobject 6
	setflag FLAG_OLDALE_TOWN_PC_OCUPADO
	releaseall
	end
	
OldaleTown_PokemonCenter_1F_EventScript_GoPC::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	speakername CommonName_Text_a_vader
	msgbox OldaleTown_PokemonCenter_1F_Text_PCOcupado2, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end
	
OldaleTown_PokemonCenter_1F_EventScript_PlayerMoveToFrontFromRight::
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_PokemonCenter_1F_Movement_MoveToFrontFromRight
	waitmovement 0
	return
	
OldaleTown_PokemonCenter_1F_Movement_MoveToFrontFromRight:
	walk_down
	walk_right
	walk_in_place_fastest_up
	step_end

OldaleTown_PokemonCenter_1F_Movement_NPCPCOcupado:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

OldaleTown_PokemonCenter_1F_Text_TrainersCantUsePC: @ 81FC059
	.string "There is a PC in that corner, but a\n" 
	.string "POKéMON TRAINER is using it.$"
	
OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC: @ 81FC059
	.string "That PC in the corner there is\n"
	.string "for any POKéMON TRAINER to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat: @ 81FC0CD
	.string "POKéMON CENTERS are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable: @ 81FC148
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub: @ 81FC1B9
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.$"
	
OldaleTown_PokemonCenter_1F_Text_PCOcupado: @ 81FC1B9
	.string "¿Qué pasa? ¿Quieres usar este PC?\n"
	.string "Lo siento, pero este lo estoy usando\l"
	.string "yo, así que tendrás que usar el PC\l"
	.string "de la siguiente ciudad. ¡Jejeje!$"

OldaleTown_PokemonCenter_1F_Text_PCOcupado2: @ 81FC1B9
	.string "¡Que no! ¡Que era broma!\n"
	.string "Puedes usar el PC todo lo que quieras.$"
