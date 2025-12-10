Darkigym_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, Darkigym_Onload
	.byte 0
	
Darkigym_Onload::
    call_if_defeated TRAINER_DARKI_BUENRO, Darkigym_DisableBuenroTrigger
    end

Darkigym_DisableBuenroTrigger:
    setvar VAR_TEMP_0, 1
    return

Darkigym_EventScript_ParedInvisible1::
	lock
	faceplayer
	special HasDefeatedAllDarkiGymTrainersZone1
	compare VAR_RESULT, TRUE
	goto_if_eq Darkigym_EventScript_ParedInvisible1_Parte2
	msgbox Darkigym_ParedInvisible_Text_1, MSGBOX_DEFAULT
Darkigym_EventScript_ParedInvisible1_Parte1:
	release
	return

Darkigym_EventScript_ParedInvisible1_Parte2:
	msgbox Darkigym_ParedInvisible_Text_0, MSGBOX_DEFAULT
    removeobject 35
    removeobject 36
	setflag FLAG_HIDE_PAREDINVISIBLE_1_DARKI_GYM
	goto Darkigym_EventScript_ParedInvisible1_Parte1

Darkigym_EventScript_ParedInvisible2::
	lock
	faceplayer
	special HasDefeatedAllDarkiGymTrainersZone2
	compare VAR_RESULT, TRUE
	goto_if_eq Darkigym_EventScript_ParedInvisible2_Parte2
	msgbox Darkigym_ParedInvisible_Text_1, MSGBOX_DEFAULT
Darkigym_EventScript_ParedInvisible2_Parte1:
	release
	return

Darkigym_EventScript_ParedInvisible2_Parte2:
	msgbox Darkigym_ParedInvisible_Text_0, MSGBOX_DEFAULT
    removeobject 37
    removeobject 38
    removeobject 39
    removeobject 40
	setflag FLAG_HIDE_PAREDINVISIBLE_2_DARKI_GYM
	goto Darkigym_EventScript_ParedInvisible2_Parte1
	
Darkigym_EventScript_ParedInvisible3::
	lock
	faceplayer
	special HasDefeatedAllDarkiGymTrainersZoneFinal
	compare VAR_RESULT, TRUE
	goto_if_eq Darkigym_EventScript_ParedInvisible3_Parte2
	msgbox Darkigym_ParedInvisible_Text_1, MSGBOX_DEFAULT
Darkigym_EventScript_ParedInvisible3_Parte1:
	release
	return

Darkigym_EventScript_ParedInvisible3_Parte2:
	msgbox Darkigym_ParedInvisible_Text_0, MSGBOX_DEFAULT
    removeobject 41
    removeobject 42
    removeobject 43
	setflag FLAG_HIDE_PAREDINVISIBLE_3_DARKI_GYM
	goto Darkigym_EventScript_ParedInvisible3_Parte1

    @ Combate contra totem.
Darkigym_EventScript_Totem::
	lockall
	msgbox DesafiarTotem_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Darkigym_EventScript_Totem2
	releaseall
	end

Darkigym_EventScript_Totem2::
	playmoncry SPECIES_TYRANITAR, 2
	delay 40
	waitmoncry
	msgbox Darkigym_Text_Totemaparece, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_TYRANITAR
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
	removeobject 3
	setflag FLAG_TOTEM_GYMDARKI
    msgbox Darkigym_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.

Darkigym_EventScript_GymStatue_Sign::
	lockall
	goto_if_set FLAG_DEFEATED_DARKI_GYM, Darkigym_EventScript_GymStatueCertified
	goto Darkigym_EventScript_GymStatue
	end

Darkigym_EventScript_GymStatueCertified::
	msgbox Darkigym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

Darkigym_EventScript_GymStatue::
	msgbox Darkigym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end
	
Darkigym_EventScript_Darkibuenro_Trigger1::
	goto_if_set FLAG_DEFEATED_DARKIBUENRO_GYM, Darkigym_EventScript_Darkibuenro_Trigger1continue2
	lockall
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
    @ Estas instrucciones hacen que el jugador mire arriba. Al activarlas, ocurre un bug que hace que el jugador mire abajo al llegar a la instruccion trainerbattle_single de Darkigym_EventScript_Buenro
    @applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceUp
    @waitmovement 0
	msgbox Darkigym_Text_BuenroIntro, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Darkigym_EventScript_Buenro
	goto Darkigym_EventScript_Darkibuenro_Trigger1continue
	end
	
Darkigym_EventScript_Darkibuenro_Trigger1continue::
	applymovement EVENT_OBJ_ID_PLAYER, Darkigym_Movement_Prota
	waitmovement 0
	releaseall
	end
	
Darkigym_Movement_Prota:
	walk_down
	step_end
	
Darkigym_EventScript_Darkibuenro_Trigger1continue2::
	releaseall
	end
	
Darkigym_EventScript_Buenro::
	goto_if_set FLAG_DEFEATED_DARKIBUENRO_GYM, Darkigym_EventScript_BuenroDefeated2
	trainerbattle_single TRAINER_DARKI_BUENRO, Darkigym_Text_BuenroIntro2, Darkigym_Text_BuenroDefeat, Darkigym_EventScript_BuenroDefeated, NO_MUSIC
	releaseall
	end
	
Darkigym_EventScript_Malro::
	goto_if_set FLAG_DEFEATED_DARKI_GYM, Darkigym_EventScript_Darki_Derrotado
	trainerbattle_single TRAINER_DARKI_MALRO, Darkigym_Text_MalroIntro, Darkigym_Text_MalroDefeat, Darkigym_EventScript_MalroDefeated, NO_MUSIC
	release
	end
	
Darkigym_EventScript_MalroDefeated::
	msgbox Darkigym_Text_MalroPostBattle, MSGBOX_DEFAULT
	waitmessage
	message Darkigym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox Darkigym_Text_ExplainBadgeTakeThis, MSGBOX_DEFAULT
	delay 30
	msgbox Darkigym_Text_MalroPostBattle2, MSGBOX_DEFAULT
	@ Level Cap Item
	delay 30
	playse SE_PIN
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	playfanfare MUS_ME_B_BIG
	waitfanfare
	playse SE_PC_OFF
	msgbox LevelCapItem_Text_GymDarki, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, ITEM_LEVEL_CAP
	bufferitemname 0, VAR_0x8004
    removeitem VAR_0x8004
	delay 30
	@ Level Cap Item	
	setflag FLAG_DEFEATED_DARKI_GYM
	release
	end
	
Darkigym_EventScript_Darki_Derrotado::
	goto_if_set FLAG_REMATCH_DARKIMALRO, Darkigym_EventScript_Malro_DarkiRematch
	faceplayer
	lock
	msgbox Darkigym_Text_MalroPostBattle2, MSGBOX_DEFAULT
	release
	end
	
Darkigym_EventScript_Malro_DarkiRematch::
	trainerbattle_single TRAINER_DARKI_MALRO, Darkigym_Text_DarkiMalroRematchIntro, Darkigym_Text_DarkiMalroRematchDefeat, Darkigym_EventScript_DarkiMalroRematchDefeated, NO_MUSIC
	release
	end
	
Darkigym_EventScript_DarkiMalroRematchDefeated::
	msgbox Darkigym_Text_MalroPostBattle3, MSGBOX_DEFAULT
	clearflag FLAG_REMATCH_DARKIMALRO
	release
	end

Darkigym_EventScript_BuenroDefeated::
	msgbox Darkigym_Text_BuenroPostBattle, MSGBOX_DEFAULT
	special HealPlayerParty
	setflag FLAG_DEFEATED_DARKIBUENRO_GYM
    setvar VAR_TEMP_0, 1
	releaseall
	end
	
Darkigym_EventScript_BuenroDefeated2::
	goto_if_set FLAG_DEFEATED_DARKI_GYM, Darkigym_EventScript_Buenro_DarkiDerrotado
	lock
	faceplayer
	msgbox Darkigym_Text_BuenroPostBattle2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Darkigym_EventScript_Heal
	release
	end
Darkigym_EventScript_Heal::
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty
	msgbox Darkigym_Text_BuenroPostBattleHeal, MSGBOX_DEFAULT
	release
	end
	
Darkigym_EventScript_Buenro_DarkiDerrotado::
	goto_if_set FLAG_REMATCH_DARKIBUENRO, Darkigym_EventScript_Buenro_DarkiRematch
	lock
	faceplayer
	msgbox Darkigym_Text_BuenroPostBattle3, MSGBOX_DEFAULT
	release
	end
	
Darkigym_EventScript_Buenro_DarkiRematch::
	trainerbattle_single TRAINER_DARKI_BUENRO, Darkigym_Text_DarkiBuenroRematchIntro, Darkigym_Text_DarkiBuenroRematchDefeat, Darkigym_EventScript_DarkiBuenroRematchDefeated, NO_MUSIC
	release
	end
	
Darkigym_EventScript_DarkiBuenroRematchDefeated::
	msgbox Darkigym_Text_BuenroPostBattle3, MSGBOX_DEFAULT
	clearflag FLAG_REMATCH_DARKIBUENRO
	release
	end
	
Darkigym_EventScript_Teleport_Entrada::
	goto_if_set FLAG_DEFEATED_DARKI_GYM, Darkigym_EventScript_Teleport_Si
	msgbox Darkigym_Text_Teleport_Entrada, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Darkigym_EventScript_Teleport_Si
	release
	end
Darkigym_EventScript_Teleport_Si::
	warp MAP_DARKIGYM, 0, 0, 0
	waitstate
	release
	end
	
Darkigym_EventScript_Teleport_Final::
	goto_if_set FLAG_TOTEM_GYMDARKI, Darkigym_EventScript_Teleport_Final_Encendido
	msgbox Darkigym_Text_Teleport_Final, MSGBOX_DEFAULT
	release
	end
Darkigym_EventScript_Teleport_Final_Encendido::
	warp MAP_DARKIGYM, 48, 0, 0
	waitstate
	release
	end
	
Darkigym_CabezaLylie_Sign::
	msgbox Darkigym_Text_CabezaLylie_Sign, MSGBOX_SIGN
	end

Darkigym_PCDarki_Sign::
	msgbox Darkigym_Text_PCDarki_Sign, MSGBOX_SIGN
	end
	
Darkigym_CartaMagma1_Sign::
	msgbox Darkigym_Text_CartaMagma1_Sign, MSGBOX_SIGN
	end
	
Darkigym_CartaMagma2_Sign::
	msgbox Darkigym_Text_CartaMagma2_Sign, MSGBOX_SIGN
	end
	
Darkigym_MaquinaMeteorito_Sign::
	msgbox Darkigym_Text_MaquinaMeteorito_Sign, MSGBOX_SIGN
	end
	
Darkigym_VitrinaIzquierda_Sign::
	msgbox Darkigym_Text_VitrinaIzquierda_Sign, MSGBOX_SIGN
	end
	
Darkigym_VitrinaDerecha_Sign::
	msgbox Darkigym_Text_VitrinaDerecha_Sign, MSGBOX_SIGN
	end
	
Darkigym_EventScript_RedSecretaria::
	trainerbattle_single TRAINER_ESBIRRO_DARKI_1, Darkigym_Text_RedSecretariaIntro, Darkigym_Text_RedSecretariaDefeat
	msgbox Darkigym_Text_RedSecretariaPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Kizarde::
	trainerbattle_single TRAINER_ESBIRRO_DARKI_2, Darkigym_Text_KizardeIntro, Darkigym_Text_KizardeDefeat
	msgbox Darkigym_Text_KizardePostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Espi::
	trainerbattle_single TRAINER_ESBIRRO_DARKI_3, Darkigym_Text_EspiIntro, Darkigym_Text_EspiDefeat
	msgbox Darkigym_Text_EspiPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Mobu::
	trainerbattle_single TRAINER_ESBIRRO_DARKI_4, Darkigym_Text_MobuIntro, Darkigym_Text_MobuDefeat
	msgbox Darkigym_Text_MobuPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Roxy::
	trainerbattle_single TRAINER_ESBIRRO_DARKI_5, Darkigym_Text_RoxyIntro, Darkigym_Text_RoxyDefeat
	msgbox Darkigym_Text_RoxyPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Anthony::
	trainerbattle_single TRAINER_ANTHONYPXP, Darkigym_Text_AnthonyIntro, Darkigym_Text_AnthonyDefeat
	msgbox Darkigym_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Dranix::
	trainerbattle_single TRAINER_DRANIX, Darkigym_Text_DranixIntro, Darkigym_Text_DranixDefeat
	msgbox Darkigym_Text_DranixPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Umbreon123::
	trainerbattle_single TRAINER_UMBREON123, Darkigym_Text_Umbreon123Intro, Darkigym_Text_Umbreon123Defeat
	msgbox Darkigym_Text_Umbreon123PostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Ultramagic::
	trainerbattle_single TRAINER_ULTRA_MAGIC, Darkigym_Text_UltramagicIntro, Darkigym_Text_UltramagicDefeat
	msgbox Darkigym_Text_UltramagicPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Charz::
	trainerbattle_single TRAINER_CHARZ, Darkigym_Text_CharzIntro, Darkigym_Text_CharzDefeat
	msgbox Darkigym_Text_CharzPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_FurryTrainerdelpasado::
	trainerbattle_single TRAINER_FURRY, Darkigym_Text_FurryIntro, Darkigym_Text_FurryDefeat
	msgbox Darkigym_Text_FurryPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_DarkMelkorOtraDimension::
	trainerbattle_single TRAINER_DARK_MELKOR, Darkigym_Text_DarkMelkorIntro, Darkigym_Text_DarkMelkorDefeat
	msgbox Darkigym_Text_DarkMelkorPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_FanboyKalos_DimensionZ::
	trainerbattle_single TRAINER_FANBOY_KALOS, Darkigym_Text_FanboyKalosIntro, Darkigym_Text_FanboyKalosDefeat
	msgbox Darkigym_Text_FanboyKalosPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_AngelFS::
	trainerbattle_single TRAINER_ANGELFS, Darkigym_Text_AngelFSIntro, Darkigym_Text_AngelFSDefeat
	msgbox Darkigym_Text_AngelFSPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Yume::
	trainerbattle_single TRAINER_YUME, Darkigym_Text_YumeIntro, Darkigym_Text_YumeDefeat
	msgbox Darkigym_Text_YumePostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_TiloAlola::
	trainerbattle_single TRAINER_TILO_ALOLA, Darkigym_Text_TiloAlolaIntro, Darkigym_Text_TiloAlolaDefeat
	goto_if_set FLAG_DEFEATED_TILO, Darkigym_EventScript_Tilo_Derrotado
	msgbox Darkigym_Text_TiloAlolaPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_DEFEATED_TILO
	giveitem ITEM_REVIVE, 10
	compare VAR_RESULT, FALSE
	call_if_eq Darkigym_EventScript_BagFull
	closemessage
	end
	
Darkigym_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	return
	
Darkigym_EventScript_Tilo_Derrotado::
	msgbox Darkigym_Text_TiloAlolaPostBattle2, MSGBOX_NPC
	release
	end

DarkiGym_EventScript_TeleportFeature::
	lock
	msgbox DarkiGym_EventScript_TeleportFeature_Text_0, MSGBOX_NPC
	msgbox DarkiGym_EventScript_TeleportFeature_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DarkiGym_EventScript_TeleportFeature_1
	msgbox DarkiGym_EventScript_TeleportFeature_Text_3, MSGBOX_NPC
	return

DarkiGym_EventScript_TeleportFeature_1:
	msgbox DarkiGym_EventScript_TeleportFeature_Text_2, MSGBOX_NPC
	warp MAP_MICOLANDIA_POKEMON_CENTER1F, 0, 0, 0
	return


DarkiGym_EventScript_TeleportFeature_Text_0:
	.string "El loco de este GIMNASIO ha logrado\n"
	.string "distorsionar el espacio-tiempo. Sí,\l"
	.string "como en SINNOH, irónico.\p"
	.string "Cambios de sexo, desapariciones de\n"
	.string "monturas de SURF, imposibilidad de\l"
	.string "utilizar WATERFALL para subir la\l"
	.string "cascada... esos son algunos de los\l"
	.string "efectos de todo este caos...\p"
	.string "Sí, son FEATURES, no BUGS. De todas\n"
	.string "formas, si crees estar atascado en el\l"
	.string "GIMNASIO debido a una de estas\l"
	.string "FEATURES, puedo teletransportarte\l"
	.string "fuera del recinto. Con suerte tus\l"
	.string "problemas se arreglarán.\p"
	.string "Con suerte.$"

DarkiGym_EventScript_TeleportFeature_Text_1:
	.string "¿Quieres que te teletransporte fuera\n"
	.string "del GIMNASIO?$"

DarkiGym_EventScript_TeleportFeature_Text_2:
	.string "Midele te salve, reina, llena eres de\n"
	.string "autismo, el Mico es contigo.\p"
	.string "Bendita tu eres, entre todas las\n"
	.string "mideles, y bendito es el fruto de tu\l"
	.string "vientre, DARK PIKA.\p"
	.string "Santa Midele, madre de Micolo, ruega por\n"
	.string "nosotros, micoleadores, ahora y en la\l"
	.string "hora de nuestros bugs.\p"
	.string "DORIME.$"

DarkiGym_EventScript_TeleportFeature_Text_3:
	.string "Cagaste, wey.$"

	
Darkigym_Text_RedSecretariaIntro: 
	.string "¿Espera, eres un humano?\p"

	.string "No se supone que los humanos\n" 
	.string "corrientes puedan rondar en este\l"
	.string "pedazo del inframundo.\p"

	.string "Supongo que tienes una cita o algo\n" 
	.string "coon mi señor...\p"

	.string "¿Que no la tienes?\p"

	.string "Bueno, espero que vinieras aquí buscando\n" 
	.string "una muerte horrible.\p"

	.string "Porque nadie ve a mi jefe el mal rollo\n" 
	.string "sin una cita previa.$" 
	
Darkigym_Text_RedSecretariaDefeat: 
	.string "¿Pero qué mier...?$"

Darkigym_Text_RedSecretariaPostBattle:
	.string "¿Cómo me has... ganado?\p"

	.string "Tsk...Malditas sean las reglas de\n"
	.string "este mundo.\p"

	.string "Te habría llenado todos los esfínteres\n" 
	.string "con granadas y volado en mil pedazos,\l" 
	.string "si no fuera por este asqueroso y\l"
	.string "opresor ambiente family friendly.\p"

	.string "Prosigue, ya avisé a mi amo de que vas\n" 
	.string "en camino.\p"

	.string "No tiene fe de que llegues ante él,\n"
	.string "pero si eres tan gilipollas como para\l" 
	.string "haber llegado hasta aquí, solo\l" 
	.string "te resta avanzar.$"
	
Darkigym_Text_KizardeIntro: 
	.string "¡Alto ahí! Pequeña ardilla,\n"
	.string "¿cómo osas entrar en la guarida\l"
	.string "del gran cientifico loco\l"
	.string "D. KIZARDE?\p"

	.string "Fu wa ja ja ja ja ja ja ja ja ja$"

Darkigym_Text_KizardeDefeat:
	.string "¡Oh, no! ¡Debes de ser un agente enviado\n" 
	.string "por la organización!\p"

	.string "¡Vienen tras mi último invento!$"

Darkigym_Text_KizardePostBattle:
	.string "Maravíllate, pequeña ardilla,\n"
	.string "ante la máquina de viaje espacio\l"
	.string "temporal.\p"

	.string "¿Sin ella, como crees que nuestros jefes\n" 
	.string "pueden viajar a tantos mundos?\p"

	.string "Solo un genio como yo,\n"
	.string "el miembro número uno del laboratorio\l"
	.string "de inventos subterráneos.\p"

	.string "El cientifico loco D. KIZARDE,\n"
	.string "podría haber inventado tan\l" 
	.string "impresionante máquina. ¡Mua ja ja!\p"

	.string "Ya que me ganaste te contaré un\n"
	.string "secreto.\p"

	.string "Esta máquina la creé con el fin de\n" 
	.string "evitar la tercera guerra\l" 
	.string "interdimensional.\p"

	.string "En la que GOOSES junto a las brujas\n" 
	.string "del destino, busca oprimir a toda la\l"
	.string "humanidad con su ejército de\l" 
	.string "lolis waifus.\p"

	.string "Siendo el detonante... un tal MASUDA.\p"

	.string "El cual dio a luz a Lilie para controlar\n"
	.string "las mentes de todos aquellos niños que\l" 
	.string "según él, no tienen tiempo para jugar\l"
	.string "más que juegos cortitos de movil...\p"

	.string "¿Sabes? Veo en ti el poder de\n"
	.string "cambiar el futuro.\p"

	.string "Vamos, sigue adelante y demuéstrale a\n"
	.string "nuestro jefe, que puedes hacerlo, y\l" 
	.string "salvarnos a todos de tan\l" 
	.string "aciago destino.$"
	
Darkigym_Text_EspiIntro: 
	.string "Hola, intruso.\n"
	.string "¿Wuieres jugar conmigo?$"

Darkigym_Text_EspiDefeat: 
	.string "Repámpanos, se acabó el juego.$"

Darkigym_Text_EspiPostBattle:
	.string "Es una lástima, yo quería seguir jugando\n"
	.string "si te ganaba y mataba.\p"

	.string "Podría haberte añadido a mi colección\n" 
	.string "de cadáveres.\p"

	.string "Y de hecho tengo bastante repetida a\n" 
	.string "cierta niña rubia.\p"

	.string "¿Qué? ¿Te creías que todas estas tumbas\n" 
	.string "son de adorno?\p"

	.string "Nope... son todas de los enemigos de mi\n" 
	.string "señor que me ha mandado a despedazar\l" 
	.string "con mi guadaña, jia jajajajaja$"
	
Darkigym_Text_MobuIntro: 
	.string "...............$"

Darkigym_Text_MobuDefeat: 
	.string "Ah.. ¿Eh? ¿Qué ha pasado?$"

Darkigym_Text_MobuPostBattle:
	.string "Ah... disculpa, creo que me volví a\n" 
	.string "descontrolar durante mi entrenamiento.\p"

	.string "Aún no logro dominar mi estado 100%...\p"

	.string "Aunque mi maestro el buen rollo, dice\n" 
	.string "que ya logro hacer muchas cosas sin\l" 
	.string "necesidad de usar mis poderes\l" 
	.string "psíquicos.\p"

	.string "Como sea... siento una gran fuerza en\n" 
	.string "ti ¿Qué buscas aquí?\p"

	.string "¿Dices que estás buscando la medalla\n" 
	.string "del gimnasio?\p"

	.string "¿Que no te da miedo el líder?\p"

	.string "I-increíble, ojalá pudiera ser tan\n" 
	.string "valiente como tú.\p"

	.string "Bueno, mucha suerte, entrenador,\n" 
	.string "te animaré desde aquí.$"
	
Darkigym_Text_RoxyIntro: 
	.string "Vaya, así que eres la persona que\n" 
	.string "ha montado tanto revuelo.\p"

	.string "....\p"

	.string "No pareces la gran cosa.\p"

	.string "No sé por que los demás se han\n" 
	.string "dejado vencer por ti.\p"

	.string "Oh, bueno, supongo que deberé\n" 
	.string "pararte ahora.\p"

	.string "Pelearé por el honor del inframundo y la\n"
	.string "felicidad de mis hermanos, por lo que ni\l" 
	.string "de coña puedo permitirme perder.\p" 

	.string "¿READY?$" 
	
Darkigym_Text_RoxyDefeat: 
	.string "Lo siento... MALRO y BUENRO...$"

Darkigym_Text_RoxyPostBattle:
	.string "Rayos.\p"

	.string "Ahora entiendo por qué has llegado\n" 
	.string "hasta aquí.\p"

	.string "Por lo que veo también dominas el\n" 
	.string "poder de la determinación.\p"

	.string "Supongo que entonces no necesito usar\n" 
	.string "toda mi fuerza, así que puedes pasar.\p"

	.string "Quién sabe, con algo de suerte lograrás\n" 
	.string "tranquilizar al mal rollo.\p"

	.string "No lo entiendo muy bien, pero, eso de\n" 
	.string "jugar con las líneas del tiempo,\l" 
	.string "no me mola.\p"

	.string "Adelante, humano, y recuerda:\p"

	.string "Por horrible y oscuro que se torne\n"
	.string "tu camino, nunca dejes de caminar.$"
	
Darkigym_Text_AnthonyIntro:
	.string "No hay nada mejor que los taladros.\p"
	
	.string "¿Quieres saber por qué?\n"
	.string "Pues...\p"
	
	.string "Preparate para mi...\n"
	.string "GIGA\l" 
	.string "DRILL\l" 
	.string "BREAKEEEEEEEEEEEEEEEEEEEEEEEEER.$"

Darkigym_Text_AnthonyDefeat: 
	.string "¡Taladro roto!$"

Darkigym_Text_AnthonyPostBattle:
	.string "Mírate Tengen Toppa Gurren-Lagann.\p"
	
	.string "Solo así sabrás el verdadero\n"
	.string "significado de los taladros y de mi\l"
	.string "técnica definitiva:\p"
	
	.string "¡GIGA DRILL BREAKER!$"
	
Darkigym_Text_DranixIntro:
	.string "Espero que hayas traído Autan...\p"
	
	.string "¡Porque tu cuerpo será acribillado\n"
	.string "por las picaduras de mi ejército\l"
	.string "definitivo de BEEDRILLs!$"

Darkigym_Text_DranixDefeat: 
	.string "¡Noooo! Mis preciosos BEEDRILLs...$"

Darkigym_Text_DranixPostBattle:
	.string "¡Pero BEEDRILL tiene que ser un\n"
	.string "OU como sea!\p"
	
	.string "¡Necesitamos más gente llevando\n"
	.string "a BEEDRILL en su equipo!\p"
	
	.string "Mmm... mejor actualizaré la TIER LIST\n"
	.string "para que se así sea.$"
	
Darkigym_Text_Umbreon123Intro:
	.string "MEEEELKOR... MAAAAALDITO...\n"
	.string "MEEEELKOR.\p"
	
	.string "MEEEELKOR, me baneaaaaste, me\n"
	.string "cambiaaaaste el texto personal y firma.\p"
	
	.string "Pusiste que soy un troll sin gracia y\n"
	.string "que me gusta el flood y el spam.\p"
	
	.string "Y me diste -100 Karma... como a ningún\n"
	.string "otro usuario.\p"
	
	.string "MEEEELKOR, ME HUMILLAAAAASTE.\p"
	
	.string "MEEEELKOR.........$"

Darkigym_Text_Umbreon123Defeat: 
	.string "MAAAAAALDITO...$"

Darkigym_Text_Umbreon123PostBattle:
	.string "MEEEEELKOR, ME VENGAREEEEEEEEE.$"
	
Darkigym_Text_UltramagicIntro:
	.string "¡Ey DOOD!\n"
	.string "¿Conoces a LAVENDER?\p"

	.string "¡La POLICÍA de JOHTO lo está\n" 
	.string "buscando! ¡Y a mí también, DOOD!\p"
	
	.string "¡Un momento, esto no son las carataras\n"
	.string "TOHJO!\p"

	.string "¡Todo esto es muy raro! ¿¡QUÉ ESTÁ\n"
	.string "PASANDO AQUÍ, DOOD?!$"

Darkigym_Text_UltramagicDefeat: 
    .string "You are all DOOD!$"

Darkigym_Text_UltramagicPostBattle:
	.string "¡Hey, DOOD! ¡Eres fuerte!\p"

	.string "¿Conoces a LAVENDER también?\n"
	.string "Uy, ehm... yo no conozco a NACHO.\l"
	.string ":dood:$"
	
Darkigym_Text_CharzIntro:
	.string "Humanos fuertes...\p"

	.string "Humanos débiles...\p"
	
	.string "Esa es la visión egoísta que rige\n" 
	.string "nuestro mundo.\p"
	
	.string "¿Pero acaso hay algún problema\n"
	.string "con ello?\p"
	
	.string "¡Por supuesto que NO!\p"
	
	.string "Los seres humanos somos egoístas por\n"
	.string "naturaleza, aunque vivamos en una\l"
	.string "sociedad con unas reglas autoimpuestas\l"
	.string "que evitan que los verdaderos...\l"
	.string "superhumanos, lo más fuertes, como yo,\l"
	.string "triunfemos siempre.\p"

	.string "Un humano débil no sirve para nada,\n"
	.string "solo nos hace a todos más\l"
	.string "manipulables.\p"
	
	.string "Pero...\p"
	
	.string "Si pudiésemos tirar abajo este maldito\n"
	.string "sistema caduco que ya está apunto\l" 
	.string "de explotar...\p"

	.string "La humanidad por fin conseguiría\n" 
	.string "alcanzar su mayor plenitud porque\l" 
	.string "solo sobreviviríamos los más fuertes\l" 
	.string "de todos.\p"
	
	.string "Por ello, debo eliminar a todos los\n"
	.string "débiles como tu.\p" 
	.string "Selección Natural, lo llamo.$"

Darkigym_Text_CharzDefeat: 
	.string "¿SELECCIÓN NATURAL?\p"
	
	.string "¡¡¡NOOOOOOOOOOOOOOOOO!!!$"

Darkigym_Text_CharzPostBattle:
	.string "Tienes demasiado poder...\p"
	
	.string "Deberías unirte a nosotros, podríamos\n"
	.string "conseguir grandes cosas contigo a\l"
	.string "nuestro lado.\p"
	
	.string "...\p"
	
	.string "Oh, venga, ¡Vamos! ¡Únete!\p"
	
	.string "¡Humanos fuertes vivirán!\p"

	.string "¡Humanos débiles morirán!\p"
	
	.string "¡Tenemos que romper este sistema\n"
	.string "caduco!\p"
	
	.string "¡Debemos demostrar al mundo que solo\n"
	.string "lo más fuertes deben sobrevivir!$"
	
Darkigym_Text_FurryIntro:
	.string "Sniff... sniff...\n"
	.string "¡Este lugar apesta a hacks!\p"
	
	.string "Estaba tan tranquilo en la ROUTE 46\n"
	.string "de JOHTO, cuando de pronto vi abrirse\l"
	.string "una especie de portal que me absorbió\l"
	.string "y me trajo a este lugar tan oscuro.\p"
	
	.string "¡Alguien debe haber usado POKéHEX para\n"
	.string "cambiar las coordenadas de mi\l" 
	.string "localización!\p" 

	.string "¡¡¡ESTO ES UN HACKEO PELIGROSO!!!\n" 
	.string "¡¿ME OYES?!\p"
	
	.string "...\p"
	
	.string "Sniff... Sniff...\n"
	.string "¡Tú también hueles a hacks...!\p" 

	.string "¡MALDITOS HACKERS! ¡OS VAIS A ENTERAR!\p"
	
	.string "Mandaré un aviso a NOENTIENDO para que\n" 
	.string "os baneen para siempre.$"

Darkigym_Text_FurryDefeat: 
	.string "Voy a llamar a NOENTIENDO ¡YA!\p"
	
	.string "En cuanto consiga cobertura...$"

Darkigym_Text_FurryPostBattle:
	.string "¡La gente aquí debe tener hackeado\n"
	.string "el cerebro!\p"
	
	.string "¿Te puedes creer que el FURRY que\n"
	.string "conocen se corrompió ante los HACKs,\l"
	.string "se unió al bando de MICOLO y toda esa\l"
	.string "chusma, y se fue de JOHTO para luego\l"
	.string "convertirse en un PIRATA?\p"
	
	.string "¡ESTÁN MINTIENDO! ¡YO NUNCA CAERÍA\n" 
	.string "TAN BAJO!\p"
	
	.string "Será mejor que avise a MICO...\n"
	.string "quiero decir... ehm... a MELKOR, eso.\p"
	
	.string "¡YA QUE ES MI TRABAJO COMO POLICIA\n"
	.string "MANTENER A LOS HACKERS A RAYA!\p"
	
	.string "¡ACABARÉ YO MISMO CON TODOS ELLOS!\n"
	.string "IN JUSTICE WE TRUST!$"
	
Darkigym_Text_DarkMelkorIntro:
	.string "¡DARKNESS! ¡DARKNESS! ¡DARKNESS!\p"

	.string "Interesante... ¡Qué interesante es\n"
	.string "este mundo!\p"
	
	.string "Vengo de un mundo en el que dejé atrás\n"
	.string "parte de mi humanidad para converger\l"
	.string "junto a la oscuridad.\p"
	
	.string "¡SÍ! ¡DARKNESS! ¡DARKNESS! ¡DARKNESS!\p"

	.string "¡Y claro, que valió la pena!\p"

	.string "¡Aplasté con mis propias manos a ese...\n" 
	.string "maldito webmaster de SEREBII!\p"
	
	.string "¡Nunca le perdoné que fastidiase mi\n"
	.string "gran exclusiva de los nombres POKéMON\l" 
	.string "de 5ªGENERACIÓN!\p"
	
	.string "...\p"
	
	.string "¡Ahora debo convencer al MELKOR de\n"
	.string "este mundo para que se una a mí para\l"
	.string "salvar la SAGA POKéMON de las garras\l"
	.string "de MASUDA!\p"
	
	.string "¡Tenemos que impedir que borre toda la\n"
	.string "POKéDEX!\p"
	
	.string "Pero antes, debo librarme de ti.$"

Darkigym_Text_DarkMelkorDefeat: 
	.string "¡DARKNESS! ¡DARKNESS! ¡DARKNESS!\p"
	
	.string "Aunque lo parezca, no soy un producto\n" 
	.string "de NOMURA.$"

Darkigym_Text_DarkMelkorPostBattle:
	.string "¡DARKNESS! ¡DARKNESS! ¡DARKNESS!\p"

	.string "Mmm... ese portal del que vine me\n" 
	.string "ha hecho perder a la mitad del equipo,\l"
	.string "pero parece que ya no puedo volver.\p"
	
	.string "...\p"
	
	.string "¿Qué es ese portal, dices?\p"

	.string "No te sabría decir, pero parece ser\n"
	.string "que alguien está alterando el equilibrio\l"
	.string "del espacio-tiempo, lo que está\l"
	.string "provocando la apertura de portales\l"
	.string "interdimensionales que está trayendo\l" 
	.string "a gentes de otros mundos.\p"
	
	.string "¡Un invento maravilloso!\n" 
	.string "¡Tal vez tengamos una oportunidad para\l"
	.string "abatir el futuro mal que se cierne\l"
	.string "sobre nosotros!\p"
	
	.string "¡SALVEMOS LA SAGA POKéMON DE LAS GARRAS\n"
	.string "DE MASUDA!$"
	
Darkigym_Text_FanboyKalosIntro:
	.string "No tengo ni la más remota idea de donde\n"
	.string "estoy, ¡pero qué importa!\l"
	.string "¡VIVA LA 6ªGEN! ¡VIVA POKéMON Z!\p"

	.string "¿CÓMO? ¿QUÉ ES POKéMON Z?\p"
	
	.string "¡PERO CÓMO PUEDES NO SABERLO! ¡SI ES EL\n"
	.string "MEJOR JUEGO QUE HA SACADO GAMEFREAK\l"
	.string "EN TODOS ESTOS AÑOS!\p"
	
	.string "¿HAS ESTADO VIVIENDO EN UNA CUEVA\n" 
	.string "O QUÉ?\p"
	
	.string "¡EJEM!\n"
	.string "Déjame explicarte las maravillas de\l" 
	.string "POKéMON Z.\p"
	
	.string "Se trata de la secuela de POKéMON XY,\n"
	.string "y tiene lugar 3 años después, en la\l"
	.string "región de KALOS, pero esta vez todo\l" 
	.string "toma lugar en KALOS SUR.\p"
	
	.string "LYSSON sobrevivió, y vuelve a ser\n" 
	.string "nuestro mayor enemigo, con un plan B:\l" 
	.string "Ha conseguido fusionar a todos los\l" 
	.string "ZYGARDES 1% en uno solo, formando el\l"
	.string "ZYGARDE FORMA COMPLETA 100%.\p"
	
	.string "También hace su aparición VOLCANION,\n" 
	.string "y el juego tiene un contenido POSTGAME\l" 
	.string "fabuloso e inmenso.\p"
	
	.string "El único pero, es que no tiene ningún\n"
	.string "FRENTE BATALLA.\p"
	
	.string "...\p"

	.string "¿¡PERO QUÉ DICES?!\n" 
	.string "¿¡CÓMO QUÉ NI POKéMON Z, NI KALOS\l" 
	.string "SUR EXISTEN?!\p"

	.string "¡YA ME HE CANSADO DE QUE TE BURLES\n" 
	.string "DE MÍ!$"

Darkigym_Text_FanboyKalosDefeat: 
	.string "¿PERO QUÉ...?\p"
	
	.string "¿Por qué mi MAWILE no puede...\n"
	.string "megaevolucionar con su Megapiedra\l"
	.string "usando mi Megaanillo?$"

Darkigym_Text_FanboyKalosPostBattle:
	.string "¡Espera! ¿Este no es mi mundo?\n"
	.string "¿Aquí no hay POKéMON Z...?\l"
	.string "¿Tampoco KALOS SUR...?\p"
	
	.string "Pero entonces... ¿Qué hay aquí\n"
	.string "después de POKéMON XY?\p"
	
	.string "¿REMAKES DE RSE SIN FRENTE?\n"
	.string "¿POKéMON SOL y LUNA?\l"
	.string "¿ALOLA? ¿ROTOMDEX?\l"
	.string "¿POKéMON LETS GO PIKACHU y EEVEE?\l"
	.string "¿POKéMON ESPADA y ESCUDO con la\l"
	.string "eliminación de la mitad de la Dex?\l"
	.string "¿DINAMAX? ¿GIGAMAX?\l"
	.string "¿DLC a 30 euros y POKéMON HOME cuatro\l"
	.string "veces más caro que POKéBANCO?\p"

	.string "¡ESTE MUNDO ES UNA MIERDA!$"
	
Darkigym_Text_AngelFSIntro:
	.string "Mire estoy en 1 de secundaria y las\n" 
	.string "16 niñas de mi salon me tratan como\l"
	.string "alfombre osea me aserco y se alejan\l" 
	.string "o gritan: AAAAAA quitate!!!\p"

	.string "y con todas es igual.\n" 
	.string "Que demonios hago!!$"

Darkigym_Text_AngelFSDefeat: 
    .string "Ahora las niñas gritarían:\n" 
	.string "AAAAAA quitate!!!$"

Darkigym_Text_AngelFSPostBattle:
	.string "¡Las niñas ya no están!\p"

	.string "No me volverán a tratar como\n"
	.string "alfombre. :)$"
	
Darkigym_Text_YumeIntro:
	.string "Ahora eres mi nuevo Onichan y estás\n" 
	.string "para untarle al pan.\p" 
	
	.string "¡ji ji ji!$"

Darkigym_Text_YumeDefeat: 
	.string "Vamos, anda, déjame darte una\n" 
	.string "mordidita, no seas malo.\p"

	.string "¡Waaaaaaaaaaaa!$" 

Darkigym_Text_YumePostBattle:
	.string "Bueno, tendré que buscar a un nuevo\n" 
	.string "Onichan, estarás contento, ojalá que\l" 
	.string "el señor MALRO te aplaste.\p" 
	
	.string "¡ji ji ji!$"
	
Darkigym_Text_TiloAlolaIntro:
	.string "¡Alola, entrenador!\p"

	.string "Qué agradable clima hoy...\p"

	.string "Pero no tanto como mi querida y\n" 
	.string "natal ALOLA con toda esa alegría,\l"
	.string "felicidad, sol y buen clima...\p"

	.string "¿Quieres que comparta mi entusiasmo\n" 
	.string "contigo con un par de buenas\l" 
	.string "malasadas?\p"

	.string "Porque sabes, las malasadas son el mejor\n" 
	.string "manjar del mundo, riquísimas,\l" 
	.string "impedirbles.\p"

	.string "Ven, ven, combatamos un poquito, cuando\n" 
	.string "me ganes, te regalaré 10 revivires.$"

Darkigym_Text_TiloAlolaDefeat: 
	.string "¡Wow, eres super fuerte, increible,\n" 
	.string "una máquina, nunca tuve una\l" 
	.string "oportunidad de conoc...!$"

Darkigym_Text_TiloAlolaPostBattle:
	.string "¡Quién diría que me encontraría con\n" 
	.string "una persona tan increíble como tú!\p"
	
	.string "¿Que nos acabamos de conocer? Da igual,\n" 
	.string "soy tu más grande admira-\l" 
	.string "AAAAAAAAAAARG!!!!\p"

	.string "¡NO, NO, PERDÓNEME, SEÑOR MALROLLO!\n" 
	.string "¡NOOOOOOOOO!\p"
	
	.string "................................\p"
	
	.string "(Coges los 10 REVIVE que te iba a dar)$"
	
Darkigym_Text_TiloAlolaPostBattle2:
	.string "................................$"

Darkigym_Text_MalroIntro: 
	.string "Así que lograste llegar hasta aquí.\p"
	
	.string "Je, patética criatura, ¿así que\n" 
	.string "tu eres la mierdecilla que se metió\l" 
	.string "en mi guarida para acabar con\l" 
	.string "mis planes?\p"
	
	.string "Había oido que en este mundo los\n" 
	.string "niños son los que cortan el bacalao.\p"

	.string "Pero sabrás... que yo DARKIZARD, el\n" 
	.string "señor del inframundo, el buscador del\l" 
	.string "caos, el hater definitivo, aquel que\l" 
	.string "sumirá a este y todos los mundos que\l"
	.string "osan molestarme con su estupidez en la\l" 
	.string "más angustiosa desesperación y horror\l"
	.string "¿Crees acaso que una pulga\l"
	.string "insignificante como TÚ, por más que sea\l"
	.string "el protagonista podrá contra mi? ¡JA!\p"

	.string "Creo que pronto verás la gravedad de\n" 
	.string "tu error al venir aquí...$"

Darkigym_Text_MalroDefeat: 
	.string "Me cago en tu vida y en tus muertos\n" 
	.string "pulga, ¿cómo es esto siquiera posible?\p"

	.string "Derrotado por una criatura... todos\n" 
	.string "mis planes, arruinados.$"

Darkigym_Text_MalroPostBattle:
	.string "¿Es que no lo entiendes?\p"

	.string "Todo esto de viajar en el tiempo fue\n" 
	.string "para matar al imbécil de MASUDA.\p"
	
	.string "¡En este punto de la historia él es\n"
	.string "quien se convierte en el dios de tu\l" 
	.string "mundo, y lo que vendrá después será\l"
	.string "horrible, SINNOH, LILIA, y hasta matará\l" 
	.string "a la mitad de los POKéMON existentes!\p"
	
	.string "Su soberbia, codicia y estupidez hará\n" 
	.string "sufrir a muchas personas...\p"

	.string "Ahora que sabes esto...\n" 
	.string "¡¿Aún así me expulsarás?!\p"

	.string ".....\p"

	.string "No... no le estoy hablando a esa carcasa\n" 
	.string "vacía a la que controlas...\p"

	.string "Tu jugador... sí, el imbecil que se\n" 
	.string "habrá gastado 40 horas de su vida o más\l"
	.string "en jugar este Hackrom.\p"

	.string "Aún no es tarde, incluso un torpe como\n" 
	.string "tu me puede ser útil, sí.\p"
	
	.string "Encuentra a MASUDA y pártele la boca\n"
	.string "por mí.\p"

	.string "Si un insignificante ser como tú, pudo\n" 
	.string "ganarme a mí, quizás tu suerte sea la\l" 
	.string "clave para destruir a ese dictador,\l"
	.string "y quién sabe, hasta podrías invocar a\l" 
	.string "una leyenda y todo si tienes suerte\l"
	.string "fu fu fu.\p"
	
	.string "Y antes que se me olvide, toma,\n" 
	.string "la MEDALLA DETERMINACIÓN, como prueba\l" 
	.string "de que sabes usar el buen y el mal rollo\l" 
	.string "para superar todos los obstáculos que\l" 
	.string "se te presenten, lo necesitarás para\l" 
	.string "vencer a ese capullo.$"

Darkigym_Text_MalroPostBattle2:
	.string "¿Sigues aquí?\p"

	.string "¡Largo!, ve y dale una PALIZA a ese\n" 
	.string "idiota de MASUDA por los dos.\p"
	
	.string "Si lo metes dentro de un VICTREEBEL o le\n" 
	.string "estampes un MIMIKYU en la cara.\l"
	.string "Tanto mejor.\p"
	
	.string "¿Ah... que quieres que te lleve de\n" 
    .string "vuelta a la entrada?\p"

    .string "Pues te jodes, te devuelves a pie,\n" 
    .string "tómalo como mi venganza por atreverte\l" 
    .string "a ganarme fu fu fu.\p"

    .string ".....\p"

    .string "¡Demonios, eso también me\n"
	.string "lo prohibieron!\p"

    .string "Bueno... te dejaré usar una cuerda huida\n"
    .string "o algo, estarás agradecido...$"
	
Darkigym_Text_MalroPostBattle3:
	.string "¿Sigues aquí?\p"

	.string "¡Largo!, ve y dale una PALIZA a ese\n" 
	.string "idiota de MASUDA por los dos.\p"
	
	.string "Si lo metes dentro de un VICTREEBEL o le\n" 
	.string "estampes un MIMIKYU en la cara.\l"
	.string "Tanto mejor.$"

Darkigym_Text_BuenroIntro:
	.string "¡OH! ¡Genialoso, un invitado!\p"

	.string "Espera, esas ropas... tú no eres\n"
	.string "un invitado, ¡eres EL humano!\p"

	.string "Me han dicho que debo capturarte.\p"

	.string "Si te dejo a tus anchas podrías echar\n" 
	.string "todos sus planes por tierra.\p"

	.string "Además este sitio es muy peligroso, solo\n" 
	.string "alguien igual de genialoso como yo\l"
	.string "podría atravesarlo y salir indemne.\p"
	
	.string "¿Insistes en seguir? ¿Te has preparado\n"
	.string "para hacerme frente en un combate?$"
	
Darkigym_Text_BuenroIntro2:
	.string "Bueno, supongo que YO, el gran DARKIZARD,\n" 
	.string "el todo poderoso buen rollo,\l" 
	.string "Capitán de la guardia imperial del\l" 
	.string "inframundo y co-líder de este gimnasio,\l"
	.string "tendré que detenerte aquí y ahora.\p"

	.string "Nyeh heh heh heh$" 
	
Darkigym_Text_BuenroDefeat:
	.string "Vaya, sí que eres fuerte,\n"
	.string "tienes mi respeto.$"

Darkigym_Text_BuenroPostBattle:
	.string "Ahora te espera la más genial de mis\n"
	.string "creaciones y me la encargó nada más ni\l" 
	.string "nada menos que mi hermano el Mal Rollo.\p"

	.string "Él quería que construyera una mazmorra\n" 
	.string "que les hiciera sentir el horror y la\l"
	.string "desesperación que es transitar por\l" 
	.string "aquellos agónicos sitios.\p"

	.string "Que son: ALOLA y SINNOH.\p"

	.string "Que para mí no estan TAAAAN mal como dice\n"
	.string "MALRO, pero bueno, como decía.\p"

	.string "Para un amante de los puzzles como yo,\n"
	.string "no podría contentarme con hacer solo\l" 
	.string "un pasillo simplón en el que se\l" 
	.string "avanzara muy lentamente.\p"

	.string "Así que hice un pasillo en el que\n" 
	.string "avanzas muy lentamente, te puedes\l"
	.string "extraviar para siempre y te asalten\l" 
	.string "todo tipo de trampas mortales\l" 
	.string "meticulosamente colocadas para\l" 
	.string "enviarte directo a un CENTRO POKéMON.\p"
	
	.string "Nyeh heh heh.\p"

	.string "Te advierto, solo un verdadero amante\n" 
	.string "de los Puzzles y las mazmorras con\l" 
	.string "la más férrea de las voluntades podrá\l"
	.string "superarlo.\p"

	.string "No te preocupes, si pudiste vencerme\n" 
	.string "a mí, al gran DARKIZARD, esta mazmorra\l" 
	.string "de la desesperación no sera nada\l"
	.string "para ti.\p"

	.string "Nyehehehe\p"

	.string "En especial por que ese tal RAGU, mejoró\n" 
	.string "las MO, ¡mecachis!\p"

	.string "¡Ánimo y mucha suerte!\p"

	.string "Te advierto, te enfrentarás con el rey\n" 
	.string "del inframundo y gobernante de todos\l" 
	.string "los monstruos.\p"

	.string "¡Sus tormentas de arena y aura siniestra\n" 
	.string "son legendarias!\p"

	.string "Vinimos aquí a llevar a cabo una\n" 
	.string "operación que asegurará la salvación de\l" 
	.string "esta rama de las lineas del mundo.\p"
	
	.string "¿A que es todo un cacho de pan,\n"
	.string "malrollo?\p"

	.string "Estoy seguro que te agradará.\n"
	.string "Nyeh heh heh\p"

	.string "Oh, veo que tu equipo está decaído,\n"
	.string "te curaré.\p"
	
	.string "Tanto mejor, pero ten en cuenta que\n"
	.string "para superar este gymnasio debes tener\l"
	.string "a tu disposición POKéMON que puedan usar\l"
	.string "ROCK SMASH, STRENGTH, SURF y WATERFALL.\p"
	
	.string "Nyeh heh heh\p"
	
	.string "Sigue adelante, humano,\n" 
	.string "no pierdas la determinación.$"

Darkigym_Text_BuenroPostBattle2:
	.string "Ten en cuenta que para superar este\n"
	.string "gymnasio debes tener a tu disposición\l"
	.string "POKéMON que puedan usar ROCK SMASH,\l"
	.string "STRENGTH, SURF y WATERFALL.\p"
	.string "Oh, ¿Quieres que cure a tu equipo?$"

Darkigym_Text_BuenroPostBattleHeal:
	.string "Tanto mejor.\n"
	.string "Nyeh heh heh\p"
	
	.string "Sigue adelante, humano,\n" 
	.string "no pierdas la determinación.$"
	
Darkigym_Text_BuenroPostBattle3:
	.string "Así que nos derrotaste a ambos, a\n"
	.string "BUENRO, osea yo, y a MALRO, es decir,\l"
	.string "mi hermano.\p"

	.string "¡La próxima vez te venceré!\n"
	.string "Nyeh heh heh$"

Darkigym_Text_ReceivedBadge:
	.string "{PLAYER} recibió la MEDALLA\n"
	.string "DETERMINACIÓN de DARKIZARD.$"

Darkigym_Text_ExplainBadgeTakeThis:
	.string "Con esta MEDALLA en tu poder, desde\n"
	.string "ahora mismo... todo POKéMON\l" 
	.string "intercambiado obedecerá todas tus\l"
	.string "ordenes, incluso aunque sean...\l"
	.string "moralmente reprochables.\p"
	
	.string "¡Je! ¡Qué patético!\p"

	.string "Y debido a que ya tienes la última\n"
	.string "medalla, podrás participar en\l"
	.string "la MICOLIGA.$"
	
Darkigym_Text_GymStatue:
	.string "POKéMON GYM Nº4\n"
	.string "LEADER: DARKIZARD\l"
	.string "“TEMÁTICA: MAL ROLLO Y BUENROLLO”$"

Darkigym_Text_GymStatueCertified:
	.string "POKéMON GYM Nº4\n"
	.string "LEADER: DARKIZARD\l"
	.string "“TEMÁTICA: MAL ROLLO Y BUENROLLO”\p"

	.string "DARKIZARD'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
	
Darkigym_Text_Teleport_Entrada:
	.string "Si usas esta baldosa teletransporte\n"
	.string "volverás a la entrada y tendrás que\l"
	.string "recorrer todo desde el principio.\p"
	
	.string "¿Estás seguro que quieres usarla?$"
	
Darkigym_Text_Teleport_Final:
	.string "Parece que la baldosa no hace nada.$"

Darkigym_Text_Totemaparece:
	.string "TYRANITAR, the TOTEM POKéMON of\n"
	.string "DARKI GYM, has appeared!$"
	
Darkigym_Text_Totemderrotado:
	.string "TYRANITAR disappeared...$"
	
Darkigym_Text_CabezaLylie_Sign:
	.string "Parece la cabeza disecada de una niña\n" 
	.string "rubia y de ojos verdes, una expresion\l" 
	.string "de agonía eterna deforma su cara...$"

Darkigym_Text_PCDarki_Sign:
	.string "Aquí hay un correo: Operación Hades en\n" 
	.string "proceso, se necesitan grandes dosis de\l" 
	.string "autismo, la máquina del tiempo, entre\l" 
	.string "otras herramientas han facilitado\l" 
	.string "la obtencion de efectivos para\l" 
	.string "enfrentarnos a un gran mal que se ciñe\l" 
	.string "sobre todos nostros, si todo sale bien\l" 
	.string "lograremos reunir suficiente autismo de\l" 
	.string "este mundo como para evitarlo.\p"
	
	.string "MICOLO y el pingüino no tienen por que\n" 
	.string "sospechar nada... $"
	
Darkigym_Text_MaquinaMeteorito_Sign:
	.string "Una máquina que parece micro-ondas, con\n"
	.string "una placa que dice:\p"

	.string "Invento futurista numero X.Y22 máquina\n" 
	.string "de saltos temporales nombre sujeto\l" 
	.string "a revisión.$"
	
Darkigym_Text_CartaMagma1_Sign:
	.string "Es una invitación de un tal MICOLO a\n"
	.string "distintas personas para que defiendan\l" 
	.string "su guarida como líderes de gimnasio.\p"
	
	.string "El final está marcado con una pata\n" 
	.string "de pingüino...$"
	
Darkigym_Text_CartaMagma2_Sign:
	.string "Querido Señor MICOLO:\p"
	.string "Yo y mi hermano MALRO, estaremos\n" 
	.string "complacidos de ser líderes de gimnasio\l" 
	.string "de su liga autista.\p"
	
	.string "MALRO esta especialmente emocionado,\n" 
	.string "dice algo que todo entra en sus planes,\l" 
	.string "pero no le haga mucho caso, simplemente\l" 
	.string "le gusta mucho fingir que es un villano,\l" 
	.string "por lo que puede contar con nosotros.$"
	
Darkigym_Text_VitrinaIzquierda_Sign:
	.string "Se ve una lanza color púrpura oscuro\n" 
	.string "con un ojo ensangrentado que te\l" 
	.string "mira fijamente.$"
	
Darkigym_Text_VitrinaDerecha_Sign:
	.string "Una pila de huesos en una caja que tiene\n" 
	.string "escrito a un lado: buenos recuerdos$"
	
Darkigym_ParedInvisible_Text_0:
	.string "Has vencido a todos los entrenadores\n"
	.string "de esta zona, puedes pasar.$"

Darkigym_ParedInvisible_Text_1:
	.string "Debes vencer a todos los entrenadores\n"
	.string "de esta zona para poder seguir adelante.$"
	
Darkigym_Text_DarkiBuenroRematchIntro:
    .string "¿Qué pasa? ¿Te dio la nostalgia\n"
	.string "y quieres otra batalla contra mi?\p"

	.string "Bueno, no te preocupes,\n"
	.string "YO el gran DARKIZARD,\l" 
	.string "el todo poderoso buen rollo,\l" 
	.string "Capitán de la guardia imperial del\l" 
	.string "inframundo y co-líder de este gimnasio,\l"
	.string "aceptará tu reto.\p"
	
	.string "Nyeh heh heh heh$" 

Darkigym_Text_DarkiBuenroRematchDefeat:
	.string "¡Muy divertido!\n"
	.string "Nyeh heh heh heh$"
	
Darkigym_Text_DarkiMalroRematchIntro:
    .string "¿Qué pasa? ¿Te dio instintos suicidas\n"
	.string "y quieres otra batalla contra mi?\p"

	.string "¡JAJAJAJAJAJAJA!\p"

	.string "¡YO, DARKIZARD, el\n" 
	.string "señor del inframundo, el buscador del\l" 
	.string "caos, el hater definitivo, aquel que\l" 
	.string "sumirá a este y todos los mundos que\l"
	.string "osan molestarme con su estupidez en la\l" 
	.string "mas angustiosa desesperación y horror,\l"
	.string "hará realidad tu deseo!$" 

Darkigym_Text_DarkiMalroRematchDefeat:
	.string "¡Debemos derrotar juntos a MASUDA!$"
	
LevelCapItem_Text_GymDarki:
	.string "LEVEL CAP: Actualización completada.\n"
	.string "Te liberaste de las cadenas que te\l"
	.string "autolimitaban, por lo que ahora tus\l"
	.string "POKéMON pueden llegar al nivel 100.\p"
	
	.string "¡El objeto LEVEL CAP desapareció!$"
