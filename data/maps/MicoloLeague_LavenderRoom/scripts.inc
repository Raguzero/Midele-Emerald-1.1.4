MicoloLeague_LavenderRoom_MapScripts::
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MicoloLeague_LavenderRoom_OnWarp
    map_script MAP_SCRIPT_ON_RESUME, MicoloLeague_LavenderRoom_OnResume
	.byte 0

MicoloLeague_LavenderRoom_OnResume:
    compare VAR_TEMP_1, 1

   call_if_eq MicoloLeague_LavenderRoom_AddAudience
   end

MicoloLeague_LavenderRoom_OnWarp:
    map_script_2 VAR_TEMP_0, 0, MicoloLeague_LavenderRoom_AddAudience
    .2byte 0

MicoloLeague_LavenderRoom_AddAudience::
	createvobject EVENT_OBJ_GFX_DRAKE, 9, 1, 5, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_PHOEBE, 10, 3, 6, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_CYNDAQUIL_DOLL, 4, 4, 5, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_LINK_RS_BRENDAN, 5, 5, 5, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_TATE, 14, 7, 6, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_LIZA, 15, 8, 6, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_FAT_MAN, 8, 8, 4, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_LITTLE_GIRL, 11, 10, 6, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_MEW, 6, 11, 4, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_SCIENTIST_1, 7, 12, 5, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_MAXIE, 12, 14, 6, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_ARCHIE, 13, 15, 5, 3, DIR_SOUTH
	return


MicoloLeague_LavenderRoom_AudienceCheer::
	playse SE_W227B
	turnvobject 9, DIR_EAST
	turnvobject 10, DIR_EAST
	turnvobject 5, DIR_EAST
	turnvobject 14, DIR_WEST
	turnvobject 15, DIR_WEST
	turnvobject 8, DIR_WEST
	turnvobject 11, DIR_WEST
	turnvobject 6, DIR_EAST
	turnvobject 7, DIR_EAST
	turnvobject 12, DIR_EAST
	turnvobject 13, DIR_EAST
	delay 20
	turnvobject 9, DIR_SOUTH
	turnvobject 10, DIR_SOUTH
	turnvobject 5, DIR_SOUTH
	turnvobject 14, DIR_SOUTH
	turnvobject 15, DIR_SOUTH
	turnvobject 8, DIR_SOUTH
	turnvobject 11, DIR_SOUTH
	turnvobject 6, DIR_SOUTH
	turnvobject 7, DIR_SOUTH
	turnvobject 12, DIR_SOUTH
	turnvobject 13, DIR_SOUTH
	delay 20
	turnvobject 9, DIR_WEST
	turnvobject 10, DIR_WEST
	turnvobject 5, DIR_WEST
	turnvobject 14, DIR_EAST
	turnvobject 15, DIR_EAST
	turnvobject 8, DIR_EAST
	turnvobject 11, DIR_EAST
	turnvobject 6, DIR_WEST
	turnvobject 7, DIR_WEST
	turnvobject 12, DIR_WEST
	turnvobject 13, DIR_WEST
	delay 20
	turnvobject 9, DIR_SOUTH
	turnvobject 10, DIR_SOUTH
	turnvobject 5, DIR_SOUTH
	turnvobject 14, DIR_SOUTH
	turnvobject 15, DIR_SOUTH
	turnvobject 8, DIR_SOUTH
	turnvobject 11, DIR_SOUTH
	turnvobject 6, DIR_SOUTH
	turnvobject 7, DIR_SOUTH
	turnvobject 12, DIR_SOUTH
	turnvobject 13, DIR_SOUTH
	waitmovement 0
	return


MicoloLeague_LavenderRoom_Recepcionist::
	lock
	faceplayer 
	checktrainerflag TRAINER_LAVENDER_MICOLANDIA
	goto_if 1, MicoloLeague_LavenderRoom_Recepcionist_2
	msgbox MicoloLeague_LavenderRoom_Recepcionist_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MicoloLeague_LavenderRoom_Recepcionist_5
	msgbox MicoloLeague_LavenderRoom_Recepcionist_Text_2, MSGBOX_DEFAULT
MicoloLeague_LavenderRoom_Recepcionist_1:
	release
	return

MicoloLeague_LavenderRoom_Recepcionist_2:
	msgbox MicoloLeague_LavenderRoom_Recepcionist_Text_0, MSGBOX_NPC
	goto MicoloLeague_LavenderRoom_Recepcionist_1

MicoloLeague_LavenderRoom_Recepcionist_5:
	closemessage
	goto MicoloLeague_LavenderRoom_FightLavender
	goto MicoloLeague_LavenderRoom_Recepcionist_1


MicoloLeague_LavenderRoom_FightLavender::
	applymovement 2, MicoloLeague_LavenderRoom_Movement_Recepcionist
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, MicoloLeague_LavenderRoom_Movement_PlayerEnters
	waitmovement 0
	msgbox MicoloLeague_LavenderRoom_FightLavender_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	call MicoloLeague_LavenderRoom_AudienceCheer
	applymovement EVENT_OBJ_ID_PLAYER, MicoloLeague_LavenderRoom_Movement_PlayerGoRing
	waitmovement 0
	applymovement 3, Common_Movement_FaceRight
	waitmovement 0
	msgbox MicoloLeague_LavenderRoom_FightLavender_Text_1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	call MicoloLeague_LavenderRoom_AudienceCheer
	applymovement 1, MicoloLeague_LavenderRoom_Movement_LavenderGoRing
	waitmovement 0
	call MicoloLeague_LavenderRoom_AudienceCheer
    setvar VAR_TEMP_1, 1
	trainerbattle_single TRAINER_LAVENDER_MICOLANDIA, MicoloLeague_LavenderRoom_FightLavender_Text_2, MicoloLeague_LavenderRoom_FightLavender_Text_3, MicoloLeague_LavenderRoom_DefeatedLavender, FALSE
	return


MicoloLeague_LavenderRoom_DefeatedLavender::
	call MicoloLeague_LavenderRoom_AudienceCheer
	msgbox MicoloLeague_LavenderRoom_DefeatedLavender_Text_0, MSGBOX_NPC
	applymovement 1, MicoloLeague_LavenderRoom_Movement_LavenderGoesBack
	waitmovement 0
	setobjectxyperm 2, 3, 15
	release
	return


MicoloLeague_LavenderRoom_Reporter::
	lock
	faceplayer
	msgbox MicoloLeague_LavenderRoom_Reporter_Text_0, MSGBOX_NPC
	release
	return


MicoloLeague_LavenderRoom_Lavender::
	lock
	faceplayer
	speakername CommonName_Text_Lavender
	msgbox MicoloLeague_LavenderRoom_DefeatedLavender_Text_0, MSGBOX_NPC
	release
	return


MicoloLeague_LavenderRoom_Movement_Recepcionist:
	face_right
	lock_facing_direction
	walk_left
	step_end

MicoloLeague_LavenderRoom_Movement_PlayerEnters:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MicoloLeague_LavenderRoom_Movement_PlayerGoRing:
	walk_right
	walk_right
	step_end

MicoloLeague_LavenderRoom_Movement_LavenderGoRing:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

MicoloLeague_LavenderRoom_Movement_LavenderGoesBack:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

MicoloLeague_LavenderRoom_Recepcionist_Text_0:
	.string "Felicidades por tu victoria. ¿La salida?\n"
	.string "Está en la puerta del noreste, al lado\l"
	.string "de las gradas.$"

MicoloLeague_LavenderRoom_Recepcionist_Text_1:
    .string "Te doy la bienvenida... aquí podrás\n"
	.string "enfrentarte a uno de los miembros del\l"
	.string "ALTO MANDO. ¿A quién? Eso deberás\l"
	.string "averiguarlo por tu cuenta, pero te\l"
	.string "aseguro que el combate no será fácil...\p"
	.string "¿Tienes todo preparado para el\n"
	.string "combate?$"

MicoloLeague_LavenderRoom_Recepcionist_Text_2:
	.string "Cuando esté todo listo habla conmigo.\n"
	.string "Tienes todo el tiempo del mundo...$"

MicoloLeague_LavenderRoom_FightLavender_Text_0:
	.string "Señores y señoras, damas y caballeros,\n"
	.string "niños y niñas... ¡una vez más, seremos\l"
	.string "presentes de un apasionante combate\l"
	.string "de la MICOLIGA!\p"
	.string "Hoy, tenemos con nosotros a la persona\n"
	.string "que derrotó al CAMPEÓN de HOENN y se\l"
	.string "hizo con el título, a la persona que\l"
	.string "logró desbaratar los planes del EQUIPO\l"
	.string "AQUA y MAGMA, a la persona que\l"
	.string "consiguió vencer en los cuatro\l"
	.string "MICOGIMNASIOS... les presento...\p"
	.string "¡a {PLAYER}!$"

MicoloLeague_LavenderRoom_FightLavender_Text_1:
	.string "Y por otra parte tenemos a nuestro\n"
	.string "favorito invicto, una de las mentes que\l"
	.string "ayudó en la construcción de la\l"
	.string "mismísima MICOLIGA, el entrenador por\l"
	.string "el que todos estáis aquí...\p"
	.string "¡Dejémonos de misterios y que aparezca\n"
	.string "de una vez!\p"
	.string "¡Con vosotros... LAVENDER!$"

MicoloLeague_LavenderRoom_FightLavender_Text_2:
	.string "Hola, ¿me recuerdas? Nos vimos en\n"
	.string "IZABE ISLAND. En cuanto te vi, supe que\l"
	.string "serías capaz de llegar hasta aquí...\p"
	.string "Nah, en realidad no. Solo era un diálogo\n"
	.string "para hacerme el interesante. Ya sabes.\p"
	.string "Sea como sea, te agradezco que hayas\n"
	.string "llegado hasta aquí. Probablemente\l"
	.string "haya habido momentos en los que has\l"
	.string "querido dejarlo, abandonar. Momentos\l"
	.string "en los que has pensado “Puto Midele, es\l"
	.string "demasiado difícil. Qué pereza farmear”.\l"
	.string "Pero conseguiste darlo todo, superar\l"
	.string "todos los retos y adversidades, y\l"
	.string "llegaste aquí.\p"
	.string "O igual no. Tal vez usaste hacks. Quién\n"
	.string "sabe.\p"
	.string "De todas formas, me gustaría luchar\n"
	.string "contra ti. Quizás mi combate te resulte\l"
	.string "muy sencillo. Quizás se te haga\l"
	.string "complicado y tengas que probar varias\l"
	.string "veces hasta que me derrotes. Pero no\l"
	.string "te rindas. Ya estás ahí, a punto de\l"
	.string "llegar al final. A punto de coronarte\l"
	.string "como el CAMPEÓN de la MICOLIGA.\p"
	.string "Por ti, por tus POKéMON y por todas las\n"
	.string "personas con las que te has\l"
	.string "encontrado para llegar hasta aquí...\l"
	.string "esfuérzate al máximo.\p"
	.string "Vamos, {PLAYER} ¡Es hora de combatir!$"

MicoloLeague_LavenderRoom_FightLavender_Text_3:
	.string "¿He perdido otra vez? Como diría GARM:\n"
	.string "pues oc.$"

MicoloLeague_LavenderRoom_DefeatedLavender_Text_0:
 	.string "LAVENDER: Has ganado... la verdad es que\n"
	.string "estoy satisfecho. No sé cuántos\l"
	.string "miembros de ALTO MANDO te quedan por\l"
	.string "derrotar. Puede que yo haya sido el\l"
	.string "primero, o puede que haya sido el\l"
	.string "último... pero es un hecho que he\l"
	.string "perdido.\p"
	.string "Ánimo, ya estás casi al final. Puedes\n"
	.string "continuar.$"

MicoloLeague_LavenderRoom_Reporter_Text_0:
	.string "¡Un combate nunca visto! ¡Has vencido!\n"
	.string "¡En todos mis años como presentador\l"
	.string "nunca había visto nada igual!$"

CommonName_Text_Lavender:
	.string "LAVENDER$"
