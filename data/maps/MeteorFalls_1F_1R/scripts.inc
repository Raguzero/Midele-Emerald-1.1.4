MeteorFalls_1F_1R_MapScripts:: @ 822BD2A
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

MeteorFalls_1F_1R_OnLoad: @ 822BD30
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave:: @ 822BD3A
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, 1
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, 1
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, 0
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, 1
	return

MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene:: @ 822BD5F
	lockall
	playbgm MUS_MGM0, 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement 5, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceFastestUp
	applymovement 6, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
	closemessage
	applymovement 5, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement 5, Common_Movement_WalkInPlaceFastestLeft
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	addobject 7
	addobject 8
	addobject 9
	playbgm MUS_AQA_0, 0
	applymovement 7, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement 8, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement 9, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	applymovement 5, Common_Movement_WalkInPlaceFastestLeft
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement 5, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	applymovement 6, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
	waitmovement 0
	removeobject 5
	removeobject 6
	applymovement 7, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement 8, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement 9, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	applymovement 7, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement 7, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement 8, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement 9, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	waitmovement 0
	fadedefaultbgm
	removeobject 7
	removeobject 8
	removeobject 9
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	// MICOLO EVENT
	clearflag FLAG_HIDE_MICOLO_METEORFALL
	playbgm THATPERSONSNAMEIS, 1
	addobject 11
	playse SE_PIN
	applymovement 11, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 11, MeteorFalls_1F_1R_Movement_Micolo	
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	speakername CommonName_Text_Micolo
	msgbox MeteorFalls_1F_1R_Text_Micolo, MSGBOX_DEFAULT
	closemessage
	speakername NULL

	setvar VAR_TEMP_1, SPECIES_ZUBAT
	givecustommon SPECIES_ZUBAT, 23, ITEM_SOOTHE_BELL, ITEM_LUXURY_BALL, NATURE_HASTY, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_FLAMETHROWER, MOVE_ICE_BEAM, MOVE_AERIAL_ACE, MOVE_SLUDGE_BOMB, TRUE
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_1F_1R_EventScript_ReceiveMonParty
	compare VAR_RESULT, 1
	goto_if_eq MeteorFalls_1F_1R_EventScript_ReceiveMonPC
	// Si no hay sitio para más Pokémon, el ZUBAT se pierde.
	goto Common_EventScript_NoMoreRoomForPokemon 
MeteorFalls_1F_1R_EventScript_ReceiveMonEnd:
	speakername CommonName_Text_Micolo
	msgbox MeteorFalls_1F_1R_Text_MicoloBye, MSGBOX_DEFAULT
	closemessage
	fadescreen 1
	delay 30
	removeobject 11
	delay 30
	fadescreen 0
	fadedefaultbgm
	setflag FLAG_HIDE_MICOLO_METEORFALL
	// MICOLO EVENT
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

MeteorFalls_1F_1R_EventScript_ReceiveMonParty:: @ 8270085
	call MeteorFalls_1F_1R_EventScript_ReceiveMonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MeteorFalls_1F_1R_EventScript_ReceiveMonEnd
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MeteorFalls_1F_1R_EventScript_ReceiveMonEnd
	end

MeteorFalls_1F_1R_EventScript_ReceiveMonPC:: @ 82700AD
	call MeteorFalls_1F_1R_EventScript_ReceiveMonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MeteorFalls_1F_1R_EventScript_SendMonPC
	call Common_EventScript_NameReceivedBoxMon
	goto MeteorFalls_1F_1R_EventScript_SendMonPC
	end
	
MeteorFalls_1F_1R_EventScript_SendMonPC:: @ 82700D0
	call Common_EventScript_TransferredToPC
	goto MeteorFalls_1F_1R_EventScript_ReceiveMonEnd
	end

MeteorFalls_1F_1R_EventScript_ReceiveMonFanfare:: @ 82700DB
	playfanfare MUS_FANFA4
	message MeteorFalls_1F_1R_Text_ReceivedMon
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_ZUBAT
	return

MeteorFalls_1F_1R_Movement_Micolo:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer: @ 822BEC0
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit: @ 822BEC4
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit: @ 822BECE
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive: @ 822BED9
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive: @ 822BEE0
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive: @ 822BEE8
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit: @ 822BEF0
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer: @ 822BEF8
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_fastest_left
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit: @ 822BEFE
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie: @ 822BF08
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit: @ 822BF0D
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie: @ 822BF18
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay: @ 822BF1D
	walk_in_place_fastest_down
	delay_4
	walk_in_place_fastest_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_EventScript_ProfCozmo:: @ 822BF25
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	setflag FLAG_MET_PROF_COZMO
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo:: @ 822BF3D
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_WithThisMeteorite: @ 822BF47
	.string "Hehehe!\p"
	.string "With this METEORITE, that thing in\n"
	.string "MT. CHIMNEY will…$"

MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma: @ 822BF84
	.string "Heh?\p"
	.string "I don't know who you are, but if you get\n"
	.string "in the way of TEAM MAGMA, don't\l"
	.string "expect any mercy!$"

MeteorFalls_1F_1R_Text_HoldItRightThereMagma: @ 822BFE4
	.string "Hold it right there, TEAM MAGMA!\p"
	.string "You're badly mistaken if you think you\n"
	.string "can have your way with the world!$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua: @ 822C04E
	.string "Hehehe!\n"
	.string "Even TEAM AQUA joins us!\p"
	.string "But it's too much trouble to deal with\n"
	.string "you all…\p"
	.string "Heh, it doesn't matter!\p"
	.string "We've got the METEORITE, so off to\n"
	.string "MT. CHIMNEY we go!\p"
	.string "Hehehe! Be seeing you, you TEAM\n"
	.string "AQUA dingbats!$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore: @ 822C11C
	.string "ARCHIE: Didn't I see you before?\n"
	.string "At SLATEPORT's MUSEUM?\p"
	.string "Ah, so your name is {PLAYER}.\p"
	.string "At the time, I thought you were one\n"
	.string "of TEAM MAGMA's goons.\p"
	.string "Humph…\n"
	.string "You're one odd kid.\p"
	.string "TEAM MAGMA is a dangerous group of\n"
	.string "total fanatics.\p"
	.string "They engage in destruction, claiming\n"
	.string "to expand the land mass.\p"
	.string "They are the rivals to us,\n"
	.string "the sea-loving TEAM AQUA!$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma: @ 822C268
	.string "BOSS, we should give chase to\n"
	.string "TEAM MAGMA…$"

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo: @ 822C292
	.string "ARCHIE: Yes, yes, we must!\n"
	.string "We've got to hurry.\p"
	.string "There's no telling what TEAM MAGMA\n"
	.string "will do at MT. CHIMNEY!$"

MeteorFalls_1F_1R_Text_ArchieFarewell: @ 822C2FC
	.string "ARCHIE: {PLAYER}, you should keep\n"
	.string "an eye out for TEAM MAGMA, too.\p"
	.string "Farewell!$"

MeteorFalls_1F_1R_Text_MeetProfCozmo: @ 822C342
	.string "I… I'm COZMO…\n"
	.string "I'm a PROFESSOR…\p"
	.string "TEAM MAGMA asked me to guide them\n"
	.string "to METEOR FALLS…\p"
	.string "But they tricked me.\n"
	.string "They even took my METEORITE away…\p"
	.string "And then another similar bunch,\n"
	.string "TEAM AQUA showed up.\p"
	.string "After that…\n"
	.string "I don't understand any of it.\p"
	.string "But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney: @ 822C47D
	.string "PROF. COZMO: But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"
	
MeteorFalls_1F_1R_Text_Micolo: 
	.string "MAXIE y ARCHIE, jefes y líderes\n"
	.string "de TEAM MAGMA y TEAM AQUA, solo son\l"
	.string "dos chiflados con un sueño absurdo y\l"
	.string "una chorrada de idea.\p"


	.string "El TEAM MAGMA quiere invocar\n"
	.string "al POKéMON legendario GROUDON\l"
	.string "para secar los mares y hacer\l"
	.string "que la humanidad tenga\l"
	.string "mayor tierra donde vivir.\p"
	
	.string "Mientras que el TEAM AQUA quiere\n"
	.string "invocar al POKéMON legendario KYOGRE\l"
	.string "para que haya más cantidad de mar\l"
	.string "donde puedan vivir los POKéMON.\p"

	.string "Sus planes no tienen ninguna\n"
	.string "lógica. ¡Piénsalo!\p"	

	.string "Si secan los mares, los\n"
	.string "humanos nos quedamos sin agua\l"
	.string "para poder sobrevivir n.n\p"
	
	.string "Mientras que si aumentan el\n"
	.string "nivel de mar...\p"
	
	.string "¡NOS AHOGAMOS TODOS!\p"
	
	.string "¡Que tontos del culo!\n"
	.string "LOOOOOOOOOOOOOOOOOOL\p"
	
	.string "Pero no te preocupes,\n"
	.string "todos sus planes saldrán mal\l"
	.string "porque tú les pararás los pies...\l"
	.string "¡Humilla a sus reclutas sin piedad!\p"
	
	.string "...\p"
	
	.string "Por cierto, me gustaría darte uno de mis\n"
	.string "POKéMON.\p"
	.string "Lo conseguí en esta cueva, seguro que\n"
	.string "cuidarás de él. Y si no... mi DARK PIKA se\l"
	.string "encargará de humillarte.$"

MeteorFalls_1F_1R_Text_ReceivedMon: @ 82706E8
	.string "{PLAYER} received ZUBAT!$"

MeteorFalls_1F_1R_Text_MicoloBye:
	.string "Estoy seguro de que nos\n"
	.string "volveremos a ver...\p"
	.string "Recuerda, monociclo porque mono es uno\n"
	.string "y la vida es un ciclo.$"
