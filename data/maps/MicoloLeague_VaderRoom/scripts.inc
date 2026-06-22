MicoloLeague_VaderRoom_MapScripts::
	.byte 0

MicoloLeague_VaderRoom_EventScript_Mew::
    lock
    faceplayer 
    waitse
    playmoncry SPECIES_MEW, 0
    msgbox MicoloLeagueLobby_Text_Mew, MSGBOX_DEFAULT
    waitmoncry
    release
    end

MicoloLeagueLobby_Text_Mew:
    .string "MEW: Meeew...$"

MicoloLeague_VaderRoom_EventScript_Vader::
	lockall
    faceplayer
	checktrainerflag TRAINER_AVADER_MICOLANDIA
	goto_if 1, MicoloLeague_VaderRoom_EventScript_Vader_2
	speakername CommonName_Text_a_vader
	msgbox MicoloLeague_VaderRoom_EventScript_Vader_Text_1, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_AVADER_MICOLANDIA, MicoloLeague_VaderRoom_EventScript_Vader_Text_2
	setflag FLAG_TEMP_1
    removeobject 10
    removeobject 11
MicoloLeague_VaderRoom_EventScript_Vader_1:
	releaseall
	return

MicoloLeague_VaderRoom_EventScript_Vader_2:
	speakername CommonName_Text_a_vader
	msgbox MicoloLeague_VaderRoom_EventScript_Vader_Text_0, MSGBOX_DEFAULT
	goto MicoloLeague_VaderRoom_EventScript_Vader_1


MicoloLeague_VaderRoom_EventScript_Vader_Text_0:
    .string "Vaya, pensaba derrotarte y que MICOLO\n"
	.string "me aumentara el sueldo. Digo...Sí, eso\l"
	.string "es, todo según mi plan como te he dicho.\p"
	.string "Ahora debes decidir {PLAYER}, does\n"
	.string "this world belong to MICOLO? Or does it\l"
	.string "belong to you?$"

MicoloLeague_VaderRoom_EventScript_Vader_Text_1:
	.string "¡Me encontraste, al hablar conmigo me\n"
	.string "has liberado de mi autismo!\p"
	.string "Eres tú, niño de los regis... Espero que\n"
	.string "me hayas dejado para el final, jeje.\p"
	.string "Yo te he guiado hasta aquí, desde que\n"
	.string "nos conocimos en la ROUTE 103...\p"
	.string "No, puede que desde antes. Todo es\n"
	.string "parte de mi plan.\p"
	.string "Según mis cálculos, si eres capaz de\n"
	.string "derrotar al alto mico, significará que\l"
	.string "estarás al nivel del gran rey MICOLO. Sí,\l"
	.string "debes derrotarlo por mí, yo no puedo\l"
	.string "hacerlo porque me robó el alma. Y\l"
	.string "cuando lo derrotes...\p"
	.string "No sé, cómprate el DLC para saberlo\n"
	.string "loooooool$"

MicoloLeague_VaderRoom_EventScript_Vader_Text_2:
    .string "How? t-the power of an autist cannot\n"
	.string "be overcome! All that I am is fading. It\l"
	.string "is vanishing.$" 
