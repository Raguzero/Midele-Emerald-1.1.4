Route103_MapScripts:: @ 81EC38E
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
	.byte 0

Route103_OnTransition: @ 81EC399
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	end

Route103_OnLoad: @ 81EC3A4
	call_if_set FLAG_SYS_POKEDEX_GET, Route103_EventScript_OpenAlteringCave
	call_if_unset FLAG_REGI_DOORS_OPENED, Route103_EventScript_CloseOldaleRuins
	end

Route103_EventScript_CloseOldaleRuins:: @ 81F0CD1
	setmetatile 23, 18, METATILE_General_RockWall_RockBase, 1
	setmetatile 23, 19, METATILE_General_RockWall_SandBase, 1
	return

Route103_EventScript_OpenAlteringCave:: @ 81EC3AE
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, 1
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, 0
	return

Route103_EventScript_Rival:: @ 81EC3C1
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_RivalMay
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_RivalBrendan
	end

Route103_EventScript_RivalMay:: @ 81EC3DA
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_GIRL_SUP, 1
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleTreecko
	case 1, Route103_EventScript_StartMayBattleTorchic
	case 2, Route103_EventScript_StartMayBattleMudkip
	end

Route103_EventScript_RivalBrendan:: @ 81EC434
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_BOY_SUP, 1
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleTreecko
	case 1, Route103_EventScript_StartBrendanBattleTorchic
	case 2, Route103_EventScript_StartBrendanBattleMudkip
	end

Route103_EventScript_StartMayBattleTreecko:: @ 81EC48E
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTorchic:: @ 81EC49E
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleMudkip:: @ 81EC4AE
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartBrendanBattleTreecko:: @ 81EC4BE
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleTorchic:: @ 81EC4CE
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleMudkip:: @ 81EC4DE
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_AfterMayBattle:: @ 81EC4EE
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_AfterBrendanBattle:: @ 81EC4FC
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_RivalExit:: @ 81EC50A
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
	end

Route103_EventScript_RivalExitFacingNorth:: @ 81EC53D
	applymovement EVENT_OBJ_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
	applymovement 2, Route103_Movement_RivalExitFacingNorth1
	waitmovement 0
	playse SE_DANSA
	applymovement 2, Route103_EventScript_RivalExitFacingNorth2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingEastOrWest:: @ 81EC561
	applymovement EVENT_OBJ_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
	applymovement 2, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_DANSA
	applymovement 2, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingSouth:: @ 81EC585
	applymovement 2, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_DANSA
	applymovement 2, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalEnd:: @ 81EC5A2
	removeobject 2
	setvar VAR_BIRCH_LAB_STATE, 4
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 1
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route103_Movement_RivalExitFacingNorth1: @ 81EC5BE
	walk_left
	walk_down
	step_end

Route103_EventScript_RivalExitFacingNorth2: @ 81EC5C1
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingNorth: @ 81EC5C8
	delay_16
	delay_4
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end

Route103_Movement_RivalExit1: @ 81EC5CE
	walk_down
	step_end

Route103_Movement_RivalExit2: @ 81EC5D0
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingEastOrWest: @ 81EC5D6
	delay_16
	walk_in_place_fastest_down
	step_end

Route103_EventScript_Boy:: @ 81EC5D9
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
	end

Route103_EventScript_Man:: @ 81EC5E2
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
	end

Route103_EventScript_RouteSign:: @ 81EC5EB
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
	end

Route103_EventScript_Daisy:: @ 81EC5F4
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Amy:: @ 81EC60B
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route102_EventScript_AmyRematch
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_AmyRegisterMatchCallAfterBattle:: @ 81EC63A
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_AmyRematch:: @ 81EC653
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Liv:: @ 81EC66E
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route102_EventScript_LivRematch
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_LivRegisterMatchCallAfterBattle:: @ 81EC69D
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_LivRematch:: @ 81EC6B6
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Andrew:: @ 81EC6D1
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Miguel:: @ 81EC6E8
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route103_EventScript_MiguelRematch
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_MiguelRegisterMatchCallAfterBattle:: @ 81EC714
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MIGUEL_1
	release
	end

Route103_EventScript_MiguelRematch:: @ 81EC733
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Marcos:: @ 81EC74A
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Rhett:: @ 81EC761
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Pete:: @ 81EC778
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Isabelle:: @ 81EC78F
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_AlteringCaveChanger::	
	lock
	faceplayer
	msgbox Route103_Text_AlteringCaveNPC, MSGBOX_NPC
	showmoneybox 0, 0, 0
	msgbox Route103_Text_AlteringCaveChanger, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route103_EventScript_AlteringCave_NoChange
	hidemoneybox
	msgbox Route103_Text_AlteringCaveChoose, MSGBOX_DEFAULT
	multichoicegrid 0, 0, MULTI_ALTERINGCAVECHANGER, 3, 0
	switch VAR_RESULT
	case 0, Route103_EventScript_AlteringCaveGen1
	case 1, Route103_EventScript_AlteringCaveGen2
	case 2, Route103_EventScript_AlteringCaveGen3
	case 3, Route103_EventScript_AlteringCaveGen4
	case 4, Route103_EventScript_AlteringCaveGen5
	case 5, Route103_EventScript_AlteringCaveGen6
	case 6, Route103_EventScript_AlteringCaveGen7
	case 7, Route103_EventScript_AlteringCaveGen8
	case 8, Route103_EventScript_AlteringCave_NoChange
	case MULTI_B_PRESSED, Route103_EventScript_AlteringCave_NoChange
	end
	
Route103_EventScript_AlteringCave_NoChange::
	hidemoneybox
	msgbox Route103_Text_AlteringCaveNoChange
	release
	end
	
Route103_EventScript_AlteringCave_Actual::
	hidemoneybox
	msgbox Route103_Text_AlteringCave_Actual
	release
	end
	
Route103_EventScript_AlteringCaveGen1::
	compare VAR_ALTERING_CAVE_RND, 0
	call_if_eq Route103_EventScript_AlteringCave_Actual
	showmoneybox 0, 0, 0
	checkmoney 20000, 0
    compare VAR_RESULT, 0
    goto_if_eq Route103_EventScript_NotEnoughMoney
    playse SE_REGI
    removemoney 20000, 0
	delay 8
    updatemoneybox 0, 0
	setvar VAR_ALTERING_CAVE_RND, 0
	msgbox Route103_Text_AlteringCaveGen1
	hidemoneybox
	release
	end
	
Route103_EventScript_AlteringCaveGen2::
	compare VAR_ALTERING_CAVE_RND, 1
	call_if_eq Route103_EventScript_AlteringCave_Actual
	showmoneybox 0, 0, 0
	checkmoney 20000, 0
    compare VAR_RESULT, 0
    goto_if_eq Route103_EventScript_NotEnoughMoney
    playse SE_REGI
    removemoney 20000, 0
	delay 8
    updatemoneybox 0, 0
	setvar VAR_ALTERING_CAVE_RND, 1
	msgbox Route103_Text_AlteringCaveGen2
	hidemoneybox
	release
	end
	
Route103_EventScript_AlteringCaveGen3::
	compare VAR_ALTERING_CAVE_RND, 2
	call_if_eq Route103_EventScript_AlteringCave_Actual
	showmoneybox 0, 0, 0
	checkmoney 20000, 0
    compare VAR_RESULT, 0
    goto_if_eq Route103_EventScript_NotEnoughMoney
    playse SE_REGI
    removemoney 20000, 0
	delay 8
    updatemoneybox 0, 0
	setvar VAR_ALTERING_CAVE_RND, 2
	msgbox Route103_Text_AlteringCaveGen3
	hidemoneybox
	release
	end
	
Route103_EventScript_AlteringCaveGen4::
	compare VAR_ALTERING_CAVE_RND, 3
	call_if_eq Route103_EventScript_AlteringCave_Actual
	showmoneybox 0, 0, 0
	checkmoney 20000, 0
    compare VAR_RESULT, 0
    goto_if_eq Route103_EventScript_NotEnoughMoney
    playse SE_REGI
    removemoney 20000, 0
	delay 8
    updatemoneybox 0, 0
	setvar VAR_ALTERING_CAVE_RND, 3
	msgbox Route103_Text_AlteringCaveGen4
	hidemoneybox
	release
	end
	
Route103_EventScript_AlteringCaveGen5::
	compare VAR_ALTERING_CAVE_RND, 4
	call_if_eq Route103_EventScript_AlteringCave_Actual
	showmoneybox 0, 0, 0
	checkmoney 20000, 0
    compare VAR_RESULT, 0
    goto_if_eq Route103_EventScript_NotEnoughMoney
    playse SE_REGI
    removemoney 20000, 0
	delay 8
    updatemoneybox 0, 0
	setvar VAR_ALTERING_CAVE_RND, 4
	msgbox Route103_Text_AlteringCaveGen5
	hidemoneybox
	release
	end
	
Route103_EventScript_AlteringCaveGen6::
	compare VAR_ALTERING_CAVE_RND, 5
	call_if_eq Route103_EventScript_AlteringCave_Actual
	showmoneybox 0, 0, 0
	checkmoney 20000, 0
    compare VAR_RESULT, 0
    goto_if_eq Route103_EventScript_NotEnoughMoney
    playse SE_REGI
    removemoney 20000, 0
	delay 8
    updatemoneybox 0, 0
	setvar VAR_ALTERING_CAVE_RND, 5
	msgbox Route103_Text_AlteringCaveGen6
	hidemoneybox
	release
	end
	
Route103_EventScript_AlteringCaveGen7::
	compare VAR_ALTERING_CAVE_RND, 6
	call_if_eq Route103_EventScript_AlteringCave_Actual
	showmoneybox 0, 0, 0
	checkmoney 20000, 0
    compare VAR_RESULT, 0
    goto_if_eq Route103_EventScript_NotEnoughMoney
    playse SE_REGI
    removemoney 20000, 0
	delay 8
    updatemoneybox 0, 0
	setvar VAR_ALTERING_CAVE_RND, 6
	msgbox Route103_Text_AlteringCaveGen7
	hidemoneybox
	release
	end
	
Route103_EventScript_AlteringCaveGen8::
	compare VAR_ALTERING_CAVE_RND, 7
	call_if_eq Route103_EventScript_AlteringCave_Actual
	showmoneybox 0, 0, 0
	checkmoney 20000, 0
    compare VAR_RESULT, 0
    goto_if_eq Route103_EventScript_NotEnoughMoney
    playse SE_REGI
    removemoney 20000, 0
	delay 8
    updatemoneybox 0, 0
	setvar VAR_ALTERING_CAVE_RND, 7
	msgbox Route103_Text_AlteringCaveGen8
	hidemoneybox
	release
	end
	
Route103_EventScript_NotEnoughMoney::
	msgbox Route103_Text_NotEnoughMoney
	hidemoneybox
	release
	end

Route103_EventScript_Avader::
	lockall
    goto_if_unset FLAG_ADVENTURE_STARTED, Route103_EventScript_Avader_NoDex
	msgbox Route103_Text_Avader_TalkToHimself, MSGBOX_DEFAULT
	faceplayer
	playse SE_PIN
	applymovement 22, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route103_Text_Avader_BeforeBattle, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_AVADER_OLDALE, Route103_Text_Avader_Defeated
	msgbox Route103_Text_Avader_Text_TakeUnown, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_UNOWN
	givemon SPECIES_UNOWN, 5, ITEM_NONE, FALSE
	compare VAR_RESULT, 0
	goto_if_eq Route103_EventScript_Avader_ReceiveUnownParty
	compare VAR_RESULT, 1
	goto_if_eq Route103_EventScript_Avader_ReceiveUnownPC
	goto Route103_Avader_EventScript_NoRoomForPokemon
	end

Route103_EventScript_Avader_NoDex:
    lockall
    faceplayer
    msgbox Route103_Text_Avader_NoDex, MSGBOX_DEFAULT
    releaseall
    end

Route103_EventScript_Avader_ReceiveUnownParty::
	call Route103_EventScript_Avader_ReceivedUnownFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route103_EventScript_Avader_AfterBattle
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route103_EventScript_Avader_AfterBattle
	end

Route103_EventScript_Avader_ReceiveUnownPC::
	call Route103_EventScript_Avader_ReceivedUnownFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route103_EventScript_Avader_SendUnownToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route103_EventScript_Avader_SendUnownToPC
	end

Route103_EventScript_Avader_SendUnownToPC::
	call Common_EventScript_TransferredToPC
	msgbox Route103_Text_Avader_AfterBattle, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_OLDALE_AVADER
	applymovement 22, Route103_Movement_AvaderSpin
	waitmovement 0
	playse SE_W100
	applymovement 22, Route103_Movement_AvaderJumpaway
	waitmovement 0
	removeobject 22
	releaseall
	end

Route103_EventScript_Avader_ReceivedUnownFanfare::
	playfanfare MUS_FANFA4
	message Route103_Text_Avader_PlayerReceivedUnown
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_UNOWN
	return

Route103_EventScript_Avader_AfterBattle::
	msgbox Route103_Text_Avader_AfterBattle, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_OLDALE_AVADER
	applymovement 22, Route103_Movement_AvaderSpin
	waitmovement 0
	playse SE_W100
	applymovement 22, Route103_Movement_AvaderJumpaway
	waitmovement 0
	removeobject 22
	releaseall
	end
	
Route103_Avader_EventScript_NoRoomForPokemon::
	msgbox Route103_Text_Avader_NoRoomForPokemon, MSGBOX_DEFAULT
	goto Route103_EventScript_Avader_AfterBattle
	end

Route103_Movement_AvaderSpin:
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	step_end

Route103_Movement_AvaderJumpaway:
	face_up
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end
	
Route103_Text_MayRoute103Pokemon: @ 81EC7A6
	.string "{RIVAL}: Let's see… The POKéMON found\n"
	.string "on ROUTE 103 include…$"

Route103_Text_MayLetsBattle: @ 81EC7DE
	.string "Oh, hi, {PLAYER}{KUN}!\p"
	.string "…Oh, I see, my dad gave you\n"
	.string "a POKéMON as a gift.\p"
	.string "Since we're here, let's have a quick\n"
	.string "battle!\p"
	.string "I'll give you a taste of what being\n"
	.string "a TRAINER is like.$"

Route103_Text_MayDefeated: @ 81EC881
	.string "Wow! That's great!\n"
	.string "{PLAYER}{KUN}, you're pretty good!$"

Route103_Text_MayTimeToHeadBack: @ 81EC8AE
	.string "{RIVAL}: I think I know why my dad has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got that POKéMON,\n"
	.string "but it already likes you.\p"
	.string "You might be able to befriend any\n"
	.string "kind of POKéMON easily.\p"
	.string "Well, it's time to head back to\n"
	.string "the LAB.$"

Route103_Text_BrendanRoute103Pokemon: @ 81EC989
	.string "{RIVAL}: Okay, so it's this one and\n"
	.string "that one that live on ROUTE 103…$"

Route103_Text_BrendanLetsBattle: @ 81EC9CE
	.string "Hey, it's {PLAYER}!\p"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
	.string "Since we're here, how about a little\n"
	.string "battle?\p"
	.string "I'll teach you what being a TRAINER's\n"
	.string "about!$"

Route103_Text_BrendanDefeated: @ 81ECA59
	.string "Huh, {PLAYER}, you're not too shabby.$"

Route103_Text_BrendanTimeToHeadBack: @ 81ECA79
	.string "{RIVAL}: I think I get it.\n"
	.string "I think I know why my dad has his eye\l"
	.string "out for you now.\p"
	.string "Look, your POKéMON already likes you,\n"
	.string "even though you just got it.\p"
	.string "{PLAYER}, I get the feeling that you\n"
	.string "could befriend any POKéMON with ease.\p"
	.string "We should head back to the LAB.$"

Route103_Text_ShouldHaveBroughtPotion: @ 81ECB73
	.string "My POKéMON is staggeringly tired…\n"
	.string "I should have brought a POTION…$"

Route103_Text_ShortcutToOldale: @ 81ECBB5
	.string "If you cross the sea from here,\n"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
	.string "Fufufu, that's useful, isn't it?$"

Route103_Text_RouteSign: @ 81ECC1A
	.string "ROUTE 103\n"
	.string "{DOWN_ARROW} OLDALE TOWN$"
	
Route103_Text_AlteringCaveChanger:
	.string "¿Cambiar ALTERING CAVE?$"

Route103_Text_AlteringCaveChoose:
	.string "Elige ALTERING CAVE.$"
	
Route103_Text_AlteringCaveNoChange:
	.string "Vuelve cuando quieras.$"
	
Route103_Text_AlteringCave_Actual:
	.string "El tipo de ALTERING CAVE que elegiste\n"
	.string "es de la misma gen que la actual.\p"
	.string "Elige otra.$"
	
Route103_Text_AlteringCaveGen1:
	.string "ALTERING CAVE ahora es Gen 1.$"

Route103_Text_AlteringCaveGen2:
	.string "ALTERING CAVE ahora es Gen 2.$"
	
Route103_Text_AlteringCaveGen3:
	.string "ALTERING CAVE ahora es Gen 3.$"
	
Route103_Text_AlteringCaveGen4:
	.string "ALTERING CAVE ahora es Gen 4.$"
	
Route103_Text_AlteringCaveGen5:
	.string "ALTERING CAVE ahora es Gen 5.$"
	
Route103_Text_AlteringCaveGen6:
	.string "ALTERING CAVE ahora es Gen 6.$"
	
Route103_Text_AlteringCaveGen7:
	.string "ALTERING CAVE ahora es Gen 7.$"
	
Route103_Text_AlteringCaveGen8:
	.string "ALTERING CAVE ahora es Gen 8.$"
	
Route103_Text_AlteringCaveNPC:
	.string "¿Conoces esta cueva?\p"
	.string "La llaman ALTERING CAVE.\p"

	.string "En ella salen POKéMON especiales\n"
	.string "que van cambiando cada día.\p"

	.string "Eso puede ocasionar un problema\n"
	.string "para atrapar a los POKéMON que buscas.\p"
	
	.string "¡Pero no tienes de qué preocuparte!\p"
	
	.string "Con mis poderes psíquicos, por un\n"
	.string "módico precio de 20000¥, cambiaré\p"
	.string "la forma en que funciona esta cueva\n"
	.string "para elegir qué tipo de POKéMON\p"
	.string "especiales quieres hacer aparecer.\p"
	
	.string "¿Qué te parece? ¿Aceptas el trato?$"
	
Route103_Text_NotEnoughMoney:
	.string "¡Pero si no tienes suficiente dinero!$"

Route103_Text_Avader_TalkToHimself:
	.string "He oído que aquí hay un regi producto de\n"
	.string "la concetración de energía dracónica.\p"
	.string "¿Puede ser usada tal energía para\n"
	.string "ayudar en nuestras investigaciones?$"

Route103_Text_Avader_BeforeBattle:
	.string "¡AH, un niño autista me ha visto!\p"
	.string "Te daré tu merecido con mi\n"
	.string "POKéMON LEGENDARIO.$"

Route103_Text_Avader_Defeated:
	.string "How could this happen, even with\n"
	.string "the apocrypha?$"

Route103_Text_Avader_AfterBattle:
	.string "Seguiremos tu carrera con gran interés.\n"
	.string "Sí... de hecho, me ayudarás.\p"
	.string "Tú resolverás por mí el misterio de estas\n"
	.string "cuevas. Lo harás porque eres autista.\p"
	.string "Y no te acordarás de esta conversación\n"
	.string "para entonces.\p"
	.string "Muajaja, volveremos a vernos.\p"
	.string "¡MEW, teletransporte!$"
	
Route103_Text_Avader_Text_TakeUnown: 
	.string "Por haber alcanzado la gran proeza\n"
	.string "de vencer a mi peor equipo, te mereces\l"
	.string "quedarte con esta basu...\p"

	.string "Quiero decir... ehm...\p"

	.string "¡CON ESTE POKéMON TAN PODEROSO!$"

Route103_Text_Avader_NoRoomForPokemon: 
	.string "¡No tienes sitio para este\n"
	.string "poderoso POKéMON ni en la cajas!\p"
	
	.string "Pues nada, tendré que tirarlo a\n"
	.string "la basura.\p"
	
	.string "En fin.$"

Route103_Text_Avader_PlayerReceivedUnown: 
	.string "{PLAYER} received UNOWN!$"

Route103_Text_Avader_NoDex:
    .string "¿Osas hablar conmigo? Para hacer eso\n"
	.string "antes tendrás que haber jugado\l"
	.string "XENOBLADE.\p"
	.string "Es broma, en este mundo POKéMON no\n"
	.string "existe XENOBLADE. Un mundo\l"
	.string "postapocalíptico, lo sé.\p"
	.string "Sea como sea, ni siquiera tienes una\n"
	.string "POKéDEX, y eso te hace un NOOB de\l"
	.string "manual, así que mejor vete, que no\l"
	.string "quiero que te vean comigo, jeje.$"
