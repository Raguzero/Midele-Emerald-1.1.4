MicoloLeague_PacoRoom_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, MicoloLeague_PacoRoom_OnLoad
	.byte 0

MicoloLeague_PacoRoom_OnLoad::
    setflag FLAG_TEMP_3
    end

MicoloLeague_PacoRoom_Piba1::
	lock
	goto_if_unset FLAG_TEMP_1, MicoloLeague_PacoRoom_Piba1_2
	msgbox MicoloLeague_PacoRoom_Piba1_Text_1, MSGBOX_NPC
MicoloLeague_PacoRoom_Piba1_1:
	release
	return

MicoloLeague_PacoRoom_Piba1_2:
	msgbox MicoloLeague_PacoRoom_Piba1_Text_0, MSGBOX_NPC
	setflag FLAG_TEMP_1
	goto MicoloLeague_PacoRoom_Piba1_1


MicoloLeague_PacoRoom_Piba2::
	lock
	goto_if_unset FLAG_TEMP_2, MicoloLeague_PacoRoom_Piba2_2
	msgbox MicoloLeague_PacoRoom_Piba2_Text_0, MSGBOX_NPC
MicoloLeague_PacoRoom_Piba2_1:
	release
	return

MicoloLeague_PacoRoom_Piba2_2:
	msgbox MicoloLeague_PacoRoom_Piba1_Text_0, MSGBOX_NPC
	setflag FLAG_TEMP_2
	goto MicoloLeague_PacoRoom_Piba2_1


MicoloLeague_PacoRoom_HombreDeAsul::
	msgbox MicoloLeague_PacoRoom_HombreDeAsul_Text_0, MSGBOX_NPC
	return


MicoloLeague_PacoRoom_Candela::
	msgbox MicoloLeague_PacoRoom_Candela_Text_0, MSGBOX_NPC
	return


MicoloLeague_PacoRoom_CameraMan::
	msgbox MicoloLeague_PacoRoom_CameraMan_Text_0, MSGBOX_NPC
	return


MicoloLeague_PacoRoom_SnorlaxDoll::
	msgbox MicoloLeague_PacoRoom_SnorlaxDoll_Text_0, MSGBOX_NPC
	return


MicoloLeague_PacoRoom_CyndaDoll::
	msgbox MicoloLeague_PacoRoom_CyndaDoll_Text_0, MSGBOX_NPC
	return


MicoloLeague_PacoRoom_Latias::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_LATIAS, 0
	msgbox MicoloLeague_PacoRoom_Latias_Text_0, MSGBOX_DEFAULT
	waitmoncry
	release
	return


MicoloLeague_PacoRoom_Latios::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_LATIOS, 0
	msgbox MicoloLeague_PacoRoom_Latios_Text_0, MSGBOX_DEFAULT
	waitmoncry
	release
	return


MicoloLeague_PacoRoom_Suicune::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SUICUNE, 0
	msgbox MicoloLeague_PacoRoom_Suicune_Text_0, MSGBOX_DEFAULT
	waitmoncry
    warp MAP_MICOLO_LEAGUE_MAIN_ROOM, 0, 0, 0
    waitstate
	release
	return

MicoloLeague_PacoRoom_Paco::
	lockall
    faceplayer
	speakername CommonName_Text_Pacochef
	checktrainerflag TRAINER_PACOCHEF_MICOLANDIA
	goto_if 1, MicoloLeague_PacoRoom_Paco_2
	msgbox MicoloLeague_PacoRoom_Paco_Text_1, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PACOCHEF_MICOLANDIA, MicoloLeague_PacoRoom_Paco_Text_2
	clearflag FLAG_TEMP_3
MicoloLeague_PacoRoom_Paco_1:
	releaseall
	return

MicoloLeague_PacoRoom_Paco_2:
	msgbox MicoloLeague_PacoRoom_Paco_Text_0, MSGBOX_DEFAULT
	goto MicoloLeague_PacoRoom_Paco_1


MicoloLeague_PacoRoom_Paco_Text_0:
	.string "Aish… supongo que eso es todo, ¿no? Me\n"
	.string "lo he pasado de puta madre luchando\l"
	.string "contigo, not gonna lie. Sin duda eres\l"
	.string "capaz de partirle la cara a ese\l"
	.string "desgraciado y sus monociclos.\p"
	.string "Gracias por haber viajado por HOENN y\n"
	.string "enfrentarte a Midele.\p"
	.string "Ha sido un largo camino, hasta te puse\n"
	.string "unos alicientes caóticos, por si no\l"
	.string "fuera suficiente con las idas de olla\l"
	.string "que hay por aquí. Nunca lo olvides, un\l"
	.string "porro al día alegra la vida.\p"
	.string "Adelante: MICOLO te espera.$"

MicoloLeague_PacoRoom_Paco_Text_1:
	.string "¡Hostia neno! Cuánto tiempo, ¿eh?\p"
	.string "Al final conseguiste llegar hasta aquí.\n"
	.string "¿Cuándo fue la última vez que nos\l"
	.string "vimos? …da igual, putos petas. Te\l"
	.string "invitaría a uno, pero está claro que\l"
	.string "este no es el momento.\p"
	.string "Aish, qué lejos has llegado. Implacable\n"
	.string "ante los TOTEM, la liga de HOENN, y a\l"
	.string "un paso de MICOLO. Debería dejarte\l"
	.string "pasar sin más para que te enfrentes a\l"
	.string "él.\p"
	.string "Naaaah no mames wey, esto es POKéMON.\p"
	.string "He de admitir que no quiero ser un\n"
	.string "obstáculo para ti, pero neno, neeeeeno,\l"
	.string "debes saber una cosa. Tal vez sean las\l"
	.string "drogas que me ponen filosófico pero,\l"
	.string "¿te has parado a pensar en cuánta\l"
	.string "importancia le da la peña al sentido de\l"
	.string "la vida?\p"
	.string "No skipees esto anda, tiene su fondo de\n"
	.string "seriedad. Algunos creen que el sentido\l"
	.string "de la vida es amar. Otros, obtener\l"
	.string "conocimiento. Algún loco, reproducirse.\l"
	.string "Y así sucesivamente, cada uno expone\l"
	.string "sus motivos para vivir. No creo que\l"
	.string "haya un sentido de la vida. Tal vez cada\l"
	.string "uno tenga el suyo, ¿no? O simplemente\l"
	.string "hay muchos… quién sabe.\p"
	.string "¿Quieres saber qué me motiva a seguir\n"
	.string "adelante? ¿A tomar una decisión u\l"
	.string "otra? Fácil: la diversión. ¿Qué sería de\l"
	.string "esta vida sin las buenas risas?\p"
	.string "Por ello, aquí y ahora, te desafío a un\n"
	.string "combate con todas las de la no-ley.\l"
	.string "Todo vale. Disfrutemos, y prepárate\l"
	.string "para descojonarte. Quiero que lleves\l"
	.string "tu mejor sonrisa cuando le rajes la\l"
	.string "garganta a MICOLO.\p"
	.string "¡LET'S FUCKING GO!$"

MicoloLeague_PacoRoom_Paco_Text_2:
	.string "Me cago en san dios, no lo pasaba tan\n"
	.string "guay desde que apalicé a la papelera.$"

MicoloLeague_PacoRoom_Piba1_Text_0:
	.string "Te doy la bienvenida a la estancia\n"
	.string "de Paquito el chocolatero.\l"
	.string "Fumar está permitido.\l"
	.string "Tirarse por los pozos no, que limpiar\l"
	.string "cadáveres es asqueroso.$"

MicoloLeague_PacoRoom_Piba1_Text_1:
	.string "¿Qué? No tengo nada más que decir,\n"
	.string "largo, atontao.$"

MicoloLeague_PacoRoom_Piba2_Text_0:
	.string "Fuera, bicho, tira pa'lante.$"

MicoloLeague_PacoRoom_HombreDeAsul_Text_0:
	.string "¿Oh? Un amigo de PACO, ya veo. Soy uno\n"
	.string "de los alter-egos de ese autista,\l"
	.string "FRANCESCO. Me usa para hacer el payaso\l"
	.string "en roles. Podría apuñalarte aquí y\l"
	.string "ahora, pero creo que está esperando\l"
	.string "por ti. Espero que me deje tus restos.$"

MicoloLeague_PacoRoom_Candela_Text_0:
	.string "Hostia, ¡hola {PLAYER}!\p"
	.string "¿...que qué hago aquí? Entre tú y yo, sí,\n"
	.string "soy la líder de tipo fuego. Pero eso no\l"
	.string "significa que no pueda estar CALIENTE.\l"
	.string "Mind your own business. ¡Suerte!$"

MicoloLeague_PacoRoom_CameraMan_Text_0:
	.string "¡AAAAAH Y TÚ QUIÉN ERES!\p"
	.string "¿...vienes a derrotar a MICOLO? ¿A\n"
	.string "SALVARNOS? Mis plegarias han sido\l"
	.string "escuchadas :D\p"
	.string "Soy FRAN, el real, no ese bicho chungo\n"
	.string "que se hace llamar PACOCHEF. Tengo un\l"
	.string "trabajo de mierda como cámara, esos\l"
	.string "pelotudos de RAGU y LAVENDER me han\l"
	.string "pedido que grabe todo para que se\l"
	.string "pueda ver en el emulador. Grrrr, se van\l"
	.string "a enterar cuando salga de aquí.\p"
	.string "...espera, ¿cómo que solo soy un NPC?\n"
	.string "¡VUELVE AQUÍ, CABRÓN!$"

MicoloLeague_PacoRoom_SnorlaxDoll_Text_0:
	.string "Es un SNORLAX dormido... está abrazando\n"
	.string "un cristal Midelar.$"

MicoloLeague_PacoRoom_CyndaDoll_Text_0:
	.string "Es un muñeco de CYNDAQUIL. Hay una nota\n"
	.string "al lado...\p"
	.string "“Nunca olvides de dónde vienes y cómo\n"
	.string "empezó todo.”$"

MicoloLeague_PacoRoom_Latias_Text_0:
	.string "TIAAAS...$"

MicoloLeague_PacoRoom_Latios_Text_0:
	.string "TIOOOS...$"

MicoloLeague_PacoRoom_Suicune_Text_0:
	.string "Cuuuune...$"
	
CommonName_Text_Pacochef:
	.string "PACOCHEF$"

