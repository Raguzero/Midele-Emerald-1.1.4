Route117_PokemonDayCare_MapScripts:: @ 822BBB1
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition:: @ 822BBB7
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end

Route117_PokemonDayCare_EventScript_Vladiland::
	lock
	faceplayer
	goto_if_set FLAG_DAYCARE_DITTO_RECEIVED, Route117_PokemonDayCare_EventScript_ExplainDitto
	msgbox Route117_PokemonDayCare_Text_Vladiland_BeforeBattle, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route117_PokemonDayCare_EventScript_Vladiland2
	release
	end

Route117_PokemonDayCare_EventScript_Vladiland2::
	msgbox Route117_PokemonDayCare_Text_Vladiland_BeforeBattle2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VLADILAND, Route117_PokemonDayCare_Text_Vladiland_Defeated
	msgbox Route117_PokemonDayCare_Text_Vladiland_AfterBattle, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_DITTO
	givecustommon SPECIES_DITTO, 20, ITEM_METAL_POWDER, ITEM_MASTER_BALL, NATURE_HARDY, 1, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE, TRUE
	compare VAR_RESULT, 0
	goto_if_eq Route117_PokemonDayCare_EventScript_Vladiland_ReceiveDittoParty
	compare VAR_RESULT, 1
	goto_if_eq Route117_PokemonDayCare_EventScript_Vladiland_ReceiveDittoPC
	goto Route117_PokemonDayCare_Vladiland_EventScript_NoRoomForPokemon
	end

Route117_PokemonDayCare_EventScript_Vladiland_ReceiveDittoParty::
	call Route117_PokemonDayCare_EventScript_Vladiland_ReceivedDittoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route117_PokemonDayCare_EventScript_Vladiland_AfterBattle
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route117_PokemonDayCare_EventScript_Vladiland_AfterBattle
	end

Route117_PokemonDayCare_EventScript_Vladiland_ReceiveDittoPC::
	call Route117_PokemonDayCare_EventScript_Vladiland_ReceivedDittoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route117_PokemonDayCare_EventScript_Vladiland_SendDittoToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route117_PokemonDayCare_EventScript_Vladiland_SendDittoToPC
	end

Route117_PokemonDayCare_EventScript_Vladiland_SendDittoToPC::
	call Common_EventScript_TransferredToPC
	msgbox Route117_PokemonDayCare_Text_Vladiland_Text_TakeDitto, MSGBOX_DEFAULT
	setflag FLAG_DAYCARE_DITTO_RECEIVED
	release
	end

Route117_PokemonDayCare_EventScript_Vladiland_ReceivedDittoFanfare::
	playfanfare MUS_FANFA4
	setflag FLAG_DAYCARE_DITTO_RECEIVED
	message Route117_PokemonDayCare_Text_Vladiland_PlayerReceivedDitto
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_DITTO
	return

Route117_PokemonDayCare_EventScript_Vladiland_AfterBattle::
	release
	end
	
Route117_PokemonDayCare_Vladiland_EventScript_NoRoomForPokemon::
	msgbox Route117_PokemonDayCare_Text_Vladiland_NoRoomForPokemon, MSGBOX_DEFAULT
	goto Route117_PokemonDayCare_EventScript_Vladiland_AfterBattle
	end

Route117_PokemonDayCare_EventScript_ExplainDitto::
	msgbox Route117_PokemonDayCare_Text_Vladiland_Text_TakeDitto, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Text_Vladiland_BeforeBattle:
	.string "Vaya, vaya... ¿Qué haces en este lugar?\p"

	.string "Así que te interesan estas cosas de\n"
	.string "crianza de POKéMON... a tu edad.\p"
	
	.string "Qué interesante... ¡MUY INTERESANTE!\n"
	.string "Mjmjmjmjmjmjmjmjjmjmjm...\p"
	
	.string "Bien, te explicaré en qué consiste,\n"
	.string "pero primero... ¿hacemos un combate\l"
	.string "POKéMON? Ten en cuenta que me adapto\l"
	.string "a tu POKéMON de mayor nivel, ¿jugamos?$"
	
Route117_PokemonDayCare_Text_Vladiland_BeforeBattle2:
	.string "¡¡¡Jejejejejeje!!!\p"
	
	.string "Bien, deja que primero te hipnotice\n" 
	.string "y te quite la ropa.$"

Route117_PokemonDayCare_Text_Vladiland_Defeated:
	.string "Vale... vale... ¿pero al menos\n"
	.string "no puedes darme una foto tuya\p"
	.string "sin ropa?$"

Route117_PokemonDayCare_Text_Vladiland_AfterBattle:
	.string "Bueno, para que veas cuánto te aprecio,\n"
	.string "déjame ofrecerte un regalo.\p"

	.string "Con esto serás el rey o la reina...\n"
	.string "(No me gusta hacer distinciones) de\l"
	.string "esta guardería de POKéMON.$"
	
Route117_PokemonDayCare_Text_Vladiland_Text_TakeDitto: 
	.string "¡Este DITTO que te he regalado es\n"
	.string "perfecto para que los POKéMON hagan\l"
	.string "sus cositas y saquen crías\l" 
	.string "como conejos!\p"
	
	.string "Dale tan buen uso como yo te daría a ti\n"
	.string "¡¡¡Jejejejejeje!!!!$"

Route117_PokemonDayCare_Text_Vladiland_NoRoomForPokemon: 
	.string "¡No tienes sitio para este\n"
	.string "regalo ni en la cajas!$"

Route117_PokemonDayCare_Text_Vladiland_PlayerReceivedDitto: 
	.string "{PLAYER} received DITTO!$"
