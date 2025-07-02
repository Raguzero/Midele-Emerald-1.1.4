GymGooses_MapScripts::
	.byte 0
	
GymGooses_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GOOSES_GYM, GymGooses_EventScript_GymGuidePostVictory
	msgbox GymGooses_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

GymGooses_EventScript_GymGuidePostVictory::
	msgbox GymGooses_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

GymGooses_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_DEFEATED_GOOSES_GYM, GymGooses_EventScript_GymStatueCertified
	goto GymGooses_EventScript_GymStatue
	end

GymGooses_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_DEFEATED_GOOSES_GYM, GymGooses_EventScript_GymStatueCertified
	goto GymGooses_EventScript_GymStatue
	end

GymGooses_EventScript_GymStatueCertified::
	msgbox GymGooses_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

GymGooses_EventScript_GymStatue::
	msgbox GymGooses_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end
	
GymGooses_EventScript_TeleportGirl::
	lock
	faceplayer
	msgbox GymGooses_TeleportGirl_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymGooses_EventScript_Entrada
	release
	end
	
GymGooses_EventScript_TeleportBoy::
	lock
	faceplayer
	clearflag FLAG_HIDE_GYMGOOSES_TELEPORTBOY
	msgbox GymGooses_TeleportBoy_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymGooses_EventScript_Entrada
	release
	end
	
GymGooses_EventScript_TeleportBoy2::
	lock
	faceplayer
	msgbox GymGooses_TeleportBoy2_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymGooses_EventScript_CuartaSala
	release
	end

GymGooses_EventScript_Entrada::
	warp MAP_GYM_GOOSES, 0, 0, 0
	waitstate
	release
	end
	
GymGooses_EventScript_CuartaSala::
	warp MAP_GYM_GOOSES, 2, 0, 0
	waitstate
	release
	end

// Primera, Segunda y Tercera Sala	
GymGooses_CasillaTableroDado::
	msgbox GymGoosesTirarDado_Text, MSGBOX_DEFAULT
	waitmessage
	lock
	faceplayer
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado1
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end

GymGooses_CasillaTableroDado2::
	msgbox GymGoosesTirarDado_Text, MSGBOX_DEFAULT
	waitmessage
	lock
	faceplayer
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado2
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
	
GymGooses_CasillaTableroDado3::
	msgbox GymGoosesTirarDado_Text, MSGBOX_DEFAULT
	waitmessage
	lock
	faceplayer
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado3
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
	
GymGooses_CasillaTableroDado4::
	msgbox GymGoosesTirarDado_Text, MSGBOX_DEFAULT
	waitmessage
	lock
	faceplayer
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado4
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
	
GymGooses_CasillaTableroDado5::
	msgbox GymGoosesTirarDado_Text, MSGBOX_DEFAULT
	waitmessage
	lock
	faceplayer
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado5
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end

GymGooses_CasillaTableroCombate::
	msgbox GymGoosesCombate_Text, MSGBOX_DEFAULT
	lock
	faceplayer
	setflag FLAG_RANDOMBATTLE_GYMGOOSES
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE
    setvar VAR_0x8005, 0
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq CasillaTableroLoss
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq CasillaTableroWin
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq CasillaTableroLoss
    compare VAR_RESULT, B_OUTCOME_FORFEITED
    call_if_eq CasillaTableroLoss
CasillaTableroWin::
	clearflag FLAG_RANDOMBATTLE_GYMGOOSES
	msgbox GymGoosesTirarDadoAgain_Text, MSGBOX_DEFAULT
	waitmessage
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDadoCombateGanado
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
CasillaTableroLoss::
	special HealPlayerParty
	clearflag FLAG_RANDOMBATTLE_GYMGOOSES
	closemessage
	warp MAP_GYM_GOOSES, 0, 0, 0
	release
	end

GymGooses_CasillaTableroCombate2::
	msgbox GymGoosesCombate_Text, MSGBOX_DEFAULT
	lock
	faceplayer
	setflag FLAG_RANDOMBATTLE_GYMGOOSES
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE
    setvar VAR_0x8005, 0
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq CasillaTableroLoss2
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq CasillaTableroWin2
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq CasillaTableroLoss2
    compare VAR_RESULT, B_OUTCOME_FORFEITED
    call_if_eq CasillaTableroLoss2
CasillaTableroWin2::
	clearflag FLAG_RANDOMBATTLE_GYMGOOSES
	msgbox GymGoosesTirarDadoAgain_Text, MSGBOX_DEFAULT
	waitmessage
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado2_Movement_PlayerDadoCombateGanado
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
CasillaTableroLoss2::
	special HealPlayerParty
	clearflag FLAG_RANDOMBATTLE_GYMGOOSES
	closemessage
	warp MAP_GYM_GOOSES, 0, 0, 0
	release
	end
	
GymGooses_CasillaTableroCombate3::
	msgbox GymGoosesCombate_Text, MSGBOX_DEFAULT
	lock
	faceplayer
	setflag FLAG_RANDOMBATTLE_GYMGOOSES
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE
    setvar VAR_0x8005, 0
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq CasillaTableroLoss3
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq CasillaTableroWin3
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq CasillaTableroLoss3
    compare VAR_RESULT, B_OUTCOME_FORFEITED
    call_if_eq CasillaTableroLoss3
CasillaTableroWin3::
	clearflag FLAG_RANDOMBATTLE_GYMGOOSES
	msgbox GymGoosesTirarDadoAgain_Text, MSGBOX_DEFAULT
	waitmessage
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado3_Movement_PlayerDadoCombateGanado
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
CasillaTableroLoss3::
	special HealPlayerParty
	clearflag FLAG_RANDOMBATTLE_GYMGOOSES
	closemessage
	warp MAP_GYM_GOOSES, 0, 0, 0
	release
	end
	
GymGooses_CasillaTableroStatus::
	lock
	faceplayer
	msgbox GymGoosesStatus_Text, MSGBOX_DEFAULT
	random 6
	switch VAR_RESULT
	case 0, GymGoosesStatus_Poison_Script
	case 1, GymGoosesStatus_Toxic_Script
	case 2, GymGoosesStatus_Burn_Script
	case 3, GymGoosesStatus_Prz_Script
	case 4, GymGoosesStatus_Slp_Script
	case 5, GymGoosesStatus_Freeze_Script
	end

GymGooses_CasillaTableroPregunta::
	lock
	faceplayer
	setvar VAR_TEMP_1, 0
	msgbox GymGoosesPregunta_Text, MSGBOX_DEFAULT
	random 18
	switch VAR_RESULT
	case 0, Script_Quiz1
	case 1, Script_Quiz2
	case 2, Script_Quiz3
	case 3, Script_Quiz4
	case 4, Script_Quiz5
	case 5, Script_Quiz6
	case 6, Script_Quiz7
	case 7, Script_Quiz8
	case 8, Script_Quiz9
	case 9, Script_Quiz10
	case 10, Script_Quiz11
	case 11, Script_Quiz12
	case 12, Script_Quiz13
	case 13, Script_QuizYESNO1
	case 14, Script_QuizYESNO2
	case 15, Script_QuizYESNO3
	case 16, Script_QuizYESNO4
	case 17, Script_QuizYESNO5
	end
	
GymGooses_CasillaTableroPregunta2::
	lock
	faceplayer
	setvar VAR_TEMP_1, 1
	msgbox GymGoosesPregunta_Text, MSGBOX_DEFAULT
	random 18
	switch VAR_RESULT
	case 0, Script_Quiz1
	case 1, Script_Quiz2
	case 2, Script_Quiz3
	case 3, Script_Quiz4
	case 4, Script_Quiz5
	case 5, Script_Quiz6
	case 6, Script_Quiz7
	case 7, Script_Quiz8
	case 8, Script_Quiz9
	case 9, Script_Quiz10
	case 10, Script_Quiz11
	case 11, Script_Quiz12
	case 12, Script_Quiz13
	case 13, Script_QuizYESNO1
	case 14, Script_QuizYESNO2
	case 15, Script_QuizYESNO3
	case 16, Script_QuizYESNO4
	case 17, Script_QuizYESNO5
	end

GymGooses_CasillaTableroPregunta3::
	lock
	faceplayer
	setvar VAR_TEMP_1, 2
	msgbox GymGoosesPregunta_Text, MSGBOX_DEFAULT
	random 18
	switch VAR_RESULT
	case 0, Script_Quiz1
	case 1, Script_Quiz2
	case 2, Script_Quiz3
	case 3, Script_Quiz4
	case 4, Script_Quiz5
	case 5, Script_Quiz6
	case 6, Script_Quiz7
	case 7, Script_Quiz8
	case 8, Script_Quiz9
	case 9, Script_Quiz10
	case 10, Script_Quiz11
	case 11, Script_Quiz12
	case 12, Script_Quiz13
	case 13, Script_QuizYESNO1
	case 14, Script_QuizYESNO2
	case 15, Script_QuizYESNO3
	case 16, Script_QuizYESNO4
	case 17, Script_QuizYESNO5
	end

GymGooses_CasillaTableroPregunta4::
	lock
	faceplayer
	setvar VAR_TEMP_1, 3
	msgbox GymGoosesPregunta_Text, MSGBOX_DEFAULT
	random 18
	switch VAR_RESULT
	case 0, Script_Quiz1
	case 1, Script_Quiz2
	case 2, Script_Quiz3
	case 3, Script_Quiz4
	case 4, Script_Quiz5
	case 5, Script_Quiz6
	case 6, Script_Quiz7
	case 7, Script_Quiz8
	case 8, Script_Quiz9
	case 9, Script_Quiz10
	case 10, Script_Quiz11
	case 11, Script_Quiz12
	case 12, Script_Quiz13
	case 13, Script_QuizYESNO1
	case 14, Script_QuizYESNO2
	case 15, Script_QuizYESNO3
	case 16, Script_QuizYESNO4
	case 17, Script_QuizYESNO5
	end

GymGooses_CasillaTableroPregunta5::
	lock
	faceplayer
	setvar VAR_TEMP_1, 4
	msgbox GymGoosesPregunta_Text, MSGBOX_DEFAULT
	random 18
	switch VAR_RESULT
	case 0, Script_Quiz1
	case 1, Script_Quiz2
	case 2, Script_Quiz3
	case 3, Script_Quiz4
	case 4, Script_Quiz5
	case 5, Script_Quiz6
	case 6, Script_Quiz7
	case 7, Script_Quiz8
	case 8, Script_Quiz9
	case 9, Script_Quiz10
	case 10, Script_Quiz11
	case 11, Script_Quiz12
	case 12, Script_Quiz13
	case 13, Script_QuizYESNO1
	case 14, Script_QuizYESNO2
	case 15, Script_QuizYESNO3
	case 16, Script_QuizYESNO4
	case 17, Script_QuizYESNO5
	end			
	
Script_Quiz1::	
	msgbox Quiz1_Text, MSGBOX_DEFAULT
	multichoice 12, 0, MULTI_QUIZ1_GYM, 1
	switch VAR_RESULT
	case 0, GymGooses_EventScript_Incorrecta
	case 1, GymGooses_EventScript_Correcta
	case 2, GymGooses_EventScript_Incorrecta
	case MULTI_B_PRESSED, NoSabeNoContesta
	end
	
Script_Quiz2::	
	msgbox Quiz2_Text, MSGBOX_DEFAULT
	multichoice 12, 0, MULTI_QUIZ2_GYM, 1
	switch VAR_RESULT
	case 0, GymGooses_EventScript_Correcta
	case 1, GymGooses_EventScript_Incorrecta
	case 2, GymGooses_EventScript_Incorrecta
	case MULTI_B_PRESSED, NoSabeNoContesta
	end
	
Script_Quiz3::	
	msgbox Quiz3_Text, MSGBOX_DEFAULT
	multichoice 12, 0, MULTI_QUIZ3_GYM, 1
	switch VAR_RESULT
	case 0, GymGooses_EventScript_Correcta
	case 1, GymGooses_EventScript_Incorrecta
	case 2, GymGooses_EventScript_Incorrecta
	case MULTI_B_PRESSED, NoSabeNoContesta
	end
	
Script_Quiz4::	
	msgbox Quiz4_Text, MSGBOX_DEFAULT
	multichoice 12, 0, MULTI_QUIZ4_GYM, 1
	switch VAR_RESULT
	case 0, GymGooses_EventScript_Incorrecta
	case 1, GymGooses_EventScript_Correcta
	case 2, GymGooses_EventScript_Incorrecta
	case MULTI_B_PRESSED, NoSabeNoContesta
	end
	
Script_Quiz5::	
	msgbox Quiz5_Text, MSGBOX_DEFAULT
	multichoice 12, 0, MULTI_QUIZ5_GYM, 1
	switch VAR_RESULT
	case 0, GymGooses_EventScript_Correcta
	case 1, GymGooses_EventScript_Incorrecta
	case 2, GymGooses_EventScript_Incorrecta
	case MULTI_B_PRESSED, NoSabeNoContesta
	end
	
Script_Quiz6::	
	msgbox Quiz6_Text, MSGBOX_DEFAULT
	multichoice 12, 0, MULTI_QUIZ6_GYM, 1
	switch VAR_RESULT
	case 0, GymGooses_EventScript_Incorrecta
	case 1, GymGooses_EventScript_Correcta
	case 2, GymGooses_EventScript_Incorrecta
	case MULTI_B_PRESSED, NoSabeNoContesta
	end
	
Script_Quiz7::	
	msgbox Quiz7_Text, MSGBOX_DEFAULT
	multichoice 12, 0, MULTI_QUIZ7_GYM, 1
	switch VAR_RESULT
	case 0, GymGooses_EventScript_Correcta
	case 1, GymGooses_EventScript_Correcta
	case 2, GymGooses_EventScript_Correcta
	case MULTI_B_PRESSED, NoSabeNoContesta
	end
	
Script_Quiz8::	
	msgbox Quiz8_Text, MSGBOX_DEFAULT
	multichoice 12, 0, MULTI_QUIZ8_GYM, 1
	switch VAR_RESULT
	case 0, GymGooses_EventScript_Correcta
	case 1, GymGooses_EventScript_Incorrecta
	case 2, GymGooses_EventScript_Incorrecta
	case MULTI_B_PRESSED, NoSabeNoContesta
	end
	
Script_Quiz9::	
	msgbox Quiz9_Text, MSGBOX_DEFAULT
	multichoice 12, 0, MULTI_QUIZ9_GYM, 1
	switch VAR_RESULT
	case 0, GymGooses_EventScript_Incorrecta
	case 1, GymGooses_EventScript_Correcta
	case 2, GymGooses_EventScript_Incorrecta
	case MULTI_B_PRESSED, NoSabeNoContesta
	end
	
Script_Quiz10::	
	msgbox Quiz10_Text, MSGBOX_DEFAULT
	multichoice 12, 0, MULTI_QUIZ10_GYM, 1
	switch VAR_RESULT
	case 0, GymGooses_EventScript_Incorrecta
	case 1, GymGooses_EventScript_Incorrecta
	case 2, GymGooses_EventScript_Correcta
	case MULTI_B_PRESSED, NoSabeNoContesta
	end
	
Script_Quiz11::	
	msgbox Quiz11_Text, MSGBOX_DEFAULT
	multichoice 12, 0, MULTI_QUIZ11_GYM, 1
	switch VAR_RESULT
	case 0, GymGooses_EventScript_Incorrecta
	case 1, GymGooses_EventScript_Incorrecta
	case 2, GymGooses_EventScript_Correcta
	case MULTI_B_PRESSED, NoSabeNoContesta
	end
	
Script_Quiz12::	
	msgbox Quiz12_Text, MSGBOX_DEFAULT
	multichoice 12, 0, MULTI_QUIZ12_GYM, 1
	switch VAR_RESULT
	case 0, GymGooses_EventScript_Incorrecta
	case 1, GymGooses_EventScript_Incorrecta
	case 2, GymGooses_EventScript_Correcta
	case MULTI_B_PRESSED, NoSabeNoContesta
	end
	
Script_Quiz13::	
	msgbox Quiz13_Text, MSGBOX_DEFAULT
	multichoice 12, 0, MULTI_QUIZ13_GYM, 1
	switch VAR_RESULT
	case 0, GymGooses_EventScript_Incorrecta
	case 1, GymGooses_EventScript_Correcta
	case 2, GymGooses_EventScript_Incorrecta
	case MULTI_B_PRESSED, NoSabeNoContesta
	end
	
Script_QuizYESNO1::	
	msgbox Quiz14_Text, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, GymGooses_EventScript_Correcta
	goto GymGooses_EventScript_Incorrecta
	end
	
Script_QuizYESNO2::	
	msgbox Quiz15_Text, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, GymGooses_EventScript_Correcta
	goto GymGooses_EventScript_Incorrecta
	end
	
Script_QuizYESNO3::	
	msgbox Quiz16_Text, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, GymGooses_EventScript_Correcta
	msgbox Quiz16_Text_Correcta, MSGBOX_DEFAULT
	goto GymGooses_EventScript_Incorrecta
	end
	
Script_QuizYESNO4::	
	msgbox Quiz17_Text, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, GymGooses_EventScript_Correcta
	goto GymGooses_EventScript_Incorrecta
	end
	
Script_QuizYESNO5::	
	msgbox Quiz18_Text, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, GymGooses_EventScript_Correcta
	goto GymGooses_EventScript_Incorrecta
	end

GymGooses_EventScript_Incorrecta::
	msgbox Respuesta_Incorrecta_Text
	goto CasillaTableroIncorrecta_EventScript

GymGooses_EventScript_Correcta::
	msgbox Respuesta_Correcta_Text	
	goto CasillaTableroCorrecta_EventScript
	
NoSabeNoContesta::
	msgbox Respuesta_NSNC_Text
	goto NoSabeNoContesta_2

CasillaTableroCorrecta_EventScript::
	switch VAR_TEMP_1
	case 0, CasillaTableroCorrectaCasilla1_EventScript
	case 1, CasillaTableroCorrectaCasilla2_EventScript
	case 2, CasillaTableroCorrectaCasilla3_EventScript
	case 3, CasillaTableroCorrectaCasilla4_EventScript
	case 4, CasillaTableroCorrectaCasilla5_EventScript
	end
	
CasillaTableroCorrectaCasilla1_EventScript::
	msgbox GymGoosesTirarDadoAgain_Text, MSGBOX_DEFAULT
	waitmessage
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDadoPreguntaCorrecta
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
	
CasillaTableroCorrectaCasilla2_EventScript::
	msgbox GymGoosesTirarDadoAgain_Text, MSGBOX_DEFAULT
	waitmessage
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado2_Movement_PlayerDadoPreguntaCorrecta
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
	
CasillaTableroCorrectaCasilla3_EventScript::
	msgbox GymGoosesTirarDadoAgain_Text, MSGBOX_DEFAULT
	waitmessage
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado3_Movement_PlayerDadoPreguntaCorrecta
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
	
CasillaTableroCorrectaCasilla4_EventScript::
	msgbox GymGoosesTirarDadoAgain_Text, MSGBOX_DEFAULT
	waitmessage
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado4_Movement_PlayerDadoPreguntaCorrecta
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
	
CasillaTableroCorrectaCasilla5_EventScript::
	msgbox GymGoosesTirarDadoAgain_Text, MSGBOX_DEFAULT
	waitmessage
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado5_Movement_PlayerDadoPreguntaCorrecta
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
	
CasillaTableroIncorrecta_EventScript::
	closemessage
	warp MAP_GYM_GOOSES, 0, 0, 0
	release
	end
	
NoSabeNoContesta_2::
	closemessage
	warp MAP_GYM_GOOSES, 0, 0, 0
	release
	end

//Dado primera casilla
GymGoosesDado1_Movement_PlayerDado1:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

//Dado segunda casilla
GymGoosesDado1_Movement_PlayerDado2:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
//Dado tercera casilla
GymGoosesDado1_Movement_PlayerDado3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end
	
//Dado cuarta casilla
GymGoosesDado1_Movement_PlayerDado4:
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

//Dado quinta casilla	
GymGoosesDado1_Movement_PlayerDado5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
//Dado primera casilla combate ganado
GymGoosesDado1_Movement_PlayerDadoCombateGanado:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

//Dado segunda casilla combate ganado
GymGoosesDado2_Movement_PlayerDadoCombateGanado:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

//Dado tercera casilla combate ganado
GymGoosesDado3_Movement_PlayerDadoCombateGanado:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

//Dado primera casilla respuesta correcta
GymGoosesDado1_Movement_PlayerDadoPreguntaCorrecta:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

//Dado segunda casilla respuesta correcta
GymGoosesDado2_Movement_PlayerDadoPreguntaCorrecta:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

//Dado tercera casilla respuesta correcta
GymGoosesDado3_Movement_PlayerDadoPreguntaCorrecta:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end
	
//Dado cuarta casilla respuesta correcta
GymGoosesDado4_Movement_PlayerDadoPreguntaCorrecta:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	step_end
	
//Dado quinta casilla respuesta correcta
GymGoosesDado5_Movement_PlayerDadoPreguntaCorrecta:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
//Dado casillas Status
GymGoosesDado1_Movement_PlayerDadoStatus:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

GymGoosesStatus_Poison_Script::
	special PoisonMons
	msgbox GymGoosesStatus_Poison
	waitse
	msgbox GymGoosesTirarDadoStatus_Text, MSGBOX_DEFAULT
	closemessage
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDadoStatus
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
	
GymGoosesStatus_Toxic_Script::
	special ToxicMons
	msgbox GymGoosesStatus_Toxic
	waitse
	msgbox GymGoosesTirarDadoStatus_Text, MSGBOX_DEFAULT
	closemessage
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDadoStatus
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
	
GymGoosesStatus_Slp_Script::
	special SleepMons
	msgbox GymGoosesStatus_Slp
	waitse
	msgbox GymGoosesTirarDadoStatus_Text, MSGBOX_DEFAULT
	closemessage
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDadoStatus
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
	
GymGoosesStatus_Prz_Script::
	special ParalisisMons
	msgbox GymGoosesStatus_Prz
	waitse
	msgbox GymGoosesTirarDadoStatus_Text, MSGBOX_DEFAULT
	closemessage
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDadoStatus
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
	
GymGoosesStatus_Burn_Script::
	special BurnMons
	msgbox GymGoosesStatus_Burn
	waitse
	msgbox GymGoosesTirarDadoStatus_Text, MSGBOX_DEFAULT
	closemessage
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDadoStatus
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
	
GymGoosesStatus_Freeze_Script::
	special FreezeMons
	msgbox GymGoosesStatus_Freeze
	waitse
	msgbox GymGoosesTirarDadoStatus_Text, MSGBOX_DEFAULT
	closemessage
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDadoStatus
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end

// Cuarta Sala
    @ Combate contra totem.
GymGooses_EventScript_Totem::
	lockall
	clearflag FLAG_HIDE_GYMGOOSES_TELEPORTBOY
	msgbox DesafiarTotem_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymGooses_EventScript_Totem2
	releaseall
	end	

GymGooses_EventScript_Totem2::	
	playmoncry SPECIES_MEGA_GLALIE, 2
	delay 40
	waitmoncry
	msgbox GymGooses_Text_Totemaparece, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_MEGA_GLALIE
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
	removeobject 2
	removeobject 3
	setflag FLAG_TOTEM_GYMGOOSES
    msgbox GymGooses_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.	
	
// Quinta Sala
GymGooses_EventScript_Gooses::
	goto_if_set FLAG_DEFEATED_GOOSES_GYM, GymGooses_EventScript_Gooses_Derrotado
	trainerbattle_single TRAINER_GOOSES, GymGooses_Text_GoosesIntro, GymGooses_Text_GoosesDefeat, GymGooses_EventScript_GoosesDefeated, NO_MUSIC
	release
	end
	
GymGooses_EventScript_GoosesDefeated::
	message GymGooses_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GymGooses_Text_ExplainBadgeTakeThis, MSGBOX_DEFAULT
	@ Level Cap Item
	delay 30
	playse SE_PIN
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	playfanfare MUS_ME_B_SMALL
	delay 30
	msgbox LevelCapItem_Text_GymGooses, MSGBOX_DEFAULT
	closemessage
	@ Level Cap Item
	setflag FLAG_DEFEATED_GOOSES_GYM
	delay 30
	release
	end
	
GymGooses_EventScript_Gooses_Derrotado::
	goto_if_set FLAG_REMATCH_GOOSES, GymGooses_EventScript_Gooses_Rematch
	msgbox GymGooses_Text_GoosesPostBattle, MSGBOX_DEFAULT
	release
	end
	
GymGooses_EventScript_Gooses_Rematch::
	trainerbattle_single TRAINER_GOOSES, GymGooses_Text_GoosesRematchIntro, GymGooses_Text_GoosesRematchDefeat, GymGooses_EventScript_GoosesRematchDefeated, NO_MUSIC
	release
	end
	
GymGooses_EventScript_GoosesRematchDefeated::
	msgbox GymGooses_Text_GoosesPostBattle, MSGBOX_DEFAULT
	clearflag FLAG_REMATCH_GOOSES
	release
	end
	
GymGooses_EventScript_Primera_Casilla_Prueba::
	lockall
	goto_if_set FLAG_DEFEATED_GOOSES_GYM, GymGooses_EventScript_GymComplete
	msgbox GymGooses_Text_Comienza, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymGooses_EventScript_Comienza2
	applymovement EVENT_OBJ_ID_PLAYER, GymGoosesNOComienzPrueba
	waitmovement 0
	releaseall
	end
GymGooses_EventScript_Comienza2::
	msgbox GymGooses_Text_Curacion, MSGBOX_DEFAULT
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty
	applymovement EVENT_OBJ_ID_PLAYER, GymGoosesComienzPrueba
	waitmovement 0
	releaseall
	end
	
GymGooses_EventScript_GymComplete::
	msgbox GymGooses_Text_Jugardenuevo, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymGooses_EventScript_Comienza2
	applymovement EVENT_OBJ_ID_PLAYER, GymGoosesNOComienzPrueba
	waitmovement 0
	releaseall
	end
	
GymGoosesComienzPrueba:
	walk_up
	step_end
	
GymGoosesNOComienzPrueba:
	walk_down
	step_end

GymGoosesTirarDado_Text:
	.string "Casilla Dado: ¡Tira el dado!$"
	
GymGoosesTirarDadoAgain_Text:
	.string "Has superado la prueba:\n"
	.string "¡Tira el dado otra vez!$"
	
GymGoosesTirarDadoStatus_Text:
	.string "¡Tira el dado otra vez!$"
	
GymGoosesCombate_Text:
	.string "Casilla Pokeball:\n"
	.string "¡Deberás vencer a un entrenador\l"
	.string "que usará un equipo creado\l"
	.string "de forma aleatoria!$"
	
GymGoosesStatus_Text:
	.string "Casilla Status:\n"
	.string "¡Probablemente tus POKéMON sufrirán\l"
	.string "un estado pernicioso!$"
	
GymGoosesStatus_Poison:
	.string "¡ENVENÉNATE!$"
	
GymGoosesStatus_Toxic:
	.string "¡INTOXÍCATE!$"
	
GymGoosesStatus_Slp:
	.string "¡DUÉRMETE!$"
	
GymGoosesStatus_Prz:
	.string "¡PARALÍZATE!$"
	
GymGoosesStatus_Burn:
	.string "¡QUÉMATE!$"
	
GymGoosesStatus_Freeze:
	.string "¡CONGÉLATE!$"
	
GymGoosesPregunta_Text:
	.string "Casilla Pregunta:\n"
	.string "¡Debes responder de forma correcta\l" 
	.string "a la siguiente pregunta!$"
	
Quiz1_Text:
	.string "¿Quién no pudo abrir un .ZIP?$"

Quiz2_Text:	
	.string "¿Quien lideró la Bronyficación por\n" 
	.string "medio de un Golpe de Estado en PxP?$"
	
Quiz3_Text:
	.string "¿Quién se equivocó de SET de\n"
	.string "GYARADOS en un torneo?$"
	
Quiz4_Text:
	.string "¿Quién dió una PATADA SALTO a\n" 
	.string "una pobre papelera?$"
	
Quiz5_Text:
	.string "Quién dijo la siguiente frase:\n"
	.string "Maestro Arena, eres un mierdas$"

Quiz6_Text:
	.string "¿Quién se considera el mayor\n" 
	.string "fan de PROBOPASS?$"
	
Quiz7_Text:
	.string "¿Qué esperamos ver todos en\n" 
	.string "un NUZLOCKE de EEVEETO?$"
	
Quiz8_Text:
	.string "Según un usuario de PxP llamado\n" 
	.string "MRZERO ¿de qué tipo es ENTEI?$"
	
Quiz9_Text:
	.string "¿Por qué MONOCICLO?$"
	
Quiz10_Text:
	.string "¿Quién creó la prestigiosa\n"
	.string "GUARDERIA MIDELE?$"

Quiz11_Text:
	.string "¿Quién fué baneado recibiendo\n"
	.string "Una cantidad de -100 Karma?$"

Quiz12_Text:
	.string "¿Qué significa el título\n"
	.string "No Person?$"
	
Quiz13_Text:
	.string "¿Cuál es el POKéMON capaz de\n" 
	.string "usar el Trueno de la Oscuridad\l" 
	.string "(DARK THUNDER)?$"

Quiz14_Text:
	.string "¿PHENT es una multicuenta\n" 
	.string "de KADERETE?$"
	
Quiz15_Text:
	.string "Según GHADDAR, ¿los juegos\n"
	.string "de la saga principal de\l"
	.string "Final Fantasy son RPGs?$"
	
Quiz16_Text:
	.string "¿Fué MELKOR el genuino creador\n"
	.string "del Off Off Topic (OOT) de PxP?$"
	
Quiz16_Text_Correcta:
	.string "¡El genuino creador del OOT\n"
	.string "fué MICHOH!$"
	
Quiz17_Text:
	.string "¿FELIPEX88 se cortó la lengua?\n"
	.string "por gusto? O eso dijo.$"
	
Quiz18_Text:
	.string "¿El último OOT fue el MCCLVIII?$"
	
Respuesta_Incorrecta_Text:
	.string "¡RESPUESTA INCORRECTA!$"
	
Respuesta_Correcta_Text:
	.string "¡CORRECTO!$"
	
Respuesta_NSNC_Text:
	.string "¡Has evitado responder!$"
	
GymGooses_Text_GymGuideAdvice:
	.string "¡Ya veo que has llegado lejos!\p"
	
	.string "Te doy la bienvenida al gimnasio\n"
	.string "de GOOSES, la bruja amante de\l"
	.string "los tableros.\p"

	.string "La pruebas de este GYM son:\n"
	.string "Completar los 3 TABLEROS de DADOS\l"
	.string "Derrotar al POKéMON TOTEM\l"
	.string "Derrotar al LÍDER de GYM\p"
	
	.string "Si consigues superar las pruebas,\n"
	.string "se te recompensará con la no-oficial\l"
	.string "MEDALLA FRÍO INVERNAL.\p"

	.string "Bien, te voy a explicar en que consiste\n"
	.string "la prueba principal: TABLERO de DADOS.\p"
	
	.string "El tablero de dados consiste en avanzar\n"
	.string "casillas usando dados aleatorios del\l"
	.string "1 al 6.\p"
	
	.string "Avanzarás casillas según el número que\n"
	.string "aparezca, pero tendrás que afrontar\l"
	.string "desafios según la casilla en la que\l"
	.string "caigas.\p"
	
	.string "Te explicaré la función de cada casilla:\p"

	.string "Casilla Naranja: Te permite tirar un dado\n"
	.string "del 1 al 6.\p"
	
	.string "Casilla Direccional: Te permite avanzar\n"
	.string "una casilla.\p"

	.string "Casilla Salto: Nada útil, solo haces que\n"
	.string "des un salto en el sitio.\p"

	.string "Casilla Pokéball: Combatirás contra\n"
	.string "un entrenador generado con un equipo\l"
	.string "generado de forma aleatoria.\p"

	.string "Casilla Morada: Tendrás que responder de\n"
	.string "forma correcta a una pregunta.\p"

	.string "Casilla Musical: Tus POKéMON pueden\n"
	.string "caer en un estado alterado aleatorio.\p"	

	.string "En cuanto al LÍDER GOOSES, solo te puedo\n"
	.string "decir... ¡Que tengas mucho cuidado\l" 
	.string "con las congelaciones!\p"

	.string "¡Buen hax!$"

GymGooses_Text_GymGuidePostVictory:
	.string "¡FLIPANDING! ¡No solo has completado\n"
	.string "los tableros, sino que también has\l"
	.string "vencido a GOOSES!$"
	
GymGooses_Text_GymStatue:
	.string "POKéMON GYM Nº3\n"
	.string "LÍDER: GOOSES\l"
	.string "“TEMÁTICA: FRÍO INVERNAL”$"

GymGooses_Text_GymStatueCertified:
	.string "POKéMON GYM Nº3\n"
	.string "LÍDER: GOOSES\l"
	.string "“TEMÁTICA: FRÍO INVERNAL”\p"

	.string "GOOSES'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
	
GymGooses_TeleportGirl_Text:
	.string "Si quieres salir del GYM, te puedo\n"
	.string "regresar a la entrada.\p"

	.string "¿Quieres que te lleve a la entrada\n"
	.string "del GYM?$"
	
GymGooses_TeleportBoy_Text:
	.string "¡Vaya! ¡Así que has superado\n"
	.string "los 3 tableros de dados logrando\l"
	.string "llegar hasta la Cuarta Sala!\p"
	
	.string "¡Mis más sinceras felicitaciones!\p"

	.string "Por cierto, si quieres salir\n"
	.string "del GYM, te puedo regresar a la\l"
	.string "entrada. Eso sí, ahora podrás\l" 
	.string "volver a esta misma sala con la\l"
	.string "ayuda de mi otro compañero.\p"

	.string "¿Quieres que te lleve a la entrada\n"
	.string "del GYM?$"
	
GymGooses_TeleportBoy2_Text:
	.string "Debido a que has superado los\n"
	.string "3 tableros de dados, ahora puedes\l"
	.string "elegir entre superar de nuevo los\l"
	.string "tableros o hacer que te lleve de\l"
	.string "nuevo a la Cuarta Sala.\p"

	.string "¿Quieres que te lleve a la Cuarta\n"
	.string "Sala del GYM?$"
	
GymGooses_Text_GoosesIntro:
	.string "Hola de nuevo, joven aspirante. Has\n"
	.string "conseguido llegar hasta mí... ¿Cómo ha\l"
	.string "sido tu viaje? ¿Qué has aprendido?\l"
	.string "¿Qué has experimentado?...\p"
	.string "¿Qué por qué me interesa? Fufufufu, en\n"
	.string "verdad eres osado... Es solo natural,\l"
	.string "siempre deseo conocimiento. He viajado\l"
	.string "para saber todo sobre los POKéMON y\l"
	.string "los secretos del mundo.\p"
	.string "Siempre estoy dispuesta a saciar mis\n"
	.string "ansias de conocimiento y tú, criatura,\l"
	.string "guardas muchos secretos.\p"
	.string "Has pasado las pruebas del helado\n"
	.string "vacío para llegar a mí, tu espíritu es\l"
	.string "fuerte y tu determinación excepcional.\p"
	.string "Yo también pasé por esas pruebas...\n"
	.string "Aquellos que se adaptan al frío, que se\l"
	.string "hacen uno con el vacío y sobreviven...\l"
	.string "son aquellos que portan la bendición y\l"
	.string "la maldición del conocimiento.\p"
	.string "No solo el hielo acecha más allá de los\n"
	.string "umbrales del mundo...\p"
	.string "Te mostraré... el verdadero poder de la\n"
	.string "bruja del hielo. Entretenme, mi pequeña\l"
	.string "criatura...\p"
	.string "¡Muéstrame que tienes lo necesario!$"
	
GymGooses_Text_GoosesDefeat:
	.string "...Excelente respuesta fufufu. Has\n"
	.string "superado la prueba... eres quien\l"
	.string "estaba esperando, aquel que\l"
	.string "llevará al brillante futuro.$"
	
GymGooses_Text_GoosesPostBattle:
	.string "...¿Oh? ¿Que por qué sonrío? Fufufu,\n"
	.string "eres observador.\p"
	.string "¿Crees que la derrota no puede\n"
	.string "complacerme? La victoria y la derrota...\l"
	.string "la vida y la muerte... son algo parte del\l"
	.string "curso natural del mundo. Siempre\l"
	.string "llegan.\p"
	.string "Además, cool kid, tu respuesta ha sido\n"
	.string "nuevamente formidable. Has seguido\l"
	.string "aquel consejo, ¿verdad?\p"
	.string "Mantenlo presente, sigue tus principios\n"
	.string "y no te traiciones. Tu futuro brillará,\l"
	.string "lo garantizo con mi título de bruja.\p"
	.string "Ahora debes ir a por DARKIZARD y el\n"
	.string "viejo rey MICOLO. Ya solo son una sombra\l"
	.string "enajenada de sus antiguos seres...\p"
	.string "Véncelos y yo me ocuparé del resto.\p"
	.string "¿Que si no le sirvo a MICOLO? Bueno,\n"
	.string "antaño le serví, ahora sigo mi propio\l"
	.string "camino para evitar una catástrofe...\p"
	.string "Si siguen así desataran el poder de una\n"
	.string "bruja capaz de engullir el mundo, lo he\l"
	.string "visto...\p"
	.string "Ve, confío en que me mostrarás el más\n"
	.string "formidable de los futuros.$"
	
GymGooses_Text_GoosesRematchIntro:
	.string "Hola de nuevo, criatura. Has\n"
	.string "recorrido un largo camino y vencido a\l"
	.string "todos, ¿por qué no me demuestras si de\l"
	.string "verdad mereces el título de campeón?\p"
	.string "No te preocupes... No me contendré.$"

GymGooses_Text_GoosesRematchDefeat:
	.string "Nunca decepcionas, ¿verdad? Con cada\n"
	.string "combate contigo aprendo algo nuevo...\l"
	.string "vuelve cuando quieras compartir más\l"
	.string "conocimiento conmigo fufufu.$"
	
GymGooses_Text_ReceivedBadge:
	.string "{PLAYER} recibió la MEDALLA FRÍO\n"
	.string "INVERNAL de GOOSES.$"

GymGooses_Text_ExplainBadgeTakeThis:
	.string "Esta es tu recompensa por tu respuesta\n"
	.string "final. Con la MEDALLA FRÍO INVERNAL\l"
	.string "te obedecerá sin rechistar todo\l"
	.string "POKéMON intercambiado que no sea\l"
	.string "superior al nivel 95.\p"
	.string "Finalmente, esta medalla te capacita\n"
	.string "para afrontar el reto de DARKIZARD, en\l"
	.string "el último GYM. Ese necio ha permitido\l"
	.string "que el HATE sobre DPP y ALOLA le\l"
	.string "consumiera y desbordara. Debes\l"
	.string "pararle y detener sus planes, LYLIA no\l"
	.string "hizo nada malo.\p"
	.string "Te deseo la mejor de las suertes... ¡La\n"
	.string "necesitarás!$"
	
GymGooses_Text_Totemaparece:
	.string "M-GLALIE, the TOTEM POKéMON of\n"
	.string "GOOSES GYM, has appeared!$"
	
GymGooses_Text_Totemderrotado:
	.string "M-GLALIE disappeared...$"
	
GymGooses_Text_Comienza:
	.string "¿Todo listo para comenzar\n"
	.string "la prueba del GYM?$"
	
GymGooses_Text_Jugardenuevo:
	.string "Debido a que has completado el GYM,\n" 
	.string "ahora podrás jugar la prueba del\l"
	.string "tablero todas las veces que quieras,\l"
	.string "pero sin ningún premio a conseguir.\p"
	
	.string "¿Todo listo para comenzar\n"
	.string "la prueba?$"
	
GymGooses_Text_Curacion:
	.string "Antes de comenzar la prueba,\n"
	.string "tu equipo será curado.\p"
	
	.string "¡ADELANTE!$"
	
LevelCapItem_Text_GymGooses:
	.string "LEVEL CAP: Actualización completada.\n"
	.string "El nuevo límite es el nivel 95.$"
