Micolandia_House1_MapScripts::
	.byte 0
	
Micolandia_House_1_Script::
	msgbox Micolandia_House_1_Text, MSGBOX_NPC
	release
	end
	
Micolandia_House_1_Text:
	.string "Menuda siesta te has tomado ¿eh?\p"

	.string "Te encuentras en MICOLANDIA,\n" 
	.string "el lugar al que solo llegan los\p"
	.string "elegidos por MICOLO.$"

Micolandia_House_2_Script::
	faceplayer
	showmoneybox 0, 0, 0	
	msgbox HatchAnEgg_Text_OpenEgg, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq HatchAnEgg_End
	checkmoney 50000, 0
	compare VAR_RESULT, FALSE
	goto_if_eq HatchAnEgg_NoMoney
	getpartysize
	compare VAR_RESULT, 0
	goto_if_eq HatchAnEgg_NoPokemon
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge HatchAnEgg_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_ne HatchAnEgg_CantForceHatch
	special EggHatch
	removemoney 50000, 0
	updatemoneybox 0, 0
	hidemoneybox
	waitstate
	releaseall
	end

HatchAnEgg_End::
	hidemoneybox
	releaseall
	end

HatchAnEgg_NoPokemon::
	hidemoneybox
	msgbox HatchAnEgg_Text_EmptyParty, MSGBOX_DEFAULT
	releaseall
	end

HatchAnEgg_CantForceHatch::
	hidemoneybox
	msgbox HatchAnEgg_Text_NotAnEgg, MSGBOX_DEFAULT
	releaseall
	end

HatchAnEgg_NoMoney::
	hidemoneybox
	msgbox HatchAnEgg_Text_NoMoney, MSGBOX_DEFAULT
	releaseall
	end
	
HatchAnEgg_Text_NoMoney::
	.string "¡Pero si no tienes el dinero!$"

HatchAnEgg_Text_EmptyParty::
	.string "No tienes POKéMON ni HUEVOS.$"

HatchAnEgg_Text_NotAnEgg::
	.string "Te faltan HUEVOS.$"
	
HatchAnEgg_Text_OpenEgg::
	.string "Hola, me llaman el CALIENTA HUEVOS.\n"
	.string "Por un módico precio puedo hacer\l"
	.string "que un POKéMON eclosione rápidamente\l"
	.string "de un HUEVO. Se acabó dejarse los\l"
	.string "HUEVOS en el monociclo.\p"
	
	.string "Así que, ¿has venido a que te abra los\n"
	.string "HUEVOS? El precio es 50000 por unidad.$"
