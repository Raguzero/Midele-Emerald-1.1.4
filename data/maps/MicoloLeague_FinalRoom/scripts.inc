MicoloLeague_FinalRoom_MapScripts::
	.byte 0

MicoloLeague_FinalRoom_Micolo::
	lockall
	faceplayer
	trainerbattle_single TRAINER_MICOLO_MICOLANDIA, MicoloLeague_FinalRoom_Micolo_Text_0, MicoloLeague_FinalRoom_Micolo_Text_1, MicoloLeague_FinalRoom_Micolo_Defeat, FALSE
	releaseall
	return


MicoloLeague_FinalRoom_Micolo_Defeat::
	lockall
	msgbox MicoloLeague_FinalRoom_Micolo_Defeat_Text_1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_1, SPECIES_DARK_PIKACHU
	msgbox MicoloLeague_FinalRoom_Micolo_DarkPika, MSGBOX_DEFAULT
	givecustommon SPECIES_DARK_PIKACHU, 5, ITEM_STARF_BERRY, ITEM_MASTER_BALL, NATURE_HARDY, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DARK_THUNDER, MOVE_HOLA_REINA, MOVE_MIDELE_POWER, MOVE_BRUTAL_BALL, 0
	compare VAR_RESULT, 0
	goto_if_eq MicoloLeague_FinalRoom_Micolo_EventScript_ReceiveMonParty
	compare VAR_RESULT, 1
	goto_if_eq MicoloLeague_FinalRoom_Micolo_EventScript_ReceiveMonPC
	goto MicoloLeague_FinalRoom_Micolo_EventScript_NoMoreRoomForPokemon
MicoloLeague_FinalRoom_Micolo_EventScript_ReceiveMonEnd:
	setflag FLAG_FORM_SPOILER_DEX
	checkitem ITEM_PSYCHE_ARMOR, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MicoloLeague_FinalRoom_Micolo_Defeat_2
MicoloLeague_FinalRoom_Micolo_Defeat_1:
	msgbox MicoloLeague_FinalRoom_Micolo_Defeat_Text_2, MSGBOX_DEFAULT	
	call MicoloLeague_FinalRoom_GameEndFlags
	goto_if_unset FLAG_MICOLANDIA_MODE, MicoloLeague_FinalRoom_Micolo_Defeat_1_Continue
	setrespawn HEAL_LOCATION_MICOLANDIA
	special SavePostMicolo @ Guarda partida
	closemessage
	fadescreenspeed FADE_TO_BLACK, 24
	special ShowGameCredits @ Muestra créditos
	waitstate
	releaseall
	return

MicoloLeague_FinalRoom_Micolo_Defeat_1_Continue:
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MicoloLeague_FinalRoom_Micolo_Defeat_5
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
MicoloLeague_FinalRoom_Micolo_Defeat_4:
	special SavePostMicolo @ Guarda partida
	closemessage
	fadescreenspeed FADE_TO_BLACK, 24
	special ShowGameCredits @ Muestra créditos
	waitstate
	releaseall
	return

MicoloLeague_FinalRoom_Micolo_EventScript_ReceiveMonParty:: @ 8270085
	call MicoloLeague_FinalRoom_Micolo_EventScript_ReceiveMonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MicoloLeague_FinalRoom_Micolo_EventScript_ReceiveMonEnd
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MicoloLeague_FinalRoom_Micolo_EventScript_ReceiveMonEnd
	end

MicoloLeague_FinalRoom_Micolo_EventScript_ReceiveMonPC:: @ 82700AD
	call MicoloLeague_FinalRoom_Micolo_EventScript_ReceiveMonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MicoloLeague_FinalRoom_Micolo_EventScript_SendMonPC
	call Common_EventScript_NameReceivedBoxMon
	goto MicoloLeague_FinalRoom_Micolo_EventScript_SendMonPC
	end
	
MicoloLeague_FinalRoom_Micolo_EventScript_SendMonPC:: @ 82700D0
	call Common_EventScript_TransferredToPC
	goto MicoloLeague_FinalRoom_Micolo_EventScript_ReceiveMonEnd
	end
	
MicoloLeague_FinalRoom_Micolo_EventScript_NoMoreRoomForPokemon::
	msgbox MicoloLeague_FinalRoom_Micolo_gText_NoMoreRoomForPokemon, MSGBOX_DEFAULT
	goto MicoloLeague_FinalRoom_Micolo_EventScript_ReceiveMonEnd
	end

MicoloLeague_FinalRoom_Micolo_EventScript_ReceiveMonFanfare:: @ 82700DB
	playfanfare MUS_FANFA4
	message MicoloLeague_FinalRoom_Micolo_Text_ReceivedMon
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_DARK_PIKACHU
	return

MicoloLeague_FinalRoom_Micolo_Defeat_2:
	msgbox MicoloLeague_FinalRoom_Micolo_Defeat_Text_0, MSGBOX_DEFAULT
	giveitem ITEM_PSYCHE_ARMOR, 1
	goto MicoloLeague_FinalRoom_Micolo_Defeat_1

MicoloLeague_FinalRoom_Micolo_Defeat_5:
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	goto MicoloLeague_FinalRoom_Micolo_Defeat_4


MicoloLeague_FinalRoom_GameEndFlags::
	cleartrainerflag TRAINER_PACOCHEF_MICOLANDIA
	cleartrainerflag TRAINER_LAVENDER_MICOLANDIA
	cleartrainerflag TRAINER_AVADER_MICOLANDIA
	cleartrainerflag TRAINER_RAGU
    cleartrainerflag TRAINER_MICOLO_MICOLANDIA
	return


MicoloLeague_FinalRoom_Micolo_Text_0:
	.string "Así que volvemos a vernos. n.n\n"
	.string "Enhorabuena por derrotar al smod inútil\l"
	.string "y vencer a los tres PALLASOS.\p"

	.string "Desde la primera vez que te ví, supe\n"
	.string "que llegarías hasta aquí.\p"
	
	.string "Durante mis viajes estuve pensando\n" 
	.string "en hacer algo diferente a los desafíos\l" 
	.string "a los que me enfrentaba. En mi aventura\l" 
	.string "por HOENN descubrí el BATTLE FRONTIER,\l"
	.string "en ese lugar se me ocurrió lo que estaba\l" 
	.string "pensando en mis otros viajes,\l" 
	.string "el desafío definitivo, por esa razón\l"
	.string "construí con la ayuda de mis POKéMON y\l" 
	.string "mis más fieles seguidores, el lugar\l"
	.string "donde estamos ahora.\p"
	
	.string "¿Todo listo? ¡Ahora te enfrentarás a la\n" 
	.string "pesadilla Midelar!$"

MicoloLeague_FinalRoom_Micolo_Text_1:
	.string "Monociclo porque mono es uno y la vida\n"
	.string "es un ciclo.$"

MicoloLeague_FinalRoom_Micolo_Defeat_Text_0:
	.string "También te hago entrega de este pequeño\n"
	.string "regalo, fruto de una de mis más\l"
	.string "ambiciosas investigaciones.\p"
	
	.string "¡Con esto podrás hacer que MEWTWO\n"
	.string "alcance su máximo potencial!$"
	
MicoloLeague_FinalRoom_Micolo_DarkPika:
	.string "Además te entrego un POKéMON muy\n"
	.string "especial. Tiene el poderosísimo\l"
	.string "MIDELE POWER, no se lo olvides o\l"
	.string "no podrá recordarlo.\p"
	.string "Espero que tengas espacio en tu\n"
	.string "equipo o en el PC.$"
	
MicoloLeague_FinalRoom_Micolo_gText_NoMoreRoomForPokemon:
	.string "Vaya, no tienes espacio en ningún\n"
	.string "sitio. LOOOOOOOOOOOL.$"
	
MicoloLeague_FinalRoom_Micolo_Text_ReceivedMon: @ 82706E8
	.string "¡{PLAYER} recibió un DARK PIKA\n"
	.string "especial de MICOLO!$"

MicoloLeague_FinalRoom_Micolo_Defeat_Text_1:
	.string "¡Superaste la MICOLIGA, el mayor\n"
	.string "desafío de todos los tiempos!\p"

	.string "Y para que conste tu victoria,\n"
	.string "todos los POKéMON de tu equipo serán\l"
	.string "galardonados con 7 RIBBONS especiales\l"
	.string "que darán fe de que habeis superado\l"
	.string "todos los Desafíos de la MICOLIGA.\p"
	
	.string "¡Enhorabuena {PLAYER} n.n!$"

MicoloLeague_FinalRoom_Micolo_Defeat_Text_2:
	.string "Eh, no creas que hayas ganado por ser\n"
	.string "bueno, a Shadow Pikachu no le apetecía\l"
	.string "luchar como sabe tras haber visto\l"
	.string "todos tus combates, le hubiera dado\l"
	.string "lástima humillar a un entrenador al que\l"
	.string "respeta, como es tu caso.\p"
	
	.string "Bueno, {PLAYER}, espero que nos\n"
	.string "volvamos a ver, ¡hasta entonces!$"
