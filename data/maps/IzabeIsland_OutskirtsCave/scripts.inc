IzabeIsland_OutskirtsCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IzabeIsland_OutskirtsCave_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, IzabeIsland_OutskirtsCave_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, IzabeIsland_OutskirtsCave_OnResume
	.byte 0

IzabeIsland_OutskirtsCave_OnTransition::
	compare VAR_IZABE_ISLAND_STATE, 2
	call_if_eq IzabeIsland_OutskirtsCave_EventScript_HideLavender
	call_if_set FLAG_CAUGHT_REGIGIGAS, IzabeIsland_OutskirtsCave_EventScript_HideRegigigas
	call_if_unset FLAG_CAUGHT_REGIGIGAS, IzabeIsland_OutskirtsCave_EventScript_TryShowRegigigas
	end

IzabeIsland_OutskirtsCave_OnLoad::
	call_if_unset FLAG_SYS_BRAILLE_SHOWN_THREE_REGI, IzabeIsland_OutskirtsCave_EventScript_CloseRegiEntrance
	end

IzabeIsland_OutskirtsCave_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, IzabeIsland_OutskirtsCave_EventScript_TryRemoveRegigigas
	end

IzabeIsland_OutskirtsCave_EventScript_TryRemoveRegigigas::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject 3
	return

IzabeIsland_OutskirtsCave_EventScript_HideRegigigas::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_REGIGIGAS
	return

IzabeIsland_OutskirtsCave_EventScript_TryShowRegigigas::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_REGIGIGAS, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_REGIGIGAS
	return

IzabeIsland_OutskirtsCave_EventScript_Regigigas::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIGIGAS, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIGIGAS, 1, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq IzabeIsland_OutskirtsCave_EventScript_DefeatedRegigigas
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq IzabeIsland_OutskirtsCave_EventScript_RanFromRegigigas
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq IzabeIsland_OutskirtsCave_EventScript_RanFromRegigigas
	setflag FLAG_CAUGHT_REGIGIGAS
	release
	end

IzabeIsland_OutskirtsCave_EventScript_DefeatedRegigigas:: @ 8238F9F
	setflag FLAG_DEFEATED_REGIGIGAS
	goto Common_EventScript_RemoveStaticPokemon
	end

IzabeIsland_OutskirtsCave_EventScript_RanFromRegigigas:: @ 8238FA8
	setvar VAR_0x8004, SPECIES_REGIGIGAS
	goto Common_EventScript_LegendaryFlewAway
	end

IzabeIsland_OutskirtsCave_EventScript_CloseRegiEntrance::
	setmetatile 7, 24, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 8, 24, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 9, 24, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 7, 23, METATILE_Cave_EntranceCover, 1
	setmetatile 8, 23, METATILE_Cave_EntranceCover, 1
	setmetatile 9, 23, METATILE_Cave_EntranceCover, 1
	return

IzabeIsland_OutskirtsCave_EventScript_OpenRegiEntrance::
	setmetatile 7, 24, METATILE_Cave_SealedChamberEntrance_BottomLeft, 1
	setmetatile 8, 24, METATILE_Cave_SealedChamberEntrance_BottomMid, 0
	setmetatile 9, 24, METATILE_Cave_SealedChamberEntrance_BottomRight, 1
	setmetatile 7, 23, METATILE_Cave_SealedChamberEntrance_TopLeft, 1
	setmetatile 8, 23, METATILE_Cave_SealedChamberEntrance_TopMid, 1
	setmetatile 9, 23, METATILE_Cave_SealedChamberEntrance_TopRight, 1
	return

IzabeIsland_OutskirtsCave_EventScript_HideLavender::
	removeobject 2
	end

IzabeIsland_OutskirtsCave_EventScript_Totem::
	lockall
	msgbox DesafiarTotem_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq IzabeIsland_OutskirtsCave_EventScript_Totem2
	releaseall
	end	
	
IzabeIsland_OutskirtsCave_EventScript_Totem2::	
	playmoncry SPECIES_WINTASS, 2
	delay 40
	waitmoncry
	msgbox IzabeIsland_OutskirtsCave_Text_TotemAppears, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_WINTASS
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
	setvar VAR_LAST_TALKED, 1
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	call_if_eq IzabeIsland_OutskirtsCave_EventScript_Totem_Won
	releaseall
	end

IzabeIsland_OutskirtsCave_EventScript_Totem_Won::
	setflag FLAG_DEFEATED_IZABE_TOTEM
	removeobject 1
	msgbox IzabeIsland_OutskirtsCave_Text_TotemDisappears
	return

IzabeIsland_OutskirtsCave_EventScript_Braille_ThreeRegi::
	lockall
	call IzabeIsland_OutskirtsCave_EventScript_TryOpenWall
	releaseall
	end

IzabeIsland_OutskirtsCave_EventScript_InnerRoomEntranceWall::
	lockall
	goto_if_set FLAG_SYS_BRAILLE_SHOWN_THREE_REGI, SealedChamber_OuterRoom_EventScript_HoleInWall
	call IzabeIsland_OutskirtsCave_EventScript_TryOpenWall
	releaseall
	end

IzabeIsland_OutskirtsCave_EventScript_TryOpenWall:
	braillemessage IzabeIsland_OutskirtsCave_Braille_ThreeRegi
	waitbuttonpress
	closebraillemessage
	goto_if_set FLAG_SYS_BRAILLE_SHOWN_THREE_REGI, IzabeIsland_OutskirtsCave_EventScript_NoEffect
	specialvar VAR_RESULT, CheckThreeRegi
	compare VAR_RESULT, FALSE
	goto_if_eq IzabeIsland_OutskirtsCave_EventScript_NoEffect
	fadeoutbgm 0
	playse SE_TRACK_MOVE
	special DoSealedChamberShakingEffect1
	waitstate
	delay 40
	special DoSealedChamberShakingEffect2
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect2
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect2
	waitstate
	playse SE_DOOR
	delay 40
	call IzabeIsland_OutskirtsCave_EventScript_OpenRegiEntrance
	special DrawWholeMapView
	msgbox IzabeIsland_OutskirtsCave_Text_DoorOpen, MSGBOX_DEFAULT
	closemessage
	fadeinbgm 0
	setflag FLAG_SYS_BRAILLE_SHOWN_THREE_REGI
	return

IzabeIsland_OutskirtsCave_EventScript_NoEffect::
	releaseall
	end

IzabeIsland_OutskirtsCave_EventScript_Lavender::
	lockall
	faceplayer
	compare VAR_TEMP_2, 1
	goto_if_eq IzabeIsland_OutskirtsCave_EventScript_Lavender_AskFight
	msgbox IzabeIsland_OutskirtsCave_Text_Lavender_ExplainSituation, MSGBOX_NPC
	setvar VAR_TEMP_2, 1
IzabeIsland_OutskirtsCave_EventScript_Lavender_AskFight:
	msgbox IzabeIsland_OutskirtsCave_Text_Lavender_AskFight, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq IzabeIsland_OutskirtsCave_EventScript_Lavender_NoFight
	msgbox IzabeIsland_OutskirtsCave_Text_Lavender_LetsFight, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_IZABE_LAVENDER, IzabeIsland_OutskirtsCave_Text_Lavender_BattleDefeated

	msgbox IzabeIsland_OutskirtsCave_Text_Lavender_TryGiveItem, MSGBOX_DEFAULT
	giveitem ITEM_HM02
	setflag FLAG_RECEIVED_HM02
	setvar VAR_IZABE_ISLAND_STATE, 2
	msgbox IzabeIsland_OutskirtsCave_Text_Lavender_UpgradeMusicPlayer, MSGBOX_DEFAULT
	setvar VAR_MUSIC_PLAYER, MUSIC_PLAYER_STATE_IZABE
	playse SE_TK_KASYA
	delay 10
	playfanfare MUS_FANFA4
	msgbox IzabeIsland_OutskirtsCave_Text_Lavender_MusicPlayerUpgraded, MSGBOX_DEFAULT
	waitfanfare
	msgbox IzabeIsland_OutskirtsCave_Text_Lavender_Bye, MSGBOX_DEFAULT

	applymovement 2, IzabeIsland_OutskirtsCave_Movement_LavenderSpin
	waitmovement 0
	playse SE_W153
	applymovement 2, IzabeIsland_OutskirtsCave_Movement_LavenderJumpAway
	waitmovement 0
	removeobject 2
	releaseall
	end

IzabeIsland_OutskirtsCave_EventScript_Lavender_NoFight:
	msgbox IzabeIsland_OutskirtsCave_Text_Lavender_NoFight, MSGBOX_DEFAULT
	releaseall
	end

IzabeIsland_OutskirtsCave_Movement_LavenderSpin:
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	step_end

IzabeIsland_OutskirtsCave_Movement_LavenderJumpAway:
	face_up
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

IzabeIsland_OutskirtsCave_Text_Lavender_ExplainSituation::
	.string "¿Eh? ¿Quién eres? ¿Que GARM te dijo \n"
	.string "que fueras a buscarme porque pensaba\l"
	.string "que me había perdido? En fin...\p"
	.string "Solo había venido aquí a investigar,\n"
	.string "supongo que me entretuve demasiado.\p"
	.string "Por cierto, intuyo habrás visto a ese\n"
	.string "TOTEM... tengo información sobre él.\p"
	.string "¿Cómo? ¿Que quieres saberla? Bueno, si\n"
	.string "me derrotas te la diré.$"

IzabeIsland_OutskirtsCave_Text_Lavender_AskFight:
	.string "¿Todo listo para el combate?$"

IzabeIsland_OutskirtsCave_Text_Lavender_LetsFight:
	.string "¡Vamos a ello!$"

IzabeIsland_OutskirtsCave_Text_Lavender_NoFight:
	.string "¡Date prisa!\p"
	.string "No me moveré de aquí hasta que me\n"
	.string "hayas derrotado.$"

IzabeIsland_OutskirtsCave_Text_Lavender_BattleDefeated::
	.string "Vaya... buen hax...\n"
	.string "Te odio.$"

IzabeIsland_OutskirtsCave_Text_Lavender_TryGiveItem::
	.string "LAVENDER: esos TOTEMS han sido creados\n"
	.string "por MICOLO, el científico legendario.\p"
	.string "MICOLO solía vivir en esta ISLA,\n"
	.string "pero un día desapareció.\p"
	.string "Sin embargo, parece que MICOLO ha vuelto\n"
	.string "a la región. Deberías tener cuidado...\p"
	.string "Cambiando de tema, gracias por ayudar a\n"
	.string "GARM, te daré algo por las molestias.$"

IzabeIsland_OutskirtsCave_Text_DoorOpen::
	.string "Se ha abierto un agujero en la pared.$"

IzabeIsland_OutskirtsCave_Text_TotemAppears:
	.string "WINTASS, the TOTEM POKéMON of\n" 
	.string "IZABE ISLAND, has appeared!$"

IzabeIsland_OutskirtsCave_Text_TotemDisappears:
	.string "WINTASS disappeared...$"

IzabeIsland_OutskirtsCave_Text_Lavender_UpgradeMusicPlayer:
	.string "Oh, ¿tienes un MUSIC PLAYER? ¿Dónde lo\n"
	.string "conseguiste?\p"
	.string "Bueno, da igual. ¿Sabías que puede ser\n"
	.string "actualizado con unos aparatos\l"
	.string "llamados TARJETAS DE EXPANSIÓN? Y yo\l"
	.string "tengo una justo aquí. Déjame que te lo\l"
	.string "actualice.$"

IzabeIsland_OutskirtsCave_Text_Lavender_Bye:
	.string "LAVENDER: Ahora podrás escuchar una\n"
	.string "mayor variedad de canciones, prúebalo.\p"
	.string "Dicho esto... ¡hasta la vista!$"

IzabeIsland_OutskirtsCave_Text_Lavender_MusicPlayerUpgraded::
	.string "¡Tu MUSIC PLAYER ha sido mejorado!$"
