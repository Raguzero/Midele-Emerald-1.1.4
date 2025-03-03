Micolandia_Cibercafe_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Micolandia_Cibercafe_OnTransition

	.byte 0

Micolandia_Cibercafe_OnTransition:
	call_if_unset FLAG_HIDE_LAVAROOM_GIRATINAMASTER, Micolandia_Cibercafe_EventScript_ManiacInRandomPC
	end

Micolandia_Cibercafe_EventScript_ManiacInRandomPC::
	setobjectxyperm 8, 12, 13
	return


Cibercafe_PCBatalla::
	msgbox PC_Batalla, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PC_NoBatalla
	multichoicegrid 0, 0, MULTI_LISTAS_CIBERCAFE, 2, 0
	switch VAR_RESULT
	case 0, PC_LISTA1
	case 1, PC_LISTA2
	case 2, PC_NoBatalla
	case MULTI_B_PRESSED, PC_NoBatalla
	end

PC_LISTA1::
	msgbox PC_ChooseEnemy, MSGBOX_DEFAULT
	multichoicegrid 0, 0, MULTI_CIBERCAFE_BATALLA, 3, 0
	switch VAR_RESULT
	case 0, PC_BatalllaBROCK
	case 1, PC_BatalllaMISTY
	case 2, PC_BatalllaLTSURGE
	case 3, PC_BatalllaERIKA
	case 4, PC_BatalllaSABRINA
	case 5, PC_BatalllaKOGA
	case 6, PC_BatalllaBLAINE
	case 7, PC_BatalllaGIOVANNI
	case 8, PC_NoBatalla
	case MULTI_B_PRESSED, PC_NoBatalla
	end

PC_LISTA2::
	msgbox PC_ChooseEnemy, MSGBOX_DEFAULT
	multichoicegrid 0, 0, MULTI_CIBERCAFE_BATALLA_2, 3, 0
	switch VAR_RESULT
	case 0, PC_BatalllaLORELEI
	case 1, PC_BatalllaBRUNO
	case 2, PC_BatalllaAGATHA
	case 3, PC_BatalllaLANCE
	case 4, PC_BatalllaBLUE
	case 5, PC_BatalllaRED
	case 6, PC_BatalllaLEAF
	case 7, PC_BatalllaCHERYL
	case 8, PC_NoBatalla
	case MULTI_B_PRESSED, PC_NoBatalla
	end

PC_BatallaLider::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end

Cibercafe_PCRandom::
  goto_if_unset FLAG_HIDE_LAVAROOM_GIRATINAMASTER, PC_Roto @ no debería ser alcanzable, pero por si acaso
	msgbox PC_Batalla_Random, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PC_NoBatalla
  special PCBatallaRandomSetTrainer
	special HealPlayerParty
	setflag FLAG_CIBERCAFE_RANDOM
	setvar VAR_0x8004, SPECIAL_CIBERCAFE_RANDOM
    setvar VAR_0x8005, 0
    special DoSpecialTrainerBattle
    waitstate
	clearflag FLAG_CIBERCAFE_RANDOM
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWINPCRandom
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	release
	end

PC_BatalllaBROCK::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_BROCK
  goto PC_BatallaLider
	
PC_BatalllaMISTY::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_MISTY
  goto PC_BatallaLider
	
PC_BatalllaLTSURGE::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_LTSURGE
  goto PC_BatallaLider
	
PC_BatalllaERIKA::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_ERIKA
  goto PC_BatallaLider
	
PC_BatalllaSABRINA::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_SABRINA
  goto PC_BatallaLider
	
PC_BatalllaKOGA::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_KOGA
  goto PC_BatallaLider
	
PC_BatalllaBLAINE::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_BLAINE
  goto PC_BatallaLider
	
PC_BatalllaGIOVANNI::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_GIOVANNI
  goto PC_BatallaLider
	
PC_BatalllaLORELEI::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_LORELEI
  goto PC_BatallaLider
	
PC_BatalllaBRUNO::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_BRUNO
  goto PC_BatallaLider
	
PC_BatalllaAGATHA::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_AGATHA
  goto PC_BatallaLider
	
PC_BatalllaLANCE::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_LANCE
  goto PC_BatallaLider
	
PC_BatalllaBLUE::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_BLUE
  goto PC_BatallaLider
	
PC_BatalllaRED::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_RED2
  goto PC_BatallaLider
	
PC_BatalllaLEAF::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_LEAF2
  goto PC_BatallaLider
	
PC_BatalllaCHERYL::
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_CHERYL
  goto PC_BatallaLider
 
Cibercafe_PCFarmeo::
	msgbox PC_Batalla_Farmeo, MSGBOX_DEFAULT
	goto Cibercafe_PCFarmeoCONTINUE
	
Cibercafe_PCFarmeoCONTINUE::
	msgbox PC_Batalla_Farmeo2, MSGBOX_DEFAULT
	multichoicegrid 0, 0, MULTI_RANDOMBATTLE, 3, 0
	switch VAR_RESULT
	case 0, PC_BatalllaModo1vs1
	case 1, PC_BatalllaModo2vs2
	case 2, PC_NoBatalla
	case MULTI_B_PRESSED, PC_NoBatalla
	end

PC_BatalllaModo1vs1::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_FARMEO
	goto ComienzaFarmeo
 
PC_BatalllaModo2vs2::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_FARMEO_DOBLES
	goto ComienzaFarmeo
	
ComienzaFarmeo::
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinFarmeo
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinFarmeo
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinFarmeo
	end
	
PC_NoBatalla::
	msgbox PC_NoBatalla_Text
	release
	end

PC_Roto::
	msgbox PC_Roto_Text
	release
	end
	
PC_BatallaFinFarmeo::
    special HealPlayerParty
	msgbox PC_Batalla_Farmeo3, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PC_NoBatalla
	goto Cibercafe_PCFarmeoCONTINUE
    release
    end

PC_BatallaFinWIN::
    special HealPlayerParty
    msgbox PC_Enhorabuena
    special PCBatallaGivePrize
    compare VAR_RESULT, 0
    goto_if_eq PC_BatallaFin_FinRandomPrize
    giveitem VAR_RESULT
    compare VAR_RESULT, FALSE
    call_if_eq PC_Batalla_Script_RandomPrize1_BagFull
    closemessage
PC_BatallaFin_FinRandomPrize::
    release
    end

PC_Batalla_Script_RandomPrize1_BagFull::
    call Common_EventScript_BagIsFull
    msgbox Script_RandomPrize1_Text_NoRoomForThis, MSGBOX_DEFAULT
    return
	
PC_BatallaFinWINPCRandom::
	special HealPlayerParty
	release
	end
	
PC_BatallaFinLOSS::
	special HealPlayerParty
	msgbox PC_Perder
	closemessage
	release
	end
	
PC_BatallaFinDRAW::
	special HealPlayerParty
	msgbox PC_Perder
	closemessage
	release
	end
	
Micolandia_Cibercafe_Dueno_Script::
  lock
  faceplayer
	msgbox Micolandia_Cibercafe_Dueno_Text, MSGBOX_DEFAULT
  goto_if_unset FLAG_HIDE_LAVAROOM_GIRATINAMASTER, Micolandia_Cibercafe_Dueno_Script_GoodLuck
	msgbox Micolandia_Cibercafe_Dueno_Text_NewPC, MSGBOX_DEFAULT
  goto Micolandia_Cibercafe_Dueno_Script_End
Micolandia_Cibercafe_Dueno_Script_GoodLuck::
	msgbox Micolandia_Cibercafe_Dueno_Text_GoodLuck, MSGBOX_DEFAULT
Micolandia_Cibercafe_Dueno_Script_End::
  release
	end
	
Micolandia_Cibercafe_NPC1::
	msgbox Micolandia_Cibercafe_NPC1_Text, MSGBOX_SIGN
	end
	
Micolandia_Cibercafe_NPC2::
	msgbox Micolandia_Cibercafe_NPC2_Text, MSGBOX_SIGN
	end
	
Micolandia_Cibercafe_NPC3::
	msgbox Micolandia_Cibercafe_NPC3_Text, MSGBOX_SIGN
	end
	
Micolandia_Cibercafe_NPC4::
	msgbox Micolandia_Cibercafe_NPC4_Text, MSGBOX_SIGN
	end
	
Micolandia_Cibercafe_NPC5::
	msgbox Micolandia_Cibercafe_NPC5_Text, MSGBOX_SIGN
	end
	
Micolandia_Cibercafe_NPC6::
	msgbox Micolandia_Cibercafe_NPC6_Text, MSGBOX_SIGN
	end
	
Micolandia_Cibercafe_NPC7::
	msgbox Micolandia_Cibercafe_NPC7_Text, MSGBOX_SIGN
	end
	
Micolandia_Cibercafe_Dueno_Text:
	.string "¡Te doy la bienvenida al\n" 
	.string "CIBERCAFE BATALLA!\p"
	
	.string "Elige un PC para combatir con\n"
	.string "simulaciones de entrenadores de\l" 
	.string "otras regiones. Estos entrenadores\l"
	.string "se adecuarán al nivel máximo de tu\l"
	.string "equipo, así que tenlo en cuenta.\p"
	
	.string "Puedes ganar dinero, experiencia y\n"
	.string "premios si vences en estas batallas.$"

Micolandia_Cibercafe_Dueno_Text_NewPC:
  .string "Hemos arreglado uno de los PCs,\n"
  .string "pero ahora está ocupado…\l"
  .string "Eso sí, el que lo está usando al fin\l"
  .string "dejó libre el PC de combates aleatorios.\p"

  .string "En ese PC, al entrar a mano derecha,\n"
  .string "puedes combatir contra entrenadores\l"
  .string "al azar de MIDELE EMERALD.\p"

  .string "Se eligen entre los entrenadores con 6\n"
  .string "pokémon, que son subidos al nivel 100.\p"
Micolandia_Cibercafe_Dueno_Text_GoodLuck:
	.string "¡Buena suerte!$"
	
PC_Enhorabuena:
	.string "Ganaste, te llevas este premio.$"

PC_Perder:
	.string "No siempre se gana.\n"
	.string "Vuelve cuando quieras.$"

PC_Batalla:
	.string "Te doy la bienvenida al servidor.\n"
	.string "¿Quieres realizar una batalla?$"
	
PC_Batalla_Random:
	.string "Te doy la bienvenida al servidor\n"
	.string "aleatorio.\l"
  .string "Aquí puedes combatir contra un\l"
  .string "entrenador al azar de MIDELE EMERALD.\l"
	.string "¿Quieres realizar una batalla?$"
	
PC_Batalla_Farmeo:
	.string "Te doy la bienvenida al servidor\n"
	.string "farmeador, la mejor forma de entrenar\l"
	.string "a POKéMON de bajo nivel.$"

PC_Batalla_Farmeo2:
	.string "¿Qué modo de batalla eliges?$"
	
PC_Batalla_Farmeo3:
	.string "¿Quieres luchar de nuevo?$"
	
PC_NoBatalla_Text:
	.string "Vuelve cuando quieras.$"
	
PC_Roto_Text:
	.string "Parece que no funciona.$"
	
PC_ChooseEnemy:
	.string "Elige un contrincante.$"
	
Micolandia_Cibercafe_NPC1_Text:
	.string "¡Qué difícil es este simulador!$"
	
Micolandia_Cibercafe_NPC2_Text:
	.string "¡Esto me servirá como entrenamiento\n"
	.string "para afrontar el desafío de la MICOLIGA!$"
	
Micolandia_Cibercafe_NPC3_Text:
	.string "¡Genial! ¡Vencí a RED y conseguí un\n"
	.string "LUCKY EGG!$"
	
Micolandia_Cibercafe_NPC4_Text:
	.string "¡Noooooo! ¡LANCE es demasiado fuerte!$"
	
Micolandia_Cibercafe_NPC5_Text:
	.string "¡El servidor farmeador es GENIAL!\n"
	.string "¡Con solo equiparles a mis POKéMON Nv1\l"
	.string "con un LUCKY EGG puedo hacer que suban\l"
	.string "de nivel a una velocidad asombrosa!\p"
	
	.string "Ojalá tuviese un POKéMON intercambiado.\n"
	.string "Se dice que estos POKéMON suben de\l"
	.string "nivel mucho más rápido.\p"
	.string "¿Cuanta Experiencia podrían conseguir?\n"
	.string "¿¿¿¿60000???? ¡¡MENUDA LOCURA!!$"

Micolandia_Cibercafe_NPC7_Text:
	.string "...$"
	
Micolandia_Cibercafe_NPC6_Text:
	.string "¡Qué vicio esto! ¡Estoy consiguiendo\n"
	.string "muchos objetos útiles!$"
