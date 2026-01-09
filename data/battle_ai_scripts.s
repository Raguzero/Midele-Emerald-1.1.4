#include "constants/battle.h"
#include "constants/battle_ai.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/battle_move_effects.h"
#include "constants/hold_effects.h"
#include "constants/pokemon.h"
	.include "asm/macros/battle_ai_script.inc"

	.section script_data, "aw", %progbits

	.align 2
gBattleAI_ScriptsTable:: @ 82DBEF8
	.4byte AI_CheckBadMove
	.4byte AI_TryToFaint
	.4byte AI_CheckViability
	.4byte AI_SetupFirstTurn
	.4byte AI_Risky
	.4byte AI_PreferStrongestMove
	.4byte AI_PreferBatonPass
	.4byte AI_DoubleBattle
	.4byte AI_HPAware
	.4byte AI_Unknown
    .4byte AI_UsePerishSongEvenIfLastPokemon
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Roaming
	.4byte AI_Safari
	.4byte AI_FirstBattle

AI_CheckBadMove:
	if_target_is_ally AI_Ret
	if_move MOVE_FISSURE, AI_CBM_CheckIfNegatesType
	if_move MOVE_HORN_DRILL, AI_CBM_CheckIfNegatesType
	if_move MOVE_GUILLOTINE, AI_CBM_CheckIfNegatesType
    if_move MOVE_FUTURE_SIGHT, AI_CheckBadMove_CheckSoundproof
	get_how_powerful_move_is
	if_equal MOVE_HAS_ZERO_OR_UNPREDICTABLE_POWER, AI_CheckBadMove_CheckSoundproof
    if_equal MOVE_POWER_DISCOURAGED, AI_CheckBadMove_CheckSubstitute
    if_equal MOVE_POWER_DISCOURAGED_AND_NOT_MOST_POWERFUL, AI_CheckBadMove_CheckSubstitute
    goto AI_CBM_CheckIfNegatesType
AI_CheckBadMove_CheckSubstitute:
    if_target_might_have_a_sub_before_our_attack AI_CheckBadMove_CheckSubstitute_ScoreMinus2
    goto AI_CBM_CheckIfNegatesType
AI_CheckBadMove_CheckSubstitute_ScoreMinus2:
	score -2

AI_CBM_CheckIfNegatesType:
    if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
    if_ability_might_be AI_TARGET, ABILITY_WONDER_GUARD, CheckIfWonderGuardCancelsMove
    get_curr_move_type
    if_equal_ TYPE_ELECTRIC, CheckVoltAbsorb
    if_equal_ TYPE_WATER, CheckWaterAbsorb
    if_equal_ TYPE_FIRE, CheckFlashFire
    if_equal_ TYPE_GROUND, CheckLevitate
    if_effect EFFECT_WEATHER_BALL, AI_CBM_CheckIfNegatesType_WeatherBall
    goto AI_CheckBadMove_CheckSoundproof

AI_CBM_CheckIfNegatesType_WeatherBall:
    get_weather
    if_equal AI_WEATHER_RAIN, CheckWaterAbsorb
    if_equal AI_WEATHER_SUN, CheckFlashFire
    goto AI_CheckBadMove_CheckSoundproof

CheckVoltAbsorb:
    if_ability_might_be AI_TARGET, ABILITY_VOLT_ABSORB, Score_Minus12
    if_ability_might_be AI_TARGET, ABILITY_LIGHTNING_ROD, Score_Minus12
    if_ability_might_be AI_TARGET, ABILITY_MOTOR_DRIVE, Score_Minus12
    goto AI_CheckBadMove_CheckSoundproof

CheckWaterAbsorb:
    if_ability_might_be AI_TARGET, ABILITY_WATER_ABSORB, Score_Minus12
    if_ability_might_be AI_TARGET, ABILITY_DRY_SKIN, Score_Minus12
    goto AI_CheckBadMove_CheckSoundproof

CheckFlashFire:
    if_ability_might_be AI_TARGET, ABILITY_FLASH_FIRE, Score_Minus12
    goto AI_CheckBadMove_CheckSoundproof

CheckIfWonderGuardCancelsMove:
    if_type_effectiveness AI_EFFECTIVENESS_x2, AI_CheckBadMove_CheckSoundproof
    if_type_effectiveness AI_EFFECTIVENESS_x4, AI_CheckBadMove_CheckSoundproof
    goto Score_Minus10

CheckLevitate:
    if_ability_might_be AI_TARGET, ABILITY_LEVITATE, Score_Minus10

AI_CheckBadMove_CheckSoundproof: @ 82DBFFE
    if_ability_might_be AI_TARGET, ABILITY_SOUNDPROOF, AI_CheckBadMove_CheckSoundMoves
    goto AI_CheckBadMove_CheckPerishSong
AI_CheckBadMove_CheckSoundMoves:
	if_move MOVE_GROWL, Score_Minus10
	if_move MOVE_ROAR, Score_Minus10
	if_move MOVE_SING, Score_Minus10
	if_move MOVE_SUPERSONIC, Score_Minus10
	if_move MOVE_SCREECH, Score_Minus10
	if_move MOVE_SNORE, Score_Minus10
	if_move MOVE_UPROAR, Score_Minus10
	if_move MOVE_METAL_SOUND, Score_Minus10
	if_move MOVE_GRASS_WHISTLE, Score_Minus10
	if_move MOVE_HYPER_VOICE, Score_Minus10
	if_move MOVE_PERISH_SONG, Score_Minus10
	if_move MOVE_OVERDRIVE, Score_Minus10
	if_move MOVE_BOOMBURST, Score_Minus10
AI_CheckBadMove_CheckPerishSong:
	if_perish_song_not_about_to_trigger AI_USER, AI_CheckBadMove_CheckThawingAndNotKO
	if_move_is_useless_when_choiced Score_Minus10
	
AI_CheckBadMove_CheckThawingAndNotKO:
    if_not_status AI_TARGET, STATUS1_FREEZE, AI_CheckBadMove_CheckEffect
    get_curr_move_type
    if_not_equal TYPE_FIRE, AI_CheckBadMove_CheckEffect
    get_considered_move_power
    if_equal 0, AI_CheckBadMove_CheckEffect
    if_can_faint AI_CheckBadMove_CheckEffect
    score -5


AI_CheckBadMove_CheckEffect: @ 82DC045
	if_effect EFFECT_SLEEP, AI_CBM_Sleep
	if_effect EFFECT_EXPLOSION, AI_CBM_Explosion
	if_effect EFFECT_DREAM_EATER, AI_CBM_DreamEater
	if_effect EFFECT_ATTACK_UP, AI_CBM_AttackUp
	if_effect EFFECT_DEFENSE_UP, AI_CBM_DefenseUp
	if_effect EFFECT_SPEED_UP, AI_CBM_SpeedUp
	if_effect EFFECT_SPECIAL_ATTACK_UP, AI_CBM_SpAtkUp
	if_effect EFFECT_SPECIAL_DEFENSE_UP, AI_CBM_SpDefUp
	if_effect EFFECT_ACCURACY_UP, AI_CBM_AccUp
	if_effect EFFECT_EVASION_UP, AI_CBM_EvasionUp
	if_effect EFFECT_ATTACK_DOWN, AI_CBM_AttackDown
	if_effect EFFECT_DEFENSE_DOWN, AI_CBM_DefenseDown
	if_effect EFFECT_SPEED_DOWN, AI_CBM_SpeedDown
	if_effect EFFECT_SPECIAL_ATTACK_DOWN, AI_CBM_SpAtkDown
	if_effect EFFECT_SPECIAL_DEFENSE_DOWN, AI_CBM_SpDefDown
	if_effect EFFECT_ACCURACY_DOWN, AI_CBM_AccDown
	if_effect EFFECT_EVASION_DOWN, AI_CBM_EvasionDown
	if_effect EFFECT_HAZE, AI_CBM_Haze
	if_effect EFFECT_BIDE, AI_CBM_HighRiskForDamage
	if_effect EFFECT_ROAR, AI_CBM_Roar
	if_effect EFFECT_TOXIC, AI_CBM_Toxic
	if_effect EFFECT_LIGHT_SCREEN, AI_CBM_LightScreen
	if_effect EFFECT_OHKO, AI_CBM_OneHitKO
	if_effect EFFECT_RAZOR_WIND, AI_CBM_HighRiskForDamage
	if_effect EFFECT_SUPER_FANG, AI_CBM_HighRiskForDamage
	if_effect EFFECT_MIST, AI_CBM_Mist
	if_effect EFFECT_FOCUS_ENERGY, AI_CBM_FocusEnergy
	if_effect EFFECT_CONFUSE, AI_CBM_Confuse
	if_effect EFFECT_ATTACK_UP_2, AI_CBM_AttackUp
	if_effect EFFECT_DEFENSE_UP_2, AI_CBM_DefenseUp
	if_effect EFFECT_SPEED_UP_2, AI_CBM_SpeedUp
	if_effect EFFECT_SPECIAL_ATTACK_UP_2, AI_CBM_SpAtkUp
	if_effect EFFECT_SPECIAL_ATTACK_UP_3, AI_CBM_SpAtkUp
	if_effect EFFECT_ATTACK_SPATK_UP, AI_CBM_Growth
	if_effect EFFECT_SPECIAL_DEFENSE_UP_2, AI_CBM_SpDefUp
	if_effect EFFECT_ACCURACY_UP_2, AI_CBM_AccUp
	if_effect EFFECT_EVASION_UP_2, AI_CBM_EvasionUp
	if_effect EFFECT_ATTACK_DOWN_2, AI_CBM_AttackDown
	if_effect EFFECT_DEFENSE_DOWN_2, AI_CBM_DefenseDown
	if_effect EFFECT_SPEED_DOWN_2, AI_CBM_SpeedDown
	if_effect EFFECT_SPECIAL_ATTACK_DOWN_2, AI_CBM_SpAtkDown
	if_effect EFFECT_SPECIAL_DEFENSE_DOWN_2, AI_CBM_SpDefDown
	if_effect EFFECT_ACCURACY_DOWN_2, AI_CBM_AccDown
	if_effect EFFECT_EVASION_DOWN_2, AI_CBM_EvasionDown
	if_effect EFFECT_REFLECT, AI_CBM_Reflect
	if_effect EFFECT_POISON, AI_CBM_Toxic
	if_effect EFFECT_PARALYZE, AI_CBM_Paralyze
	if_effect EFFECT_SUBSTITUTE, AI_CBM_Substitute
	if_effect EFFECT_RECHARGE, AI_CBM_HighRiskForDamage
	if_effect EFFECT_LEECH_SEED, AI_CBM_LeechSeed
	if_effect EFFECT_DISABLE, AI_CBM_Disable
	if_effect EFFECT_PSYWAVE, AI_CBM_HighRiskForDamage
	if_effect EFFECT_COUNTER, AI_CBM_HighRiskForDamage
	if_effect EFFECT_ENCORE, AI_CBM_Encore
	if_effect EFFECT_SNORE, AI_CBM_DamageDuringSleep
	if_effect EFFECT_MEAN_LOOK, AI_CBM_CantEscape
	if_effect EFFECT_NIGHTMARE, AI_CBM_Nightmare
	if_effect EFFECT_MINIMIZE, AI_CBM_EvasionUp
	if_effect EFFECT_CURSE, AI_CBM_Curse
	if_effect EFFECT_SPIKES, AI_CBM_Spikes
	if_effect EFFECT_FORESIGHT, AI_CBM_Foresight
	if_effect EFFECT_PERISH_SONG, AI_CBM_PerishSong
	if_effect EFFECT_SANDSTORM, AI_CBM_Sandstorm
	if_effect EFFECT_SWAGGER, AI_CBM_Confuse
	if_effect EFFECT_ATTRACT, AI_CBM_Attract
	if_effect EFFECT_PRESENT, AI_CBM_HighRiskForDamage
	if_effect EFFECT_SAFEGUARD, AI_CBM_Safeguard
	if_effect EFFECT_MAGNITUDE, AI_CBM_Magnitude
	if_effect EFFECT_BATON_PASS, AI_CBM_BatonPass
	if_effect EFFECT_RAIN_DANCE, AI_CBM_RainDance
	if_effect EFFECT_SUNNY_DAY, AI_CBM_SunnyDay
	if_effect EFFECT_BELLY_DRUM, AI_CBM_BellyDrum
	if_effect EFFECT_PSYCH_UP, AI_CBM_Haze
	if_effect EFFECT_MIRROR_COAT, AI_CBM_HighRiskForDamage
	if_effect EFFECT_SKULL_BASH, AI_CBM_HighRiskForDamage
	if_effect EFFECT_FUTURE_SIGHT, AI_CBM_FutureSight
	if_effect EFFECT_TELEPORT, Score_Minus10
	if_effect EFFECT_DEFENSE_CURL, AI_CBM_DefenseUp
	if_effect EFFECT_FAKE_OUT, AI_CBM_FakeOut
	if_effect EFFECT_STOCKPILE, AI_CBM_Stockpile
	if_effect EFFECT_SPIT_UP, AI_CBM_SpitUpAndSwallow
	if_effect EFFECT_SWALLOW, AI_CBM_SpitUpAndSwallow
	if_effect EFFECT_HAIL, AI_CBM_Hail
	if_effect EFFECT_TORMENT, AI_CBM_Torment
	if_effect EFFECT_FLATTER, AI_CBM_Confuse
	if_effect EFFECT_WILL_O_WISP, AI_CBM_WillOWisp
	if_effect EFFECT_MEMENTO, AI_CBM_Memento
	if_effect EFFECT_HELPING_HAND, AI_CBM_HelpingHand
	if_effect EFFECT_TRICK, AI_CBM_Trick
	if_effect EFFECT_INGRAIN, AI_CBM_Ingrain
	if_effect EFFECT_SUPERPOWER, AI_CBM_HighRiskForDamage
	if_effect EFFECT_OVERHEAT, AI_CBM_HighRiskForDamage_DiscourageAgainstOpponentsWithSub
	if_effect EFFECT_RECYCLE, AI_CBM_Recycle
	if_effect EFFECT_ENDEAVOR, AI_CBM_HighRiskForDamage
	if_effect EFFECT_IMPRISON, AI_CBM_Imprison
	if_effect EFFECT_REFRESH, AI_CBM_Refresh
	if_effect EFFECT_MUD_SPORT, AI_CBM_MudSport
	if_effect EFFECT_TICKLE, AI_CBM_Tickle
	if_effect EFFECT_COSMIC_POWER, AI_CBM_CosmicPower
	if_effect EFFECT_BULK_UP, AI_CBM_BulkUp
	if_effect EFFECT_WATER_SPORT, AI_CBM_WaterSport
	if_effect EFFECT_CALM_MIND, AI_CBM_CalmMind
	if_effect EFFECT_DRAGON_DANCE, AI_CBM_DragonDance
	if_effect EFFECT_QUIVER_DANCE, AI_CBM_QuiverDance
	if_effect EFFECT_LOCK_ON, AI_CBM_LockOn
	if_effect EFFECT_COIL, AI_CBM_Coil
	if_effect EFFECT_TAUNT, AI_CBM_Taunt
	if_effect EFFECT_PROTECT, AI_CBM_Protect
	if_effect EFFECT_HEAL_BELL, AI_CBM_HealBell
	if_effect EFFECT_HEAL_PULSE, Score_Minus5
	if_effect EFFECT_MIDELE_POWER Score_Plus3
	if_effect EFFECT_YAWN, AI_CBM_Sleep
	if_effect EFFECT_MIMIC, AI_CBM_Mimic
	if_effect EFFECT_TEETER_DANCE, AI_CBM_Confuse
	if_effect EFFECT_WISH, AI_CBM_Wish
	if_effect EFFECT_FOLLOW_ME, AI_CBM_FollowMe
	if_effect EFFECT_RECOIL_IF_MISS, AI_CBM_JumpKickMiss
	end

AI_CBM_Sleep: @ 82DC2D4
    if_ability_might_be AI_TARGET, ABILITY_INSOMNIA, Score_Minus10
    if_ability_might_be AI_TARGET, ABILITY_VITAL_SPIRIT, Score_Minus10
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_target_expected_to_be_statused_assuming_equal_priority Score_Minus10
	if_status3 AI_TARGET, STATUS3_YAWN, Score_Minus10
    if_side_affecting AI_TARGET, SIDE_STATUS_SAFEGUARD, Score_Minus10
    if_move MOVE_SLEEP_POWDER, AI_CBM_Sleep_Overcoat
    if_move MOVE_SPORE, AI_CBM_Sleep_Overcoat
AI_CBM_Sleep_NoProblemWithOvercoat:
    if_ability_might_be AI_TARGET, ABILITY_EARLY_BIRD, Score_Minus5
    if_ability_might_be AI_TARGET, ABILITY_SHED_SKIN, Score_Minus5
    if_has_move_with_effect AI_TARGET, EFFECT_SLEEP_TALK, Score_Minus3
    if_user_faster AI_CBM_Sleep_End
    if_might_heal_with_natural_cure AI_TARGET, Score_Minus3
AI_CBM_Sleep_End:
    end

AI_CBM_Sleep_Overcoat:
    if_ability_might_be AI_TARGET, ABILITY_OVERCOAT, Score_Minus10
    goto AI_CBM_Sleep_NoProblemWithOvercoat


AI_CBM_Explosion: @ 82DC2F7
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	if_ability AI_USER, ABILITY_DAMP, Score_Minus10
    if_ability_might_be AI_TARGET, ABILITY_DAMP, Score_Minus10
	count_usable_party_mons AI_USER
	if_not_equal 0, AI_CBM_Explosion_NotOneVsMany
	count_usable_party_mons AI_TARGET
	if_not_equal 0, Score_Minus10
AI_CBM_Explosion_NotOneVsMany:
    if_target_might_have_a_sub_before_our_attack Score_Minus8
    if_next_turn_target_might_use_move_with_effect EFFECT_PROTECT, AI_CBM_Explosion_TargetHasProtect
    goto AI_CBM_Explosion_TargetNotExpectedToUseProtect
AI_CBM_Explosion_TargetHasProtect:
	get_protect_count AI_TARGET
    if_equal 0, Score_Minus8
    if_equal 1, Score_Minus2
AI_CBM_Explosion_TargetNotExpectedToUseProtect:
	if_next_turn_target_might_use_move_with_effect EFFECT_SEMI_INVULNERABLE, AI_CBM_Explosion_WatchOutForSemiInvulnerability
	goto AI_CBM_Explosion_SkipSemiInvulnerabilityCheck
AI_CBM_Explosion_WatchOutForSemiInvulnerability:
	if_ability AI_USER, ABILITY_NO_GUARD, AI_CBM_Explosion_SkipSemiInvulnerabilityCheck
	if_ability AI_TARGET, ABILITY_NO_GUARD, AI_CBM_Explosion_SkipSemiInvulnerabilityCheck
	if_status3 AI_TARGET, STATUS3_ALWAYS_HITS, AI_CBM_Explosion_SkipSemiInvulnerabilityCheck
	if_user_faster AI_CBM_Explosion_WatchOutForSemiInvulnerability_UserIsFaster
	if_not_status3 AI_TARGET, STATUS3_SEMI_INVULNERABLE, Score_Minus8
	goto AI_CBM_Explosion_SkipSemiInvulnerabilityCheck

AI_CBM_Explosion_WatchOutForSemiInvulnerability_UserIsFaster:
	if_status3 AI_TARGET, STATUS3_SEMI_INVULNERABLE, Score_Minus8
AI_CBM_Explosion_SkipSemiInvulnerabilityCheck:
	goto Score_Minus1

AI_CBM_Nightmare: @ 82DC31B
	if_status2 AI_TARGET, STATUS2_NIGHTMARE, Score_Minus10
	if_status2 AI_TARGET, STATUS2_SUBSTITUTE, Score_Minus10
	if_target_not_expected_to_sleep_during_next_turn Score_Minus8
	end

AI_CBM_DreamEater: @ 82DC330
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	if_target_not_expected_to_be_asleep_assuming_equal_priority Score_Minus10
	if_status2 AI_TARGET, STATUS2_SUBSTITUTE, Score_Minus10
	end

AI_CBM_BellyDrum: @ 82DC341
	if_hp_condition USER_CANNOT_USE_BELLY_DRUM, Score_Minus10
AI_CBM_AttackUp: @ 82DC348
	if_perish_song_about_to_trigger AI_USER, Score_Minus10
	if_stat_level_equal AI_USER, STAT_ATK, 12, Score_Minus10
	if_user_cannot_attack_and_no_pass_is_available Score_Minus10
	end

AI_CBM_DefenseUp: @ 82DC351
	if_stat_level_equal AI_USER, STAT_DEF, 12, Score_Minus10
	goto AI_CBM_DefenseOrEvasion_CheckIfOpponentCanPhaze

AI_CBM_SpeedUp: @ 82DC35A
	if_perish_song_about_to_trigger AI_USER, Score_Minus10
	if_stat_level_equal AI_USER, STAT_SPEED, 12, Score_Minus10
	end

AI_CBM_Growth:
	if_perish_song_about_to_trigger AI_USER, Score_Minus10
	if_stat_level_less_than AI_USER, STAT_ATK, 12, AI_CBM_GrowthOrSpAtkUp_CanRaiseSomeStat
AI_CBM_SpAtkUp: @ 82DC363
	if_perish_song_about_to_trigger AI_USER, Score_Minus10
	if_stat_level_equal AI_USER, STAT_SPATK, 12, Score_Minus10
AI_CBM_GrowthOrSpAtkUp_CanRaiseSomeStat:
	if_user_cannot_attack_and_no_pass_is_available Score_Minus10
	end

AI_CBM_SpDefUp: @ 82DC36C
	if_stat_level_equal AI_USER, STAT_SPDEF, 12, Score_Minus10
	goto AI_CBM_DefenseOrEvasion_CheckIfOpponentCanPhaze

AI_CBM_AccUp: @ 82DC375
	if_perish_song_about_to_trigger AI_USER, Score_Minus10
	if_stat_level_equal AI_USER, STAT_ACC, 12, Score_Minus10
	end

AI_CBM_EvasionUp: @ 82DC37E
	if_stat_level_equal AI_USER, STAT_EVASION, 12, AI_CBM_EvasionUp_Minus10or8
AI_CBM_DefenseOrEvasion_CheckIfOpponentCanPhaze:
	if_next_turn_target_might_use_move_with_effect EFFECT_HAZE, Score_Minus8
	if_next_turn_target_might_use_move_with_effect EFFECT_ROAR, AI_CBM_Minus8IfAICanBePhazed
	end

@ Hace que prefiera gastar PP del mov de subirse Evasión en lugar de los de
@ otros movimientos igualmente inútiles si el rival está agonizando
@ (que tienen más opciones de ser útiles cuando el rival caiga)
AI_CBM_EvasionUp_Minus10or8:
    if_status AI_TARGET, STATUS1_TOXIC_POISON, Score_Minus8
    if_status2 AI_TARGET, STATUS2_CURSED, Score_Minus8
    goto Score_Minus10

AI_CBM_AttackDown: @ 82DC387
    if_target_might_have_a_sub_before_our_attack Score_Minus10
AI_CBM_AttackDown_SkipSub:
	if_stat_level_equal AI_TARGET, STAT_ATK, 0, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_MIST, Score_Minus10
    if_ability_might_be AI_TARGET, ABILITY_HYPER_CUTTER, Score_Minus10
	goto CheckIfAbilityBlocksStatChange

AI_CBM_DefenseDown: @ 82DC39C
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_stat_level_equal AI_TARGET, STAT_DEF, 0, Score_Minus10
AI_CBM_DefenseDown_SkipSubAndStatCheck:
	if_side_affecting AI_TARGET, SIDE_STATUS_MIST, Score_Minus10
	goto CheckIfAbilityBlocksStatChange

AI_CBM_SpeedDown: @ 82DC3A9
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_stat_level_equal AI_TARGET, STAT_SPEED, 0, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_MIST, Score_Minus10
	if_ability_might_be AI_TARGET, ABILITY_SPEED_BOOST, Score_Minus10
	if_move MOVE_COTTON_SPORE, AI_CBM_SpeedDown_Overcoat
	goto CheckIfAbilityBlocksStatChange
AI_CBM_SpeedDown_Overcoat:
	if_ability_might_be AI_TARGET, ABILITY_OVERCOAT, Score_Minus10
	goto CheckIfAbilityBlocksStatChange

AI_CBM_SpAtkDown: @ 82DC3BF
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_stat_level_equal AI_TARGET, STAT_SPATK, 0, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_MIST, Score_Minus10
	goto CheckIfAbilityBlocksStatChange

AI_CBM_SpDefDown: @ 82DC3CC
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_stat_level_equal AI_TARGET, STAT_SPDEF, 0, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_MIST, Score_Minus10
	goto CheckIfAbilityBlocksStatChange

AI_CBM_AccDown: @ 82DC3D9
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_stat_level_equal AI_TARGET, STAT_ACC, 0, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_MIST, Score_Minus10
    if_ability_might_be AI_TARGET, ABILITY_KEEN_EYE, Score_Minus10
    if_ability_might_be AI_TARGET, ABILITY_NO_GUARD, Score_Minus10
	goto CheckIfAbilityBlocksStatChange

AI_CBM_EvasionDown: @ 82DC3EE
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_stat_level_equal AI_TARGET, STAT_EVASION, 0, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_MIST, Score_Minus10
	goto CheckIfAbilityBlocksStatChange

CheckIfAbilityBlocksStatChange: @ 82DC3F6
    if_ability_might_be AI_TARGET, ABILITY_CLEAR_BODY, Score_Minus10
    if_ability_might_be AI_TARGET, ABILITY_WHITE_SMOKE, Score_Minus10
	end

AI_CBM_Haze: @ 82DC405
	if_stat_level_less_than AI_USER, STAT_ATK, 6, AI_CBM_Haze_End
	if_stat_level_less_than AI_USER, STAT_DEF, 6, AI_CBM_Haze_End
	if_stat_level_less_than AI_USER, STAT_SPEED, 6, AI_CBM_Haze_End
	if_stat_level_less_than AI_USER, STAT_SPATK, 6, AI_CBM_Haze_End
	if_stat_level_less_than AI_USER, STAT_SPDEF, 6, AI_CBM_Haze_End
	if_stat_level_less_than AI_USER, STAT_ACC, 6, AI_CBM_Haze_End
	if_stat_level_less_than AI_USER, STAT_EVASION, 6, AI_CBM_Haze_End
	if_stat_level_more_than AI_TARGET, STAT_ATK, 6, AI_CBM_Haze_End
	if_stat_level_more_than AI_TARGET, STAT_DEF, 6, AI_CBM_Haze_End
	if_stat_level_more_than AI_TARGET, STAT_SPEED, 6, AI_CBM_Haze_End
	if_stat_level_more_than AI_TARGET, STAT_SPATK, 6, AI_CBM_Haze_End
	if_stat_level_more_than AI_TARGET, STAT_SPDEF, 6, AI_CBM_Haze_End
	if_stat_level_more_than AI_TARGET, STAT_ACC, 6, AI_CBM_Haze_End
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 6, AI_CBM_Haze_End
	goto Score_Minus10

AI_CBM_Haze_End: @ 82DC47A
	end

AI_CBM_Roar: @ 82DC47B
	count_usable_party_mons AI_TARGET
	if_equal 0, Score_Minus10
    if_ability_might_be AI_TARGET, ABILITY_SUCTION_CUPS, Score_Minus10
	if_status3 AI_TARGET, STATUS3_ROOTED, Score_Minus10
	end

AI_CBM_Toxic: @ 82DC48C
	if_ability AI_USER, ABILITY_CORROSION, AI_CBM_Toxic_SkipTypeCheck
	if_type AI_TARGET, TYPE_STEEL, Score_Minus10
	if_type AI_TARGET, TYPE_POISON, Score_Minus10
AI_CBM_Toxic_SkipTypeCheck:
    if_ability_might_be AI_TARGET, ABILITY_IMMUNITY, Score_Minus10
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_target_expected_to_be_statused_assuming_equal_priority Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_SAFEGUARD, Score_Minus10
    if_effect EFFECT_TOXIC, AI_CBM_Toxic_SkipMarvelScaleCheck
    if_ability_might_be AI_TARGET, ABILITY_MARVEL_SCALE, Score_Minus8
AI_CBM_Toxic_SkipMarvelScaleCheck:
    if_ability_might_be AI_TARGET, ABILITY_GUTS, Score_Minus8
    if_ability_might_be AI_TARGET, ABILITY_TOXIC_BOOST, Score_Minus8
	if_ability_might_be AI_TARGET, ABILITY_SYNCHRONIZE, AI_CBM_Toxic_Synchronize
	if_move MOVE_POISON_POWDER, AI_CBM_PoisonPowder_OverCoat
AI_CBM_Toxic_End:
	end
AI_CBM_Toxic_Synchronize:
	if_ability AI_USER, ABILITY_GUTS, AI_CBM_Toxic_End
	if_ability AI_USER, ABILITY_TOXIC_BOOST, AI_CBM_Toxic_End
	if_ability AI_USER, ABILITY_MARVEL_SCALE, AI_CBM_Toxic_End
	if_ability AI_USER, ABILITY_IMMUNITY, AI_CBM_Toxic_End
	if_status AI_USER, STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_PARALYSIS, AI_CBM_Toxic_End
	if_might_heal_with_natural_cure AI_USER, AI_CBM_Toxic_End
	get_user_type1
	if_equal TYPE_STEEL, AI_CBM_Toxic_End
	if_equal TYPE_POISON, AI_CBM_Toxic_End
	get_user_type2
	if_equal TYPE_STEEL, AI_CBM_Toxic_End
	if_equal TYPE_POISON, AI_CBM_Toxic_End
	score -5
	end
AI_CBM_PoisonPowder_OverCoat:
	if_ability_might_be AI_TARGET, ABILITY_OVERCOAT, Score_Minus10
	end

AI_CBM_LightScreen: @ 82DC4C5
	if_side_affecting AI_USER, SIDE_STATUS_LIGHTSCREEN, Score_Minus8
	end

AI_CBM_OneHitKO: @ 82DC4D0
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
    if_ability_might_be AI_TARGET, ABILITY_STURDY, Score_Minus10
	if_level_cond AI_LEVEL_IS_LESS_THAN_TARGETS, Score_Minus10
    if_target_might_have_a_sub_before_our_attack Score_Minus5
	end

AI_CBM_Magnitude: @ 82DC4E5
    if_ability_might_be AI_TARGET, ABILITY_LEVITATE, Score_Minus10

AI_CBM_HighRiskForDamage: @ 82DC4ED
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	get_ability AI_TARGET
	if_not_equal ABILITY_WONDER_GUARD, AI_CBM_HighRiskForDamage_DiscourageAgainstOpponentsWithSub
	if_type_effectiveness AI_EFFECTIVENESS_x2, AI_CBM_HighRiskForDamage_DiscourageAgainstOpponentsWithSub
	if_type_effectiveness AI_EFFECTIVENESS_x4, AI_CBM_HighRiskForDamage_DiscourageAgainstOpponentsWithSub
	goto Score_Minus10

AI_CBM_HighRiskForDamage_DiscourageAgainstOpponentsWithSub:
	if_doesnt_have_move_with_effect AI_TARGET, EFFECT_SUBSTITUTE, AI_CBM_HighRiskForDamage_End
	if_effect EFFECT_COUNTER, AI_CBM_HighRiskForDamage_CheckHP2
	if_effect EFFECT_MIRROR_COAT, AI_CBM_HighRiskForDamage_CheckHP2
	if_effect EFFECT_RAZOR_WIND, AI_CBM_HighRiskForDamage_CheckHP2
	if_effect EFFECT_SKULL_BASH, AI_CBM_HighRiskForDamage_CheckHP2
	if_effect EFFECT_BIDE, AI_CBM_HighRiskForDamage_CheckHP2
	if_target_faster AI_CBM_HighRiskForDamage_CheckHP
	if_not_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_CBM_HighRiskForDamage_End
AI_CBM_HighRiskForDamage_CheckHP:
	if_hp_more_than AI_TARGET, 45, Score_Minus2
	if_user_faster AI_CBM_HighRiskForDamage_End
	if_not_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_CBM_HighRiskForDamage_End
AI_CBM_HighRiskForDamage_CheckHP2:
	if_hp_more_than AI_TARGET, 24, Score_Minus2
AI_CBM_HighRiskForDamage_End: @ 82DC506
	end

AI_CBM_Mist: @ 82DC507
	if_side_affecting AI_USER, SIDE_STATUS_MIST, Score_Minus8
	if_this_attack_might_be_the_last Score_Minus5
	end

AI_CBM_FocusEnergy: @ 82DC512
	if_status2 AI_USER, STATUS2_FOCUS_ENERGY, Score_Minus10
	if_perish_song_about_to_trigger AI_USER, Score_Minus10
	if_user_cannot_attack_and_no_pass_is_available Score_Minus10
	if_this_attack_might_be_the_last Score_Minus5
	end

AI_CBM_Confuse: @ 82DC51D
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_ability_might_be AI_TARGET, ABILITY_OWN_TEMPO, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_SAFEGUARD, Score_Minus10
	if_status2 AI_TARGET, STATUS2_CONFUSION, Score_Minus5
	end

AI_CBM_Reflect: @ 82DC53A
	if_side_affecting AI_USER, SIDE_STATUS_REFLECT, Score_Minus8
	end

AI_CBM_Paralyze: @ 82DC545
	if_move MOVE_GLARE, AI_CBM_Paralyze_SkipEffectiveness
    if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
AI_CBM_Paralyze_SkipEffectiveness:
	if_ability_might_be AI_TARGET, ABILITY_LIMBER, Score_Minus10
    if_target_expected_to_be_statused_assuming_equal_priority Score_Minus10
	if_target_might_have_a_sub_before_our_attack Score_Minus10
    if_side_affecting AI_TARGET, SIDE_STATUS_SAFEGUARD, Score_Minus10
    if_move MOVE_THUNDER_WAVE, AI_CBM_Paralyze_ThunderWave
    if_move MOVE_STUN_SPORE, AI_CBM_Paralyze_OverCoat
AI_CBM_Paralyze_SynchronizeCheck:
    if_ability_might_be AI_TARGET, ABILITY_SYNCHRONIZE, AI_CBM_Paralyze_Synchronize
AI_CBM_Paralyze2:
    if_ability_might_be AI_TARGET, ABILITY_MARVEL_SCALE, Score_Minus8
    if_ability_might_be AI_TARGET, ABILITY_GUTS, Score_Minus2
    end
    
AI_CBM_Paralyze_ThunderWave:
	if_ability_might_be AI_TARGET, ABILITY_MOTOR_DRIVE, Score_Minus10
	if_ability_might_be AI_TARGET, ABILITY_LIGHTNING_ROD, Score_Minus10
	if_ability_might_be AI_TARGET, ABILITY_VOLT_ABSORB, Score_Minus10
    goto AI_CBM_Paralyze_SynchronizeCheck
AI_CBM_Paralyze_OverCoat:
	if_ability_might_be AI_TARGET, ABILITY_OVERCOAT, Score_Minus10
    goto AI_CBM_Paralyze_SynchronizeCheck
AI_CBM_Paralyze_Synchronize:
	if_ability AI_USER, ABILITY_GUTS, AI_CBM_Paralyze2
	if_ability AI_USER, ABILITY_MARVEL_SCALE, AI_CBM_Paralyze2
	if_ability AI_USER, ABILITY_LIMBER, AI_CBM_Paralyze2
	if_status AI_USER, STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_PARALYSIS, AI_CBM_Paralyze2
	if_might_heal_with_natural_cure AI_USER, AI_CBM_Paralyze2
	score -5
    goto AI_CBM_Paralyze2

AI_CBM_Substitute: @ 82DC568
    if_hp_condition USER_CANNOT_USE_SUB, Score_Minus10
    if_status2 AI_USER, STATUS2_SUBSTITUTE, Score_Minus8
    if_perish_song_about_to_trigger AI_USER, Score_Minus8
    if_next_turn_target_might_use_move_with_effect EFFECT_ROAR, AI_CBM_Minus8IfAICanBePhazed
    end

AI_CBM_Minus8IfAICanBePhazed:
    count_usable_party_mons AI_USER
    if_equal 0, AI_Ret
    if_ability AI_USER, ABILITY_SUCTION_CUPS, AI_Ret
    if_status3 AI_USER, STATUS3_ROOTED, AI_Ret
    goto Score_Minus8

AI_CBM_LeechSeed: @ 82DC57A
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_status3 AI_TARGET, STATUS3_LEECHSEED, Score_Minus10
	if_type AI_TARGET, TYPE_GRASS, Score_Minus10
	if_ability_might_be AI_TARGET, ABILITY_LIQUID_OOZE, Score_Minus8
	end

AI_CBM_Disable: @ 82DC595
	if_any_move_disabled AI_TARGET, Score_Minus8
	end

AI_CBM_Encore: @ 82DC59D
	if_any_move_encored AI_TARGET, Score_Minus8
	end

AI_CBM_DamageDuringSleep: @ 82DC5A5
	if_not_expected_to_sleep Score_Minus8
	end

AI_CBM_CantEscape: @ 82DC5B0
  if_type AI_TARGET, TYPE_GHOST, Score_Minus10
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_status2 AI_TARGET, STATUS2_ESCAPE_PREVENTION, Score_Minus10
    count_usable_party_mons AI_TARGET
    if_equal 0, Score_Minus10
	if_perish_song_about_to_trigger AI_USER, Score_Minus10
	end

AI_CBM_Curse: @ 82DC5BB
	if_type AI_USER, TYPE_GHOST, AI_CBM_Curse_Ghost
	goto AI_CBM_BulkUp

AI_CBM_Curse_Ghost:
	if_hp_condition USER_CANNOT_USE_BELLY_DRUM, AI_CBM_Curse_Ghost_UserWillFaint
AI_CBM_Curse_End:
	end

AI_CBM_Curse_Ghost_UserWillFaint:
	count_usable_party_mons AI_USER
	if_equal 0, Score_Minus10
	goto AI_CBM_Curse_End

AI_CBM_Spikes: @ 82DC5CC
	count_usable_party_mons AI_TARGET
	if_equal 0, Score_Minus10
	if_not_side_affecting AI_TARGET, SIDE_STATUS_SPIKES, AI_Ret
	get_hazards_count AI_TARGET, EFFECT_SPIKES
	if_equal 3, Score_Minus10
	end

AI_CBM_Foresight: @ 82DC5D7
	if_status2 AI_TARGET, STATUS2_FORESIGHT, Score_Minus10
	if_perish_song_about_to_trigger AI_USER, Score_Minus10
	end

AI_CBM_PerishSong: @ 82DC5E2
	if_status3 AI_TARGET, STATUS3_PERISH_SONG, Score_Minus10
	count_usable_party_mons AI_TARGET
	if_equal 0, Score_Plus2
	count_usable_party_mons AI_USER
	if_equal 0, Score_Minus10
AI_CBM_PerishSong_IgnoreNumberOfMons:
	if_stat_level_more_than AI_TARGET, STAT_ATK, 7, AI_CBM_PerishSong_EncouragePhazing
	if_stat_level_more_than AI_TARGET, STAT_DEF, 8, AI_CBM_PerishSong_EncouragePhazing
	if_stat_level_more_than AI_TARGET, STAT_SPATK, 7, AI_CBM_PerishSong_EncouragePhazing
	if_stat_level_more_than AI_TARGET, STAT_SPDEF, 8, AI_CBM_PerishSong_EncouragePhazing
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 8, AI_CBM_PerishSong_EncouragePhazing
	if_stat_level_more_than AI_TARGET, STAT_ATK, 6, AI_CBM_PerishSong_CheckSpeedForPossibleDragonDance
	if_stat_level_more_than AI_TARGET, STAT_DEF, 7, AI_CBM_PerishSong_ConsiderPhazing
	if_stat_level_more_than AI_TARGET, STAT_SPATK, 6, AI_CBM_PerishSong_ConsiderPhazing
	if_stat_level_more_than AI_TARGET, STAT_SPDEF, 7, AI_CBM_PerishSong_ConsiderPhazing
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 7, AI_CBM_PerishSong_ConsiderPhazing
AI_CBM_PerishSong_SkipPhazing:
    if_ability_might_be AI_TARGET, ABILITY_SHED_SKIN, AI_CBM_PerishSong_SkipPenaltyToStatusedMon
    if_has_move_with_effect AI_TARGET, EFFECT_REST, AI_CBM_PerishSong_SkipPenaltyToStatusedMon
    if_has_move_with_effect AI_TARGET, EFFECT_REFRESH, AI_CBM_PerishSong_SkipPenaltyToStatusedMon
    if_has_move_with_effect AI_TARGET, EFFECT_BATON_PASS, AI_CBM_PerishSong_SkipPenaltyToStatusedMon
    if_status AI_TARGET, STATUS1_TOXIC_POISON, Score_Minus3
    if_status2 AI_TARGET, STATUS2_CURSED, Score_Minus3
AI_CBM_PerishSong_SkipPenaltyToStatusedMon:
    if_type AI_TARGET, TYPE_GHOST, AI_CBM_PerishSong_DefaultPenalty
    if_status3 AI_TARGET, STATUS3_ROOTED, Score_Plus2
    if_status2 AI_TARGET, STATUS2_ESCAPE_PREVENTION | 0x8000, Score_Plus2 @ con 0x8000 se determina si quedan al menos 4 turnos de Wrap y similares
    if_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_CBM_PerishSong_DefaultPenalty
    if_has_move_with_effect AI_USER, EFFECT_MEAN_LOOK, Score_Minus3
    if_has_move_with_effect AI_USER, EFFECT_TRAP, Score_Minus3
AI_CBM_PerishSong_DefaultPenalty:
	score -1
	if_random_less_than 55, AI_CBM_PerishSong_End
	score -1
AI_CBM_PerishSong_End:
	end

AI_CBM_PerishSong_CheckSpeedForPossibleDragonDance:
	if_stat_level_more_than AI_TARGET, STAT_SPEED, 6, AI_CBM_PerishSong_EncouragePhazing
AI_CBM_PerishSong_ConsiderPhazing:
	if_has_move_with_effect AI_TARGET, EFFECT_BATON_PASS, AI_CBM_PerishSong_EncouragePhazing
	if_random_less_than 128, AI_CBM_PerishSong_SkipPhazing
AI_CBM_PerishSong_EncouragePhazing:
	score +1
	goto AI_CBM_PerishSong_End

AI_CBM_Sandstorm: @ 82DC5ED
	get_weather
	if_equal AI_WEATHER_SANDSTORM, Score_Minus8
	end

AI_CBM_Attract: @ 82DC5F5
	if_status2 AI_TARGET, STATUS2_INFATUATION, Score_Minus10
	if_ability_might_be AI_TARGET, ABILITY_OBLIVIOUS, Score_Minus10
	get_gender AI_USER
	if_equal 0, AI_CBM_Attract_CheckIfTargetIsFemale
	if_equal 254, AI_CBM_Attract_CheckIfTargetIsMale
	goto Score_Minus10

AI_CBM_Attract_CheckIfTargetIsFemale: @ 82DC61A
	get_gender AI_TARGET
	if_equal 254, AI_CBM_Attract_OppositeGenders
	goto Score_Minus10

AI_CBM_Attract_CheckIfTargetIsMale: @ 82DC627
	get_gender AI_TARGET
	if_equal 0, AI_CBM_Attract_OppositeGenders
	goto Score_Minus10

AI_CBM_Attract_OppositeGenders:
	if_user_is_intoxicated_and_does_not_have_baton_pass Score_Minus5
	if_status2 AI_USER, STATUS2_CURSED, Score_Minus5
	if_status3 AI_USER, STATUS3_PERISH_SONG, Score_Minus5
AI_CBM_Attract_End:
	end

AI_CBM_Safeguard: @ 82DC635
	if_side_affecting AI_USER, SIDE_STATUS_SAFEGUARD, Score_Minus8
	end

AI_CBM_Memento: @ 82DC640
	count_usable_party_mons AI_USER
	if_equal 0, Score_Minus12
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_stat_level_equal AI_TARGET, STAT_ATK, 0, Score_Minus10
	if_stat_level_equal AI_TARGET, STAT_SPATK, 0, Score_Minus8
	goto CheckIfAbilityBlocksStatChange

AI_CBM_BatonPass: @ 82DC650
	count_usable_party_mons AI_USER
	if_equal 0, Score_Minus10
	end

AI_CBM_RainDance: @ 82DC659
	get_weather
	if_equal AI_WEATHER_RAIN, Score_Minus8
	end

AI_CBM_SunnyDay: @ 82DC661
	get_weather
	if_equal AI_WEATHER_SUN, Score_Minus8
	end

AI_CBM_FutureSight: @ 82DC669
	if_side_affecting AI_TARGET, SIDE_STATUS_FUTUREATTACK, Score_Minus12
	if_side_affecting AI_USER, SIDE_STATUS_FUTUREATTACK, Score_Minus12
	score -1
	end

AI_CBM_FakeOut: @ 82DC680
	is_first_turn_for AI_USER
	if_equal 0, Score_Minus10
	end

AI_CBM_Stockpile: @ 82DC689
	get_stockpile_count AI_USER
	if_equal 3, Score_Minus10
	end

AI_CBM_SpitUpAndSwallow: @ 82DC692
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	get_stockpile_count AI_USER
	if_equal 0, Score_Minus10
	end

AI_CBM_Hail: @ 82DC6A1
	get_weather
	if_equal AI_WEATHER_HAIL, Score_Minus8
	end

AI_CBM_Torment: @ 82DC6A9
	if_status2 AI_TARGET, STATUS2_TORMENT, Score_Minus10
	if_ability AI_TARGET, ABILITY_TRUANT, Score_Minus8
	end

AI_CBM_WillOWisp: @ 82DC6B4
    if_ability_might_be AI_TARGET, ABILITY_FLASH_FIRE, Score_Minus10
    if_ability_might_be AI_TARGET, ABILITY_WATER_VEIL, Score_Minus10
	if_target_expected_to_be_statused_assuming_equal_priority Score_Minus10
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_type AI_TARGET, TYPE_FIRE, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_SAFEGUARD, Score_Minus10
    if_ability_might_be AI_TARGET, ABILITY_MARVEL_SCALE, Score_Minus8
    if_ability_might_be AI_TARGET, ABILITY_GUTS, Score_Minus8
	if_ability_might_be AI_TARGET, ABILITY_SYNCHRONIZE, WillOWisp_Synchronize
AI_CBM_WillOWisp_End:
	end
WillOWisp_Synchronize:
	if_ability AI_USER, ABILITY_GUTS, AI_CBM_WillOWisp_End
	if_ability AI_USER, ABILITY_MARVEL_SCALE, AI_CBM_WillOWisp_End
	if_ability AI_USER, ABILITY_WATER_VEIL, AI_CBM_WillOWisp_End
	if_status AI_USER, STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_PARALYSIS, AI_CBM_WillOWisp_End
	if_might_heal_with_natural_cure AI_USER, AI_CBM_WillOWisp_End
	get_user_type1
    if_equal TYPE_FIRE, AI_CBM_WillOWisp_End
    get_user_type2
    if_equal TYPE_FIRE, AI_CBM_WillOWisp_End
	score -5
	end

AI_CBM_HelpingHand: @ 82DC6E3
	if_not_double_battle Score_Minus10
	if_battler_absent AI_USER_PARTNER, Score_Minus10
	end

AI_CBM_Trick: @ 82DC6EB
	if_trick_fails_in_this_type_of_battle Score_Minus10
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_ability_might_be AI_TARGET, ABILITY_STICKY_HOLD, Score_Minus10
	is_first_turn_for AI_USER
	if_equal 0, Score_Minus8
	end

AI_CBM_Ingrain: @ 82DC6F4
	if_status3 AI_USER, STATUS3_ROOTED, Score_Minus10
	if_user_is_intoxicated_and_does_not_have_baton_pass Score_Minus8
	if_status2 AI_USER, STATUS2_CURSED, Score_Minus8
	if_status3 AI_USER, STATUS3_PERISH_SONG, Score_Minus8
	if_this_attack_might_be_the_last Score_Minus5
	end

AI_CBM_Recycle: @ 82DC6FF
	if_holds_item AI_USER, ITEM_NONE, AI_CBM_Recycle_HasNoItem
	goto Score_Minus10
AI_CBM_Recycle_HasNoItem:
	get_used_held_item AI_USER
	if_equal 0, Score_Minus10
	end

AI_CBM_Imprison: @ 82DC708
	if_status3 AI_USER, STATUS3_IMPRISONED_OTHERS, Score_Minus10
	end

AI_CBM_Refresh: @ 82DC713
	if_not_status AI_USER, STATUS1_POISON | STATUS1_BURN | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON, Score_Minus10
	end

AI_CBM_MudSport: @ 82DC71E
	if_status3 AI_USER, STATUS3_MUDSPORT, Score_Minus10
	end

AI_CBM_Tickle: @ 82DC729
	if_stat_level_equal AI_TARGET, STAT_DEF, 0, AI_CBM_AttackDown_SkipSub
	goto AI_CBM_DefenseDown_SkipSubAndStatCheck

AI_CBM_CosmicPower: @ 82DC73A
	if_stat_level_equal AI_USER, STAT_DEF, 12, AI_CBM_SpDefUp
	goto AI_CBM_DefenseOrEvasion_CheckIfOpponentCanPhaze

AI_CBM_BulkUp: @ 82DC74B
	if_stat_level_equal AI_USER, STAT_ATK, 12, AI_CBM_DefenseUp
	if_perish_song_about_to_trigger AI_USER, AI_CBM_DefenseUp
	if_user_cannot_attack_and_no_pass_is_available AI_CBM_DefenseUp
	end

AI_CBM_WaterSport: @ 82DC75C
	if_status3 AI_USER, STATUS3_WATERSPORT, Score_Minus10
	end

AI_CBM_CalmMind: @ 82DC767
	if_stat_level_equal AI_USER, STAT_SPATK, 12, AI_CBM_SpDefUp
	if_perish_song_about_to_trigger AI_USER, AI_CBM_SpDefUp
	if_user_cannot_attack_and_no_pass_is_available AI_CBM_SpDefUp
	end

AI_CBM_DragonDance: @ 82DC778
	if_stat_level_equal AI_USER, STAT_SPEED, 12, AI_CBM_AttackUp
	end
	
AI_CBM_QuiverDance:
	if_stat_level_equal AI_USER, STAT_SPEED, 12, AI_CBM_CalmMind
	end
	
AI_CBM_LockOn:
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_status3 AI_TARGET, STATUS3_ALWAYS_HITS, Score_Minus10
	if_ability_might_be AI_TARGET, ABILITY_NO_GUARD, Score_Minus10
	if_ability AI_USER, ABILITY_NO_GUARD, Score_Minus10
	if_perish_song_about_to_trigger AI_USER, Score_Minus10
	end

AI_CBM_HealBell:
	if_move MOVE_HEAL_BELL, AI_CBM_HealBell2
AI_CBM_HealBellEnd:
	end
@ Don't use Heal Bell to heal a partner that has Soundproof
AI_CBM_HealBell2:
	if_status AI_USER, STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_PARALYSIS, AI_CBM_HealBellEnd
	if_not_status AI_USER_PARTNER, STATUS1_ANY, AI_CBM_HealBellEnd
	if_ability AI_USER_PARTNER, ABILITY_SOUNDPROOF, Score_Minus3
	goto AI_CBM_HealBellEnd

AI_CBM_Taunt:
	if_ability_might_be AI_TARGET, ABILITY_OBLIVIOUS, Score_Minus10
	if_target_taunted Score_Minus10
	get_possible_categories_of_foes_attacks
	if_equal AI_NO_DAMAGING_MOVES, Score_Plus2
	if_this_attack_might_be_the_last Score_Minus3
	calculate_nhko AI_TARGET
	if_less_than 3, Score_Minus1
	is_first_turn_for AI_USER
	if_equal 1, AI_CBM_TauntIfFaster
	goto AI_CBM_Taunt_End
AI_CBM_TauntIfFaster:
	if_user_faster Score_Plus1
AI_CBM_Taunt_End:
	end
	
AI_CBM_Protect:
	get_protect_count AI_USER
	if_more_than 2, Score_Minus10
	if_target_wont_attack_due_to_truant Score_Minus10
	if_status AI_TARGET, STATUS1_FREEZE, Score_Minus8
	if_target_not_expected_to_sleep_during_next_turn AI_CBM_Protect_End
	if_next_turn_target_might_use_move_with_effect EFFECT_SLEEP_TALK, Score_Minus3
	score -5
AI_CBM_Protect_End:
	end
	
AI_CBM_Coil:
	if_stat_level_equal AI_USER, STAT_ACC, 12, AI_CBM_BulkUp
	end
	
AI_CBM_Mimic:
    if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_this_attack_might_be_the_last Score_Minus5
	end
	
AI_CBM_Wish:
	if_receiving_wish AI_USER, Score_Minus10
	end
	
AI_CBM_FollowMe:
	if_not_double_battle Score_Minus10
	if_battler_absent AI_USER_PARTNER, Score_Minus10
	end
	
AI_CBM_JumpKickMiss:
    if_next_turn_target_might_use_move_with_effect EFFECT_PROTECT, AI_CBM_JumpKick_TargetHasProtect
	end
AI_CBM_JumpKick_TargetHasProtect:
	get_protect_count AI_TARGET
    if_more_than 1, AI_CBM_JumpKick_End
    if_more_than 0, AI_CBM_JumpKick_ProtectedOnce
    if_random_less_than 128, Score_Minus10
	score -3
AI_CBM_JumpKick_End:
    end
AI_CBM_JumpKick_ProtectedOnce:
	if_random_less_than 128, Score_Minus3
    goto AI_CBM_JumpKick_End

AI_UselessEffectsWhenChoiced:
    .byte EFFECT_ATTACK_UP
    .byte EFFECT_DEFENSE_UP
    .byte EFFECT_SPEED_UP
    .byte EFFECT_SPECIAL_ATTACK_UP
    .byte EFFECT_SPECIAL_DEFENSE_UP
    .byte EFFECT_ACCURACY_UP
    .byte EFFECT_EVASION_UP
    .byte EFFECT_CONVERSION
    .byte EFFECT_FOCUS_ENERGY
    .byte EFFECT_ATTACK_UP_2
    .byte EFFECT_DEFENSE_UP_2
    .byte EFFECT_SPEED_UP_2
    .byte EFFECT_SPECIAL_ATTACK_UP_2
    .byte EFFECT_SPECIAL_DEFENSE_UP_2
    .byte EFFECT_ACCURACY_UP_2
    .byte EFFECT_EVASION_UP_2
    .byte EFFECT_SUBSTITUTE
    .byte EFFECT_MINIMIZE
    .byte EFFECT_DEFENSE_CURL
    .byte EFFECT_INGRAIN
    .byte EFFECT_IMPRISON
    .byte EFFECT_COSMIC_POWER
    .byte EFFECT_BULK_UP
    .byte EFFECT_CALM_MIND
    .byte EFFECT_CAMOUFLAGE
    .byte EFFECT_QUIVER_DANCE
    .byte EFFECT_COIL
    .byte EFFECT_STOCKPILE
    .byte EFFECT_DRAGON_DANCE
    .byte EFFECT_ATTACK_SPATK_UP
    .byte EFFECT_SPECIAL_ATTACK_UP_3
    .byte EFFECT_CHARGE
    .byte EFFECT_LOCK_ON
    .byte EFFECT_BELLY_DRUM
    .byte EFFECT_ATTRACT
    .byte -1
	
@ If move doesn't do meaningful damage, switch out
AI_ChoiceDamage:
    if_move_is_useless_when_choiced Score_Minus12
	get_considered_move_power
	if_equal 0, Score_Minus5
AI_ChoiceDamage_CalculateNHKO:
	if_effect EFFECT_OHKO, AI_ChoiceDamage_End
    calculate_nhko
    if_less_than 3, AI_ChoiceDamage_End
    if_equal 3, AI_ChoiceDamage_3HKO
    if_equal 4, AI_ChoiceDamage_4HKO
    goto Score_Minus8

AI_ChoiceDamage_3HKO:
    if_has_a_50_percent_hp_recovery_move AI_TARGET, Score_Minus8
    if_target_will_be_faster_after_this_effect Score_Minus5
    goto AI_ChoiceDamage_End

AI_ChoiceDamage_4HKO:
    if_has_a_50_percent_hp_recovery_move AI_TARGET, Score_Minus8
    if_has_move_with_effect AI_TARGET, EFFECT_REST, Score_Minus8
    if_target_will_be_faster_after_this_effect Score_Minus8
    goto Score_Minus5
AI_ChoiceDamage_End:
	end

Score_Minus1:
	score -1
	end

Score_Minus2:
	score -2
	end

Score_Minus3:
	score -3
	end

Score_Minus5:
	score -5
	end

Score_Minus8:
	score -8
	end

Score_Minus10:
	score -10
	end

Score_Minus12:
	score -12
	end

Score_Minus30:
	score -30
	end

Score_Plus1:
	score +1
	end

Score_Plus2:
	score +2
	end

Score_Plus3:
	score +3
	end
	
Score_Plus4:
	score +4
	end

Score_Plus5:
	score +5
	end

Score_Plus10:
	score +10
	end

AI_CheckViability:
	if_target_is_ally AI_Ret
    if_user_choiced AI_CheckViability_CallChoiceDamage
    goto AI_CheckViability_CheckEffects
AI_CheckViability_CallChoiceDamage:
    call AI_ChoiceDamage
AI_CheckViability_CheckEffects:
	if_effect EFFECT_SLEEP, AI_CV_Sleep
	if_effect EFFECT_ABSORB, AI_CV_Absorb
	if_effect EFFECT_EXPLOSION, AI_CV_Explosion
	if_effect EFFECT_DREAM_EATER, AI_CV_DreamEater
	if_effect EFFECT_MIRROR_MOVE, AI_CV_MirrorMove
	if_effect EFFECT_ATTACK_UP, AI_CV_AttackUp_NotSwordsDance
	if_effect EFFECT_DEFENSE_UP, AI_CV_DefenseUp
	if_effect EFFECT_SPEED_UP, AI_CV_SpeedUp
	if_effect EFFECT_SPECIAL_ATTACK_UP, AI_CV_SpAtkUp_NotNastyPlotOrTailGlow
	if_effect EFFECT_SPECIAL_DEFENSE_UP, AI_CV_SpDefUp
	if_effect EFFECT_ACCURACY_UP, AI_CV_AccuracyUp
	if_effect EFFECT_EVASION_UP, AI_CV_EvasionUp
	if_effect EFFECT_ALWAYS_HIT, AI_CV_AlwaysHit
	if_effect EFFECT_ATTACK_DOWN, AI_CV_AttackDown
	if_effect EFFECT_DEFENSE_DOWN, AI_CV_DefenseDown
	if_effect EFFECT_SPEED_DOWN, AI_CV_SpeedDown
	if_effect EFFECT_SPECIAL_ATTACK_DOWN, AI_CV_SpAtkDown
	if_effect EFFECT_SPECIAL_DEFENSE_DOWN, AI_CV_SpDefDown
	if_effect EFFECT_ACCURACY_DOWN, AI_CV_AccuracyDown
	if_effect EFFECT_EVASION_DOWN, AI_CV_EvasionDown
	if_effect EFFECT_HAZE, AI_CV_Haze
	if_effect EFFECT_BIDE, AI_CV_Bide
	if_effect EFFECT_ROAR, AI_CV_Roar
	if_effect EFFECT_CONVERSION, AI_CV_Conversion
	if_effect EFFECT_RESTORE_HP, AI_CV_Heal
	if_effect EFFECT_TOXIC, AI_CV_Toxic
	if_effect EFFECT_LIGHT_SCREEN, AI_CV_LightScreen
	if_effect EFFECT_REST, AI_CV_Rest
	if_effect EFFECT_OHKO, AI_CV_OneHitKO
	if_effect EFFECT_RAZOR_WIND, AI_CV_ChargeUpMove
	if_effect EFFECT_TRAP, AI_CV_PartialTrap
	if_effect EFFECT_CONFUSE, AI_CV_Confuse
	if_effect EFFECT_ATTACK_UP_2, AI_CV_SwordsDance
	if_effect EFFECT_DEFENSE_UP_2, AI_CV_DefenseUp
	if_effect EFFECT_SPEED_UP_2, AI_CV_SpeedUp
	if_effect EFFECT_SPECIAL_ATTACK_UP_2, AI_CV_SpAtkUpNPTG
	if_effect EFFECT_SPECIAL_ATTACK_UP_3, AI_CV_SpAtkUpNPTG
	if_effect EFFECT_ATTACK_SPATK_UP, AI_CV_Growth
	if_effect EFFECT_SPECIAL_DEFENSE_UP_2, AI_CV_SpDefUp
	if_effect EFFECT_ACCURACY_UP_2, AI_CV_AccuracyUp
	if_effect EFFECT_EVASION_UP_2, AI_CV_EvasionUp
	if_effect EFFECT_ATTACK_DOWN_2, AI_CV_AttackDown
	if_effect EFFECT_DEFENSE_DOWN_2, AI_CV_DefenseDown
	if_effect EFFECT_SPEED_DOWN_2, AI_CV_SpeedDown
	if_effect EFFECT_SPECIAL_ATTACK_DOWN_2, AI_CV_SpAtkDown
	if_effect EFFECT_SPECIAL_DEFENSE_DOWN_2, AI_CV_SpDefDown
	if_effect EFFECT_ACCURACY_DOWN_2, AI_CV_AccuracyDown
	if_effect EFFECT_EVASION_DOWN_2, AI_CV_EvasionDown
	if_effect EFFECT_REFLECT, AI_CV_Reflect
	if_effect EFFECT_POISON, AI_CV_Poison
	if_effect EFFECT_PARALYZE, AI_CV_Paralyze
	if_effect EFFECT_SWAGGER, AI_CV_Swagger
	if_effect EFFECT_SPEED_DOWN_HIT, AI_CV_SpeedDownFromChance
	if_effect EFFECT_SKY_ATTACK, AI_CV_ChargeUpMove
	if_effect EFFECT_VITAL_THROW, AI_CV_VitalThrow
	if_effect EFFECT_SUBSTITUTE, AI_CV_Substitute
	if_effect EFFECT_RECHARGE, AI_CV_Recharge
	if_effect EFFECT_LEECH_SEED, AI_CV_Toxic
	if_effect EFFECT_DISABLE, AI_CV_Disable
	if_effect EFFECT_COUNTER, AI_CV_Counter
	if_effect EFFECT_ENCORE, AI_CV_Encore
	if_effect EFFECT_PAIN_SPLIT, AI_CV_PainSplit
	if_effect EFFECT_SNORE, AI_CV_Snore
	if_effect EFFECT_LOCK_ON, AI_CV_LockOn
	if_effect EFFECT_SLEEP_TALK, AI_CV_SleepTalk
	if_effect EFFECT_DESTINY_BOND, AI_CV_DestinyBond
	if_effect EFFECT_GRUDGE, AI_CV_Grudge
	if_effect EFFECT_FLAIL, AI_CV_Flail
	if_effect EFFECT_HEAL_BELL, AI_CV_HealBell
	if_effect EFFECT_THIEF, AI_CV_Thief
	if_effect EFFECT_MEAN_LOOK, AI_CV_Trap
	if_effect EFFECT_MINIMIZE, AI_CV_EvasionUp
	if_effect EFFECT_CURSE, AI_CV_Curse
	if_effect EFFECT_PROTECT, AI_CV_Protect
	if_effect EFFECT_SPIKES, AI_CV_Spikes
	if_effect EFFECT_FORESIGHT, AI_CV_Foresight
	if_effect EFFECT_ENDURE, AI_CV_Endure
	if_effect EFFECT_BATON_PASS, AI_CV_BatonPass
	if_effect EFFECT_PURSUIT, AI_CV_Pursuit
	if_effect EFFECT_MORNING_SUN, AI_CV_HealWeather
	if_effect EFFECT_SYNTHESIS, AI_CV_HealWeather
	if_effect EFFECT_MOONLIGHT, AI_CV_HealWeather
	if_effect EFFECT_SHORE_UP, AI_CV_Heal
	if_effect EFFECT_RAIN_DANCE, AI_CV_RainDance
	if_effect EFFECT_SUNNY_DAY, AI_CV_SunnyDay
	if_effect EFFECT_BELLY_DRUM, AI_CV_BellyDrum
	if_effect EFFECT_PSYCH_UP, AI_CV_PsychUp
	if_effect EFFECT_MIRROR_COAT, AI_CV_MirrorCoat
	if_effect EFFECT_SKULL_BASH, AI_CV_ChargeUpMove
	if_effect EFFECT_SOLARBEAM, AI_CV_ChargeUpMove
	if_effect EFFECT_SEMI_INVULNERABLE, AI_CV_SemiInvulnerable
	if_effect EFFECT_SOFTBOILED, AI_CV_Heal
	if_effect EFFECT_FAKE_OUT, AI_CV_FakeOut
	if_effect EFFECT_SPIT_UP, AI_CV_SpitUp
	if_effect EFFECT_SWALLOW, AI_CV_Heal
	if_effect EFFECT_HAIL, AI_CV_Hail
	if_effect EFFECT_FLATTER, AI_CV_Flatter
	if_effect EFFECT_MEMENTO, AI_CV_SelfKO
	if_effect EFFECT_FOCUS_PUNCH, AI_CV_FocusPunch
	if_effect EFFECT_SMELLINGSALT, AI_CV_SmellingSalt
	if_effect EFFECT_TRICK, AI_CV_Trick
	if_effect EFFECT_ROLE_PLAY, AI_CV_ChangeSelfAbility
	if_effect EFFECT_SUPERPOWER, AI_CV_Superpower
	if_effect EFFECT_MAGIC_COAT, AI_CV_MagicCoat
	if_effect EFFECT_RECYCLE, AI_CV_Recycle
	if_effect EFFECT_REVENGE, AI_CV_Revenge
	if_effect EFFECT_BRICK_BREAK, AI_CV_BrickBreak
	if_effect EFFECT_KNOCK_OFF, AI_CV_KnockOff
	if_effect EFFECT_ENDEAVOR, AI_CV_Endeavor
	if_effect EFFECT_ERUPTION, AI_CV_Eruption
	if_effect EFFECT_SKILL_SWAP, AI_CV_ChangeSelfAbility
	if_effect EFFECT_IMPRISON, AI_CV_Imprison
	if_effect EFFECT_REFRESH, AI_CV_Refresh
	if_effect EFFECT_SNATCH, AI_CV_Snatch
	if_effect EFFECT_MUD_SPORT, AI_CV_MudSport
	if_effect EFFECT_OVERHEAT, AI_CV_Overheat
	if_effect EFFECT_TICKLE, AI_CV_DefenseDown
	if_effect EFFECT_COSMIC_POWER, AI_CV_CosmicPower
	if_effect EFFECT_BULK_UP, AI_CV_AttackUp_NotSwordsDance
	if_effect EFFECT_WATER_SPORT, AI_CV_WaterSport
	if_effect EFFECT_CALM_MIND, AI_CV_SpAtkUp_NotNastyPlotOrTailGlow
	if_effect EFFECT_DRAGON_DANCE, AI_CV_DragonDance
	if_effect EFFECT_SANDSTORM, AI_CV_Sandstorm
	if_effect EFFECT_QUICK_ATTACK, AI_CV_QuickAttack @ para FEAR, incluye ExtremeSpeed y Mach Punch
	if_effect EFFECT_WILL_O_WISP, AI_CV_WillOWisp
	if_effect EFFECT_WISH, AI_CV_Wish
	if_effect EFFECT_RAPID_SPIN, AI_CV_RapidSpin
	if_effect EFFECT_ROLLOUT, AI_CV_Rollout
	if_effect EFFECT_COIL, AI_CV_AttackUp_NotSwordsDance
	if_effect EFFECT_QUIVER_DANCE, AI_CV_SpAtkUp_NotNastyPlotOrTailGlow
	if_effect EFFECT_STOCKPILE, AI_CV_CosmicPower
	if_effect EFFECT_SPITE, AI_CV_Spite
	end

AI_CV_Sleep: @ 82DCA92
	if_accuracy_less_than 97, AI_CV_SleepSkipBonusToSpore @ o Sleep Powder (75 acc) + Compoundeyes
	if_user_faster AI_CV_SleepPlus1or2
AI_CV_SleepSkipBonusToSpore:
	if_has_move_with_effect AI_USER, EFFECT_DREAM_EATER, AI_CV_SleepEncourageSlpDamage
	if_has_move_with_effect AI_USER, EFFECT_NIGHTMARE, AI_CV_SleepEncourageSlpDamage
	goto AI_CV_Sleep_End

AI_CV_SleepPlus1or2:
	score +1
	if_free_setup_turn AI_CV_SleepPlus1
AI_CV_SleepEncourageSlpDamage: @ 82DCAA5
	if_random_less_than 128, AI_CV_Sleep_End
AI_CV_SleepPlus1:
	score +1
AI_CV_Sleep_End: @ 82DCAAD
	end

AI_CV_Absorb: @ 82DCAAE
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, AI_CV_AbsorbEncourageMaybe
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, AI_CV_AbsorbEncourageMaybe
	goto AI_CV_Absorb_End

AI_CV_AbsorbEncourageMaybe: @ 82DCABF
	if_random_less_than 50, AI_CV_Absorb_End
	score -3

AI_CV_Absorb_End: @ 82DCAC7
	end
	
@ Si el usuario (que no puede cambiar) y el rival van a caer por Canto Mortal,
@ mejor explotar, incluso si el rival es inmune (probablemente cambie)
AI_CV_Explosion:
    if_perish_song_not_about_to_trigger AI_USER, AI_CV_SelfKO
    if_perish_song_not_about_to_trigger AI_TARGET, AI_CV_SelfKO
    count_usable_party_mons AI_TARGET
    if_equal 0, Score_Minus10  @ el rival va a caer igualmente, no conviene explotar
    score +6                  @ le explota a lo que sea que aparezca
    if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Plus10  @ neutraliza el -10 por ser Fantasma el rival, ya que va a cambiar
    end

@ (incluye Explosión, salvo en la situación de KO inminente por Canto Mortal)
AI_CV_SelfKO: @ 82DCAC8
	if_stat_level_less_than AI_TARGET, STAT_EVASION, 7, AI_CV_SelfKO_Encourage1
	score -1
	if_stat_level_less_than AI_TARGET, STAT_EVASION, 10, AI_CV_SelfKO_Encourage1
	if_random_less_than 128, AI_CV_SelfKO_Encourage1
	score -1

AI_CV_SelfKO_Encourage1: @ 82DCAE2
	if_hp_less_than AI_USER, 80, AI_CV_SelfKO_Encourage2
	if_target_faster AI_CV_SelfKO_Encourage2
	if_random_less_than 50, AI_CV_SelfKO_End
	goto Score_Minus3

AI_CV_SelfKO_Encourage2: @ 82DCAFA
	if_hp_more_than AI_USER, 50, AI_CV_SelfKO_Encourage4
    if_cant_faint AI_CV_SelfKO_SkipLastMonCheck
    count_usable_party_mons AI_TARGET
    if_equal 0, AI_CV_SelfKO_End  @ recibe bonus en AI_TryToFaint, no necesita más
AI_CV_SelfKO_SkipLastMonCheck:
	if_random_less_than 128, AI_CV_SelfKO_Encourage3
	score +1

AI_CV_SelfKO_Encourage3: @ 82DCB09
	if_hp_more_than AI_USER, 30, AI_CV_SelfKO_End
	if_random_less_than 50, AI_CV_SelfKO_End
	score +1
	goto AI_CV_SelfKO_End

AI_CV_SelfKO_Encourage4: @ 82DCB1D
	if_random_less_than 50, AI_CV_SelfKO_End
	score -1

AI_CV_SelfKO_End: @ 82DCB25
	end

AI_CV_DreamEater: @ 82DCB26
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, AI_CV_DreamEater_ScoreDown1
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, AI_CV_DreamEater_ScoreDown1
	goto AI_CV_DreamEater_End

AI_CV_DreamEater_ScoreDown1: @ 82DCB37
	score -1

AI_CV_DreamEater_End: @ 82DCB39
	end

AI_CV_MirrorMove: @ 82DCB3A
	if_target_faster AI_CV_MirrorMove_TargetIsFaster
	get_last_used_bank_move AI_TARGET
	if_equal MOVE_NONE, Score_Minus8
	if_not_in_hwords AI_CV_MirrorMove_EncouragedMovesToMirror, AI_CV_MirrorMove2
	if_random_less_than 128, AI_CV_MirrorMove_End
	score +2
	goto AI_CV_MirrorMove_End

AI_CV_MirrorMove_TargetIsFaster: @ 82DCB58
	get_last_used_bank_move AI_TARGET
	if_in_hwords AI_CV_MirrorMove_EncouragedMovesToMirror, AI_CV_MirrorMove_End
AI_CV_MirrorMove2:
	if_random_less_than 80, AI_CV_MirrorMove_End
	score -1

AI_CV_MirrorMove_End: @ 82DCB6B
	end

.align 2
AI_CV_MirrorMove_EncouragedMovesToMirror: @ 82DCB6C
    .2byte MOVE_SLEEP_POWDER
    .2byte MOVE_LOVELY_KISS
    .2byte MOVE_SPORE
    .2byte MOVE_HYPNOSIS
    .2byte MOVE_SING
    .2byte MOVE_GRASS_WHISTLE
    .2byte MOVE_SHADOW_PUNCH
    .2byte MOVE_SAND_ATTACK
    .2byte MOVE_SMOKESCREEN
    .2byte MOVE_TOXIC
    .2byte MOVE_GUILLOTINE
    .2byte MOVE_HORN_DRILL
    .2byte MOVE_FISSURE
    .2byte MOVE_SHEER_COLD
    .2byte MOVE_CROSS_CHOP
    .2byte MOVE_AEROBLAST
    .2byte MOVE_CONFUSE_RAY
    .2byte MOVE_SWEET_KISS
    .2byte MOVE_SCREECH
    .2byte MOVE_COTTON_SPORE
    .2byte MOVE_SCARY_FACE
    .2byte MOVE_FAKE_TEARS
    .2byte MOVE_METAL_SOUND
    .2byte MOVE_THUNDER_WAVE
    .2byte MOVE_GLARE
    .2byte MOVE_POISON_POWDER
    .2byte MOVE_SHADOW_BALL
    .2byte MOVE_DYNAMIC_PUNCH
    .2byte MOVE_HYPER_BEAM
    .2byte MOVE_EXTREME_SPEED
    .2byte MOVE_THIEF
    .2byte MOVE_COVET
    .2byte MOVE_ATTRACT
    .2byte MOVE_SWAGGER
    .2byte MOVE_TORMENT
    .2byte MOVE_FLATTER
    .2byte MOVE_TRICK
    .2byte MOVE_SUPERPOWER
    .2byte MOVE_SKILL_SWAP
    .2byte -1

@ Comprueba que tiene Endeavor y nivel como máximo 2
@ En caso contrario, considera que no es FEAR
AI_CV_QuickAttack::
	if_level_cond AI_LEVEL_IS_AT_MOST_2, AI_CV_QuickAttackFear_CheckEndeavor
    goto AI_CV_QuickAttack_NoFEAR

AI_CV_QuickAttackFear_CheckEndeavor:
	if_has_move AI_USER, MOVE_ENDEAVOR, AI_CV_QuickAttackFear
    goto AI_CV_QuickAttack_NoFEAR

@ IA para FEAR
@ Quita puntos a no ser que el rival tenga 1 PS
AI_CV_QuickAttackFear:
	if_hp_condition TARGET_HAS_1_HP, AI_CV_QuickAttackFear_End   @ recibirá puntos en otra parte porque es suficiente para KO
	score -4
AI_CV_QuickAttackFear_End:
	end

@ IA no FEAR. Tira prioridad (incluye otros movs de prioridad)
@ si es probable que, de elegir un ataque sin prioridad, no les dé tiempo a atacar
@ Da más bonus cuando alguno de los pokes está en su primer turno
AI_CV_QuickAttack_NoFEAR:
    if_user_faster AI_CV_QuickAttack_End
    if_can_faint AI_CV_QuickAttack_End @ ya recibe suficiente bonus
    get_curr_dmg_hp_percent
    if_less_than 4, AI_CV_QuickAttack_End
    if_status2 AI_USER, STATUS2_SUBSTITUTE, AI_CV_QuickAttack_End
    if_hp_not_equal AI_USER, 100, AI_CV_QuickAttack_NoFEAR_SkipSashSturdyCheck
    if_ability AI_USER, ABILITY_STURDY, AI_CV_QuickAttack_End
    if_holds_item AI_USER, ITEM_FOCUS_SASH, AI_CV_QuickAttack_End
AI_CV_QuickAttack_NoFEAR_SkipSashSturdyCheck:
    calculate_nhko AI_TARGET
    if_more_than 1, AI_CV_QuickAttack_End
    calculate_nhko AI_TARGET @ se hace dos veces para que solo lo haga si es claro que el rival hace KO
    if_more_than 1, AI_CV_QuickAttack_End
@ Se da 5 si alguno de los pokes está en su primer turno (más incertidumbre sobre lo que hará el rival)
    is_first_turn_for AI_USER
    if_equal 1, Score_Plus5
    is_first_turn_for AI_TARGET
    if_equal 1, Score_Plus5
    score +1
AI_CV_QuickAttack_End:
    end
	
AI_CV_WillOWisp:
    if_ability_might_be AI_TARGET, ABILITY_WONDER_GUARD, Score_Plus1
    get_possible_categories_of_foes_attacks
    if_equal AI_PHYSICAL_ONLY, Score_Plus1
    if_equal AI_ONLY_PHYSICAL_KNOWN, Score_Plus1
    if_equal AI_UNKNOWN_CATEGORIES_PROBABLY_PHYSICAL, Score_Plus1
    if_equal AI_NO_DAMAGING_MOVES, AI_CV_WillOWisp_DiscourageIfTargetHasRest @ posiblemente no viene mal meterle status a un poke defensivo que no tenga Rest
    if_equal AI_BOTH_PHYSICAL_AND_SPECIAL AI_Ret
    if_equal AI_UNKNOWN_CATEGORIES, AI_Ret
    calculate_nhko AI_TARGET     @ es un poke que ataca por el lado especial probablemente:
    if_less_than 3, Score_Minus2 @ si hace mucho daño mejor no perder el tiempo con WoW
AI_CV_WillOWisp_DiscourageIfTargetHasRest:
    if_has_move_with_effect AI_TARGET, EFFECT_REST, Score_Minus2
    end

AI_CV_Wish:
    count_usable_party_mons AI_USER
    if_more_than 0, AI_CV_Wish_NotLastMon
    if_perish_song_about_to_trigger AI_USER, Score_Minus5
    goto AI_CV_Wish_CannotSwitchOut

AI_CV_Wish_NotLastMon:
    if_perish_song_about_to_trigger AI_USER, Score_Plus1
    if_not_status2 AI_USER, STATUS2_ESCAPE_PREVENTION | STATUS2_WRAPPED, AI_CV_Wish2
AI_CV_Wish_CannotSwitchOut:
    calculate_nhko AI_TARGET
    if_equal 1, Score_Minus3
    if_more_than 2, AI_CV_Wish2
    if_doesnt_have_move_with_effect AI_USER, EFFECT_PROTECT, Score_Minus3
    if_hp_more_than AI_USER, 85, Score_Minus2
AI_CV_Wish2:
    if_user_has_revealed_move MOVE_WISH, AI_CV_Wish_MoveHasBeenRevealed
    goto AI_CV_Wish_End

@ No tiene prisa en usar Wish si no corre peligro ante el rival
AI_CV_Wish_MoveHasBeenRevealed:
    if_hp_less_than AI_USER, 87, AI_CV_Wish_End
    is_first_turn_for AI_USER
    if_equal 0, AI_CV_Wish_End
    is_first_turn_for AI_TARGET
    if_equal 0, AI_CV_Wish_End
    if_random_less_than 64, AI_CV_Wish_End
    calculate_nhko AI_TARGET
    if_less_than 3, AI_CV_Wish_End
    if_more_than 4, Score_Minus1
    if_has_move_with_effect AI_USER, EFFECT_PROTECT, Score_Minus1
AI_CV_Wish_End:
    end

AI_CV_RapidSpin:
    if_side_affecting AI_USER, SIDE_STATUS_SPIKES, AI_CV_RapidSpin_SpikesCount
AI_CV_RapidSpin_SpikesAreIrrelevant:
    calculate_nhko AI_TARGET
    if_equal 1, AI_CV_RapidSpin_End
    if_status3 AI_USER, STATUS3_LEECHSEED, Score_Plus1
    if_status2 AI_USER, STATUS2_WRAPPED, Score_Plus1
    if_user_faster AI_CV_RapidSpin_End
    if_target_will_be_faster_after_this_effect AI_CV_RapidSpin_End
    score +1
AI_CV_RapidSpin_End:
    end

AI_CV_RapidSpin_SpikesCount:
    count_usable_party_mons AI_USER
    if_equal 0, AI_CV_RapidSpin_SpikesAreIrrelevant
    get_hazards_count AI_USER, EFFECT_SPIKES
    if_equal 3, Score_Plus3
    if_equal 2, Score_Plus2
    goto Score_Plus1        @ hay una fila de púas

AI_CV_Rollout:
	if_status AI_USER, STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_PARALYSIS, Score_Minus10
	if_status2 AI_USER, STATUS2_CONFUSION | STATUS2_INFATUATION, Score_Minus10
	if_stat_level_less_than AI_USER, STAT_ACC, 6, Score_Minus5
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 6, Score_Minus5
	if_status2 AI_TARGET, STATUS2_CONFUSION | STATUS2_INFATUATION, AI_CV_Rollout2
	if_status AI_TARGET, STATUS1_PARALYSIS, AI_CV_Rollout2
	goto AI_CV_Rollout3
AI_CV_Rollout2:
	score +1
AI_CV_Rollout3:
	if_status AI_TARGET, STATUS1_SLEEP | STATUS1_FREEZE, Score_Plus2
	end

AI_CV_SwordsDance:
	if_stat_level_less_than AI_USER, STAT_ATK, 8, AI_CV_AttackUp_NotInATimer
AI_CV_AttackUp_NotSwordsDance:
	if_status3 AI_USER, STATUS3_PERISH_SONG, Score_Minus5
	if_user_is_intoxicated_and_does_not_have_baton_pass Score_Minus5
AI_CV_AttackUp_NotInATimer:
	if_perish_song_about_to_trigger AI_USER, Score_Minus5
	if_has_move_with_effect AI_USER, EFFECT_BATON_PASS, AI_CV_AttackUp_ConsiderSetupEagerly
	calculate_nhko
	if_less_than 3, AI_CV_AttackUp_ConsiderSetupEagerly
	if_more_than 3, AI_CV_AttackUp_FreeSetupNotWorth
	if_stat_level_more_than AI_USER, STAT_ATK, 8, AI_CV_AttackUp_FreeSetupNotWorth
	if_stat_level_less_than AI_USER, STAT_ATK, 3, AI_CV_AttackUp_FreeSetupNotWorth
	if_user_can_probably_boost_safely Score_Plus2
	goto AI_CV_AttackUp_FreeSetupNotWorth_Minus2

AI_CV_AttackUp_ConsiderSetupEagerly:
	if_free_setup_turn Score_Plus5
	if_user_can_probably_boost_safely Score_Plus5
	goto AI_CV_AttackUp_SkipFreeSetupCheck

AI_CV_AttackUp_FreeSetupNotWorth:
	if_user_can_probably_boost_safely AI_CV_AttackUp_SkipFreeSetupCheck
AI_CV_AttackUp_FreeSetupNotWorth_Minus2:
	score -2
AI_CV_AttackUp_SkipFreeSetupCheck:
	if_this_attack_might_be_the_last Score_Minus5
	if_doesnt_have_move_with_effect AI_TARGET, EFFECT_SUBSTITUTE, AI_CV_AttackUp_SkipSubCheck
	if_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_CV_AttackUp_SkipSubCheck
	if_hp_condition TARGET_CANNOT_USE_SUB, AI_CV_AttackUp_SkipSubCheck
	score -1
AI_CV_AttackUp_SkipSubCheck:
	if_stat_level_less_than AI_USER, STAT_ATK, 9, AI_CV_AttackUp2
	if_random_less_than 100, AI_CV_AttackUp3
	score -1
	goto AI_CV_AttackUp3
	 
AI_CV_AttackUp2: @ 82DCBD1
	if_hp_not_equal AI_USER, 100, AI_CV_AttackUp3
	if_random_less_than 128, AI_CV_AttackUp3
	score +2

AI_CV_AttackUp3: @ 82DCBE0
	if_hp_more_than AI_USER, 70, AI_CV_AttackUp_End
	if_hp_less_than AI_USER, 40, AI_CV_AttackUp_ScoreDown2
	if_random_less_than 40, AI_CV_AttackUp_End

AI_CV_AttackUp_ScoreDown2: @ 82DCBF4
	score -2

AI_CV_AttackUp_End: @ 82DCBF6
	end

AI_CV_DefenseUp: @ 82DCBF7
    if_status3 AI_USER, STATUS3_PERISH_SONG, Score_Minus5
    if_user_is_intoxicated_and_does_not_have_baton_pass Score_Minus5
    if_hp_condition USER_HAS_1_HP, Score_Minus5
    get_possible_categories_of_foes_attacks
    if_equal AI_SPECIAL_ONLY, AI_CV_DefenseUp_Minus3Or5
    if_equal AI_ONLY_SPECIAL_KNOWN, AI_CV_DefenseUp_Minus2Or5
    if_equal AI_UNKNOWN_CATEGORIES_PROBABLY_SPECIAL, AI_CV_DefenseUp_Minus2Or5
    if_equal AI_NO_DAMAGING_MOVES, AI_CV_DefenseUp_Minus2Or5
    if_equal AI_UNKNOWN_CATEGORIES, AI_CV_DefenseUp_CheckIfThisAttackMightBeTheLast
    if_has_non_ineffective_move_with_effect AI_TARGET, EFFECT_LEVEL_DAMAGE, AI_CV_DefenseUp_CheckIfThisAttackMightBeTheLast
    if_stat_level_less_than AI_USER, STAT_DEF, 8, AI_CV_DefenseUp_DoNotCheckIfThisAttackMightBeTheLast
AI_CV_DefenseUp_CheckIfThisAttackMightBeTheLast:
    if_this_attack_might_be_the_last Score_Minus5
AI_CV_DefenseUp_DoNotCheckIfThisAttackMightBeTheLast:
	if_stat_level_less_than AI_USER, STAT_DEF, 9, AI_CV_DefenseUp2
	if_random_less_than 100, AI_CV_DefenseUp3
	score -1
	goto AI_CV_DefenseUp3

AI_CV_DefenseUp_Minus3Or5:
	if_this_attack_might_be_the_last Score_Minus5
	goto Score_Minus3

AI_CV_DefenseUp_Minus2Or5:
	if_this_attack_might_be_the_last Score_Minus5
	goto Score_Minus2

AI_CV_DefenseUp2: @ 82DCC0C
	if_hp_not_equal AI_USER, 100, AI_CV_DefenseUp3
	if_random_less_than 128, AI_CV_DefenseUp3
	score +2

AI_CV_DefenseUp3: @ 82DCC1B
	if_hp_less_than AI_USER, 70, AI_CV_DefenseUp4
	if_random_less_than 200, AI_CV_DefenseUp_End

AI_CV_DefenseUp4: @ 82DCC28
	if_hp_less_than AI_USER, 40, AI_CV_DefenseUp_ScoreDown2
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, AI_CV_DefenseUp5
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_not_in_bytes AI_CV_DefenseUp_PhysicalTypes, AI_CV_DefenseUp_ScoreDown2
	if_random_less_than 60, AI_CV_DefenseUp_End

AI_CV_DefenseUp5: @ 82DCC4A
	if_random_less_than 60, AI_CV_DefenseUp_End

AI_CV_DefenseUp_ScoreDown2: @ 82DCC50
	score -2

AI_CV_DefenseUp_End: @ 82DCC52
	end

AI_CV_DefenseUp_PhysicalTypes: @ 82DCC53
    .byte TYPE_NORMAL
    .byte TYPE_FIGHTING
    .byte TYPE_POISON
    .byte TYPE_GROUND
    .byte TYPE_FLYING
    .byte TYPE_ROCK
    .byte TYPE_BUG
    .byte TYPE_GHOST
    .byte TYPE_STEEL
    .byte -1

AI_CV_SpeedUp: @ 82DCC5D
	if_status3 AI_USER, STATUS3_PERISH_SONG, Score_Minus5
	count_usable_party_mons AI_USER
	if_equal 0, AI_CV_SpeedUp_NoBatonPass
	if_has_move_with_effect AI_USER, EFFECT_BATON_PASS, AI_CV_SpeedUp_HasBatonPass
AI_CV_SpeedUp_NoBatonPass:
@ Evita subirse Velocidad si tardará más de 3 turnos en dar KO al rival,
@ si el rival mete OHKO, o si el rival mete 2HKO y no le mete OHKO
   calculate_nhko
   if_more_than 3, Score_Minus3
   calculate_nhko AI_TARGET
   if_equal 1, Score_Minus3
   if_more_than 2, AI_CV_SpeedUp_SkipOHKOCheck
   calculate_nhko
   if_more_than 1, Score_Minus3
AI_CV_SpeedUp_SkipOHKOCheck:
    if_ability AI_USER, ABILITY_SHED_SKIN, AI_CV_SpeedUp_SkipParalysisCheck
    if_not_status AI_USER, STATUS1_PARALYSIS, AI_CV_SpeedUp_SkipParalysisCheck
    score -2
AI_CV_SpeedUp_SkipParalysisCheck:
    if_target_faster AI_CV_SpeedUp2
@ Si ya es más rápido, evita subirse Velocidad a no ser que pase todo lo siguiente:
@ 1.- puede meterle 2HKO al rival
@ 2.- no espera caer en menos de 4 golpes del rival
@ 3.- está a +0 o menos de Velocidad
@ 4.- el rival no es el último poke
@ 5.- el rival no tiene Encore
@ en cuyo caso puede intentar subirse Velocidad, aunque con un poco menos de ganas
    count_usable_party_mons AI_TARGET
    if_equal 0, AI_CV_SpeedUp_AlreadyFasterAndNoChanceToSweep
    if_has_move_with_effect AI_TARGET, EFFECT_ENCORE, AI_CV_SpeedUp_AlreadyFasterAndNoChanceToSweep
    if_stat_level_more_than AI_USER, STAT_SPEED, 6, AI_CV_SpeedUp_AlreadyFasterAndNoChanceToSweep
    calculate_nhko
    if_more_than 2, AI_CV_SpeedUp_AlreadyFasterAndNoChanceToSweep
    calculate_nhko AI_TARGET
    if_less_than 4, AI_CV_SpeedUp_AlreadyFasterAndNoChanceToSweep
    if_random_less_than 170, AI_CV_SpeedUp2WithPenalty
AI_CV_SpeedUp_AlreadyFasterAndNoChanceToSweep:
	score -3
	goto AI_CV_SpeedUp_End

@ Si tiene Baton Pass, los criterios anteriores se sustituyen por:
@ no subirse Velocidad si espera recibir KO o si está ya a +4
@ por lo menos (en general, de sobra para outspeedear casi todo)
@ Además, le resta 1 punto (pero continúa evaluando) si ya está a +2 o +3
AI_CV_SpeedUp_HasBatonPass:
    calculate_nhko AI_TARGET
    if_equal 1, Score_Minus3
    if_stat_level_more_than AI_USER, STAT_SPEED, 9, Score_Minus3
    if_stat_level_less_than AI_USER, STAT_SPEED, 8, AI_CV_SpeedUp2
AI_CV_SpeedUp2WithPenalty:
    score -1 @ (sigue)
AI_CV_SpeedUp2: @ 82DCC6A
	if_free_setup_turn Score_Plus5
	if_this_attack_might_be_the_last Score_Minus5
	if_random_less_than 70, AI_CV_SpeedUp_End
	score +3

AI_CV_SpeedUp_End: @ 82DCC72
	end

AI_CV_SpAtkUpNPTG:
	if_stat_level_less_than AI_USER, STAT_SPATK, 8, AI_CV_SpAtkUp_NotInATimer
AI_CV_SpAtkUp_NotNastyPlotOrTailGlow:
	if_status3 AI_USER, STATUS3_PERISH_SONG, Score_Minus5
	if_user_is_intoxicated_and_does_not_have_baton_pass Score_Minus5
AI_CV_SpAtkUp_NotInATimer:
	if_perish_song_about_to_trigger AI_USER, Score_Minus5
	if_has_move_with_effect AI_USER, EFFECT_BATON_PASS, AI_CV_SpAtkUp_ConsiderSetupEagerly
	calculate_nhko
	if_less_than 3, AI_CV_SpAtkUp_ConsiderSetupEagerly
	if_more_than 3, AI_CV_SpAtkUp_FreeSetupNotWorth
	if_stat_level_more_than AI_USER, STAT_SPATK, 8, AI_CV_SpAtkUp_FreeSetupNotWorth
	if_stat_level_less_than AI_USER, STAT_SPATK, 3, AI_CV_SpAtkUp_FreeSetupNotWorth
	if_user_can_probably_boost_safely Score_Plus2
	goto AI_CV_SpAtkUp_FreeSetupNotWorth_Minus2

AI_CV_SpAtkUp_ConsiderSetupEagerly:
	if_free_setup_turn Score_Plus5
	if_user_can_probably_boost_safely Score_Plus5
	goto AI_CV_SpAtkUp_SkipFreeSetupCheck

AI_CV_SpAtkUp_FreeSetupNotWorth:
	if_user_can_probably_boost_safely AI_CV_SpAtkUp_SkipFreeSetupCheck
AI_CV_SpAtkUp_FreeSetupNotWorth_Minus2:
	score -2
AI_CV_SpAtkUp_SkipFreeSetupCheck:
	if_this_attack_might_be_the_last Score_Minus5
	if_doesnt_have_move_with_effect AI_TARGET, EFFECT_SUBSTITUTE, AI_CV_SpAtkUp_SkipSubCheck
	if_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_CV_SpAtkUp_SkipSubCheck
	if_hp_condition TARGET_CANNOT_USE_SUB, AI_CV_SpAtkUp_SkipSubCheck
	score -1
AI_CV_SpAtkUp_SkipSubCheck:
	if_stat_level_less_than AI_USER, STAT_SPATK, 9, AI_CV_SpAtkUp2
	if_random_less_than 100, AI_CV_SpAtkUp3
	score -1
	goto AI_CV_SpAtkUp3

AI_CV_SpAtkUp2: @ 82DCC88
	if_hp_not_equal AI_USER, 100, AI_CV_SpAtkUp3
	if_random_less_than 128, AI_CV_SpAtkUp3
	score +2

AI_CV_SpAtkUp3: @ 82DCC97
	if_hp_more_than AI_USER, 70, AI_CV_SpAtkUp_End
	if_hp_less_than AI_USER, 40, AI_CV_SpAtkUp_ScoreDown2
	if_random_less_than 70, AI_CV_SpAtkUp_End

AI_CV_SpAtkUp_ScoreDown2: @ 82DCCAB
	score -2

AI_CV_SpAtkUp_End: @ 82DCCAD
	end

AI_CV_Growth:
	if_stat_level_equal AI_USER, STAT_SPATK, 12, AI_CV_AttackUp_NotSwordsDance
	if_status3 AI_USER, STATUS3_PERISH_SONG, Score_Minus5
	if_user_is_intoxicated_and_does_not_have_baton_pass Score_Minus5
	if_has_move_with_effect AI_USER, EFFECT_BATON_PASS, AI_CV_Growth_ConsiderSetupEagerly
	calculate_nhko
	if_less_than 3, AI_CV_Growth_ConsiderSetupEagerly
	if_more_than 3, AI_CV_Growth_FreeSetupNotWorth
	if_stat_level_more_than AI_USER, STAT_ATK, 8, AI_CV_Growth_FreeSetupNotWorth
	if_stat_level_less_than AI_USER, STAT_ATK, 3, AI_CV_Growth_FreeSetupNotWorth
	if_stat_level_more_than AI_USER, STAT_SPATK, 8, AI_CV_Growth_FreeSetupNotWorth
	if_stat_level_less_than AI_USER, STAT_SPATK, 3, AI_CV_Growth_FreeSetupNotWorth
	if_user_can_probably_boost_safely Score_Plus2
	goto AI_CV_Growth_FreeSetupNotWorth_Minus2

AI_CV_Growth_ConsiderSetupEagerly:
	if_free_setup_turn Score_Plus5
	if_user_can_probably_boost_safely Score_Plus5
	goto AI_CV_Growth_SkipFreeSetupCheck

AI_CV_Growth_FreeSetupNotWorth:
	if_user_can_probably_boost_safely AI_CV_Growth_SkipFreeSetupCheck
AI_CV_Growth_FreeSetupNotWorth_Minus2:
	score -2
AI_CV_Growth_SkipFreeSetupCheck:
	if_this_attack_might_be_the_last Score_Minus5
	if_doesnt_have_move_with_effect AI_TARGET, EFFECT_SUBSTITUTE, AI_CV_Growth_SkipSubCheck
	if_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_CV_Growth_SkipSubCheck
	if_hp_condition TARGET_CANNOT_USE_SUB, AI_CV_Growth_SkipSubCheck
	score -1
AI_CV_Growth_SkipSubCheck:
	if_stat_level_less_than AI_USER, STAT_SPATK, 8, AI_CV_Growth2
	if_stat_level_less_than AI_USER, STAT_ATK, 8, AI_CV_Growth2
	if_random_less_than 100, AI_CV_Growth3
	score -1
	goto AI_CV_Growth3

AI_CV_Growth2:
	if_hp_not_equal AI_USER, 100, AI_CV_Growth3
	if_random_less_than 128, AI_CV_Growth3
	score +2

AI_CV_Growth3:
	if_hp_more_than AI_USER, 70, AI_CV_Growth_End
	if_hp_less_than AI_USER, 40, AI_CV_Growth_ScoreDown2
	if_random_less_than 70, AI_CV_Growth_End

AI_CV_Growth_ScoreDown2:
	score -2

AI_CV_Growth_End:
	end
	
AI_CV_CosmicPower:
    if_stat_level_equal AI_USER, STAT_SPDEF, 12, AI_CV_DefenseUp
    if_status3 AI_USER, STATUS3_PERISH_SONG, Score_Minus5
    if_user_is_intoxicated_and_does_not_have_baton_pass Score_Minus5
    if_hp_condition USER_HAS_1_HP, Score_Minus5
    if_has_non_ineffective_move_with_effect AI_TARGET, EFFECT_LEVEL_DAMAGE, AI_CV_CosmicPower_CheckIfThisAttackMightBeTheLast
    if_stat_level_less_than AI_USER, STAT_SPDEF, 8, AI_CV_CosmicPower_DoNotCheckIfThisAttackMightBeTheLast
    if_stat_level_less_than AI_USER, STAT_DEF, 8, AI_CV_CosmicPower_DoNotCheckIfThisAttackMightBeTheLast
AI_CV_CosmicPower_CheckIfThisAttackMightBeTheLast:
    if_this_attack_might_be_the_last Score_Minus5
AI_CV_CosmicPower_DoNotCheckIfThisAttackMightBeTheLast:
    if_stat_level_less_than AI_USER, STAT_SPDEF, 9, AI_CV_CosmicPowerUp2
    if_stat_level_less_than AI_USER, STAT_DEF, 9, AI_CV_CosmicPowerUp2
    if_random_less_than 100, AI_CV_CosmicPowerUp3
    score -1
    goto AI_CV_CosmicPowerUp3

AI_CV_CosmicPowerUp2:
    if_user_can_probably_boost_safely Score_Plus5
    if_hp_not_equal AI_USER, 100, AI_CV_CosmicPowerUp3
    if_random_less_than 128, AI_CV_CosmicPowerUp3
    score +2

AI_CV_CosmicPowerUp3:
    if_user_can_probably_boost_safely Score_Plus2
    if_hp_less_than AI_USER, 70, AI_CV_CosmicPowerUp4
    if_random_less_than 200, AI_CV_CosmicPower_End

AI_CV_CosmicPowerUp4:
    if_hp_more_than AI_USER, 40, AI_CV_CosmicPower_End

AI_CV_CosmicPower_ScoreDown2:
    score -2

AI_CV_CosmicPower_End:
    end

AI_CV_SpDefUp: @ 82DCCAE
    if_status3 AI_USER, STATUS3_PERISH_SONG, Score_Minus5
    if_user_is_intoxicated_and_does_not_have_baton_pass Score_Minus5
    if_hp_condition USER_HAS_1_HP, Score_Minus5
    get_possible_categories_of_foes_attacks
    if_equal AI_PHYSICAL_ONLY, AI_CV_SpDefUp_Minus3Or5
    if_equal AI_ONLY_PHYSICAL_KNOWN, AI_CV_SpDefUp_Minus2Or5
    if_equal AI_UNKNOWN_CATEGORIES_PROBABLY_PHYSICAL, AI_CV_SpDefUp_Minus2Or5
    if_equal AI_NO_DAMAGING_MOVES, AI_CV_SpDefUp_Minus2Or5
    if_equal AI_UNKNOWN_CATEGORIES, AI_CV_SpDefUp_CheckIfThisAttackMightBeTheLast
    if_has_non_ineffective_move_with_effect AI_TARGET, EFFECT_LEVEL_DAMAGE, AI_CV_SpDefUp_CheckIfThisAttackMightBeTheLast
    if_stat_level_less_than AI_USER, STAT_SPDEF, 8, AI_CV_SpDefUp_DoNotCheckIfThisAttackMightBeTheLast
AI_CV_SpDefUp_CheckIfThisAttackMightBeTheLast:
    if_this_attack_might_be_the_last Score_Minus5
AI_CV_SpDefUp_DoNotCheckIfThisAttackMightBeTheLast:
	if_stat_level_less_than AI_USER, STAT_SPDEF, 9, AI_CV_SpDefUp2
	if_random_less_than 100, AI_CV_SpDefUp3
	score -1
	goto AI_CV_SpDefUp3

AI_CV_SpDefUp_Minus3Or5:
	if_this_attack_might_be_the_last Score_Minus5
	goto Score_Minus3

AI_CV_SpDefUp_Minus2Or5:
	if_this_attack_might_be_the_last Score_Minus5
	goto Score_Minus2


AI_CV_SpDefUp2: @ 82DCCC3
	if_hp_not_equal AI_USER, 100, AI_CV_SpDefUp3
	if_random_less_than 128, AI_CV_SpDefUp3
	score +2

AI_CV_SpDefUp3: @ 82DCCD2
	if_hp_less_than AI_USER, 70, AI_CV_SpDefUp4
	if_random_less_than 200, AI_CV_SpDefUp_End

AI_CV_SpDefUp4: @ 82DCCDF
	if_hp_less_than AI_USER, 40, AI_CV_SpDefUp_ScoreDown2
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, AI_CV_SpDefUp5
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_in_bytes AI_CV_SpDefUp_PhysicalTypes, AI_CV_SpDefUp_ScoreDown2
	if_random_less_than 60, AI_CV_SpDefUp_End

AI_CV_SpDefUp5: @ 82DCD01
	if_random_less_than 60, AI_CV_SpDefUp_End

AI_CV_SpDefUp_ScoreDown2: @ 82DCD07
	score -2

AI_CV_SpDefUp_End: @ 82DCD09
	end

AI_CV_SpDefUp_PhysicalTypes: @ 82DCD0A
    .byte TYPE_NORMAL
    .byte TYPE_FIGHTING
    .byte TYPE_POISON
    .byte TYPE_GROUND
    .byte TYPE_FLYING
    .byte TYPE_ROCK
    .byte TYPE_BUG
    .byte TYPE_GHOST
    .byte TYPE_STEEL
    .byte -1

AI_CV_AccuracyUp:
	if_stat_level_less_than AI_USER, STAT_ACC, 9, AI_CV_AccuracyUp2
	if_random_less_than 50, AI_CV_AccuracyUp2
	score -2

AI_CV_AccuracyUp2:
	if_hp_more_than AI_USER, 70, AI_CV_AccuracyUp_End
	score -2

AI_CV_AccuracyUp_End:
	end

AI_CV_EvasionUp:
    if_user_is_intoxicated_and_does_not_have_baton_pass Score_Minus5
    if_has_non_ineffective_move_with_effect AI_TARGET, EFFECT_ALWAYS_HIT, Score_Minus5
    if_has_non_ineffective_move_with_effect AI_TARGET, EFFECT_VITAL_THROW, Score_Minus5
    if_ability AI_USER, ABILITY_NO_GUARD, Score_Minus5
    if_ability_might_be AI_TARGET, ABILITY_NO_GUARD, Score_Minus5
    if_ability_might_be AI_TARGET, ABILITY_KEEN_EYE, Score_Minus5
    if_status2 AI_USER, STATUS2_FORESIGHT, Score_Minus5
    get_weather
    if_equal AI_WEATHER_HAIL, AI_CV_EvasionUp_BlizzardCheck
    if_equal AI_WEATHER_RAIN, AI_CV_EvasionUp_ThunderCheck
AI_CV_EvasionUp_NoProblematicWeather:
	if_not_status3 AI_USER, STATUS3_ALWAYS_HITS, AI_CV_EvasionUp_NotLockedOn
	if_status2 AI_USER, STATUS2_SUBSTITUTE, AI_CV_EvasionUp_NotLockedOn
	calculate_nhko AI_TARGET
	if_equal 1, AI_CV_EvasionUp_ScoreDown2
	if_ability AI_USER, ABILITY_STURDY, AI_CV_EvasionUp_NotLockedOn
	if_level_cond AI_LEVEL_IS_GREATER_THAN_TARGETS, AI_CV_EvasionUp_NotLockedOn
	if_next_turn_target_might_use_move_with_effect EFFECT_OHKO, AI_CV_EvasionUp_ScoreDown2
AI_CV_EvasionUp_NotLockedOn:
	if_user_can_probably_boost_safely Score_Plus5
	if_stat_level_more_than AI_TARGET, STAT_ACC, 7, AI_CV_EvasionUp2Penalty
	if_stat_level_more_than AI_USER, STAT_EVASION, 6, AI_CV_EvasionUp_ConsiderBonusWithFullHealth
	if_status2 AI_USER, STATUS2_SUBSTITUTE, AI_CV_EvasionUp_ConsiderBonusWithFullHealth
	if_user_faster AI_CV_EvasionUp_ConsiderBonusWithFullHealth
	calculate_nhko AI_TARGET
	if_less_than 3, AI_CV_EvasionUp2Penalty
AI_CV_EvasionUp_ConsiderBonusWithFullHealth:
	if_hp_less_than AI_USER, 90, AI_CV_EvasionUp2
	if_random_less_than 100, AI_CV_EvasionUp2
	score +3

AI_CV_EvasionUp2:
	if_stat_level_less_than AI_USER, STAT_EVASION, 9, AI_CV_EvasionUp3
	if_random_less_than 128, AI_CV_EvasionUp3
AI_CV_EvasionUp2Penalty:
	score -1

AI_CV_EvasionUp3:
	if_not_status AI_TARGET, STATUS1_TOXIC_POISON, AI_CV_EvasionUp5
	if_hp_more_than AI_USER, 50, AI_CV_EvasionUp4
	if_random_less_than 80, AI_CV_EvasionUp5

AI_CV_EvasionUp4:
	if_random_less_than 50, AI_CV_EvasionUp5
	score +3

AI_CV_EvasionUp5:
	if_not_status3 AI_TARGET, STATUS3_LEECHSEED, AI_CV_EvasionUp6
	if_random_less_than 70, AI_CV_EvasionUp6
	score +3

AI_CV_EvasionUp6:
	if_not_status3 AI_USER, STATUS3_ROOTED, AI_CV_EvasionUp7
	if_random_less_than 128, AI_CV_EvasionUp7
	score +2

AI_CV_EvasionUp7:
	if_not_status2 AI_TARGET, STATUS2_CURSED, AI_CV_EvasionUp8
	if_random_less_than 70, AI_CV_EvasionUp8
	score +3

AI_CV_EvasionUp8:
	if_hp_more_than AI_USER, 70, AI_CV_EvasionUp_End
	if_stat_level_equal AI_USER, STAT_EVASION, 6, AI_CV_EvasionUp_End
	if_hp_less_than AI_USER, 40, AI_CV_EvasionUp_ScoreDown2
	if_hp_less_than AI_TARGET, 40, AI_CV_EvasionUp_ScoreDown2
	if_random_less_than 70, AI_CV_EvasionUp_End

AI_CV_EvasionUp_ScoreDown2:
	score -2

AI_CV_EvasionUp_End:
	end

AI_CV_EvasionUp_BlizzardCheck:
    if_has_move AI_TARGET, MOVE_BLIZZARD, Score_Minus2
    goto AI_CV_EvasionUp_NoProblematicWeather

AI_CV_EvasionUp_ThunderCheck:
    if_next_turn_target_might_use_move_with_effect EFFECT_THUNDER, Score_Minus2
    goto AI_CV_EvasionUp_NoProblematicWeather

AI_CV_AlwaysHit:
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 10, AI_CV_AlwaysHit_ScoreUp1
	if_stat_level_less_than AI_USER, STAT_ACC, 2, AI_CV_AlwaysHit_ScoreUp1
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 8, AI_CV_AlwaysHit2
	if_stat_level_less_than AI_USER, STAT_ACC, 4, AI_CV_AlwaysHit2
	goto AI_CV_AlwaysHit_End

AI_CV_AlwaysHit_ScoreUp1:
	score +1

AI_CV_AlwaysHit2:
    score +1
	if_random_less_than 100, AI_CV_AlwaysHit_End
	score +1

AI_CV_AlwaysHit_End:
	end

AI_CV_AttackDown: @ 82DCDF8
	if_stat_level_more_than AI_TARGET, STAT_ATK, 6, AI_CV_AttackDown3
	score -1
	if_hp_more_than AI_USER, 90, AI_CV_AttackDown2
	score -1

AI_CV_AttackDown2: @ 82DCE0B
	if_stat_level_more_than AI_TARGET, STAT_ATK, 3, AI_CV_AttackDown3
	if_random_less_than 50, AI_CV_AttackDown3
	score -2

AI_CV_AttackDown3: @ 82DCE1B
	if_hp_more_than AI_TARGET, 70, AI_CV_AttackDown4
	score -2

AI_CV_AttackDown4: @ 82DCE24
	get_possible_categories_of_foes_attacks
	if_equal AI_PHYSICAL_ONLY, AI_CV_AttackDown_Plus2IfLastMonAgainstSeveral
	if_equal AI_ONLY_PHYSICAL_KNOWN, AI_CV_AttackDown_Plus2IfLastMonAgainstSeveral
	if_equal AI_UNKNOWN_CATEGORIES_PROBABLY_PHYSICAL, AI_CV_AttackDown_End
	if_equal AI_BOTH_PHYSICAL_AND_SPECIAL AI_CV_AttackDown5
	if_equal AI_UNKNOWN_CATEGORIES, AI_CV_AttackDown5
	goto AI_CV_AttackDown_ScoreMinus2 @ no tiene ataques de daño o son probablemente especiales
AI_CV_AttackDown5:
	if_random_less_than 50, AI_CV_AttackDown_End
AI_CV_AttackDown_ScoreMinus2:
	score -2

AI_CV_AttackDown_End: @ 82DCE42
	end

AI_CV_AttackDown_Plus2IfLastMonAgainstSeveral:
	count_usable_party_mons AI_TARGET
	if_more_than 0, AI_CV_AttackDown_End
	count_usable_party_mons AI_USER
	if_more_than 0, Score_Plus2
	goto AI_CV_AttackDown_End

AI_CV_DefenseDown:
	if_stat_level_more_than AI_TARGET, STAT_DEF, 2, AI_CV_DefenseDown_SkipFirstMinus1
	score -1
AI_CV_DefenseDown_SkipFirstMinus1:
	if_has_move_with_effect AI_TARGET, EFFECT_DEFENSE_UP_2, AI_CV_DefenseDown2
	if_hp_less_than AI_USER, 70, AI_CV_DefenseDown2
	if_stat_level_more_than AI_TARGET, STAT_DEF, 5, AI_CV_DefenseDown3
	if_stat_level_less_than AI_TARGET, STAT_DEF, 4, AI_CV_DefenseDown2
	if_random_less_than 100, AI_CV_DefenseDown3

AI_CV_DefenseDown2:
	if_random_less_than 50, AI_CV_DefenseDown3
	score -2
	if_not_status2 AI_TARGET, STATUS2_CONFUSION, AI_CV_DefenseDown3
	score +1
AI_CV_DefenseDown3:
	if_hp_condition TARGET_HAS_1_MAX_HP, Score_Minus3
	if_hp_more_than AI_TARGET, 70, AI_CV_DefenseDown_End
	if_has_move_with_effect AI_TARGET, EFFECT_REST, AI_CV_DefenseDown_End
	if_has_a_50_percent_hp_recovery_move AI_TARGET, AI_CV_DefenseDown_End
	score -1
	if_effect EFFECT_DEFENSE_DOWN_2, AI_CV_DefenseDown_End
	score -1

AI_CV_DefenseDown_End:
	end

AI_CV_SpeedDownFromChance: @ 82DCE6B
	if_ability AI_USER, ABILITY_SHEER_FORCE, AI_Ret
	if_move MOVE_ICY_WIND, AI_CV_SpeedDownAsAGuaranteedSecondaryEffect
	if_move MOVE_ROCK_TOMB, AI_CV_SpeedDownAsAGuaranteedSecondaryEffect
	if_move MOVE_MUD_SHOT, AI_CV_SpeedDownAsAGuaranteedSecondaryEffect
	if_move MOVE_ELECTROWEB, AI_CV_SpeedDownAsAGuaranteedSecondaryEffect
	end

AI_CV_SpeedDownAsAGuaranteedSecondaryEffect:
	count_usable_party_mons AI_USER
	if_more_than 0, AI_CV_SpeedDownAsAGuaranteedSecondaryEffect_NotLastMonOrSlower
	if_user_faster AI_Ret
AI_CV_SpeedDownAsAGuaranteedSecondaryEffect_NotLastMonOrSlower:
	if_side_affecting AI_TARGET, SIDE_STATUS_MIST, AI_Ret
	if_ability_might_be AI_TARGET, ABILITY_SHIELD_DUST, AI_Ret
	if_stat_level_equal AI_TARGET, STAT_SPEED, 0, AI_Ret
	if_ability_might_be AI_TARGET, ABILITY_SPEED_BOOST, AI_Ret
	if_ability_might_be AI_TARGET, ABILITY_CLEAR_BODY, AI_Ret
	if_ability_might_be AI_TARGET, ABILITY_WHITE_SMOKE, AI_Ret
	if_target_might_have_a_sub_before_our_attack AI_Ret
AI_CV_SpeedDown: @ 82DCE81
	if_target_faster AI_CV_SpeedDown2
	count_usable_party_mons AI_USER
	if_equal 0, Score_Minus8
	goto AI_CV_SpeedDown_End

AI_CV_SpeedDown2: @ 82DCE8E
	if_random_less_than 70, AI_CV_SpeedDown_End
	score +2
	if_target_will_be_faster_after_this_effect Score_Minus1

AI_CV_SpeedDown_End: @ 82DCE96
	end

AI_CV_SpAtkDown:
	if_stat_level_more_than AI_TARGET, STAT_SPATK, 6, AI_CV_SpAtkDown3
	score -1
	if_hp_more_than AI_USER, 90, AI_CV_SpAtkDown2
	score -1

AI_CV_SpAtkDown2:
	if_stat_level_more_than AI_TARGET, STAT_SPATK, 3, AI_CV_SpAtkDown3
	if_random_less_than 50, AI_CV_SpAtkDown3
	score -2

AI_CV_SpAtkDown3:
	if_hp_more_than AI_TARGET, 70, AI_CV_SpAtkDown4
	score -2

AI_CV_SpAtkDown4:
	get_possible_categories_of_foes_attacks
	if_equal AI_SPECIAL_ONLY, AI_CV_SpAtkDown_Plus2IfLastMonAgainstSeveral
	if_equal AI_ONLY_SPECIAL_KNOWN, AI_CV_SpAtkDown_Plus2IfLastMonAgainstSeveral
	if_equal AI_UNKNOWN_CATEGORIES_PROBABLY_SPECIAL, AI_CV_SpAtkDown_End
	if_equal AI_BOTH_PHYSICAL_AND_SPECIAL AI_CV_SpAtkDown5
	if_equal AI_UNKNOWN_CATEGORIES, AI_CV_SpAtkDown5
	goto AI_CV_SpAtkDown_ScoreMinus2 @ no tiene ataques de daño o son probablemente físicos
AI_CV_SpAtkDown5:
	if_random_less_than 50, AI_CV_SpAtkDown_End
AI_CV_SpAtkDown_ScoreMinus2:
	score -2

AI_CV_SpAtkDown_End: @ 82DCEE1
	end

AI_CV_SpAtkDown_Plus2IfLastMonAgainstSeveral:
	count_usable_party_mons AI_TARGET
	if_more_than 0, AI_CV_SpAtkDown_End
	count_usable_party_mons AI_USER
	if_more_than 0, Score_Plus2
	goto AI_CV_SpAtkDown_End

AI_CV_SpDefDown: @ 82DCEEB
	if_stat_level_more_than AI_TARGET, STAT_SPDEF, 2, AI_CV_SpDefDown_SkipFirstMinus1
	score -1
AI_CV_SpDefDown_SkipFirstMinus1:
	if_has_move_with_effect AI_TARGET, EFFECT_SPECIAL_DEFENSE_UP_2, AI_CV_SpDefDown2
	if_hp_less_than AI_USER, 70, AI_CV_SpDefDown2
	if_stat_level_more_than AI_TARGET, STAT_SPDEF, 5, AI_CV_SpDefDown3
	if_stat_level_less_than AI_TARGET, STAT_SPDEF, 4, AI_CV_SpDefDown2
	if_random_less_than 100, AI_CV_SpDefDown3

AI_CV_SpDefDown2: @ 82DCEFA
	if_random_less_than 50, AI_CV_SpDefDown3
	score -2

AI_CV_SpDefDown3: @ 82DCF02
	if_hp_condition TARGET_HAS_1_MAX_HP, Score_Minus3
	if_hp_more_than AI_TARGET, 70, AI_CV_SpDefDown_End
	if_has_move_with_effect AI_TARGET, EFFECT_REST, AI_CV_SpDefDown_End
	if_has_a_50_percent_hp_recovery_move AI_TARGET, AI_CV_SpDefDown_End
	score -1
	if_effect EFFECT_SPECIAL_DEFENSE_DOWN_2, AI_CV_SpDefDown_End
	score -1

AI_CV_SpDefDown_End: @ 82DCF0B
	end
	
AI_CV_AccuracyDownFromChance:
	if_ability AI_USER, ABILITY_SHEER_FORCE, AI_Ret
	if_ability AI_TARGET, ABILITY_SHIELD_DUST, AI_Ret
	if_move MOVE_MUD_SLAP, AI_CV_AccuracyDown_MudSlap
	end

AI_CV_AccuracyDown_MudSlap:
    if_target_might_have_a_sub_before_our_attack AI_Ret
    if_stat_level_equal AI_TARGET, STAT_ACC, 0, AI_Ret
    if_side_affecting AI_TARGET, SIDE_STATUS_MIST, AI_Ret
    if_ability_might_be AI_TARGET, ABILITY_KEEN_EYE, AI_Ret
    if_ability_might_be AI_TARGET, ABILITY_NO_GUARD, AI_Ret
    if_ability_might_be AI_TARGET, ABILITY_CLEAR_BODY, AI_Ret
    if_ability_might_be AI_TARGET, ABILITY_WHITE_SMOKE, AI_Ret
    if_has_non_ineffective_move_with_effect AI_TARGET, EFFECT_ALWAYS_HIT, AI_Ret
    if_has_non_ineffective_move_with_effect AI_TARGET, EFFECT_VITAL_THROW, AI_Ret
    if_ability AI_USER, ABILITY_NO_GUARD, AI_Ret
    goto AI_CV_AccuracyDown_SkipMinus

AI_CV_AccuracyDown: @ 82DCF0C
    if_has_non_ineffective_move_with_effect AI_TARGET, EFFECT_ALWAYS_HIT, Score_Minus5
    if_has_non_ineffective_move_with_effect AI_TARGET, EFFECT_VITAL_THROW, Score_Minus5
    if_ability AI_USER, ABILITY_NO_GUARD, Score_Minus5
AI_CV_AccuracyDown_SkipMinus:
	if_user_can_probably_boost_safely Score_Plus2
	if_hp_less_than AI_USER, 70, AI_CV_AccuracyDown2
	if_hp_more_than AI_TARGET, 70, AI_CV_AccuracyDownIfOpponentCannotSwitch

AI_CV_AccuracyDown2:
	if_random_less_than 100, AI_CV_AccuracyDownIfOpponentCannotSwitch
	score -1
	
AI_CV_AccuracyDownIfOpponentCannotSwitch:
    if_stat_level_less_than AI_TARGET, STAT_ACC, 2, AI_CV_AccuracyDown3
    count_usable_party_mons AI_TARGET
    if_equal 0, AI_CV_AccuracyDown_OpponentCannotSwitch
    if_not_status3 AI_TARGET, STATUS3_ROOTED, AI_CV_AccuracyDown3
AI_CV_AccuracyDown_OpponentCannotSwitch:
    if_random_less_than 100, AI_CV_AccuracyDown3
    score +2
    if_random_less_than 100, AI_CV_AccuracyDown3
    score +2

AI_CV_AccuracyDown3:
	if_stat_level_more_than AI_TARGET, STAT_ACC, 4, AI_CV_AccuracyDown4
	if_random_less_than 80, AI_CV_AccuracyDown4
	score -2

AI_CV_AccuracyDown4:
	if_not_status AI_TARGET, STATUS1_TOXIC_POISON, AI_CV_AccuracyDown5
	if_random_less_than 70, AI_CV_AccuracyDown5
	score +2

AI_CV_AccuracyDown5:
	if_not_status3 AI_TARGET, STATUS3_LEECHSEED, AI_CV_AccuracyDown6
	if_random_less_than 70, AI_CV_AccuracyDown6
	score +2

AI_CV_AccuracyDown6:
	if_not_status3 AI_USER, STATUS3_ROOTED, AI_CV_AccuracyDown7
	if_random_less_than 128, AI_CV_AccuracyDown7
	score +1

AI_CV_AccuracyDown7:
	if_not_status2 AI_TARGET, STATUS2_CURSED, AI_CV_AccuracyDown8
	if_random_less_than 70, AI_CV_AccuracyDown8
	score +2

AI_CV_AccuracyDown8:
	if_hp_more_than AI_USER, 70, AI_CV_AccuracyDown_End
	if_stat_level_equal AI_TARGET, STAT_ACC, 6, AI_CV_AccuracyDown_End
	if_hp_less_than AI_USER, 40, AI_CV_AccuracyDown_ScoreDown2
	if_hp_less_than AI_TARGET, 40, AI_CV_AccuracyDown_ScoreDown2
	if_random_less_than 70, AI_CV_AccuracyDown_End

AI_CV_AccuracyDown_ScoreDown2:
	score -2

AI_CV_AccuracyDown_End:
	end

AI_CV_EvasionDown:
	if_hp_less_than AI_USER, 70, AI_CV_EvasionDown2
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 3, AI_CV_EvasionDown3

AI_CV_EvasionDown2:
	if_random_less_than 50, AI_CV_EvasionDown3
	score -2

AI_CV_EvasionDown3:
	if_hp_more_than AI_TARGET, 70, AI_CV_EvasionDown_End
	score -2

AI_CV_EvasionDown_4:
	if_stat_level_less_than AI_USER, STAT_ACC, 6, AI_CV_EvasionDown_5
	if_stat_level_less_than AI_TARGET, STAT_EVASION, 7, AI_CV_EvasionDown_6
	if_ability AI_USER, ABILITY_NO_GUARD, AI_CV_EvasionDown_6
AI_CV_EvasionDown_End:
	end
AI_CV_EvasionDown_5:
	score +1
	goto AI_CV_EvasionDown_End
AI_CV_EvasionDown_6:
	score -2
	goto AI_CV_EvasionDown_End

AI_CV_Haze:
	if_stat_level_more_than AI_USER, STAT_ATK, 7, AI_CV_Haze2
	if_stat_level_more_than AI_USER, STAT_DEF, 7, AI_CV_Haze2
	if_stat_level_more_than AI_USER, STAT_SPATK, 7, AI_CV_Haze2
	if_stat_level_more_than AI_USER, STAT_SPDEF, 7, AI_CV_Haze2
	if_stat_level_more_than AI_USER, STAT_EVASION, 7, AI_CV_Haze2
	if_stat_level_less_than AI_TARGET, STAT_ATK, 5, AI_CV_Haze2
	if_stat_level_less_than AI_TARGET, STAT_DEF, 5, AI_CV_Haze2
	if_stat_level_less_than AI_TARGET, STAT_SPATK, 5, AI_CV_Haze2
	if_stat_level_less_than AI_TARGET, STAT_SPDEF, 5, AI_CV_Haze2
	if_stat_level_less_than AI_TARGET, STAT_ACC, 5, AI_CV_Haze2
	goto AI_CV_Haze3

AI_CV_Haze2:
	if_random_less_than 50, AI_CV_Haze3
	score -3

AI_CV_Haze3:
	if_stat_level_more_than AI_TARGET, STAT_ATK, 7, AI_CV_Haze_Encourage
	if_stat_level_more_than AI_TARGET, STAT_DEF, 8, AI_CV_Haze_Encourage
	if_stat_level_more_than AI_TARGET, STAT_SPATK, 7, AI_CV_Haze_Encourage
	if_stat_level_more_than AI_TARGET, STAT_SPDEF, 8, AI_CV_Haze_Encourage
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 8, AI_CV_Haze_Encourage
	if_stat_level_less_than AI_USER, STAT_ATK, 4, AI_CV_Haze_Encourage
	if_stat_level_less_than AI_USER, STAT_DEF, 4, AI_CV_Haze_Encourage
	if_stat_level_less_than AI_USER, STAT_SPATK, 4, AI_CV_Haze_Encourage
	if_stat_level_less_than AI_USER, STAT_SPDEF, 4, AI_CV_Haze_Encourage
	if_stat_level_less_than AI_USER, STAT_ACC, 4, AI_CV_Haze_Encourage
	if_stat_level_more_than AI_TARGET, STAT_ATK, 6, AI_CV_Haze_ConsiderEncouraging
	if_stat_level_more_than AI_TARGET, STAT_DEF, 7, AI_CV_Haze_ConsiderEncouraging
	if_stat_level_more_than AI_TARGET, STAT_SPATK, 6, AI_CV_Haze_ConsiderEncouraging
	if_stat_level_more_than AI_TARGET, STAT_SPDEF, 7, AI_CV_Haze_ConsiderEncouraging
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 7, AI_CV_Haze_ConsiderEncouraging
	if_random_less_than 50, AI_CV_Haze_End
	score -1
	goto AI_CV_Haze_End
	
AI_CV_Haze_ConsiderEncouraging_SkipSpeedCheck:
	if_random_less_than 128, AI_CV_Haze_End
	goto Score_Plus1

AI_CV_Haze_ConsiderEncouraging:
	if_user_faster AI_CV_Haze_ConsiderEncouraging_SkipSpeedCheck
	if_target_will_be_faster_after_this_effect AI_CV_Haze_ConsiderEncouraging_SkipSpeedCheck
AI_CV_Haze_Encourage:
	if_random_less_than 50, Score_Plus1
	score +3

AI_CV_Haze_End:
	end

AI_CV_Bide:
	if_hp_more_than AI_USER, 90, AI_CV_Bide_End
	if_this_attack_might_be_the_last Score_Minus5
	score -2

AI_CV_Bide_End:
	end

AI_CV_Roar:
	if_stat_level_more_than AI_TARGET, STAT_ATK, 7, AI_CV_Roar3
	if_stat_level_more_than AI_TARGET, STAT_DEF, 8, AI_CV_Roar3
	if_stat_level_more_than AI_TARGET, STAT_SPATK, 7, AI_CV_Roar3
	if_stat_level_more_than AI_TARGET, STAT_SPDEF, 8, AI_CV_Roar3
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 8, AI_CV_Roar3
	if_stat_level_more_than AI_TARGET, STAT_ATK, 6, AI_CV_Roar2_CheckSpeedForPossibleDragonDance
	if_stat_level_more_than AI_TARGET, STAT_DEF, 7, AI_CV_Roar2
	if_stat_level_more_than AI_TARGET, STAT_SPATK, 6, AI_CV_Roar2
	if_stat_level_more_than AI_TARGET, STAT_SPDEF, 7, AI_CV_Roar2
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 7, AI_CV_Roar2
	if_not_side_affecting AI_TARGET, SIDE_STATUS_SPIKES, AI_CV_Roar_Discourage
	if_ability_might_be AI_TARGET, ABILITY_LEVITATE, AI_CV_Roar_SpikesWontFaintTheTarget
	if_type AI_TARGET, TYPE_FLYING, AI_CV_Roar_SpikesWontFaintTheTarget
	if_hp_condition TARGET_HAS_1_MAX_HP, Score_Plus2
	if_has_a_50_percent_hp_recovery_move AI_TARGET, AI_CV_Roar_SpikesWontFaintTheTarget
	get_hazards_count AI_TARGET, EFFECT_SPIKES
	if_equal 3, AI_CV_Roar_Spikes_3
	if_equal 2, AI_CV_Roar_Spikes_2
	if_equal 1, AI_CV_Roar_Spikes_1
	goto AI_CV_Roar_Discourage

AI_CV_Roar_SpikesWillFaintTheTarget:
	goto Score_Minus1

AI_CV_Roar_Spikes_3:
	if_hp_condition TARGET_CANNOT_USE_SUB, AI_CV_Roar_SpikesWillFaintTheTarget
	goto AI_CV_Roar_SpikesWontFaintTheTarget

AI_CV_Roar_Spikes_2:
	if_hp_less_than AI_TARGET, 16, AI_CV_Roar_SpikesWillFaintTheTarget
	goto AI_CV_Roar_SpikesWontFaintTheTarget

AI_CV_Roar_Spikes_1:
	if_hp_less_than AI_TARGET, 12, AI_CV_Roar_SpikesWillFaintTheTarget
AI_CV_Roar_SpikesWontFaintTheTarget:
	if_status AI_TARGET, STATUS1_TOXIC_POISON, AI_CV_Roar_Discourage
	if_status2 AI_TARGET, STATUS2_CURSED | STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION, AI_CV_Roar_Discourage
	if_status3 AI_TARGET, STATUS3_PERISH_SONG | STATUS3_LEECHSEED | STATUS3_YAWN, AI_CV_Roar_Discourage
	if_target_faster AI_CV_Roar_ConsiderRoarIfSpikesAndDamagingMovesAreWeak
	calculate_nhko AI_TARGET
	if_equal 1, AI_CV_Roar_Discourage
AI_CV_Roar_ConsiderRoarIfSpikesAndDamagingMovesAreWeak:
	get_hazards_count AI_TARGET, EFFECT_SPIKES
	if_equal 3, Score_Minus1
	if_equal 2, Score_Minus2
	if_equal 0, AI_CV_Roar_Discourage
	if_random_less_than 160, Score_Minus2
AI_CV_Roar_Discourage:
	score -3
	goto AI_CV_Roar_End

AI_CV_Roar2_CheckSpeedForPossibleDragonDance:
    if_stat_level_more_than AI_TARGET, STAT_SPEED, 6, AI_CV_Roar3
AI_CV_Roar2:
	if_random_less_than 128, AI_CV_Roar_End
AI_CV_Roar3:
	score +2
AI_CV_Roar_End:
	end

AI_CV_Conversion:
	if_hp_more_than AI_USER, 90, AI_CV_Conversion2
	score -2

AI_CV_Conversion2:
	get_turn_count
	if_equal 0, AI_CV_Conversion_End
	if_random_less_than 200, Score_Minus2

AI_CV_Conversion_End:
	end

AI_CV_HealWeather:
	get_weather
	if_equal AI_WEATHER_HAIL, AI_CV_HealWeather_ScoreDown2
	if_equal AI_WEATHER_RAIN, AI_CV_HealWeather_ScoreDown2
	if_equal AI_WEATHER_SANDSTORM, AI_CV_HealWeather_ScoreDown2
	goto AI_CV_Heal

AI_CV_HealWeather_ScoreDown2:
	score -2

AI_CV_Heal:
	if_perish_song_about_to_trigger AI_USER, Score_Minus8
	if_hp_equal AI_USER, 100, AI_CV_Heal3_PlentyOfHP
	if_target_faster AI_CV_Heal4
	
AI_CV_Heal2:
	if_hp_less_than AI_USER, 50, AI_CV_Heal5
	if_hp_more_than AI_USER, 80, AI_CV_Heal3_PlentyOfHP
	if_random_less_than 70, AI_CV_Heal5

AI_CV_Heal3_PlentyOfHP:
    if_status2 AI_USER, STATUS2_SUBSTITUTE, Score_Minus8
    if_stat_level_more_than AI_USER, STAT_EVASION, 9, Score_Minus8
    if_user_faster Score_Minus8
    calculate_nhko AI_TARGET | AI_NHKO_PESSIMISTIC
    if_more_than 4, Score_Minus8
    if_equal 4, Score_Minus5
    if_stat_level_more_than AI_USER, STAT_EVASION, 7, Score_Minus5
	score -3
	goto AI_CV_Heal_End

AI_CV_Heal4:
	if_hp_less_than AI_USER, 70, AI_CV_Heal5
    if_hp_more_than AI_USER, 90, AI_CV_Heal3_PlentyOfHP
	if_random_less_than 30, AI_CV_Heal5
	goto AI_CV_Heal3_PlentyOfHP

AI_CV_Heal5:
     if_next_turn_target_might_use_move_with_effect EFFECT_SNATCH, AI_CV_Heal5b
    goto AI_CV_Heal6
AI_CV_Heal5b:
	if_random_less_than 100, AI_CV_Heal_End

AI_CV_Heal6:
    if_hp_less_than AI_USER, 40, Score_Plus2
    calculate_nhko AI_TARGET
    if_more_than 3, AI_CV_Heal3_PlentyOfHP
    if_equal 3, AI_CV_Heal_End
	if_random_less_than 20, AI_CV_Heal_End
	score +2

AI_CV_Heal_End:
	end

AI_CV_Toxic: @ También lo usa Leech Seed
	if_ability_might_be AI_TARGET, ABILITY_WONDER_GUARD, Score_Plus2
	if_this_attack_might_be_the_last AI_CV_Toxic_FirstMinus1
	if_user_has_no_attacking_non_ineffective_moves AI_CV_Toxic3
	if_hp_more_than AI_USER, 50, AI_CV_Toxic2
	if_has_move_with_effect AI_USER, EFFECT_PROTECT, AI_CV_Toxic2
	if_random_less_than 50, AI_CV_Toxic2
AI_CV_Toxic_FirstMinus1:
	score -1

AI_CV_Toxic2:
	if_has_move_with_effect AI_TARGET, EFFECT_REST, AI_CV_Toxic_SecondMinus1
	if_has_a_50_percent_hp_recovery_move AI_TARGET, AI_CV_Toxic_SecondMinus1
	if_hp_more_than AI_TARGET, 50, AI_CV_Toxic3
	calculate_nhko
	if_more_than 3, AI_CV_Toxic3
	if_random_less_than 50, AI_CV_Toxic3
AI_CV_Toxic_SecondMinus1:
	score -1

AI_CV_Toxic3:
	calculate_nhko AI_TARGET
	if_less_than 3, AI_CV_Toxic_End
	if_more_than 4, AI_CV_Toxic4
	if_equal 3, AI_CV_Toxic3_SkipSpeedAndLeechSeedCheck
	if_user_faster AI_CV_Toxic4
	if_move MOVE_LEECH_SEED, AI_CV_Toxic4
AI_CV_Toxic3_SkipSpeedAndLeechSeedCheck:
	if_has_a_50_percent_hp_recovery_move AI_USER, AI_CV_Toxic4
	if_has_move_with_effect AI_USER, MOVE_REST, AI_CV_Toxic4
	if_has_move_with_effect AI_USER, EFFECT_PROTECT, AI_CV_Toxic4
	goto AI_CV_Toxic_End

AI_CV_Toxic4:
	if_random_less_than 60, AI_CV_Toxic_End
	if_has_move_with_effect AI_TARGET, EFFECT_REST, Score_Plus1
	if_has_a_50_percent_hp_recovery_move AI_TARGET, Score_Plus1
	score +2

AI_CV_Toxic_End:
	end

AI_CV_LightScreen:
  get_possible_categories_of_foes_attacks
  if_equal AI_NO_DAMAGING_MOVES, AI_CV_LightScreen_ScoreDown2
  if_equal AI_PHYSICAL_ONLY, AI_CV_LightScreen_ScoreDown2
  if_equal AI_ONLY_PHYSICAL_KNOWN, AI_CV_LightScreen_ScoreDown2
  if_equal AI_UNKNOWN_CATEGORIES_PROBABLY_PHYSICAL, AI_CV_LightScreen_ScoreDown2
  if_not_equal AI_UNKNOWN_CATEGORIES, AI_CV_LightScreen_End
	if_random_less_than 50, AI_CV_LightScreen_End

AI_CV_LightScreen_ScoreDown2:
	score -2

AI_CV_LightScreen_End:
	end

AI_CV_LightScreen_SpecialTypeList:
    .byte TYPE_FIRE
    .byte TYPE_WATER
    .byte TYPE_GRASS
    .byte TYPE_ELECTRIC
    .byte TYPE_PSYCHIC
    .byte TYPE_ICE
    .byte TYPE_DRAGON
    .byte TYPE_DARK
    .byte TYPE_FAIRY
    .byte -1

AI_CV_Rest:
	if_ability AI_USER, ABILITY_INSOMNIA, Score_Minus10
	if_ability AI_USER, ABILITY_VITAL_SPIRIT, Score_Minus10
	if_perish_song_about_to_trigger AI_USER, Score_Minus8
	if_target_faster AI_CV_Rest4
	if_hp_not_equal AI_USER, 100, AI_CV_Rest2
	score -8
	goto AI_CV_Rest_End

AI_CV_Rest2:
	if_hp_less_than AI_USER, 40, AI_CV_Rest6
	if_hp_more_than AI_USER, 50, AI_CV_Rest3
	if_random_less_than 70, AI_CV_Rest6

AI_CV_Rest3:
	score -7
	goto AI_CV_Rest_End

AI_CV_Rest4:
	if_hp_less_than AI_USER, 60, AI_CV_Rest6
	if_hp_more_than AI_USER, 70, AI_CV_Rest5
	if_random_less_than 50, AI_CV_Rest6

AI_CV_Rest5:
	score -5
	goto AI_CV_Rest_End

AI_CV_Rest6:
	 if_next_turn_target_might_use_move_with_effect EFFECT_SNATCH, AI_CV_Rest6b
     goto AI_CV_Rest7
AI_CV_Rest6b:
	if_random_less_than 50, AI_CV_Rest_End

AI_CV_Rest7:
	if_random_less_than 10, AI_CV_Rest_End
	score +3

AI_CV_Rest_End:
	end

AI_CV_OneHitKO:
	if_status3 AI_TARGET, STATUS3_ALWAYS_HITS, Score_Plus3
    if_ability AI_USER, ABILITY_NO_GUARD, Score_Plus3
    if_ability AI_TARGET, ABILITY_NO_GUARD, Score_Plus3
    if_has_move_with_effect AI_USER, EFFECT_LOCK_ON, Score_Minus3
	end

AI_CV_PartialTrap:
	if_status2 AI_TARGET, STATUS2_WRAPPED | STATUS2_MULTIPLETURNS | STATUS2_ESCAPE_PREVENTION, AI_CV_PartialTrap_End
  if_type AI_TARGET, TYPE_GHOST, AI_CV_PartialTrap_End
	if_target_might_have_a_sub_before_our_attack AI_CV_PartialTrap_End
	count_usable_party_mons AI_TARGET
	if_equal 0, AI_CV_PartialTrap_End
	if_this_attack_might_be_the_last AI_CV_PartialTrap_End
	if_has_move_with_effect AI_TARGET, EFFECT_ROAR, AI_CV_PartialTrap_IgnoreTrapUnlessUserCannotBePhazed
AI_CV_PartialTrap_UserCannotBePhazed:
	if_status AI_TARGET, STATUS1_TOXIC_POISON, AI_CV_PartialTrap_TargetReallyAffected
	if_status2 AI_TARGET, STATUS2_CURSED, AI_CV_PartialTrap_TargetReallyAffected
	if_status3 AI_TARGET, STATUS3_PERISH_SONG, AI_CV_PartialTrap_TargetReallyAffected
	if_status AI_TARGET, STATUS1_POISON | STATUS1_BURN, AI_CV_PartialTrap_TargetAffected
	if_status2 AI_TARGET, STATUS2_INFATUATION, AI_CV_PartialTrap_TargetAffected
	if_status3 AI_TARGET, STATUS3_LEECHSEED | STATUS3_YAWN, AI_CV_PartialTrap_TargetAffected
	goto AI_CV_PartialTrap_End

AI_CV_PartialTrap_IgnoreTrapUnlessUserCannotBePhazed:
	if_ability AI_USER, ABILITY_SUCTION_CUPS, AI_CV_PartialTrap_UserCannotBePhazed
	count_usable_party_mons AI_USER
	if_equal 0, AI_CV_PartialTrap_UserCannotBePhazed
	if_ability AI_USER, ABILITY_SOUNDPROOF, AI_CV_PartialTrap_IgnoreTrapIfPhazingMoveIsWhirlwind
	goto AI_CV_PartialTrap_End

AI_CV_PartialTrap_IgnoreTrapIfPhazingMoveIsWhirlwind:
	if_has_move AI_TARGET, MOVE_WHIRLWIND, AI_CV_PartialTrap_End
	goto AI_CV_PartialTrap_UserCannotBePhazed

AI_CV_PartialTrap_TargetReallyAffected:
	calculate_nhko AI_TARGET
	if_more_than 3, AI_CV_PartialTrap_ScorePlus1or2
	if_less_than 2, AI_CV_PartialTrap_End
	if_equal 2, AI_CV_PartialTrap_BalancedScenario
	if_has_move_with_effect AI_USER, EFFECT_PROTECT, AI_CV_PartialTrap_ScorePlus1or2
	if_has_a_50_percent_hp_recovery_move AI_USER, AI_CV_PartialTrap_ScorePlus1or2
	if_has_move_with_effect AI_USER, EFFECT_REST, AI_CV_PartialTrap_ScorePlus1or2
	goto AI_CV_PartialTrap_ScorePlus1

AI_CV_PartialTrap_TargetAffected:
	if_user_is_intoxicated_and_does_not_have_baton_pass AI_CV_PartialTrap_End
	if_status2 AI_USER, STATUS2_CURSED, AI_CV_PartialTrap_End
	if_status3 AI_USER, STATUS3_PERISH_SONG, AI_CV_PartialTrap_End
	calculate_nhko AI_TARGET | AI_NHKO_PESSIMISTIC
	if_more_than 3, AI_CV_PartialTrap_ScorePlus1
	if_less_than 3, AI_CV_PartialTrap_End
AI_CV_PartialTrap_BalancedScenario:
	if_user_is_intoxicated_and_does_not_have_baton_pass AI_CV_PartialTrap_End
	if_status2 AI_USER, STATUS2_CURSED, AI_CV_PartialTrap_End
	if_status3 AI_USER, STATUS3_PERISH_SONG, AI_CV_PartialTrap_End
	if_has_move_with_effect AI_USER, EFFECT_PROTECT, AI_CV_PartialTrap_ScorePlus1maybe
	if_has_a_50_percent_hp_recovery_move AI_USER, AI_CV_PartialTrap_ScorePlus1maybe
	if_has_move_with_effect AI_USER, EFFECT_REST, AI_CV_PartialTrap_ScorePlus1maybe
	goto AI_CV_PartialTrap_End

AI_CV_PartialTrap_ScorePlus1maybe:
	if_random_less_than 128, Score_Plus1
	goto AI_CV_PartialTrap_End

AI_CV_PartialTrap_ScorePlus1or2:
	if_random_less_than 128, Score_Plus2
	goto Score_Plus1

AI_CV_PartialTrap_ScorePlus1:
	score +1
AI_CV_PartialTrap_End:
	end

AI_CV_Trap:
	if_this_attack_might_be_the_last Score_Minus5
    if_has_move_with_effect AI_TARGET, EFFECT_ROAR, AI_CV_Trap_DontTrapUnlessUserCannotBePhazed
AI_CV_Trap_UserCannotBePhazed:
	if_status AI_TARGET, STATUS1_TOXIC_POISON, AI_CV_Trap2
	if_status2 AI_TARGET, STATUS2_CURSED, AI_CV_Trap2
	if_status3 AI_TARGET, STATUS3_PERISH_SONG, AI_CV_Trap2
	if_status2 AI_TARGET, STATUS2_INFATUATION, AI_CV_Trap2
	if_user_is_intoxicated_and_does_not_have_baton_pass Score_Minus5
	if_status2 AI_USER, STATUS2_CURSED, Score_Minus5
	if_status3 AI_USER, STATUS3_PERISH_SONG, Score_Minus5
	goto AI_CV_Trap_End

AI_CV_Trap_DontTrapUnlessUserCannotBePhazed:
    if_ability AI_USER, ABILITY_SUCTION_CUPS, AI_CV_Trap_UserCannotBePhazed
    count_usable_party_mons AI_USER
    if_equal 0, AI_CV_Trap_UserCannotBePhazed
    if_ability AI_USER, ABILITY_SOUNDPROOF, AI_CV_Trap_DontTrapIfPhazingMoveIsWhirlwind
    goto Score_Minus3

AI_CV_Trap_DontTrapIfPhazingMoveIsWhirlwind:
    if_has_move AI_TARGET, MOVE_WHIRLWIND, Score_Minus3
    goto AI_CV_Trap_UserCannotBePhazed

AI_CV_Trap2:
	if_random_less_than 128, AI_CV_Trap_End
	score +1

AI_CV_Trap_End:
	end

AI_CV_Swagger:
	if_has_move AI_USER, MOVE_PSYCH_UP, AI_CV_SwaggerHasPsychUp
	goto AI_CV_Confuse

AI_CV_Flatter:
	get_possible_categories_of_foes_attacks
	if_equal AI_PHYSICAL_ONLY, AI_CV_Confuse
	if_equal AI_ONLY_PHYSICAL_KNOWN, AI_CV_Confuse
	if_equal AI_UNKNOWN_CATEGORIES_PROBABLY_PHYSICAL, AI_CV_Confuse
	if_equal AI_NO_DAMAGING_MOVES, AI_CV_Confuse
	if_random_less_than 64, AI_CV_Confuse
	score -1

AI_CV_Confuse:
	if_ability_might_be AI_TARGET, ABILITY_WONDER_GUARD, Score_Plus1
	if_hp_more_than AI_TARGET, 70, AI_CV_Confuse_End
	if_hp_less_than AI_TARGET, 8, AI_CV_Confuse_End
	if_random_less_than 128, AI_CV_Confuse2
	score -1

AI_CV_Confuse2:
	if_target_faster AI_CV_Confuse2b
	calculate_nhko AI_TARGET
	if_equal 1, AI_CV_Confuse_End
AI_CV_Confuse2b:
	if_hp_more_than AI_TARGET, 50, AI_CV_Confuse_End
	score -1
	if_hp_more_than AI_TARGET, 30, AI_CV_Confuse_End
	score -1

AI_CV_Confuse_End:
	end

AI_CV_SwaggerHasPsychUp:
	if_stat_level_less_than AI_TARGET, STAT_ATK, 5, AI_CV_SwaggerHasPsychUp_Minus5 @ probablemente se le ha bajado por algo, mejor no subir
	if_stat_level_more_than AI_TARGET, STAT_ATK, 10, AI_CV_Confuse @ no tiene mucho efecto seguir subiendo el Ataque
	if_stat_level_more_than AI_USER, STAT_ATK, 10, AI_CV_Confuse @ no se puede aprovechar ninguna subida de Ataque al rival
@ Si se llega aquí, el usuario está a entre -6 y +4 y el objetivo entre -1 y +4
	if_stat_level_less_than AI_USER, STAT_ATK, 7, AI_CV_SwaggerHasPsychUp_Encourage
@ Usuario: +1 ~ +4, objetivo: -1 ~ +4
	if_stat_level_less_than AI_TARGET, STAT_ATK, 8, AI_CV_Confuse
	if_stat_level_more_than AI_TARGET, STAT_ATK, 8, AI_CV_SwaggerHasPsychUp_Encourage
@ Usuario: +1 ~ +4, objetivo: +2
	if_stat_level_more_than AI_USER, STAT_ATK, 8, AI_CV_Confuse
@ Usuario: +1 ~ +2, objetivo: +2
AI_CV_SwaggerHasPsychUp_Encourage:
	score +2
	get_turn_count
	if_not_equal 0, AI_CV_SwaggerHasPsychUp_End
	score +2
	goto AI_CV_SwaggerHasPsychUp_End

AI_CV_SwaggerHasPsychUp_Minus5:
	score -5

AI_CV_SwaggerHasPsychUp_End:
	end

AI_CV_Reflect:
  get_possible_categories_of_foes_attacks
  if_equal AI_NO_DAMAGING_MOVES, AI_CV_Reflect_ScoreDown2
  if_equal AI_SPECIAL_ONLY, AI_CV_Reflect_ScoreDown2
  if_equal AI_ONLY_SPECIAL_KNOWN, AI_CV_Reflect_ScoreDown2
  if_equal AI_UNKNOWN_CATEGORIES_PROBABLY_SPECIAL, AI_CV_Reflect_ScoreDown2
  if_not_equal AI_UNKNOWN_CATEGORIES, AI_CV_Reflect_End
	if_random_less_than 50, AI_CV_Reflect_End

AI_CV_Reflect_ScoreDown2:
	score -2

AI_CV_Reflect_End:
	end

AI_CV_Poison:
	if_has_move_with_effect AI_TARGET, EFFECT_REST, Score_Minus2
	if_ability_might_be AI_TARGET, ABILITY_WONDER_GUARD, Score_Plus1
	if_hp_less_than AI_USER, 50, AI_CV_Poison_ScoreDown1
	if_hp_more_than AI_TARGET, 50, AI_CV_Poison_End

AI_CV_Poison_ScoreDown1:
	score -1

AI_CV_Poison_End:
	end

AI_CV_Paralyze:
	if_ability_might_be AI_TARGET, ABILITY_WONDER_GUARD, Score_Minus2 @ mejor no paralizar por si se puede provocar otro cambio de estado
	if_target_faster AI_CV_Paralyze2
	if_hp_more_than AI_USER, 70, AI_CV_Paralyze_End
	score -1
	goto AI_CV_Paralyze_End

AI_CV_Paralyze2:
	if_random_less_than 20, AI_CV_Paralyze_End
	score +3

AI_CV_Paralyze_End:
	end

AI_CV_VitalThrow:
    if_target_faster AI_CV_AlwaysHit
	calculate_nhko AI_TARGET
	if_equal 1, Score_Minus2
	if_hp_more_than AI_USER, 60, AI_CV_VitalThrow_End
	if_hp_less_than AI_USER, 40, AI_CV_VitalThrow2
	if_random_less_than 180, AI_CV_VitalThrow_End

AI_CV_VitalThrow2:
	if_random_less_than 50, AI_CV_VitalThrow_End
	score -1

AI_CV_VitalThrow_End:
	end

AI_CV_Substitute:
	if_hp_condition USER_CANNOT_USE_SUB, AI_CV_Substitute_End
	if_status AI_USER, STATUS1_TOXIC_POISON, Score_Minus5
	if_status2 AI_USER, STATUS2_CURSED, Score_Minus5
	if_status3 AI_USER, STATUS3_PERISH_SONG, Score_Minus5
	goto AI_CV_Substitute_IsHealingAbilityActive
AI_CV_SubstituteStart:
	if_target_wont_attack_due_to_truant AI_CV_SubstitutePlus3Continue
	if_ability AI_USER, ABILITY_SPEED_BOOST, AI_CV_Substitute_SpeedBoost
	if_status AI_USER, STATUS1_PSN_ANY | STATUS1_BURN, AI_CV_SubstituteMinus1Continue
  count_usable_party_mons AI_TARGET
  if_equal 0, AI_CV_Substitute_TargetCannotEscape
  if_type AI_TARGET, TYPE_GHOST, AI_CV_Substitute_ConsiderIfLosingHPIsWorth
  if_status3 AI_TARGET, STATUS3_ROOTED, AI_CV_Substitute_TargetCannotEscape
	if_not_status2 AI_TARGET, STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION, AI_CV_Substitute_ConsiderIfLosingHPIsWorth
AI_CV_Substitute_TargetCannotEscape:
	if_status3 AI_TARGET, STATUS3_PERISH_SONG, AI_CV_SubstitutePlus3Continue
	if_status AI_TARGET, STATUS1_BURN | STATUS1_PSN_ANY, AI_CV_SubstitutePlus1Continue
	goto AI_CV_Substitute_ConsiderIfLosingHPIsWorth
AI_CV_SubstituteMinus1Continue:
    score -1
    goto AI_CV_Substitute_ConsiderIfLosingHPIsWorth
AI_CV_SubstitutePlus1Continue:
	score +1
	goto AI_CV_Substitute_ConsiderIfLosingHPIsWorth
AI_CV_SubstitutePlus3Continue:
	score +3
AI_CV_Substitute_ConsiderIfLosingHPIsWorth:
	if_hp_more_than AI_USER, 90, AI_CV_Substitute_HPNotAConcern
	if_hp_more_than AI_USER, 70, AI_CV_Substitute_HPAMinorConcern
	if_hp_more_than AI_USER, 50, AI_CV_Substitute_HPAConcern
	if_random_less_than 100, AI_CV_Substitute_HPAConcern
	score -1
AI_CV_Substitute_HPAConcern:
	if_random_less_than 100, AI_CV_Substitute_HPAMinorConcern
	score -1
AI_CV_Substitute_HPAMinorConcern:
	if_random_less_than 100, AI_CV_Substitute_HPNotAConcern
	score -1
AI_CV_Substitute_HPNotAConcern:
	if_target_faster AI_CV_Substitute_End
	if_target_probably_cannot_repeat_last_effect AI_CV_Substitute_End
	get_last_used_bank_move AI_TARGET
	get_move_effect_from_result
	if_equal EFFECT_SLEEP, AI_CV_Substitute_TargetAttemptedPermanentStatus
	if_equal EFFECT_TOXIC, AI_CV_Substitute_TargetAttemptedPermanentStatus
	if_equal EFFECT_POISON, AI_CV_Substitute_TargetAttemptedPermanentStatus
	if_equal EFFECT_PARALYZE, AI_CV_Substitute_TargetAttemptedPermanentStatus
	if_equal EFFECT_WILL_O_WISP, AI_CV_Substitute_TargetAttemptedPermanentStatus
	if_equal EFFECT_CONFUSE, AI_CV_Substitute_TargetAttemptedConfusion
	if_equal EFFECT_FLATTER, AI_CV_Substitute_TargetAttemptedConfusion
	if_equal EFFECT_SWAGGER, AI_CV_Substitute_TargetAttemptedConfusion
	if_equal EFFECT_LEECH_SEED, AI_CV_Substitute_TargetAttemptedLeechSeed
	if_equal EFFECT_COUNTER, AI_CV_Substitute_ConsiderALastBonus
	if_equal EFFECT_MIRROR_COAT, AI_CV_Substitute_ConsiderALastBonus
	goto AI_CV_Substitute_End

AI_CV_Substitute_TargetAttemptedPermanentStatus:
	if_not_status AI_USER, STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_PARALYSIS, AI_CV_Substitute_ConsiderALastBonus
	goto AI_CV_Substitute_End

AI_CV_Substitute_TargetAttemptedConfusion:
	if_not_status2 AI_USER, STATUS2_CONFUSION, AI_CV_Substitute_ConsiderALastBonus
	goto AI_CV_Substitute_End

AI_CV_Substitute_TargetAttemptedLeechSeed:
	if_status3 AI_USER, STATUS3_LEECHSEED, AI_CV_Substitute_End
AI_CV_Substitute_ConsiderALastBonus:
	if_random_less_than 100, AI_CV_Substitute_End
	score +1
	goto AI_CV_Substitute_End
AI_CV_Substitute_SpeedBoost:
	if_status2 AI_USER, STATUS2_SUBSTITUTE, AI_CV_Substitute_Minus3
	if_user_faster Score_Plus5
AI_CV_Substitute_Minus3:
	score -3
AI_CV_Substitute_End:
	end
	
@ Check for abilities that let the user spam Substitute under certain conditions
AI_CV_Substitute_IsHealingAbilityActive:
	if_ability AI_USER, ABILITY_ICE_BODY, AI_CV_Substitute_HealHail
	if_ability AI_USER, ABILITY_RAIN_DISH, AI_CV_Substitute_HealRain
	if_ability AI_USER, ABILITY_DRY_SKIN, AI_CV_Substitute_HealRain
	goto AI_CV_SubstituteStart

AI_CV_Substitute_HealHail:
	get_weather_at_the_end_of_turn
	if_equal AI_WEATHER_HAIL, AI_CV_SubstitutePlus1Continue
	end

AI_CV_Substitute_HealRain:
	get_weather_at_the_end_of_turn
	if_equal AI_WEATHER_RAIN, AI_CV_SubstitutePlus1Continue
	end

AI_CV_Recharge:
	if_target_might_have_a_sub_before_our_attack Score_Minus2
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, AI_CV_Recharge_ScoreDown1
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, AI_CV_Recharge_ScoreDown1
	if_target_faster AI_CV_Recharge2
	if_hp_more_than AI_USER, 40, AI_CV_Recharge_ScoreDown1
	goto AI_CV_Recharge_End

AI_CV_Recharge2:
	if_hp_less_than AI_USER, 60, AI_CV_Recharge_End

AI_CV_Recharge_ScoreDown1:
	score -1

AI_CV_Recharge_End:
	end

AI_CV_Disable:
	if_target_expected_to_be_statused_assuming_equal_priority AI_CV_Disable_OpponentIsNotExpectedToAttack
	if_status AI_TARGET, STATUS1_FREEZE, AI_CV_Disable_OpponentIsNotExpectedToAttack
	if_target_faster AI_CV_Disable_TargetIsFaster
AI_CV_Disable_OpponentIsNotExpectedToAttack:
	get_last_used_bank_move AI_TARGET
	if_equal MOVE_NONE, Score_Minus8
	get_move_effect_from_result
	if_in_bytes AI_CV_Disable_DiscouragedMoveEffectsToDisable, Score_Minus5
	if_not_in_bytes AI_CV_Disable_DiscouragedMoveEffectsToDisableWhenStatused, AI_CV_Disable_SkipEffectCheck
	if_status AI_USER, STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_PARALYSIS, Score_Minus5
AI_CV_Disable_SkipEffectCheck:
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, AI_CV_Disable2
	score +1
	goto AI_CV_Disable_End

AI_CV_Disable2:
	if_random_less_than 100, AI_CV_Disable_End
	score -1

AI_CV_Disable_End:
	end

AI_CV_Disable_TargetIsFaster:
	if_perish_song_about_to_trigger AI_TARGET, Score_Minus8
	goto AI_CV_Disable_End

AI_CV_Disable_DiscouragedMoveEffectsToDisable:
    .byte EFFECT_FAKE_OUT
    .byte EFFECT_RAIN_DANCE
    .byte EFFECT_SUNNY_DAY
    .byte EFFECT_HAIL
    .byte EFFECT_SANDSTORM
    .byte EFFECT_SAFEGUARD
    .byte EFFECT_REFLECT
    .byte EFFECT_LIGHT_SCREEN
    .byte EFFECT_WATER_SPORT
    .byte EFFECT_MUD_SPORT
    .byte EFFECT_MIST
    .byte EFFECT_MEAN_LOOK
    .byte EFFECT_PERISH_SONG
    .byte EFFECT_BELLY_DRUM
    .byte EFFECT_FUTURE_SIGHT
    .byte EFFECT_INGRAIN
    .byte EFFECT_IMPRISON
    .byte EFFECT_SPLASH
    .byte EFFECT_TELEPORT
    .byte EFFECT_MEMENTO
    .byte EFFECT_EXPLOSION
    .byte EFFECT_FOCUS_ENERGY
    .byte EFFECT_SKETCH
    .byte EFFECT_CAMOUFLAGE
    .byte -1

AI_CV_Disable_DiscouragedMoveEffectsToDisableWhenStatused:
    .byte EFFECT_POISON
    .byte EFFECT_TOXIC
    .byte EFFECT_WILL_O_WISP
    .byte EFFECT_PARALYZE
    .byte EFFECT_SLEEP
    .byte EFFECT_YAWN
    .byte -1



AI_CV_Counter:
    if_hp_condition USER_HAS_1_HP, Score_Minus10
    if_target_wont_attack_due_to_truant Score_Minus10
    if_perish_song_about_to_trigger AI_TARGET, Score_Minus10
    if_status2 AI_TARGET, STATUS2_RECHARGE, Score_Minus10
    if_status2 AI_TARGET, STATUS2_MULTIPLETURNS, AI_CV_Counter_TargetEncored
    if_any_move_encored AI_TARGET, AI_CV_Counter_TargetEncored
AI_CV_Counter_IgnoreEncore:
    get_possible_categories_of_foes_attacks
    if_equal AI_SPECIAL_ONLY, Score_Minus10
    if_equal AI_NO_DAMAGING_MOVES, Score_Minus10
    if_equal AI_UNKNOWN_CATEGORIES_PROBABLY_SPECIAL, Score_Minus5
    if_equal AI_ONLY_SPECIAL_KNOWN, Score_Minus5
    if_not_equal AI_UNKNOWN_CATEGORIES, AI_CV_Counter_PossiblyPhysical
    score -1
    if_random_less_than 128, AI_CV_Counter_PossiblyPhysical
    score -1
AI_CV_Counter_PossiblyPhysical:
    if_target_not_expected_to_sleep_during_next_turn AI_CV_Counter_TargetNotSleeping
    goto AI_CV_Counter_ScoreDown3
AI_CV_Counter_TargetNotSleeping:
	if_status AI_TARGET, STATUS1_FREEZE, AI_CV_Counter_ScoreDown3
	if_status2 AI_TARGET, STATUS2_INFATUATION, AI_CV_Counter_ScoreDown3
	if_status2 AI_TARGET, STATUS2_CONFUSION, AI_CV_Counter_ScoreDown3
	if_target_taunted AI_CV_Counter1
	if_status2 AI_TARGET, STATUS2_MULTIPLETURNS, AI_CV_Counter1
	if_any_move_encored AI_TARGET, AI_CV_Counter1
	if_user_has_revealed_move MOVE_COUNTER, AI_CV_Counter_MoveHasBeenRevealed
	goto AI_CV_Counter1
AI_CV_Counter_MoveHasBeenRevealed:
	get_last_used_bank_move AI_TARGET
	get_move_effect_from_result
	if_not_in_bytes AI_HighlySpammableRepeatableSetupEffects, AI_CV_Counter1
	score -1
	if_not_in_bytes AI_CV_ExcellentEffectsToUseAgainstCounterAndMirrorCoat, AI_CV_Counter1
	if_target_probably_cannot_repeat_last_effect AI_CV_Counter1
@ El rival de la IA podría boostearse hasta dar OHKO o hacerse casi intocable:
@ conviene no usar este ataque salvo si se puede aguantar un golpe por Sturdy o sash;
@ y aun así conviene no usarlos siempre porque el rival podría agotar los PP,
@ por lo que se considera una pequeña probabilidad (6,25%) de ahorrar un PP
@ que puede provocar que los PP de este movimiento terminen después si ambos tienen 32 PP.
@ La probabilidad de que esto suceda alguna vez en al menos 32 oportunidades es de un 87,3%
	if_in_bytes AI_CV_EvasionUpEffects, AI_CV_Counter_ScoreDown3
	if_random_less_than 16, AI_CV_Counter_ScoreDown3
	if_hp_less_than AI_USER, 100, AI_CV_Counter_NoSturdyOrSash
	if_ability AI_USER, ABILITY_STURDY, AI_CV_Counter1
	if_holds_item AI_USER, ITEM_FOCUS_SASH, AI_CV_Counter1
AI_CV_Counter_NoSturdyOrSash:
@ Si el rival está a +6 y aun así la IA no ve venir un OHKO,
@ tiene un 46,875% de considerar usar este ataque cada turno.
@ Esto permite que, probablemente, no se agoten los PP de este movimiento
@ antes que los de Meditate o Howl, o los de otros ataques con 32 PP
@ (lo que incluye SD, NP, QD, BU, CM, DD) ante un rival con Pressure
	if_stat_level_less_than AI_TARGET, STAT_ATK, 12, AI_CV_Counter_ScoreDown3
	calculate_nhko AI_TARGET | AI_NHKO_PESSIMISTIC
	if_equal 1, AI_CV_Counter_ScoreDown3
	if_random_less_than 128, AI_CV_Counter_ScoreDown3
AI_CV_Counter1:
	if_hp_more_than AI_USER, 30, AI_CV_Counter2
	if_random_less_than 10, AI_CV_Counter2
	score -1

AI_CV_Counter2:
	if_hp_more_than AI_USER, 50, AI_CV_Counter3
	if_random_less_than 100, AI_CV_Counter3
	score -1

AI_CV_Counter3:
	if_status2 AI_TARGET, STATUS2_MULTIPLETURNS, AI_CV_Counter3Plus1Continue
	if_any_move_encored AI_TARGET, AI_CV_Counter3PossiblePlus1Continue
    if_has_move AI_USER, MOVE_MIRROR_COAT, AI_CV_Counter6
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, AI_CV_Counter5
	if_target_not_taunted AI_CV_Counter4
AI_CV_Counter3PossiblePlus1Continue:
	if_random_less_than 100, AI_CV_Counter4
 AI_CV_Counter3Plus1Continue:
	score +1

AI_CV_Counter4:
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_not_in_bytes AI_CV_Counter_PhysicalTypeList, AI_CV_Counter_ScoreDown3
	if_random_less_than 100, AI_CV_Counter_End
	score +1
	goto AI_CV_Counter_End

AI_CV_Counter5:
	if_status2 AI_TARGET, STATUS2_MULTIPLETURNS, AI_CV_Counter5PossiblePlus1Continue
	if_any_move_encored AI_TARGET, AI_CV_Counter5PossiblePlus1Continue
	if_target_not_taunted AI_CV_Counter6
AI_CV_Counter5PossiblePlus1Continue:
	if_random_less_than 100, AI_CV_Counter6
	score +1

AI_CV_Counter6:
	end

AI_CV_Counter_TargetEncored:
	get_last_used_bank_move AI_TARGET
	if_equal MOVE_FAKE_OUT, Score_Minus10
	get_move_power_from_result
	if_equal 0, Score_Minus10
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_not_in_bytes AI_CV_Counter_PhysicalTypeList, Score_Minus10
	goto AI_CV_Counter_IgnoreEncore

AI_CV_Counter_ScoreDown3:
	score -3

AI_CV_Counter_End:
	end

AI_CV_Counter_PhysicalTypeList:
    .byte TYPE_NORMAL
    .byte TYPE_FIGHTING
    .byte TYPE_FLYING
    .byte TYPE_POISON
    .byte TYPE_GROUND
    .byte TYPE_ROCK
    .byte TYPE_BUG
    .byte TYPE_GHOST
    .byte TYPE_STEEL
    .byte -1

AI_CV_Encore:
    if_target_faster AI_CV_Encore_TargetIsFaster
    get_last_used_bank_move AI_TARGET
    if_equal MOVE_NONE, Score_Minus8
    if_equal MOVE_ENCORE, Score_Minus8      @ resulta que falla
    if_equal MOVE_STRUGGLE, Score_Minus8
    if_equal MOVE_MIRROR_MOVE, Score_Minus8
    if_equal MOVE_SKETCH, Score_Minus8
    if_target_probably_cannot_repeat_last_effect AI_CV_Encore_EffectCannotBeRepeated
    get_move_effect_from_result
    if_not_in_bytes AI_CV_Encore_EncouragedMovesToEncore, AI_CV_Encore_ScoreDown2
AI_CV_Encore_Encourage:
    if_random_less_than 30, AI_CV_Encore_End
    score +3
    goto AI_CV_Encore_End

@ Si no puede repetir el último movimiento y no es por PP, tirar Encore obligará al rival a usar Struggle.
@ Aquí tratar de averiguar por qué falla, según eso se aprovecha o no.
@ Se comprueba todo lo necesario excepto Imprison, pero parece improbable que sea Imprison
AI_CV_Encore_EffectCannotBeRepeated:
	if_status2 AI_TARGET, STATUS2_TORMENT, AI_CV_Encore_Encourage
	if_target_not_taunted AI_CV_Encore_EffectCannotBeRepeated_NoTaunt
	get_move_power_from_result
	if_equal 0, AI_CV_Encore_Encourage @ es Taunt lo que impide usarlo
AI_CV_Encore_EffectCannotBeRepeated_NoTaunt:
	if_any_move_disabled AI_TARGET, AI_CV_Encore_Encourage @ puede ser Disable lo que le impide repetir ataque
	goto Score_Minus8

AI_CV_Encore_TargetIsFaster:
    if_perish_song_about_to_trigger AI_TARGET, Score_Minus5
    get_last_used_bank_move AI_TARGET
    if_not_equal MOVE_NONE, AI_CV_Encore_TargetIsFaster_TargetHasAttackedOrIsExpectedToAttack
    if_status AI_TARGET, STATUS1_FREEZE, Score_Minus5
    if_target_not_expected_to_sleep_during_next_turn AI_CV_Encore_TargetIsFaster_TargetHasAttackedOrIsExpectedToAttack
    goto Score_Minus5

AI_CV_Encore_TargetIsFaster_TargetHasAttackedOrIsExpectedToAttack:
    if_this_attack_might_be_the_last Score_Minus5
    if_ability AI_USER, ABILITY_SHADOW_TAG, AI_CV_Encore_Encourage
@ En general conviene poco usar Encore en pokes lentos
AI_CV_Encore_ScoreDown2:
    score -2
AI_CV_Encore_End:
    end

AI_CV_Encore_EncouragedMovesToEncore:
    .byte EFFECT_DREAM_EATER
    .byte EFFECT_ATTACK_UP
    .byte EFFECT_DEFENSE_UP
    .byte EFFECT_SPEED_UP
    .byte EFFECT_SPECIAL_ATTACK_UP
    .byte EFFECT_HAZE
    .byte EFFECT_ROAR
    .byte EFFECT_CONVERSION
    .byte EFFECT_TOXIC
    .byte EFFECT_LIGHT_SCREEN
    .byte EFFECT_REST
    .byte EFFECT_SUPER_FANG
    .byte EFFECT_SPECIAL_DEFENSE_UP_2
    .byte EFFECT_CONFUSE
    .byte EFFECT_POISON
    .byte EFFECT_PARALYZE
    .byte EFFECT_LEECH_SEED
    .byte EFFECT_SPLASH
    .byte EFFECT_TELEPORT
    .byte EFFECT_ATTACK_UP_2
    .byte EFFECT_CONVERSION_2
    .byte EFFECT_LOCK_ON
    .byte EFFECT_HEAL_BELL
    .byte EFFECT_MEAN_LOOK
    .byte EFFECT_NIGHTMARE
    .byte EFFECT_PROTECT
    .byte EFFECT_SKILL_SWAP
    .byte EFFECT_FORESIGHT
    .byte EFFECT_PERISH_SONG
    .byte EFFECT_SANDSTORM
    .byte EFFECT_ENDURE
    .byte EFFECT_SWAGGER
    .byte EFFECT_ATTRACT
    .byte EFFECT_SAFEGUARD
    .byte EFFECT_RAIN_DANCE
    .byte EFFECT_SUNNY_DAY
    .byte EFFECT_BELLY_DRUM
    .byte EFFECT_PSYCH_UP
    .byte EFFECT_FUTURE_SIGHT
    .byte EFFECT_FAKE_OUT
    .byte EFFECT_STOCKPILE
    .byte EFFECT_SPIT_UP
    .byte EFFECT_SWALLOW
    .byte EFFECT_HAIL
    .byte EFFECT_TORMENT
    .byte EFFECT_WILL_O_WISP
    .byte EFFECT_FOLLOW_ME
    .byte EFFECT_CHARGE
    .byte EFFECT_TRICK
    .byte EFFECT_ROLE_PLAY
    .byte EFFECT_INGRAIN
    .byte EFFECT_RECYCLE
    .byte EFFECT_KNOCK_OFF
    .byte EFFECT_IMPRISON
    .byte EFFECT_REFRESH
    .byte EFFECT_GRUDGE
    .byte EFFECT_TEETER_DANCE
    .byte EFFECT_MUD_SPORT
    .byte EFFECT_WATER_SPORT
    .byte EFFECT_DRAGON_DANCE
    .byte EFFECT_CAMOUFLAGE
	.byte EFFECT_QUIVER_DANCE
   	.byte EFFECT_COIL
    .byte EFFECT_SPECIAL_ATTACK_UP_2
    .byte EFFECT_SPECIAL_ATTACK_UP_3
    .byte EFFECT_SPEED_UP_2
    .byte EFFECT_MEMENTO
    .byte EFFECT_EXPLOSION
    .byte EFFECT_FOCUS_ENERGY
    .byte -1

AI_CV_PainSplit:
	if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_hp_less_than AI_TARGET, 80, AI_CV_PainSplit_ScoreDown3
	if_target_faster AI_CV_PainSplit2
	if_hp_more_than AI_USER, 40, AI_CV_PainSplit_ScoreDown3
	score +1
	goto AI_CV_PainSplit_End

AI_CV_PainSplit2:
	if_hp_more_than AI_USER, 60, AI_CV_PainSplit_ScoreDown3
	score +1
	goto AI_CV_PainSplit_End

AI_CV_PainSplit_ScoreDown3:
	score -3

AI_CV_PainSplit_End:
	end

AI_CV_Snore:
    if_not_expected_to_sleep AI_CV_Snore_End
    score +8
AI_CV_Snore_End:
    end

AI_CV_LockOn:
	if_doesnt_have_move AI_USER, MOVE_SPORE, AI_CV_LockOn_SkipMinus1ForSpore
	if_target_expected_to_be_statused_assuming_equal_priority AI_CV_LockOn_SkipMinus1ForSpore
	score -1
AI_CV_LockOn_SkipMinus1ForSpore:
	if_perish_song_about_to_trigger AI_USER, Score_Minus5
	if_doesnt_have_non_ineffective_move_with_effect AI_USER, EFFECT_OHKO, AI_CV_LockOn_NoChanceToOHKOInFreeTurn
	if_ability_might_be AI_TARGET, ABILITY_STURDY, AI_CV_LockOn_NoChanceToOHKOInFreeTurn
	if_level_cond AI_LEVEL_IS_LESS_THAN_TARGETS, AI_CV_LockOn_NoChanceToOHKOInFreeTurn
    if_free_setup_turn Score_Plus2
AI_CV_LockOn_NoChanceToOHKOInFreeTurn:
	if_status AI_TARGET, STATUS1_FREEZE, AI_CV_LockOn_TargetMightNotAttackNextTurn
	if_status2 AI_TARGET, STATUS2_CONFUSION | STATUS2_INFATUATION, AI_CV_LockOn_TargetMightNotAttackNextTurn
	if_target_not_expected_to_sleep_during_next_turn AI_CV_LockOn_TargetShouldHaveNoProblemAttacking
AI_CV_LockOn_TargetMightNotAttackNextTurn:
	if_this_attack_might_be_the_last Score_Minus3
	goto AI_CV_LockOn_CalculateNHKOincludingOHKOmoves

AI_CV_LockOn_TargetShouldHaveNoProblemAttacking:
	if_this_attack_might_be_the_last Score_Minus5
AI_CV_LockOn_CalculateNHKOincludingOHKOmoves:
	if_ability_might_be AI_TARGET, ABILITY_STURDY, AI_CV_LockOn_CalculateNHKO
	if_level_cond AI_LEVEL_IS_LESS_THAN_TARGETS, AI_CV_LockOn_CalculateNHKO
	if_has_non_ineffective_move_with_effect AI_USER, EFFECT_OHKO, AI_CV_LockOn_SkipMinus1ForNotDoingEnoughDamage
AI_CV_LockOn_CalculateNHKO:
	calculate_nhko
	if_more_than 2, Score_Minus3
	if_equal 1, AI_CV_LockOn_SkipMinus1ForNotDoingEnoughDamage
	score -1
AI_CV_LockOn_SkipMinus1ForNotDoingEnoughDamage:
	if_random_less_than 128, AI_CV_LockOn_End
	score +2

AI_CV_LockOn_End:
	end

AI_CV_SleepTalk:
    if_not_expected_to_sleep Score_Minus8
    score +10
    end

AI_CV_Grudge:
	score -2
	if_status2 AI_USER, STATUS2_SUBSTITUTE, Score_Minus3
	if_target_faster AI_CV_Grudge_CheckIfThisAttackMightBeTheLast
	if_status2 AI_TARGET, STATUS2_RECHARGE, Score_Minus3
	if_hp_less_than AI_USER, 100, AI_CV_Grudge_CheckIfThisAttackMightBeTheLast
	if_ability AI_USER, ABILITY_STURDY, Score_Minus3
	if_holds_item AI_USER, ITEM_FOCUS_SASH, Score_Minus3
AI_CV_Grudge_CheckIfThisAttackMightBeTheLast:
	if_this_attack_might_be_the_last AI_CV_Grudge_End
	goto Score_Minus3
AI_CV_Grudge_End:
	end

AI_CV_DestinyBond:
	score -1
	if_status2 AI_USER, STATUS2_SUBSTITUTE, Score_Minus3
	if_target_faster AI_CV_DestinyBond_TargetIsFaster
	if_status2 AI_TARGET, STATUS2_RECHARGE, Score_Minus3
	if_hp_less_than AI_USER, 100, AI_CV_DestinyBond_SkipSturdyOrSashCheck
	if_ability AI_USER, ABILITY_STURDY, Score_Minus3
	if_holds_item AI_USER, ITEM_FOCUS_SASH, Score_Minus3
AI_CV_DestinyBond_SkipSturdyOrSashCheck:
	if_status2 AI_TARGET, STATUS2_MULTIPLETURNS, AI_CV_DestinyBond_SlowerTargetIsInMultiturnAttack
	if_any_move_encored AI_TARGET,AI_CV_DestinyBond_SlowerTargetIsEncored
AI_CV_DestinyBond_SlowerTargetNotEncoredInADamagelessMove:
	if_user_has_revealed_move MOVE_DESTINY_BOND, AI_CV_DestinyBond_MoveHasBeenRevealed
	goto AI_CV_DestinyBond_1

AI_CV_DestinyBond_SlowerTargetIsEncored:
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, Score_Minus3
	goto AI_CV_DestinyBond_SlowerTargetNotEncoredInADamagelessMove

AI_CV_DestinyBond_SlowerTargetIsInMultiturnAttack:
	calculate_nhko AI_TARGET
	if_more_than 2, Score_Minus3 @ ni con crítico es KO
	if_equal 2, Score_Minus1
	count_usable_party_mons AI_USER
	if_equal 0, AI_CV_DestinyBond_SlowerTargetIsInMultiturnAttack_ThisIsOurLastMon
	count_usable_party_mons AI_TARGET
	if_equal 0, Score_Plus4
	if_more_than 2, Score_Plus2
AI_CV_DestinyBond_SlowerTargetIsInMultiturnAttack_SacrificeWorth:
	if_status AI_TARGET, STATUS3_SEMI_INVULNERABLE, Score_Plus3
	goto Score_Plus2

AI_CV_DestinyBond_SlowerTargetIsInMultiturnAttack_ThisIsOurLastMon:
	count_usable_party_mons AI_TARGET
	if_equal 0, AI_CV_DestinyBond_SlowerTargetIsInMultiturnAttack_SacrificeWorth
	goto Score_Minus1

@ El rival sabe que tenemos Destiny Bond: no hay sorpresa posible.
@ Conviene reducir el uso de Destiny Bond para evitar fundir los PP
@ y para evitar que el rival se aproveche de que la IA pierde el tiempo,
@ boosteándose o metiendo Spikes por ejemplo.
@ Para ello, una vez que la IA revela Destiny Bond,
@ la IA tiene un 20% de no considerar usarlo cada turno si el rival usó un movimiento de daño,
@ y un 70% de no considerar usarlo cada turno si usó uno que no es de daño o acaba de entrar.
@ El tener un 30% de tirar Destiny Bond a partir del segundo hace que los 7 PP restantes de
@ Destiny Bond se acaben poco antes que unos supuestos 23 PP de un ataque del oponente.
AI_CV_DestinyBond_MoveHasBeenRevealed:
	is_first_turn_for AI_TARGET
	if_equal 1, AI_CV_DestinyBond_MoveHasBeenRevealed_TargetDidNotAttack
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, AI_CV_DestinyBond_MoveHasBeenRevealed_TargetDidNotAttack
	if_random_less_than 50, Score_Minus3 @ ~20% de no tirar Destiny Bond
	goto AI_CV_DestinyBond_1

AI_CV_DestinyBond_TargetIsFaster:
	if_this_attack_might_be_the_last AI_CV_DestinyBond_End
	goto Score_Minus3

AI_CV_DestinyBond_MoveHasBeenRevealed_TargetDidNotAttack:
	if_random_less_than 180, Score_Minus3 @ ~70% de no tirar Destiny Bond
AI_CV_DestinyBond_1:
	if_this_attack_might_be_the_last Score_Plus3
	if_hp_more_than AI_USER, 50, AI_CV_DestinyBond_End
	if_random_less_than 160, AI_CV_DestinyBond2
	score +1

AI_CV_DestinyBond2:
	if_hp_more_than AI_USER, 30, AI_CV_DestinyBond_End
	if_random_less_than 128, AI_CV_DestinyBond_End
	score +1

AI_CV_DestinyBond_End:
	end

AI_CV_Flail:
	if_target_faster AI_CV_Flail2
	if_hp_more_than AI_USER, 33, AI_CV_Flail_ScoreDown1
	if_hp_more_than AI_USER, 20, AI_CV_Flail_End
	if_hp_less_than AI_USER, 8, AI_CV_Flail_ScoreUp1
	goto AI_CV_Flail3

AI_CV_Flail2:
	if_hp_more_than AI_USER, 60, AI_CV_Flail_ScoreDown1
	if_hp_more_than AI_USER, 40, AI_CV_Flail_End
	goto AI_CV_Flail3

AI_CV_Flail_ScoreUp1:
	score +1

AI_CV_Flail3:
	if_random_less_than 100, AI_CV_Flail_End
	score +1
	goto AI_CV_Flail_End

AI_CV_Flail_ScoreDown1:
	score -1

AI_CV_Flail_End:
	end

@ Recuérdese que if_status_in_party excluye al poke actual	
AI_CV_HealBell:
    if_this_attack_might_be_the_last AI_CV_HealBell_ConsiderSacrificeIfNothingElseToDo
    if_status_in_party AI_USER, STATUS1_TOXIC_POISON | STATUS1_FREEZE | STATUS1_SLEEP, Score_Plus1
    if_status_in_party AI_USER, STATUS1_PARALYSIS | STATUS1_BURN, AI_CV_HealBell_End
    if_not_status AI_USER, STATUS1_TOXIC_POISON, AI_CV_HealBell_NoToxic
    if_status2 AI_USER, STATUS2_SUBSTITUTE, AI_CV_HealBell_End
    @ Si nos pueden repetir Toxic y dejarnos sin PP, mejor no usar Heal Bell
    if_doesnt_have_move_with_effect AI_TARGET, EFFECT_TOXIC, AI_CV_HealBell_End
    if_status AI_USER, 0xC00, Score_Minus1 @ Toxic bastante avanzado: tratará de curarse si no encuentra cambio
AI_CV_HealBell_NoToxic:
    if_status_in_party AI_USER, STATUS1_ANY & ~(STATUS1_POISON | STATUS1_BURN), Score_Minus1
    if_status_in_party AI_USER, STATUS1_ANY & ~(STATUS1_POISON), Score_Minus2
    if_not_status AI_USER, STATUS1_PARALYSIS, AI_CV_HealBell_NoParalysis
    if_target_will_be_faster_after_this_effect AI_CV_HealBell_NoParalysis
    @ Si nos pueden causar otro status o repetir la parálisis, mejor no usar Heal Bell
    @ (no tiene en cuenta posibles inmunidades)
    if_has_move_with_effect AI_TARGET, EFFECT_TOXIC, AI_CV_HealBell_NoParalysis
    if_has_move_with_effect AI_TARGET, EFFECT_SLEEP, AI_CV_HealBell_NoParalysis
    if_doesnt_have_move_with_effect AI_TARGET, EFFECT_PARALYZE, Score_Minus2
AI_CV_HealBell_NoParalysis:
    if_status_in_party AI_USER, STATUS1_ANY, Score_Minus5
    if_status AI_USER, STATUS1_ANY, Score_Minus8
    goto Score_Minus10

AI_CV_HealBell_End:
    end

@ Si el poke de la IA ve que corre peligro y no encuentra un cambio aceptable
@ (o si no puede cambiar), puede tratar de curar status importantes del equipo
AI_CV_HealBell_ConsiderSacrificeIfNothingElseToDo:
    if_status_in_party AI_USER, STATUS1_TOXIC_POISON | STATUS1_FREEZE | STATUS1_SLEEP | STATUS1_PARALYSIS, Score_Minus5
    if_status_in_party AI_USER, STATUS1_ANY, Score_Minus8
    goto Score_Minus10


AI_CV_Thief:
    if_holds_item AI_USER, ITEM_NONE, AI_CV_Thief_UserHasNoItem
    goto AI_CV_Thief_End
AI_CV_Thief_UserHasNoItem:
    if_trick_fails_in_this_type_of_battle AI_CV_Thief_End
    if_target_might_have_a_sub_before_our_attack AI_CV_Thief_End
    if_ability_might_be AI_TARGET, ABILITY_STICKY_HOLD, AI_CV_Thief_End
    get_hold_effect AI_TARGET
    if_in_bytes AI_CV_Thief_EncourageItemsToSteal, AI_CV_Thief_ScorePlus2
    goto AI_CV_Thief_End

AI_CV_Thief_ScorePlus2:
	score +2

AI_CV_Thief_End:
	end

AI_CV_Thief_EncourageItemsToSteal:
    .byte HOLD_EFFECT_CURE_SLP
    .byte HOLD_EFFECT_CURE_STATUS
    .byte HOLD_EFFECT_RESTORE_HP
    .byte HOLD_EFFECT_EVASION_UP
    .byte HOLD_EFFECT_LEFTOVERS
    .byte HOLD_EFFECT_LIGHT_BALL
    .byte HOLD_EFFECT_THICK_CLUB
    .byte HOLD_EFFECT_CHOICE_BAND
    .byte HOLD_EFFECT_CHOICE_SCARF
    .byte HOLD_EFFECT_CHOICE_SPECS
	.byte HOLD_EFFECT_RESTORE_PCT_HP @ SITRUS BERRY UPDATE GEN
    .byte HOLD_EFFECT_HEART_SCALE
    .byte HOLD_EFFECT_STICK
    .byte HOLD_EFFECT_TINY_MUSHROOM
    .byte HOLD_EFFECT_BIG_MUSHROOM
    .byte HOLD_EFFECT_PREVENT_EVOLVE @ EVERSTONE
    .byte HOLD_EFFECT_YELLOW_FLUTE
    .byte HOLD_EFFECT_BLUE_FLUTE
    .byte HOLD_EFFECT_RED_FLUTE
    .byte HOLD_EFFECT_LUCKY_PUNCH
    .byte HOLD_EFFECT_POKE_DOLL
    .byte HOLD_EFFECT_FLUFFY_TAIL
    .byte HOLD_EFFECT_CAN_ALWAYS_RUN @ SMOKE BALL
    .byte HOLD_EFFECT_HAPPINESS_UP @ SOOTHE BELL
	.byte HOLD_EFFECT_DEEP_SEA_SCALE
	.byte HOLD_EFFECT_DEEP_SEA_TOOTH
	.byte HOLD_EFFECT_SOUL_DEW
    .byte -1

AI_CV_Curse:
	if_type AI_USER, TYPE_GHOST, AI_CV_Curse_Ghost
	if_status3 AI_USER, STATUS3_PERISH_SONG, Score_Minus5
	if_user_is_intoxicated_and_does_not_have_baton_pass Score_Minus5
	if_has_move_with_effect AI_USER, EFFECT_BATON_PASS, AI_CV_Curse_ConsiderSetupEagerly
	calculate_nhko
	if_less_than 3, AI_CV_Curse_ConsiderSetupEagerly
	if_more_than 3, AI_CV_Curse_FreeSetupNotWorth
	if_stat_level_more_than AI_USER, STAT_ATK, 8, AI_CV_Curse_FreeSetupNotWorth
	if_stat_level_less_than AI_USER, STAT_ATK, 3, AI_CV_Curse_FreeSetupNotWorth
	if_user_can_probably_boost_safely Score_Plus2
	goto AI_CV_Curse_FreeSetupNotWorth_Minus2

AI_CV_Curse_ConsiderSetupEagerly:
	if_user_can_probably_boost_safely Score_Plus5
	goto AI_CV_Curse_SkipFreeSetupCheck

AI_CV_Curse_FreeSetupNotWorth:
	if_user_can_probably_boost_safely AI_CV_Curse_SkipFreeSetupCheck
AI_CV_Curse_FreeSetupNotWorth_Minus2:
	score -2
AI_CV_Curse_SkipFreeSetupCheck:
    if_user_faster AI_CV_Curse_CheckIfThisAttackMightBeTheLast
    get_possible_categories_of_foes_attacks
    if_equal AI_SPECIAL_ONLY, AI_CV_Curse_CheckIfThisAttackMightBeTheLast
    if_equal AI_UNKNOWN_CATEGORIES_PROBABLY_SPECIAL, AI_CV_Curse_CheckIfThisAttackMightBeTheLast
    if_equal AI_ONLY_SPECIAL_KNOWN, AI_CV_Curse_CheckIfThisAttackMightBeTheLast
    if_stat_level_less_than AI_USER, STAT_DEF, 8, AI_CV_Curse_DoNotCheckIfThisAttackMightBeTheLast
AI_CV_Curse_CheckIfThisAttackMightBeTheLast:
    if_this_attack_might_be_the_last Score_Minus5
AI_CV_Curse_DoNotCheckIfThisAttackMightBeTheLast:
	if_stat_level_more_than AI_USER, STAT_DEF, 9, AI_CV_Curse_End
	if_random_less_than 128, AI_CV_Curse2
	score +1

AI_CV_Curse2:
	if_stat_level_more_than AI_USER, STAT_DEF, 7, AI_CV_Curse_End
	if_random_less_than 128, AI_CV_Curse_End
	score +1
	goto AI_CV_Curse_End

AI_CV_Curse_Ghost:
	if_target_might_have_a_sub_before_our_attack Score_Minus10
	if_status2 AI_TARGET, STATUS2_CURSED, Score_Minus5
	if_hp_more_than AI_USER, 80, AI_CV_Curse_End
	score -1
AI_CV_Curse_End:
	end

AI_CV_Protect:
	get_protect_count AI_USER
	if_more_than 1, AI_CV_Protect_ScoreDown5
    if_ability AI_TARGET, ABILITY_TRUANT, AI_CV_Protect_MessWithTruant
    if_status3 AI_TARGET, STATUS3_SEMI_INVULNERABLE, AI_CV_Protect_OpponentIsSemiInvulnerable
    if_not_status2 AI_TARGET, STATUS2_MULTIPLETURNS, AI_CV_Protect_OpponentIsNotInAMultiturnAttack
    if_target_faster AI_CV_Protect_FasterOpponentIsCharging

@ La IA es más rápida: se protege si recibe OHKO y no puede meterlo antes
    calculate_nhko AI_TARGET
    if_equal 1, Score_Plus2
    goto AI_CV_Protect_OpponentIsNotInAMultiturnAttack

@ La IA es más lenta: se protege si recibe OHKO o si recibe 2HKO y no puede meter OHKO
AI_CV_Protect_FasterOpponentIsCharging:
    calculate_nhko AI_TARGET
    if_equal 1, Score_Plus5
    if_equal 2, Score_Plus2
    @ recibe 3HKO o menos daño: sigue por donde iba en la evaluación de Protect
AI_CV_Protect_OpponentIsNotInAMultiturnAttack:
	if_next_turn_target_might_use_move_with_effect EFFECT_MIDELE_POWER, AI_CV_Protect_ScoreDown5
	if_status3 AI_USER, STATUS3_ALWAYS_HITS, Score_Plus2
	if_ability AI_USER, ABILITY_SPEED_BOOST, AI_CV_Protect_Boost
	if_status  AI_USER, STATUS1_PSN_ANY | STATUS1_BURN, AI_CV_ProtectUserStatused
	if_status2 AI_USER, STATUS2_CURSED | STATUS2_INFATUATION, AI_CV_ProtectUserStatused
    if_status3 AI_USER, STATUS3_LEECHSEED | STATUS3_YAWN, AI_CV_ProtectUserStatused
    if_status3 AI_TARGET, STATUS3_PERISH_SONG, AI_CV_Protect_IgnoreTargetHealing
    if_status3 AI_USER, STATUS3_PERISH_SONG, AI_CV_ProtectUserStatused
    if_next_turn_target_might_use_move_with_effect EFFECT_RESTORE_HP, AI_CV_Protect_TargetCanHeal
	if_next_turn_target_might_use_move_with_effect EFFECT_SOFTBOILED, AI_CV_Protect_TargetCanHeal
	if_next_turn_target_might_use_move_with_effect EFFECT_MORNING_SUN, AI_CV_Protect_TargetCanHeal
	if_next_turn_target_might_use_move_with_effect EFFECT_MOONLIGHT, AI_CV_Protect_TargetCanHeal
	if_next_turn_target_might_use_move_with_effect EFFECT_SHORE_UP, AI_CV_Protect_TargetCanHeal
	if_next_turn_target_might_use_move_with_effect EFFECT_SYNTHESIS, AI_CV_Protect_TargetCanHeal
	if_next_turn_target_might_use_move_with_effect EFFECT_REST, AI_CV_Protect_TargetCanHeal
AI_CV_Protect_IgnoreTargetHealing:
	if_status2 AI_TARGET, STATUS2_CURSED, AI_CV_Protect_EncourageAndContinue
	if_status AI_TARGET, STATUS1_TOXIC_POISON, AI_CV_Protect_EncourageAndContinue
	if_status3 AI_TARGET, STATUS3_LEECHSEED, AI_CV_Protect_EncourageAndContinue
AI_CV_Protect_TargetCanRecoverFromItsCurrentStatus:
	get_last_used_bank_move AI_TARGET
	get_move_effect_from_result
	if_equal EFFECT_LOCK_ON, AI_CV_Protect_EncourageAndContinue
	if_status3 AI_TARGET, STATUS3_PERISH_SONG, AI_CV_Protect_TargetUnderPerishSong
AI_CV_Protect_NoRelevantPerishSong:
	if_receiving_wish AI_USER, AI_CV_Protect_Wish
	if_status2 AI_TARGET, STATUS2_INFATUATION, AI_CV_Protect_End
	if_status3 AI_TARGET, STATUS3_YAWN, AI_CV_Protect_End
	goto AI_CV_Protect2

AI_CV_Protect_TargetUnderPerishSong:
  count_usable_party_mons AI_TARGET
  if_equal 0, AI_CV_Protect_EncourageAndContinue
  if_type AI_TARGET, TYPE_GHOST, AI_CV_Protect_TargetUnderPerishSong_ButCanSwitchOut
  if_status2 AI_TARGET, STATUS2_ESCAPE_PREVENTION | STATUS2_WRAPPED, AI_CV_Protect_EncourageAndContinue
  if_status3 AI_TARGET, STATUS3_ROOTED, AI_CV_Protect_EncourageAndContinue
AI_CV_Protect_TargetUnderPerishSong_ButCanSwitchOut:
  if_not_status3 AI_USER, STATUS3_PERISH_SONG, AI_CV_Protect_NoRelevantPerishSong
  count_usable_party_mons AI_USER
  if_equal 0, AI_CV_ProtectUserStatused
  if_type AI_TARGET, TYPE_GHOST, AI_CV_Protect_NoRelevantPerishSong
  if_status2 AI_USER, STATUS2_ESCAPE_PREVENTION | STATUS2_WRAPPED, AI_CV_ProtectUserStatused
  if_status3 AI_USER, STATUS3_ROOTED, AI_CV_ProtectUserStatused
  goto AI_CV_Protect_NoRelevantPerishSong

AI_CV_Protect_EncourageAndContinue:
	score +2

AI_CV_Protect2:
	if_random_less_than 128, AI_CV_Protect4
	score -1
	
AI_CV_Protect4:
	get_protect_count AI_USER
	if_equal 0, AI_CV_Protect_End
	score -1
	if_status2 AI_USER, STATUS2_SUBSTITUTE, AI_CV_Protect_Minus1
	if_random_less_than 128, AI_CV_Protect_End
AI_CV_Protect_Minus1:
	score -1
	goto AI_CV_Protect_End
	
AI_CV_ProtectUserStatused:
	score -1
	if_double_battle AI_CV_Protect4
	score -3
	goto AI_CV_Protect4
	
AI_CV_Protect_TargetCanHeal:
  if_hp_more_than AI_TARGET, 65, AI_CV_Protect_IgnoreTargetHealing
  if_hp_more_than AI_TARGET, 50, AI_CV_Protect_TargetCanRecoverFromItsCurrentStatus
  score -2
  goto AI_CV_Protect_TargetCanRecoverFromItsCurrentStatus

AI_CV_Protect_ScoreDown5:
	score -5
	goto AI_CV_Protect_End
	
AI_CV_Protect_Wish:
	if_hp_more_than AI_USER, 75, Score_Minus3
	if_hp_more_than AI_USER, 50, AI_CV_Protect_End
	score +3
	goto AI_CV_Protect_End

AI_CV_Protect_MessWithTruant:
    if_target_wont_attack_due_to_truant AI_CV_Protect_End @ conviene ahorrar Protect para el siguiente turno, y ya se penaliza Protect en AI_CBM_Protect
    if_target_faster Score_Plus5
    score +4
    goto AI_CV_Protect_End

AI_CV_Protect_OpponentIsSemiInvulnerable:
    if_user_faster Score_Plus5  @ Si la IA es más rápida, no tiene sentido que ataque, mejor protegerse
    calculate_nhko AI_TARGET    @ En caso contrario, conviene protegerse salvo si la IA recibe poco y puede hacer mucho
    if_more_than 4, AI_CV_Protect_End @ Si recibe 5HKO o menos daño, a la IA le da un poco igual. Se protegerá si no tiene nada
    if_more_than 2, Score_Plus2 @ Si recibe 3HKO o menos daño, con este +2 preferirá ataques que hagan KO (por if_can_faint) antes que protegerse
    goto Score_Plus5
	
AI_CV_Protect_Boost:
	is_first_turn_for AI_USER
	if_equal 1, AI_CV_Protect_Boost2
	goto AI_CV_Protect_End	
AI_CV_Protect_Boost2:
	if_target_faster Score_Plus10
AI_CV_Protect_End:
	end

AI_CV_Spikes:
	count_usable_party_mons AI_USER
	if_less_than 2, AI_CV_Spikes_NoWorthSingleTurnOfSetup
	if_status AI_TARGET, STATUS1_FREEZE, AI_CV_Spikes_ConsiderSafeSetup
	calculate_nhko AI_TARGET | AI_NHKO_PESSIMISTIC
	if_less_than  3, AI_CV_Spikes_NoWorthSafeSetup
	if_more_than  3, AI_CV_Spikes_ConsiderSafeSetup
	if_target_faster AI_CV_Spikes_NoWorthSafeSetup
AI_CV_Spikes_ConsiderSafeSetup:
	if_has_non_ineffective_move_with_effect AI_TARGET, EFFECT_RAPID_SPIN, Score_Minus2
	if_random_less_than 100, AI_CV_Spikes_End
	if_not_side_affecting AI_TARGET, SIDE_STATUS_SPIKES, AI_CV_Spikes_Plus1
	get_hazards_count AI_TARGET, EFFECT_SPIKES
	if_equal 3, AI_CV_Spikes_End
	goto AI_CV_Spikes_Plus1

AI_CV_Spikes_NoWorthSafeSetup:
	if_free_setup_turn AI_CV_Spikes_ConsiderSingleTurnOfSetup
AI_CV_Spikes_NoWorthSingleTurnOfSetup:
	if_this_attack_might_be_the_last AI_CV_Spikes_ConsiderSacrifice
	if_has_non_ineffective_move_with_effect AI_TARGET, EFFECT_RAPID_SPIN, Score_Minus2
	count_usable_party_mons AI_USER
	if_equal 0, Score_Minus1
AI_CV_Spikes_End:
	end

AI_CV_Spikes_ConsiderSacrifice:
	count_usable_party_mons AI_USER
	if_less_than 2, Score_Minus5
	if_less_than 4, Score_Minus3
	if_equal     4, Score_Minus2
	if_has_non_ineffective_move_with_effect AI_TARGET, EFFECT_RAPID_SPIN, Score_Minus2
	goto Score_Minus1

AI_CV_Spikes_ConsiderSingleTurnOfSetup:
	if_has_non_ineffective_move_with_effect AI_TARGET, EFFECT_RAPID_SPIN, Score_Minus2
	if_random_less_than 100, AI_CV_Spikes_End
	if_not_side_affecting AI_TARGET, SIDE_STATUS_SPIKES, AI_CV_Spikes_Plus1
	if_random_less_than 128, AI_CV_Spikes_End
	get_hazards_count AI_TARGET, EFFECT_SPIKES
	if_more_than 1, AI_CV_Spikes_End
AI_CV_Spikes_Plus1:
	score +1
	goto AI_CV_Spikes_End

AI_CV_Foresight:
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 7, AI_CV_Foresight3
	if_has_move_with_effect AI_TARGET, EFFECT_EVASION_UP, AI_CV_Foresight3
	if_has_move_with_effect AI_TARGET, EFFECT_MINIMIZE, AI_CV_Foresight3
	if_stat_level_equal AI_TARGET, STAT_EVASION, 7, AI_CV_Foresight2
	if_type AI_TARGET, TYPE_GHOST, AI_CV_Foresight2
AI_CV_Foresight_Discourage:
	score -4
	goto AI_CV_Foresight_End

AI_CV_Foresight_DiscourageIfLastMon:
	count_usable_party_mons AI_USER
	if_equal 0, AI_CV_Foresight_Discourage
	goto AI_CV_Foresight_End

AI_CV_Foresight2:
	if_random_less_than 80, AI_CV_Foresight_End

AI_CV_Foresight3:
	if_this_attack_might_be_the_last AI_CV_Foresight_DiscourageIfLastMon
	if_random_less_than 80, AI_CV_Foresight_End
	score +2

AI_CV_Foresight_End:
	end

AI_CV_Endure:
	if_target_wont_attack_due_to_truant Score_Minus10
	get_possible_categories_of_foes_attacks
	if_equal AI_NO_DAMAGING_MOVES, Score_Minus10
	if_hp_less_than AI_USER, 100, AI_CV_Endure_NotRedundantWithSashOrSturdy
	if_ability AI_USER, ABILITY_STURDY, Score_Minus10
	if_holds_item AI_USER, ITEM_FOCUS_SASH, Score_Minus10
AI_CV_Endure_NotRedundantWithSashOrSturdy:
	if_status  AI_USER, STATUS1_PSN_ANY | STATUS1_BURN, AI_CV_Endure_UserWillFaintAfterEnduring
	if_status3 AI_USER, STATUS3_LEECHSEED, AI_CV_Endure_UserWillFaintAfterEnduring
	if_status2 AI_USER, STATUS2_CURSED | STATUS2_INFATUATION, AI_CV_EndureUserStatused
	if_status3 AI_USER, STATUS3_PERISH_SONG | STATUS3_YAWN, AI_CV_EndureUserStatused
	get_weather_at_the_end_of_turn
	if_user_receives_damage_from_stored_weather AI_CV_Endure_UserWillFaintAfterEnduring
AI_CV_Endure_NoWeatherDamageExpected:
	get_protect_count AI_USER
	if_more_than 1, AI_CV_Endure_Discourage
	calculate_nhko AI_TARGET | AI_NHKO_PESSIMISTIC
	if_more_than 2, AI_CV_Endure_Discourage
	if_hp_less_than AI_USER, 8, AI_CV_Endure_DiscourageUnlessTargetIsSuffering
	if_hp_less_than AI_USER, 14, AI_CV_Endure_SlightlyDiscourageUnlessTargetIsSuffering
	if_hp_less_than AI_USER, 35, AI_CV_Endure3
	if_doesnt_have_non_ineffective_move_with_effect AI_USER, EFFECT_FLAIL, AI_CV_Endure_Discourage
	if_has_non_ineffective_move_with_effect AI_TARGET, EFFECT_QUICK_ATTACK, AI_CV_Endure_Discourage
	if_user_faster Score_Plus1
	if_stat_level_equal AI_USER, STAT_SPEED, 12, AI_CV_Endure_Discourage
	if_ability AI_USER, ABILITY_SPEED_BOOST, Score_Plus1
	if_holds_item AI_USER, ITEM_SALAC_BERRY, Score_Plus1
	goto AI_CV_Endure_Discourage

AI_CV_Endure_UserWillFaintAfterEnduring:
	score -8
	goto AI_CV_Endure_End

AI_CV_Endure_DiscourageUnlessTargetIsSuffering:
	if_hp_more_than AI_TARGET, 24, AI_CV_Endure_Discourage
	if_has_move_with_effect AI_TARGET, EFFECT_REST, AI_CV_Endure_Discourage
	if_has_a_50_percent_hp_recovery_move AI_TARGET, AI_CV_Endure_Discourage
	if_status AI_TARGET, STATUS1_TOXIC_POISON, AI_CV_Endure_End
	if_status2 AI_TARGET, STATUS2_CURSED, AI_CV_Endure_End
	if_hp_more_than AI_TARGET, 11, AI_CV_Endure_Discourage
	if_status3 AI_TARGET, STATUS3_LEECHSEED, AI_CV_Endure_End
	if_status AI_TARGET, STATUS1_POISON | STATUS1_BURN, AI_CV_Endure_End
AI_CV_Endure_Discourage:
AI_CV_EndureUserStatused:
	score -3
	goto AI_CV_Endure_End

AI_CV_Endure_SlightlyDiscourageUnlessTargetIsSuffering:
	if_hp_more_than AI_TARGET, 24, AI_CV_Endure_SlightlyDiscourage
	if_has_move_with_effect AI_TARGET, EFFECT_REST, AI_CV_Endure_SlightlyDiscourage
	if_has_a_50_percent_hp_recovery_move AI_TARGET, AI_CV_Endure_SlightlyDiscourage
	if_status AI_TARGET, STATUS1_TOXIC_POISON, AI_CV_Endure_End
	if_status2 AI_TARGET, STATUS2_CURSED, AI_CV_Endure_End
	if_hp_more_than AI_TARGET, 11, AI_CV_Endure_SlightlyDiscourage
	if_status3 AI_TARGET, STATUS3_LEECHSEED, AI_CV_Endure_End
	if_status AI_TARGET, STATUS1_POISON | STATUS1_BURN, AI_CV_Endure_End
AI_CV_Endure_SlightlyDiscourage:
	score -1
	goto AI_CV_Endure_End

AI_CV_Endure3:
	if_doesnt_have_non_ineffective_move_with_effect AI_USER, EFFECT_FLAIL, AI_CV_Endure3_NoFlail
	if_has_non_ineffective_move_with_effect AI_TARGET, EFFECT_QUICK_ATTACK, AI_CV_Endure3_NoFlail
	if_user_faster Score_Plus2
	if_stat_level_equal AI_USER, STAT_SPEED, 12, AI_CV_Endure3_NoFlail
	if_ability AI_USER, ABILITY_SPEED_BOOST, Score_Plus2
	if_holds_item AI_USER, ITEM_SALAC_BERRY, Score_Plus2
AI_CV_Endure3_NoFlail:
	get_protect_count AI_USER
	if_more_than 0, AI_CV_Endure_SlightlyDiscourage
	if_random_less_than 70, AI_CV_Endure_End
	score +1

AI_CV_Endure_End:
	end

AI_CV_BatonPass:
	if_stat_level_more_than AI_USER, STAT_ATK, 8, AI_CV_BatonPass2
	if_stat_level_more_than AI_USER, STAT_DEF, 8, AI_CV_BatonPass2
	if_stat_level_more_than AI_USER, STAT_SPATK, 8, AI_CV_BatonPass2
	if_stat_level_more_than AI_USER, STAT_SPDEF, 8, AI_CV_BatonPass2
	if_stat_level_more_than AI_USER, STAT_SPEED, 8, AI_CV_BatonPass2
	if_stat_level_more_than AI_USER, STAT_EVASION, 8, AI_CV_BatonPass2
	goto AI_CV_BatonPass5

AI_CV_BatonPass2:
	if_target_faster AI_CV_BatonPass3
	if_hp_more_than AI_USER, 60, AI_CV_BatonPass_End
	goto AI_CV_BatonPass4

AI_CV_BatonPass3:
	if_hp_more_than AI_USER, 70, AI_CV_BatonPass_End

AI_CV_BatonPass4:
	if_random_less_than 80, AI_CV_BatonPass_End
	score +2
	goto AI_CV_BatonPass_End

AI_CV_BatonPass5:
	if_stat_level_more_than AI_USER, STAT_ATK, 7, AI_CV_BatonPass7
	if_stat_level_more_than AI_USER, STAT_DEF, 7, AI_CV_BatonPass7
	if_stat_level_more_than AI_USER, STAT_SPATK, 7, AI_CV_BatonPass7
	if_stat_level_more_than AI_USER, STAT_SPDEF, 7, AI_CV_BatonPass7
	if_stat_level_more_than AI_USER, STAT_SPEED, 7, AI_CV_BatonPass7
	if_stat_level_more_than AI_USER, STAT_EVASION, 7, AI_CV_BatonPass7
	goto AI_CV_BatonPass_ScoreDown2

AI_CV_BatonPass7:
	if_target_faster AI_CV_BatonPass8
	if_hp_more_than AI_USER, 60, AI_CV_BatonPass_ScoreDown2
	goto AI_CV_BatonPass_End

AI_CV_BatonPass8:
	if_hp_less_than AI_USER, 70, AI_CV_BatonPass_End

AI_CV_BatonPass_ScoreDown2:
	score -2

AI_CV_BatonPass_End:
	end

AI_CV_Pursuit:
	count_usable_party_mons AI_TARGET
	if_equal 0, AI_CV_Pursuit_End
	if_status3 AI_TARGET, STATUS3_ROOTED, AI_CV_Pursuit_End
	is_first_turn_for AI_USER
	if_not_equal 0, AI_CV_Pursuit_End
	if_no_type AI_USER, TYPE_DARK, AI_CV_Pursuit_SkipPsychicImmunityCheck
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_equal TYPE_PSYCHIC, AI_CV_Pursuit_ConsiderSeriously
AI_CV_Pursuit_SkipPsychicImmunityCheck:
	if_type AI_USER, TYPE_FLYING, AI_CV_Pursuit_CheckGroundImmunity
	if_no_ability AI_USER, ABILITY_LEVITATE, AI_CV_Pursuit_SkipGroundImmunityCheck
AI_CV_Pursuit_CheckGroundImmunity:
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_equal TYPE_GROUND, AI_CV_Pursuit_ConsiderSeriously
AI_CV_Pursuit_SkipGroundImmunityCheck:
	if_no_ability AI_USER, ABILITY_FLASH_FIRE, AI_CV_Pursuit_SkipFireImmunityCheck
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_equal TYPE_FIRE, AI_CV_Pursuit_ConsiderSeriously
AI_CV_Pursuit_SkipFireImmunityCheck:
	if_no_type AI_USER, TYPE_FAIRY, AI_CV_Pursuit_SkipDragonImmunityCheck
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_equal TYPE_DRAGON, AI_CV_Pursuit_ConsiderSeriously
AI_CV_Pursuit_SkipDragonImmunityCheck:
AI_CV_Pursuit_CheckTargetsType:
	if_type AI_TARGET, TYPE_GHOST, AI_CV_Pursuit2
	if_type AI_TARGET, TYPE_PSYCHIC, AI_CV_Pursuit2
	goto AI_CV_Pursuit_End

AI_CV_Pursuit_ConsiderSeriously:
	score +1
	goto AI_CV_Pursuit_CheckTargetsType

AI_CV_Pursuit2:
	if_random_less_than 128, AI_CV_Pursuit_End
	score +1

AI_CV_Pursuit_End:
	end

AI_CV_RainDance:
	get_ability AI_USER
	if_equal ABILITY_FORECAST, AI_CV_RainDance3
	get_ability AI_USER_PARTNER
	if_equal ABILITY_FORECAST, AI_CV_RainDance3
	if_equal ABILITY_SWIFT_SWIM, AI_CV_RainDance3
	if_user_faster AI_CV_RainDance2
	get_ability AI_USER
	if_equal ABILITY_SWIFT_SWIM, AI_CV_RainDance3

AI_CV_RainDance2:
	if_hp_less_than AI_USER, 40, AI_CV_RainDance_ScoreDown1
	get_weather
	if_equal AI_WEATHER_HAIL, AI_CV_RainDance3
	if_equal AI_WEATHER_SUN, AI_CV_RainDance3
	if_equal AI_WEATHER_SANDSTORM, AI_CV_RainDance3
	get_ability AI_USER
	if_equal ABILITY_RAIN_DISH, AI_CV_RainDance3
	if_equal ABILITY_DRY_SKIN, AI_CV_RainDance3
	goto AI_CV_RainDance_End

AI_CV_RainDance3:
	score +1
	goto AI_CV_RainDance_End

AI_CV_RainDance_ScoreDown1:
	score -1

AI_CV_RainDance_End:
	end

AI_CV_SunnyDay:
	get_ability AI_USER
	if_equal ABILITY_FORECAST, AI_CV_SunnyDay3
	get_ability AI_USER_PARTNER
	if_equal ABILITY_FORECAST, AI_CV_SunnyDay3
	if_equal ABILITY_CHLOROPHYLL, AI_CV_SunnyDay3
	if_user_faster AI_CV_SunnyDay2
	get_ability AI_USER
	if_equal ABILITY_CHLOROPHYLL, AI_CV_SunnyDay3

AI_CV_SunnyDay2:
	if_hp_less_than AI_USER, 40, AI_CV_SunnyDay_ScoreDown1
	get_weather
	if_equal AI_WEATHER_HAIL, AI_CV_SunnyDay3
	if_equal AI_WEATHER_RAIN, AI_CV_SunnyDay3
	if_equal AI_WEATHER_SANDSTORM, AI_CV_SunnyDay3
	goto AI_CV_SunnyDay_End

AI_CV_SunnyDay3:
	score +1
	goto AI_CV_SunnyDay_End

AI_CV_SunnyDay_ScoreDown1:
	score -1

AI_CV_SunnyDay_End:
	end

AI_CV_BellyDrum:
	if_perish_song_about_to_trigger AI_USER, Score_Minus8
	if_hp_condition USER_CANNOT_USE_BELLY_DRUM, AI_CV_BellyDrum_ScoreDown2
	if_status2 AI_USER, STATUS2_SUBSTITUTE, Score_Plus1
	if_hp_less_than AI_USER, 90, AI_CV_BellyDrum_ScoreDown2
	goto AI_CV_BellyDrum_End

AI_CV_BellyDrum_ScoreDown2:
	score -2

AI_CV_BellyDrum_End:
	end

AI_CV_PsychUp:
	if_stat_level_more_than AI_TARGET, STAT_ATK, 8, AI_CV_PsychUp2
	if_stat_level_more_than AI_TARGET, STAT_DEF, 8, AI_CV_PsychUp2
	if_stat_level_more_than AI_TARGET, STAT_SPATK, 8, AI_CV_PsychUp2
	if_stat_level_more_than AI_TARGET, STAT_SPDEF, 8, AI_CV_PsychUp2
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 8, AI_CV_PsychUp2
	goto AI_CV_PsychUp_ScoreDown2

AI_CV_PsychUp2:
	if_stat_level_less_than AI_USER, STAT_ATK, 7, AI_CV_PsychUp3
	if_stat_level_less_than AI_USER, STAT_DEF, 7, AI_CV_PsychUp3
	if_stat_level_less_than AI_USER, STAT_SPATK, 7, AI_CV_PsychUp3
	if_stat_level_less_than AI_USER, STAT_SPDEF, 7, AI_CV_PsychUp3
	if_stat_level_less_than AI_USER, STAT_EVASION, 7, AI_CV_PsychUp_ScoreUp1
	if_random_less_than 50, AI_CV_PsychUp_End
	goto AI_CV_PsychUp_ScoreDown2

AI_CV_PsychUp_ScoreUp1:
	score +1

AI_CV_PsychUp3:
	score +1
	end

AI_CV_PsychUp_ScoreDown2:
	score -2

AI_CV_PsychUp_End:
	end

AI_CV_MirrorCoat:
    if_hp_condition USER_HAS_1_HP, Score_Minus10
    if_target_wont_attack_due_to_truant Score_Minus10
    if_perish_song_about_to_trigger AI_TARGET, Score_Minus10
    if_status2 AI_TARGET, STATUS2_RECHARGE, Score_Minus10
    if_status2 AI_TARGET, STATUS2_MULTIPLETURNS, AI_CV_MirrorCoat_TargetEncored
    if_any_move_encored AI_TARGET, AI_CV_MirrorCoat_TargetEncored
AI_CV_MirrorCoat_IgnoreEncore:
    get_possible_categories_of_foes_attacks
    if_equal AI_PHYSICAL_ONLY, Score_Minus10
    if_equal AI_NO_DAMAGING_MOVES, Score_Minus10
    if_equal AI_UNKNOWN_CATEGORIES_PROBABLY_PHYSICAL, Score_Minus5
    if_equal AI_ONLY_PHYSICAL_KNOWN, Score_Minus5
    if_not_equal AI_UNKNOWN_CATEGORIES, AI_CV_MirrorCoat_PossiblySpecial
    score -1
    if_random_less_than 128, AI_CV_MirrorCoat_PossiblySpecial
    score -1
AI_CV_MirrorCoat_PossiblySpecial:
    if_target_not_expected_to_sleep_during_next_turn AI_CV_MirrorCoat_TargetNotSleeping
    goto AI_CV_MirrorCoat_ScoreDown3
AI_CV_MirrorCoat_TargetNotSleeping:
	if_status AI_TARGET, STATUS1_FREEZE, AI_CV_MirrorCoat_ScoreDown3
	if_status2 AI_TARGET, STATUS2_INFATUATION, AI_CV_MirrorCoat_ScoreDown3
	if_status2 AI_TARGET, STATUS2_CONFUSION, AI_CV_MirrorCoat_ScoreDown3
	if_target_taunted AI_CV_MirrorCoat1
	if_status2 AI_TARGET, STATUS2_MULTIPLETURNS, AI_CV_MirrorCoat1
	if_any_move_encored AI_TARGET, AI_CV_MirrorCoat1
	if_user_has_revealed_move MOVE_MIRROR_COAT, AI_CV_MirrorCoat_MoveHasBeenRevealed
	goto AI_CV_MirrorCoat1
AI_CV_MirrorCoat_MoveHasBeenRevealed:
	get_last_used_bank_move AI_TARGET
	get_move_effect_from_result
	if_not_in_bytes AI_HighlySpammableRepeatableSetupEffects, AI_CV_MirrorCoat1
	score -1
	if_not_in_bytes AI_CV_ExcellentEffectsToUseAgainstCounterAndMirrorCoat, AI_CV_MirrorCoat1
	if_target_probably_cannot_repeat_last_effect AI_CV_MirrorCoat1
@ El rival de la IA podría boostearse hasta dar OHKO o hacerse casi intocable:
@ conviene no usar este ataque salvo si se puede aguantar un golpe por Sturdy o sash;
@ y aun así conviene no usarlos siempre porque el rival podría agotar los PP,
@ por lo que se considera una pequeña probabilidad (6,25%) de ahorrar un PP
@ que puede provocar que los PP de este movimiento terminen después si ambos tienen 32 PP.
@ La probabilidad de que esto suceda alguna vez en al menos 32 oportunidades es de un 87,3%
	if_in_bytes AI_CV_EvasionUpEffects, AI_CV_MirrorCoat_ScoreDown3
	if_random_less_than 16, AI_CV_MirrorCoat_ScoreDown3
	if_hp_less_than AI_USER, 100, AI_CV_MirrorCoat_NoSturdyOrSash
	if_ability AI_USER, ABILITY_STURDY, AI_CV_MirrorCoat1
	if_holds_item AI_USER, ITEM_FOCUS_SASH, AI_CV_MirrorCoat1
AI_CV_MirrorCoat_NoSturdyOrSash:
@ Si el rival está a +6 y aun así la IA no ve venir un OHKO,
@ tiene un 46,875% de considerar usar este ataque cada turno.
@ Esto permite que, probablemente, no se agoten los PP de este movimiento
@ antes que los de Meditate o Howl, o los de otros ataques con 32 PP
@ (lo que incluye SD, NP, QD, BU, CM, DD) ante un rival con Pressure
	if_stat_level_less_than AI_TARGET, STAT_SPATK, 12, AI_CV_MirrorCoat_ScoreDown3
	calculate_nhko AI_TARGET | AI_NHKO_PESSIMISTIC
	if_equal 1, AI_CV_MirrorCoat_ScoreDown3
	if_random_less_than 128, AI_CV_MirrorCoat_ScoreDown3
AI_CV_MirrorCoat1:
	if_hp_more_than AI_USER, 30, AI_CV_MirrorCoat2
	if_random_less_than 10, AI_CV_MirrorCoat2
	score -1

AI_CV_MirrorCoat2:
	if_hp_more_than AI_USER, 50, AI_CV_MirrorCoat3
	if_random_less_than 100, AI_CV_MirrorCoat3
	score -1

AI_CV_MirrorCoat3:
	if_status2 AI_TARGET, STATUS2_MULTIPLETURNS, AI_CV_MirrorCoat3Plus1Continue
	if_any_move_encored AI_TARGET, AI_CV_MirrorCoat3PossiblePlus1Continue
    if_has_move AI_USER, MOVE_COUNTER, AI_CV_MirrorCoat6
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, AI_CV_MirrorCoat5
	if_target_not_taunted AI_CV_MirrorCoat4
AI_CV_MirrorCoat3PossiblePlus1Continue:
	if_random_less_than 100, AI_CV_MirrorCoat4
AI_CV_MirrorCoat3Plus1Continue:
	score +1

AI_CV_MirrorCoat4:
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_not_in_bytes AI_CV_MirrorCoat_SpecialTypeList, AI_CV_MirrorCoat_ScoreDown3
	if_random_less_than 100, AI_CV_MirrorCoat_End
	score +1
	goto AI_CV_MirrorCoat_End

AI_CV_MirrorCoat5:
	if_status2 AI_TARGET, STATUS2_MULTIPLETURNS, AI_CV_MirrorCoat5PossiblePlus1Continue
	if_any_move_encored AI_TARGET, AI_CV_MirrorCoat5PossiblePlus1Continue
	if_target_not_taunted AI_CV_MirrorCoat6
AI_CV_MirrorCoat5PossiblePlus1Continue:
	if_random_less_than 100, AI_CV_MirrorCoat6
	score +1

AI_CV_MirrorCoat6:
	end

AI_CV_MirrorCoat_TargetEncored:
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, Score_Minus10
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_not_in_bytes AI_CV_MirrorCoat_SpecialTypeList, Score_Minus10
	goto AI_CV_MirrorCoat_IgnoreEncore

AI_CV_MirrorCoat_ScoreDown3:
	score -3

AI_CV_MirrorCoat_End:
	end

AI_CV_MirrorCoat_SpecialTypeList:
    .byte TYPE_FIRE
    .byte TYPE_WATER
    .byte TYPE_GRASS
    .byte TYPE_ELECTRIC
    .byte TYPE_PSYCHIC
    .byte TYPE_ICE
    .byte TYPE_DRAGON
    .byte TYPE_DARK
    .byte TYPE_FAIRY
    .byte -1

AI_CV_ChargeUpMove:
	if_not_effect EFFECT_SOLARBEAM, AI_CV_ChargeUpMove_NotSolarBeamOnSun
    get_weather
    if_equal AI_WEATHER_SUN, AI_CV_ChargeUpMove_End
AI_CV_ChargeUpMove_NotSolarBeamOnSun:
    if_has_move_with_effect AI_TARGET, EFFECT_PROTECT, Score_Minus5
	get_hold_effect AI_USER
    if_equal HOLD_EFFECT_POWER_HERB, AI_CV_ChargeUpMove_SkipKOCheck
    score -2
    if_effect EFFECT_SKULL_BASH, AI_CV_ChargeUpMove_SkipKOCheck
	if_this_attack_might_be_the_last Score_Minus5
AI_CV_ChargeUpMove_SkipKOCheck:
	if_hp_more_than AI_USER, 38, AI_CV_ChargeUpMove_End
	score -1
	goto AI_CV_ChargeUpMove_End

AI_CV_ChargeUpMove_ScoreDown2:
	score -2

AI_CV_ChargeUpMove_End:
	end

AI_CV_ChargeUpMove_ScoreUp2:
	score +2
	goto AI_CV_ChargeUpMove_End

@ Si hay No Guard, o si nos están usando Lock-On o Mind Reader, Fly/Dig/Dive son como si fuesen simplemente de dos turnos
AI_CV_SemiInvulnerable:
	if_ability AI_USER, ABILITY_NO_GUARD, AI_CV_ChargeUpMove_NotSolarBeamOnSun
	if_ability AI_TARGET, ABILITY_NO_GUARD, AI_CV_ChargeUpMove_NotSolarBeamOnSun
	if_not_status3 AI_USER, STATUS3_ALWAYS_HITS, AI_CV_SemiInvulnerable_NoVulnerability
	if_user_faster AI_CV_ChargeUpMove_NotSolarBeamOnSun
AI_CV_SemiInvulnerable_NoVulnerability:
	if_has_move_with_effect AI_TARGET, EFFECT_PROTECT, Score_Minus5
	get_hold_effect AI_USER
    if_equal HOLD_EFFECT_POWER_HERB, AI_CV_SemiInvulnerable_End
    if_no_ability AI_TARGET, ABILITY_TRUANT, AI_CV_SemiInvulnerable_NoTruant
    if_target_faster AI_CV_SemiInvulnerable_TruantTargetFaster
    @ La IA ataca antes que el poke con Truant: conviene iniciar el ataque si ataca en este turno
    if_target_wont_attack_due_to_truant Score_Minus3
    goto Score_Plus3
AI_CV_SemiInvulnerable_TruantTargetFaster:  @ La IA ataca después del poke con Truant: conviene iniciar el ataque si no ataca en este turno
    if_target_wont_attack_due_to_truant Score_Plus3
    goto Score_Minus3
AI_CV_SemiInvulnerable_NoTruant:
	if_status AI_TARGET, STATUS1_TOXIC_POISON, AI_CV_SemiInvulnerable_TryEncourage
	if_status2 AI_TARGET, STATUS2_CURSED, AI_CV_SemiInvulnerable_TryEncourage
	if_status3 AI_TARGET, STATUS3_LEECHSEED, AI_CV_SemiInvulnerable_TryEncourage
	get_weather_at_the_end_of_turn
	if_equal AI_WEATHER_SANDSTORM, AI_CV_SemiInvulnerable_ConsiderEncouragingUnderWeather
	if_equal AI_WEATHER_HAIL, AI_CV_SemiInvulnerable_ConsiderEncouragingUnderWeather
AI_CV_SemiInvulnerable_AgainstOtherSemiInvulnerableMoves:
	if_not_status3 AI_TARGET, STATUS3_SEMI_INVULNERABLE, AI_CV_SemiInvulnerable_End
	if_target_faster Score_Minus5
	calculate_nhko AI_TARGET | AI_NHKO_PESSIMISTIC
	if_more_than 2, AI_CV_SemiInvulnerable_End
	goto Score_Plus2

AI_CV_SemiInvulnerable_ConsiderEncouragingUnderWeather:
	if_user_receives_damage_from_stored_weather AI_CV_SemiInvulnerable_AgainstOtherSemiInvulnerableMoves
AI_CV_SemiInvulnerable_TryEncourage:
	if_random_less_than 80, AI_CV_SemiInvulnerable_End
	score +1

AI_CV_SemiInvulnerable_End:
	end

AI_CV_SandstormResistantTypes:
    .byte TYPE_GROUND
    .byte TYPE_ROCK
    .byte TYPE_STEEL
    .byte -1
	
AI_SandstormResistantAbilities:
	.byte ABILITY_SAND_VEIL
	.byte ABILITY_SAND_FORCE
	.byte ABILITY_SAND_RUSH
	.byte ABILITY_OVERCOAT
	.byte -1

AI_HailResistantAbilities:
	.byte ABILITY_ICE_BODY
	.byte ABILITY_SNOW_CLOAK
	.byte ABILITY_SLUSH_RUSH
	.byte ABILITY_OVERCOAT
	.byte -1

AI_CV_FakeOut:
	call AI_CV_FakeOut_AvoidIfChoicedAndLastMon
    is_first_turn_for AI_USER
    if_equal 0, AI_CV_FakeOut_End
	if_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_CV_FakeOut_CheckIfSubIsBroken
	if_ability_might_be AI_TARGET, ABILITY_INNER_FOCUS, AI_CV_FakeOut_UseIfInNeed
	if_ability_might_be AI_TARGET, ABILITY_SHIELD_DUST, AI_CV_FakeOut_UseIfInNeed
AI_CV_FakeOut_Encourage:
	if_double_battle AI_CV_FakeOut_Double
    if_user_choiced AI_CV_FakeOut_Double
	score +5
	end
AI_CV_FakeOut_Double:
	score +2
AI_CV_FakeOut_End:
	end

@ Tira Fake Out a pokes que podrían tener Inner Focus o Shield Dust si no va a tener tiempo de atacar primero
AI_CV_FakeOut_UseIfInNeed:
    if_can_faint AI_CV_FakeOut_End @ ya recibe suficiente bonus
    if_user_faster AI_TryToFaint_ApplyPenaltiesForLowDamage @ esto se salta al usar Fake Out (si el rival no tiene sustituto), pero en este caso no conviene
    calculate_nhko AI_TARGET
    if_more_than 1, AI_TryToFaint_ApplyPenaltiesForLowDamage
    calculate_nhko AI_TARGET @ se hace dos veces para que solo lo haga si es claro que el rival hace KO
    if_more_than 1, AI_TryToFaint_ApplyPenaltiesForLowDamage
    goto AI_CV_FakeOut_Encourage

AI_CV_FakeOut_CheckIfSubIsBroken:
    if_can_faint AI_CV_FakeOut_End
    goto Score_Minus8
	
AI_CV_FakeOut_AvoidIfChoicedAndLastMon:
    if_user_choiced AI_CV_FakeOut_AvoidIfLastMon
    goto AI_CV_FakeOut_End

@ Si es el último poke se evita Fake Out, salvo si el rival también es el último poke, no tiene sustituto, Fake Out es KO y no tiene Protect/Detect ni Endure
AI_CV_FakeOut_AvoidIfLastMon:
    count_usable_party_mons AI_USER
    if_more_than 0, AI_CV_FakeOut_End @ en caso contrario, es el último poke
    count_usable_party_mons AI_TARGET
    if_more_than 0, AI_CV_FakeOut_Avoid
    if_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_CV_FakeOut_Avoid
    if_will_faint AI_CV_FakeOut_CheckProtectEndure
		if_cant_faint AI_CV_FakeOut_Avoid
    score -5
AI_CV_FakeOut_CheckProtectEndure:
    if_has_move_with_effect AI_TARGET, EFFECT_PROTECT, AI_CV_FakeOut_Avoid
    if_has_move_with_effect AI_TARGET, EFFECT_ENDURE, AI_CV_FakeOut_Avoid
    goto AI_CV_FakeOut_End @ no tiene nada de eso: puede ser conveniente tirar Fake Out

AI_CV_FakeOut_Avoid:
    goto Score_Minus12

AI_CV_SpitUp:
	get_stockpile_count AI_USER
	if_less_than 2, AI_CV_SpitUp_End
	if_random_less_than 80, AI_CV_SpitUp_End
	score +2

AI_CV_SpitUp_End:
	end

AI_CV_Hail:
	call AI_CheckIfTargetIsRemovedByWeather
    get_ability AI_USER
    if_equal ABILITY_FORECAST, AI_CV_Hail3
	get_ability AI_USER_PARTNER
    if_equal ABILITY_FORECAST, AI_CV_Hail3
    if_equal ABILITY_SLUSH_RUSH, AI_CV_Hail3
    if_user_faster AI_CV_Hail2
    get_ability AI_USER
    if_equal ABILITY_SLUSH_RUSH, AI_CV_Hail3

AI_CV_Hail2:
	if_hp_less_than AI_USER, 40, AI_CV_Hail_ScoreDown1
	get_weather
	if_equal AI_WEATHER_SUN, AI_CV_Hail3
	if_equal AI_WEATHER_RAIN, AI_CV_Hail3
	if_equal AI_WEATHER_SANDSTORM, AI_CV_Hail3
    get_ability AI_USER
	if_equal ABILITY_ICE_BODY, AI_CV_Hail3
	if_equal ABILITY_SNOW_CLOAK, AI_CV_Hail3
	goto AI_CV_Hail_End

AI_CV_Hail3:
	score +1
	goto AI_CV_Hail_End

AI_CV_Hail_ScoreDown1:
	score -1

AI_CV_Hail_End:
	end

AI_CV_FocusPunch:
    if_target_wont_attack_due_to_truant AI_CV_FocusPunch_End
    get_possible_categories_of_foes_attacks
    if_equal AI_NO_DAMAGING_MOVES, AI_CV_FocusPunch_End
    if_status2 AI_USER, STATUS2_SUBSTITUTE, AI_CV_FocusPunch_End @ esto ignora posibles movimientos multigolpeo que rompan el sustituto y continúen
    if_target_faster AI_CV_FocusPunch_PriorityPosesNoProblem
    calculate_nhko AI_TARGET
    if_equal 1, Score_Minus5    @ mejor hacer otra cosa: puede no darle tiempo a usar Focus Punch
AI_CV_FocusPunch_PriorityPosesNoProblem:
    if_status AI_TARGET, STATUS1_PARALYSIS, AI_CV_FocusPunch_SkipFirstMinus1
    if_status2 AI_TARGET, STATUS2_INFATUATION, AI_CV_FocusPunch_SkipFirstMinus1
    if_status2 AI_TARGET, STATUS2_CONFUSION, AI_CV_FocusPunch_SkipFirstMinus1
    score -1
AI_CV_FocusPunch_SkipFirstMinus1:
    if_next_turn_target_might_use_move_with_effect EFFECT_THAW_HIT, AI_CV_FocusPunch_SkipFreezeCheck @ esto ignora que el usuario podría ser inmune a dicho ataque
    if_status AI_TARGET, STATUS1_FREEZE, AI_CV_FocusPunch_End
AI_CV_FocusPunch_SkipFreezeCheck:
    if_ability AI_USER, ABILITY_NO_GUARD, AI_CV_FocusPunch_SkipAccuracyAndPrecisionCheck1
    if_ability_might_be AI_TARGET, ABILITY_NO_GUARD, AI_CV_FocusPunch_SkipAccuracyAndPrecisionCheck1
    if_stat_level_less_than AI_TARGET, STAT_ACC, 2, AI_CV_FocusPunch_End
    if_ability_might_be AI_TARGET, ABILITY_KEEN_EYE, AI_CV_FocusPunch_SkipAccuracyAndPrecisionCheck1
    if_stat_level_more_than AI_USER, STAT_EVASION, 10, AI_CV_FocusPunch_End
AI_CV_FocusPunch_SkipAccuracyAndPrecisionCheck1:
    score -1
    if_target_not_expected_to_sleep_during_next_turn AI_CV_FocusPunch_NotExpectedToSleep
    goto AI_CV_FocusPunch_End
AI_CV_FocusPunch_NotExpectedToSleep:
    if_not_status AI_TARGET, STATUS1_PARALYSIS, AI_CV_FocusPunch_NoParafuseOrParalove
    if_status2 AI_TARGET, STATUS2_INFATUATION, AI_CV_FocusPunch_End
    if_status2 AI_TARGET, STATUS2_CONFUSION, AI_CV_FocusPunch_End
	
AI_CV_FocusPunch_NoParafuseOrParalove:
    if_ability AI_USER, ABILITY_NO_GUARD, AI_CV_FocusPunch_SkipAccuracyAndPrecisionCheck2
    if_ability_might_be AI_TARGET, ABILITY_NO_GUARD, AI_CV_FocusPunch_SkipAccuracyAndPrecisionCheck2
    if_stat_level_less_than AI_TARGET, STAT_ACC, 4, AI_CV_FocusPunch_End
    if_ability_might_be AI_TARGET, ABILITY_KEEN_EYE, AI_CV_FocusPunch_SkipAccuracyAndPrecisionCheck2
    if_stat_level_more_than AI_USER, STAT_EVASION, 8, AI_CV_FocusPunch_End
AI_CV_FocusPunch_SkipAccuracyAndPrecisionCheck2:
    score -1
AI_CV_FocusPunch_End:
    end

AI_CV_SmellingSalt:
	if_status AI_TARGET, STATUS1_PARALYSIS, AI_CV_SmellingSalt_ScoreUp1
	goto AI_CV_SmellingSalt_End

AI_CV_SmellingSalt_ScoreUp1:
	score +1

AI_CV_SmellingSalt_End:
	end

AI_CV_Trick:
	get_hold_effect AI_USER
	if_in_bytes AI_CV_Trick_EffectsToEncourage2, AI_CV_Trick3
	if_in_bytes AI_CV_Trick_EffectsToEncourage, AI_CV_Trick4

AI_CV_Trick2:
	score -3
	goto AI_CV_Trick_End

AI_CV_Trick3:
	get_hold_effect AI_TARGET
	if_in_bytes AI_CV_Trick_EffectsToEncourage2, AI_CV_Trick2
	score +5
	goto AI_CV_Trick_End

AI_CV_Trick4:
	get_hold_effect AI_TARGET
	if_in_bytes AI_CV_Trick_EffectsToEncourage, AI_CV_Trick2
	if_random_less_than 50, AI_CV_Trick_End
	score +2

AI_CV_Trick_End:
	end

AI_CV_Trick_EffectsToEncourage:
    .byte HOLD_EFFECT_CONFUSE_SPICY
    .byte HOLD_EFFECT_CONFUSE_DRY
    .byte HOLD_EFFECT_CONFUSE_SWEET
    .byte HOLD_EFFECT_CONFUSE_BITTER
    .byte HOLD_EFFECT_CONFUSE_SOUR
    .byte HOLD_EFFECT_MACHO_BRACE
    .byte HOLD_EFFECT_CHOICE_BAND
    .byte HOLD_EFFECT_CHOICE_SCARF
    .byte HOLD_EFFECT_CHOICE_SPECS
    .byte -1

AI_CV_Trick_EffectsToEncourage2:
    .byte HOLD_EFFECT_CHOICE_BAND
    .byte HOLD_EFFECT_CHOICE_SCARF
    .byte HOLD_EFFECT_CHOICE_SPECS
    .byte -1

AI_CV_ChangeSelfAbility:
	get_ability AI_USER
	if_in_bytes AI_CV_ChangeSelfAbility_AbilitiesToEncourage, AI_CV_ChangeSelfAbility2
	get_ability AI_TARGET
	if_in_bytes AI_CV_ChangeSelfAbility_AbilitiesToEncourage, AI_CV_ChangeSelfAbility3

AI_CV_ChangeSelfAbility2:
	score -1
	goto AI_CV_ChangeSelfAbility_End

AI_CV_ChangeSelfAbility3:
	if_random_less_than 50, AI_CV_ChangeSelfAbility_End
	score +2

AI_CV_ChangeSelfAbility_End:
	end

AI_CV_ChangeSelfAbility_AbilitiesToEncourage:
    .byte ABILITY_SPEED_BOOST
    .byte ABILITY_BATTLE_ARMOR
    .byte ABILITY_SAND_VEIL
    .byte ABILITY_STATIC
    .byte ABILITY_FLASH_FIRE
    .byte ABILITY_WONDER_GUARD
    .byte ABILITY_EFFECT_SPORE
    .byte ABILITY_SWIFT_SWIM
    .byte ABILITY_HUGE_POWER
    .byte ABILITY_RAIN_DISH
    .byte ABILITY_CUTE_CHARM
    .byte ABILITY_SHED_SKIN
    .byte ABILITY_MARVEL_SCALE
    .byte ABILITY_PURE_POWER
    .byte ABILITY_CHLOROPHYLL
    .byte ABILITY_SHIELD_DUST
    .byte ABILITY_ICE_BODY
    .byte ABILITY_SNOW_CLOAK
    .byte ABILITY_SAND_RUSH
    .byte ABILITY_SLUSH_RUSH
    .byte ABILITY_SAND_FORCE
    .byte ABILITY_ADAPTABILITY
    .byte ABILITY_FUR_COAT
    .byte ABILITY_SOLID_ROCK
    .byte ABILITY_ICE_SCALES
    .byte -1

AI_CV_Superpower:
    get_hold_effect AI_USER
    if_equal HOLD_EFFECT_RESTORE_STATS, AI_CV_Superpower_End
    count_usable_party_mons AI_USER
    if_equal 0, AI_CV_Superpower_ScoreDown1
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, AI_CV_Superpower_ScoreDown1
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, AI_CV_Superpower_ScoreDown1
	if_stat_level_less_than AI_USER, STAT_ATK, 6, AI_CV_Superpower_ScoreDown1
	if_target_faster AI_CV_Superpower2
	if_hp_more_than AI_USER, 40, AI_CV_Superpower_ScoreDown1
	goto AI_CV_Superpower_End

AI_CV_Superpower2:
	if_hp_less_than AI_USER, 60, AI_CV_Superpower_End

AI_CV_Superpower_ScoreDown1:
	score -1

AI_CV_Superpower_End:
	end

AI_CV_MagicCoat:
	if_target_wont_attack_due_to_truant Score_Minus10
	if_this_attack_might_be_the_last Score_Minus5
	if_hp_more_than AI_TARGET, 30, AI_CV_MagicCoat2
	if_random_less_than 100, AI_CV_MagicCoat2
	score -1

AI_CV_MagicCoat2:
	is_first_turn_for AI_USER
	if_equal 0, AI_CV_MagicCoat4
	if_random_less_than 150, AI_CV_MagicCoat_End
	score +1
	goto AI_CV_MagicCoat_End

AI_CV_MagicCoat3:
	if_random_less_than 50, AI_CV_MagicCoat_End

AI_CV_MagicCoat4:
	if_random_less_than 30, AI_CV_MagicCoat_End
	score -1

AI_CV_MagicCoat_End:
	end

AI_CV_Recycle:
    if_this_attack_might_be_the_last Score_Minus5
	get_used_held_item AI_USER
	if_not_in_bytes AI_CV_Recycle_ItemsToEncourage, AI_CV_Recycle_ScoreDown2
	if_random_less_than 50, AI_CV_Recycle_End
	score +1
	goto AI_CV_Recycle_End

AI_CV_Recycle_ScoreDown2:
	score -2

AI_CV_Recycle_End:
	end

AI_CV_Recycle_ItemsToEncourage:
    .byte ITEM_CHESTO_BERRY
    .byte ITEM_LUM_BERRY
    .byte ITEM_STARF_BERRY
    .byte ITEM_SITRUS_BERRY
    .byte -1

AI_CV_Revenge:
	if_target_not_expected_to_sleep_during_next_turn AI_CV_Revenge_TargetNotExpectedToSleep
	goto AI_CV_Revenge_ScoreDown2
AI_CV_Revenge_TargetNotExpectedToSleep:
	if_status2 AI_TARGET, STATUS2_INFATUATION, AI_CV_Revenge_ScoreDown2
	if_status2 AI_TARGET, STATUS2_CONFUSION, AI_CV_Revenge_ScoreDown2
	calculate_nhko AI_TARGET
	if_equal 1, AI_CV_Revenge_ScoreDown2
	if_random_less_than 180, AI_CV_Revenge_ScoreDown2
	score +2
	goto AI_CV_Revenge_End

AI_CV_Revenge_ScoreDown2:
	score -2

AI_CV_Revenge_End:
	end

AI_CV_BrickBreak:
	if_side_affecting AI_TARGET, SIDE_STATUS_REFLECT, AI_CV_BrickBreak_ScoreUp1
	goto AI_CV_BrickBreak_End

AI_CV_BrickBreak_ScoreUp1:
	score +1

AI_CV_BrickBreak_End:
	end

AI_CV_KnockOff:
	if_hp_less_than AI_TARGET, 30, AI_CV_KnockOff_End
	is_first_turn_for AI_USER
	if_more_than 0, AI_CV_KnockOff_End
	if_random_less_than 180, AI_CV_KnockOff_End
	score +1

AI_CV_KnockOff_End:
	end

AI_CV_Endeavor:
	if_level_cond AI_LEVEL_IS_AT_MOST_2, AI_CV_Endeavor_assumeFEAR
	if_perish_song_about_to_trigger AI_TARGET, AI_CV_Endeavor_TargetUnderImminentPerishSong
	if_status2 AI_USER, STATUS2_SUBSTITUTE, AI_CV_Endeavor_HPOfTargetWillBeKnown
	if_target_faster AI_CV_Endeavor_TargetIsFaster
AI_CV_Endeavor_HPOfTargetWillBeKnown:
	if_hp_condition TARGET_WITH_LEFTIES_WONT_LOSE_HP_IF_WE_USE_ENDEAVOR, Score_Minus5
	if_hp_more_than AI_USER, 70, Score_Minus1
	if_hp_more_than AI_USER, 20, AI_CV_Endeavor_End
	if_hp_less_than AI_USER, 2, Score_Plus1
	if_hp_less_than AI_TARGET, 25, AI_CV_Endeavor_End
	score +1
	goto AI_CV_Endeavor_End

@ Si el rival tiene 1 PS, resta 8 (mejor atacar con prioridad)
@ Si el rival tiene más PS que el usuario más lo que el rival gana por Restos, es buena idea tirar Endeavor: suma 4
@ En caso contrario, resta 3 (Endeavor no hace mucho)
AI_CV_Endeavor_assumeFEAR:
	if_hp_condition TARGET_HAS_1_HP, Score_Minus8
	if_hp_condition TARGET_WITH_LEFTIES_WONT_LOSE_HP_IF_WE_USE_ENDEAVOR, Score_Minus3
	score +4
	goto AI_CV_Endeavor_End

@ Si el rival caerá por Perish Song, considera tirarle Endeavor a lo que entre.
@ Lo más normal es que cambie la IA si puede, y que si no pueda sea porque el rival sí. En el raro caso de que el rival haya tirado Perish Song con su último poke, entonces no se usa Endeavor
AI_CV_Endeavor_TargetUnderImminentPerishSong:
	count_usable_party_mons AI_TARGET
	if_equal 0, Score_Minus8
	if_hp_more_than AI_USER, 70, Score_Minus5
	if_hp_more_than AI_USER, 40, Score_Minus3
	if_hp_more_than AI_USER, 25, Score_Minus2
	if_hp_less_than AI_USER, 6, Score_Plus2
	if_hp_less_than AI_USER, 14, Score_Plus1
	goto AI_CV_Endeavor_End
	
AI_CV_Endeavor_TargetIsFaster:
	if_hp_more_than AI_TARGET, 25, AI_CV_Endeavor_TargetIsFaster_SkipPenaltyForLowHP
	if_hp_condition TARGET_HAS_1_HP, AI_CV_Endeavor_TargetIsFasterAndHas1HP
	if_hp_condition TARGET_WITH_LEFTIES_WONT_LOSE_HP_IF_WE_USE_ENDEAVOR, AI_CV_Endeavor_TargetIsFaster_ApplyExtraPenaltyForLowHP
	if_hp_condition USER_HAS_1_HP, AI_CV_Endeavor_TargetIsFaster_SkipPenaltyForLowHP
	goto AI_CV_Endeavor_TargetIsFaster_ApplyPenaltyForLowHP

AI_CV_Endeavor_TargetIsFasterAndHas1HP:
	if_hp_more_than AI_USER, 40, Score_Minus8
	score -2
AI_CV_Endeavor_TargetIsFaster_ApplyExtraPenaltyForLowHP:
	score -1
AI_CV_Endeavor_TargetIsFaster_ApplyPenaltyForLowHP:
	score -1
AI_CV_Endeavor_TargetIsFaster_SkipPenaltyForLowHP:
	calculate_nhko AI_TARGET
	if_equal 1, AI_CV_Endeavor_TargetIsFasterAndMightOHKO
	if_equal 2, AI_CV_Endeavor_TargetIsFasterAndInflictsSignificantDamage
	if_equal 3, AI_CV_Endeavor_TargetIsFasterAndInflictsSomeDamage
	score -1
AI_CV_Endeavor_TargetIsFasterAndInflictsSomeDamage:
	score -1
	if_hp_condition TARGET_WITH_LEFTIES_WONT_LOSE_HP_IF_WE_USE_ENDEAVOR, AI_CV_Endeavor_Minus1AndCheckIfFasterTargetMightNotAttack
	if_hp_more_than AI_USER, 70, AI_CV_Endeavor_Minus1AndCheckIfFasterTargetMightNotAttack
	goto AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack

AI_CV_Endeavor_TargetIsFasterAndMightOHKO:
	if_hp_not_equal AI_USER, 100, AI_CV_Endeavor_Minus1AndCheckIfFasterTargetMightNotAttack
	if_ability AI_USER, ABILITY_STURDY, AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack
	if_holds_item AI_USER, ITEM_FOCUS_SASH, AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack
	goto AI_CV_Endeavor_Minus1AndCheckIfFasterTargetMightNotAttack

AI_CV_Endeavor_TargetIsFasterAndInflictsSignificantDamage:
	if_hp_more_than AI_TARGET, 50, AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack
AI_CV_Endeavor_Minus1AndCheckIfFasterTargetMightNotAttack:
	score -1
AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack:
	if_hp_less_than AI_USER, 10, AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_2
	if_hp_less_than AI_TARGET, 65, AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_3
	if_hp_more_than AI_USER, 30, AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_3
AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_2:
	if_hp_condition TARGET_WITH_LEFTIES_WONT_LOSE_HP_IF_WE_USE_ENDEAVOR, AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_3
	goto AI_CV_Endeavor_End

AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_3:
	if_target_wont_attack_due_to_truant Score_Minus5
	if_status AI_TARGET, STATUS1_FREEZE, Score_Minus5
	if_status2 AI_TARGET, STATUS2_RECHARGE, Score_Minus5
	if_target_not_expected_to_sleep_during_next_turn AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_4
	score -2
	goto AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_5

AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_4:
	if_status AI_TARGET, STATUS1_PARALYSIS, AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_Minus1and5
	if_status2 AI_TARGET, STATUS2_CONFUSION | STATUS2_INFATUATION, AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_Minus1and5
	if_status2 AI_TARGET, STATUS2_MULTIPLETURNS, AI_CV_Endeavor_CheckIfFasterTargetMightDoSeriousDamageByAttacking
	if_any_move_encored AI_TARGET, AI_CV_Endeavor_CheckLastMoveOfFasterTarget
	if_user_has_revealed_move MOVE_ENDEAVOR, AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_Minus1and5
	if_not_status AI_TARGET, 0xC00, AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_5 @ en caso de Toxic bastante avanzado, se teme cambio
	count_usable_party_mons AI_TARGET
	if_more_than 0, AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_Minus1and5
	goto AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_5

AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_Minus1and5:
	score -1
	if_hp_less_than AI_USER, 60, AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_5
	if_random_less_than 128, AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_5
	score -1
AI_CV_Endeavor_CheckIfFasterTargetMightNotAttack_5:
	is_first_turn_for AI_TARGET
	if_equal 1, AI_CV_Endeavor_CheckIfFasterTargetMightDoSeriousDamageByAttacking
	if_status2 AI_TARGET, STATUS2_TORMENT, AI_CV_Endeavor_CheckIfFasterTargetMightDoSeriousDamageByAttacking
AI_CV_Endeavor_CheckLastMoveOfFasterTarget:
	if_target_taunted AI_CV_Endeavor_CheckIfFasterTargetMightDoSeriousDamageByAttacking
	get_last_used_bank_move AI_TARGET
	if_equal MOVE_NONE, AI_CV_Endeavor_CheckIfFasterTargetMightDoSeriousDamageByAttacking
	get_move_power_from_result
	if_equal 0, AI_CV_Endeavor_MinusUpTo3Randomly
AI_CV_Endeavor_CheckIfFasterTargetMightDoSeriousDamageByAttacking:
	calculate_nhko AI_TARGET | AI_NHKO_PESSIMISTIC
	if_more_than 3, Score_Minus3
	if_equal 3, Score_Minus2
	if_equal 2, Score_Minus1
AI_CV_Endeavor_End:
	end

@ Para tratar de evitar que el rival piense que no se le va a usar Endeavor, trata de seguir tirando Endeavor si no tiene otros movimientos buenos
AI_CV_Endeavor_MinusUpTo3Randomly:
	score -1
	if_random_less_than 100, AI_CV_Endeavor_End
	score -1
	if_random_less_than 128, AI_CV_Endeavor_End
	score -1
	goto AI_CV_Endeavor_End

AI_CV_Eruption:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, AI_CV_Eruption_ScoreDown1
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, AI_CV_Eruption_ScoreDown1
	if_target_faster AI_CV_Eruption2
	if_hp_more_than AI_TARGET, 50, AI_CV_Eruption_End
	goto AI_CV_Eruption_ScoreDown1

AI_CV_Eruption2:
	if_hp_more_than AI_TARGET, 70, AI_CV_Eruption_End

AI_CV_Eruption_ScoreDown1:
	score -1

AI_CV_Eruption_End:
	end

AI_CV_Imprison:
	if_user_is_intoxicated_and_does_not_have_baton_pass Score_Minus5
	if_status2 AI_USER, STATUS2_CURSED, Score_Minus5
	if_status3 AI_USER, STATUS3_PERISH_SONG, Score_Minus5
	is_first_turn_for AI_USER
	if_more_than 0, AI_CV_Imprison_End
	if_random_less_than 100, AI_CV_Imprison_End
	score +2

AI_CV_Imprison_End:
	end

AI_CV_Refresh:
    if_not_status AI_USER, STATUS1_PSN_ANY | STATUS1_PARALYSIS | STATUS1_BURN, Score_Minus8
    if_this_attack_might_be_the_last Score_Minus5
    if_has_move_with_effect AI_TARGET, EFFECT_TOXIC, Score_Minus3
    if_has_move_with_effect AI_TARGET, EFFECT_SLEEP, Score_Minus2
    if_has_move_with_effect AI_TARGET, EFFECT_PARALYZE, Score_Minus2
    if_not_status AI_USER, STATUS1_TOXIC_POISON, Score_Plus1
    goto Score_Plus2

AI_CV_Snatch:
	if_target_wont_attack_due_to_truant Score_Minus10
	if_perish_song_about_to_trigger AI_TARGET, Score_Minus5
	is_first_turn_for AI_USER
	if_equal 1, AI_CV_Snatch3
	if_random_less_than 30, AI_CV_Snatch_End
	if_target_faster AI_CV_Snatch2
	if_hp_not_equal AI_USER, 100, AI_CV_Snatch5
	if_hp_less_than AI_TARGET, 70, AI_CV_Snatch5
	if_random_less_than 60, AI_CV_Snatch_End
    if_this_attack_might_be_the_last Score_Minus5
	goto AI_CV_Snatch5

AI_CV_Snatch2:
	if_hp_more_than AI_TARGET, 25, AI_CV_Snatch5
    if_next_turn_target_might_use_move_with_effect EFFECT_RESTORE_HP, AI_CV_Snatch3
	if_next_turn_target_might_use_move_with_effect EFFECT_SOFTBOILED, AI_CV_Snatch3
	if_next_turn_target_might_use_move_with_effect EFFECT_MORNING_SUN, AI_CV_Snatch3
	if_next_turn_target_might_use_move_with_effect EFFECT_MOONLIGHT, AI_CV_Snatch3
	if_next_turn_target_might_use_move_with_effect EFFECT_SHORE_UP, AI_CV_Snatch3
	if_next_turn_target_might_use_move_with_effect EFFECT_SYNTHESIS, AI_CV_Snatch3
	if_next_turn_target_might_use_move_with_effect EFFECT_DEFENSE_CURL, AI_CV_Snatch3
	goto AI_CV_Snatch4

AI_CV_Snatch3:
	if_random_less_than 150, AI_CV_Snatch_End
	score +2
	goto AI_CV_Snatch_End

AI_CV_Snatch4:
	if_random_less_than 230, AI_CV_Snatch5
	score +1
	goto AI_CV_Snatch_End

AI_CV_Snatch5:
	if_random_less_than 30, AI_CV_Snatch_End
	score -2

AI_CV_Snatch_End:
	end

AI_CV_MudSport:
	if_hp_less_than AI_USER, 50, AI_CV_MudSport_ScoreDown1
	if_no_type AI_TARGET, TYPE_ELECTRIC, AI_CV_MudSport_ScoreDown1
	score +1
	goto AI_CV_MudSport_End

AI_CV_MudSport_ScoreDown1:
	score -1

AI_CV_MudSport_End:
	end

AI_CV_Overheat:
    get_hold_effect AI_USER
    if_equal HOLD_EFFECT_RESTORE_STATS, AI_CV_Overheat_End
    count_usable_party_mons AI_USER
    if_equal 0, AI_CV_Overheat_ScoreDown1
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, AI_CV_Overheat_ScoreDown1
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, AI_CV_Overheat_ScoreDown1
	if_target_faster AI_CV_Overheat2
	if_hp_more_than AI_USER, 60, AI_CV_Overheat_End
	goto AI_CV_Overheat_ScoreDown1

AI_CV_Overheat2:
	if_hp_more_than AI_USER, 80, AI_CV_Overheat_End

AI_CV_Overheat_ScoreDown1:
	score -1

AI_CV_Overheat_End:
	end

AI_CV_WaterSport:
	if_hp_less_than AI_USER, 50, AI_CV_WaterSport_ScoreDown1
	if_no_type AI_TARGET, TYPE_FIRE, AI_CV_WaterSport_ScoreDown1
	score +1
	goto AI_CV_WaterSport_End

AI_CV_WaterSport_ScoreDown1:
	score -1

AI_CV_WaterSport_End:
	end

AI_CV_Spite:
	if_perish_song_about_to_trigger AI_TARGET, AI_CV_Spite_Discourage
	if_target_faster AI_CV_Spite_End
	get_last_used_bank_move AI_TARGET
	if_equal MOVE_NONE, AI_CV_Spite_Discourage
	if_target_probably_cannot_repeat_last_effect Score_Minus2
	goto AI_CV_Spite_End

AI_CV_Spite_Discourage:
	score -6
AI_CV_Spite_End:
	end

AI_CV_DragonDance:
	if_status3 AI_USER, STATUS3_PERISH_SONG, Score_Minus5
	if_user_is_intoxicated_and_does_not_have_baton_pass Score_Minus5
	if_has_move_with_effect AI_USER, EFFECT_BATON_PASS, AI_CV_DragonDance_ConsiderSetupEagerly
	calculate_nhko
	if_less_than 3, AI_CV_DragonDance_ConsiderSetupEagerly
	if_more_than 3, AI_CV_DragonDance_FreeSetupNotWorth
	if_stat_level_more_than AI_USER, STAT_ATK, 8, AI_CV_DragonDance_FreeSetupNotWorth
	if_stat_level_less_than AI_USER, STAT_ATK, 3, AI_CV_DragonDance_FreeSetupNotWorth
	if_user_can_probably_boost_safely Score_Plus2
	goto AI_CV_DragonDance_FreeSetupNotWorth_Minus2

AI_CV_DragonDance_ConsiderSetupEagerly:
	if_free_setup_turn Score_Plus5
	if_user_can_probably_boost_safely Score_Plus5
	goto AI_CV_DragonDance_SkipFreeSetupCheck

AI_CV_DragonDance_FreeSetupNotWorth:
	if_user_can_probably_boost_safely AI_CV_DragonDance_SkipFreeSetupCheck
AI_CV_DragonDance_FreeSetupNotWorth_Minus2:
	score -2
AI_CV_DragonDance_SkipFreeSetupCheck:
	if_this_attack_might_be_the_last Score_Minus5
	if_doesnt_have_move_with_effect AI_TARGET, EFFECT_SUBSTITUTE, AI_CV_DragonDance_SkipSubCheck
	if_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_CV_DragonDance_SkipSubCheck
	if_hp_condition TARGET_CANNOT_USE_SUB, AI_CV_DragonDance_SkipSubCheck
	if_user_faster AI_CV_DragonDance_ApplyMinus1AgainstPossibleIncomingSub
	if_target_will_be_faster_after_this_effect AI_CV_DragonDance_ApplyMinus1AgainstPossibleIncomingSub
	goto AI_CV_DragonDance_SkipSubCheck @ va a poder usar DD y atacar de forma seguida: no aplica la penalización por poder encontrarse un sub enfrente (si atacase directamente, también se podría encontrar un sub)

AI_CV_DragonDance_ApplyMinus1AgainstPossibleIncomingSub:
	score -1
AI_CV_DragonDance_SkipSubCheck:
	if_target_faster AI_CV_DragonDance2
	if_hp_more_than AI_USER, 50, AI_CV_DragonDance_End
	if_random_less_than 70, AI_CV_DragonDance_End
	score -1
	goto AI_CV_DragonDance_End

AI_CV_DragonDance2:
	if_random_less_than 128, AI_CV_DragonDance_End
	if_target_will_be_faster_after_this_effect AI_CV_DragonDance_End
	score +1

AI_CV_DragonDance_End:
	end

AI_CV_Sandstorm:
	call AI_CheckIfTargetIsRemovedByWeather
    if_user_faster AI_CV_Sandstorm2
    get_ability AI_USER
    if_equal ABILITY_SAND_RUSH, AI_CV_Sandstorm3
	get_ability AI_USER_PARTNER
    if_equal ABILITY_SAND_RUSH, AI_CV_Sandstorm3

AI_CV_Sandstorm2:
	if_hp_less_than AI_USER, 40, AI_CV_Sandstorm_ScoreDown1
	get_weather
	if_equal AI_WEATHER_SUN, AI_CV_Sandstorm3
	if_equal AI_WEATHER_RAIN, AI_CV_Sandstorm3
	if_equal AI_WEATHER_HAIL, AI_CV_Sandstorm3
    get_ability AI_USER
	if_equal ABILITY_SAND_VEIL, AI_CV_Sandstorm3
	if_equal ABILITY_SAND_FORCE, AI_CV_Sandstorm3
	goto AI_CV_Sandstorm_End

AI_CV_Sandstorm3:
	score +1
	goto AI_CV_Sandstorm_End

AI_CV_Sandstorm_ScoreDown1:
	score -1

AI_CV_Sandstorm_End:
	end

AI_CheckIfTargetIsRemovedByWeather:
    if_hp_condition TARGET_HAS_1_MAX_HP, AI_TargetIsRemovedByWeather
    goto AI_Ret

@ Convoca clima para acabar con el Shedinja rival
@ Si es más lento que Shedinja, es incluso mejor que un ataque que haga KO (que no sea Pursuit), ya que no se puede proteger
@ Si es más rápido que Shedinja, probablemente es mejor atacar directamente si se puede, sobre todo si Shedinja puede hacer KO
AI_TargetIsRemovedByWeather:
    if_target_faster Score_Plus5
    calculate_nhko AI_TARGET
    if_equal 1, Score_Plus2
    goto Score_Plus4
	
AI_TryToFaint:
	if_target_is_ally AI_Ret
	if_can_faint AI_TryToFaint_ConsiderEncouragingKOingMove
@ Quita puntos a ataques que hagan poco daño al rival (3 si 6% o menos, 2 si 20% o menos, 1 si 40% o menos).
@ Si, además de no llegar al 40%, tiene menos de un 70% de acertar o el rival se puede curar, quita otro punto.
@ Esto evita que la IA use ataques flojos y hace que en dobles ataque a los que más daño hace
        get_considered_move_power
        if_equal 0, AI_TryToFaint_End
        if_effect EFFECT_OHKO, AI_TryToFaint_End
        if_effect EFFECT_COUNTER, AI_TryToFaint_End
        if_effect EFFECT_MIRROR_COAT, AI_TryToFaint_End
        if_not_effect EFFECT_ENDEAVOR, AI_TryToFaint_SkipEndeavor
        if_status2 AI_USER, STATUS2_SUBSTITUTE, AI_TryToFaint_ApplyPenaltiesForLowDamage
        if_user_faster AI_TryToFaint_ApplyPenaltiesForLowDamage
        goto AI_TryToFaint_End

AI_TryToFaint_SkipEndeavor:
        if_not_effect EFFECT_FAKE_OUT, AI_TryToFaint_SkipFakeOut
        if_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_TryToFaint_ApplyPenaltiesForLowDamage
        goto AI_TryToFaint_End

AI_TryToFaint_SkipFakeOut:
AI_TryToFaint_ApplyPenaltiesForLowDamage:
        get_curr_dmg_hp_percent
        if_more_than 40, AI_TryToFaint_PenaltyForTheLeastPowerfulAttacks
        score -1
        if_accuracy_less_than 70, AI_TryToFaint_IncreasePenaltyForHealingTargetOrLowAccuracy
        if_effect EFFECT_TRAP, AI_TryToFaint_ConsiderSkippingPenaltiesForPartialTrapping
AI_TryToFaint_DoNotSkipFirstPenaltiesForPartialTrapping:
        if_target_taunted AI_TryToFaint_SkipPenaltyForLowDamageAgainstAHealingMon
        if_status2 AI_TARGET, STATUS2_CURSED, AI_TryToFaint_SkipPenaltyForLowDamageAgainstAHealingMon
        if_has_move_with_effect AI_TARGET, EFFECT_REST, AI_TryToFaint_IncreasePenaltyForHealingTargetOrLowAccuracy
        if_status AI_TARGET, STATUS1_TOXIC_POISON, AI_TryToFaint_SkipPenaltyForLowDamageAgainstAHealingMon
        if_has_a_50_percent_hp_recovery_move AI_TARGET, AI_TryToFaint_IncreasePenaltyForHealingTargetOrLowAccuracy
        if_receiving_wish AI_TARGET, AI_TryToFaint_IncreasePenaltyForHealingTargetOrLowAccuracy
        goto AI_TryToFaint_SkipPenaltyForLowDamageAgainstAHealingMon
AI_TryToFaint_IncreasePenaltyForHealingTargetOrLowAccuracy:
        score -1
AI_TryToFaint_SkipPenaltyForLowDamageAgainstAHealingMon:
        if_more_than 6, AI_TryToFaint_SkipPenaltyForReallyLowDamage
        if_effect EFFECT_RAPID_SPIN, AI_TryToFaint_SkipPenaltyForReallyLowDamage
        score -1
AI_TryToFaint_SkipPenaltyForReallyLowDamage:
        if_more_than 20, AI_TryToFaint_PenaltyForTheLeastPowerfulAttacks
        if_effect EFFECT_MIDELE_POWER, AI_TryToFaint_CheckIfTargetOHKOsUser
        if_effect EFFECT_RAPID_SPIN, AI_TryToFaint_CheckEffectsOfRapidSpin
        if_effect EFFECT_TRAP, AI_TryToFaint_CheckIfPartialTrappingMoveWillDealDamage
        if_ability_might_be AI_TARGET, ABILITY_SHIELD_DUST, AI_TryToFaint_SkipCheckingMovesWithSecondaryEffect
        if_ability_might_be AI_TARGET, ABILITY_CLEAR_BODY, AI_TryToFaint_SkipCheckingMovesWithSecondaryEffect
        if_ability_might_be AI_TARGET, ABILITY_WHITE_SMOKE, AI_TryToFaint_SkipCheckingMovesWithSecondaryEffect
        if_move MOVE_APPLE_ACID, AI_TryToFaint_CheckIfTargetsAttackCouldFinishTheBattle
        if_move MOVE_GRAV_APPLE, AI_TryToFaint_CheckIfTargetsAttackCouldFinishTheBattle
AI_TryToFaint_SkipCheckingMovesWithSecondaryEffect:
        score -1
AI_TryToFaint_SkipOnePenaltyForWeakMovesDueToSecondaryEffects:
AI_TryToFaint_PenaltyForTheLeastPowerfulAttacks:
	get_how_powerful_move_is
	if_equal MOVE_NOT_MOST_POWERFUL, Score_Minus1
	if_equal MOVE_POWER_DISCOURAGED_AND_NOT_MOST_POWERFUL, Score_Minus2
	end

@ Se salta la penalización por no llegar al 20% y a veces la penalización por no ser el movimiento de mayor daño (cuando va a AI_TryToFaint_End)
AI_TryToFaint_CheckEffectsOfRapidSpin:
	count_usable_party_mons AI_USER
	if_equal 0, AI_TryToFaint_CheckEffectsOfRapidSpin_SpikesAreIrrelevant
	if_side_affecting AI_USER, SIDE_STATUS_SPIKES, AI_TryToFaint_End
AI_TryToFaint_CheckEffectsOfRapidSpin_SpikesAreIrrelevant:
	goto AI_TryToFaint_CheckIfTargetOHKOsUser

AI_TryToFaint_ConsiderSkippingPenaltiesForPartialTrapping:
	if_status2 AI_TARGET, STATUS2_WRAPPED, AI_TryToFaint_DoNotSkipFirstPenaltiesForPartialTrapping
	if_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_TryToFaint_SkipPenaltyForLowDamageAgainstAHealingMon
	goto AI_TryToFaint_SkipPenaltyForReallyLowDamage

AI_TryToFaint_CheckIfPartialTrappingMoveWillDealDamage:
	if_status2 AI_TARGET, STATUS2_WRAPPED, AI_TryToFaint_SkipCheckingMovesWithSecondaryEffect
	if_target_might_have_a_sub_before_our_attack AI_TryToFaint_SkipCheckingMovesWithSecondaryEffect
AI_TryToFaint_CheckIfTargetOHKOsUser:
	calculate_nhko AI_TARGET
	if_equal 1, AI_TryToFaint_ProbablyIrrelevantSecondaryEffect
	get_curr_dmg_hp_percent
	goto AI_TryToFaint_SkipOnePenaltyForWeakMovesDueToSecondaryEffects

AI_TryToFaint_CheckIfTargetsAttackCouldFinishTheBattle:
	count_usable_party_mons AI_USER
	if_equal 0, AI_TryToFaint_CheckIfTargetOHKOsUser
	goto AI_TryToFaint_SkipOnePenaltyForWeakMovesDueToSecondaryEffects

AI_TryToFaint_ProbablyIrrelevantSecondaryEffect:
	get_curr_dmg_hp_percent
	goto AI_TryToFaint_SkipCheckingMovesWithSecondaryEffect

AI_TryToFaint_ConsiderEncouragingKOingMove:
    if_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_TryToFaint_CheckFakeOutWithSub
    if_effect EFFECT_PURSUIT, AI_TryToFaint_PursuitAndFakeOutBonus
    goto AI_TryToFaint_CheckFakeOutWithNoSub
AI_TryToFaint_CheckFakeOutWithSub:
    if_not_effect EFFECT_FAKE_OUT, AI_TryToFaint_SkipPlus3Bonus
    is_first_turn_for AI_USER
    if_equal 0, AI_TryToFaint_End
    if_user_faster AI_TryToFaint_SkipPlus3Bonus @ no tiene sentido sumarle +3 a Fake Out si la IA ya es más rápida y el rival tiene sub
    goto AI_TryToFaint_PursuitAndFakeOutBonus

AI_TryToFaint_CheckFakeOutWithNoSub:
    if_not_effect EFFECT_FAKE_OUT, AI_TryToFaint_SkipPlus3Bonus
    is_first_turn_for AI_USER
    if_equal 0, AI_TryToFaint_End
AI_TryToFaint_PursuitAndFakeOutBonus:
    score +3
AI_TryToFaint_SkipPlus3Bonus:
    if_not_effect EFFECT_SOLARBEAM, AI_TryToFaint_NotSolarBeam
    get_weather
    if_not_equal AI_WEATHER_SUN, AI_TryToFaint_End
AI_TryToFaint_NotSolarBeam:
    if_effect EFFECT_RAZOR_WIND, AI_TryToFaint_End
    if_effect EFFECT_SKY_ATTACK, AI_TryToFaint_End
    if_effect EFFECT_SKULL_BASH, AI_TryToFaint_End
	if_effect EFFECT_FOCUS_PUNCH, AI_TryToFaint_FocusPunch
    if_effect EFFECT_SUPERPOWER, AI_TryToFaint_NegativeEffectThatDoesNotMatterIfCanFinishBattle
    if_effect EFFECT_OVERHEAT, AI_TryToFaint_NegativeEffectThatDoesNotMatterIfCanFinishBattle
    if_effect EFFECT_RAMPAGE, AI_TryToFaint_NegativeEffectThatDoesNotMatterIfCanFinishBattle @ THRASH, OUTRAGE, PETAL DANCE
    if_effect EFFECT_RECOIL_50, AI_TryToFaint_Recoil50 @ LIGHT OF RUIN, HEAD SMASH
    if_effect EFFECT_DOUBLE_EDGE, AI_TryToFaint_Recoil33 @ DOUBLE EDGE, BRAVE BIRD, VOLT TACKLE
    if_effect EFFECT_RECOIL, AI_TryToFaint_Recoil25 @ TAKE DOWN, SUBMISION
    if_effect EFFECT_VITAL_THROW, AI_TryToFaint_LowPriorityMove
    if_effect EFFECT_REVENGE, AI_TryToFaint_LowPriorityMove
	if_effect EFFECT_EXPLOSION, AI_TryToFaint_Explosion
AI_TryToFaint_CheckContact:
    if_move_is_contactless AI_TryToFaint_SkipContactCheck
    if_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_TryToFaint_SkipContactCheck
    if_ability_might_be AI_TARGET, ABILITY_ROUGH_SKIN, AI_TryToFaint_RoughSkinIronBarbs
    if_ability_might_be AI_TARGET, ABILITY_IRON_BARBS, AI_TryToFaint_RoughSkinIronBarbs
    if_ability_might_be AI_TARGET, ABILITY_MUMMY, AI_TryToFaint_TransmittingAbility
    if_ability_might_be AI_TARGET, ABILITY_WANDERING_SPIRIT, AI_TryToFaint_TransmittingAbility
    if_ability_might_be AI_TARGET, ABILITY_GOOEY, AI_TryToFaint_Gooey
    if_ability_might_be AI_TARGET, ABILITY_TANGLING_HAIR, AI_TryToFaint_Gooey
    if_ability_might_be AI_TARGET, ABILITY_PERISH_BODY, AI_TryToFaint_PerishBody
    if_ability_might_be AI_TARGET, ABILITY_EFFECT_SPORE, AI_TryToFaint_EffectSpore
    if_ability_might_be AI_TARGET, ABILITY_POISON_POINT, AI_TryToFaint_PoisonPoint
    if_ability_might_be AI_TARGET, ABILITY_STATIC, AI_TryToFaint_Static
    if_ability_might_be AI_TARGET, ABILITY_FLAME_BODY, AI_TryToFaint_FlameBody
AI_TryToFaint_SkipContactCheck:
	if_high_change_to_break_sub_and_keep_hitting AI_TryToFaint_ExtraPointForBreakingSubAndKeepHitting
	if_not_effect EFFECT_QUICK_ATTACK, AI_TryToFaint_IncreaseScoreDependingOnAccuracy
	score +2
	goto AI_TryToFaint_IncreaseScoreDependingOnAccuracy

AI_TryToFaint_NegativeEffectThatDoesNotMatterIfCanFinishBattle:
	if_doesnt_have_move_with_effect AI_TARGET, EFFECT_SUBSTITUTE, AI_TryToFaint_NegativeEffectThatDoesNotMatterIfCanFinishBattle_NoOptionToSpamSub
	if_target_faster AI_TryToFaint_NegativeEffectThatDoesNotMatterIfCanFinishBattle_CheckHP
	if_not_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_TryToFaint_NegativeEffectThatDoesNotMatterIfCanFinishBattle_NoOptionToSpamSub
AI_TryToFaint_NegativeEffectThatDoesNotMatterIfCanFinishBattle_CheckHP:
	if_hp_more_than AI_TARGET, 45, AI_TryToFaint_End
	if_user_faster AI_TryToFaint_NegativeEffectThatDoesNotMatterIfCanFinishBattle_NoOptionToSpamSub
	if_not_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_TryToFaint_NegativeEffectThatDoesNotMatterIfCanFinishBattle_NoOptionToSpamSub
	if_hp_more_than AI_TARGET, 24, AI_TryToFaint_End
AI_TryToFaint_NegativeEffectThatDoesNotMatterIfCanFinishBattle_NoOptionToSpamSub:
	count_usable_party_mons AI_TARGET
	if_not_equal 0, AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy
	if_target_faster AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy
	if_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy
	if_will_faint AI_TryToFaint_CheckContact
	goto AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy

AI_TryToFaint_ExtraPointForBreakingSubAndKeepHitting:
    score +1
    goto AI_TryToFaint_IncreaseScoreDependingOnAccuracy
	
AI_TryToFaint_FocusPunch:
	if_target_wont_attack_due_to_truant AI_TryToFaint_IncreaseScoreDependingOnAccuracy
    if_user_faster AI_TryToFaint_End
    get_possible_categories_of_foes_attacks
    if_equal AI_NO_DAMAGING_MOVES, AI_TryToFaint_IncreaseScoreDependingOnAccuracy
    if_status2 AI_USER, STATUS2_SUBSTITUTE, AI_TryToFaint_ScoreUp3
    if_stat_level_more_than AI_USER, STAT_EVASION, 10, AI_TryToFaint_ScoreUp2
    if_stat_level_less_than AI_TARGET, STAT_ACC, 2, AI_TryToFaint_ScoreUp2
    if_status AI_TARGET, STATUS1_FREEZE, AI_TryToFaint_ScoreUp2
    if_stat_level_more_than AI_USER, STAT_EVASION, 8, AI_TryToFaint_ScoreUp1
    if_stat_level_less_than AI_TARGET, STAT_ACC, 4, AI_TryToFaint_ScoreUp1
    if_target_not_expected_to_sleep_during_next_turn AI_TryToFaint_FocusPunch_SkipPlus1AgainstAsleepMons
    goto AI_TryToFaint_ScoreUp1
AI_TryToFaint_FocusPunch_SkipPlus1AgainstAsleepMons:
    if_status2 AI_TARGET, STATUS2_INFATUATION, AI_TryToFaint_ScoreUp1
    if_status2 AI_TARGET, STATUS2_CONFUSION, AI_TryToFaint_ScoreUp1
    goto AI_TryToFaint_End

AI_TryToFaint_TransmittingAbility:
    if_ability AI_USER, ABILITY_TRUANT, AI_TryToFaint_SkipContactCheck
    if_ability AI_USER, ABILITY_SLOW_START, AI_TryToFaint_SkipContactCheck
    goto AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy

AI_TryToFaint_Gooey:
    count_usable_party_mons AI_TARGET
    if_not_equal 0, AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy
    if_target_faster AI_TryToFaint_SkipContactCheck
    if_will_faint AI_TryToFaint_SkipContactCheck
    goto AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy

AI_TryToFaint_PerishBody:
    count_usable_party_mons AI_USER
    if_not_equal 0, AI_TryToFaint_SkipContactCheck
    count_usable_party_mons AI_TARGET
    if_not_equal 0, AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy
    goto AI_TryToFaint_SkipContactCheck

AI_TryToFaint_PoisonPoint:
	if_status AI_USER, STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_PARALYSIS, AI_TryToFaint_SkipContactCheck
	if_ability AI_USER, ABILITY_IMMUNITY, AI_TryToFaint_SkipContactCheck
	if_type AI_USER, TYPE_POISON, AI_TryToFaint_SkipContactCheck
	if_type AI_USER, TYPE_STEEL, AI_TryToFaint_SkipContactCheck
	if_side_affecting AI_USER, SIDE_STATUS_SAFEGUARD, AI_TryToFaint_SkipContactCheck
	if_might_heal_with_natural_cure AI_USER, AI_TryToFaint_SkipContactCheck
	goto AI_TryToFaint_CheckIfStatusDoesNotMatter

AI_TryToFaint_Static:
	if_status AI_USER, STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_PARALYSIS, AI_TryToFaint_SkipContactCheck
	if_ability AI_USER, ABILITY_LIMBER, AI_TryToFaint_SkipContactCheck
	if_side_affecting AI_USER, SIDE_STATUS_SAFEGUARD, AI_TryToFaint_SkipContactCheck
	if_might_heal_with_natural_cure AI_USER, AI_TryToFaint_SkipContactCheck
	goto AI_TryToFaint_CheckIfStatusDoesNotMatter

AI_TryToFaint_FlameBody:
	if_status AI_USER, STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_PARALYSIS, AI_TryToFaint_SkipContactCheck
	if_ability AI_USER, ABILITY_WATER_VEIL, AI_TryToFaint_SkipContactCheck
	if_type AI_USER, TYPE_FIRE, AI_TryToFaint_SkipContactCheck
	if_side_affecting AI_USER, SIDE_STATUS_SAFEGUARD, AI_TryToFaint_SkipContactCheck
	if_might_heal_with_natural_cure AI_USER, AI_TryToFaint_SkipContactCheck
	goto AI_TryToFaint_CheckIfStatusDoesNotMatter

AI_TryToFaint_EffectSpore:
	if_status AI_USER, STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_PARALYSIS, AI_TryToFaint_SkipContactCheck
	if_side_affecting AI_USER, SIDE_STATUS_SAFEGUARD, AI_TryToFaint_SkipContactCheck
	if_might_heal_with_natural_cure AI_USER, AI_TryToFaint_SkipContactCheck
AI_TryToFaint_CheckIfStatusDoesNotMatter:
	if_will_faint AI_TryToFaint_CheckIfStatusDoesNotMatter2
	goto AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy

AI_TryToFaint_CheckIfStatusDoesNotMatter2:
	count_usable_party_mons AI_TARGET
	if_equal 0, AI_TryToFaint_SkipContactCheck
	if_ability AI_USER, ABILITY_GUTS, AI_TryToFaint_CheckHPForGuts
	goto AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy

AI_TryToFaint_CheckHPForGuts:
	if_hp_less_than AI_USER, 25, AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy
	goto AI_TryToFaint_SkipContactCheck

AI_TryToFaint_RoughSkinIronBarbs:
	if_hp_less_than AI_USER, 13, AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy
	goto AI_TryToFaint_SkipContactCheck

AI_TryToFaint_Recoil50:
    if_ability AI_USER, ABILITY_ROCK_HEAD, AI_TryToFaint_CheckContact
    if_hp_more_than AI_USER, 30, AI_TryToFaint_CheckContact
    goto AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy
	
AI_TryToFaint_Recoil33:
    if_ability AI_USER, ABILITY_ROCK_HEAD, AI_TryToFaint_CheckContact
    if_hp_more_than AI_USER, 20, AI_TryToFaint_CheckContact
    goto AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy
	
AI_TryToFaint_Recoil25:
    if_ability AI_USER, ABILITY_ROCK_HEAD, AI_TryToFaint_CheckContact
    if_hp_more_than AI_USER, 15, AI_TryToFaint_CheckContact
    goto AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy

AI_TryToFaint_LowPriorityMove:
    if_target_faster AI_TryToFaint_CheckContact
    score -2  @ Recibirá dos puntos menos que un ataque de la misma precisión
    goto AI_TryToFaint_IncreaseScoreDependingOnAccuracy

AI_TryToFaint_Explosion:
    if_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_TryToFaint_End
    if_next_turn_target_might_use_move_with_effect EFFECT_PROTECT, AI_TryToFaint_Explosion_TargetHasProtect
    goto AI_TryToFaint_EncourageExplosionIfOpponentHasOneMonLeft

AI_TryToFaint_Explosion_TargetHasProtect:
    get_protect_count AI_TARGET
    if_equal 0, AI_TryToFaint_End
AI_TryToFaint_EncourageExplosionIfOpponentHasOneMonLeft:
    count_usable_party_mons AI_TARGET
    if_not_equal 0, AI_TryToFaint_End

AI_TryToFaint_Minus1AndIncreaseScoreDependingOnAccuracy:
    score -1  @ Recibirá un punto menos que un ataque de la misma precisión
	
AI_TryToFaint_IncreaseScoreDependingOnAccuracy:
    if_accuracy_less_than 70, AI_TryToFaint_End
    if_accuracy_less_than 80, AI_TryToFaint_ScoreUp1
    if_accuracy_less_than 90, AI_TryToFaint_ScoreUp2
    if_accuracy_less_than 100, AI_TryToFaint_ScoreUp3
    score +1
AI_TryToFaint_ScoreUp3:
    score +1
AI_TryToFaint_ScoreUp2:
    score +1
AI_TryToFaint_ScoreUp1:
    score +1
    if_will_faint AI_TryToFaint_SkipMinus1ToMovesThatMightNotKO
    score -1 @ evita que use un mov que pueda no dar KO si hay otro de igual precisión que da KO seguro
AI_TryToFaint_SkipMinus1ToMovesThatMightNotKO:
    if_not_status2 AI_TARGET, STATUS2_SUBSTITUTE, AI_TryToFaint_ConsiderBonusToMostDamagingAttack
    if_user_choiced AI_TryToFaint_GiveBonusToMostDamagingAttack
    goto AI_TryToFaint_End

AI_TryToFaint_ConsiderBonusToMostDamagingAttack:
    if_user_faster AI_TryToFaint_End
    if_has_a_50_percent_hp_recovery_move AI_TARGET, AI_TryToFaint_GiveBonusToMostDamagingAttack
    if_has_move_with_effect AI_TARGET, EFFECT_REST, AI_TryToFaint_GiveBonusToMostDamagingAttack
    goto AI_TryToFaint_End

AI_TryToFaint_GiveBonusToMostDamagingAttack:
    get_how_powerful_move_is
    if_equal MOVE_MOST_POWERFUL, Score_Plus2
	if_effect EFFECT_QUICK_ATTACK, Score_Plus1
AI_TryToFaint_End:
	end

AI_SetupFirstTurn:
	if_target_is_ally AI_Ret
	get_turn_count
	if_not_equal 0, AI_SetupFirstTurn_End
	get_considered_move_effect
	if_not_in_bytes AI_SetupFirstTurn_SetupEffectsToEncourage, AI_SetupFirstTurn_End
	if_random_less_than 80, AI_SetupFirstTurn_End
	score +2

AI_SetupFirstTurn_End:
	end

AI_SetupFirstTurn_SetupEffectsToEncourage:
    .byte EFFECT_SPEED_UP
    .byte EFFECT_SPEED_DOWN
    .byte EFFECT_EVASION_DOWN
    .byte EFFECT_CONVERSION
    .byte EFFECT_LIGHT_SCREEN
    .byte EFFECT_FOCUS_ENERGY
    .byte EFFECT_CONFUSE
    .byte EFFECT_SPEED_UP_2
    .byte EFFECT_SPEED_DOWN_2
    .byte EFFECT_EVASION_DOWN_2
    .byte EFFECT_REFLECT
    .byte EFFECT_POISON
    .byte EFFECT_PARALYZE
    .byte EFFECT_SUBSTITUTE
    .byte EFFECT_LEECH_SEED
    .byte EFFECT_SWAGGER
    .byte EFFECT_CAMOUFLAGE
    .byte EFFECT_YAWN
    .byte EFFECT_TORMENT
    .byte EFFECT_FLATTER
    .byte EFFECT_WILL_O_WISP
    .byte EFFECT_INGRAIN
    .byte EFFECT_IMPRISON
    .byte EFFECT_TEETER_DANCE
    .byte EFFECT_CAMOUFLAGE
    .byte EFFECT_RAIN_DANCE
    .byte EFFECT_SUNNY_DAY
    .byte EFFECT_SANDSTORM
    .byte EFFECT_HAIL
AI_HighlySpammableRepeatableSetupEffects:
    .byte EFFECT_DEFENSE_UP
    .byte EFFECT_SPECIAL_DEFENSE_UP
    .byte EFFECT_ACCURACY_UP
    .byte EFFECT_ATTACK_DOWN
    .byte EFFECT_DEFENSE_DOWN
    .byte EFFECT_SPECIAL_ATTACK_DOWN
    .byte EFFECT_SPECIAL_DEFENSE_DOWN
    .byte EFFECT_ACCURACY_DOWN
    .byte EFFECT_DEFENSE_UP_2
    .byte EFFECT_SPECIAL_DEFENSE_UP_2
    .byte EFFECT_ACCURACY_UP_2
    .byte EFFECT_ATTACK_DOWN_2
    .byte EFFECT_DEFENSE_DOWN_2
    .byte EFFECT_SPECIAL_ATTACK_DOWN_2
    .byte EFFECT_SPECIAL_DEFENSE_DOWN_2
    .byte EFFECT_ACCURACY_DOWN_2
    .byte EFFECT_CURSE
    .byte EFFECT_DEFENSE_CURL
    .byte EFFECT_TICKLE
    .byte EFFECT_COSMIC_POWER
    .byte EFFECT_STOCKPILE
    .byte EFFECT_SPIKES
AI_CV_ExcellentEffectsToUseAgainstCounterAndMirrorCoat:
    .byte EFFECT_ATTACK_UP
    .byte EFFECT_SPECIAL_ATTACK_UP
    .byte EFFECT_ATTACK_UP_2
    .byte EFFECT_SPECIAL_ATTACK_UP_2
    .byte EFFECT_BULK_UP
    .byte EFFECT_CALM_MIND
    .byte EFFECT_QUIVER_DANCE
    .byte EFFECT_COIL
    .byte EFFECT_DRAGON_DANCE
    .byte EFFECT_ATTACK_SPATK_UP
    .byte EFFECT_SPECIAL_ATTACK_UP_3
AI_CV_EvasionUpEffects:
    .byte EFFECT_EVASION_UP
    .byte EFFECT_EVASION_UP_2
    .byte EFFECT_MINIMIZE
    .byte -1

AI_PreferStrongestMove:
	if_target_is_ally AI_Ret
	get_how_powerful_move_is
	if_not_equal MOVE_HAS_ZERO_OR_UNPREDICTABLE_POWER, AI_PreferStrongestMove_End
	if_random_less_than 100, AI_PreferStrongestMove_End
	score +2

AI_PreferStrongestMove_End:
	end

AI_Risky:
	if_target_is_ally AI_Ret
	get_considered_move_effect
	if_not_in_bytes AI_Risky_EffectsToEncourage, AI_Risky_End
	if_random_less_than 128, AI_Risky_End
	score +2

AI_Risky_End:
	end

AI_Risky_EffectsToEncourage:
    .byte EFFECT_SLEEP
    .byte EFFECT_EXPLOSION
    .byte EFFECT_MIRROR_MOVE
    .byte EFFECT_OHKO
    .byte EFFECT_HIGH_CRITICAL
    .byte EFFECT_CONFUSE
    .byte EFFECT_METRONOME
    .byte EFFECT_PSYWAVE
    .byte EFFECT_COUNTER
    .byte EFFECT_DESTINY_BOND
    .byte EFFECT_SWAGGER
    .byte EFFECT_ATTRACT
    .byte EFFECT_PRESENT
    .byte EFFECT_ALL_STATS_UP_HIT
    .byte EFFECT_BELLY_DRUM
    .byte EFFECT_MIRROR_COAT
    .byte EFFECT_FOCUS_PUNCH
    .byte EFFECT_REVENGE
    .byte EFFECT_TEETER_DANCE
    .byte -1

AI_PreferBatonPass:
	if_target_is_ally AI_Ret
	count_usable_party_mons AI_USER
	if_equal 0, AI_PreferBatonPassEnd
	get_how_powerful_move_is
	if_not_equal MOVE_HAS_ZERO_OR_UNPREDICTABLE_POWER, AI_PreferBatonPassEnd
	if_has_move_with_effect AI_USER, EFFECT_BATON_PASS, AI_PreferBatonPass_GoForBatonPass
	if_random_less_than 80, AI_Risky_End

AI_PreferBatonPass_GoForBatonPass:
	if_move MOVE_SWORDS_DANCE, AI_PreferBatonPass2
	if_move MOVE_DRAGON_DANCE, AI_PreferBatonPass2
	if_move MOVE_CALM_MIND, AI_PreferBatonPass2
	if_move MOVE_NASTY_PLOT, AI_PreferBatonPass2
	if_move MOVE_QUIVER_DANCE, AI_PreferBatonPass2
	if_move MOVE_COIL, AI_PreferBatonPass2
	if_effect EFFECT_PROTECT, AI_PreferBatonPass_End
	if_move MOVE_BATON_PASS, AI_PreferBatonPass_EncourageIfHighStats
	if_random_less_than 20, AI_Risky_End
	score +3

AI_PreferBatonPass2:
	get_turn_count
	if_equal 0, Score_Plus5
	if_hp_less_than AI_USER, 60, Score_Minus10
	goto Score_Plus1

AI_PreferBatonPass_End:
	get_last_used_bank_move AI_USER
	if_in_hwords sMovesTable_ProtectMoves, Score_Minus2
	score +2
	end

sMovesTable_ProtectMoves:
    .2byte MOVE_PROTECT
    .2byte MOVE_DETECT
    .2byte -1

AI_PreferBatonPass_EncourageIfHighStats:
	get_turn_count
	if_equal 0, Score_Minus2
	if_stat_level_more_than AI_USER, STAT_ATK, 8, Score_Plus3
	if_stat_level_more_than AI_USER, STAT_ATK, 7, Score_Plus2
	if_stat_level_more_than AI_USER, STAT_ATK, 6, Score_Plus1
	if_stat_level_more_than AI_USER, STAT_SPATK, 8, Score_Plus3
	if_stat_level_more_than AI_USER, STAT_SPATK, 7, Score_Plus2
	if_stat_level_more_than AI_USER, STAT_SPATK, 6, Score_Plus1
	end

AI_PreferBatonPassEnd:
	end

AI_DoubleBattle:
	if_target_is_ally AI_TryOnAlly
	if_move MOVE_SKILL_SWAP, AI_DoubleBattleSkillSwap
	get_curr_move_type
	if_move MOVE_EARTHQUAKE, AI_DoubleBattleAllHittingGroundMove
	if_move MOVE_MAGNITUDE, AI_DoubleBattleAllHittingGroundMove
	if_move MOVE_SURF, AI_DoubleBattleAllHittingWaterMove
	if_move MOVE_BOOMBURST, AI_DoubleBattleAllHittingBoomburts
	if_move MOVE_EXPLOSION, AI_DoubleBattleAllHittingExplosion
	if_equal TYPE_ELECTRIC, AI_DoubleBattleElectricMove
	if_equal TYPE_FIRE, AI_DoubleBattleFireMove
	get_ability AI_USER
	if_not_equal ABILITY_GUTS, AI_DoubleBattleCheckUserStatus
	if_has_move AI_USER_PARTNER, MOVE_HELPING_HAND, AI_DoubleBattlePartnerHasHelpingHand
	end

AI_DoubleBattlePartnerHasHelpingHand:
	get_how_powerful_move_is
	if_not_equal MOVE_HAS_ZERO_OR_UNPREDICTABLE_POWER, Score_Plus1
	end

AI_DoubleBattleCheckUserStatus:
	if_status AI_USER, STATUS1_ANY, AI_DoubleBattleCheckUserStatus2
	end

AI_DoubleBattleCheckUserStatus2:
	get_how_powerful_move_is
	if_equal MOVE_POWER_DISCOURAGED, Score_Minus5
	if_equal MOVE_POWER_DISCOURAGED_AND_NOT_MOST_POWERFUL, Score_Minus5
	score +1
	if_equal MOVE_MOST_POWERFUL, Score_Plus2
	end

AI_DoubleBattleAllHittingGroundMove:
	if_ability AI_USER_PARTNER, ABILITY_LEVITATE, Score_Plus2
	if_type AI_USER_PARTNER, TYPE_FLYING, Score_Plus2
	if_type AI_USER_PARTNER, TYPE_FIRE, Score_Minus10
	if_type AI_USER_PARTNER, TYPE_ELECTRIC, Score_Minus10
	if_type AI_USER_PARTNER, TYPE_POISON, Score_Minus10
	if_type AI_USER_PARTNER, TYPE_ROCK, Score_Minus10
	goto Score_Minus3
	
AI_DoubleBattleAllHittingWaterMove:
	if_ability AI_USER_PARTNER, ABILITY_WATER_ABSORB, Score_Plus2
	if_ability AI_USER_PARTNER, ABILITY_DRY_SKIN, Score_Plus2
	if_type AI_USER_PARTNER, TYPE_FIRE, Score_Minus10
	if_type AI_USER_PARTNER, TYPE_GROUND, Score_Minus10
	if_type AI_USER_PARTNER, TYPE_ROCK, Score_Minus10
	goto Score_Minus3
	
AI_DoubleBattleAllHittingBoomburts:
	if_ability AI_USER_PARTNER, ABILITY_SOUNDPROOF, Score_Plus2
	if_type AI_USER_PARTNER, TYPE_GHOST, Score_Plus2
	goto Score_Minus3
	
AI_DoubleBattleAllHittingExplosion:
	if_ability AI_USER_PARTNER, ABILITY_DAMP, Score_Minus10
	if_ability AI_TARGET_PARTNER, ABILITY_DAMP, Score_Minus10
	if_type AI_USER_PARTNER, TYPE_GHOST, Score_Plus2
	if_type AI_USER_PARTNER, TYPE_ROCK, AI_DoubleBattleAllHittingExplosion_Rock_Type
	goto Score_Minus3
AI_DoubleBattleAllHittingExplosion_Rock_Type:
	if_type AI_USER_PARTNER, TYPE_STEEL, Score_Plus2
	goto Score_Minus3

AI_DoubleBattleSkillSwap:
	get_ability AI_USER
	if_equal ABILITY_TRUANT, Score_Plus5
	get_ability AI_TARGET
	if_equal ABILITY_SHADOW_TAG, Score_Plus2
	if_equal ABILITY_PURE_POWER, Score_Plus2
	if_ability AI_TARGET, ABILITY_HUGE_POWER, Score_Plus2
	if_ability AI_TARGET, ABILITY_FUR_COAT, Score_Plus2
	end

AI_DoubleBattleElectricMove:
	if_no_ability AI_TARGET_PARTNER, ABILITY_LIGHTNING_ROD, AI_DoubleBattleElectricMoveEnd
	score -2
	if_type AI_TARGET_PARTNER, TYPE_GROUND, Score_Minus8
AI_DoubleBattleElectricMoveEnd:
	end

AI_DoubleBattleFireMove:
	if_flash_fired AI_USER, AI_DoubleBattleFireMove2
	end

AI_DoubleBattleFireMove2:
	goto Score_Plus1

AI_TryOnAlly:
	get_considered_move_power @ Fix Bug. This checks if he should roll a worthy status move to ally. But that was never going to happen, so this was wasting time checking.
	if_equal 0, AI_TryStatusMoveOnAlly
	get_curr_move_type
	if_equal TYPE_FIRE, AI_TryFireMoveOnAlly

AI_DiscourageOnAlly:
	goto Score_Minus30

AI_TryFireMoveOnAlly:
	if_ability AI_USER_PARTNER, ABILITY_FLASH_FIRE, AI_TryFireMoveOnAlly_FlashFire
	goto AI_DiscourageOnAlly

AI_TryFireMoveOnAlly_FlashFire:
	if_flash_fired AI_USER_PARTNER, AI_DiscourageOnAlly
	goto Score_Plus3

AI_TryStatusMoveOnAlly:
	if_move MOVE_SKILL_SWAP, AI_TrySkillSwapOnAlly
	if_move MOVE_WILL_O_WISP, AI_TryStatusOnAlly
	if_move MOVE_TOXIC, AI_TryStatusOnAlly
	if_move MOVE_HELPING_HAND, AI_TryHelpingHandOnAlly
	if_move MOVE_SWAGGER, AI_TrySwaggerOnAlly
	if_move MOVE_HEAL_PULSE, AI_HEALPULSEALLY
	goto Score_Minus30_

AI_TrySkillSwapOnAlly:
	get_ability AI_TARGET
	if_equal ABILITY_TRUANT, Score_Plus10
	get_ability AI_USER
	if_not_equal ABILITY_LEVITATE, AI_TrySkillSwapOnAlly2
	get_ability AI_TARGET
	if_equal ABILITY_LEVITATE, Score_Minus30_
	get_target_type1
	if_not_equal TYPE_ELECTRIC, AI_TrySkillSwapOnAlly2
	score +1
	get_target_type2
	if_not_equal TYPE_ELECTRIC, AI_TrySkillSwapOnAlly2
	score +1
	end

AI_TrySkillSwapOnAlly2:
	if_not_equal ABILITY_COMPOUND_EYES, Score_Minus30_
	if_has_move AI_USER_PARTNER, MOVE_FIRE_BLAST, AI_TrySkillSwapOnAllyPlus3
	if_has_move AI_USER_PARTNER, MOVE_THUNDER, AI_TrySkillSwapOnAllyPlus3
	if_has_move AI_USER_PARTNER, MOVE_CROSS_CHOP, AI_TrySkillSwapOnAllyPlus3
	if_has_move AI_USER_PARTNER, MOVE_HYDRO_PUMP, AI_TrySkillSwapOnAllyPlus3
	if_has_move AI_USER_PARTNER, MOVE_DYNAMIC_PUNCH, AI_TrySkillSwapOnAllyPlus3
	if_has_move AI_USER_PARTNER, MOVE_BLIZZARD, AI_TrySkillSwapOnAllyPlus3
	if_has_move AI_USER_PARTNER, MOVE_MEGAHORN, AI_TrySkillSwapOnAllyPlus3
	if_has_move AI_USER_PARTNER, MOVE_ZAP_CANNON, AI_TrySkillSwapOnAllyPlus3
	if_has_move AI_USER_PARTNER, MOVE_STONE_EDGE, AI_TrySkillSwapOnAllyPlus3
	if_has_move AI_USER_PARTNER, MOVE_GUNK_SHOT, AI_TrySkillSwapOnAllyPlus3
	goto Score_Minus30_

AI_TrySkillSwapOnAllyPlus3:
	goto Score_Plus3

AI_TryStatusOnAlly:
	get_ability AI_TARGET
    if_equal ABILITY_TOXIC_BOOST, AI_TryStatusOnAlly_ToxicBoost
	if_not_equal ABILITY_GUTS, Score_Minus30_
AI_TryStatusOnAlly_CorrectAbility:
	if_status AI_TARGET, STATUS1_ANY, Score_Minus30_
	if_hp_less_than AI_USER, 91, Score_Minus30_
	goto Score_Plus5

AI_TryStatusOnAlly_ToxicBoost:
    if_effect EFFECT_TOXIC, AI_TryStatusOnAlly_CorrectAbility
    if_effect EFFECT_POISON, AI_TryStatusOnAlly_CorrectAbility
    goto Score_Minus30_

AI_TryHelpingHandOnAlly:
	if_random_less_than 64, Score_Minus1
	goto Score_Plus2
	
AI_HEALPULSEALLY:
	if_hp_more_than AI_TARGET, 60, Score_Minus30_
	goto Score_Plus5

AI_TrySwaggerOnAlly:
	if_holds_item AI_TARGET, ITEM_PERSIM_BERRY, AI_TrySwaggerOnAlly2
	if_holds_item AI_TARGET, ITEM_LUM_BERRY, AI_TrySwaggerOnAlly2
	if_ability AI_USER_PARTNER, ABILITY_OWN_TEMPO, AI_TrySwaggerOnAlly2
	goto Score_Minus30_

AI_TrySwaggerOnAlly2:
	if_stat_level_more_than AI_TARGET, STAT_ATK, 7, AI_TrySwaggerOnAlly_End
	score +3

AI_TrySwaggerOnAlly_End:
	end

Score_Minus30_:
	score -30
	end

AI_HPAware:
	if_target_is_ally AI_TryOnAlly
	if_hp_more_than AI_USER, 70, AI_HPAware_UserHasHighHP
	if_hp_more_than AI_USER, 30, AI_HPAware_UserHasMediumHP
	get_considered_move_effect
	if_in_bytes AI_HPAware_DiscouragedEffectsWhenLowHP, AI_HPAware_TryToDiscourage
	goto AI_HPAware_ConsiderTarget

AI_HPAware_UserHasHighHP:
	get_considered_move_effect
	if_in_bytes AI_HPAware_DiscouragedEffectsWhenHighHP, AI_HPAware_TryToDiscourage
	goto AI_HPAware_ConsiderTarget

AI_HPAware_UserHasMediumHP:
	get_considered_move_effect
	if_in_bytes AI_HPAware_DiscouragedEffectsWhenMediumHP, AI_HPAware_TryToDiscourage
	goto AI_HPAware_ConsiderTarget

AI_HPAware_TryToDiscourage:
	if_random_less_than 50, AI_HPAware_ConsiderTarget
	score -2

AI_HPAware_ConsiderTarget:
	if_hp_more_than AI_TARGET, 70, AI_HPAware_TargetHasHighHP
	if_hp_more_than AI_TARGET, 30, AI_HPAware_TargetHasMediumHP
	get_considered_move_effect
	if_in_bytes AI_HPAware_DiscouragedEffectsWhenTargetLowHP, AI_HPAware_TargetTryToDiscourage
	goto AI_HPAware_End

AI_HPAware_TargetHasHighHP:
	get_considered_move_effect
	if_in_bytes AI_HPAware_DiscouragedEffectsWhenTargetHighHP, AI_HPAware_TargetTryToDiscourage
	goto AI_HPAware_End

AI_HPAware_TargetHasMediumHP:
	get_considered_move_effect
	if_in_bytes AI_HPAware_DiscouragedEffectsWhenTargetMediumHP, AI_HPAware_TargetTryToDiscourage
	goto AI_HPAware_End

AI_HPAware_TargetTryToDiscourage:
	if_random_less_than 50, AI_HPAware_End
	score -2

AI_HPAware_End:
	end

AI_HPAware_DiscouragedEffectsWhenHighHP: @ 82DE21F
    .byte EFFECT_EXPLOSION
    .byte EFFECT_RESTORE_HP
    .byte EFFECT_REST
    .byte EFFECT_DESTINY_BOND
    .byte EFFECT_FLAIL
    .byte EFFECT_ENDURE
    .byte EFFECT_MORNING_SUN
    .byte EFFECT_SYNTHESIS
    .byte EFFECT_MOONLIGHT
    .byte EFFECT_SOFTBOILED
    .byte EFFECT_MEMENTO
    .byte EFFECT_GRUDGE
    .byte EFFECT_OVERHEAT
    .byte EFFECT_SHORE_UP
    .byte -1

AI_HPAware_DiscouragedEffectsWhenMediumHP: @ 82DE22D
    .byte EFFECT_EXPLOSION
    .byte EFFECT_ATTACK_UP
    .byte EFFECT_DEFENSE_UP
    .byte EFFECT_SPEED_UP
    .byte EFFECT_SPECIAL_ATTACK_UP
    .byte EFFECT_SPECIAL_DEFENSE_UP
    .byte EFFECT_ACCURACY_UP
    .byte EFFECT_EVASION_UP
    .byte EFFECT_ATTACK_DOWN
    .byte EFFECT_DEFENSE_DOWN
    .byte EFFECT_SPEED_DOWN
    .byte EFFECT_SPECIAL_ATTACK_DOWN
    .byte EFFECT_SPECIAL_DEFENSE_DOWN
    .byte EFFECT_ACCURACY_DOWN
    .byte EFFECT_EVASION_DOWN
    .byte EFFECT_BIDE
    .byte EFFECT_CONVERSION
    .byte EFFECT_LIGHT_SCREEN
    .byte EFFECT_MIST
    .byte EFFECT_FOCUS_ENERGY
    .byte EFFECT_ATTACK_UP_2
    .byte EFFECT_DEFENSE_UP_2
    .byte EFFECT_SPEED_UP_2
    .byte EFFECT_SPECIAL_ATTACK_UP_2
    .byte EFFECT_SPECIAL_DEFENSE_UP_2
    .byte EFFECT_ACCURACY_UP_2
    .byte EFFECT_EVASION_UP_2
    .byte EFFECT_ATTACK_DOWN_2
    .byte EFFECT_SPEED_DOWN_2
    .byte EFFECT_SPECIAL_ATTACK_DOWN_2
    .byte EFFECT_ACCURACY_DOWN_2
    .byte EFFECT_EVASION_DOWN_2
    .byte EFFECT_CONVERSION_2
    .byte EFFECT_SAFEGUARD
    .byte EFFECT_BELLY_DRUM
    .byte EFFECT_TICKLE
    .byte EFFECT_COSMIC_POWER
    .byte EFFECT_BULK_UP
    .byte EFFECT_CALM_MIND
    .byte EFFECT_DRAGON_DANCE
	.byte EFFECT_ATTACK_SPATK_UP
    .byte -1

AI_HPAware_DiscouragedEffectsWhenLowHP: @ 82DE258
    .byte EFFECT_ATTACK_UP
    .byte EFFECT_DEFENSE_UP
    .byte EFFECT_SPEED_UP
    .byte EFFECT_SPECIAL_ATTACK_UP
    .byte EFFECT_SPECIAL_DEFENSE_UP
    .byte EFFECT_ACCURACY_UP
    .byte EFFECT_EVASION_UP
    .byte EFFECT_ATTACK_DOWN
    .byte EFFECT_DEFENSE_DOWN
    .byte EFFECT_SPEED_DOWN
    .byte EFFECT_SPECIAL_ATTACK_DOWN
    .byte EFFECT_SPECIAL_DEFENSE_DOWN
    .byte EFFECT_ACCURACY_DOWN
    .byte EFFECT_EVASION_DOWN
    .byte EFFECT_BIDE
    .byte EFFECT_CONVERSION
    .byte EFFECT_LIGHT_SCREEN
    .byte EFFECT_MIST
    .byte EFFECT_FOCUS_ENERGY
    .byte EFFECT_ATTACK_UP_2
    .byte EFFECT_DEFENSE_UP_2
    .byte EFFECT_SPEED_UP_2
    .byte EFFECT_SPECIAL_ATTACK_UP_2
    .byte EFFECT_SPECIAL_DEFENSE_UP_2
    .byte EFFECT_ACCURACY_UP_2
    .byte EFFECT_EVASION_UP_2
    .byte EFFECT_ATTACK_DOWN_2
    .byte EFFECT_DEFENSE_DOWN_2
    .byte EFFECT_SPEED_DOWN_2
    .byte EFFECT_SPECIAL_ATTACK_DOWN_2
    .byte EFFECT_SPECIAL_DEFENSE_DOWN_2
    .byte EFFECT_ACCURACY_DOWN_2
    .byte EFFECT_EVASION_DOWN_2
    .byte EFFECT_RAGE
    .byte EFFECT_CONVERSION_2
    .byte EFFECT_LOCK_ON
    .byte EFFECT_SAFEGUARD
    .byte EFFECT_BELLY_DRUM
    .byte EFFECT_PSYCH_UP
    .byte EFFECT_MIRROR_COAT
    .byte EFFECT_SOLARBEAM
    .byte EFFECT_ERUPTION
    .byte EFFECT_TICKLE
    .byte EFFECT_COSMIC_POWER
    .byte EFFECT_BULK_UP
    .byte EFFECT_CALM_MIND
    .byte EFFECT_DRAGON_DANCE
	.byte EFFECT_QUIVER_DANCE
	.byte EFFECT_COIL
	.byte EFFECT_SPECIAL_ATTACK_UP_3
	.byte EFFECT_ATTACK_SPATK_UP
    .byte EFFECT_STOCKPILE
    .byte EFFECT_CHARGE
    .byte EFFECT_CURSE
    .byte -1

AI_HPAware_DiscouragedEffectsWhenTargetHighHP: @ 82DE288
    .byte -1

AI_HPAware_DiscouragedEffectsWhenTargetMediumHP: @ 82DE289
    .byte EFFECT_ATTACK_UP
    .byte EFFECT_DEFENSE_UP
    .byte EFFECT_SPEED_UP
    .byte EFFECT_SPECIAL_ATTACK_UP
    .byte EFFECT_SPECIAL_DEFENSE_UP
    .byte EFFECT_ACCURACY_UP
    .byte EFFECT_EVASION_UP
    .byte EFFECT_ATTACK_DOWN
    .byte EFFECT_DEFENSE_DOWN
    .byte EFFECT_SPEED_DOWN
    .byte EFFECT_SPECIAL_ATTACK_DOWN
    .byte EFFECT_SPECIAL_DEFENSE_DOWN
    .byte EFFECT_ACCURACY_DOWN
    .byte EFFECT_EVASION_DOWN
    .byte EFFECT_MIST
    .byte EFFECT_FOCUS_ENERGY
    .byte EFFECT_ATTACK_UP_2
    .byte EFFECT_DEFENSE_UP_2
    .byte EFFECT_SPEED_UP_2
    .byte EFFECT_SPECIAL_ATTACK_UP_2
    .byte EFFECT_SPECIAL_DEFENSE_UP_2
    .byte EFFECT_ACCURACY_UP_2
    .byte EFFECT_EVASION_UP_2
    .byte EFFECT_ATTACK_DOWN_2
    .byte EFFECT_DEFENSE_DOWN_2
    .byte EFFECT_SPEED_DOWN_2
    .byte EFFECT_SPECIAL_ATTACK_DOWN_2
    .byte EFFECT_SPECIAL_DEFENSE_DOWN_2
    .byte EFFECT_ACCURACY_DOWN_2
    .byte EFFECT_EVASION_DOWN_2
    .byte EFFECT_POISON
    .byte EFFECT_PAIN_SPLIT
    .byte EFFECT_PERISH_SONG
    .byte EFFECT_SAFEGUARD
    .byte EFFECT_TICKLE
    .byte EFFECT_COSMIC_POWER
    .byte EFFECT_BULK_UP
    .byte EFFECT_CALM_MIND
    .byte EFFECT_DRAGON_DANCE
	.byte EFFECT_ATTACK_SPATK_UP
    .byte -1

AI_HPAware_DiscouragedEffectsWhenTargetLowHP: @ 82DE2B1
    .byte EFFECT_SLEEP
    .byte EFFECT_EXPLOSION
    .byte EFFECT_ATTACK_UP
    .byte EFFECT_DEFENSE_UP
    .byte EFFECT_SPEED_UP
    .byte EFFECT_SPECIAL_ATTACK_UP
    .byte EFFECT_SPECIAL_DEFENSE_UP
    .byte EFFECT_ACCURACY_UP
    .byte EFFECT_EVASION_UP
    .byte EFFECT_ATTACK_DOWN
    .byte EFFECT_DEFENSE_DOWN
    .byte EFFECT_SPEED_DOWN
    .byte EFFECT_SPECIAL_ATTACK_DOWN
    .byte EFFECT_SPECIAL_DEFENSE_DOWN
    .byte EFFECT_ACCURACY_DOWN
    .byte EFFECT_EVASION_DOWN
    .byte EFFECT_BIDE
    .byte EFFECT_CONVERSION
    .byte EFFECT_TOXIC
    .byte EFFECT_LIGHT_SCREEN
    .byte EFFECT_OHKO
    .byte EFFECT_RAZOR_WIND
    .byte EFFECT_SUPER_FANG
    .byte EFFECT_MIST
    .byte EFFECT_FOCUS_ENERGY
    .byte EFFECT_CONFUSE
    .byte EFFECT_ATTACK_UP_2
    .byte EFFECT_DEFENSE_UP_2
    .byte EFFECT_SPEED_UP_2
    .byte EFFECT_SPECIAL_ATTACK_UP_2
    .byte EFFECT_SPECIAL_DEFENSE_UP_2
    .byte EFFECT_ACCURACY_UP_2
    .byte EFFECT_EVASION_UP_2
    .byte EFFECT_ATTACK_DOWN_2
    .byte EFFECT_DEFENSE_DOWN_2
    .byte EFFECT_SPEED_DOWN_2
    .byte EFFECT_SPECIAL_ATTACK_DOWN_2
    .byte EFFECT_SPECIAL_DEFENSE_DOWN_2
    .byte EFFECT_ACCURACY_DOWN_2
    .byte EFFECT_EVASION_DOWN_2
    .byte EFFECT_POISON
    .byte EFFECT_PARALYZE
    .byte EFFECT_PAIN_SPLIT
    .byte EFFECT_CONVERSION_2
    .byte EFFECT_LOCK_ON
    .byte EFFECT_SPITE
    .byte EFFECT_PERISH_SONG
    .byte EFFECT_SWAGGER
    .byte EFFECT_FURY_CUTTER
    .byte EFFECT_ATTRACT
    .byte EFFECT_SAFEGUARD
    .byte EFFECT_PSYCH_UP
    .byte EFFECT_MIRROR_COAT
    .byte EFFECT_WILL_O_WISP
    .byte EFFECT_TICKLE
    .byte EFFECT_COSMIC_POWER
    .byte EFFECT_BULK_UP
    .byte EFFECT_CALM_MIND
    .byte EFFECT_DRAGON_DANCE
	.byte EFFECT_QUIVER_DANCE
	.byte EFFECT_COIL
	.byte EFFECT_SPECIAL_ATTACK_UP_3
	.byte EFFECT_ATTACK_SPATK_UP
    .byte EFFECT_STOCKPILE
    .byte EFFECT_CHARGE
    .byte EFFECT_CURSE
    .byte -1

AI_Unknown:
	if_target_is_ally AI_TryOnAlly
	if_not_effect EFFECT_SUNNY_DAY, AI_Unknown_End
	if_equal 0, AI_Unknown_End
	is_first_turn_for AI_USER
	if_equal 0, AI_Unknown_End
	score +5

AI_Unknown_End: @ 82DE308
	end
	
@ Hace que la IA ignore la penalización a Perish Song por quedarse con un solo poke contra un rival con más de uno
AI_UsePerishSongEvenIfLastPokemon:
    if_not_effect EFFECT_PERISH_SONG, AI_UsePerishSongEvenIfLastPokemon_End
    if_status3 AI_TARGET, STATUS3_PERISH_SONG, AI_UsePerishSongEvenIfLastPokemon_End
    count_usable_party_mons AI_TARGET
    if_equal 0, AI_UsePerishSongEvenIfLastPokemon_End
    count_usable_party_mons AI_USER
    if_not_equal 0, AI_UsePerishSongEvenIfLastPokemon_End
    score +10
	goto AI_CBM_PerishSong_IgnoreNumberOfMons
AI_UsePerishSongEvenIfLastPokemon_End:
    end

AI_Roaming:
	if_status2 AI_USER, STATUS2_WRAPPED, AI_Roaming_End
	if_status2 AI_USER, STATUS2_ESCAPE_PREVENTION, AI_Roaming_End
	get_ability AI_TARGET
	if_equal ABILITY_SHADOW_TAG, AI_Roaming_End
	get_ability AI_USER
	if_equal ABILITY_LEVITATE, AI_Roaming_Flee
	get_ability AI_TARGET
	if_equal ABILITY_ARENA_TRAP, AI_Roaming_End

AI_Roaming_Flee: @ 82DE335
	flee

AI_Roaming_End: @ 82DE336
	end

AI_Safari:
	if_random_safari_flee AI_Safari_Flee
	watch

AI_Safari_Flee:
	flee

AI_FirstBattle:
	if_hp_equal AI_TARGET, 20, AI_FirstBattle_Flee
	if_hp_less_than AI_TARGET, 20, AI_FirstBattle_Flee
	end

AI_FirstBattle_Flee:
	flee

AI_Ret:
	end
