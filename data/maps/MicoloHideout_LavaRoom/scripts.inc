MicoloHideout_LavaRoom_MapScripts::
	.byte 0

MicoloHideout_LavaRoom_EventScript_GiratinaMaster::
	lock
	faceplayer
	setflag FLAG_AVADER_MAUVILLE_RUINS_MEW_BYE
	special HasDefeatedAllMicoloHideoutTrainers
	compare VAR_RESULT, TRUE
	goto_if_eq MicoloHideout_LavaRoom_EventScript_GiratinaMaster_2
	msgbox MicoloHideout_LavaRoom_EventScript_GiratinaMaster_Text_1, MSGBOX_DEFAULT
MicoloHideout_LavaRoom_EventScript_GiratinaMaster_1:
	release
	return

MicoloHideout_LavaRoom_EventScript_GiratinaMaster_2:
	msgbox MicoloHideout_LavaRoom_EventScript_GiratinaMaster_Text_0, MSGBOX_DEFAULT
	applymovement 6, MicoloHideout_LavaRoom_Movement_GiratinaMaster
	waitmovement 0
	removeobject 6
	setflag FLAG_HIDE_LAVAROOM_GIRATINAMASTER
	msgbox MicoloHideout_LavaRoom_Text_GiratinaMaster_MusicPlayerUpgrade, MSGBOX_DEFAULT
	playse SE_TK_KASYA
	delay 10
	playfanfare MUS_FANFA4
	waitfanfare
	msgbox MicoloHideout_Text_MusicPlayerUpgraded, MSGBOX_DEFAULT
	setvar VAR_MUSIC_PLAYER, MUSIC_PLAYER_STATE_FINAL
	goto MicoloHideout_LavaRoom_EventScript_GiratinaMaster_1


MicoloHideout_LavaRoom_Movement_GiratinaMaster:
	walk_up
	step_end
	
MicoloHideout_LavaRoom_EventScript_Nugget::
    giveitem ITEM_NUGGET, 99
    compare VAR_RESULT, FALSE
    call_if_eq MicoloHideout_LavaRoom_BagFull
    closemessage
    removeobject 8
    setflag FLAG_ITEM_MICOLO_NUGGETS
    end
    
MicoloHideout_LavaRoom_BagFull::
    call Common_EventScript_BagIsFull
    closemessage
    release
    end

MicoloHideout_LavaRoom_EventScript_GiratinaMaster_Text_0:
	.string "GIRATINA MASTER: ¿has derrotado a\n"
	.string "todos los entrenadores? eres pro,\l"
	.string "puedes pasar. cierro tema. :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock:$"

MicoloHideout_LavaRoom_EventScript_GiratinaMaster_Text_1:
	.string "GIRATINA MASTER: SOY MOD, NO PUEDES\n"
	.string "PASAR. SE CIERRA LA LIGA.\p"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\n"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\p"
	.string "soy mod, pero te dejaré pasar si\n"
	.string "derrotas a todos los entrenadores de\l"
	.string "la GUARIDA.\p"
	.string "has derrotado a {STR_VAR_1} de\n"
	.string "{STR_VAR_2}.\p"
	.string "venga, combate o te baneo. cierro tema.\p"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\n"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock:$"

MicoloHideout_LavaRoom_EventScript_Phent::
	trainerbattle_single TRAINER_PHENT, MicoloHideout_LavaRoom_Text_PhentIntro, MicoloHideout_LavaRoom_Text_PhentDefeat
	msgbox MicoloHideout_LavaRoom_Text_PhentPostBattle, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_LavaRoom_EventScript_MDragon::
	trainerbattle_single TRAINER_MDRAGON, MicoloHideout_LavaRoom_Text_MDragonIntro, MicoloHideout_LavaRoom_Text_MDragonDefeat
	msgbox MicoloHideout_LavaRoom_Text_MDragonPostBattle, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_LavaRoom_EventScript_MaestroArena::
	trainerbattle_single TRAINER_MAESTRO_ARENA, MicoloHideout_LavaRoom_Text_MaestroArenaIntro, MicoloHideout_LavaRoom_Text_MaestroArenaDefeat
	msgbox MicoloHideout_LavaRoom_Text_MaestroArenaPostBattle, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_LavaRoom_EventScript_Manec::
	trainerbattle_single TRAINER_MANEC, MicoloHideout_LavaRoom_Text_ManecIntro, MicoloHideout_LavaRoom_Text_ManecDefeat
	msgbox MicoloHideout_LavaRoom_Text_ManecPostBattle, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_LavaRoom_EventScript_Pichu7::
	trainerbattle_single TRAINER_PICHU7, MicoloHideout_LavaRoom_Text_Pichu7Intro, MicoloHideout_LavaRoom_Text_Pichu7Defeat
	msgbox MicoloHideout_LavaRoom_Text_Pichu7PostBattle, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_LavaRoom_EventScript_EEVEETO::
	trainerbattle_double TRAINER_EEVEETO, MicoloHideout_LavaRoom_Text_EEVEETOIntro, MicoloHideout_LavaRoom_Text_EEVEETODefeat, MicoloHideout_LavaRoom_EEVEETO_MasdeunPokemon
	msgbox MicoloHideout_LavaRoom_Text_EEVEETOPostBattle, MSGBOX_AUTOCLOSE
	end

MicoloHideout_LavaRoom_EEVEETO_MasdeunPokemon: // BATALLA DOBLE
	.string "Así que solo llevas un Pokémon?\n"
	.string "No puedo luchar contigo, entonces.\p"

	.string "Mi estrategia es solo para las\n"
	.string "BATALLA DOBLE.$"
	
MicoloHideout_LavaRoom_Text_EEVEETOIntro: 
	.string "Mal día has elegido para pasear\n"
	.string "sin el casco anti-hax.\p" 
	
	.string "Mi Abomasnow al fin ha alcanzado\n" 
	.string "el poder de la Megaevolución.\p"

    .string "¡Prepárate para sentir el poder\n"
    .string "del invierno!$"

MicoloHideout_LavaRoom_Text_EEVEETODefeat: 
	.string "Ok, he perdido, pero seguro que\n"
    .string "te he jodido el Nuzlocke.$"

MicoloHideout_LavaRoom_Text_EEVEETOPostBattle:
	.string "No importa, usaré esta derrota\n"
	.string "como pretexto para que el cabrón\l"
	.string "de Ragu haga Midele Platinum.$"
	
MicoloHideout_LavaRoom_Text_PhentIntro:
	.string "Existe una teoría que relata que\n"
	.string "los DITTOS son los desechos expulsados\l"
	.string "por el POKéMON legendario MEW.\p"
	
	.string "Se cree, por ello, que por eso DITTO\n"
	.string "es el único POKéMON aparte de MEW, que\l" 
	.string "sabe TRANSFORM de forma natural, y que\l" 
	.string "por eso hay DITTOs pululando por los\l"
	.string "alrededores de un laboratorio en KANTO,\l"
	.string "donde el TEAM ROCKET hizo experimentos\l"
	.string "con MEW para poder crear a MEWTWO.\p"

	.string "Me encomendaron la tarea de examinar\n"
	.string "los excrementos de MEW y de varios\l"
	.string "POKéMON, pero ahora mismo estoy en un\l"
	.string "punto muerto, ya que no he descubierto\l" 
	.string "nada sorprendente.\p"
	
	.string "Nada tan sorprendente como mi mayor\n"
	.string "experimento de todos:\p"
	
	.string "¡EL PIKACHU OSCURO DEL TRUENO DE\n" 
	.string "LA OSCURIDAD!$"

MicoloHideout_LavaRoom_Text_PhentDefeat: 
	.string "¡Vaya trabajo de mierda!$"

MicoloHideout_LavaRoom_Text_PhentPostBattle:
	.string "Este trabajo es... literalmente...\n"
	.string "¡MIERDA!\p"

	.string "Mmm... tal vez pueda investigar por qué\n"
	.string "existen REGIELEKI y REGIDRAGO.\p"
	
	.string "Si los REGIS originales siempre fueron\n"
	.string "REGICE, REGIROCK y REGISTEEL...\p"
	
	.string "¿Por qué GF sacó los otros dos?$"
	
MicoloHideout_LavaRoom_Text_Pichu7Intro:
	.string "Yo fui moderador de POKéXPERTO\n"
	.string "durante un tiempo.\p"
	
	.string "Dediqué mi vida entera a instruir a la\n"
	.string "gente de la región de Teselia para\l"
	.string "evitar que usara Cinta Experto porque\l"
	.string "tengo que decir que no tiene nada de\l"
	.string "experto usar un objeto que potencia\l"
	.string "ataques que ya son superefectivos.\p"
	
	.string "Por lo tanto ya harán el doble de daño\n"
	.string "y no tiene sentido potenciar lo que ya\l"
	.string "hace mucho daño, no entiendo como la\l"
	.string "gente puede usar eso, vaya tontería ¿no?\p"

	.string "Ni siquiera se molestaron los\n"
	.string "creadores de este hack en meterlo...\l"
	.string "sabia elección. Era más que obvio.$"

MicoloHideout_LavaRoom_Text_Pichu7Defeat: 
	.string "Ahora mismo borro el tema ese con una\n"
	.string "mención positiva a Cinta Experto que ha\l"
	.string "escrito ese user hace poco y...anda\p"
	.string "que ahora no soy mod, que lo dejé\n"
	.string "por asuntos...laborales (?).$"

MicoloHideout_LavaRoom_Text_Pichu7PostBattle:
	.string "Recuerda no usar Cinta Experto.\p"
	.string "Antes de usar ese objeto considera usar\n"
	.string "Vidasfera, Gafas Especiales, Cinta\l"
	.string "Fuerte, Periscopio, tablas u objeto que\l"
	.string "subían el 20% de poder a un ataque,\l"
	.string "bla, bla, bla...incluso no llevar\l"
	.string "objeto para al menos recibir menos\l"
	.string "daño de KNOCK OFF.$"
	
MicoloHideout_LavaRoom_Text_MDragonIntro:
	.string "Hola, soy M DRAGON, uno de los más\n" 
	.string "fuertes entrenadores de todos los\l" 
	.string "tiempos, ganador de una gran cantidad\l" 
	.string "de torneos en SMOGON, POKEXPERTO,\l" 
	.string "POKESPAIN en todas las regiones y en\l"
	.string "todos los formatos AG, UBER, OU, UU,\l"
	.string "RU, NU, PU, FU, ZU...\p"

	.string "Estoy seguro de que has oído\n" 
	.string "hablar de mí.\p"

	.string "Así que me he estado preparando a\n"
	.string "conciencia para este momento.\l"
	.string "Yo seré el CAMPEÓN de la LIGA POKéMON\l"
	.string "MICOLANDIA.\p"
	
	.string "Por eso he llegado hasta aquí, porque\n"
	.string "solo llegan los mejores entrenadores.\p"

	.string "He superado todos los obstáculos que\n"
	.string "se me han puesto por delante y\l"
	.string "ya solo me queda uno más para poder\l"
	.string "alcanzar la LIGA POKéMON, y ese\l"
	.string "es nada mas y nada menos que...\p"
	
	.string "¡A quien tengo delante!$"

MicoloHideout_LavaRoom_Text_MDragonDefeat: 
	.string "¡MALDITA SEA!$"

MicoloHideout_LavaRoom_Text_MDragonPostBattle:
	.string "¡ME EQUIVOQUÉ DE GYARADOS OTRA VEZ!\p"
	
	.string "Iba a usar al GYARADOS defensivo\n"
	.string "en vez del ofensivo...$"

MicoloHideout_LavaRoom_Text_MaestroArenaIntro:
	.string "Hola, ¿me recuerdas?\n"
	.string "Soy MAESTRO ARENA, el poderoso\l"
	.string "entrenador de los POKéMON del\l"
	.string "desierto.\p"
	
	.string "También tengo un buen olfato para\n"
	.string "mis predicciones:\l" 
	.string "¡ESPAÑA ganará la EUROCOPA!\p"
	
	.string "Por otra parte...\p"

	.string "¿Tú también has superado todos estos\n"
	.string "desafíos de los líderes?\l"
	.string "¡Qué interesante! ¡Muy interesante!\p"
	
	.string "¡He venido a desafiar a esta LIGA\n"
	.string "POKéMON, y me proclamaré vencedor\l"
	.string "como hice en el PRIMER NACIONAL\l"
	.string "ESPAÑOL de DP! x)\p"

	.string "Me vendrás bien como saco de boxeo,\n"
	.string "solo espero que no lleves a ningún\l"
	.string "POKéMON gato.\p"
	
	.string "¡ODIO A LOS GATOS, SIEMPRE SE MEAN\n"
	.string "EN ARENA! ToT$"

MicoloHideout_LavaRoom_Text_MaestroArenaDefeat:
	.string "¡NO VALE! ¡HAX! ¡TRAMPOSO! ToT$"

MicoloHideout_LavaRoom_Text_MaestroArenaPostBattle:
	.string "¿Pero por qué? ¿Cómo yo, el grandioso\n"
	.string "MAESTRO ARENA ha sido derrotado?\p"

	.string "¿Por qué mi estrategia TSS no funcionó\n"
	.string "contra ti?\p"
	
	.string "Por si no lo sabes, TSS significa\n"
	.string "TOXIC, SPIKES y SANDSTORM.\p"
	
	.string "Es una estrategia que desespera a\n"
	.string "cualquier tipo de rival que no esté\l"
	.string "preparado, porque irá perdiendo más\l"
	.string "y más puntos de salud casi sin darse\l"
	.string "cuenta ¡JAJAJAJAJAJAJA!$"

MicoloHideout_LavaRoom_Text_GiratinaMaster_MusicPlayerUpgrade:
	.string "Parece que GIRATINA MASTER ha dejado\n"
	.string "algo en el suelo...\p"
	.string "¡Es la última TARJETA DE EXPANSIÓN para\n"
	.string "tu MUSIC PLAYER!$"
	
MicoloHideout_LavaRoom_Text_ManecIntro:
    .string "Hola buenas, ¿sabes si voy bien para\n"
    .string "LILYCOVE CITY?\p"
    .string "…\n"
    .string "¿No?\p"
    .string "Ya decía yo que los entrenadores eran\n"
    .string "menos flojos de la cuenta…\p"
    .string "El tal M DRAGON creo que tiene futuro,\n"
    .string "casi le gana a mis pokes de concurso.\p"
    .string "Bueno, pues muchas gracias, hasta otra.\p"
    .string "…\p"
    .string "Ah, es verdad, que por habernos mirado a\n"
    .string "los ojos ya tenemos que pelear.\p"
    .string "Pues nada, encuérese.$"

MicoloHideout_LavaRoom_Text_ManecDefeat: 
	.string "Cagüen…$"

MicoloHideout_LavaRoom_Text_ManecPostBattle:
    .string "Vaya flojera da tener que ir ahora al\n"
    .string "CENTRO POKéMON.\l"
    .string "Y menos mal que no están privatizados.$"
