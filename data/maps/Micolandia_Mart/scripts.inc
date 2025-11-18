Micolandia_Mart_MapScripts::
	.byte 0
	
Micolandia_Mart_EventScript_Boy::
	msgbox Micolandia_Mart_Text_Boy, MSGBOX_NPC
	end

Micolandia_Mart_EventScript_Shop::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Micolandia_Mart_Pokemart_Shop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Micolandia_Mart_Pokemart_Shop:
	.2byte ITEM_ULTRA_BALL
    .2byte ITEM_NET_BALL
    .2byte ITEM_DIVE_BALL
    .2byte ITEM_NEST_BALL
    .2byte ITEM_REPEAT_BALL
    .2byte ITEM_TIMER_BALL
    .2byte ITEM_LUXURY_BALL
    .2byte ITEM_PREMIER_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ETHER
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_NONE
	release
	end
	
Micolandia_Mart_EventScript_Shop2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Micolandia_Mart_Pokemart_Shop2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Micolandia_Mart_Pokemart_Shop2:
    .2byte ITEM_CHERI_BERRY
    .2byte ITEM_CHESTO_BERRY
    .2byte ITEM_PECHA_BERRY
    .2byte ITEM_RAWST_BERRY
    .2byte ITEM_ASPEAR_BERRY
    .2byte ITEM_LEPPA_BERRY
    .2byte ITEM_ORAN_BERRY
    .2byte ITEM_PERSIM_BERRY
    .2byte ITEM_LUM_BERRY
    .2byte ITEM_SITRUS_BERRY
    .2byte ITEM_FIGY_BERRY
    .2byte ITEM_WIKI_BERRY
    .2byte ITEM_MAGO_BERRY
    .2byte ITEM_AGUAV_BERRY
    .2byte ITEM_IAPAPA_BERRY
    .2byte ITEM_RAZZ_BERRY
    .2byte ITEM_BLUK_BERRY
    .2byte ITEM_NANAB_BERRY
    .2byte ITEM_WEPEAR_BERRY
    .2byte ITEM_PINAP_BERRY
    .2byte ITEM_POMEG_BERRY
    .2byte ITEM_KELPSY_BERRY
    .2byte ITEM_QUALOT_BERRY
    .2byte ITEM_HONDEW_BERRY
    .2byte ITEM_GREPA_BERRY
    .2byte ITEM_TAMATO_BERRY
    .2byte ITEM_CORNN_BERRY
    .2byte ITEM_MAGOST_BERRY
    .2byte ITEM_RABUTA_BERRY
    .2byte ITEM_NOMEL_BERRY
    .2byte ITEM_SPELON_BERRY
    .2byte ITEM_PAMTRE_BERRY
    .2byte ITEM_WATMEL_BERRY
    .2byte ITEM_DURIN_BERRY
    .2byte ITEM_BELUE_BERRY
	.2byte ITEM_NONE
	release
	end	
	
// ESTO FUNCIONA COMO CAMBIADOR DE EVS, NO COMO TIENDA, NO TOCAR NADA:
Micolandia_Mart_EventScript_Clerk::
	lock
	faceplayer
	msgbox Micolandia_EV_Mart, MSGBOX_DEFAULT
Micolandia_Mart_EventScript_Clerk_SelectMon:
	waitmessage
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq Micolandia_Mart_EventScript_Clerk_Bye
	copyvar VAR_RESULT, VAR_0x8004
	evmart Micolandia_Mart_Pokemart
	compare VAR_0x8004, 200
  goto_if_eq Micolandia_Mart_EventScript_Clerk_SelectMon
Micolandia_Mart_EventScript_Clerk_Bye:
	msgbox Micolandia_EV_Mart_Bye, MSGBOX_DEFAULT
	release
	end

 .align 2	

Micolandia_Mart_Pokemart:
	.2byte ITEM_DESTINY_KNOT // EV HP.    Cost 0 $
	.2byte ITEM_DESTINY_KNOT // EV ATK.   Cost 0 $
	.2byte ITEM_DESTINY_KNOT // EV DEF.   Cost 0 $
	.2byte ITEM_DESTINY_KNOT // EV SPEED. Cost 0 $
	.2byte ITEM_DESTINY_KNOT // EV SATK.  Cost 0 $
	.2byte ITEM_DESTINY_KNOT // EV SDEF.  Cost 0 $
	.2byte ITEM_NONE
	release
	end
	
Micolandia_EV_Mart:
	.string "¡Te doy la bienvenida al EV CHANGER!\p"

	.string "Aquí podrás cambiar a tu gusto los\n"
	.string "EVs de tus POKéMON.\p"
	
	.string "IT'S FREE!\p"

	.string "Así que, ¿a qué POKéMON quieres\n"
	.string "cambiarle los EVs?$"
	
Micolandia_EV_Mart_Bye:
	.string "¡Hasta pronto!$"
	
Micolandia_Mart_Text_Boy:
	.string "¿Has usado ya el EV CHANGER?\p"
	
	.string "¡Puedes redistribuir los EVs a tus\n"
	.string "POKéMON como quieras!\l"
	.string "¡Es super útil!\p"

	.string "Se acabó el comprar vitaminas y plantar\n"
	.string "bayas reductoras de EVs.$"
