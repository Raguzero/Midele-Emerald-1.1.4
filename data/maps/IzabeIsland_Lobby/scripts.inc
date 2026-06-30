IzabeIsland_Lobby_MapScripts::
	.byte 0

IzabeIsland_Lobby_EventScript_Receptionist::
	msgbox IzabeIsland_Lobby_Text_Receptionist, MSGBOX_NPC
	end
	
IzabeIsland_Lobby_EventScript_OldMan::
	msgbox IzabeIsland_Lobby_Text_OldMan, MSGBOX_NPC
	end
	
IzabeIsland_Lobby_EventScript_IceSample::
	msgbox IzabeIsland_Lobby_Text_IceSample, MSGBOX_SIGN
	end
	
IzabeIsland_Lobby_Text_Receptionist::
	.string "IZABE se enorgullece de estar a la\n"
	.string "última en investigación marina y naval.\p"
	.string "Trabajamos junto a los ASTILLEROS y el\n"
	.string "MUSEO OCEÁNICO de SLATEPORT CITY.$"

IzabeIsland_Lobby_Text_OldMan::
	.string "Uf... el camino a la ciudad es más largo\n"
	.string "de lo que parece. Creo que me tomaré un\l"
	.string "descanso.$"

IzabeIsland_Lobby_Text_IceSample::
	.string "Es una muestra de hielo obtenida en las\n"
	.string "montañas de la isla.\p"
	.string "“Muestra de hielo obtenida en la CUEVA\n"
	.string "de la montaña, a las afueras de la isla.\l"
	.string "Analizando su estructura, parece que\l"
	.string "este hielo requiere una temperatura\p"
	.string "superior a la normal para ser derretido.”$"
