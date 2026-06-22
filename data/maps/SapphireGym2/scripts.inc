SapphireGym2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SapphireGym2_MapScripts_OnLoad
	.byte 0

SapphireGym2_MapScripts_OnLoad:
	call_if_unset FLAG_DEFEATED_SAPPHIRE_TOTEM, SapphireGym2_BlockTotemPath
	checktrainerflag TRAINER_SAPPH
	call_if_ne SapphireGym2_BlockTitanRoom
	return

SapphireGym2_BlockTotemPath:
	setmetatile 10, 37, 0x23C, 1
	setmetatile 10, 36, 0x234, 1
	return

SapphireGym2_OpenTotemPath:
	setmetatile 10, 37, 0x2C1, 0
	setmetatile 10, 36, 0x2C1, 0
	return

SapphireGym2_BlockTitanRoom:
	setmetatile 9, 3, 0x259, 1
	setmetatile 10, 3, 0x25A, 1
	setmetatile 11, 3, 0x25B, 1
	setmetatile 9, 2, 0x251, 1
	setmetatile 10, 2, 0x252, 1
	setmetatile 11, 2, 0x253, 1
	setmetatile 9, 1, 0x249, 1
	setmetatile 10, 1, 0x24A, 1
	setmetatile 11, 1, 0x24B, 1
	return

SapphireGym2_OpenTitanRoom:
	setmetatile 9, 3, 0x2BA, 1
	setmetatile 10, 3, 0x2BB, 0
	setmetatile 11, 3, 0x2BC, 1
	setmetatile 9, 2, 0x2B2, 1
	setmetatile 10, 2, 0x2B3, 1
	setmetatile 11, 2, 0x2B4, 1
	setmetatile 9, 1, 0x2AA, 1
	setmetatile 10, 1, 0x2AB, 1
	setmetatile 11, 1, 0x2AC, 1
	return

SapphireGym2_EventScript_Totem::
	lockall
	msgbox DesafiarTotem_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SapphireGym2_EventScript_Totem2
	releaseall
	end	
	
SapphireGym2_EventScript_Totem2::	
	playmoncry SPECIES_DARK_PIKACHU, 2
	delay 40
	waitmoncry
	msgbox SapphireGym2_Text_TotemAppears, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_SAPPHIRE
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
	setvar VAR_LAST_TALKED, 2
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	call_if_eq SapphireGym2_EventScript_Totem_Won
	releaseall
	end

SapphireGym2_EventScript_Totem_Won::
	setflag FLAG_DEFEATED_SAPPHIRE_TOTEM
	removeobject 2
	call SapphireGym2_OpenTotemPath
	special DrawWholeMapView
	msgbox SapphireGym2_Text_TotemDisappears
	return

SapphireGym2_EventScript_Sapphire::
	lock
	faceplayer
	goto_if_set FLAG_REMATCH_SAPPH, SapphireGym2_EventScript_Sapphire_Defeated
    checktrainerflag TRAINER_SAPPH
    goto_if_eq SapphireGym2_EventScript_Sapphire_Defeated
	trainerbattle_single TRAINER_SAPPH, SapphireGym_Text_SapphIntro, SapphireGym_Text_SapphLose, SapphireGym2_EventScript_SapphDefeated, NO_MUSIC
	release
	end

SapphireGym2_EventScript_SapphDefeated::
	msgbox SapphireGym2_Text_ExplainBadgeTakeThis, MSGBOX_DEFAULT
	delay 30
	playse SE_DOOR
	delay 40
	call SapphireGym2_OpenTitanRoom
	playse SE_RG_W_DOOR
	special DrawWholeMapView
	release
	end
	
SapphireGym2_EventScript_Sapphire_Defeated::
	goto_if_set FLAG_REMATCH_SAPPH, SapphireGym2_EventScript_Sapph_Rematch
	goto_if_unset FLAG_DEFEATED_BOSS_TITAN, SapphireGym2_EventScript_SapphPostBattle_CheckTheBasement
	speakername CommonName_Text_Sapphire
	msgbox SapphireGym2_Text_SapphPostBattle, MSGBOX_DEFAULT
	release
	end

SapphireGym2_EventScript_SapphPostBattle_CheckTheBasement:
	speakername CommonName_Text_Sapphire
	msgbox SapphireGym2_Text_SapphPostBattle_CheckTheBasement, MSGBOX_DEFAULT
	release
	end

SapphireGym2_EventScript_Sapph_Rematch::
	trainerbattle_single TRAINER_SAPPH, SapphireGym2_Text_SapphRematchIntro, SapphireGym_Text_SapphLoseRematch, SapphireGym2_EventScript_SapphRematchDefeated, NO_MUSIC
	release
	end
	
SapphireGym2_EventScript_SapphRematchDefeated::
	msgbox SapphireGym2_Text_SapphRematchPostBattle, MSGBOX_DEFAULT
	clearflag FLAG_REMATCH_SAPPH
	release
	end

SapphireGym2_Text_TotemAppears:
	.string "DARK PIKA, the TOTEM POKéMON of\n" 
	.string "SAPPHIRE GYM, has appeared!$"

SapphireGym2_Text_TotemDisappears:
	.string "DARK PIKA disappeared...$"

SapphireGym_Text_SapphIntro:
	.string "Hola, yo... te doy la bienvenida a mi\n"
	.string "gimnasio. Tú debes ser de quién\l"
	.string "hablaban las chicas...\p"
	.string "... creo que las dejaste impresionadas,\n"
	.string "teehee.\p"
	.string "Me presento, mi nombre es SAPPHIRE y\n"
	.string "soy la líder de este gimnasio.\p"
	.string "¿Viste al POKéMON tótem DARK PIKA? Es\n"
	.string "terroríficamente hermoso, ¿no crees?\l"
	.string "Yo diseñé su sprite. También diseñé los\l"
	.string "sprites de las idols que viste durante\l"
	.string "las pruebas.\p"
	.string "¿Que a qué me refiero?... mmm... Para\n"
	.string "responderte, necesito primero que me\l"
	.string "respondas tú, ¿crees que exista algún\l"
	.string "plano dimensional en donde tú no seas\l"
	.string "más que parte de un videojuego en\l"
	.string "donde otra persona controla todos tus\l"
	.string "movimientos? ¿Y no sólo a ti, sino a\l"
	.string "todo tu mundo?\p"
	.string "...\p"
	.string "¿Dices que suena tenebroso?... mmm...\n"
	.string "Siendo así... mejor cambiemos de tema...\l"
	.string "sí...\p"
	.string "¿Sabías que siempre soñé con montar un\n"
	.string "espectáculo de idols? Así es, y me\l"
	.string "pareció divertido invocar a las mejores\l"
	.string "idols desde su mundo virtual y traerlas\l"
	.string "a mi gimnasio.\p"
	.string "... Ains, ¿no me entiendes? Esto...,\n"
	.string "perdón, es que... ay...\p"
	.string "...\p"
	.string "Bueno, olvídalo, creo que ahora hay\n"
	.string "asuntos más importantes que tratar.\p"
	.string "Viniste porque quieres la medalla\n"
	.string "de este gimnasio, ¿no? Pero\l"
	.string "tengo un problema...\p"
	.string "... sucede que...\p"
	.string "No, no, olvídalo. Si lo que quieres es\n"
	.string "luchar, entonces eso haremos.\p"
	.string "¡Que comience la función!$"

SapphireGym_Text_SapphLose:
	.string "¡Wuau! ¡Si impresionaste a las\n"
	.string "idols, pues que sepas que a mí\l"
	.string "también me has dejado impresionada!$"

SapphireGym2_Text_ExplainBadgeTakeThis:
	.string "De verdad eres increíble. Has superado\n"
	.string "todas las pruebas de este gimnasio. El\l"
	.string "único problema es que... no puedo\l"
	.string "entregarte la medalla...\p"
	.string "...\p"
	.string "Ains... te cuento. Detrás de estas\n"
	.string "cortinas yo tenía un pequeño\l"
	.string "laboratorio, y es que... bueno... resulta\l"
	.string "que me ordenaron diseñar el sprite de\l"
	.string "una criatura para añadir a la colección\l"
	.string "de MICOLO, quiero decir, la “cara\l"
	.string "bonita”, el cascarón del que sería el\l"
	.string "POKéMON insignia de MICOLO. Un\l"
	.string "científico llamado PHENT era el\l"
	.string "encargado de aquel bizarro proyecto y\l"
	.string "de darle vida a ese POKéMON al cual\l"
	.string "llamó DARK PIKA.\p"
	.string "Sin embargo, el otro día, mientras\n"
	.string "ensayaba unas coreografías con las\l"
	.string "chicas, hubo un terremoto y mi\l"
	.string "laboratorio se destruyó y en su lugar\l"
	.string "apareció un túnel muy extraño y\l"
	.string "oscuro. Me armé de valor y bajé por el\l"
	.string "túnel, pero algo me atacó. No pude verlo\l"
	.string "bien, pero era algo enorme y aterrador.\l"
	.string "Apenas pude huir, pero con la prisa\l"
	.string "dejé caer las medallas... ains...\p"
	.string "Tú eres fuerte, tal vez puedas bajar y\n"
	.string "ver que hay allí aunque no te lo\l"
	.string "recomiendo.\p"
	.string "Sí, ¡mejor no vayas!$"

SapphireGym2_Text_ReceivedBadge:
	.string "{PLAYER} obtuvo la MEDALLA BURBUJA\n" 
	.string "RÍTMICA del gimnasio de SAPPHIRE.$"

SapphireGym2_Text_SapphPostBattle:
    .string "Gracias a ti, todo vuelve a la calma en\n"
	.string "este gimnasio. Las chicas y yo te\l"
	.string "estaremos eternamente agradecidas.$"

SapphireGym2_Text_SapphRematchIntro:
	.string "Hola, qué tal, ¿cómo has estado? ¿Qué?\n"
	.string "¿Quieres una revancha? ¡Estaba\l"
	.string "esperando que lo dijeras! ¡Me gustaría\l"
	.string "emplearme a fondo y también ver cuánto\l"
	.string "has mejorado!$"

SapphireGym2_Text_SapphRematchPostBattle:
	.string "Está bien, aún no estoy preparada. Debo\n"
	.string "seguir entrenando junto a mis POKéMON\l"
	.string "y las idols. No podemos permitir que un\l"
	.string "incidente como el de aquella vez,\l"
	.string "sacuda nuevamente a mi gimnasio.$"

SapphireGym_Text_SapphLoseRematch:
    .string "Vale, ya entendí u.u$"

SapphireGym2_Text_SapphPostBattle_CheckTheBasement:
	.string "La gente de MICOLO solía entrar y salir\n"
	.string "de mi laboratorio. Una vez los oí\l"
	.string "hablando algo de portales espacio\l"
	.string "temporales. Creo que algo hicieron allá\l"
	.string "abajo o enterraron algo que finalmente\l"
	.string "se desató.$"
	
CommonName_Text_Sapphire:
	.string "SAPPHIRE$"
