Micolandia_Temple_of_Time2_MapScripts::
	.byte 0

TempleTime_EventScript_EnterRoom6::
	closemessage
	delay 30
	warp MAP_MICOLANDIA_TEMPLE_OF_TIME, 5, 0, 0
	waitstate
	releaseall
	end
	
TempleTime_EventScript_Soothebell::
	giveitem ITEM_SOOTHE_BELL, 1
	compare VAR_RESULT, FALSE
	call_if_eq TempleTime_BagFull
	closemessage
	removeobject 10
	setflag FLAG_ITEM_TempleTime_SOOTHEBELL
	end
	
TempleTime2_EventScript_Anciana::
	msgbox TempleTime2_Text_Anciana, MSGBOX_NPC
	end
	
TempleTime2_Text_Anciana:
	.string "Hace unos meses vino un chaval\n"
	.string "con gorra bastante extraño.\p"
	.string "Dijo que quería convertir nuestro\n"
	.string "templo en un quinto gymnasio\l"
	.string "o algo parecido.\p"
	.string "Incluso nos ofreció dinero para ello,\n"
	.string "pero nos negamos rotundamente.\l"
	.string "Eso perturbaría nuestra paz\l"
	.string "espiritual.$"
