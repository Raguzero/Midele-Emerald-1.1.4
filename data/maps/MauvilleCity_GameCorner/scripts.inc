MauvilleCity_GameCorner_MapScripts:: @ 820FBB8
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_GameCorner_OnTransition
	.byte 0

    @ Game Corner prices
	.set TM32_COINS,  9000
	.set DOLL_COINS,  1000

	.set COINS_PRICE_50,  1000
	.set COINS_PRICE_500, 10000

MauvilleCity_GameCorner_OnTransition::
	call_if_defeated TRAINER_GHADDAR, MauvilleCity_GameCorner_OnTransition_RemoveGhaddarEvent
	return

MauvilleCity_GameCorner_OnTransition_RemoveGhaddarEvent:
	setvar VAR_TEMP_0, 1
	return

MauvilleCity_GameCorner_EventScript_CoinsClerk:: @ 820FBB9
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NeedCoinCase
	message MauvilleCity_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0, 0
	showcoinsbox 1, 6
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50:: @ 820FBE5
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, 0
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

@ Unused
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault500:: @ 820FC0C
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, 0
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_Buy50Coins:: @ 820FC33
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, MAX_COINS + 1 - 50
	goto_if_ge MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50, 0
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50, 0
	updatemoneybox 0, 0
	updatecoinsbox 1, 6
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_Buy500Coins:: @ 820FC75
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, MAX_COINS + 1 - 500
	goto_if_ge MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500, 0
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500, 0
	updatemoneybox 0, 0
	updatecoinsbox 1, 6
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NeedCoinCase:: @ 820FCB7
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughMoney:: @ 820FCC1
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_CancelBuyCoins:: @ 820FCD1
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NoRoomForCoins:: @ 820FCE1
	msgbox MauvilleCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_PrizeCornerDolls:: @ 820FCF1
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage:: @ 820FD0D
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize:: @ 820FD20
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ChooseDollPrize:: @ 820FD2B
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, 0
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_TreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_TorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_MudkipDoll
	case 3, MauvilleCity_GameCorner_EventScript_CancelDollSelect
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect
	end

MauvilleCity_GameCorner_EventScript_TreeckoDoll:: @ 820FD67
	setvar VAR_TEMP_1, 1
	bufferdecorationname 0, DECOR_TREECKO_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_TorchicDoll:: @ 820FD75
	setvar VAR_TEMP_1, 2
	bufferdecorationname 0, DECOR_TORCHIC_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_MudkipDoll:: @ 820FD83
	setvar VAR_TEMP_1, 3
	bufferdecorationname 0, DECOR_MUDKIP_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_ConfirmDollPrize:: @ 820FD91
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_CancelDollSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll
	case 2, MauvilleCity_GameCorner_EventScript_BuyTorchicDoll
	case 3, MauvilleCity_GameCorner_EventScript_BuyMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll:: @ 820FDCB
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, DOLL_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname 1, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TREECKO_DOLL
	updatecoinsbox 1, 1
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTorchicDoll:: @ 820FE05
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, DOLL_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname 1, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TORCHIC_DOLL
	updatecoinsbox 1, 1
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyMudkipDoll:: @ 820FE3F
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, DOLL_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname 1, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_MUDKIP_DOLL
	updatecoinsbox 1, 1
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll:: @ 820FE79
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForDoll:: @ 820FE87
	call Common_EventScript_NoRoomForDecor
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_CancelDollSelect:: @ 820FE92
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_PrizeCornerTMs:: @ 820FE9F
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage:: @ 820FEBB
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize:: @ 820FECE
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize

MauvilleCity_GameCorner_EventScript_ChooseTMPrize:: @ 820FED9
	multichoice 12, 0, MULTI_GAME_CORNER_TMS, 0
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_TM32
	case 1, MauvilleCity_GameCorner_EventScript_CancelTMSelect
	goto MauvilleCity_GameCorner_EventScript_CancelTMSelect
	end

MauvilleCity_GameCorner_EventScript_TM32:: @ 820FF2B
	setvar VAR_TEMP_1, 1
	bufferitemname 0, ITEM_TM32
	setvar VAR_0x8004, ITEM_TM32
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_ConfirmTMPrize:: @ 820FF8A
	special BufferTMHMMoveName
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_CancelTMSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyTM32
	end

MauvilleCity_GameCorner_EventScript_BuyTM32:: @ 820FFDD
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, TM32_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM32, 1
    compare VAR_RESULT, TRUE
    goto_if_eq MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins TM32_COINS
	additem ITEM_TM32
	updatecoinsbox 1, 1
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM:: @ 82100FF
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis::
    msgbox gText_YouAlreadyHaveThis, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_CancelTMSelect:: @ 8210118
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_Woman2:: @ 8210125
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Gentleman:: @ 821012E
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Girl:: @ 8210137
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
	switch VAR_STARTER_MON
	case 0, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll:: @ 821017C
	bufferdecorationname 1, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TREECKO_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTorchicDoll:: @ 82101A6
	bufferdecorationname 1, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TORCHIC_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveMudkipDoll:: @ 82101D0
	bufferdecorationname 1, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_MUDKIP_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll:: @ 82101FA
	call Common_EventScript_NoRoomForDecor
	msgbox MauvilleCity_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_DeclineStarterDoll:: @ 8210209
	msgbox MauvilleCity_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll:: @ 8210213
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_PokefanM:: @ 821021D
	lock
	faceplayer
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_TryGive20Coins
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_TryGive20Coins:: @ 821023D
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_PokefanMNormal
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, 1  @ Only give 20 coins if player has no coins
	goto_if_ge MauvilleCity_GameCorner_EventScript_PokefanMNormal
	setflag FLAG_RECEIVED_20_COINS
	addcoins 20
	msgbox MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
	playse SE_REGI
	goto MauvilleCity_GameCorner_EventScript_PokefanMNormal
	end

MauvilleCity_GameCorner_EventScript_PokefanMNormal:: @ 821026B
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_OldMan:: @ 8210279
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Cook:: @ 8210289
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Man:: @ 8210299
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_NPCReturnToSlots:: @ 82102A9
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_GameCorner_EventScript_Maniac:: @ 82102B6
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Woman:: @ 82102C6
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine0:: @ 82102D6
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine1:: @ 82102F6
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine2:: @ 8210316
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine3:: @ 8210336
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine4:: @ 8210356
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine5:: @ 8210376
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine6:: @ 8210396
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine7:: @ 82103B6
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine8:: @ 82103D6
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine9:: @ 82103F6
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine10:: @ 8210416
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine11:: @ 8210436
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_NoCoinCase:: @ 8210456
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end
	
MauvilleCity_GameCorner_EventScript_MonPrizesStart::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst
	release
	end
	
MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst:
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 0, 0
	goto MauvilleCity_GameCorner_EventScript_MonPrizes
	
MauvilleCity_GameCorner_EventScript_MonPrizes:
    multichoice 12, 0, MULTI_GAME_CORNER_PKMN, 0
    switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_FERROSEEDConfirm
	case 1, MauvilleCity_GameCorner_EventScript_SANDYGASTConfirm
	case 2, MauvilleCity_GameCorner_EventScript_SNOMConfirm
	case 3, MauvilleCity_GameCorner_EventScript_PINECOConfirm
	case 4, MauvilleCity_GameCorner_EventScript_MEDITITEConfirm
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect 
	end
	
MauvilleCity_GameCorner_EventScript_FERROSEEDConfirm:
	setvar VAR_TEMP_1, 1
    bufferspeciesname 0, SPECIES_FERROSEED
	goto MauvilleCity_GameCorner_EventScript_MonConfirm
    
MauvilleCity_GameCorner_EventScript_SANDYGASTConfirm:
	setvar VAR_TEMP_1, 2
    bufferspeciesname 0, SPECIES_SANDYGAST
	goto MauvilleCity_GameCorner_EventScript_MonConfirm
    
MauvilleCity_GameCorner_EventScript_SNOMConfirm:
	setvar VAR_TEMP_1, 3
    bufferspeciesname 0, SPECIES_SNOM
	goto MauvilleCity_GameCorner_EventScript_MonConfirm
    
MauvilleCity_GameCorner_EventScript_PINECOConfirm:
	setvar VAR_TEMP_1, 4
    bufferspeciesname 0, SPECIES_PINECO
	goto MauvilleCity_GameCorner_EventScript_MonConfirm
    
MauvilleCity_GameCorner_EventScript_MEDITITEConfirm:
	setvar VAR_TEMP_1, 5
    bufferspeciesname 0, SPECIES_MEDITITE
	goto MauvilleCity_GameCorner_EventScript_MonConfirm
	
MauvilleCity_GameCorner_EventScript_MonConfirm:
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO 
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_CancelDollSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_FERROSEED
	case 2, MauvilleCity_GameCorner_EventScript_SANDYGAST
	case 3, MauvilleCity_GameCorner_EventScript_SNOM
	case 4, MauvilleCity_GameCorner_EventScript_PINECO
	case 5, MauvilleCity_GameCorner_EventScript_MEDITITE
	end

.macro GiveMonGameCorner species:req, level:req, coins:req, chooseAddress:req
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, \coins
	goto_if_ge .GiveMonGameCorner_Pay_\@
	call MauvilleCity_GameCorner_EventScript_NoCoinsForMon
	goto \chooseAddress
.GiveMonGameCorner_Pay_\@:
	givemon \species, \level, ITEM_NONE
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoom
	copyvar VAR_0x8004, VAR_RESULT
	removecoins \coins
	updatecoinsbox 0, 0
	playse SE_REGI
    waitse
	playfanfare MUS_FANFA4
	bufferspeciesname 0, \species
	message MauvilleCity_GameCorner_Text_GetMon
	waitfanfare
	waitmessage
	bufferspeciesname 1, \species
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne .GiveMonGameCorner_NicknameDone_\@
	compare VAR_0x8004, MON_GIVEN_TO_PC
	goto_if_eq .GiveMonGameCorner_NicknamePC_\@
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto .GiveMonGameCorner_NicknameDone_\@
.GiveMonGameCorner_NicknamePC_\@:
	call Common_EventScript_NameReceivedBoxMon
.GiveMonGameCorner_NicknameDone_\@:
	setvar VAR_TEMP_1, \species
	compare VAR_0x8004, MON_GIVEN_TO_PC
	call_if_eq Common_EventScript_TransferredToPC
    goto \chooseAddress
.endm
	
MauvilleCity_GameCorner_EventScript_FERROSEED:
	GiveMonGameCorner SPECIES_FERROSEED, 20, 1500, MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst

MauvilleCity_GameCorner_EventScript_SANDYGAST:
	GiveMonGameCorner SPECIES_SANDYGAST, 20, 1200, MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst
    
MauvilleCity_GameCorner_EventScript_SNOM:
	GiveMonGameCorner SPECIES_SNOM, 20, 1000, MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst
    
MauvilleCity_GameCorner_EventScript_PINECO:
	GiveMonGameCorner SPECIES_PINECO, 20, 500, MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst
    
MauvilleCity_GameCorner_EventScript_MEDITITE:
	GiveMonGameCorner SPECIES_MEDITITE, 20, 1300, MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst

MauvilleCity_GameCorner_EventScript_MonPrizesStart2::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst2
	release
	end
	
MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst2:
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 0, 0
	goto MauvilleCity_GameCorner_EventScript_MonPrizes2	
	
MauvilleCity_GameCorner_EventScript_MonPrizes2:
    multichoice 12, 0, MULTI_GAME_CORNER_PKMN2, 0
    switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_SPHEALConfirm
	case 1, MauvilleCity_GameCorner_EventScript_CUBONEConfirm
	case 2, MauvilleCity_GameCorner_EventScript_VENONATConfirm
	case 3, MauvilleCity_GameCorner_EventScript_HAPPINYConfirm
	case 4, MauvilleCity_GameCorner_EventScript_WOOPERConfirm
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect 
	end
	
MauvilleCity_GameCorner_EventScript_SPHEALConfirm:
	setvar VAR_TEMP_1, 1
    bufferspeciesname 0, SPECIES_SPHEAL
	goto MauvilleCity_GameCorner_EventScript_MonConfirm2
    
MauvilleCity_GameCorner_EventScript_CUBONEConfirm:
	setvar VAR_TEMP_1, 2
    bufferspeciesname 0, SPECIES_CUBONE
	goto MauvilleCity_GameCorner_EventScript_MonConfirm2
    
MauvilleCity_GameCorner_EventScript_VENONATConfirm:
	setvar VAR_TEMP_1, 3
    bufferspeciesname 0, SPECIES_VENONAT
	goto MauvilleCity_GameCorner_EventScript_MonConfirm2
    
MauvilleCity_GameCorner_EventScript_HAPPINYConfirm:
	setvar VAR_TEMP_1, 4
    bufferspeciesname 0, SPECIES_HAPPINY
	goto MauvilleCity_GameCorner_EventScript_MonConfirm2
    
MauvilleCity_GameCorner_EventScript_WOOPERConfirm:
	setvar VAR_TEMP_1, 5
    bufferspeciesname 0, SPECIES_WOOPER
	goto MauvilleCity_GameCorner_EventScript_MonConfirm2
	
MauvilleCity_GameCorner_EventScript_MonConfirm2:
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO 
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_CancelDollSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_SPHEAL
	case 2, MauvilleCity_GameCorner_EventScript_CUBONE
	case 3, MauvilleCity_GameCorner_EventScript_VENONAT
	case 4, MauvilleCity_GameCorner_EventScript_HAPPINY
	case 5, MauvilleCity_GameCorner_EventScript_WOOPER
	end
	
MauvilleCity_GameCorner_EventScript_SPHEAL:
	GiveMonGameCorner SPECIES_SPHEAL, 20, 800, MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst2

MauvilleCity_GameCorner_EventScript_CUBONE:
	GiveMonGameCorner SPECIES_CUBONE, 20, 500, MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst2
    
MauvilleCity_GameCorner_EventScript_VENONAT:
	GiveMonGameCorner SPECIES_VENONAT, 20, 500, MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst2
    
MauvilleCity_GameCorner_EventScript_HAPPINY:
	GiveMonGameCorner SPECIES_HAPPINY, 20, 2500, MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst2
    
MauvilleCity_GameCorner_EventScript_WOOPER:
	GiveMonGameCorner SPECIES_WOOPER, 20, 800, MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst2

MauvilleCity_GameCorner_EventScript_NoRoom:
	msgbox MauvilleCity_GameCorner_Text_NoRoom, 4
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_NoCoinsForMon:
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, 4
	return	

MauvilleCity_GameCorner_EventScript_Ghaddar_Hablar::
	lock
	faceplayer
	goto_if_defeated TRAINER_GHADDAR, MauvilleCity_GameCorner_EventScript_Ghaddar_FALTAEMPATIA
	goto MauvilleCity_GameCorner_EventScript_Ghaddar_ENCONTRA
	release
	end 

MauvilleCity_GameCorner_EventScript_Ghaddar::
	lock
	faceplayer
	speakername CommonName_Text_Ghaddar
	msgbox MauvilleCity_GameCorner_Text_Ghaddar, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq MauvilleCity_GameCorner_EventScript_Ghaddar_Combate
	compare VAR_RESULT, NO
    call_if_eq MauvilleCity_GameCorner_EventScript_Ghaddar_ENCONTRA
	release
	end
	
MauvilleCity_GameCorner_EventScript_Ghaddar_Combate::
	setvar VAR_TEMP_0, 1
	trainerbattle_single TRAINER_GHADDAR, MauvilleCity_GameCorner_Text_GhaddarIntro, MauvilleCity_GameCorner_Text_GhaddarDefeat
	release
	end
	
MauvilleCity_GameCorner_EventScript_Ghaddar_ENCONTRA::
	speakername CommonName_Text_Ghaddar
	msgbox MauvilleCity_GameCorner_Text_Ghaddar_ENCONTRA, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
	release
	end

MauvilleCity_GameCorner_EventScript_Ghaddar_FALTAEMPATIA:
	speakername CommonName_Text_Ghaddar
	msgbox MauvilleCity_GameCorner_Text_Ghaddar_FALTAEMPATIA, MSGBOX_NPC
	release
	end

MauvilleCity_GameCorner_EventScript_Ghaddar_Trigger1::
	applymovement 15, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN 
	applymovement 15, MauvilleCity_GameCorner_Movement_GhaddarFaceDown
	waitmovement 0
	goto MauvilleCity_GameCorner_EventScript_Ghaddar
	end

MauvilleCity_GameCorner_EventScript_Ghaddar_Trigger2::
	applymovement 15, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN 
	applymovement 15, MauvilleCity_GameCorner_Movement_GhaddarMoveRightEntrance
	waitmovement 0
	goto MauvilleCity_GameCorner_EventScript_Ghaddar
	end

MauvilleCity_GameCorner_Movement_GhaddarMoveRightEntrance::
	walk_fast_right
MauvilleCity_GameCorner_Movement_GhaddarFaceDown:
	face_down
	step_end
	
MauvilleCity_GameCorner_Text_Ghaddar:
	.string "¡HACHA al GACHA!\n"
	.string "¡Este lugar es una vergüenza!\p"

	.string "¿Que no entiendes por qué?\n"
	.string "Deja que te lo explique.\p"

	.string "El GACHA es un conjunto de\n"
	.string "técnicas para abusar del\l" 
	.string "comportamiento humano y hacer\l" 
	.string "que la gente se deje toda la pasta\l" 
	.string "en cosas superfluas cayendo directos\l"
	.string "a una adicción.\p"

	.string "Estas compañías sacan de forma\n"
	.string "gratuita estos juegos llenos\l"
	.string "de gachas para así captar a sus\l"
	.string "nuevas víctimas.\p"
	
	.string "¡Pero todos vosotros no hacéis\n"
	.string "más que normalizar el gacha hablando\l"
	.string "de ello y haciendo que más gente\l"
	.string "caiga en el pozo inmundo de\l"
	.string "los GACHAS!\p"
	
	.string "Y bien, ¿en qué bando estás?\p"
	
	.string "¿Estás a FAVOR de los GACHAS?$"
	
MauvilleCity_GameCorner_Text_Ghaddar_ENCONTRA:
	.string "¡HACHA al GACHA!\p"

	.string "¡El primer paso será desinstalar\n"
	.string "todos los Fire Emblem Heroes y los\l"
	.string "Genshin Impact de los móviles!$"
	
MauvilleCity_GameCorner_Text_GhaddarIntro:
	.string "Así que eres otra víctima de la\n"
	.string "manipulación de cerebros que hacen\l"
	.string "las compañías con los GACHAS...\p"

	.string "Si a pesar de mis argumentos, decides\n"
	.string "jugar en este sitio...\p"
	
	.string "No me quedará más remedio...\p"
	
	.string "¡QUE OBLIGARTE A ENTENDERLO POR\n"
	.string "LA FUERZA!$"
	
MauvilleCity_GameCorner_Text_GhaddarDefeat:
	.string "Se dice GHADDAR, no GADAR,\n"
	.string "ni GADDAR...\p"
	
	.string "¡Aprended de una vez a escribir\n"
	.string "bien mi nombre! :/$"

MauvilleCity_GameCorner_Text_Ghaddar_FALTAEMPATIA:
	.string "Bah, te falta empatía.\p"
	
	.string "Sabes que yo tengo razón.\p"
	
	.string "¡Sabes muy bien que la tengo!\p"
	
	.string "¡Estás cometiendo un grave error\n"
	.string "poniéndote del lado de los GACHAS!$"

MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner: @ 8210460
	.string "This is MAUVILLE GAME CORNER.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins: @ 821047E
	.string "Okay, you wanted some COINS for\n"
	.string "the games?\p"
	.string "But you don't have a COIN CASE for\n"
	.string "stowing the COINS.$"

MauvilleCity_GameCorner_Text_WereYouLookingForCoins: @ 82104DF
	.string "Were you looking for COINS?\p"
	.string "It's ¥1000 for 50 COINS.\n"
	.string "Would you like some?$"

MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins: @ 8210529
	.string "Thank you very much!\n"
	.string "Here are your COINS!$"

MauvilleCity_GameCorner_Text_DontHaveEnoughMoney: @ 8210553
	.string "Um… You don't appear to have\n"
	.string "enough money…$"

MauvilleCity_GameCorner_Text_CoinCaseIsFull: @ 821057E
	.string "Oh?\n"
	.string "Your COIN CASE is full.$"

MauvilleCity_GameCorner_Text_DontNeedCoinsThen: @ 821059A
	.string "Oh… You don't need COINS, then?\n"
	.string "Good luck on your adventure!$"

MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes: @ 82105D7
	.string "Welcome.\p"
	.string "You can exchange your COINS for\n"
	.string "prizes here.$"

MauvilleCity_GameCorner_Text_WhichPrize: @ 821060D
	.string "Which prize would you like?$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX: @ 8210629
	.string "So your choice is\n"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"

MauvilleCity_GameCorner_Text_SendToYourHomePC: @ 8210646
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

MauvilleCity_GameCorner_Text_NotEnoughCoins: @ 8210673
	.string "You don't have enough COINS.$"

@ Unused
MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor: @ 8210690
	.string "There isn't any room available for\n"
	.string "placing {STR_VAR_1}.$"

MauvilleCity_GameCorner_Text_OhIsThatSo: @ 82106BF
	.string "Oh, is that so? \n"
	.string "You need to save some COINS before\l"
	.string "coming back here.$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsX: @ 8210705
	.string "So your choice is {STR_VAR_1}?$"

MauvilleCity_GameCorner_Text_HereYouGo: @ 821071B
	.string "Here you go!$"

@ Unused
MauvilleCity_GameCorner_Text_CantCarryAnyMore: @ 8210728
	.string "Oh, you can't carry any more than that.$"

MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne: @ 8210750
	.string "I made a mistake and got two of\n"
	.string "the same DOLLS.\p"
	.string "Would you like one of them?$"

MauvilleCity_GameCorner_Text_HereYouGo2: @ 821079C
	.string "Here you go!$"

MauvilleCity_GameCorner_Text_YouWantItButNotNow: @ 82107A9
	.string "Huh?\n"
	.string "You want it, but not right now?$"

MauvilleCity_GameCorner_Text_DontBeNegative: @ 82107CE
	.string "Oh, don't be so negative!\n"
	.string "You can have this!$"

MauvilleCity_GameCorner_Text_CantWinJackpot: @ 82107FB
	.string "There's a prize I want, but I can't win\n"
	.string "the jackpot.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor: @ 8210830
	.string "Hey, kid, if you want to play here,\n"
	.string "you need a COIN CASE.\p"
	.string "I think the young lady next door\n"
	.string "had one. Go see her!$"

MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins: @ 82108A0
	.string "My luck can only last so long.\n"
	.string "This is too much for me.\l"
	.string "Here, take some COINS!$"

MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone: @ 82108EF
	.string "MAUVILLE has something for\n"
	.string "everyone.\p"
	.string "For me, it's the GAME CORNER.$"

MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates: @ 8210932
	.string "The ROULETTE tables have different\n"
	.string "rates.\p"
	.string "Check your COINS if you're going to\n"
	.string "pick a table.$"

MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime: @ 821098E
	.string "It's easy to lose track of time in here. \n"
	.string "I should get back to work.$"

MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay: @ 82109D3
	.string "COINS are needed to play here\n"
	.string "in the GAME CORNER.$"

MauvilleCity_GameCorner_Text_RouletteOnlyLuck: @ 8210A05
	.string "This ROULETTE thing…\n"
	.string "It's rather demanding.\p"
	.string "Win or lose, it's only by luck.$"

MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed: @ 8210A51
	.string "Up to three COINS can be used to play\n"
	.string "the SLOTS.$"

MauvilleCity_GameCorner_Text_DifficultToStopOn7: @ 8210A82
	.string "It's very difficult to make it stop\n"
	.string "right on “7.”\p"
	.string "If it stops on “7” during the REEL TIME\n"
	.string "bonus game, you'll receive extra COINS.$"

MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo: @ 8210B04
	.string "Here's some information for you\n"
	.string "about the SLOTS.\p"
	.string "The more lightning bolts you stock,\n"
	.string "the more REEL TIME chances you get.\p"
	.string "In a game with the maximum five\n"
	.string "REEL TIME chances…\p"
	.string "It is possible to receive four regular\n"
	.string "bonuses, then a big bonus.\p"
	.string "That would total 660 COINS, but it's\n"
	.string "very difficult to get.$"

MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase: @ 8210C2E
	.string "You can't play if you don't have\n"
	.string "a COIN CASE.$"
	
MauvilleCity_GameCorner_Text_GetMon::
	.string "{PLAYER} received {STR_VAR_1}!$"

MauvilleCity_GameCorner_Text_NoRoom::
    .string "Your PC and party are full.$"
	
CommonName_Text_Ghaddar:
	.string "GHADDAR$"
