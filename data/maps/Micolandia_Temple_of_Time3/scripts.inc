Micolandia_Temple_of_Time3_MapScripts::
	.byte 0
	
Micolandia_Temple_of_Time3_Kirlia_Script::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KIRLIA, 0
	waitmoncry
	release
	end
	
Micolandia_Temple_of_Time3_Dueno_de_Kirlia_Script::
	lock
	faceplayer
	msgbox Micolandia_Temple_of_Time3_Dueno_de_Kirlia_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Micolandia_Temple_of_Time3_Dueno_de_Kirlia_Teleport
	release
	end
Micolandia_Temple_of_Time3_Dueno_de_Kirlia_Teleport::
	warp MAP_MICOLANDIA, 1, 0, 0
	waitstate
	release
	end
	
Micolandia_Temple_of_Time3_Viajera_Script::
	lockall
	faceplayer
	goto_if_set FLAG_FORBIDDEN_FOREST_CELEBI_ENTRANCE, Micolandia_Temple_of_Time3_Viajera_Script2
	msgbox Micolandia_Temple_of_Time3_Viajera_Text, MSGBOX_NPC
	closemessage
	releaseall
	end
	
Micolandia_Temple_of_Time3_Viajera_Script2::
	goto_if_set FLAG_CAUGHT_CELEBI, Micolandia_Temple_of_Time3_Viajera_Script3
	msgbox Micolandia_Temple_of_Time3_Viajera_Text2, MSGBOX_NPC
	closemessage
	releaseall
	end
	
Micolandia_Temple_of_Time3_Viajera_Script3::
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	delay 80
	msgbox Micolandia_Temple_of_Time3_Viajera_Text3, MSGBOX_NPC
	closemessage
	releaseall
	end
	
Micolandia_Temple_of_Time3_EventScript_Santygrass::
	lockall
	msgbox Micolandia_Temple_of_Time3_Text_Santygrass_TalkToHimself, MSGBOX_DEFAULT
	faceplayer
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Micolandia_Temple_of_Time3_Text_Santygrass_Talks, MSGBOX_NPC
	setflag FLAG_COMPLETE_FORBIDDEN_FOREST
	applymovement 4, Micolandia_Temple_of_Time3_Movement_SantygrassSpin
	waitmovement 0
	playse SE_W100
	applymovement 4, Micolandia_Temple_of_Time3_Movement_SantygrassJumpaway
	waitmovement 0
	removeobject 4
	@ Level Cap Item
	delay 30
	playse SE_PIN
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	playfanfare MUS_ME_B_SMALL
	delay 30
	msgbox Micolandia_Temple_of_Time3_LevelCap_Text, MSGBOX_DEFAULT
	closemessage
	@ Level Cap Item
	delay 30
	releaseall
	end
	
Micolandia_Temple_of_Time3_Movement_SantygrassSpin:
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	step_end

Micolandia_Temple_of_Time3_Movement_SantygrassJumpaway:
	face_up
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end
	
Micolandia_Temple_of_Time3_EventScript_Celebi_Sign::
	lockall
	braillemessage OldaleRuins_Braille_CelebiPuzzle	
	waitbuttonpress
	closebraillemessage	
	specialvar VAR_RESULT, CheckJirachiMewinTeam
	compare VAR_RESULT, TRUE
	goto_if_eq Micolandia_Temple_of_Time3_EventScript_Celebi_Sign2
	end

Micolandia_Temple_of_Time3_EventScript_Celebi_Sign2::
	waitse
	playmoncry SPECIES_MEW, 2
	delay 40
	waitmoncry
	waitse
	playmoncry SPECIES_JIRACHI, 2
	delay 40
	waitmoncry
	goto_if_set FLAG_FORBIDDEN_FOREST_CELEBI_ENTRANCE, Micolandia_Temple_of_Time3_EventScript_Celebi_Sign3
	msgbox Micolandia_Temple_of_Time3_Text_Celebi2, MSGBOX_SIGN
	closemessage
	setflag FLAG_FORBIDDEN_FOREST_CELEBI_ENTRANCE
	delay 30
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	delay 80
	warp MAP_CELEBI_ROOM, 0, 0, 0
	waitstate
	releaseall
	end
	
Micolandia_Temple_of_Time3_EventScript_Celebi_Sign3::
	delay 30
	warp MAP_CELEBI_ROOM, 0, 0, 0
	waitstate
	releaseall
	end
	
Micolandia_Temple_of_Time3_Text_Celebi2:
	.string "EL CAMINO SE HA ABIERTO\n"
	.string "EL VIAJERO DEL TIEMPO QUIERE VERTE$"
	
Micolandia_Temple_of_Time3_Dueno_de_Kirlia_Text:
	.string "Mi KIRLIA puede usar la técnica del\n"
	.string "TELEPORT para enviarte a la zona\l"
	.string "principal de MICOLANDIA.\p"
	
	.string "¿Quieres que te lleve hacia allí?$"
	
Micolandia_Temple_of_Time3_Viajera_Text:
	.string "En mis años de belleza pura tuve\n"
	.string "una experiencia que nunca olvidaré.\p"
	
	.string "Mientras rezaba ante este pedestal\n"
	.string "dorado, de repente, viajé en el tiempo\l"
	.string "hacia el futuro.\p"
	
	.string "Asombroso, ¿verdad?\p"
	
	.string "¿Pero sabes que es lo que vi?\p"
	.string "Pues a ti molestándome. ¡Maldita sea!\n"
	.string "Con lo tranquila que estaba aquí\l"
	.string "rezando y tuviste que interrumpirme.\p"
	
	.string "Me tienen harta todos los gamberros\n"
	.string "que llegan hasta aquí a preguntarme\l"
	.string "donde está CELEBI.$"
	
Micolandia_Temple_of_Time3_Viajera_Text2:
	.string "¿Qué es lo que ha pasado?\n"
	.string "¿Adónde has ido?\l"
	.string "¿De dónde has salido?\l"
	.string "¿Habías usado un ESCAPE ROPE?\p"
	
	.string "En fin, seguiré rezando a CELEBI,\n"
	.string "espero que no me molestes más con\l"
	.string "tus tonterias.$"
	
Micolandia_Temple_of_Time3_Viajera_Text3:
	.string "Espera un momento, ¡has encontrado\n"
	.string "a CELEBI!\p"

	.string "Así que la leyenda era cierta...\n"
	.string "Te había juzgado mal.\p"
	
	.string "Si el mismo CELEBI te ha elegido,\n"
	.string "no tendré ningún inconveniente.\p"
	
	.string "¡Pero la elegida por CELEBI debería\n"
	.string "haber sido yo, que para algo llevo\l"
	.string "rezándole toda mi vida!$"
	
Micolandia_Temple_of_Time3_Text_Santygrass_TalkToHimself:
	.string "Qué extraño es este bosque...\p"

	.string "Por mucho que lo intente quemar...\n"
	.string "¡las llamas se vuelven a apagar!\p"
	
	.string "Siento como si el mismísimo TIEMPO\n"
	.string "volviese hacia atrás cada vez que\l"
	.string "lo intento.\p"

	.string "¿Debe ser que el CELEBI de este mundo\n"
	.string "es el protector de este bosque?$"

Micolandia_Temple_of_Time3_Text_Santygrass_Talks:
	.string "¡Oh! ¡No me di cuenta de que estabas\n"
	.string "ahí!\p"

	.string "Así que eres {PLAYER} ¿eh?\n"
	.string "He oído cosas impresionantes de ti.\p"
	
	.string "Yo soy SANTYGRASS, uno de los cuatro\n"
	.string "líderes de GYM de MICOLANDIA.\l"
	.string "¿Me estabas buscando?\p"
	
	.string "Vine a este templo a investigar.\n"
	.string "Pero, chale, estos viejos de verdad que\l"
	.string "son unos cabezones y no quieren\l"
	.string "explicar nada.\p"
	
	.string "En fin, ya va tocando que vuelva a la\n"
	.string "chamba.\p"
	.string "Ahora mismo vuelvo a mi GIMNASIO para\n"
	.string "esperar tu desafío.\l"
	.string "¡No te lo pondré fácil!\p"

	.string "Y recuerda: ¡no hay nada mejor\n"
	.string "que el olor a hierba quemada!$"

Micolandia_Temple_of_Time3_LevelCap_Text:
	.string "LEVEL CAP: Actualización completada.\n"
	.string "El nuevo límite es el nivel 78.$"

