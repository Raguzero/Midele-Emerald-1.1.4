#ifndef GUARD_SCRIPTPOKE80F8_H
#define GUARD_SCRIPTPOKE80F8_H

void ShowContestWinner(void);
u8 ScriptGiveMon(u16, u8, u16, bool32, bool32, u8);
u8 ScriptGiveEgg(u16);
void CreateScriptedWildMon(u16, u8, u16);
void ScriptSetMonMoveSlot(u8, u16, u8);
u8 ScriptGiveCustomMon(u16 species, u8 level, u16 item, u8 ball, u8 nature, u8 abilityNum, u8 *evs, u8 *ivs, u16 *moves, bool8 isShiny, u8 nickname, u8 *conditions, u8 sheen);
u8 GiveMonWithLevelAndAbilityNum(u16 species, u8 level, u16 item, u8 abilityNum);
void CreateScriptedWildShinyMon(u16, u8, u16);
#endif
