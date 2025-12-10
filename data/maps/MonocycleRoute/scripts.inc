MonocycleRoute_MapScripts::
	.byte 0
	
Monocycle_Road_Sign::
	msgbox Monocycle_Road_Sign_Text, MSGBOX_SIGN
	end
	
Monocycle_Road_EventScript_TimerBall::
	giveitem ITEM_TIMER_BALL, 8
	compare VAR_RESULT, FALSE
	call_if_eq Monocycle_Road_BagFull
	closemessage
	removeobject 10
	setflag FLAG_ITEM_MONOCYCLEROAD_8TIMERBALL
	end
	
Monocycle_Road_EventScript_RareCandy::
	giveitem ITEM_RARE_CANDY, 4
	compare VAR_RESULT, FALSE
	call_if_eq Monocycle_Road_BagFull
	closemessage
	removeobject 11
	setflag FLAG_ITEM_MONOCYCLEROAD_4RARECANDY
	end
	
Monocycle_Road_EventScript_ShellBell::
	giveitem ITEM_SHELL_BELL, 1
	compare VAR_RESULT, FALSE
	call_if_eq Monocycle_Road_BagFull
	closemessage
	removeobject 12
	setflag FLAG_ITEM_MONOCYCLEROAD_SHELLBELL
	end
	
Monocycle_Road_EventScript_HeartScale::
	giveitem ITEM_HEART_SCALE, 9
	compare VAR_RESULT, FALSE
	call_if_eq Monocycle_Road_BagFull
	closemessage
	removeobject 13
	setflag FLAG_ITEM_MONOCYCLEROAD_9HEARTSCALE
	end
	
Monocycle_Road_BagFull::
	call Common_EventScript_BagIsFull
	closemessage
	release
	end
	
Monocycle_Road_EventScript_Constructor::
	lock
	faceplayer
	msgbox Monocycle_Road_Text_Constructor, MSGBOX_DEFAULT
	release
	end

Monocycle_Road_EventScript_MrZero::
	trainerbattle_single TRAINER_MR_ZERO, MrZero_AntesBatalla, MrZero_MensajeDerrota
	msgbox MrZero_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
Monocycle_Road_EventScript_Zzz::
	trainerbattle_single TRAINER_ZZZ, Zzz_AntesBatalla, Zzz_MensajeDerrota
	msgbox Zzz_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
Monocycle_Road_EventScript_PoisonMastahhhh::
	trainerbattle_single TRAINER_POISONMASTAHHHH, PoisonMastahhhh_AntesBatalla, PoisonMastahhhh_MensajeDerrota
	msgbox PoisonMastahhhh_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
Monocycle_Road_EventScript_Blue::
	trainerbattle_double TRAINER_BLUE_AND_YELLOW, BlueYellow_AntesBatalla, BlueYellow_MensajeDerrota, Monocycle_Road_Text_BlueNotEnoughMons
	msgbox BlueYellow_DespuesDeBatalla, MSGBOX_DEFAULT
	release
	end
	
Monocycle_Road_EventScript_Yellow::
	trainerbattle_double TRAINER_BLUE_AND_YELLOW, BlueYellow_AntesBatalla, BlueYellow_MensajeDerrota, Monocycle_Road_Text_BlueNotEnoughMons
	msgbox BlueYellow_DespuesDeBatalla, MSGBOX_DEFAULT
	release
	end
	
Monocycle_Road_EventScript_Dunk2::
	trainerbattle_single TRAINER_DUNK_2, Dunk2_AntesBatalla, Dunk2_MensajeDerrota
	msgbox Dunk2_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
Monocycle_Road_EventScript_Josito2::
	trainerbattle_single TRAINER_JOSITO_2, Josito2_AntesBatalla, Josito2_MensajeDerrota
	msgbox Josito2_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
Monocycle_Road_EventScript_MirorB::
	lockall
	faceplayer
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox MirorB_AntesBatalla, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_MIRORB, MirorB_MensajeDerrota
	msgbox MirorB_DespuesDeBatalla_Text
	closemessage
	applymovement 9, Monocycle_Road_Movement_MirorBSpin
	waitmovement 0
	playse SE_W100
	applymovement 9, Monocycle_Road_Movement_MirorBJumpaway
	waitmovement 0
	setflag FLAG_DARKI_GYM_READY
	removeobject 9
	setflag FLAG_MIRORB_DEFEATED
	releaseall
	end
	
Monocycle_Road_Movement_MirorBSpin:
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	step_end

Monocycle_Road_Movement_MirorBJumpaway:
	face_up
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

MirorB_AntesBatalla:
	.string "¡Estás delante de una estrella,\n"
	.string "hoy estás de suerte! ¡Muy pocos\l"
	.string "tienen el honor de conocer en\l"
	.string "persona al gran MIROR B.!\p"
	
	.string "¡Rrrrrrrrrrittmo!\p"

	.string "¡Llegó la hora de quitarme este\n"
	.string "disfraz, y comenzar a bailar al\l"
	.string "ritmo de la música!\p"
	
	.string "¡¡¡SALSAAAAAAAAAA!!!$"

MirorB_MensajeDerrota: 
	.string "¡Que pare la música! ¡Serás inútil!\p" 
	
	.string "A estas alturas, ¡deberías saber que\n"
	.string "te conviene seguir mis pasos!\l" 
	.string "¡Por tu culpa he perdido el ritmo!$"

MirorB_DespuesDeBatalla_Text:
	.string "¡No puedo contigo!\n" 
	.string "Me repatea que me venzas.\p"
	
	.string "¿Eso es ser fan, eh, eh?\n" 
	.string "Por esta vez voy a hacer la vista gorda.\l" 
	.string "Pero ¡que no se repita!\p" 
	.string "¡Hala! ¡Bueno! ¡Huyamos!$"

Josito2_AntesBatalla:
	.string "Tú y mi osito verde ya os habéis\n" 
	.string "encontrado antes, ¿me recuerdas?$"

Josito2_MensajeDerrota: 
	.string "GGs, que vayan bien las próximas.$"
 
Josito2_DespuesDeBatalla:
	.string "Tremendo equipo te has montado,\n"
	.string "aunque los míos molan más.$"
	
Dunk2_AntesBatalla:
	.string "¿Me recuerdas? Soy DUNK, nos vimos en\n"
	.string "SKY PILLAR cuando fuiste a ver a\l"
	.string "RAYQUAZA.\p"

	.string "Te dije que no hay ningún cambio\n" 
	.string "climático, y al final el tiempo me dió\l"
	.string "la razón.\p"

	.string "Pero ahora estoy aquí por otro asunto\n"
	.string "bastante distinto. Estoy reclutando\l" 
	.string "gente para echar abajo por fin a la\l"
	.string "dictadura Smogonita.\p"
	
	.string "SMOGON ha quedado corrompido por dar\n"
	.string "asilo a personas de tan mala calaña, y\l"
	.string "además los Bans de POKéMON que realizan\l" 
	.string "cada vez son más incongruentes. Parece\l"
	.string "que no saben hacer otra cosa que perder\l"
	.string "el tiempo de sus vidas jugando\l" 
	.string "STALL 6vs6, y es como si hubiesen\l" 
	.string "convertido el juego en un FANGAME\l" 
	.string "a la carta.\p"

	.string "Para ello necesitamos formar una nueva\n"
	.string "comunidad en la que jugaremos combates\l"
	.string "rápidos 3vs3 con las reglas\l" 
	.string "de GAMEFREAK.\p"
	
	.string "¡Así que demuéstrame que sabes hacer!$"

Dunk2_MensajeDerrota: 
	.string "Tienes mucho potencial, ¿por qué no\n"
	.string "te unes a nosotros?$"  
 
Dunk2_DespuesDeBatalla:
	.string "Ya te lo he dicho, los de SMOGON han\n"
	.string "perdido totalmente el norte.\p"
	
	.string "Al final solo nos queda jugar al\n"
	.string "metagame original de GAMEFREAK.$"
	
Monocycle_Road_Sign_Text:
	.string "MONOCYCLE ROAD: Móntate en el\n"
	.string "ACROCYCLE y usa el B + Dirección\l"
	.string "para atravesar todos los caminos.\p"
	
	.string "Y recuerda: Monociclo, porque\n" 
	.string "mono es uno y la vida es un ciclo.$"
	
BlueYellow_AntesBatalla:
	.string "YELLOW: Gran amiga BLUE, ¿me estás\n"
	.string "oyendo? Oh vamos, BLUE, ¡ahora no te\l"
	.string "hagas la tonta! ¿Recuerdas esa foto en\l"
	.string "la que saliste tan sexy como modelo de\l"
	.string "cierta marca de ropa de cierto\l"
	.string "catálogo de moda?\p"
	
	.string "Mi amiga BLUE es modelo, ¿sabes?\n"
	.string "No dejaré que se acerque a ella ningún\l"
	.string "baboso ni nadie que pueda hacerle algo\l"
	.string "malo.\p"

	.string "BLUE: Amiga YELLOW, se te ve\n"
	.string "eufórica, baja un poco de las nubes que\l"
	.string "mi vida privada no tiene porque saberla\l"
	.string "nadie.$"

BlueYellow_MensajeDerrota: 
	.string "YELLOW: Perdón, amiga BLUE.$"  
 
BlueYellow_DespuesDeBatalla:
	.string "BLUE: Conozco de sobra los extremos a\n"
	.string "los que puede llegar un chico, no solo\l"
	.string "las fotos. La ropa interior que dejas\l"
	.string "en el cesto de la ropa sucia que\l"
	.string "desaparece, la que puedes dejar\l"
	.string "tendida al sol para que se seque y\l"
	.string "después encontrarla toda arrugada y\l"
	.string "con una rara mancha que desprende un\l"
	.string "desagradable olor.\p"
	
	.string "YELLOW: ¡Debe ser leche desnatada!$"
	
Monocycle_Road_Text_BlueNotEnoughMons:
	.string "BLUE: Si no tienes dos POKéMON,\n"
	.string "no podemos luchar.\p"
	
	.string "¡Solo aceptamos BATALLAS DOBLES!$"
	
Monocycle_Road_Text_YellowNotEnoughMons:
	.string "YELLOW: Pero si no tienes ni dos\n"
	.string "POKéMON listos para luchar...\p"
	
	.string "¡Solo luchamos BATALLAS DOBLES!$"

MrZero_AntesBatalla: 
	.string "Si te preguntasen si te gusta más\n" 
	.string "ENTEI, RAIKOU, o SUICUNE,\l"
	.string "¿cuál dirías, tú?\p"
	
	.string "Para mi es ENTEI porque me gustan\n"
	.string "los de tipo PLANTA.$" 

MrZero_MensajeDerrota: 
	.string "¡Pero si ENTEI es de tipo PLANTA!$"  
 
MrZero_DespuesDeBatalla:
	.string "¿No te gustan los de tipo PLANTA\n"
	.string "como ENTEI?\p"
	
	.string "Por cierto, me han dicho que LUGIA\n"
	.string "es de tipo AGUA, ¿es cierto?$"
	
Zzz_AntesBatalla: 
	.string "¡¡¡SENSEI RED KROW!!!\p"
	
	.string "¡¡¡DÓNDE ESTÁS SENSEI RED KROW!!!\p"

	.string "Eh, tú, ¿has visto a mi sensei\n"
	.string "por aquí?$"

Zzz_MensajeDerrota: 
	.string "¡Qué decepción para mi sensei!$"  
 
Zzz_DespuesDeBatalla:
	.string "Mi sensei RED KROW era el único\n"
	.string "que aceptaba todos mis retos\l"
	.string "diarios con mi MONOTIPO NORMAL.\p"
	
	.string "Nadie más.$"
	
PoisonMastahhhh_AntesBatalla: 
	.string "Io creo que el megor monotipaso\n" 
	.string "es el veneno poque tiene al\l" 
	.string "tosicroa ese que se cura cuando\l" 
	.string "le lansan agua y ase mucho daño,\l" 
	.string "tamien tienes al dripiñon que no\l"
	.string "le afestan los atacasos de tierra$"

PoisonMastahhhh_MensajeDerrota: 
	.string "Pero el megor monotipaso...$"  
 
PoisonMastahhhh_DespuesDeBatalla:
	.string "El megor monotipaso es el veneno\n"
	.string "te pongas como te pongas.\p"
	
	.string "Un saludo y muy buen floro.$"

Monocycle_Road_Text_Constructor:
	.string "MICOLO ha pagado a mi empresa\n"
	.string "para que se encargue de construir\l" 
	.string "la mejor carretera de monociclos\l"
	.string "que has visto jamás.\p"
	
	.string "¿Por qué no retas algún GYM mientras\n"
	.string "tanto, para hacer tiempo?$"
