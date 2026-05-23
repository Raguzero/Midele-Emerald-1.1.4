GymSanty2_MapScripts::
    map_script MAP_SCRIPT_ON_RESUME, GymSanty2_OnResume
	map_script MAP_SCRIPT_ON_LOAD, GymSanty2_OnLoad
    .byte 0
	
GymSanty2_OnLoad:
	compare VAR_FUEGO_GYM_SANTY, 0
	goto_if_eq GymSanty2_Script_Close
	compare VAR_FUEGO_GYM_SANTY, 1
	goto_if_eq GymSanty2_Script_Close
	compare VAR_FUEGO_GYM_SANTY, 2
	goto_if_eq GymSanty2_Script_Close
	compare VAR_FUEGO_GYM_SANTY, 3
	goto_if_eq GymSanty2_Script_Close
	end

GymSanty2_OnResume:
    setstepcallback STEP_CB_ASH
    end
	
GymSanty2_Script_Close::
	setmetatile 28, 11, 0x066, 1
	return

GymSanty2_EventScript_Sign::
	msgbox GymSanty2_Text_Sign, MSGBOX_SIGN
	end
	
GymSanty2_EventScript_Farol1::
	lock
	faceplayer
	goto_if_set FLAG_FAROL1_GYM_SANTY, GymSanty2_EventScript_FarolEncendida2
	msgbox GymSanty2_Text_EncenderFarol, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymSanty2_EventScript_FarolEncendida
	release
	end
GymSanty2_EventScript_FarolEncendida:
	msgbox GymSanty2_Text_FarolEncendida, MSGBOX_DEFAULT
	addvar VAR_FUEGO_GYM_SANTY, 1
	setflag FLAG_FAROL1_GYM_SANTY
	removeobject 10
	addobject 14
	clearflag FLAG_HIDE_FIREON_1_GYM_SANTY
	compare VAR_FUEGO_GYM_SANTY, 4
	goto_if_eq GymSanty2_EventScript_FarolesEncendidos
	release
	end
	
GymSanty2_EventScript_Farol2::
	lock
	faceplayer
	goto_if_set FLAG_FAROL2_GYM_SANTY, GymSanty2_EventScript_FarolEncendida2
	msgbox GymSanty2_Text_EncenderFarol, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymSanty2_EventScript_Farol2Encendida
	release
	end
GymSanty2_EventScript_Farol2Encendida:
	msgbox GymSanty2_Text_FarolEncendida, MSGBOX_DEFAULT
	addvar VAR_FUEGO_GYM_SANTY, 1
	setflag FLAG_FAROL2_GYM_SANTY
	removeobject 12
	addobject 16
	clearflag FLAG_HIDE_FIREON_2_GYM_SANTY
	compare VAR_FUEGO_GYM_SANTY, 4
	goto_if_eq GymSanty2_EventScript_FarolesEncendidos
	release
	end
	
GymSanty2_EventScript_Farol3::
	lock
	faceplayer
	goto_if_set FLAG_FAROL3_GYM_SANTY, GymSanty2_EventScript_FarolEncendida2
	msgbox GymSanty2_Text_EncenderFarol, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymSanty2_EventScript_Farol3Encendida
	release
	end
GymSanty2_EventScript_Farol3Encendida:
	msgbox GymSanty2_Text_FarolEncendida, MSGBOX_DEFAULT
	addvar VAR_FUEGO_GYM_SANTY, 1
	removeobject 11
	addobject 15
	clearflag FLAG_HIDE_FIREON_3_GYM_SANTY
	setflag FLAG_FAROL3_GYM_SANTY
	compare VAR_FUEGO_GYM_SANTY, 4
	goto_if_eq GymSanty2_EventScript_FarolesEncendidos
	release
	end
	
GymSanty2_EventScript_Farol4::
	lock
	faceplayer
	goto_if_set FLAG_FAROL4_GYM_SANTY, GymSanty2_EventScript_FarolEncendida2
	msgbox GymSanty2_Text_EncenderFarol, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymSanty2_EventScript_Farol4Encendida
	release
	end
GymSanty2_EventScript_Farol4Encendida:
	msgbox GymSanty2_Text_FarolEncendida, MSGBOX_DEFAULT
	addvar VAR_FUEGO_GYM_SANTY, 1
	removeobject 13
	addobject 17
	clearflag FLAG_HIDE_FIREON_4_GYM_SANTY
	setflag FLAG_FAROL4_GYM_SANTY
	compare VAR_FUEGO_GYM_SANTY, 4
	goto_if_eq GymSanty2_EventScript_FarolesEncendidos
	release
	end

GymSanty2_EventScript_FarolEncendida2:
	msgbox GymSanty2_Text_FarolEncendida2, MSGBOX_DEFAULT
	release
	end

GymSanty2_EventScript_FarolesEncendidos::
	setmetatile 28, 11, METATILE_General_Grass, 0
	special DrawWholeMapView
	msgbox GymSanty2_Text_CaminoAbierto, MSGBOX_SIGN
	releaseall
	end
	
    @ Combate contra totem.
GymSanty2_EventScript_Totem::
	lockall
	msgbox DesafiarTotem_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymSanty2_EventScript_Totem2
	releaseall
	end		

GymSanty2_EventScript_Totem2::
	playmoncry SPECIES_MEGA_CAMERUPT, 2
	delay 40
	waitmoncry
	msgbox GymSanty2_Text_Totemaparece, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_MEGA_CAMERUPT
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
	removeobject 1
	setflag FLAG_TOTEM_GYMSANTY
    msgbox GymSanty2_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.	
	
GymSanty2_EventScript_Entropia::
	trainerbattle_single TRAINER_ENTROPIA, Entropia_AntesBatalla, Entropia_MensajeDerrota
	msgbox Entropia_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
GymSanty2_EventScript_RedKrow::
	trainerbattle_single TRAINER_RED_KROW, RedKrow_AntesBatalla, RedKrow_MensajeDerrota
	msgbox RedKrow_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
GymSanty2_EventScript_Vin::
	trainerbattle_single TRAINER_VIN, Vin_AntesBatalla, Vin_MensajeDerrota
	msgbox Vin_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
GymSanty2_EventScript_Ghaddar::
	trainerbattle_single TRAINER_GHADDAR_2, Ghaddar_AntesBatalla, Ghaddar_MensajeDerrota
	msgbox Ghaddar_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
GymSanty2_EventScript_Felipex88::
	trainerbattle_double TRAINER_FELIPEX88, Felipex88_AntesBatalla, Felipex88_MensajeDerrota, Felipex88_Text_MasdeunPokemon
	msgbox Felipex88_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
GymSanty2_EventScript_Albermaus::
	trainerbattle_single TRAINER_ALBERMAUS, Albermaus_AntesBatalla, Albermaus_MensajeDerrota
	msgbox Albermaus_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
GymSanty2_EventScript_Krub2::
	trainerbattle_single TRAINER_KRUB_2, Krub2_AntesBatalla, Krub2_MensajeDerrota
	msgbox Krub2_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
GymSanty2_EventScript_Fenan::
	trainerbattle_single TRAINER_FENAN, Fenan_AntesBatalla, Fenan_MensajeDerrota
	msgbox Fenan_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
Albermaus_AntesBatalla: 
	.string "Tú no serás psicoanalísta,\n"
	.string "¿verdad?$"
	
Albermaus_MensajeDerrota: 
	.string "M-word$"
	
Albermaus_DespuesDeBatalla:
	.string "No sé cuál fue mi peor decisión:\n"
	.string "empezar a prepararme el PIR\l" 
	.string "o moderar PxP.$"
	
Entropia_AntesBatalla: 
	.string "Amore, ¿sabías que estamos en la\n"
    .string "piscis season?\p"

    .string "El amor está en el aire, las feromon...\p"

    .string "¿Cómo? ¿No crees en el horóscopo?\p"

    .string "¡No puedes decirme eso y quedarte\n"
    .string "tan tranquilo!\p"

    .string "Eso va a cambiar cuando te patée el culo\n"
	.string "Hm.$"
	
Entropia_MensajeDerrota: 
	.string "Paso.$"
	
Entropia_DespuesDeBatalla:
	.string "¿Es así como te han enseñado\n"
	.string "a tratar a las brujas?\p"

	.string "Anyways, so... Si hay algo que te\n"
	.string "inquieta, te atormenta o te\l"
	.string "perturba, siempre puedes volver\l"
	.string "aquí y te diré lo que los astro te\l"
	.string "deparan...\p"

	.string "O puede hablar con un tal Alpha\n"
	.string "que seguramente esté por algún\l"
	.string "lugar de aquí fagoteando.\l"
	.string "¡Besis de fresi!$"
	
RedKrow_AntesBatalla: 
    .string "No hace falta que digas nada,\n"
    .string "solo con verte ya estoy entrando\l"
    .string "en calor.\p"
	
	.string "Federico, prepárate que vamos\n" 
	.string "a erupcionar.$"
	
RedKrow_MensajeDerrota: 
    .string "¡Por favor, no me pegues!\n"
    .string "...\l"
    .string "...\p"
    .string "O bueno, si quieres pégame.\n"
    .string "...\l"
    .string "...\p"
    .string "¿No? Oh.\n"
    .string "¿Y si te pagara me pegarías?$"
	
RedKrow_DespuesDeBatalla:
    .string "Si quieres que repitamos, creéme, por mí\n"
    .string "encantado, pero deja por lo menos que\l"
    .string "vaya a limpiarme la cara primero.$"
	
Vin_AntesBatalla: 
	.string "¡Volar es la mejor forma de\n"
	.string "liberar el espíritu!\p"

    .string "Desde pequeña he querido siempre\n"
    .string "llegar hasta las nubes.\p"

    .string "Todos los viajes por los aires\n"
    .string "que he realizado con mis POKéMON\l"
    .string "nos han dado un vínculo\l"
    .string "inquebrantable.\p"

    .string "¡Pongámoslo a prueba con una\n"
    .string "batalla!$"
	
Vin_MensajeDerrota: 
	.string "Aterrizados antes de tiempo...$"
	
Vin_DespuesDeBatalla:
	.string "¡Gracias por tan buena batalla!\p"

	.string "Gane o pierda, una batalla POKéMON\n"
    .string "en los aires siempre me hace sentir\l"
     .string "mucho más feliz.$"
	 
Ghaddar_AntesBatalla: 
	.string "SNIFF SNIFF\n"
	.string "Huelo...A alguien...\l"
	.string "¡¡A ALGUIEN QUE JUEGA GACHAS!!$"
	
Ghaddar_MensajeDerrota: 
	.string "Los Gachas... Han ganado...\n"
	.string "Sword&Shield... POKéMON Go...\p"

	.string "Es el futuro que nos espera...$"
	
Ghaddar_DespuesDeBatalla:
	.string "Está claro que has pagado extra\n"
	.string "para tener esos POKéMON.\p"

	.string "Mis POKéMON han sido entrenados\n"
	.string "con CARIÑO y ESFUERZO.\p"

	.string "Nada de EVs ni IVs ni tonterías.\n"
	.string "Puro AMOR.\p"

	.string "¡HACHA AL GACHA!$"

Felipex88_AntesBatalla: 
	.string "Hola, soy Felipex88, y me gusta hacer\n"
	.string "cachitos mi lengua.\p"

	.string "Los mexicanos en si son feos, chicos\n"
	.string "y negros, más aún los k juegan pokemon,\l" 
	.string "no salva ninguno pu viejo, e visto fotos\l" 
	.string "y son todos unos troles, llegan a dar\l" 
	.string "miedo y pena, para lo único k sirven es\l" 
	.string "para sentarse a jugar mierdas\l"
	.string "como estas.\p"
	
	.string "Los de este foro tampoco se salvan,\n" 
	.string "dan pena ver que siempre están\l"
	.string "introducidos en el mundo virtual\l"
	.string "desperdiciando sus jóvenes vidas.\p"
	
	.string "Empezando por las mujeres y terminando\n" 
	.string "por el mas feo del foro del k hay k\l" 
	.string "estar eligiendo con pinzas cual es el\l"
	.string "mas ogro, da pena meterse al foro a\l" 
	.string "preguntar algo y que te respondan los\l" 
	.string "mismos sin vida de siempre, de verdad\l" 
	.string "es penosa la situación y el idiota k\l"
	.string "cree sentirse de acero jugando a un\l" 
	.string "juego random donde el 70% es pura\l" 
	.string "suerte entre criticals, fallidas, y\l" 
	.string "evasiones y solo el 30 de forma\l"
	.string "normal, esta mas que perdido.$"

Felipex88_MensajeDerrota: 
	.string "¡Hora de cortarse la lengua!\n"
	.string ":video: :video:\l"
	.string "ghhghfghgghghghggh$"
 
Felipex88_DespuesDeBatalla:
	.string "Comog podeig gegui guando a gesta wea.\p"

	.string "Soig gunos fragasagos, salig a gugar\n" 
	.string "a gosas mas agultas con viogentas\l"
	.string "y sangggre... muga sangggreee ghghghgh\p"
	
	.string "¡GHAMA A GUNA GAMBUGANCIA!$"
	
Felipex88_Text_MasdeunPokemon: // BATALLA DOBLE
	.string "¿Así que solo llevas un POKéMON?\p"
	.string "Prefiero cortarme la lengua que usar\n"
	.string "mi equipo en BATALLA INDIVIDUAL.$"	
	
Krub2_AntesBatalla: 
    .string "¿Puedes dejarme 20 EUROS?$"
	
Krub2_MensajeDerrota: 
    .string ":sad: Perdí, tendría que haber\n"
    .string "mirado más bulbapedia.$"
	
Krub2_DespuesDeBatalla:
    .string "Te tengo que decir y dar algo útil.\n"
	
	.string "...\p"
	
	.string "...\p"
	
	.string "...\p"

    .string "Nah, estaba troleando.$"
	
Fenan_AntesBatalla: 
	.string "los k usan pokesav son unos mamones\n"
	.string "amargaos k no kieren jugar vien y eso\l"
	.string "es de jilipollas y si no :nenemalo:\l"
	.string ":nenemalo: :nenemalo: :nenemalo:\l"
	.string ":nenemalo: :nenemalo: :nenemalo:\l"
	.string ":nenemalo: :nenemalo: :nenemalo:\l"
	.string ":nenemalo: :nenemalo:\p"
	
	.string "edit:tambien se le jode el juego\n" 
	.string "por usarlo$"
	
Fenan_MensajeDerrota: 
	.string "por lo k llo domino una enfermedad de mi\n"
	.string "familia jilipollitis aguditis xD xD$"
	
Fenan_DespuesDeBatalla:
	.string "...\p"
	
	.string "...\p"
	
	.string "...\p"

	.string "k me as dicho ijo puta k es traampa y\n"
	.string "callarse lla cerrar el tema y si te pillo\l"
	.string "por la calle ijo puta t mato nadie me\l"
	.string "insulta a mi padre si k es un jilipollas$"

GymSanty2_Text_Sign:
	.string "ENCIENDE LAS CUATRO ANTORCHAS\n"
	.string "Y EL CAMINO SE ABRIRÁ$"
	
GymSanty2_Text_EncenderFarol:
	.string "¿Quieres encender la antorcha?$"
	
GymSanty2_Text_FarolEncendida:
	.string "Has encendido la antorcha.$"
	
GymSanty2_Text_FarolEncendida2:
	.string "El fuego arde de forma intensa.$"

GymSanty2_Text_CaminoAbierto:
	.string "Has encendido las cuatro antorchas.\n"
	.string "Todas arden con gran intensidad.\p"

	.string "El camino hacia la siguiente sala\n"
	.string "ha sido desbloqueado.$"
	
GymSanty2_Text_Totemaparece:
	.string "M-CAMERUPT, the TOTEM POKéMON of\n"
	.string "SANTYGRASS GYM, has appeared!$"
	
GymSanty2_Text_Totemderrotado:
	.string "M-CAMERUPT disappeared...$"
