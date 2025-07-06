MicoloHideout_ExperimentRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MicoloHideout_ExperimentRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MicoloHideout_ExperimentRoom_OnTransition
	.byte 0
	
MicoloHideout_ExperimentRoom_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MicoloHideout_ExperimentRoom_EventScript_TryRemoveMewtwo
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MicoloHideout_ExperimentRoom_EventScript_TryRemoveRegieleki
	end

MicoloHideout_ExperimentRoom_EventScript_TryRemoveMewtwo::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MicoloHideout_ExperimentRoom_EventScript_TryRemoveRegieleki::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MicoloHideout_ExperimentRoom_OnTransition:
	call_if_unset FLAG_CAUGHT_MEWTWO, MicoloHideout_ExperimentRoom_EventScript_TryShowMewtwo
	call_if_unset FLAG_CAUGHT_REGIELEKI, MicoloHideout_ExperimentRoom_EventScript_TryShowRegieleki
	end

MicoloHideout_ExperimentRoom_EventScript_TryShowMewtwo::
	goto_if_set FLAG_DEFEATED_MEWTWO, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MEWTWO
	return

MicoloHideout_ExperimentRoom_EventScript_TryShowRegieleki::
	goto_if_set FLAG_DEFEATED_REGIELEKI, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_REGIELEKI
	return
	
MicoloHideout_ExperimentRoom_EventScript_Mewtwo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEWTWO, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_MEWTWO, 70, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_DefeatedMewtwo
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_RanFromMewtwo
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_RanFromMewtwo
	setflag FLAG_CAUGHT_MEWTWO
	release
	end

MicoloHideout_ExperimentRoom_EventScript_DefeatedMewtwo::
	setflag FLAG_DEFEATED_MEWTWO
	goto Common_EventScript_RemoveStaticPokemon
	end

MicoloHideout_ExperimentRoom_EventScript_RanFromMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway
	end

MicoloHideout_ExperimentRoom_EventScript_Regieleki::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIELEKI, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIELEKI, 40, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_DefeatedRegieleki
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_RanFromRegieleki
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_RanFromRegieleki
	setflag FLAG_CAUGHT_REGIELEKI
	release
	end

MicoloHideout_ExperimentRoom_EventScript_DefeatedRegieleki::
	setflag FLAG_DEFEATED_REGIELEKI
	goto Common_EventScript_RemoveStaticPokemon
	end

MicoloHideout_ExperimentRoom_EventScript_RanFromRegieleki::
	setvar VAR_0x8004, SPECIES_REGIELEKI
	goto Common_EventScript_LegendaryFlewAway
	end

MicoloHideout_ExperimentRoom_EventScript_LegendaryMachine::
	lock
	msgbox MicoloHideout_ExperimentRoom_Text_LegendaryMachineUse, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineEnd
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineNoRoom

	msgbox MicoloHideout_ExperimentRoom_Text_LegendaryMachineChooseMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineEnd
	
	special IsSelectedMonLegendary
	compare VAR_RESULT, FALSE
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineNotLegendary
	playse SE_TK_WARPIN
	msgbox MicoloHideout_ExperimentRoom_Text_LegendaryMachineReceivedMon, MSGBOX_DEFAULT
	waitse
	setflag FLAG_SHINY_CREATION
	giveEgg VAR_0x8005
	clearflag FLAG_SHINY_CREATION
MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineEnd:
	release
	end

MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineNoRoom:
	msgbox MicoloHideout_ExperimentRoom_Text_LegendaryMachineNoRoom, MSGBOX_DEFAULT
	release
	end

MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineNotLegendary:
	msgbox MicoloHideout_ExperimentRoom_Text_LegendaryMachineNotLegendary, MSGBOX_DEFAULT
	release
	end
	
MicoloHideout_ExperimentRoom_EventScript_Javisoto2::  
	trainerbattle_single TRAINER_JAVISITO_POSTGAME, MicoloHideout_ExperimentRoom_Text_Javisoto2Intro, MicoloHideout_ExperimentRoom_Text_Javisoto2Defeat
	msgbox MicoloHideout_ExperimentRoom_Text_Javisoto2PostBattle, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_ExperimentRoom_EventScript_Uta::  
	trainerbattle_single TRAINER_UTALAWEA, MicoloHideout_ExperimentRoom_Text_UtaIntro, MicoloHideout_ExperimentRoom_Text_UtaDefeat
	msgbox MicoloHideout_ExperimentRoom_Text_UtaPostBattle, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_ExperimentRoom_EventScript_CursedSlowbro::  
	trainerbattle_single TRAINER_SLOWBRO, MicoloHideout_ExperimentRoom_Text_CursedSlowbroIntro, MicoloHideout_ExperimentRoom_Text_CursedSlowbroDefeat
	msgbox MicoloHideout_ExperimentRoom_Text_CursedSlowbroPostBattle, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_LavaRoom_EventScript_LAEX::
	trainerbattle_double TRAINER_LAEX, MicoloHideout_ExperimentRoom_Text_LAEXIntro, MicoloHideout_ExperimentRoom_Text_LAEXDefeat, MicoloHideout_ExperimentRoom_Text_LAEX_MasdeunPokemon
	msgbox MicoloHideout_ExperimentRoom_Text_LAEXPostBattle, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_ExperimentRoom_Text_LAEXIntro: 
	.string "¡¡¡Abriste el spoiler!!!\p" 
	.string "Ahora tendrás pesadillas con Sulley\n"
	.string "y la chochomburguesa.$"
	
MicoloHideout_ExperimentRoom_Text_LAEXDefeat: 
	.string "Esto es peor que lo del HIPPOPOTAS...$"

MicoloHideout_ExperimentRoom_Text_LAEXPostBattle: 
	.string "Bueno, me tengo que ir a cuidar de\n"
	.string "mi hermana, que es la sobrina de mi\l"
	.string "hermano, el cuñado de mi padre...$"
	
MicoloHideout_ExperimentRoom_Text_LAEX_MasdeunPokemon: // BATALLA DOBLE
	.string "Así que solo llevas un Pokémon?\n"
	.string "No puedo luchar contigo, entonces.\p"

	.string "Mi estrategia es solo para las\n"
	.string "BATALLA DOBLE.$"

MicoloHideout_ExperimentRoom_Text_CursedSlowbroIntro: 
	.string "Ser... O no ser...\n"
	.string "Esa es la cuestión.\p"

	.string "Soy un SLOWBRO y al mismo tiempo\n"
	.string "no soy un SLOWBRO.\p"
	
	.string "No soy un ENTE, pero tampoco\n"
	.string "soy un ULTRAENTE.\p"

	.string "Solo soy un experimento fallido de\n"
	.string "MICOLO que vaga sin rumbo por este\l"
	.string "lugar sin tener un rumbo\l" 
	.string "por donde vagar.\p"

	.string "Por lo que soy un maldito ERROR que\n"
	.string "no debería existir por ser\l" 
	.string "un maldito ERROR.\p"

	.string "Los conceptos en sí mismos no tienen\n"
	.string "significado, la intención que imprimes\l" 
	.string "en el concepto, le da significado.\p"

	.string "Las contradicciones... no existen.\n" 
	.string "La coherencia... no existe.\p"

	.string "Puede ser verdad, puede ser mentira.\n"
    .string "El tiempo dirá lo que es o lo que no es.\p"
	
	.string "Nada tiene sentido, y al mismo tiempo\n"
	.string "todo puede tener sentido.\p"
	
    .string "Al estar en desventaja soy una víctima,\n"
	.string "pero al mostrar poder...\l" 
	.string "¡Te convierto en víctima!$"	

MicoloHideout_ExperimentRoom_Text_CursedSlowbroDefeat: 
	.string "¡Mejor vida es morir que vivir muerto!\p"

	.string "¡¡¡KILL ME, PLEASE!!!$"

MicoloHideout_ExperimentRoom_Text_CursedSlowbroPostBattle: 
	.string "He sufrido mucho, y cada día sufro más,\n" 
	.string "ni te imaginas cuanto más puedo sufrir.\p"

	.string "Mas esto ya no es necesario,\n" 
	.string "me voy de este lugar.\p"
	
	.string "Antes de irme sí debo decir\n" 
	.string "que la mayoría son idiotas,\l" 
	.string "y que los idiotas son mayoría.\p"

	.string "Me han atacado, y cuando yo ataco\n"
	.string "me quieren sancionar, siendo que\l" 
	.string "al resto no han sancionado.$"

MicoloHideout_ExperimentRoom_Text_Javisoto2Intro: 
	.string "Buenas, ¿cuándo harán el evento de\n" 
	.string "la Flauta Azur y del Floette Eterno?\p" 
	
	.string "Aún estoy esperando estos eventos.$"

MicoloHideout_ExperimentRoom_Text_Javisoto2Defeat: 
	.string "Y algo me dice que aún tengo que\n" 
	.string "esperar mas.$"

MicoloHideout_ExperimentRoom_Text_Javisoto2PostBattle: 
	.string "Supongo que no puedo esperar mucho\n" 
	.string "de aquellos que arruinaron POKéMON\l" 
	.string "y monetizaron los shinys, y todos\l"
	.string "sabemos que también arruinarán Sinnoh.$"
	
MicoloHideout_ExperimentRoom_Text_UtaIntro: 
	.string "No deberías molestarte en combatir.\n"
	.string "Ya sé como acabará.$"

MicoloHideout_ExperimentRoom_Text_UtaDefeat: 
	.string "Me cago en tu puta madre.$"

MicoloHideout_ExperimentRoom_Text_UtaPostBattle: 
	.string "El resultado fue el que esperaba.\n"
	.string "Lo planeé desde el principio.$"

MicoloHideout_ExperimentRoom_Text_LegendaryMachineUse:
	.string "Hay un programa abierto en el PC.\p"
	.string "“Programa de crianza de legendarios\n"
	.string "100% legal n.n”\p"
	.string "¿Lo utilizas?$"

MicoloHideout_ExperimentRoom_Text_LegendaryMachineChooseMon:
	.string "Elige un POKéMON legendario.$"

MicoloHideout_ExperimentRoom_Text_LegendaryMachineReceivedMon:
	.string "¡Has obtenido un HUEVO de legendario!$"

MicoloHideout_ExperimentRoom_Text_LegendaryMachineNoRoom:
	.string "No tienes espacio en el equipo.$"

MicoloHideout_ExperimentRoom_Text_LegendaryMachineNotLegendary:
	.string "El POKéMON que has elegido no es un\n"
	.string "POKéMON legendario.$"

MicoloHideout_ExperimentRoom_Experiment1::
	msgbox MicoloHideout_ExperimentRoom_Experiment1_Text_0, MSGBOX_SIGN
	return


MicoloHideout_ExperimentRoom_Experiment2::
	msgbox MicoloHideout_ExperimentRoom_Experiment2_Text_0, MSGBOX_SIGN
	return


MicoloHideout_ExperimentRoom_Experiment3::
	msgbox MicoloHideout_ExperimentRoom_Experiment3_Text_0, MSGBOX_SIGN
	return


MicoloHideout_ExperimentRoom_Experiment4::
	msgbox MicoloHideout_ExperimentRoom_Experiment4_Text_0, MSGBOX_SIGN
	return


MicoloHideout_ExperimentRoom_Experiment5::
	msgbox MicoloHideout_ExperimentRoom_Experiment5_Text_0, MSGBOX_SIGN
	return


MicoloHideout_ExperimentRoom_Experiment6::
	msgbox MicoloHideout_ExperimentRoom_Experiment6_Text_0, MSGBOX_SIGN
	return


MicoloHideout_ExperimentRoom_Experiment7::
	msgbox MicoloHideout_ExperimentRoom_Experiment7_Text_0, MSGBOX_SIGN
	return


MicoloHideout_ExperimentRoom_Scientist1::
	msgbox MicoloHideout_ExperimentRoom_Scientist1_Text_0, MSGBOX_NPC
	return


MicoloHideout_ExperimentRoom_Scientist2::
	msgbox MicoloHideout_ExperimentRoom_Scientist2_Text_0, MSGBOX_NPC
	return


MicoloHideout_ExperimentRoom_Scientist3::
	msgbox MicoloHideout_ExperimentRoom_Scientist3_Text_0, MSGBOX_NPC
	return


MicoloHideout_ExperimentRoom_Experiment1_Text_0:
	.string "EXPERIMENTO FALLIDO N1$"

MicoloHideout_ExperimentRoom_Experiment2_Text_0:
	.string "EXPERIMENTO FALLIDO N2$"

MicoloHideout_ExperimentRoom_Experiment3_Text_0:
	.string "EXPERIMENTO FALLIDO N3$"

MicoloHideout_ExperimentRoom_Experiment4_Text_0:
	.string "CLON N1: GROUDON$"

MicoloHideout_ExperimentRoom_Experiment5_Text_0:
	.string "CLON N2: KYOGRE$"

MicoloHideout_ExperimentRoom_Experiment6_Text_0:
	.string "CLON N3: RAYQUAZA$"

MicoloHideout_ExperimentRoom_Experiment7_Text_0:
	.string "CLON DE MEW N12$"

MicoloHideout_ExperimentRoom_Scientist1_Text_0:
	.string "¿Q-quién eres? ¿Cómo has llegado hasta\n"
	.string "aquí?\p"
	.string "N-no me hagas nada, yo solo sigo las\n"
	.string "órdenes de MICOLO...\p"
	.string "Mira, hagamos un trato. Si me dejas en\n"
	.string "paz, te dejaré utilizar ese PC de ahí.\p"
	.string "Es la última creación de MICOLO, con él\n"
	.string "podrás criar POKéMON legendarios...$"

MicoloHideout_ExperimentRoom_Scientist2_Text_0:
	.string "¿Que qué hay en esa sala de ahí? Es\n"
	.string "donde hemos almacenado a todos los\l"
	.string "clones de MEW y MEWTWO fallidos.\p"
	.string "Quizás quede alguno vivo, pero ya no\n"
	.string "nos sirven de nada, haz lo que quieras\l"
	.string "con ellos.$"

MicoloHideout_ExperimentRoom_Scientist3_Text_0:
	.string "No sé quién eres, pero no te\n"
	.string "recomendaría continuar por la sala de\l"
	.string "la derecha.\p"
	.string "En esa sala se encuentra el POKéMON que\n"
	.string "A.VADER trajo de su viaje a la RUTA\l"
	.string "110... REGIELEKI, creo que se llamaba.\l"
	.string "Es extremadamente peligroso, apenas\l"
	.string "hemos podido contenerlo.\p"
    .string "Dicen que A.VADER se lo quitó en la cara\n"
	.string "a un entrenador muy PALLASO.$"
	
PCBatallaTotem::
	msgbox PCBatallaTotem_Text, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PC_NoBatallaTotem
	msgbox PC_ChooseTotem, MSGBOX_DEFAULT
	multichoicegrid 0, 0, MULTI_TOTEM_BATTLE_LIST, 3, 0
	switch VAR_RESULT
	case 0, PC_BatalllaTotem1
	case 1, PC_BatalllaTotem2
	case 2, PC_BatalllaTotem3
	case 3, PC_BatalllaTotem4
	case 4, PC_BatalllaTotem5
	case 5, PC_BatalllaTotem6
	case 6, PC_BatalllaTotem7
	case 7, PC_BatalllaTotem8
	case 8, PC_BatalllaTotem9
	case 9, PC_BatalllaTotem10
	case 10, PC_BatalllaTotem11
	case 11, PC_BatalllaTotem12
	case MULTI_B_PRESSED, PC_NoBatallaTotem
	end
	
PC_BatalllaTotem1::	
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_PROBOPASS
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
	releaseall
	end
	
PC_BatalllaTotem2::	
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_CENTISKORCH
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
	releaseall
	end

PC_BatalllaTotem3::	
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_TOXTRICITY
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
	releaseall
	end
	
PC_BatalllaTotem4::	
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_COFAGRIGUS
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
	releaseall
	end
	
PC_BatalllaTotem5::	
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_WINTASS
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
	releaseall
	end
	
PC_BatalllaTotem6::	
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_RHYPERIOR
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
	releaseall
	end
	
PC_BatalllaTotem7::	
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_MEGA_ABSOL
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
	releaseall
	end
	
PC_BatalllaTotem8::	
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_PRIMARINA
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
	releaseall
	end

PC_BatalllaTotem9::	
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_MEGA_CAMERUPT
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
	releaseall
	end
	
PC_BatalllaTotem10::	
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_SAPPHIRE
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
	releaseall
	end
	
PC_BatalllaTotem11::	
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_MEGA_GLALIE
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
	releaseall
	end
	
PC_BatalllaTotem12::	
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_TYRANITAR
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
	releaseall
	end
	
PC_NoBatallaTotem::
	msgbox PC_NoBatallaTotem_Text
	release
	end

PCBatallaTotem_Text:
	.string "Este PC contiene un registro\n"
	.string "de los TOTEM creados en este\l"
	.string "laboratorio.\p"

	.string "¿Quieres combatir contra un TOTEM?$"
	
PC_NoBatallaTotem_Text:
	.string "Vuelve cuando quieras.$"
	
PC_ChooseTotem:
	.string "Elige contra cuál TOTEM quieres\n"
	.string "combatir.$"
	
