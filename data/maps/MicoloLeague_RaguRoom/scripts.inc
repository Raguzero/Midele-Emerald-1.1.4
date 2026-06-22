MicoloLeague_RaguRoom_MapScripts::
	.byte 0
	
MicoloLeague_RaguRoom_EventScript_Ragu::
	lock
	faceplayer
	checktrainerflag TRAINER_RAGU
	goto_if 1, MicoloLeague_RaguRoom_EventScript_Ragu_Derrotado
	trainerbattle_single TRAINER_RAGU, MicoloLeague_RaguRoom_Text_RaguIntro, MicoloLeague_RaguRoom_Text_RaguDefeat, MicoloLeague_RaguRoom_EventScript_RaguDefeated, NO_MUSIC
	release
	end
	
MicoloLeague_RaguRoom_EventScript_RaguDefeated::
	msgbox MicoloLeague_RaguRoom_Text_RaguPostBattle, MSGBOX_DEFAULT
	waitmessage
	applymovement 2, MicoloLeague_RaguRoom_Movement_RaguUnblocksExit
	applymovement 1, MicoloLeague_RaguRoom_Movement_RaguUnblocksExit
	waitmovement 0
	setobjectxyperm 2, 11, 6
	setobjectxyperm 1, 10, 6
	release
	end
	
MicoloLeague_RaguRoom_EventScript_Ragu_Derrotado::
	speakername CommonName_Text_Ragu
	msgbox MicoloLeague_RaguRoom_Text_RaguPostBattle, MSGBOX_DEFAULT
	release
	end
	
MicoloLeague_RaguRoom_Mudkip::
	waitse
	playmoncry SPECIES_MUDKIP, 2
	delay 40
	waitmoncry
	msgbox MicoloLeague_RaguRoom_Text_Mudkip, MSGBOX_NPC
	release
	end
	
MicoloLeague_RaguRoom_NPCmirandoTV::
	lockall
	msgbox MicoloLeague_RaguRoom_Text_NPCmirandoTV, MSGBOX_DEFAULT
	releaseall
	end
	
MicoloLeague_RaguRoom_EsclavoSign::
	msgbox MicoloLeague_RaguRoom_Text_EsclavoSign, MSGBOX_SIGN
	end
	
MicoloLeague_RaguRoom_TeleSign::
	msgbox MicoloLeague_RaguRoom_Text_TeleSign, MSGBOX_SIGN
	end
	
MicoloLeague_RaguRoom_PlanosSign::
	msgbox MicoloLeague_RaguRoom_Text_PlanosSign, MSGBOX_SIGN
	end
	
MicoloLeague_RaguRoom_PinguinoPataSign::
	msgbox MicoloLeague_RaguRoom_Text_PinguinoPataSign, MSGBOX_SIGN
	end
	
MicoloLeague_RaguRoom_TumbaSign::
	msgbox MicoloLeague_RaguRoom_Text_TumbaSign, MSGBOX_SIGN
	end
	
MicoloLeague_RaguRoom_PCSign::
	msgbox MicoloLeague_RaguRoom_Text_PCSign, MSGBOX_SIGN
	end

MicoloLeague_RaguRoom_Movement_RaguUnblocksExit:
	walk_right
	step_end
	
MicoloLeague_RaguRoom_Text_EsclavoSign:
	.string "¡ATENCIÓN!\p" 
	
	.string "Prohibido lanzar comida a los\n"
	.string "esclavos, no sabemos cómo pueden\l"
	.string "reaccionar ante los visitantes.$"

MicoloLeague_RaguRoom_Text_TeleSign:
	.string "Parece que están reproduciendo las\n"
	.string "jugadas más mortíferas del NUZLOCKE\l"
	.string "de EEVEETO.$"
	
MicoloLeague_RaguRoom_Text_PlanosSign:
	.string "Parecen notas sobre MIDELE EMERALD:\p"
	
	.string "Copypaste de scripts\p"

	.string "Recordar que manden equipo y frases\p"

	.string "Hacer más óptimo el trabajo de mis\n"
	.string "esclavos, para ello les daré una\l"
	.string "papelera a cada uno donde puedan hacer\l"
	.string "sus necesidades sin interrupciones.\p"
	
	.string "Fecha de Lanzamiento de\n"
	.string "MIDELE EMERALD: AÑO 2020\p"
	
	.string "MIDELE EMERALD se retrasa a 2021.\p"
	
	.string "Fecha definitiva Lanzamiento de\n"
	.string "MIDELE EMERALD: JULIO 2021\p"
	
	.string "MIDELE EMERALD se retrasa de nuevo.\p"
	
	.string "Fecha definitiva Lanzamiento de\n"
	.string "MIDELE EMERALD: AGOSTO 2021\p"
	
	.string "MIDELE EMERALD se retrasa de nuevo.\p"
	
	.string "Fecha definitiva Lanzamiento de\n"
	.string "MIDELE EMERALD: SEPTIEMBRE 2021$"
	
MicoloLeague_RaguRoom_Text_Mudkip:
	.string "¡Es el POKéMON favorito de RAGU!\p"

	.string "Lleva una nota en la boca que dice\n"
	.string "lo siguiente:\p"
	
	.string "so i herd u liek mudkipz$"

MicoloLeague_RaguRoom_Text_TumbaSign:
	.string "Aquí yace PIKACHU aplastado.$"
	
MicoloLeague_RaguRoom_Text_NPCmirandoTV:
	.string "¡SIIIIIII! ¡TOMAAAAAAAAA!\n" 
	.string "¡Han matado al SNORLAX roto de\l"
	.string "EEVEETO!\p"
	
	.string "¡Esta droja es maravillosa!\p"
	
	.string "...\p"
	
	.string "¡JOJOJO! ¡Se ha comido un golpe crítico\n"
	.string "que le hizo KO a su HYDREIGON.\p"
	
	.string "¡EEVEETO ESTÁ A PUNTO DE PERDER!\p"
	
	.string "...\p"
	
	.string "¿QUÉ? ¿QUÉ? ¿¿¿QUEEEEEEEEEEE???\p"
	
	.string "¡MALDITA IA! ¡ME CAGOENTOOOO!\n" 
	.string "La IA se ha puesto a boostearse en vez\l" 
	.string "de matarle un POKéMON, ¡AAAAAAAAAAA!\p"
	
	.string "...\p"
	
	.string "EEVEETO está remontando, ¡¡¡NOOOOO!!!\n"
	.string "¡Está haciendo KO a todo lo que sale!\p"
	
	.string "...\p"
	
	.string "¡JODEEEEEEEEEEEEER!\n"
	.string "¡EEVEETO HA GANADO EL NUZLOCKE!\p"
	.string "¡VAYA MIERDA!$"
	
MicoloLeague_RaguRoom_Text_PCSign:
	.string "Parecen notas sobre un MIDELE\n"
	.string "PLATINUM cancelado:\p"
	
	.string "Justo después de lo ocurrido en\n"
	.string "MIDELE EMERALD.\p"
	
	.string "Una nueva y gran amenaza se cierne\n"
	.string "sobre SINNOH que afectará a todo\l"
	.string "el MUNDO POKéMON.\p"
	
	.string "MICOLO ha sido engañado y capturado\n"
	.string "por DARKI MALRO y sus esbirros, y se\l"
	.string "ha llevado todos los experimentos,\l"
	.string "incluyendo el PODER MIDELAR.\p"
	
	.string "DARKI MALRO ha conseguido un ejército\n"
	.string "de esbirros de otros mundos gracias\l" 
	.string "al uso de una máquina con un\l"
	.string "desmesurado poder que ha desequilibrado\l"
	.string "las estructuras del espacio-tiempo.\p"
	
	.string "El MT. CORONA de SINNOH ha sido\n"
	.string "eliminado completamente.\p"
	
	.string "¿Aparecerá alguien capaz de\n" 
	.string "hacerle FRENTE en BATALLA?$"
	
MicoloLeague_RaguRoom_Text_RaguIntro: 
	.string "No sé si seré el primero al que retas,\n"
	.string "pero, no importa.\l"
	.string "¡Te doy la bienvenida a la MICOLIGA!\p"
	
	.string "Supongo que has estado observando este\n"
	.string "lugar...\p"
	
	.string "Muy bonito, ¿verdad?\n"
	.string "Y sobre todo muy eficiente, todo va\l"
	.string "sobre ruedas gracias a mi plan de\l"
	.string "eficiencia del trabajo 24-7 al que\l"
	.string "son sometidos mis esclavos.\p"
	
	.string "Pero aún debo mejorarlo más,\n" 
	.string "¡No quiero más retrasos!\p"
	
	.string ":saca el látigo:\p"

	.string "...\p"
	
	.string "¿Que la esclavitud se abolió hace mucho\n"
	.string "tiempo? ¡Jajajaja! ¡No me hagas reir!\p"
	
	.string "¿Acaso no sabes la cantidad de gente\n"
	.string "que está obligada a trabajar gratis\l" 
	.string "para pillar experiencia...\l" 
	.string "o con sueldos basura echando más horas\l" 
	.string "que un reloj... con la esperanza de que\l" 
	.string "en un futuro... poder conseguir un\l" 
	.string "sueldo que le permita vivir dignamente?\p"
	
	.string "Yo por lo menos ofrezco a mis esclavos\n"
	.string "un cuarto donde ellos pueden vivir y\l"
	.string "hacer todas sus necesidades\l" 
	.string "fisiológicas...\p"

	.string "Así que me preocupo mucho de que mis\n"
	.string "esclavos del MIDELE estén a gusto y\l"
	.string "tengan un lugar al que ellos puedan\l" 
	.string "llamar hogar. Es decir, ¡tienen la\l"
	.string "vida resuelta!\p"
	
	.string "Pero, dejando de lado todo esto, debes\n"
	.string "tener un potencial enorme para haber\l"
	.string "llegado hasta aquí... Me intriga ver de\l" 
	.string "qué eres capaz.\p"
	
	.string "Bien, ¡prepárate para un combate\n"
	.string "sin igual, vas a comprender por qué me\l" 
	.string "llaman MAESTRO HAX!$"

MicoloLeague_RaguRoom_Text_RaguDefeat: 
	.string "¡¡¡AAAAAAAAA!!!\p"

	.string "¡Necesito aplastar un PIKACHU\n"
	.string "con mis propias manos!\p"
	
	.string "¡DÓNDE ESTÁ! ¡DÓNDE ESTÁ!\p"
	
	.string "Ostiaaaaa... pero si ya lo\n" 
	.string "maté...\p"
	
	.string "¡DEP, siempre se van los mejores!$"

MicoloLeague_RaguRoom_Text_RaguPostBattle:
	.string "Es una pena que no quieras ser\n"
	.string "mi esclavo. ¡Serías muy útil!\p"
	
	.string "Sigue adelante, que aún puede que te\n"
	.string "quede un buen trecho para convertirte\l"
	.string "en el CAMPEÓN de la MICOLIGA.\p"
	
	.string "Y no olvides echar un vistazo a los\n" 
	.string "documentos y a todo lo que he\l" 
	.string "almacenado aquí.$"
	
MicoloLeague_RaguRoom_Text_PinguinoPataSign:
	.string "Parece un sello con la forma de\n"
	.string "una pata de pingüino.$"
	
