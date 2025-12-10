GymSanty_MapScripts::
	.byte 0

GymSanty_EventScript_Santy::
	switch VAR_SHIFTEO_SANTY_GYM
	case 0, GymSanty_EventScript_Santy_Shifteo0
	case 1, GymSanty_EventScript_Santy_Shifteo1
	case 2, GymSanty_EventScript_Santy_Shifteo2
	case 3, GymSanty_EventScript_Santy_Derrotado
	case 4, GymSanty_EventScript_Santy_Rematch
	end

GymSanty_EventScript_Santy_Shifteo0::
	trainerbattle_single TRAINER_SANTYGRASS, GymSanty_Text_SantyShifteo0Intro, GymSanty_Text_SantyShifteo0Defeat, GymSanty_EventScript_SantyShifteo0Defeated, NO_MUSIC
	release
	end
	
GymSanty_EventScript_Santy_Shifteo1::
	trainerbattle_single TRAINER_SANTYGRASS_2, GymSanty_Text_SantyShifteo1Intro, GymSanty_Text_SantyShifteo1Defeat, GymSanty_EventScript_SantyShifteo1Defeated, NO_MUSIC
	release
	end
	
GymSanty_EventScript_Santy_Shifteo2::
	trainerbattle_single TRAINER_SANTYGRASS_3, GymSanty_Text_SantyShifteo2Intro, GymSanty_Text_SantyShifteo2Defeat, GymSanty_EventScript_SantyShifteo2Defeated, NO_MUSIC
	release
	end
	
GymSanty_EventScript_Santy_Derrotado::
	msgbox GymSanty_Text_SantyPostBattle, MSGBOX_DEFAULT
	release
	end
	
GymSanty_EventScript_Santy_Rematch::
	trainerbattle_single TRAINER_SANTYGRASS_3, GymSanty_Text_SantyRematchIntro, GymSanty_Text_SantyRematchDefeat, GymSanty_EventScript_SantyRematchDefeated, NO_MUSIC
	release
	end
	
GymSanty_EventScript_SantyRematchDefeated::
	msgbox GymSanty_Text_SantyPostBattle, MSGBOX_DEFAULT
	setvar VAR_SHIFTEO_SANTY_GYM, 3
	release
	end

GymSanty_EventScript_SantyShifteo0Defeated::
	setvar VAR_SHIFTEO_SANTY_GYM, 1
	warp MAP_GYM_SANTY, 3, 0, 0
	waitstate
	release
	end
	
GymSanty_EventScript_SantyShifteo1Defeated::
	setvar VAR_SHIFTEO_SANTY_GYM, 2
	warp MAP_GYM_SANTY, 3, 0, 0
	waitstate
	release
	end

GymSanty_EventScript_SantyShifteo2Defeated::
	message GymSanty_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GymSanty_Text_ExplainBadgeTakeThis, MSGBOX_DEFAULT
	@ Level Cap Item
	delay 30
	playse SE_PIN
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	playfanfare MUS_ME_B_SMALL
	delay 30
	msgbox LevelCapItem_Text_GymSanty, MSGBOX_DEFAULT
	closemessage
	@ Level Cap Item	
	setflag FLAG_DEFEATED_SANTY_GYM
	setvar VAR_SHIFTEO_SANTY_GYM, 3
	delay 30
	release
	end

GymSanty_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SANTY_GYM, GymSanty_EventScript_GymGuidePostVictory
	msgbox GymSanty_Text_GymGuideAdvice, MSGBOX_DEFAULT
	msgbox GymSanty_Text_GymGuideAdvice2, MSGBOX_DEFAULT
	msgbox GymSanty_Text_GymGuideAdvice3, MSGBOX_DEFAULT
	release
	end
	
GymSanty_EventScript_GymGuideAdviceExplainMicoliga::
	msgbox GymSanty_Text_GymGuideAdvice2, MSGBOX_DEFAULT
	release
	end

GymSanty_EventScript_GymGuidePostVictory::
	msgbox GymSanty_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	msgbox GymSanty_Text_GymGuideAdviceExplainMicoliga, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymSanty_EventScript_GymGuideAdviceExplainMicoliga
	release
	end

GymSanty_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_DEFEATED_SANTY_GYM, GymSanty_EventScript_GymStatueCertified
	goto GymSanty_EventScript_GymStatue
	end

GymSanty_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_DEFEATED_SANTY_GYM, GymSanty_EventScript_GymStatueCertified
	goto GymSanty_EventScript_GymStatue
	end

GymSanty_EventScript_GymStatueCertified::
	msgbox GymSanty_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

GymSanty_EventScript_GymStatue::
	msgbox GymSanty_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end
	
GymSanty_Text_GymGuideAdviceExplainMicoliga:
	.string "¿Quieres que te explique que es esto?$"
	
GymSanty_Text_GymGuideAdvice:
	.string "¡Veo que eres una cara nueva!$"
	
GymSanty_Text_GymGuideAdvice2:
	.string "Te explicaré en que consiste todo esto.\p"
	
	.string "En MICOLANDIA se está organizando una\n"
	.string "nueva competición que permite sacar\l"
	.string "todo el potencial de los entrenadores.\p"
	
	.string "Cada entrenador tendrá que superar cada\n"
	.string "uno de los retos que suponen los 4 GYM\l" 
	.string "de MICOLANDIA, de forma ordenada.\p"
	
	.string "El entrenador que sea capaz de derrotar\n" 
	.string "a los 4 LÍDERES será invitado para\l" 
	.string "participar en la maravillosa MICOLIGA.\p"
	
	.string "¿Qué es la MICOLIGA?\p"
	
	.string "Es una nueva LIGA POKéMON más dificil\n"
	.string "que cualquier otra LIGA de cualquier\l" 
	.string "otra región.\p"
	
	.string "La MICOLIGA se trata del mayor reto que\n"
	.string "jamás se ha hecho en la historia de\l"
	.string "las competiciones POKéMON.\p"
	
	.string "Por lo que el entrenador que se proclame\n"
	.string "vencedor en la MICOLIGA será el mejor\l" 
	.string "entrenador de MIDELE.\p"

	.string "Ten en cuenta, que todo esto es...\n"
	.string "digamos, no-oficial, por lo que no tiene\l" 
	.string "ninguna validez legal para los gobiernos\l"
	.string "que organizan la LIGA POKéMON de cada\l"
	.string "región, y por tanto, en tu info de\l" 
	.string "entrenador no quedarán registradas las\l" 
	.string "medallas que consigas en este lugar.\p"
	
	.string "Cada GYM normalmente constará de\n" 
	.string "3 pruebas:\l"
	.string "Derrotar a todos los entrenadores\l"
	.string "Derrotar al POKéMON TOTEM\l"
	.string "Derrotar al LÍDER de GYM\p"
	
    .string "Pero las pruebas pueden cambiar\n"
	.string "dependiendo de las ideas del líder.$"

GymSanty_Text_GymGuideAdvice3:
	.string "En cuanto a este GYM...\p"

	.string "Si consigues superar las 3 pruebas,\n"
	.string "se te recompensará con la no-oficial\l"
	.string "MEDALLA HIERBA QUEMADA.\p"

	.string "Por cierto, el LÍDER SANTYGRASS es un\n"
	.string "maestro del olor a hierba quemada y del\l"
	.string "shifteo.\p"

	.string "¡Ten mucho cuidado y no caigas en la\n" 
	.string "desesperación que supone el shifteo!\p"
	
	.string "¡Buen hax!$"

GymSanty_Text_GymGuidePostVictory:
	.string "¡WOW! ¡Así que venciste a SANTYGRASS!$"

GymSanty_Text_SantyShifteo0Intro:
    .string "Te doy la bienvenida a mi gimnasio.\p" 
    .string "Espero que te agrade el aroma que\n"
	.string "hay aquí.\p"

    .string "Llevo años cuidando con mucho cariño\n"
    .string "todas las plantas personalmente.\p"

    .string "¡Ahora es el momento de encender\n"
	.string "este lugar!$"

GymSanty_Text_SantyShifteo0Defeat:
    .string "Ya veo, con que esa es tu estrategia...\p"
    .string "¿Eh? ¿Acaso crees que ya ha terminado\n"
	.string "la pelea?\p"

    .string "¡Esto solo ha sido el inicio!\p"
    .string "“CELEBI usa un extraño poder”$"

GymSanty_Text_SantyShifteo1Intro:
    .string "Te doy la bienvenida a mi gimnasio.\p" 
    .string "Espero que te agrade el aroma que\n"
	.string "hay aquí.\p"
    .string "¿La medalla?\p"
    .string "Lo siento, pero a mí jamás me ganaste,\n"
    .string "aunque parece que ya viste el poder\l"
	.string "de mi CELEBI.\p"

    .string "¡Si quieres te puedo hacer\n"
	.string "otra demostración!$"

GymSanty_Text_SantyShifteo1Defeat:
    .string "Ese ha sido un buen intento\n"
    .string "aunque parece que el día no me\l"
	.string "acompañaba.\p"

    .string "Pero no importa, CELEBI me permite\n"
	.string "viajar en el tiempo e ir a una línea\l"
	.string "temporal en donde no me hayas ganado.\p"

    .string "¡CELEBI, es hora de SHIFTear!\p"
    .string "“CELEBI usa un extraño poder”$"

GymSanty_Text_SantyShifteo2Intro:
    .string "Te doy la bienvenida a mi gimnasio.\p" 
    .string "Espero que te agrade el aroma que\n"
	.string "hay aquí.\p"
	
    .string "No hay nada mejor que cuando las\n"
	.string "plantas arden.\p"

    .string "Parece que sabes sobre mi SHIFTeo.\p"
    .string "Así que ya es momento de silenciarte.\p"
    .string "El olor a hierba quemada es lo mejor\n"
    .string "para una batalla definitiva.$"

GymSanty_Text_SantyShifteo2Defeat:
    .string "How Could this Happen\n"
    .string "Even with the apocrypha!?\p"
    .string "Está bien, toma la medalla\n"
    .string "y vete que ya me estás quemando.$"

GymSanty_Text_ReceivedBadge:
	.string "{PLAYER} recibió la MEDALLA HIERBA\n"
	.string "QUEMADA de SANTYGRASS.$"

GymSanty_Text_ExplainBadgeTakeThis:
	.string "Con esta MEDALLA en tu poder,\n"
	.string "te obedecerá sin rechistar todo\l"
	.string "POKéMON intercambiado que no sea\l"
	.string "superior al nivel 85.\p"
	
	.string "También te capacita para el reto\n"
	.string "del siguiente GYM.\p"

	.string "SAPPHIRE te estará esperando allí.\n"
	.string "¡Será mejor que te prepares para\l"
	.string "su espectáculo de baile!$"

GymSanty_Text_SantyPostBattle:
	.string "A ti aún te quedan muchos entrenadores\n"
	.string "por vencer.\p"
	
	.string "Mientras que a mí, aún me quedan\n"
	.string "muchas hierbas por quemar.\p"
	
	.string "¡No hay nada mejor que el olor a\n"
	.string "hierba quemada!$"

GymSanty_Text_GymStatue:
	.string "POKéMON GYM Nº1\n"
	.string "LÍDER: SANTYGRASS\l"
	.string "“TEMÁTICA: HIERBA QUEMADA”$"

GymSanty_Text_GymStatueCertified:
	.string "POKéMON GYM Nº1\n"
	.string "LÍDER: SANTYGRASS\l"
	.string "“TEMÁTICA: HIERBA QUEMADA”\p"

	.string "SANTYGRASS'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
	
GymSanty_Text_SantyRematchIntro:
    .string "Así que has venido de nuevo a\n"
	.string "visitarme a mi gimnasio.\p"
	
    .string "Si es que no hay nada mejor que\n"
	.string "cuando las plantas arden.\l"
	.string "¡Todos son atraídos por este aroma!\p"

    .string "Ha pasado tiempo desde nuestra batalla\n"
    .string "quemada. ¡Te reto a una revancha!$"

GymSanty_Text_SantyRematchDefeat:
    .string "How Could this Happen\n"
    .string "Even with the apocrypha!?$"
	
LevelCapItem_Text_GymSanty:
	.string "LEVEL CAP: Actualización completada.\n"
	.string "El nuevo límite es el nivel 85.$"
