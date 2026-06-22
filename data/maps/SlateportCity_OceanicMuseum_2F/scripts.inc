SlateportCity_OceanicMuseum_2F_MapScripts:: @ 820BAFF
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern:: @ 820BB00
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_AQA_0, 1
	addobject 3
	applymovement 3, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject 4
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement 3, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	compare VAR_FACING, DIR_SOUTH
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	compare VAR_FACING, DIR_EAST
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	compare VAR_FACING, DIR_EAST
	call_if_ne SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	
	@ Micolo
	addobject 8
	applymovement 8, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement 8, SlateportCity_OceanicMuseum_2F_Movement_MicoloApproach
	waitmovement 0
	applymovement 3, Common_Movement_FaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_QuestionMark
	waitmovement 0
	playse SE_PIN
	applymovement 4, Common_Movement_FaceLeft
	waitmovement 0
	applymovement 4, Common_Movement_QuestionMark
	waitmovement 0
	playbgm THATPERSONSNAMEIS, 1 @ Micolo music
	speakername CommonName_Text_Micolo
	msgbox SlateportCity_OceanicMuseum_2F_Text_MicoloAppears, MSGBOX_DEFAULT
	playse SE_W153
	waitse
	msgbox SlateportCity_OceanicMuseum_2F_Text_MicoloDefeatsGrunts, MSGBOX_DEFAULT
	applymovement 3, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntLeave
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntLeave
	waitmovement 0
	removeobject 3
	removeobject 4
	playse SE_KAIDAN
	waitse
	msgbox SlateportCity_OceanicMuseum_2F_Text_MicoloWantsToBattle, MSGBOX_DEFAULT
	applymovement 8, SlateportCity_OceanicMuseum_2F_Movement_MicoloApproachToBattle
	waitmovement 0
	compare VAR_FACING, DIR_SOUTH
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachMicoloSouth
	compare VAR_FACING, DIR_WEST
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachMicoloWest
	trainerbattle_no_intro TRAINER_MICOLO_1, SlateportCity_OceanicMuseum_2F_Text_MicoloDefeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_MicoloLeaves, MSGBOX_DEFAULT
	closemessage
	applymovement 8, SlateportCity_OceanicMuseum_2F_Movement_MicoloLeaves
	waitmovement 0
	removeobject 8
	playse SE_KAIDAN
	waitse
	playbgm MUS_AQA_0, 1
	
	delay 35
	addobject 2
	applymovement 2, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	waitmovement 0
	speakername NULL
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement 2, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty
	removeobject 1
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	compare VAR_REGISTER_BIRCH_STATE, 0
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	setvar VAR_PACOCHEF_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch:: @ 820BC8C
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts:: @ 820BC92
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts:: @ 820BC9D
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachMicoloSouth:: @ 820BCA8
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachMicoloSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachMicoloWest:: @ 820BCB3
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachMicoloWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachMicoloSouth: @ 820BCBE
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachMicoloWest: @ 820BCC2
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused: @ 820BCC8
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer: @ 820BCD6
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter: @ 820BCD8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_MicoloApproachToBattle: @ 820BCE2
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter: @ 820BCE4
	walk_down
	walk_right
	walk_in_place_fastest_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach: @ 820BCE8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter: @ 820BCF3
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach: @ 820BCF5
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_MicoloApproach: @ 820BCE8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntLeave: @ 820BCE4
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_up
	walk_left
	walk_up
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntLeave: @ 820BCF3
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_OceanicMuseum_2F_Movement_MicoloLeaves:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1:: @ 820BD0A
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2:: @ 820BD13
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment:: @ 820BD1C
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel:: @ 820BD25
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay:: @ 820BD2E
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay:: @ 820BD37
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica:: @ 820BD40
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica:: @ 820BD49
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica:: @ 820BD52
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica:: @ 820BD5B
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1:: @ 820BD64
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2:: @ 820BD6D
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3:: @ 820BD76
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts: @ 820BD8D
	.string "Yes? If you're looking for STERN,\n"
	.string "that would be me.\p"
	.string "Ah! Those must be the parts I ordered\n"
	.string "from MR. STONE of DEVON.\p"
	.string "Thank you! That's great!\n"
	.string "We can prepare for our expedition now.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts: @ 820BE40
	.string "Hehehe, hold it!\n"
	.string "We'll take those parts!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou: @ 820BE69
	.string "CAPT. STERN: Wh-what?\n"
	.string "Who are you people?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua: @ 820BE93
	.string "We're TEAM AQUA!\p"
	.string "Our BOSS wants those parts!\n"
	.string "Shut your yap and fork them over!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong: @ 820BFF2
	.string "I came to see what was taking so\n"
	.string "long to snatch some parts, and you\l"
	.string "simps are held up by a mere child?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning: @ 820C059
	.string "We are TEAM AQUA,\n"
	.string "and we love the sea!\p"
	.string "And I am TEAM AQUA's leader,\n"
	.string "ARCHIE!\p"
	.string "What makes you interfere with us?\p"
	.string "…No! You can't be!\n"
	.string "You're not one of TEAM MAGMA?\p"
	.string "Wait, that can't be right.\n"
	.string "You're not dressed for the part.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "POKéMON, people… All life depends on\n"
	.string "the sea.\p"
	.string "So, TEAM AQUA is dedicated to\n"
	.string "the expansion of the sea.\p"
	.string "Don't you agree? What we are doing\n"
	.string "is a magnificent undertaking.\p"
	.string "Ah, fine…\n"
	.string "You're still too young to understand\l"
	.string "our noble objective.\p"
	.string "But, I warn you, don't even consider\n"
	.string "interfering with our plans again.\p"
	.string "The consequences will cost you\n"
	.string "dearly!\p"
	.string "And don't you forget it!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs: @ 820C2BE
	.string "CAPT. STERN: You're…\n"
	.string "Ah, okay, you're {PLAYER}{KUN}…\p"
	.string "Anyway, that was a tense situation!\n"
	.string "Thank you for saving us!\p"
	.string "Oh, yes, I almost forgot that you\n"
	.string "even brought the parts from DEVON!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo: @ 820C36C
	.string "CAPT. STERN: Whoops!\n"
	.string "There's no time to lose!\p"
	.string "We have to set out on our ocean-floor\n"
	.string "expedition really soon.\p"
	.string "Thanks again, but now I've got\n"
	.string "to go!\p"
	.string "Feel free to wander around and check\n"
	.string "out our facilities, though.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip: @ 820C43F
	.string "I saw a model of a ship here.\p"
	.string "It reminded me of the ABANDONED SHIP\n"
	.string "near DEWFORD TOWN…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum: @ 820C495
	.string "Don't you dare run around inside\n"
	.string "the MUSEUM!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine: @ 820C4C2
	.string "Wow, the submarine's awesome!\n"
	.string "I want to go for a ride!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1: @ 820C4F9
	.string "“WATER QUALITY SAMPLE 1,” the\n"
	.string "label says.\p"
	.string "The sea is all connected, but the\n"
	.string "water seems to differ by region.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2: @ 820C566
	.string "“WATER QUALITY SAMPLE 2,” the\n"
	.string "label says.\p"
	.string "Does the saltiness of seawater differ\n"
	.string "by region, too?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment: @ 820C5C6
	.string "A rubber ball is expanding and\n"
	.string "shrinking.\p"
	.string "“In the sea, the weight of water itself\n"
	.string "exerts pressure.\p"
	.string "“In shallow water, the pressure is not\n"
	.string "very heavy.\p"
	.string "“However, in extremely deep water,\n"
	.string "the pressure can reach even tens of\l"
	.string "thousands of tons on a small area.”$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel: @ 820C6C7
	.string "“MODEL OF HOENN REGION”\p"
	.string "It's a miniature diorama of the\n"
	.string "HOENN region.\p"
	.string "Where is LITTLEROOT TOWN on this?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay: @ 820C72F
	.string "It's a display on the flow of seawater.\p"
	.string "“Near the bottom of the sea, water\n"
	.string "flows due to differences in such\l"
	.string "factors as temperature and salinity.”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay: @ 820C7C1
	.string "It's a display on the flow of seawater.\p"
	.string "“Toward the surface, seawater flows\n"
	.string "as currents driven by the winds.”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica: @ 820C82F
	.string "“THE FERRY S.S. TIDAL\p"
	.string "“A scale replica of the ship under\n"
	.string "construction at STERN'S SHIPYARD.”$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica: @ 820C88B
	.string "“SUBMARINE EXPLORER 1\p"
	.string "“A replica of the high-performance\n"
	.string "ocean floor exploration submarine.”$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica: @ 820C8E8
	.string "“SUBMERSIBLE POD\p"
	.string "“A replica of a compact, unmanned\n"
	.string "pod for seafloor exploration.”$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica: @ 820C93A
	.string "“S.S. ANNE\p"
	.string "“A replica of the luxury liner that\n"
	.string "circles the globe.”$"

SlateportCity_OceanicMuseum_2F_Text_MicoloAppears:
	.string "Hola reina n.n\p"
	.string "DARKRAI: Estos noobs quieren las\n"
	.string "DEVON GOODS.\p"
	.string "MEWTWO: Pero ya no hacen\n"
	.string "falta para nuestros planes.\p"
	.string "MOLTRES: ¿Entonces qué hacemos?\p"
	.string "ARTICUNO: Cállate, pollo frito.\p"
	.string "MICOLO: ¿Seguís buscando las\n"
	.string "DEVON GOODS?\p"
	.string "Ya os las quitaron una vez, no hace.\n"
	.string "falta tanta insistencia xDDDDDDD\p"
	.string "Si queréis las piezas os tendré que\n"
	.string "poner a prueba xDDDDDD$"

SlateportCity_OceanicMuseum_2F_Text_MicoloDefeatsGrunts:
	.string "Un 6-0...\p"
	.string "Qué noobs LOOOOOOOOOOOOOOOO\n"
	.string "OOOOOOOOOOOOOOOOOOOOOOOOOOO\l"
	.string "OOOOOOOOOOOOOOOOOOOOOOOOOOOL\p"
	.string "Mejor que os marchéis antes de que\n"
	.string "vuestro JEFE os despida xDDDDDDD$"

SlateportCity_OceanicMuseum_2F_Text_MicoloWantsToBattle:
	.string "Nos vemos otra vez, {PLAYER} n.n\p"
	.string "Veo que STEVEN y su padre te han pedido\n"
	.string "que les entregues las DEVON GOODS al\l"
	.string "CAPT. STERN.\p"
	.string "No te preocupes, yo no he venido aquí\n"
	.string "a por las DEVON GOODS, ya no me son\l"
	.string "necesarias xDDDDDDDDDD\p"
	.string "¿Que por qué estoy aquí entonces?\p"
	.string "Me interesa ver tu forma de entrenar a\n"
	.string "los POKéMON, ¡prepárate!$"

SlateportCity_OceanicMuseum_2F_Text_MicoloDefeat:
	.string "Eres muy poderoso n.n$"

SlateportCity_OceanicMuseum_2F_Text_MicoloLeaves:
	.string "Tienes potencial n.n\p"
	.string "Quizás algún día podrías llegar a\n"
	.string "MICOLANDIA... n.n\p"
	.string "Eso es todo, amigo n.n\p"
	.string "¿Qué? esperabas que te regalase algo?\p"
	.string "No soy una ONG con patas xDDDDDDDDDDD\n"
	.string "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\p"
	.string "Adiós, seguro que nos volvemos a ver n.n\p"
	.string "Recuerda, monociclo porque mono es uno\n"
	.string "y la vida es un ciclo.$"
