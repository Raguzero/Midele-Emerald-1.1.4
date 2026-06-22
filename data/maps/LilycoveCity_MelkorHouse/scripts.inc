LilycoveCity_MelkorHouse_MapScripts::
	.byte 0

LilycoveCity_MelkorHouse_EventScript_Alliare::
	lock
	faceplayer
	speakername CommonName_Text_Alliare
	msgbox LilycoveCity_MelkorHouse_EventScript_Alliare_Text_0
	release
	return


LilycoveCity_MelkorHouse_EventScript_DataminingBook::
	lock
	msgbox LilycoveCity_MelkorHouse_EventScript_DataminingBook_Text_0
	release
	return


LilycoveCity_MelkorHouse_EventScript_Melkor::
	lock
	speakername CommonName_Text_Melkor
	compare VAR_MELKOR_STATE, 0
	goto_if_eq LilycoveCity_MelkorHouse_EventScript_Melkor_2
	compare VAR_MELKOR_STATE, 1
	goto_if_eq LilycoveCity_MelkorHouse_EventScript_Melkor_3
	compare VAR_MELKOR_STATE, 2
	goto_if_eq LilycoveCity_MelkorHouse_EventScript_Melkor_4
LilycoveCity_MelkorHouse_EventScript_Melkor_1:
	release
	return
	
LilycoveCity_MelkorHouse_EventScript_Melkor_4:
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_MelkorHouse_PostgameBattle
	faceplayer
	msgbox LilycoveCity_MelkorHouse_EventScript_Melkor_Text_4
	release
	end

LilycoveCity_MelkorHouse_PostgameBattle:
	faceplayer
	trainerbattle_single TRAINER_MELKOR, LilycoveCity_MelkorHouse_PostgameBattle_Intro, LilycoveCity_MelkorHouse_PostgameBattle_Defeat
	msgbox LilycoveCity_MelkorHouse_PostgameBattlePostBattle, MSGBOX_AUTOCLOSE
	end

LilycoveCity_MelkorHouse_EventScript_Melkor_2:
	msgbox LilycoveCity_MelkorHouse_EventScript_Melkor_Text_0
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	faceplayer
	msgbox LilycoveCity_MelkorHouse_EventScript_Melkor_Text_1
	msgbox LilycoveCity_MelkorHouse_EventScript_Melkor_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_MelkorHouse_EventScript_Melkor_7
	setvar VAR_MELKOR_STATE, 1
	msgbox LilycoveCity_MelkorHouse_EventScript_Melkor_Text_5
	goto LilycoveCity_MelkorHouse_EventScript_Melkor_1

LilycoveCity_MelkorHouse_EventScript_Melkor_3:
	faceplayer
	msgbox LilycoveCity_MelkorHouse_EventScript_Melkor_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_MelkorHouse_EventScript_Melkor_10
	setvar VAR_MELKOR_STATE, 1
	msgbox LilycoveCity_MelkorHouse_EventScript_Melkor_Text_5
	goto LilycoveCity_MelkorHouse_EventScript_Melkor_1

LilycoveCity_MelkorHouse_EventScript_Melkor_7:
	speakername NULL
	setvar VAR_TEMP_1, SPECIES_RIOLU
	givemon SPECIES_RIOLU, 5, ITEM_SOOTHE_BELL, TRUE
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_MelkorHouse_EventScript_Melkor_15
LilycoveCity_MelkorHouse_EventScript_Melkor_13:
	playfanfare MUS_FANFA4
	message LilycoveCity_MelkorHouse_EventScript_Melkor_Text_3
	waitmessage
	waitfanfare
	setvar VAR_MELKOR_STATE, 2
	speakername CommonName_Text_Melkor
	msgbox LilycoveCity_MelkorHouse_EventScript_Melkor_Text_4
	goto LilycoveCity_MelkorHouse_EventScript_Melkor_1

LilycoveCity_MelkorHouse_EventScript_Melkor_10:
	speakername NULL
	setvar VAR_TEMP_1, SPECIES_RIOLU
	givemon SPECIES_RIOLU, 5, ITEM_SOOTHE_BELL, TRUE
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_MelkorHouse_EventScript_Melkor_20
LilycoveCity_MelkorHouse_EventScript_Melkor_18:
	playfanfare MUS_FANFA4
	message LilycoveCity_MelkorHouse_EventScript_Melkor_Text_3
	waitmessage
	waitfanfare
	setvar VAR_MELKOR_STATE, 2
	speakername CommonName_Text_Melkor
	msgbox LilycoveCity_MelkorHouse_EventScript_Melkor_Text_4
	goto LilycoveCity_MelkorHouse_EventScript_Melkor_1

LilycoveCity_MelkorHouse_EventScript_Melkor_14:
	goto Common_EventScript_NoMoreRoomForPokemon
	goto LilycoveCity_MelkorHouse_EventScript_Melkor_13

LilycoveCity_MelkorHouse_EventScript_Melkor_15:
	compare VAR_RESULT, 1
	goto_if_ne LilycoveCity_MelkorHouse_EventScript_Melkor_14
	goto LilycoveCity_MelkorHouse_EventScript_Melkor_13

LilycoveCity_MelkorHouse_EventScript_Melkor_19:
	goto Common_EventScript_NoMoreRoomForPokemon
	goto LilycoveCity_MelkorHouse_EventScript_Melkor_18

LilycoveCity_MelkorHouse_EventScript_Melkor_20:
	compare VAR_RESULT, 1
	goto_if_ne LilycoveCity_MelkorHouse_EventScript_Melkor_19
	goto LilycoveCity_MelkorHouse_EventScript_Melkor_18

LilycoveCity_MelkorHouse_EventScript_PCPokexperto::
	lock
	msgbox LilycoveCity_MelkorHouse_EventScript_PCPokexperto_Text
	release
	return

LilycoveCity_MelkorHouse_EventScript_Alliare_Text_0:
	.string "Los foros están pasados de moda...\n"
	.string "eso es lo que dice MELKOR.\p"
	.string "No es que no esté de acuerdo, pero, ¿no\n"
	.string "podría hacer algo más que no sea\l"
	.string "pasarse todo el día en TWITTR?\p"
	.string "No sé, cosas como ocuparse de la\n"
	.string "familia, limpiar la casa...\p"
	.string "¡o mover de sitio esas malditas cajas!$"

LilycoveCity_MelkorHouse_EventScript_DataminingBook_Text_0:
	.string "Hay un libro sobre la mesa. El título\n"
	.string "es...\p"
	.string "“DATAMINING DE POKéMON GO: GUÍA PARA\n"
	.string "NOVATOS”$"

LilycoveCity_MelkorHouse_EventScript_Melkor_Text_0:
	.string "Estos de CP son unos tóxicos... ¿Cómo\n"
	.string "son capaces de publicar los leaks de\l"
	.string "Game Freak?...\p"
	.string "Bueno, hora de tweetear sobre el\n"
	.string "datamining de POKéMON GO...$"

LilycoveCity_MelkorHouse_EventScript_Melkor_Text_1:
	.string "¿Eh? ¿Quién eres? ¿Alguien de la MAFIA?\n"
	.string "¿Uno de mis haters? Que sepas que soy\l"
	.string "abogado, y no me hagas la rima que ya\l"
	.string "somos mayorcitos, podría llevarte a los\l"
	.string "tribunales por allanamiento de morada\l"
	.string "y tráfico de POKéMON en peligro...\p"
	.string "...\p"
	.string "...Ah, solo eres un entrenador que\n"
	.string "pasaba por aquí... Mmm... en ese caso...\l"
	.string "¿podrías hacer como que no has oído\l"
	.string "nada?\p"
	.string "soy MELKOR, administrador de PxP\n"
	.string "Hace tiempo que dejé el antiguo PxP\l"
	.string "y me mudé aquí, a mi nuevo hogar.\l"
	.string "Desde entonces me dedico a publicar\l"
	.string "noticias de POKéMON GO en TWITTR. Ya\l"
	.string "sabes, los foros están muertos y eso.\p"
	.string "El problema es que hay ciertas personas\n"
	.string "que no se han tomado bien esto... he\l"
	.string "oído que la MAFIA ha venido a HOENN y\l"
	.string "temo que estén buscándome para\l"
	.string "vengarse.$"

LilycoveCity_MelkorHouse_EventScript_Melkor_Text_2:
	.string "Hagamos un trato. Si no le dices a nadie\n"
	.string "que vivo aquí, te regalaré un\l"
	.string "fantástico POKéMON. ¿Qué te parece?$"

LilycoveCity_MelkorHouse_EventScript_Melkor_Text_3:
	.string "¡{PLAYER} obtuvo a RIOLU!$"

LilycoveCity_MelkorHouse_EventScript_Melkor_Text_4:
	.string "Un placer hacer negocios contigo.\n"
	.string "Ahora, si me disculpas, TWITTR me llama.$"

LilycoveCity_MelkorHouse_EventScript_Melkor_Text_5:
	.string "Entonces será mejor que te largues de\n"
	.string "aquí antes de que te lleve a los\l"
	.string "tribunales.$"

LilycoveCity_MelkorHouse_EventScript_PCPokexperto_Text:
	.string "PC iniciado. Conectándose a\n"
	.string "Pokéxperto.net.\p"
	.string "...\p"
	.string "...\p"
	.string "...\p"
	.string "Estableciendo una conexión TLS con\n"
	.string "pokexperto.net...\p"
	.string "Enviando datos a pokexperto.net...\p"
	.string "Esperando a pokexperto.net...\p"
	.string "...\p"
	.string "...\p"
	.string "...\p"
	.string "...\p"
	.string "Cargando foros Pokéxperto...\p"
	.string "Cargando comentarios flood de MICOLO y\n"
	.string "poke-xavi...\p"
	.string "Cargando calendario de eventos\n"
	.string "bugeado... (quedan -1230 días para el\l"
	.string "evento de DARKRAI)\p"
	.string "Cargando emoticonos...\p"
	.string "...\p"
	.string "...\p"
	.string "...\p"
	.string "... ERROR 500 INTERNAL SERVER ERROR.\p"
	.string "No te has podido conectar a PxP :($"

LilycoveCity_MelkorHouse_PostgameBattle_Intro: 
	.string "Esto de TWITTR va de mal en peor\n"
	.string "desde que lo compró el MELÓN.\p"
	.string "Voy a tener que preparar un plan B\n"
	.string "por si acaso para asegurar las\l"
	.string "noticias de PxP.\p"
	
	.string "¡Espera un momento! ¿Has vencido a la\n"
	.string "LIGA POKéMON de HOENN?\p"
    .string "Entonces estoy seguro de que puedes\n"
	.string "darme una buena batalla de pokexpertos.\p"

    .string "Te demostraré mi poder con la estrategia\n"
    .string "que he ideado después de tantos años\l"
	.string "de investigación de todo el mundo\p"
	.string "POKéMON que puedes encontrar en mi WEB.$"

LilycoveCity_MelkorHouse_PostgameBattle_Defeat: 
	.string "¿Como has roto la cadena?$"

LilycoveCity_MelkorHouse_PostgameBattlePostBattle: 
	.string "Baton Pass Team es una terrorífica\n"
	.string "estrategia de combate que funciona\l"
	.string "en cadena, si sale bien.$"
	
CommonName_Text_Alliare:
	.string "ALLIARE$"
	
CommonName_Text_Melkor:
	.string "MELKOR$"

