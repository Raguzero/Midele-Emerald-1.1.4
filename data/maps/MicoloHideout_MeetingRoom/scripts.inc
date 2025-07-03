MicoloHideout_MeetingRoom_MapScripts::
	.byte 0
	
MicoloHideout_MeetingRoom_EventScript_Goldie::
	trainerbattle_double TRAINER_GOLDIE, Goldie_AntesBatalla, Goldie_MensajeDerrota, Goldie_MasdeunPokemon
	msgbox Goldie_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_MeetingRoom_EventScript_Merum::
	trainerbattle_single TRAINER_MERUM, Merum_AntesBatalla, Merum_MensajeDerrota
	msgbox Merum_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_MeetingRoom_EventScript_Kaderete::  
	trainerbattle_single TRAINER_KADERETE_2, MicoloHideout_MeetingRoom_Text_KadereteIntro, MicoloHideout_MeetingRoom_Text_KadereteDefeat
	msgbox MicoloHideout_MeetingRoom_Text_KaderetePostBattle, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_MeetingRoom_EventScript_Hathar::  
	trainerbattle_single TRAINER_HATHAR, MicoloHideout_MeetingRoom_Text_HatharIntro, MicoloHideout_MeetingRoom_Text_HatharDefeat
	msgbox MicoloHideout_MeetingRoom_Text_HatharPostBattle, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_MeetingRoom_EventScript_Escroto::
	trainerbattle_single TRAINER_ESCROTO, Escroto_AntesBatalla, Escroto_MensajeDerrota
	msgbox Escroto_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_MeetingRoom_EventScript_Alpha::
	trainerbattle_single TRAINER_ALPHA, Alpha_AntesBatalla, Alpha_MensajeDerrota
	msgbox Alpha_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
Goldie_MasdeunPokemon: // BATALLA DOBLE
	.string "Pero si no llevas más de un\n"
	.string "POKéMON con vida...\p"

	.string "Mi equipo es solo para DOBLES,\n"
	.string "así que vuelve cuando tengas\l"
	.string "al menos dos.$"
	
Goldie_AntesBatalla: 
	.string "¡Te doy la bienvenida!\p"

    .string "¿Sabes qué hacen dos personas\n"
    .string "cuando se conocen?\p"

    .string "¡Exacto! ¡Compartir logros\n"
    .string "en gachas de baja calidad!\p"

    .string "...Oh, que quieres luchar.\p"

    .string "Vale, ¡no pienso perder!\n"
    .string "(posa por algún motivo)$"
	
Goldie_MensajeDerrota: 
    .string "Oh, lo olvidaba, que aquí\n"
    .string "no está programado.\p"

    .string "Al menos me lo justifican\n"
    .string "mejor que los guardas de Galar.$"
	
Goldie_DespuesDeBatalla:
    .string "¿Sabías que en los dos anteriores\n"
    .string "juegos Midele yo salía como NPC\l"
    .string "masculino? Me han dejado niquelada.\p"

    .string "Y sí, acabo de romper la\n"
    .string "cuarta pared de gratis.$"
	
Merum_AntesBatalla: 
    .string "A ver que yo me entere... ¿me estás\n"
    .string "diciendo que tienes un equipo de\l"
    .string "la hostia y entre ellos no hay un\l"
    .string "buen puto MOÁI bien mamadísimo?\p"
    .string "Es que es para pegarte.\p"
    .string "Es más, seré YO quien te pegue.$"
	
Merum_MensajeDerrota: 
    .string "Vaya por dios. Bueno, como sea...\n"
    .string "espero que este combate sirviese\l"
    .string "para mostrarte lo que mola mi MOÁI.$"
	
Merum_DespuesDeBatalla:
	.string "Es gracioso y a la par triste cuando\n"
    .string "tu parodia es exactamente como tú.\p"

    .string "Si te empiezas a sentir como un NPC\n"
    .string "es que quizás deberías ampliar tus\l"
    .string "temas de conversación. Dicho eso,\l"
    .string "¿qué opinas de mi GRAN MOÁI?$"
	
Escroto_AntesBatalla: 
	.string "Soy ESCROTO, el GAMER\n"
	.string "LEGENDARIO.\p"
	
	.string "No tienes ninguna oportunidad,\n"
	.string "cabrón.$"
	
Escroto_MensajeDerrota: 
	.string "¡PERO SI FUI VOTADO COMO GAMER\n"
	.string" DEL AÑO!$"
	
Escroto_DespuesDeBatalla:
    .string "Te recomiendo jugar el Xenoblade\n"
	.string "Chronicles.\p"
 
    .string "Se parece a POKéMON en el aspecto\n"
    .string "de niveles y esas cosas.$"
	
MicoloHideout_MeetingRoom_Text_HatharIntro: 
    .string "Te voy a banear.$"

MicoloHideout_MeetingRoom_Text_HatharDefeat: 
    .string "¡Ay! ¡Mi apéndice!$"
 
MicoloHideout_MeetingRoom_Text_HatharPostBattle:
    .string "Podría haberte ganado,\n"
    .string "si no estuviese recuperándome\l" 
	.string "de mi vesícula.$"
	
MicoloHideout_MeetingRoom_Text_KadereteIntro: 
	.string "¿Cómo puedo haber acabado yo aquí?\p"

    .string "O sea, mira a toda esta gente.\n"
    .string "Está todo lleno de putos frikazos...\p"

    .string "En fin, ya me has enfadado.\n"
    .string "¡¡¡A poquemonear!!!$"

MicoloHideout_MeetingRoom_Text_KadereteDefeat: 
	.string "NOOOOOOOO$"

MicoloHideout_MeetingRoom_Text_KaderetePostBattle: 
	.string "En fin, tampoco le había echado ganas.\p"

    .string "Vete antes de que te parta la cara.$"
	
Alpha_AntesBatalla: 
	.string "En la batalla, así como en el ejercicio\n"
	.string "de la medicina, solo acepto la\l"
	.string "excelencia. ¿Será su merced capaz de,\l"
	.string "al menos, entretenerme?$"
	
Alpha_MensajeDerrota: 
	.string "¿En verdad he perdido?\n"
	.string "...\p"
	
	.string "Me he cansado de esta pantomima.\p" 
	
	.string "Anda, toma la calderilla que me ha\n" 
	.string "sobrado de comprar en Versace;\l" 
	.string "a ver si dejas de usar esos harapos,\l"
	.string "muerto de hambre.$"
	
Alpha_DespuesDeBatalla:
	.string "¿En serio no tienes nada mejor que\n"
	.string "hacer? Si en vez de farmear\l"
	.string "experiencia y hacer shiny hunting,\l"
	.string "hubieses estudiado 100 GB por\l"
	.string "cuatrimestre, no estarías en paro y sin\l"
	.string "un duro.\p"
	
	.string "¡Uy qué tarde! Me voy que van a\n"
	.string "llegar pronto los jardineros y tengo\l"
	.string "que decirles qué hacer... si es que los\l"
	.string "de clase media no sabéis hacer nada\l"
	.string "solos.$"

MicoloHideout_MeetingRoom_Showcase_Monociclo::
	msgbox MicoloHideout_MeetingRoom_Showcase_Monociclo_Text_0, MSGBOX_SIGN
	return


MicoloHideout_MeetingRoom_Showcase_Micomandamientos::
	msgbox MicoloHideout_MeetingRoom_Showcase_Micomandamientos_Text_0, MSGBOX_SIGN
	return


MicoloHideout_MeetingRoom_Showcase_Monociclo_Text_0:
	.string "Hay un monociclo dentro.$"

MicoloHideout_MeetingRoom_Showcase_Micomandamientos_Text_0:
	.string "Hay una inscripción en una tabilla de\n"
	.string "piedra. Lees lo que pone:\p"
	.string "“LOS DIEZ MICOMANDAMIENTOS\p"
	.string "1. Amarás al mico sobre todas las cosas.\p"
	.string "2. No tomarás el nombre del mico en vano.\p"
	.string "3. Santificarás a los monociclos.\p"
	.string "4. Honrarás a MIDELE y a ULTRA MAGIC.\p"
	.string "5. No pensarás.\p"
	.string "6. No hackearás POKéMON impuros.\p"
	.string "7. No robarás protagonismo a MICOLO.\p"
	.string "8. No dirás LOOOOOOL en vano.\p"
	.string "9. NO consentirás pensamientos ni\n"
	.string "deseos inteligentes.\p"
	.string "10. NO codiciarás monociclos ajenos.\p"
	.string "En nombre del mico, del hijo, del\n"
	.string "espíritu midélico. LOOOOOOOOOL.”$"

MicoloHideout_MeetingRoom_MagmaLetter::
	msgbox MicoloHideout_MeetingRoom_MagmaLetter_Text_0, MSGBOX_SIGN
	return


MicoloHideout_MeetingRoom_MagmaLetter_Text_0:
	.string "Hay una carta con el símbolo MAGMA en\n"
	.string "la mesa, dice lo siguiente:\p"
	.string "“Estimado MICOLO:\p"
	.string "Tu plan sobre el secado de todas las\n"
	.string "rutas marítimas más allá de ROUTE 124\l"
	.string "nos ha parecido bastante interesante,\l"
	.string "así que hemos decidido enviarte todas\l"
	.string "esas máquinas, como pediste.\p"
	.string "Son el mismo tipo de máquinas que\n"
	.string "utilizamos en nuestra GUARIDA MAGMA,\l"
	.string "así que sin duda te serán útiles.\p"
	.string "Según tus indicaciones, se espera que\n"
	.string "sean enviadas en unos días a la isla al\l"
	.string "oeste de IZABE, de nombre MICOLANDIA.\l"
	.string "Recomiendo que hagas espacio para\l"
	.string "ellas, pues son bastante grandes.\p"
	.string "PD: si bien nuestras máquinas son de la\n"
	.string "máxima calidad, dudo que sean capaces\l"
	.string "de secar en su totalidad toda esa masa\l"
	.string "de agua. Probablamente ocurra un\l"
	.string "secado parcial, pero eso debería ser\l"
	.string "más que suficiente para probar la\l"
	.string "efectividad de las máquinas.\p"
	.string "LÍDER MAGMA, MAXIE”$"

MicoloHideout_MeetingRoom_PC1::
	playse SE_PC_LOGIN
	waitse
	msgbox MicoloHideout_MeetingRoom_PC1_Text_0, MSGBOX_SIGN
	return


MicoloHideout_MeetingRoom_PC2::
	playse SE_W153
	waitse
	msgbox MicoloHideout_MeetingRoom_PC2_Text_0, MSGBOX_SIGN
	return


MicoloHideout_MeetingRoom_PC3::
	playse SE_PC_LOGIN
	waitse
	msgbox MicoloHideout_MeetingRoom_PC3_Text_0, MSGBOX_SIGN
	return
	
MicoloHideout_MeetingRoom_PC4::
	playse SE_PC_LOGIN
	waitse
	msgbox MicoloHideout_MeetingRoom_PC4_Text_0, MSGBOX_SIGN
	return
	
MicoloHideout_MeetingRoom_PC5::
	playse SE_PC_LOGIN
	waitse
	msgbox MicoloHideout_MeetingRoom_PC5_Text_0, MSGBOX_SIGN
	return
	
MicoloHideout_MeetingRoom_PC6::
	playse SE_PC_LOGIN
	waitse
	msgbox MicoloHideout_MeetingRoom_PC6_Text_0, MSGBOX_SIGN
	return
	
MicoloHideout_MeetingRoom_PC7::
	playse SE_PC_LOGIN
	waitse
	msgbox MicoloHideout_MeetingRoom_PC7_Text_0, MSGBOX_SIGN
	return


MicoloHideout_MeetingRoom_PCHeal::
	lock
	playse SE_PC_LOGIN
	waitse
	msgbox MicoloHideout_MeetingRoom_PCHeal_Text_0, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq MicoloHideout_MeetingRoom_PCHeal_2
MicoloHideout_MeetingRoom_PCHeal_1:
	release
	return

MicoloHideout_MeetingRoom_PCHeal_2:
	playse MUS_ME_ASA
	waitse
	special HealPlayerParty
	goto MicoloHideout_MeetingRoom_PCHeal_1

MicoloHideout_MeetingRoom_Chairman::
	lockall
	faceplayer
	msgbox MicoloHideout_MeetingRoom_Chairman_Text_0
	releaseall
	return


MicoloHideout_MeetingRoom_Chairman_Text_0:
	.string "¿Eh? ¿Qué quieres? ¿Cómo has llegado\n"
	.string "hasta aquí? Bueno, da igual...\p"
	.string "Esta es la SALA de REUNIONES del gran\n"
	.string "MICOLO. Aquí se llevan a cabo las\l"
	.string "charlas más intelectuales de toda\l"
	.string "MICOLANDIA... donde acuden los\l"
	.string "entrenadores más poderosos de todo el\l"
	.string "mundo.\p"
	.string "Será mejor que te largues si no quieres\n"
	.string "que te hagan un 6-0.$"



MicoloHideout_MeetingRoom_PC1_Text_0:
	.string "Hay un montón de datos técnicos sobre\n"
	.string "POKéMON y entrenadores.$"

MicoloHideout_MeetingRoom_PC2_Text_0:
	.string "No funciona. Le han pegado una PATADA\n"
	.string "SALTO...$"

MicoloHideout_MeetingRoom_PC3_Text_0:
	.string "Hay una tabla con datos sobre las\n"
	.string "operaciones de MICOLANDIA:\p"
	.string "“MAQUINARIA MAGMA: 300000¥\p"
	.string "INFRAESTRUCTURA GENERAL DE LA CIUDAD:\n"
	.string "1000000¥\p"
	.string "MICOCASINO: 250000¥\p"
	.string "MICOLIGA: 350000¥\p"
	.string "LABORATORIO: 800000¥\p"
	.string "MONOCICLOS: 9999000¥”$"
	
MicoloHideout_MeetingRoom_PC4_Text_0:
	.string "Parece un documento con información\n"
	.string "confidencial que dice lo siguiente:\p"
	
	.string "He tenido que usar materiales\n"
	.string "extremadamente raros con costes\l"
	.string "millonarios, pero gracias al mecenas\l"
	.string "ALPHA que ha apoyado mi proyecto con\l"
	.string "una cuantiosa cantidad de dinero,\l" 
	.string "he podido costear toda la investigación\l" 
	.string "y desarrollo a cambio de ser él el\l" 
	.string "primero en conseguir una unidad de mi\l" 
	.string "HONEDGE modificado.\p"
	
	.string "¡SÍ! ¡POR FIN MI SUEÑO SE HA CUMPLIDO!\p"
	
	.string "¡Yo, el gran A.VADER, he conseguido\n"
	.string "crear una forma alternativa de HONEDGE\l"
	.string "totalmente nueva!\p"
	
	.string "¡El HONEDGE MONADO! THIS IS THE POWER\n"
	.string "OF THE MONADO!\l"
	.string "Your blade.... it did not cut\l"
	.string "deep enough.\p"
	
	.string "¡EJEM! Como iba escribiendo aquí...\p"

	.string "Se trata de una versión mucho más\n" 
	.string "poderosa que la forma normal, incluso\l" 
	.string "más poderosa que la evolución final\l" 
	.string "de HONEDGE.\p"
	
	.string "Estadísticas Base:\n"
	.string "60 HP, 140 ATK, 50 DEF, 60 SATK,\l" 
	.string "50 SDEF, 140 SPEED\p"
	
	.string "Habilidad: ADAPTABILITY\p"

	.string "Más datos: No puede evolucionar, y\n"
	.string "tampoco puede criar de forma normal,\l"
	.string "pero eso no importa, tenemos la\l"
	.string "clonación y la máquina de crianza de\l"
	.string "legendarios... Pero, ¿podemos llamar\l" 
	.string "a esto, LEGENDARIO?\p"

	.string "Resto de datos: Desconocido por ahora.\n"
	.string "¡Haré que lo investigue el resto de la\l"
	.string "humanidad!\l"
	.string "Today mankind moves one step closer\l" 
	.string "to the divine!\l" 
	.string "push button monados liberadas$"
	
MicoloHideout_MeetingRoom_PC5_Text_0:
	.string "Parece un documento que describe\n"
	.string "varios movimientos creados por MICOLO:\p"
	
	.string "BRUTAL BALL: Tipo DARK, 100 Power,\n"
	.string "100 Accuracy, 20% de congelar, quemar\l"
	.string "o paralizar.\p"
	
	.string "SEISMIC PUNCH: Tipo FIGHT, 100 Power,\n"
	.string "100 Accuracy.\p"
	
	.string "MIDELE POWER: Tipo ???, 70 Power,\n"
	.string "100 Accuracy, Priority +2, atraviesa\l"
	.string "PROTECT y ENDURE, sube 50% ATK, DEF,\l"
	.string "SATK, SPDEF y SPEED por cada uso.\p"
	
	.string "DARK THUNDER: Tipo ELECTRIC, 70 Power,\n"
	.string "100 Accuracy, efecto de doble golpe.\p"
	
	.string "HOLA REINA: Tipo DARK, 100 Accuracy,\n"
	.string "atraviesa PROTECT y ENDURE, efecto de\l"
	.string "NIGHT SHADE.$"
	
MicoloHideout_MeetingRoom_PC6_Text_0:
	.string "Parece un documento con información\n"
	.string "confidencial que dice lo siguiente:\p"

	.string "La POKéFABRICA ha sido creada de forma\n"
	.string "exitosa como objetivo para la creación\l"
	.string "de nuevas formas de vida Pokemoniles\l"
	.string "capaces de cambiar el METAGAME.\p"
	
	.string "Se lo debemos todo a la ayuda inestimable\n"
	.string "de RAGU, y de MERÚM, los fundadores del\l"
	.string "proyecto.\p"
	
	.string "Nuestra primera creación es un nuevo\n"
	.string "POKéMON al que llamamos PRINPAWN,\l"
	.string "el POKéMON peón.\p"
	
	.string "PRINPAWN puede parece débil a simple\n"
	.string "vista, pero hemos descubierto su\l"
	.string "capacidad de evolucionar a dos fuertes\l"
	.string "nuevos POKéMON dependiendo del género.\p"
	.string "Los llamamos por el nombre de COUREEN,\n"
	.string "el POKéMON reina, y KINCURS, el POKéMON\l"
	.string "rey.\p"
	
	.string "Hemos soltado muchos PRINPAWN por la\n"
	.string "región de HOENN.\p"
	.string "Estaremos pendiendes de ver como se\n"
	.string "desenvuelven en este mundo cruel.\p"

	.string "Firmado por el científico Gerph.$"
	
MicoloHideout_MeetingRoom_PC7_Text_0:
	.string "Parece un documento con información\n"
	.string "confidencial que dice lo siguiente:\p"

	.string "Esto es maravilloso, la POKéFABRICA\n"
	.string "sigue dando buenas alegrías.\p"
	
	.string "Después de varias creaciones exitosas:\n"
	.string "WINTASS, PRINPAWN, NUMEL LUCKY,\l"
	.string "WOOLOKA, y HONEDGE MONADO.\p"
	
	.string "¡Por fin he podido crear al POKéMON de\n"
	.string "mis sueños!\p"
	
	.string "Me ha costado sudor y lagrimas convencer\n"
	.string "a los fundadores del proyecto, pero ha\l"
	.string "merecido la pena.\p"
	
	.string "Nuestra nueva creación es un nuevo\n"
	.string "POKéMON al que hemos llamado POSORD.\p"
	
	.string "Tipos: GHOST / STEEL\p"
	
	.string "Estadísticas Base:\n"
	.string "55 HP, 90 ATK, 120 DEF, 70 SATK,\l" 
	.string "60 SDEF, 109 SPEED\p"
	
	.string "Habilidad: LEVITATE\p"
	
	.string "Hemos soltado muchos POSORD en lugares\n"
	.string "estratégicos para que la gente pueda\l"
	.string "admirar su grandeza.\p"
	
	.string "Firmado por el científico Gerph.$"


MicoloHideout_MeetingRoom_PCHeal_Text_0:
	.string "¿Quieres curar a tus POKéMON?$"

MicoloHideout_MeetingRoom_MauvilleMewVader::
	lock
	faceplayer
	playmoncry SPECIES_MEW, 2
	waitmoncry
	setflag FLAG_AVADER_OPEN_MAUVILLE_RUINS
	msgbox MicoloHideout_MeetingRoom_MauvilleMewVader_Text_0, MSGBOX_DEFAULT
	waitmessage
	msgbox MicoloHideout_MeetingRoom_MauvilleMewVader_Text_1, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq MicoloHideout_MeetingRoom_MauvilleMewVader2
	release
	end
MicoloHideout_MeetingRoom_MauvilleMewVader2:
	warp MAP_ROUTE110, 6, 0, 0
	waitstate
	release
	end


MicoloHideout_MeetingRoom_MauvilleMewVader_Text_0:
	.string "Este MEW tiene una nota:\p"
	.string "“He ido a la RUTA 110 con tu PRIMA.\n"
	.string "Si quieres pasar, ve a buscarme.\p"
	.string "A.VADER”$"
	

MicoloHideout_MeetingRoom_MauvilleMewVader_Text_1:
	.string "MEW puede teletransportarte hasta\n"
	.string "el lugar de encuentro.\p"
	.string "¿Quieres que te lleve hacia allí?$"
