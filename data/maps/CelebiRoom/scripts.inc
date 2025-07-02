CelebiRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CelebiRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, CelebiRoom_OnTransition
	.byte 0
	
CelebiRoom_OnResume: 
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CelebiRoom_EventScript_TryRemoveCelebi
	end
	
CelebiRoom_OnTransition:
	call_if_unset FLAG_CAUGHT_CELEBI, CelebiRoom_EventScript_TryShowCelebi
	end
	
CelebiRoom_EventScript_TryRemoveCelebi::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject 1
	return

CelebiRoom_EventScript_HideCelebi::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_CELEBI
	return

CelebiRoom_EventScript_TryShowCelebi::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_CELEBI, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_CELEBI
	return

CelebiRoom_EventScript_Celebi::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CELEBI, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_CELEBI, 60, ITEM_LUM_BERRY
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CelebiRoom_EventScript_DefeatedCelebi
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq CelebiRoom_EventScript_RanFromCelebi
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq CelebiRoom_EventScript_RanFromCelebi
	setflag FLAG_CAUGHT_CELEBI
	release
	end

CelebiRoom_EventScript_DefeatedCelebi:: 
	setflag FLAG_DEFEATED_CELEBI
	goto Common_EventScript_RemoveStaticPokemon
	end

CelebiRoom_EventScript_RanFromCelebi:: 
	setvar VAR_0x8004, SPECIES_CELEBI
	goto Common_EventScript_LegendaryFlewAway
	end
	
CelebiRoom_EventScript_Warp::
	closemessage
	delay 30
	warp MAP_MICOLANDIA_TEMPLE_OF_TIME3, 2, 0, 0
	waitstate
	releaseall
	end
