Micolandia_Temple_of_Time_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Micolandia_Temple_of_Time_OnTransition
	.byte 0
	
Micolandia_Temple_of_Time_OnTransition:
	setflag FLAG_LANDMARK_TEMPLE_OF_TIME
	end

TempleTime_EventScript_YellowFlute::
	giveitem ITEM_YELLOW_FLUTE, 1
	compare VAR_RESULT, FALSE
	call_if_eq TempleTime_BagFull
	closemessage
	removeobject 6
	setflag FLAG_ITEM_TempleTime_YELLOWFLUTE
	end
	
TempleTime_EventScript_BlueFlute::
	giveitem ITEM_BLUE_FLUTE, 1
	compare VAR_RESULT, FALSE
	call_if_eq TempleTime_BagFull
	closemessage
	removeobject 4
	setflag FLAG_ITEM_TempleTime_BLUEFLUTE
	end
	
TempleTime_EventScript_RedFlute::
	giveitem ITEM_RED_FLUTE, 2
	compare VAR_RESULT, FALSE
	call_if_eq TempleTime_BagFull
	closemessage
	removeobject 5
	setflag FLAG_ITEM_TempleTime_REDFLUTE
	end
	
TempleTime_EventScript_Pokedoll::
	giveitem ITEM_POKE_DOLL, 1
	compare VAR_RESULT, FALSE
	call_if_eq TempleTime_BagFull
	closemessage
	removeobject 12
	setflag FLAG_ITEM_TempleTime_POKEDOLL
	end
	
TempleTime_EventScript_FluffyTail::
	giveitem ITEM_FLUFFY_TAIL, 1
	compare VAR_RESULT, FALSE
	call_if_eq TempleTime_BagFull
	closemessage
	removeobject 10
	setflag FLAG_ITEM_TempleTime_FLUFFYTAIL
	end
	
TempleTime_EventScript_Cleansetag::
	giveitem ITEM_CLEANSE_TAG, 1
	compare VAR_RESULT, FALSE
	call_if_eq TempleTime_BagFull
	closemessage
	removeobject 11
	setflag FLAG_ITEM_TempleTime_CLEANSETAG
	end
	
TempleTime_BagFull::
	call Common_EventScript_BagIsFull
	closemessage
	release
	end
	
TempleTime_EventScript_EnterRoom1::
	closemessage
	delay 30
	warpdoor MAP_MICOLANDIA_TEMPLE_OF_TIME, 3, 0, 0
	waitstate
	releaseall
	end
	
TempleTime_EventScript_EnterRoom2::
	closemessage
	delay 30
	warpdoor MAP_MICOLANDIA_TEMPLE_OF_TIME, 2, 0, 0
	waitstate
	releaseall
	end
	
TempleTime_EventScript_EnterRoom3::
	closemessage
	delay 30
	warpdoor MAP_MICOLANDIA_TEMPLE_OF_TIME, 6, 0, 0
	waitstate
	releaseall
	end
	
TempleTime_EventScript_EnterRoom4::
	closemessage
	delay 30
	warpdoor MAP_MICOLANDIA_TEMPLE_OF_TIME, 4, 0, 0
	waitstate
	releaseall
	end
	
TempleTime_EventScript_EnterRoom5::
	closemessage
	delay 30
	warpdoor MAP_MICOLANDIA_TEMPLE_OF_TIME2, 0, 0, 0
	waitstate
	releaseall
	end
	
TempleTime_EventScript_Heal::
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty
	msgbox TempleTime_Text_Curacion, MSGBOX_DEFAULT
	release
	end
	
TempleTime_Text_Curacion:
	.string "El aroma de las flores cura tu equipo.$"
	
TempleTime_EventScript_Anciano::
	msgbox TempleTime_Text_Anciano, MSGBOX_NPC
	end
	
TempleTime_Text_Anciano:
	.string "Te doy la bienvenida al Templo del\n"
	.string "Tiempo.\p"
	.string "Este templo fue construido hace siglos\n"
	.string "en honor al POKéMON CELEBI.\p"
	
	.string "Espero que mantengas la compostura,\n"
	.string "últimamente se cuela mucho gamberro.\p"
	
	.string "Si necesitas curar a tus POKéMON, esas\n"
	.string "flores tan aromáticas serán de ayuda.$"


	
TempleTime_EventScript_Anciana::
	msgbox TempleTime_Text_Anciana, MSGBOX_NPC
	end
	
TempleTime_Text_Anciana:
	.string "Desde que construyeron MICOLANDIA,\n"
	.string "en este lugar ya no se puede encontrar\l"
	.string "la paz espiritual.\p"
	.string "Antes esto solo era una isla en la que\n"
	.string "velabamos por este templo, ¡pero mira\l"
	.string "en lo que se ha convertido!\p"
	.string "¡Ahora tenemos que lidiar con porretas\n"
	.string "y furros!$"
	
TempleTime_EventScript_Kraft::  
	trainerbattle_single TRAINER_KRAFT, TempleTime_Text_KraftIntro, TempleTime_Text_KraftDefeat
	msgbox TempleTime_Text_KraftPostBattle, MSGBOX_AUTOCLOSE
	end
	
TempleTime_EventScript_Gatolete::
	trainerbattle_single TRAINER_GATOLETE, Gatolete_AntesBatalla, Gatolete_MensajeDerrota
	msgbox Gatolete_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
TempleTime_EventScript_Pajaroespin::
	trainerbattle_single TRAINER_PAJAROESPIN, Pajaroespin_AntesBatalla, Pajaroespin_MensajeDerrota
	msgbox Pajaroespin_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
TempleTime_EventScript_Frantasy::
	trainerbattle_single TRAINER_FRANTASY, TempleTime_Text_FrantasyIntro, TempleTime_Text_FrantasyDefeat
	msgbox TempleTime_Text_FrantasyPostBattle, MSGBOX_AUTOCLOSE
	end
	
TempleTime_EventScript_Neuer::
	trainerbattle_single TRAINER_NEUER, TempleTime_Text_NeuerIntro, TempleTime_Text_NeuerDefeat
	msgbox TempleTime_Text_NeuerPostBattle, MSGBOX_AUTOCLOSE
	end
	
TempleTime_Text_KraftIntro: 
	.string "¿No quieres darle una calada?\n"
	.string "Bah, mejor me la fumo yo.$"

TempleTime_Text_KraftDefeat: 
	.string "Si ella se tira de un puente, tú\n"
	.string "te tiras con ella y en la bajada\l"
	.string "te la tiras.$"

TempleTime_Text_KraftPostBattle: 
	.string "¿No quieres que hagamos algo...\n"
	.string "juntos? Nosotros dos o más gente.\p"
	.string "Usaremos mi lista de fetiches como\n"
	.string "guía.$"
	
TempleTime_Text_FrantasyIntro: 
	.string "Mis pelos del ombligo miden ya\n"
	.string "cinco centímetros. ¿Puedes creerlo?$"

TempleTime_Text_FrantasyDefeat: 
	.string "Es la hora de poner una imagen\n"
	.string "de Blancanieves disgutada con\l"
	.string "esta derrota.$"

TempleTime_Text_FrantasyPostBattle:
	.string "¿No te parece CHESNAUGHT uno de\n"
	.string "los mejores POKéMON que existen?\p"
	.string "Es tan suave al tacto...$"
	
TempleTime_Text_NeuerIntro: 
	.string "Oh Girly, Girly, tus expresiones\n" 
	.string "me fascinan, son como Nero y yo\l"
	.string "en nuestra piscina.\p"
	
	.string "En ese pueblo latinoamericano mejicano\n" 
	.string "nació, para llamar homosexual a todo\l" 
	.string "dios. Oh Girly, Girly.\p"
	.string "Tan plana como una mesa, tu léxico me\n"
	.string "embelesa, y a muchos de aquí, se les\l"
	.string "pone tiesa.$"

TempleTime_Text_NeuerDefeat: 
	.string "Oh Girly, Girly.$" 

TempleTime_Text_NeuerPostBattle:
	.string "Venga, sois como una mafia.\p"
	.string "No os sabéis defender solos ninguno,\n"
	.string "sois unos putos mierdas y os lo digo\l"
	.string "completamente en serio.\p"
	.string "Hace un año me defendí solo, con dos mods\n"
	.string "soltando gilipolleces y muchos foreros\l"
	.string "lamiéndoles el culo por el mero hecho\l"
	.string "de serlo. Dais vergüenza.$"
	
Gatolete_AntesBatalla: 
	.string "Hola, me llamo Gatolete y me he\n"
	.string "postulado como moderador.\p"
	.string "a.vader creó un tablón en el foro\n"
	.string "para que me voten como moderador.\p"
	.string "¡Y he ganado las votaciones!\n"
	.string "Por fin voy a ser moderador de\l"
	.string "MICOLANDIA.\p"
	.string "a.vader me dijo que viniese aquí\n"
	.string "para que me diesen la bienvenida\l"
	.string "al STAFF, pero no veo a nadie.\l"
	.string "¿sabes dónde están?$"

Gatolete_MensajeDerrota: 
	.string "¿Dices que me ha trolleado a.vader?\n"
	.string "Espero que no.$"
 
Gatolete_DespuesDeBatalla:
	.string "a.vader, quiero ser moderador...\p"
	.string "¿DÓNDE ESTÁS, A.VADER?\n"
	.string "¿ME HAS ENGAÑADO?$"
	
Pajaroespin_AntesBatalla: 
	.string "Soy diseñador gráfico.\n"
	.string "¿Quieres que te haga algún avatar\l"
	.string "o firma?$"

Pajaroespin_MensajeDerrota: 
	.string "Pero que les has hecho a mis\n"
	.string "pajaritos...$"
 
Pajaroespin_DespuesDeBatalla:
	.string "¡Pues que sepas que yo fui quien\n"
	.string "hizo el avatar a MICOLO!\p"
	.string "En realidad no.$"
