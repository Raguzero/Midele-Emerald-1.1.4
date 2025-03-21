#include "global.h"
#include "battle_main.h"
#include "bg.h"
#include "contest_effect.h"
#include "constants/contest.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "m4a.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokedex_area_screen.h"
#include "pokedex_cry_screen.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "scanline_effect.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "battle_util.h"

// EWRAM
static EWRAM_DATA struct PokedexView *sPokedexView = NULL;
static EWRAM_DATA u16 gUnknown_02039B50 = 0;
static EWRAM_DATA u8 gUnknown_02039B52 = 0;
static EWRAM_DATA struct PokedexListItem *sPokedexListItem = NULL;
//Pokedex Plus HGSS_Ui
EWRAM_DATA static u16 sStatsMovesLevelUp[EGG_LVL_UP_MOVES_ARRAY_COUNT] = {0};
EWRAM_DATA static u16 sStatsMovesEgg[EGG_MOVES_ARRAY_COUNT] = {0};
EWRAM_DATA static u16 sStatsMovesTMHM[NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES] = {0};
EWRAM_DATA static u16 sStatsMovesTMHM_ID[NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES] = {0};
EWRAM_DATA static u16 sStatsMovesTutor[TUTOR_MOVE_COUNT] = {0};

// IWRAM common
// This is written to, but never read.
u8 gUnusedPokedexU8;
void (*gUnknown_030060B4)(void);

struct PokedexOption
{
    const u8 *description;
    const u8 *title;
};

struct UnknownStruct1
{
    const struct PokedexOption *pokedexList;
    u8 unk4;
    u8 unk5;
    u16 numOptions;
};

struct UnknownStruct3
{
    const u8 *text;
    u8 unk4;
    u8 unk5;
    u8 unk6;
};

struct UnknownStruct4
{
    const u8 *text;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
};

extern struct MusicPlayerInfo gMPlayInfo_BGM;

struct PokedexListItem
{
    u16 dexNum;
    u16 species;
    u16 seen:1;
    u16 owned:1;
};

struct PokedexView
{
    struct PokedexListItem pokedexList[NATIONAL_DEX_COUNT];
    u16 unk608;
    u8 unk60A_1:1;
    u8 unk60A_2:1;
    u8 unk60B;
    u16 pokemonListCount;
    u16 selectedPokemon;
    u16 unk610;
    u16 dexMode;
    u16 unk614;
    u16 dexOrder;
    u16 unk618;
    u16 seenCount;
    u16 ownCount;
    u16 monSpriteIds[4];
	u8 typeIconSpriteIds[2]; //HGSS_Ui
    u16 moveSelected; //HGSS_Ui
    u8 moveMax; //HGSS_Ui
    u8 statBarsSpriteId; //HGSS_Ui
    u8 statBarsBgSpriteId; //HGSS_Ui
    bool8 justScrolled; //HGSS_Ui
    u8 splitIconSpriteId;  //HGSS_Ui Physical/Special Split from BE
    u8 numEggMoves;
    u8 numLevelUpMoves;
    u8 numTMHMMoves;
    u8 numTutorMoves;
	u8 numPreEvolutions; //HGSS_Ui
    u16 selectedMonSpriteId;
    u16 unk628;
    u16 unk62A;
    u8 unk62C;
    u8 initialVOffset;
    u8 unk62E;
    u8 unk62F;
    s16 unk630;
    s16 unk632;
    u16 unk634;
    u16 unk636;
    u16 unk638;
    u16 unk63A[4];
	u8 item1_icon;
	u8 item2_icon;
	u8 filler642[6];
    u8 unk64A;
    u8 unk64B;
    u8 unk64C_1:1;
    u8 selectedScreen;
    u8 unk64E;
    u8 menuIsOpen;      //menuIsOpen
    u16 menuCursorPos;     //Menu cursor position
    s16 menuY;     //Menu Y position (inverted because we use REG_BG0VOFS for this)
    u8 unk654[8];
    u8 unk65C[8];
};

enum
{
	INFO_SCREEN,
    STATS_SCREEN,
	EVO_SCREEN,
    AREA_SCREEN,
    CRY_SCREEN,
    SIZE_SCREEN,
    CANCEL_SCREEN,
};

// this file's functions
void sub_80BB774(void);
void sub_80BB78C(u8);
void sub_80BB7D4(u8);
void sub_80BBA28(u8);
void sub_80BBA78(u8);
void LoadPageOnceMonFinishedMoving(u8);
void sub_80BBC74(u8);
void sub_80BBD1C(u8);
void sub_80BBDE8(u8);
void sub_80BBE70(u8);
void sub_80BBEB8(u8);
void sub_80BC0A8(u8);
static void HandleButtonPress_StartMenu(u8);
void sub_80BC2D4(u8);
void sub_80BC360(u8);
void sub_80BC3DC(u8);
void sub_80BC47C(u8);
bool8 sub_80BC514(u8);
static void LoadPokedexBgPalette(u8);
static void FreeWindowAndBgBuffers(void);
static void CreatePokedexList(u8 dexMode, u8 sortMode);
static void CreateMonDexNum(u16, u8, u8, u16);
static void CreateCaughtBall(u16, u8, u8, u16);
static u8 CreateMonName(u16, u8, u8);
static void ClearMonListEntry(u8 x, u8 y, u16 unused);
static void CreateInitialPokemonSprites(u16, u16);
bool8 sub_80BD404(u8, u8, u8);
u16 sub_80BD69C(u16, u16);
static void UpdateSelectedMonSpriteId(void);
static bool8 UpdateSelectedMon(void);
static u8 ClearMonSprites(void);
u16 GetPokemonSpriteToDisplay(u16);
u32 sub_80BDACC(u16, s16, s16);
static void CreateInterfaceSprites(u8);
void MoveMonIntoPosition(struct Sprite *sprite);
static void SpriteCB_Scrollbar(struct Sprite *sprite);
void sub_80BE658(struct Sprite *sprite);
void sub_80BE758(struct Sprite *sprite);
void sub_80BE780(struct Sprite *sprite);
void sub_80BE44C(struct Sprite *sprite);
void sub_80BE834(struct Sprite *sprite);
void sub_80BE4E0(struct Sprite *sprite);
u8 SetupInfoScreen(struct PokedexListItem*, u8 monSpriteId);
bool8 sub_80BE9C4(u8);
u8 sub_80BE9F8(struct PokedexListItem*, u8);
void LoadInfoScreen(u8);
void ChangePokedexScreen(u8);
void LoadSelectedScreen(u8);
void BeginChangeInfoScreen(u8);
void BeginReturnToPokedex(u8);
void LoadAreaScreen(u8);
static void WaitForAreaScreenInput(u8 taskId);
void sub_80BF1EC(u8);
void LoadCryScreen(u8);
void sub_80BF5CC(u8);
void sub_80BF790(u8);
void sub_80BF7FC(u8);
void LoadSizeScreen(u8);
void sub_80BFBB0(u8);
void sub_80BFC78(u8);
void sub_80BFCDC(u16);
void sub_80BFCF4(u16);
void sub_80BFD0C(u8, u16);
void sub_80BFD7C(u8, u16);
static void Task_DisplayNewMonData(u8);
void sub_80C0088(u8);
void blockset_load_palette_to_gpu(u8);
void sub_80C01CC(struct Sprite *sprite);
static void PrintMonInfo(u32 num, u32, u32 owned, u32 newEntry);
static void PrintMonHeight(u16 height, u8 left, u8 top);
static void PrintMonWeight(u16 weight, u8 left, u8 top);
static void ResetOtherVideoRegisters(u16);
u8 sub_80C0B44(u8, u16, u8, u8);
static void PrintFootprint(u8 windowId, u16 dexNum);
u16 sub_80C0EF8(u16, s16, s16, s8);
u16 sub_80C0E0C(u8, u16, u16, u16);
u8 LoadSearchMenu(void);
void Task_LoadSearchMenu(u8);
void sub_80C1570(u8);
void sub_80C15B0(u8);
void sub_80C16CC(u8);
void sub_80C170C(u8);
void sub_80C19A4(u8);
void sub_80C1A4C(u8);
void sub_80C1AB8(u8);
void sub_80C1B64(u8);
void sub_80C1BCC(u8);
void sub_80C1D38(u8);
void sub_80C1D70(u8);
void sub_80C2040(u8);
void sub_80C2064(u8, u8);
void sub_80C20F8(u8);
void sub_80C21D4(u8);
void sub_80C2294(u8);
static u8 GetSearchModeSelection(u8 taskId, u8 option);
void sub_80C23B8(u8);
void sub_80C2594(u8);
void sub_80C2618(const u8*);
void sub_80C2638(u32);
void sub_80C2650(u32);
void sub_80C2668(u32, const u8*);
void sub_80C267C(void);
static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible);
static void CreateTypeIconSprites(void);
//Stats screen HGSS_Ui
#define SCROLLING_MON_X 146
#define HGSS_HIDE_UNSEEN_EVOLUTION_NAMES 0 //0 false, 1 true
static void CreateCaughtBallEvolutionScreen(u16 targetSpecies, u8 x, u8 y, u16 unused);
static void Task_HandleStatsScreenInput(u8 taskId);
static void PrintMonStats(u8 taskId, u32 num, u32 value, u32 owned, u32 newEntry);
static void Task_LoadStatsScreen(u8 taskId);
static void Task_SwitchScreensFromStatsScreen(u8 taskId);
static void Task_ExitStatsScreen(u8 taskId);
static bool8 CalculateMoves(void);
static void DestroyMoveIcon(u8 taskId);
static void PrintMoveNameAndInfo(u8 taskId, bool8 toogle);
static void PrintMonStatsToggle(u8 taskId);
static void PrintInfoScreenTextWhite(const u8* str, u8 left, u8 top);
static void PrintInfoScreenTextSmall(const u8* str, u8 left, u8 top);
static void PrintInfoScreenTextSmallWhite(const u8* str, u8 left, u8 top);
static void Task_LoadEvolutionScreen(u8 taskId);
static void Task_HandleEvolutionScreenInput(u8 taskId);
static void Task_SwitchScreensFromEvolutionScreen(u8 taskId);
static void Task_ExitEvolutionScreen(u8 taskId);
static u8 PrintEvolutionTargetSpeciesAndMethod(u8 taskId, u16 species, u8 depth, u8 depth_i);
static u8 PrintPreEvolutions(u8 taskId, u16 species);
static u8 ShowSplitIcon(u32 split); //Physical/Special Split from BE
static void DestroySplitIcon(void); //Physical/Special Split from BE
//Stat bars on scrolling screens
static void TryDestroyStatBars(void);
static void TryDestroyStatBarsBg(void);
static void CreateStatBars(struct PokedexListItem *dexMon);
static void CreateStatBarsBg(void);
static void SpriteCB_StatBars(struct Sprite *sprite);
static void SpriteCB_StatBarsBg(struct Sprite *sprite);
u16 CreateMonSpriteFromSpeciesNumber(u16 speciesNum, s16 x, s16 y, u16 paletteSlot, bool8 forceFemale);

static const u8 sSelectFormGfx[] = INCBIN_U8("graphics/pokedex/select_form.4bpp");
//Physical/Special Split from BE
 #define TAG_SPLIT_ICONS 30004
 static const u16 sSplitIcons_Pal[] = INCBIN_U16("graphics/interface/split_icons.gbapal");
 static const u32 sSplitIcons_Gfx[] = INCBIN_U32("graphics/interface/split_icons.4bpp.lz");
 static const struct OamData sOamData_SplitIcons =
 {
     .size = SPRITE_SIZE(16x16),
     .shape = SPRITE_SHAPE(16x16),
     .priority = 0,
 };
 static const struct CompressedSpriteSheet sSpriteSheet_SplitIcons =
 {
     .data = sSplitIcons_Gfx,
     .size = 16*16*3/2,
     .tag = TAG_SPLIT_ICONS,
 };
 static const struct SpritePalette sSpritePal_SplitIcons =
 {
     .data = sSplitIcons_Pal,
     .tag = TAG_SPLIT_ICONS
 };
 static const union AnimCmd sSpriteAnim_SplitIcon0[] =
 {
     ANIMCMD_FRAME(0, 0),
     ANIMCMD_END
 };
 static const union AnimCmd sSpriteAnim_SplitIcon1[] =
 {
     ANIMCMD_FRAME(4, 0),
     ANIMCMD_END
 };
 static const union AnimCmd sSpriteAnim_SplitIcon2[] =
 {
     ANIMCMD_FRAME(8, 0),
     ANIMCMD_END
 };
 static const union AnimCmd *const sSpriteAnimTable_SplitIcons[] =
 {
     sSpriteAnim_SplitIcon0,
     sSpriteAnim_SplitIcon1,
     sSpriteAnim_SplitIcon2,
 };
 static const struct SpriteTemplate sSpriteTemplate_SplitIcons =
 {
     .tileTag = TAG_SPLIT_ICONS,
     .paletteTag = TAG_SPLIT_ICONS,
     .oam = &sOamData_SplitIcons,
     .anims = sSpriteAnimTable_SplitIcons,
     .images = NULL,
     .affineAnims = gDummySpriteAffineAnimTable,
     .callback = SpriteCallbackDummy
 };
 
 //HGSS_Ui Stat bars by DizzyEgg
#define TAG_STAT_BAR 4097
#define TAG_STAT_BAR_BG 4098
static const struct OamData sOamData_StatBar =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
};
static const struct OamData sOamData_StatBarBg =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
};
static const struct SpriteTemplate sStatBarSpriteTemplate =
{
    .tileTag = TAG_STAT_BAR,
    .paletteTag = TAG_STAT_BAR,
    .oam = &sOamData_StatBar,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_StatBars,
};
static const struct SpriteTemplate sStatBarBgSpriteTemplate =
{
    .tileTag = TAG_STAT_BAR_BG,
    .paletteTag = TAG_STAT_BAR_BG,
    .oam = &sOamData_StatBarBg,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_StatBarsBg,
};
enum
{
    COLOR_ID_ALPHA,
    COLOR_ID_BAR_WHITE,
    // These are repeated 6 times
    COLOR_ID_FILL,
    COLOR_ID_FILL_SHADOW,
    COLOR_ID_FONT = 14,
    COLOR_ID_FONT_SHADOW = 15,
};
enum
{
    COLOR_BEST, // Light blue
    COLOR_VERY_GOOD, // Green
    COLOR_GOOD, // Light Green
    COLOR_AVERAGE, // Yellow
    COLOR_BAD, // Orange
    COLOR_WORST, // Red
};
static const u8 sStatBarsGfx[] = INCBIN_U8("graphics/pokedex/stat_bars.4bpp");
static const u16 sStatBarPalette[16] = {
    [COLOR_ID_ALPHA] = RGB(0, 0, 10),
    [COLOR_ID_BAR_WHITE] = RGB_WHITE,

    [COLOR_ID_FILL + COLOR_BEST * 2] = RGB(2, 25, 25),
    [COLOR_ID_FILL_SHADOW + COLOR_BEST * 2] = RGB(13, 27, 27),

    [COLOR_ID_FILL + COLOR_VERY_GOOD * 2] = RGB(11, 25, 2),
    [COLOR_ID_FILL_SHADOW + COLOR_VERY_GOOD * 2] = RGB(19, 27, 13),

    [COLOR_ID_FILL + COLOR_GOOD * 2] = RGB(22, 25, 2),
    [COLOR_ID_FILL_SHADOW + COLOR_GOOD * 2] = RGB(26, 27, 13),

    [COLOR_ID_FILL + COLOR_AVERAGE * 2] = RGB(25, 22, 2),
    [COLOR_ID_FILL_SHADOW + COLOR_AVERAGE * 2] = RGB(27, 26, 13),

    [COLOR_ID_FILL + COLOR_BAD * 2] = RGB(25, 17, 2),
    [COLOR_ID_FILL_SHADOW + COLOR_BAD * 2] = RGB(27, 22, 13),

    [COLOR_ID_FILL + COLOR_WORST * 2] = RGB(25, 4, 2),
    [COLOR_ID_FILL_SHADOW + COLOR_WORST * 2] = RGB(27, 15, 13),

    [COLOR_ID_FONT] = RGB_BLACK,
    [COLOR_ID_FONT_SHADOW] = RGB(22, 22, 22),
};
static const struct SpritePalette sStatBarSpritePal[] = //{sStatBarPalette, TAG_STAT_BAR};
{
    {sStatBarPalette, TAG_STAT_BAR},
    {sStatBarPalette, TAG_STAT_BAR_BG},
    {0}
};

// const rom data
#include "data/pokemon/pokedex_orders.h"

static const struct OamData sOamData_855CFE4 =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_855CFEC =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_855CFF4 =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_855CFFC =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_WINDOW,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_855D004 =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_855D00C =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_855D014[] =
{
    ANIMCMD_FRAME(3, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D01C[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D024[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D02C[] =
{
    ANIMCMD_FRAME(48, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D034[] =
{
    ANIMCMD_FRAME(40, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D03C[] =
{
    ANIMCMD_FRAME(32, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D044[] =
{
    ANIMCMD_FRAME(56, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D04C[] =
{
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D054[] =
{
    ANIMCMD_FRAME(96, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D05C[] =
{
    ANIMCMD_FRAME(160, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D064[] =
{
    ANIMCMD_FRAME(168, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D06C[] =
{
    ANIMCMD_FRAME(128, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D074[] =
{
    ANIMCMD_FRAME(130, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D07C[] =
{
    ANIMCMD_FRAME(132, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D084[] =
{
    ANIMCMD_FRAME(134, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D08C[] =
{
    ANIMCMD_FRAME(136, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D094[] =
{
    ANIMCMD_FRAME(138, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D09C[] =
{
    ANIMCMD_FRAME(140, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0A4[] =
{
    ANIMCMD_FRAME(142, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0AC[] =
{
    ANIMCMD_FRAME(144, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0B4[] =
{
    ANIMCMD_FRAME(146, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0BC[] =
{
    ANIMCMD_FRAME(176, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0C4[] =
{
    ANIMCMD_FRAME(178, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0CC[] =
{
    ANIMCMD_FRAME(180, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0D4[] =
{
    ANIMCMD_FRAME(182, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0DC[] =
{
    ANIMCMD_FRAME(184, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0E4[] =
{
    ANIMCMD_FRAME(186, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0EC[] =
{
    ANIMCMD_FRAME(188, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0F4[] =
{
    ANIMCMD_FRAME(190, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0FC[] =
{
    ANIMCMD_FRAME(192, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D104[] =
{
    ANIMCMD_FRAME(194, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D10C[] =
{
    ANIMCMD_FRAME(4, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_855D114[] =
{
    sSpriteAnim_855D014
};

static const union AnimCmd *const sSpriteAnimTable_855D118[] =
{
    sSpriteAnim_855D01C
};

static const union AnimCmd *const sSpriteAnimTable_855D11C[] =
{
    sSpriteAnim_855D024
};

static const union AnimCmd *const sSpriteAnimTable_855D120[] =
{
    sSpriteAnim_855D02C,
    sSpriteAnim_855D034,
    sSpriteAnim_855D03C,
    sSpriteAnim_855D044
};

static const union AnimCmd *const sSpriteAnimTable_855D130[] =
{
    sSpriteAnim_855D04C,
    sSpriteAnim_855D054
};

static const union AnimCmd *const sSpriteAnimTable_855D138[] =
{
    sSpriteAnim_855D05C,
    sSpriteAnim_855D064
};

static const union AnimCmd *const sSpriteAnimTable_855D140[] =
{
    sSpriteAnim_855D06C,
    sSpriteAnim_855D074,
    sSpriteAnim_855D07C,
    sSpriteAnim_855D084,
    sSpriteAnim_855D08C,
    sSpriteAnim_855D094,
    sSpriteAnim_855D09C,
    sSpriteAnim_855D0A4,
    sSpriteAnim_855D0AC,
    sSpriteAnim_855D0B4
};

static const union AnimCmd *const sSpriteAnimTable_855D168[] =
{
    sSpriteAnim_855D0BC,
    sSpriteAnim_855D0C4,
    sSpriteAnim_855D0CC,
    sSpriteAnim_855D0D4,
    sSpriteAnim_855D0DC,
    sSpriteAnim_855D0E4,
    sSpriteAnim_855D0EC,
    sSpriteAnim_855D0F4,
    sSpriteAnim_855D0FC,
    sSpriteAnim_855D104
};

static const union AnimCmd *const sSpriteAnimTable_855D190[] =
{
    sSpriteAnim_855D10C
};

static const struct SpriteTemplate sScrollBarSpriteTemplate =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFE4,
    .anims = sSpriteAnimTable_855D114,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Scrollbar,
};

static const struct SpriteTemplate sArrowSpriteTemplate =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFEC,
    .anims = sSpriteAnimTable_855D118,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE658,
};

static const struct SpriteTemplate sInterfaceTextSpriteTemplate =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFF4,
    .anims = sSpriteAnimTable_855D120,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE758,
};

static const struct SpriteTemplate sRotatingPokeballSpriteTemplate =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFFC,
    .anims = sSpriteAnimTable_855D11C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE780,
};

static const struct SpriteTemplate sSeenOwnTextSpriteTemplate =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D004,
    .anims = sSpriteAnimTable_855D130,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

static const struct SpriteTemplate gUnknown_0855D20C =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFF4,
    .anims = sSpriteAnimTable_855D138,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

static const struct SpriteTemplate gUnknown_0855D224 =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D00C,
    .anims = sSpriteAnimTable_855D140,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

static const struct SpriteTemplate gUnknown_0855D23C =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D00C,
    .anims = sSpriteAnimTable_855D168,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

static const struct SpriteTemplate gUnknown_0855D254 =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D00C,
    .anims = sSpriteAnimTable_855D190,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE834,
};

static const struct CompressedSpriteSheet sInterfaceSpriteSheet[] =
{
    {gPokedexMenu2_Gfx, 0x2000, 4096},
    {0}
};

static const struct SpritePalette sInterfaceSpritePalette[] =
{
    {gPokedexText_Pal, 4096},
    {0}
};

static const u8 gUnknown_0855D28C[] = {0x4, 0x8, 0x10, 0x20, 0x20};
static const u8 gUnknown_0855D291[] = {0x8, 0x4, 0x2, 0x1, 0x1};

static const struct BgTemplate sPokedex_BgTemplate[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sPokemonList_WindowTemplate[] =
{
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 32,
        .height = 32,
        .paletteNum = 0,
        .baseBlock = 1,
    },
    DUMMY_WIN_TEMPLATE
};

static const u8 sText_No000[] = _("{NO}000");
static const u8 gUnknown_0855D2BE[] = INCBIN_U8("graphics/pokedex/caught_ball.4bpp");
static const u8 sText_TenDashes[] = _("----------");

ALIGNED(4) static const u8 gExpandedPlaceholder_PokedexDescription[] = _("");

#include "data/pokemon/pokedex_text.h"
#include "data/pokemon/pokedex_entries.h"

static const u16 gUnknown_0856E610[] = INCBIN_U16("graphics/pokedex/black.gbapal");

static const struct BgTemplate sInfoScreen_BgTemplate[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    }
};

#define WIN_INFO 0
#define WIN_FOOTPRINT 1
#define WIN_CRY_WAVE 2
#define WIN_VU_METER 3

static const struct WindowTemplate sInfoScreen_WindowTemplates[] =
{
    { // WIN_INFO
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 32,
        .height = 20,
        .paletteNum = 0,
        .baseBlock = 0x0001,
    },
    { // WIN_FOOTPRINT
        .bg = 2,
        .tilemapLeft = 15, //HGSSS_Ui
        .tilemapTop = 7, //HGSSS_Ui
        .width = 2,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x0281,
    },
    { // WIN_CRY_WAVE
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 12,
        .width = 32,
        .height = 7,
        .paletteNum = 8,
        .baseBlock = 0x0285,
    },
    { // WIN_VU_METER
        .bg = 2,
        .tilemapLeft = 18,
        .tilemapTop = 3,
        .width = 10,
        .height = 8,
        .paletteNum = 9,
        .baseBlock = 0x0365,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sNewEntryInfoScreen_BgTemplate[] =
{
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const struct WindowTemplate sNewEntryInfoScreen_WindowTemplates[] =
{
    { // WIN_INFO
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 32,
        .height = 20,
        .paletteNum = 0,
        .baseBlock = 0x0001,
    },
    { // WIN_FOOTPRINT
        .bg = 2,
        .tilemapLeft = 15, //HGSSS_Ui
        .tilemapTop = 7, //HGSSS_Ui
        .width = 2,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x0281,
    },
    DUMMY_WIN_TEMPLATE
};

static const u8 sText_TenDashes2[] = _("----------");

#include "data/pokemon_graphics/footprint_table.h"

static const u8 gUnknown_0856ED08[][4] =
{
    {0x00, 0x00, 0x00, 0x00},
    {0xbb, 0x03, 0xd5, 0x03},
    {0xbe, 0x03, 0xd8, 0x03},
    {0xc1, 0x03, 0xdb, 0x03},
    {0xc4, 0x03, 0xde, 0x03},
    {0xc7, 0x03, 0xe1, 0x03},
    {0xca, 0x03, 0xe4, 0x03},
    {0xcd, 0x03, 0xe7, 0x03},
    {0xd0, 0x03, 0xea, 0x03},
    {0xd3, 0x02, 0xed, 0x02},
};

static const struct UnknownStruct3 gUnknown_0856ED30[] =
{
    {
        .text = gText_SearchForPkmnBasedOnParameters,
        .unk4 = 0,
        .unk5 = 0,
        .unk6 = 5,
    },
    {
        .text = gText_SwitchPokedexListings,
        .unk4 = 6,
        .unk5 = 0,
        .unk6 = 5,
    },
    {
        .text = gText_ReturnToPokedex,
        .unk4 = 12,
        .unk5 = 0,
        .unk6 = 5,
    },
};

static const struct UnknownStruct4 gUnknown_0856ED48[] =
{
    {
        .text = gText_ListByFirstLetter,
        .unk4 = 0,
        .unk5 = 2,
        .unk6 = 5,
        .unk7 = 5,
        .unk8 = 2,
        .unk9 = 12,
    },
    {
        .text = gText_ListByBodyColor,
        .unk4 = 0,
        .unk5 = 4,
        .unk6 = 5,
        .unk7 = 5,
        .unk8 = 4,
        .unk9 = 12,
    },
    {
        .text = gText_ListByType,
        .unk4 = 0,
        .unk5 = 6,
        .unk6 = 5,
        .unk7 = 5,
        .unk8 = 6,
        .unk9 = 6,
    },
    {
        .text = gText_ListByType,
        .unk4 = 0,
        .unk5 = 6,
        .unk6 = 5,
        .unk7 = 11,
        .unk8 = 6,
        .unk9 = 6,
    },
    {
        .text = gText_SelectPokedexListingMode,
        .unk4 = 0,
        .unk5 = 8,
        .unk6 = 5,
        .unk7 = 5,
        .unk8 = 8,
        .unk9 = 12,
    },
    {
        .text = gText_SelectPokedexMode,
        .unk4 = 0,
        .unk5 = 10,
        .unk6 = 5,
        .unk7 = 5,
        .unk8 = 10,
        .unk9 = 12,
    },
    {
        .text = gText_ExecuteSearchSwitch,
        .unk4 = 0,
        .unk5 = 12,
        .unk6 = 5,
        .unk7 = 0,
        .unk8 = 0,
        .unk9 = 0,
    },
};

static const u8 gUnknown_0856ED9C[][4] =
{
    {0xFF, 0xFF, 0xFF,    1},
    {0xFF, 0xFF,    0,    2},
    {0xFF,    3,    1,    4},
    {   2, 0xFF,    1,    4},
    {0xFF, 0xFF,    2,    5},
    {0xFF, 0xFF,    4,    6},
    {0xFF, 0xFF,    5, 0xFF},
};

static const u8 gUnknown_0856EDB8[][4] =
{
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF,    5},
    {0xFF, 0xFF,    4,    6},
    {0xFF, 0xFF,    5, 0xFF},
};

static const u8 gUnknown_0856EDD4[][4] =
{
    {0xFF, 0xFF, 0xFF,    1},
    {0xFF, 0xFF,    0,    2},
    {0xFF,    3,    1,    4},
    {   2, 0xFF,    1,    4},
    {0xFF, 0xFF,    2,    6},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF,    4, 0xFF},
};

static const u8 gUnknown_0856EDF0[][4] =
{
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF,    6},
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF,    4, 0xFF},
};

static const struct PokedexOption gDexModeOptions[] =
{
    {gText_DexHoennDescription, gText_DexHoennTitle},
    {gText_DexNatDescription, gText_DexNatTitle},
    {NULL, NULL},
};

static const struct PokedexOption gDexSortOptions[] =
{
    {gText_DexSortNumericalDescription, gText_DexSortNumericalTitle},
    {gText_DexSortAtoZDescription, gText_DexSortAtoZTitle},
    {gText_DexSortHeaviestDescription, gText_DexSortHeaviestTitle},
    {gText_DexSortLightestDescription, gText_DexSortLightestTitle},
    {gText_DexSortTallestDescription, gText_DexSortTallestTitle},
    {gText_DexSortSmallestDescription, gText_DexSortSmallestTitle},
    {NULL, NULL},
};

static const struct PokedexOption gDexSearchAlphaOptions[] =
{
    {gText_DexEmptyString, gText_DexSearchDontSpecify},
    {gText_DexEmptyString, gText_DexSearchAlphaABC},
    {gText_DexEmptyString, gText_DexSearchAlphaDEF},
    {gText_DexEmptyString, gText_DexSearchAlphaGHI},
    {gText_DexEmptyString, gText_DexSearchAlphaJKL},
    {gText_DexEmptyString, gText_DexSearchAlphaMNO},
    {gText_DexEmptyString, gText_DexSearchAlphaPQR},
    {gText_DexEmptyString, gText_DexSearchAlphaSTU},
    {gText_DexEmptyString, gText_DexSearchAlphaVWX},
    {gText_DexEmptyString, gText_DexSearchAlphaYZ},
    {NULL, NULL},
};

static const struct PokedexOption gDexSearchColorOptions[] =
{
    {gText_DexEmptyString, gText_DexSearchDontSpecify},
    {gText_DexEmptyString, gText_DexSearchColorRed},
    {gText_DexEmptyString, gText_DexSearchColorBlue},
    {gText_DexEmptyString, gText_DexSearchColorYellow},
    {gText_DexEmptyString, gText_DexSearchColorGreen},
    {gText_DexEmptyString, gText_DexSearchColorBlack},
    {gText_DexEmptyString, gText_DexSearchColorBrown},
    {gText_DexEmptyString, gText_DexSearchColorPurple},
    {gText_DexEmptyString, gText_DexSearchColorGray},
    {gText_DexEmptyString, gText_DexSearchColorWhite},
    {gText_DexEmptyString, gText_DexSearchColorPink},
    {NULL, NULL},
};

static const struct PokedexOption gDexSearchTypeOptions[] =
{
    {gText_DexEmptyString, gText_DexSearchTypeNone},
    {gText_DexEmptyString, gTypeNames[TYPE_NORMAL]},
    {gText_DexEmptyString, gTypeNames[TYPE_FIGHTING]},
    {gText_DexEmptyString, gTypeNames[TYPE_FLYING]},
    {gText_DexEmptyString, gTypeNames[TYPE_POISON]},
    {gText_DexEmptyString, gTypeNames[TYPE_GROUND]},
    {gText_DexEmptyString, gTypeNames[TYPE_ROCK]},
    {gText_DexEmptyString, gTypeNames[TYPE_BUG]},
    {gText_DexEmptyString, gTypeNames[TYPE_GHOST]},
    {gText_DexEmptyString, gTypeNames[TYPE_STEEL]},
    {gText_DexEmptyString, gTypeNames[TYPE_FIRE]},
    {gText_DexEmptyString, gTypeNames[TYPE_WATER]},
    {gText_DexEmptyString, gTypeNames[TYPE_GRASS]},
    {gText_DexEmptyString, gTypeNames[TYPE_ELECTRIC]},
    {gText_DexEmptyString, gTypeNames[TYPE_PSYCHIC]},
    {gText_DexEmptyString, gTypeNames[TYPE_ICE]},
    {gText_DexEmptyString, gTypeNames[TYPE_DRAGON]},
    {gText_DexEmptyString, gTypeNames[TYPE_DARK]},
    {gText_DexEmptyString, gTypeNames[TYPE_FAIRY]}, // NUEVO TIPO HADA
    {NULL, NULL},
};


#define SEARCH_NAME 0
#define SEARCH_COLOR 1
#define SEARCH_TYPE_1 2
#define SEARCH_TYPE_2 3
#define SEARCH_ORDER 4
#define SEARCH_DEX_MODE 5

#define SORT_NUMERICAL 0
#define SORT_ALPHABETICAL 1
#define SORT_HEAVIEST 2
#define SORT_LIGHTEST 3
#define SORT_TALLEST 4
#define SORT_SMALLEST 5

static const u8 sPokedexModes[] = {DEX_MODE_HOENN, DEX_MODE_NATIONAL};
static const u8 sSortOptions[] =
{
    SORT_NUMERICAL,
    SORT_ALPHABETICAL,
    SORT_HEAVIEST,
    SORT_LIGHTEST,
    SORT_TALLEST,
    SORT_SMALLEST,
};

static const u8 gDexSearchTypeIds[] =
{
    TYPE_NONE,
    TYPE_NORMAL,
    TYPE_FIGHTING,
    TYPE_FLYING,
    TYPE_POISON,
    TYPE_GROUND,
    TYPE_ROCK,
    TYPE_BUG,
    TYPE_GHOST,
    TYPE_STEEL,
    TYPE_FIRE,
    TYPE_WATER,
    TYPE_GRASS,
    TYPE_ELECTRIC,
    TYPE_PSYCHIC,
    TYPE_ICE,
    TYPE_DRAGON,
    TYPE_DARK,
    TYPE_FAIRY, // NUEVO TIPO HADA
};

static const struct UnknownStruct1 sSearchOptions[] =
{
    {gDexSearchAlphaOptions, 6, 7, 10},
    {gDexSearchColorOptions, 8, 9, 11},
    {gDexSearchTypeOptions, 10, 11, NUMBER_OF_MON_TYPES},
    {gDexSearchTypeOptions, 12, 13, NUMBER_OF_MON_TYPES},
    {gDexSortOptions, 4, 5, 6},
    {gDexModeOptions, 2, 3, 2},
};

static const struct BgTemplate sSearchMenu_BgTemplate[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sSearchMenu_WindowTemplate[] =
{
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 32,
        .height = 20,
        .paletteNum = 0,
        .baseBlock = 0x0001,
    },
    DUMMY_WIN_TEMPLATE
};

// .text

void ResetPokedex(void)
{
    u16 i;

    gUnknown_02039B50 = 0;
    gUnknown_02039B52 = 64;
    gUnusedPokedexU8 = 0;
    gSaveBlock2Ptr->pokedex.mode = DEX_MODE_HOENN;
    gSaveBlock2Ptr->pokedex.order = 0;
    gSaveBlock2Ptr->pokedex.nationalMagic = 0;
    gSaveBlock2Ptr->pokedex.unknown2 = 0;
    gSaveBlock2Ptr->pokedex.unownPersonality = 0;
    gSaveBlock2Ptr->pokedex.spindaPersonality = 0;
    gSaveBlock2Ptr->pokedex.unknown3 = 0;
    DisableNationalPokedex();
    for (i = 0; i < DEX_FLAGS_NO; i++)
    {
        gSaveBlock2Ptr->pokedex.owned[i] = 0;
        gSaveBlock2Ptr->pokedex.seen[i] = 0;
        #ifndef FREE_EXTRA_SEEN_FLAGS
        gSaveBlock1Ptr->seen1[i] = 0;
        gSaveBlock1Ptr->seen2[i] = 0;
        #endif
    }
}

void ResetPokedexScrollPositions(void)
{
    gUnknown_02039B50 = 0;
    gUnknown_02039B52 = 64;
}

void sub_80BB370(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void ResetPokedexView(struct PokedexView *pokedexView)
{
    u16 i;

    for (i = 0; i < NATIONAL_DEX_COUNT; i++)
    {
        pokedexView->pokedexList[i].dexNum = 0xFFFF;
        pokedexView->pokedexList[i].species = 0xFFFF;
        pokedexView->pokedexList[i].seen = 0;
        pokedexView->pokedexList[i].owned = 0;
    }
    pokedexView->unk608 = 0;
    pokedexView->unk60A_1 = 0;
    pokedexView->unk60A_2 = 0;
    pokedexView->pokemonListCount = 0;
    pokedexView->selectedPokemon = 0;
    pokedexView->unk610 = 0;
    pokedexView->dexMode = 0;
    pokedexView->unk614 = 0;
    pokedexView->dexOrder = 0;
    pokedexView->unk618 = 0;
    pokedexView->seenCount = 0;
    pokedexView->ownCount = 0;
    for (i = 0; i < 4; i++)
        pokedexView->monSpriteIds[i] = 0xFFFF;
    pokedexView->unk628 = 0;
    pokedexView->unk62A = 0;
    pokedexView->unk62C = 0;
    pokedexView->initialVOffset = 0;
    pokedexView->unk62E = 0;
    pokedexView->unk62F = 0;
    pokedexView->unk630 = 0;
    pokedexView->unk632 = 0;
    pokedexView->unk634 = 0;
    pokedexView->unk636 = 0;
    pokedexView->unk638 = 0;
	pokedexView->item1_icon = 0;
	pokedexView->item2_icon = 0;
    for (i = 0; i <= 3; i++)
        pokedexView->unk63A[i] = 0;
    pokedexView->unk64A = 0;
    pokedexView->unk64B = 0;
    pokedexView->unk64C_1 = 0;
    pokedexView->selectedScreen = 0;
    pokedexView->unk64E = 0;
    pokedexView->menuIsOpen = 0;
    pokedexView->menuCursorPos = 0;
    pokedexView->menuY = 0;
    for (i = 0; i <= 7; i++)
        pokedexView->unk654[i] = 0;
    for (i = 0; i <= 7; i++)
        pokedexView->unk65C[i] = 0;
}

void UpdateSpecies(bool8 resetForm)
{
    u16 * dexNum  = &sPokedexListItem->dexNum;
    u16 * species = &sPokedexListItem->species;
    if (*dexNum != 0xFFFF && (resetForm || *species == 0xFFFF || SpeciesToNationalPokedexNum(*species) != *dexNum))
        *species = NationalPokedexNumToSpecies(*dexNum);
}

s32 GetNextFormSpecies()
{
    s32 sp;

	if (sPokedexListItem->species == SPECIES_MEWTWO && FlagGet(FLAG_FORM_SPOILER_DEX) != 1)
       return sPokedexListItem->species;

    for (sp = 1 + sPokedexListItem->species; sp < NUM_SPECIES; sp++)
        if (SpeciesToNationalPokedexNum(sp) == sPokedexListItem->dexNum)
            break;
    if (sp == NUM_SPECIES)
        for (sp = 1; sp < sPokedexListItem->species; sp++)
            if (SpeciesToNationalPokedexNum(sp) == sPokedexListItem->dexNum)
                break;
		return sp;
}

bool8 TryToChangeForm(u8 taskId, TaskFunc task)
{
    s32 sp = GetNextFormSpecies();
    if (sp == sPokedexListItem->species)
        return FALSE;

    sPokedexListItem->species = sp;

    BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
    sPokedexView->unk64E = 11;
    gTasks[taskId].func = task;
    PlaySE(SE_PIN);
    return TRUE;
}

void CB2_Pokedex(void)
{
    u8 *addr;
    u32 size;

    switch (gMain.state)
    {
        case 0:
        default:
            SetVBlankCallback(NULL);
            ResetOtherVideoRegisters(0);
            DmaFillLarge16(3, 0, (u8 *)VRAM, VRAM_SIZE, 0x1000);
            DmaClear32(3, OAM, OAM_SIZE);
            DmaClear16(3, PLTT, PLTT_SIZE);
            gMain.state = 1;
            break;
        case 1:
            ScanlineEffect_Stop();
            ResetTasks();
            ResetSpriteData();
            ResetPaletteFade();
            FreeAllSpritePalettes();
            gReservedSpritePaletteCount = 8;
            ResetAllPicSprites();
            gMain.state++;
            break;
        case 2:
            sPokedexView = AllocZeroed(sizeof(struct PokedexView));
            ResetPokedexView(sPokedexView);
            CreateTask(sub_80BB78C, 0);
            sPokedexView->dexMode = gSaveBlock2Ptr->pokedex.mode;
            if (!IsNationalPokedexEnabled())
                sPokedexView->dexMode = DEX_MODE_HOENN;
            sPokedexView->dexOrder = gSaveBlock2Ptr->pokedex.order;
            sPokedexView->selectedPokemon = gUnknown_02039B50;
            sPokedexView->unk62C = gUnknown_02039B52;
            sPokedexView->selectedScreen = 0;
            if (!IsNationalPokedexEnabled())
            {
                sPokedexView->seenCount = GetHoennPokedexCount(FLAG_GET_SEEN);
                sPokedexView->ownCount = GetHoennPokedexCount(FLAG_GET_CAUGHT);
            }
            else
            {
                sPokedexView->seenCount = GetNationalPokedexCount(FLAG_GET_SEEN);
                sPokedexView->ownCount = GetNationalPokedexCount(FLAG_GET_CAUGHT);
            }
            sPokedexView->initialVOffset = 8;
            gMain.state++;
            break;
        case 3:
            EnableInterrupts(1);
            SetVBlankCallback(sub_80BB370);
            SetMainCallback2(sub_80BB774);
            CreatePokedexList(sPokedexView->dexMode, sPokedexView->dexOrder);
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x80);
            break;
    }
}

void sub_80BB774(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_80BB78C(u8 taskId)
{
    sPokedexView->unk64C_1 = FALSE;
    if (sub_80BC514(0))
        gTasks[taskId].func = sub_80BB7D4;
}

void sub_80BB7D4(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, sPokedexView->menuY);

    if (sPokedexView->menuY)
    {
        sPokedexView->menuY -= 8;
		 if (sPokedexView->menuIsOpen == FALSE && sPokedexView->menuY == 8) //HGSS_Ui
        {
            CreateStatBars(&sPokedexView->pokedexList[sPokedexView->selectedPokemon]);
            CreateStatBarsBg();
        }
    }
    else
    {
        if ((gMain.newKeys & A_BUTTON) && sPokedexView->pokedexList[sPokedexView->selectedPokemon].seen)
        {
			TryDestroyStatBars(); //HGSS_Ui
            UpdateSelectedMonSpriteId();
            BeginNormalPaletteFade(~(1 << (gSprites[sPokedexView->selectedMonSpriteId].oam.paletteNum + 16)), 0, 0, 0x10, RGB_BLACK);
            gSprites[sPokedexView->selectedMonSpriteId].callback = MoveMonIntoPosition;
            gTasks[taskId].func = LoadPageOnceMonFinishedMoving;
            PlaySE(SE_PIN);
            FreeWindowAndBgBuffers();
        }
        else if (gMain.newKeys & START_BUTTON)
        {
            //Open menu
			TryDestroyStatBars(); //HGSS_Ui
            TryDestroyStatBarsBg(); //HGSS_Ui
            sPokedexView->menuY = 0;
            sPokedexView->menuIsOpen = 1;
            sPokedexView->menuCursorPos = 0;
            gTasks[taskId].func = sub_80BBA78;
            PlaySE(SE_SELECT);
        }
        else if (gMain.newKeys & SELECT_BUTTON)
        {
            PlaySE(SE_SELECT);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].data[0] = LoadSearchMenu();
            sPokedexView->unk64E = 0;
            sPokedexView->unk62A = sPokedexView->unk62C;
            sPokedexView->unk610 = sPokedexView->selectedPokemon;
            sPokedexView->unk614 = sPokedexView->dexMode;
            sPokedexView->unk618 = sPokedexView->dexOrder;
            gTasks[taskId].func = sub_80BBD1C;
            PlaySE(SE_PC_LOGIN);
            FreeWindowAndBgBuffers();
        }
        else if (gMain.newKeys & B_BUTTON)
        {
			TryDestroyStatBars(); //HGSS_Ui
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = sub_80BBDE8;
            PlaySE(SE_PC_OFF);
        }
        else
        {
            //Handle D-pad
            sPokedexView->selectedPokemon = sub_80BD69C(sPokedexView->selectedPokemon, 0xE);
            if (sPokedexView->unk62E)
                gTasks[taskId].func = sub_80BBA28;
            else if (!sPokedexView->unk62E && !sPokedexView->unk638 && sPokedexView->justScrolled) //HGSS_Ui
                CreateStatBars(&sPokedexView->pokedexList[sPokedexView->selectedPokemon]); //HGSS_Ui
        }
    }
}

void sub_80BBA28(u8 taskId)
{
	TryDestroyStatBars(); //HGSS_Ui
    if (sub_80BD404(sPokedexView->unk62F, sPokedexView->unk634, sPokedexView->unk636))
        gTasks[taskId].func = sub_80BB7D4;
}

void sub_80BBA78(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, sPokedexView->menuY);

    //If menu is not open, slide it up, on screen
    if (sPokedexView->menuY != 80)
    {
        sPokedexView->menuY += 8;
    }
    else
    {
        if (gMain.newKeys & A_BUTTON)
        {
            switch (sPokedexView->menuCursorPos)
            {
                case 0: //BACK TO LIST
                default:
                    gMain.newKeys |= START_BUTTON;  //Exit menu
                    break;
                case 1: //LIST TOP
                    sPokedexView->selectedPokemon = 0;
                    sPokedexView->unk62C = 0x40;
                    ClearMonSprites();
                    CreateInitialPokemonSprites(sPokedexView->selectedPokemon, 0xE);
                    gMain.newKeys |= START_BUTTON;  //Exit menu
                    break;
                case 2: //LIST BOTTOM
                    sPokedexView->selectedPokemon = sPokedexView->pokemonListCount - 1;
                    sPokedexView->unk62C = sPokedexView->pokemonListCount * 16 + 0x30;
                    ClearMonSprites();
                    CreateInitialPokemonSprites(sPokedexView->selectedPokemon, 0xE);
                    gMain.newKeys |= START_BUTTON;  //Exit menu
                    break;
                case 3: //CLOSE POKEDEX
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                    gTasks[taskId].func = sub_80BBDE8;
                    PlaySE(SE_PC_OFF);
                    break;
            }
        }

        //Exit menu when Start or B is pressed
        if (gMain.newKeys & (START_BUTTON | B_BUTTON))
        {
            sPokedexView->menuIsOpen = 0;
            gTasks[taskId].func = sub_80BB7D4;
            PlaySE(SE_SELECT);
        }
        else if ((gMain.newAndRepeatedKeys & DPAD_UP) && sPokedexView->menuCursorPos != 0)
        {
            sPokedexView->menuCursorPos--;
            PlaySE(SE_SELECT);
        }
        else if ((gMain.newAndRepeatedKeys & DPAD_DOWN) && sPokedexView->menuCursorPos <= 2)
        {
            sPokedexView->menuCursorPos++;
            PlaySE(SE_SELECT);
        }
    }
}

void LoadPageOnceMonFinishedMoving(u8 taskId)
{
    if (gSprites[sPokedexView->selectedMonSpriteId].pos1.x == 48 && gSprites[sPokedexView->selectedMonSpriteId].pos1.y == 56)
    {
        sPokedexView->unk64B = sPokedexView->unk64A;
        gTasks[taskId].data[0] = SetupInfoScreen(&sPokedexView->pokedexList[sPokedexView->selectedPokemon], sPokedexView->selectedMonSpriteId);
        gTasks[taskId].func = sub_80BBC74;
    }
}

void sub_80BBC74(u8 taskId)
{
    if (gTasks[gTasks[taskId].data[0]].isActive)
    {
        if (sPokedexView->unk64A == 1 && !sub_80BE9C4(gTasks[taskId].data[0]) && UpdateSelectedMon())
            sub_80BE9F8(&sPokedexView->pokedexList[sPokedexView->selectedPokemon], gTasks[taskId].data[0]);
    }
    else
    {
        gUnknown_02039B50 = sPokedexView->selectedPokemon;
        gUnknown_02039B52 = sPokedexView->unk62C;
        gTasks[taskId].func = sub_80BB78C;
    }
}

void sub_80BBD1C(u8 taskId)
{
    if (!gTasks[gTasks[taskId].data[0]].isActive)
    {
        ClearMonSprites();
        TryDestroyStatBars(); //HGSS_Ui
        TryDestroyStatBarsBg(); //HGSS_Ui
        if (sPokedexView->unk64E != 0)
        {
            sPokedexView->selectedPokemon = 0;
            sPokedexView->unk62C = 0x40;
            gTasks[taskId].func = sub_80BBE70;
        }
        else
        {
            sPokedexView->unk62C = sPokedexView->unk62A;
            sPokedexView->selectedPokemon = sPokedexView->unk610;
            sPokedexView->dexMode = sPokedexView->unk614;
            if (!IsNationalPokedexEnabled())
                sPokedexView->dexMode = DEX_MODE_HOENN;
            sPokedexView->dexOrder = sPokedexView->unk618;
            gTasks[taskId].func = sub_80BB78C;
        }
    }
}

void sub_80BBDE8(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gSaveBlock2Ptr->pokedex.mode = sPokedexView->dexMode;
        if (!IsNationalPokedexEnabled())
            gSaveBlock2Ptr->pokedex.mode = DEX_MODE_HOENN;
        gSaveBlock2Ptr->pokedex.order = sPokedexView->dexOrder;
        ClearMonSprites();
        FreeWindowAndBgBuffers();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
        Free(sPokedexView);
    }
}

void sub_80BBE70(u8 taskId)
{
    sPokedexView->unk64C_1 = TRUE;
    if (sub_80BC514(3))
        gTasks[taskId].func = sub_80BBEB8;
}

void sub_80BBEB8(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, sPokedexView->menuY);

    if (sPokedexView->menuY)
    {
        sPokedexView->menuY -= 8;
        if (sPokedexView->menuIsOpen == FALSE && sPokedexView->menuY == 8) //HGSS_Ui
        {
            CreateStatBars(&sPokedexView->pokedexList[sPokedexView->selectedPokemon]);
            CreateStatBarsBg();
        }
    }
    else
    {
        if ((gMain.newKeys & A_BUTTON) && sPokedexView->pokedexList[sPokedexView->selectedPokemon].seen)
        {
            u32 a;
            TryDestroyStatBars(); //HGSS_Ui
            UpdateSelectedMonSpriteId();
            a = (1 << (gSprites[sPokedexView->selectedMonSpriteId].oam.paletteNum + 16));
            gSprites[sPokedexView->selectedMonSpriteId].callback = MoveMonIntoPosition;
            BeginNormalPaletteFade(~a, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = sub_80BC2D4;
            PlaySE(SE_PIN);
            FreeWindowAndBgBuffers();
        }
        else if (gMain.newKeys & START_BUTTON)
        {
			TryDestroyStatBars(); //HGSS_Ui
            TryDestroyStatBarsBg(); //HGSS_Ui
            sPokedexView->menuY = 0;
            sPokedexView->menuIsOpen = 1;
            sPokedexView->menuCursorPos = 0;
            gTasks[taskId].func = HandleButtonPress_StartMenu;
            PlaySE(SE_SELECT);
        }
        else if (gMain.newKeys & SELECT_BUTTON)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].data[0] = LoadSearchMenu();
            sPokedexView->unk64E = 0;
            gTasks[taskId].func = sub_80BBD1C;
            PlaySE(SE_PC_LOGIN);
            FreeWindowAndBgBuffers();
        }
        else if (gMain.newKeys & B_BUTTON)
        {
			TryDestroyStatBars(); //HGSS_Ui
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = sub_80BC3DC;
            PlaySE(SE_PC_OFF);
        }
        else
        {
            //Handle D-pad
            sPokedexView->selectedPokemon = sub_80BD69C(sPokedexView->selectedPokemon, 0xE);
            if (sPokedexView->unk62E)
                gTasks[taskId].func = sub_80BC0A8;
            else if (!sPokedexView->unk62E && !sPokedexView->unk638 && sPokedexView->justScrolled) //HGSS_Ui
                CreateStatBars(&sPokedexView->pokedexList[sPokedexView->selectedPokemon]); //HGSS_Ui
        }
    }
}

void sub_80BC0A8(u8 taskId)
{
	TryDestroyStatBars(); //HGSS_Ui
    if (sub_80BD404(sPokedexView->unk62F, sPokedexView->unk634, sPokedexView->unk636))
        gTasks[taskId].func = sub_80BBEB8;
}

static void HandleButtonPress_StartMenu(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, sPokedexView->menuY);

    if (sPokedexView->menuY != 96)
    {
        sPokedexView->menuY += 8;
    }
    else
    {
        if (gMain.newKeys & A_BUTTON)
        {
            switch (sPokedexView->menuCursorPos)
            {
            case 0: //BACK TO LIST
                default:
                    gMain.newKeys |= START_BUTTON;
                    break;
                case 1: //LIST TOP
                    sPokedexView->selectedPokemon = 0;
                    sPokedexView->unk62C = 0x40;
                    ClearMonSprites();
                    CreateInitialPokemonSprites(sPokedexView->selectedPokemon, 0xE);
                    gMain.newKeys |= START_BUTTON;
                    break;
                case 2: //LIST BOTTOM
                    sPokedexView->selectedPokemon = sPokedexView->pokemonListCount - 1;
                    sPokedexView->unk62C = sPokedexView->pokemonListCount * 16 + 0x30;
                    ClearMonSprites();
                    CreateInitialPokemonSprites(sPokedexView->selectedPokemon, 0xE);
                    gMain.newKeys |= START_BUTTON;
                    break;
                case 3: //BACK TO POKEDEX
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                    gTasks[taskId].func = sub_80BC3DC;
                    PlaySE(SE_TRACK_DOOR);
                    break;
                case 4: //CLOSE POKEDEX
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                    gTasks[taskId].func = sub_80BC47C;
                    PlaySE(SE_PC_OFF);
                    break;
            }
        }

        //Exit menu when Start or B is pressed
        if (gMain.newKeys & (START_BUTTON | B_BUTTON))
        {
            sPokedexView->menuIsOpen = 0;
            gTasks[taskId].func = sub_80BBEB8;
            PlaySE(SE_SELECT);
        }
        else if ((gMain.newAndRepeatedKeys & DPAD_UP) && sPokedexView->menuCursorPos)
        {
            sPokedexView->menuCursorPos--;
            PlaySE(SE_SELECT);
        }
        else if ((gMain.newAndRepeatedKeys & DPAD_DOWN) && sPokedexView->menuCursorPos <= 3)
        {
            sPokedexView->menuCursorPos++;
            PlaySE(SE_SELECT);
        }
    }
}

void sub_80BC2D4(u8 taskId)
{
    if (gSprites[sPokedexView->selectedMonSpriteId].pos1.x == 48 && gSprites[sPokedexView->selectedMonSpriteId].pos1.y == 56)
    {
        sPokedexView->unk64B = sPokedexView->unk64A;
        gTasks[taskId].data[0] = SetupInfoScreen(&sPokedexView->pokedexList[sPokedexView->selectedPokemon], sPokedexView->selectedMonSpriteId);
        sPokedexView->selectedMonSpriteId = -1;
        gTasks[taskId].func = sub_80BC360;
    }
}

void sub_80BC360(u8 taskId)
{
    if (gTasks[gTasks[taskId].data[0]].isActive)
    {
        if (sPokedexView->unk64A == 1 && !sub_80BE9C4(gTasks[taskId].data[0]) && UpdateSelectedMon())
            sub_80BE9F8(&sPokedexView->pokedexList[sPokedexView->selectedPokemon], gTasks[taskId].data[0]);
    }
    else
    {
        gTasks[taskId].func = sub_80BBE70;
    }
}

void sub_80BC3DC(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sPokedexView->unk62C = sPokedexView->unk62A;
        sPokedexView->selectedPokemon = sPokedexView->unk610;
        sPokedexView->dexMode = sPokedexView->unk614;
        if (!IsNationalPokedexEnabled())
            sPokedexView->dexMode = DEX_MODE_HOENN;
        sPokedexView->dexOrder = sPokedexView->unk618;
        gTasks[taskId].func = sub_80BB78C;
        ClearMonSprites();
        FreeWindowAndBgBuffers();
    }
}

void sub_80BC47C(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sPokedexView->unk62C = sPokedexView->unk62A;
        sPokedexView->selectedPokemon = sPokedexView->unk610;
        sPokedexView->dexMode = sPokedexView->unk614;
        if (!IsNationalPokedexEnabled())
            sPokedexView->dexMode = DEX_MODE_HOENN;
        sPokedexView->dexOrder = sPokedexView->unk618;
        gTasks[taskId].func = sub_80BBDE8;
    }
}

bool8 sub_80BC514(u8 a)
{
    switch (gMain.state)
    {
        case 0:
        default:
            if (gPaletteFade.active)
                return 0;
            SetVBlankCallback(NULL);
            sPokedexView->unk64A = a;
            ResetOtherVideoRegisters(0);
            SetGpuReg(REG_OFFSET_BG2VOFS, sPokedexView->initialVOffset);
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sPokedex_BgTemplate, 4);
            SetBgTilemapBuffer(3, AllocZeroed(0x800));
            SetBgTilemapBuffer(2, AllocZeroed(0x800));
            SetBgTilemapBuffer(1, AllocZeroed(0x800));
            SetBgTilemapBuffer(0, AllocZeroed(0x800));
            DecompressAndLoadBgGfxUsingHeap(3, gPokedexMenuList_Gfx, 0x2000, 0, 0);
            CopyToBgTilemapBuffer(1, gPokedexTilemap_Main, 0, 0);
            CopyToBgTilemapBuffer(3, gPokedexTilemap_MainUnderlay, 0, 0);
            if (a == 0)
                CopyToBgTilemapBuffer(0, gPokedexTilemap_StartMenu1, 0, 0x280);
            else
                CopyToBgTilemapBuffer(0, gPokedexTilemap_StartMenu2, 0, 0x280);
            ResetPaletteFade();
            if (a == 0)
                sPokedexView->unk64C_1 = FALSE;
            else
                sPokedexView->unk64C_1 = TRUE;
            LoadPokedexBgPalette(sPokedexView->unk64C_1);
            InitWindows(sPokemonList_WindowTemplate);
            DeactivateAllTextPrinters();
            PutWindowTilemap(0);
            CopyWindowToVram(0, 3);
            gMain.state = 1;
            break;
        case 1:
            ResetSpriteData();
            FreeAllSpritePalettes();
            gReservedSpritePaletteCount = 8;
            LoadCompressedSpriteSheet(&sInterfaceSpriteSheet[0]);
            LoadSpritePalettes(sInterfaceSpritePalette);
			LoadSpritePalettes(sStatBarSpritePal); //HGSS_Ui
            CreateInterfaceSprites(a);
            gMain.state++;
            break;
        case 2:
            gMain.state++;
            break;
        case 3:
            if (a == 0)
                CreatePokedexList(sPokedexView->dexMode, sPokedexView->dexOrder);
            CreateInitialPokemonSprites(sPokedexView->selectedPokemon, 0xE);
			sPokedexView->statBarsSpriteId = 0xFF;  //HGSS_Ui stat bars
			CreateStatBars(&sPokedexView->pokedexList[sPokedexView->selectedPokemon]); //HGSS_Ui stat bars
			sPokedexView->statBarsBgSpriteId = 0xFF;  //HGSS_Ui stat bars background
			CreateStatBarsBg(); //HGSS_Ui stat bars background
            sPokedexView->menuIsOpen = 0;
            sPokedexView->menuY = 0;
            CopyBgTilemapBufferToVram(0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(3);
            gMain.state++;
            break;
        case 4:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
            SetVBlankCallback(sub_80BB370);
            gMain.state++;
            break;
        case 5:
            SetGpuReg(REG_OFFSET_WININ, 0x3F3F);
            SetGpuReg(REG_OFFSET_WINOUT, 0x1D3F);
            SetGpuReg(REG_OFFSET_WIN0H, 0);
            SetGpuReg(REG_OFFSET_WIN0V, 0);
            SetGpuReg(REG_OFFSET_WIN1H, 0);
            SetGpuReg(REG_OFFSET_WIN1V, 0);
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_OBJWIN_ON);
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            gMain.state++;
            break;
        case 6:
            if (!gPaletteFade.active)
            {
                gMain.state = 0;
                return TRUE;
            }
            break;
    }
    return FALSE;
}

static void LoadPokedexBgPalette(u8 a)
{
    if (a == 1)
        LoadPalette(gPokedexHoennBg_Pal + 1, 1, 0xBE);
    else if (!IsNationalPokedexEnabled())
        LoadPalette(gPokedexText_Pal + 1, 1, 0xBE);
    else
        LoadPalette(gPokedexNationalBg_Pal + 1, 1, 0xBE);
    LoadPalette(GetOverworldTextboxPalettePtr(), 0xF0, 32);
}

static void FreeWindowAndBgBuffers(void)
{
    void* tilemapBuffer;

    FreeAllWindowBuffers();
    tilemapBuffer = GetBgTilemapBuffer(0);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(1);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(2);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(3);
    if (tilemapBuffer)
        Free(tilemapBuffer);
}

static void CreatePokedexList(u8 dexMode, u8 sortMode)
{
    u16 vars[3]; //I have no idea why three regular variables are stored in an array, but whatever.
#define temp_dexCount   vars[0]
#define temp_isHoennDex vars[1]
#define temp_dexNum     vars[2]
    s16 i;

    sPokedexView->pokemonListCount = 0;

    switch (dexMode)
    {
        default:
        case DEX_MODE_HOENN:
            temp_dexCount = HOENN_DEX_COUNT;
            temp_isHoennDex = TRUE;
            break;
        case DEX_MODE_NATIONAL:
            if (IsNationalPokedexEnabled())
            {
                temp_dexCount = NATIONAL_DEX_COUNT;
                temp_isHoennDex = FALSE;
            }
            else
            {
                temp_dexCount = HOENN_DEX_COUNT;
                temp_isHoennDex = TRUE;
            }
            break;
    }

    switch (sortMode)
    {
        case SORT_NUMERICAL:
            if (temp_isHoennDex)
            {
                for (i = 0; i < temp_dexCount; i++)
                {
                    temp_dexNum = HoennToNationalOrder(i + 1);
                    sPokedexView->pokedexList[i].dexNum = temp_dexNum;
                    sPokedexView->pokedexList[i].seen = GetSetPokedexFlag(temp_dexNum, FLAG_GET_SEEN);
                    sPokedexView->pokedexList[i].owned = GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT);
                    if (sPokedexView->pokedexList[i].seen)
                        sPokedexView->pokemonListCount = i + 1;
                }
            }
            else
            {
                bool32 r10;
                s16 r5;

                r10 = r5 = i = 0;
                for (i = 0; i < temp_dexCount; i++)
                {
                    temp_dexNum = i + 1;
                    if (GetSetPokedexFlag(temp_dexNum, FLAG_GET_SEEN))
                        r10 = 1;
                    if (r10)
                    {
                        asm("");    //Needed to match for some reason
                        sPokedexView->pokedexList[r5].dexNum = temp_dexNum;
                        sPokedexView->pokedexList[r5].seen = GetSetPokedexFlag(temp_dexNum, FLAG_GET_SEEN);
                        sPokedexView->pokedexList[r5].owned = GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT);
                        if (sPokedexView->pokedexList[r5].seen)
                            sPokedexView->pokemonListCount = r5 + 1;
                        r5++;
                    }
                }
            }
            break;
        case SORT_ALPHABETICAL:
            for (i = 0; i < ARRAY_COUNT(gPokedexOrder_Alphabetical); i++)
            {
                temp_dexNum = gPokedexOrder_Alphabetical[i];

                if ((!temp_isHoennDex || NationalToHoennOrder(temp_dexNum) <= temp_dexCount) && GetSetPokedexFlag(temp_dexNum, FLAG_GET_SEEN))
                {
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT);
                    sPokedexView->pokemonListCount++;
                }
            }
            break;
        case SORT_HEAVIEST:
            for (i = ARRAY_COUNT(gPokedexOrder_Weight) - 1; i >= 0; i--)
            {
                temp_dexNum = gPokedexOrder_Weight[i];

                 if ((!temp_isHoennDex || NationalToHoennOrder(temp_dexNum) <= temp_dexCount) && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
                {
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = TRUE;
                    sPokedexView->pokemonListCount++;
                }
            }
            break;
        case SORT_LIGHTEST:
            for (i = 0; i < ARRAY_COUNT(gPokedexOrder_Weight); i++)
            {
                temp_dexNum = gPokedexOrder_Weight[i];

                if ((!temp_isHoennDex || NationalToHoennOrder(temp_dexNum) <= temp_dexCount) && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
                {
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = TRUE;
                    sPokedexView->pokemonListCount++;
                }
            }
            break;
        case SORT_TALLEST:
            for (i = ARRAY_COUNT(gPokedexOrder_Height) - 1; i >= 0; i--)
            {
                temp_dexNum = gPokedexOrder_Height[i];

                if ((!temp_isHoennDex || NationalToHoennOrder(temp_dexNum) <= temp_dexCount) && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
                {
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = TRUE;
                    sPokedexView->pokemonListCount++;
                }
            }
            break;
        case SORT_SMALLEST:
            for (i = 0; i < ARRAY_COUNT(gPokedexOrder_Height); i++)
            {
                temp_dexNum = gPokedexOrder_Height[i];

                if ((!temp_isHoennDex || NationalToHoennOrder(temp_dexNum) <= temp_dexCount) && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
                {
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                    sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = TRUE;
                    sPokedexView->pokemonListCount++;
                }
            }
            break;
    }

    for (i = sPokedexView->pokemonListCount; i < NATIONAL_DEX_COUNT; i++)
    {
        sPokedexView->pokedexList[i].dexNum = 0xFFFF;
        sPokedexView->pokedexList[i].seen = FALSE;
        sPokedexView->pokedexList[i].owned = FALSE;
    }
}

static void PrintMonDexNumAndName(u8 windowId, u8 fontId, const u8* str, u8 left, u8 top)
{
    u8 color[3];

    color[0] = 0;
    color[1] = 15;
    color[2] = 3;
    AddTextPrinterParameterized4(windowId, fontId, left * 8 - (left == 7 ? 3 : 2), (top * 8) + 1, 0, 0, color, -1, str);
}

#define MON_LIST_X 2
static void CreateMonListEntry(u8 direction, u16 b, u16 c)
{
    s16 _b;
    u16 i;
    u16 r2;

    switch (direction)
    {
        case 0: // Initial
        default:
            _b = b - 5;
            for (i = 0; i <= 10; i++)
            {
                if (_b < 0 || _b >= NATIONAL_DEX_COUNT || sPokedexView->pokedexList[_b].dexNum == 0xFFFF)
                {
                   ClearMonListEntry(MON_LIST_X, i * 2, c);
                }
                else
                {
                    ClearMonListEntry(MON_LIST_X, i * 2, c);
                    if (sPokedexView->pokedexList[_b].seen)
                    {
                    CreateMonDexNum(_b, MON_LIST_X+1, i * 2, c);
                    CreateCaughtBall(sPokedexView->pokedexList[_b].owned, MON_LIST_X, i * 2, c);
                    CreateMonName(sPokedexView->pokedexList[_b].dexNum, MON_LIST_X+5, i * 2);
                    }
                    else
                    {
                    CreateMonDexNum(_b, MON_LIST_X+1, i * 2, c);
                    CreateCaughtBall(FALSE, MON_LIST_X, i * 2, c);
                    CreateMonName(0, MON_LIST_X+5, i * 2);
                    }
                }
                _b++;
            }
            break;
        case 1: // Up
            _b = b - 5;
            if (_b < 0 || _b >= NATIONAL_DEX_COUNT || sPokedexView->pokedexList[_b].dexNum == 0xFFFF)
            {
                ClearMonListEntry(MON_LIST_X, sPokedexView->unk630 * 2, c);
            }
            else
            {
                ClearMonListEntry(MON_LIST_X, sPokedexView->unk630 * 2, c);
                if (sPokedexView->pokedexList[_b].seen)
                {
                CreateMonDexNum(_b, MON_LIST_X+1, sPokedexView->unk630 * 2, c);
                CreateCaughtBall(sPokedexView->pokedexList[_b].owned, MON_LIST_X, sPokedexView->unk630 * 2, c);
                CreateMonName(sPokedexView->pokedexList[_b].dexNum, MON_LIST_X+5, sPokedexView->unk630 * 2);
                }
                else
                {
                CreateMonDexNum(_b, MON_LIST_X+1, sPokedexView->unk630 * 2, c);
                CreateCaughtBall(FALSE, MON_LIST_X, sPokedexView->unk630 * 2, c);
                CreateMonName(0, MON_LIST_X+5, sPokedexView->unk630 * 2);
                }
            }
            break;
        case 2: // Down
            _b = b + 5;
            r2 = sPokedexView->unk630 + 10;
            if (r2 > 15)
                r2 -= 16;
            if (_b < 0 || _b >= NATIONAL_DEX_COUNT || sPokedexView->pokedexList[_b].dexNum == 0xFFFF)
                ClearMonListEntry(MON_LIST_X, r2 * 2, c);
            else
            {
                ClearMonListEntry(MON_LIST_X, r2 * 2, c);
                if (sPokedexView->pokedexList[_b].seen)
                {
                CreateMonDexNum(_b, MON_LIST_X+1, r2 * 2, c);
                CreateCaughtBall(sPokedexView->pokedexList[_b].owned, MON_LIST_X, r2 * 2, c);
                CreateMonName(sPokedexView->pokedexList[_b].dexNum, MON_LIST_X+5, r2 * 2);
                }
                else
                {
                CreateMonDexNum(_b, MON_LIST_X+1, r2 * 2, c);
                CreateCaughtBall(FALSE, MON_LIST_X, r2 * 2, c);
                CreateMonName(0, MON_LIST_X+5, r2 * 2);
                }
            }
            break;
    }
    CopyWindowToVram(0, 2);
}

static void CreateMonDexNum(u16 a, u8 left, u8 top, u16 unused)
{
    u8 text[6];
    u16 r6;

    memcpy(text, sText_No000, 6);
    r6 = sPokedexView->pokedexList[a].dexNum;
    if (sPokedexView->dexMode == DEX_MODE_HOENN)
        r6 = NationalToHoennOrder(r6);
    text[2] = CHAR_0 + r6 / 100;
    text[3] = CHAR_0 + (r6 % 100) / 10;
    text[4] = CHAR_0 + (r6 % 100) % 10;
    PrintMonDexNumAndName(0, 7, text, left, top);
}

static void CreateCaughtBall(u16 a, u8 x, u8 y, u16 unused)
{
    if (a)
        BlitBitmapToWindow(0, gUnknown_0855D2BE, x * 8 - 2, y * 8, 8, 16);
    else
        FillWindowPixelRect(0, PIXEL_FILL(0), x * 8 - 2, y * 8, 8, 16);
}

static u8 CreateMonName(u16 num, u8 left, u8 top)
{
    const u8* str;

    num = NationalPokedexNumToSpecies(num);
    if (num)
        str = gSpeciesNames[num];
    else
        str = sText_TenDashes;
    PrintMonDexNumAndName(0, 7, str, left, top);
    return StringLength(str);
}

static void ClearMonListEntry(u8 x, u8 y, u16 unused)
{
    FillWindowPixelRect(0, PIXEL_FILL(0), x * 8 - 2, y * 8, 0x62, 16);
}

static void CreateInitialPokemonSprites(u16 selectedMon, u16 b)
{
    u8 i;
    u16 unk;
    u8 spriteId;

    gPaletteFade.bufferTransferDisabled = TRUE;

    for (i = 0; i < 4; i++)
        sPokedexView->monSpriteIds[i] = 0xFFFF;
    sPokedexView->selectedMonSpriteId = 0xFFFF;

    unk = GetPokemonSpriteToDisplay(selectedMon - 1);
    if (unk != 0xFFFF)
    {
        spriteId = sub_80BDACC(unk, SCROLLING_MON_X, 0x50);
        gSprites[spriteId].callback = sub_80BE4E0;
        gSprites[spriteId].data[5] = -32;
    }

    unk = GetPokemonSpriteToDisplay(selectedMon);
    if (unk != 0xFFFF)
    {
        spriteId = sub_80BDACC(unk, SCROLLING_MON_X, 0x50);
        gSprites[spriteId].callback = sub_80BE4E0;
        gSprites[spriteId].data[5] = 0;
    }

    unk = GetPokemonSpriteToDisplay(selectedMon + 1);
    if (unk != 0xFFFF)
    {
        spriteId = sub_80BDACC(unk, SCROLLING_MON_X, 0x50);
        gSprites[spriteId].callback = sub_80BE4E0;
        gSprites[spriteId].data[5] = 32;
    }

    CreateMonListEntry(0, selectedMon, b);
    SetGpuReg(REG_OFFSET_BG2VOFS, sPokedexView->initialVOffset);

    sPokedexView->unk630 = 0;
    sPokedexView->unk632 = 0;

    gPaletteFade.bufferTransferDisabled = FALSE;
}

bool8 sub_80BD404(u8 a, u8 b, u8 c)
{
    u16 i;
    u8 foo;

    if (sPokedexView->unk62E)
    {
        sPokedexView->unk62E--;
        switch (a)
        {
            case 1:
                for (i = 0; i < 4; i++)
                {
                    if (sPokedexView->monSpriteIds[i] != 0xFFFF)
                        gSprites[sPokedexView->monSpriteIds[i]].data[5] += b;
                }
                foo = 16 * (c - sPokedexView->unk62E) / c;
                SetGpuReg(REG_OFFSET_BG2VOFS, sPokedexView->initialVOffset + sPokedexView->unk632 * 16 - foo);
                sPokedexView->unk62C -= sPokedexView->unk628;
                break;
            case 2:
                for (i = 0; i < 4; i++)
                {
                    if (sPokedexView->monSpriteIds[i] != 0xFFFF)
                        gSprites[sPokedexView->monSpriteIds[i]].data[5] -= b;
                }
                foo = 16 * (c - sPokedexView->unk62E) / c;
                SetGpuReg(REG_OFFSET_BG2VOFS, sPokedexView->initialVOffset + sPokedexView->unk632 * 16 + foo);
                sPokedexView->unk62C += sPokedexView->unk628;
                break;
        }
        return FALSE;
    }
    else
    {
        SetGpuReg(REG_OFFSET_BG2VOFS, sPokedexView->initialVOffset + sPokedexView->unk630 * 16);
        return TRUE;
    }
}

static void CreateNewPokemonSprite(u8 direction, u16 selectedMon)
{
    u16 unk;
    u8 spriteId;

    sPokedexView->unk632 = sPokedexView->unk630;
    switch (direction)
    {
        case 1: // up
            unk = GetPokemonSpriteToDisplay(selectedMon - 1);
            if (unk != 0xFFFF)
            {
                spriteId = sub_80BDACC(unk, SCROLLING_MON_X, 0x50);
                gSprites[spriteId].callback = sub_80BE4E0;
                gSprites[spriteId].data[5] = -64;
            }
            if (sPokedexView->unk630 > 0)
                sPokedexView->unk630--;
            else
                sPokedexView->unk630 = 15;
            break;
        case 2: // down
            unk = GetPokemonSpriteToDisplay(selectedMon + 1);
            if (unk != 0xFFFF)
            {
                spriteId = sub_80BDACC(unk, SCROLLING_MON_X, 0x50);
                gSprites[spriteId].callback = sub_80BE4E0;
                gSprites[spriteId].data[5] = 0x40;
            }
            if (sPokedexView->unk630 <= 0xE)
                sPokedexView->unk630++;
            else
                sPokedexView->unk630 = 0;
            break;
    }
}

u16 sub_80BD69C(u16 selectedMon, u16 b)
{
    u8 r3;
    u8 r5;
    u8 i;
    u16 r6;
    u8 r10 = 0;

    if ((gMain.heldKeys & DPAD_UP) && (selectedMon > 0))
    {
        r10 = 1;
        selectedMon = sub_80C0E0C(1, selectedMon, 0, sPokedexView->pokemonListCount - 1);
        CreateNewPokemonSprite(1, selectedMon);
        CreateMonListEntry(1, selectedMon, b);
        sPokedexView->justScrolled = TRUE; //HGSS_Ui
        PlaySE(SE_Z_SCROLL);
    }
    else if ((gMain.heldKeys & DPAD_DOWN) && (selectedMon < sPokedexView->pokemonListCount - 1))
    {
        r10 = 2;
        selectedMon = sub_80C0E0C(0, selectedMon, 0, sPokedexView->pokemonListCount - 1);
        CreateNewPokemonSprite(2, selectedMon);
        CreateMonListEntry(2, selectedMon, b);
        sPokedexView->justScrolled = TRUE; //HGSS_Ui
        PlaySE(SE_Z_SCROLL);
    }
    else if ((gMain.newKeys & DPAD_LEFT) && (selectedMon > 0))
    {
        r6 = selectedMon;

        for (i = 0; i < 7; i++)
            selectedMon = sub_80C0E0C(1, selectedMon, 0, sPokedexView->pokemonListCount - 1);
        sPokedexView->unk62C += 16 * (selectedMon - r6);
        ClearMonSprites();
        CreateInitialPokemonSprites(selectedMon, 0xE);
        sPokedexView->justScrolled = TRUE; //HGSS_Ui
        PlaySE(SE_Z_PAGE);
    }
    else if ((gMain.newKeys & DPAD_RIGHT) && (selectedMon < sPokedexView->pokemonListCount - 1))
    {
        r6 = selectedMon;
        for (i = 0; i < 7; i++)
            selectedMon = sub_80C0E0C(0, selectedMon, 0, sPokedexView->pokemonListCount - 1);
        sPokedexView->unk62C += (selectedMon - r6) * 16;
        ClearMonSprites();
        CreateInitialPokemonSprites(selectedMon, 0xE);
        sPokedexView->justScrolled = TRUE; //HGSS_Ui
        PlaySE(SE_Z_PAGE);
    }

    if (r10 == 0)
    {
        sPokedexView->unk638 = 0;
        return selectedMon;
    }

    r5 = gUnknown_0855D28C[sPokedexView->unk638 / 4];
    r3 = gUnknown_0855D291[sPokedexView->unk638 / 4];
    sPokedexView->unk62E = r3;
    sPokedexView->unk636 = r3;
    sPokedexView->unk634 = r5;
    sPokedexView->unk62F = r10;
    sPokedexView->unk628 = r5 / 2;
    sub_80BD404(sPokedexView->unk62F, sPokedexView->unk634, sPokedexView->unk636);
    if (sPokedexView->unk638 <= 0xB)
        sPokedexView->unk638++;
    return selectedMon;
}

static void UpdateSelectedMonSpriteId(void)
{
    u16 i;

    for (i = 0; i < 4; i++)
    {
        u16 spriteId = sPokedexView->monSpriteIds[i];

        if (gSprites[spriteId].pos2.x == 0 && gSprites[spriteId].pos2.y == 0 && spriteId != 0xFFFF)
            sPokedexView->selectedMonSpriteId = spriteId;
    }
}

static bool8 UpdateSelectedMon(void)
{
    u16 r2;
    u16 r4 = sPokedexView->selectedPokemon;

    if ((gMain.newKeys & DPAD_UP) && r4)
    {
        r2 = r4;
        while (r2 != 0)
        {
            r2 = sub_80C0E0C(1, r2, 0, sPokedexView->pokemonListCount - 1);

            if (sPokedexView->pokedexList[r2].seen)
            {
                r4 = r2;
                break;
            }
        }

        if (sPokedexView->selectedPokemon == r4)
            return FALSE;
        else
        {
            sPokedexView->selectedPokemon = r4;
            sPokedexView->unk62C -= 16;
            return TRUE;
        }
    }
    else if ((gMain.newKeys & DPAD_DOWN) && r4 < sPokedexView->pokemonListCount - 1)
    {
        r2 = r4;
        while (r2 < sPokedexView->pokemonListCount - 1)
        {
            r2 = sub_80C0E0C(0, r2, 0, sPokedexView->pokemonListCount - 1);

            if (sPokedexView->pokedexList[r2].seen)
            {
                r4 = r2;
                break;
            }
        }

        if (sPokedexView->selectedPokemon == r4)
            return FALSE;
        else
        {
            sPokedexView->selectedPokemon = r4;
            sPokedexView->unk62C += 16;
            return TRUE;
        }
    }
    return FALSE;
}

static u8 ClearMonSprites(void)
{
    u16 i;

    for (i = 0; i < 4; i++)
    {
        if (sPokedexView->monSpriteIds[i] != 0xFFFF)
        {
            FreeAndDestroyMonPicSprite(sPokedexView->monSpriteIds[i]);
            sPokedexView->monSpriteIds[i] = 0xFFFF;
        }
    }
    return FALSE;
}

u16 GetPokemonSpriteToDisplay(u16 species)
{
    if (species >= NATIONAL_DEX_COUNT || sPokedexView->pokedexList[species].dexNum == 0xFFFF)
        return 0xFFFF;
    else if (sPokedexView->pokedexList[species].seen)
        return sPokedexView->pokedexList[species].dexNum;
    else
        return 0;
}

u32 sub_80BDACC(u16 num, s16 x, s16 y)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        if (sPokedexView->monSpriteIds[i] == 0xFFFF)
        {
            u8 spriteId = CreateMonSpriteFromNationalDexNumber(num, x, y, i);

            gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
            gSprites[spriteId].oam.priority = 3;
            gSprites[spriteId].data[0] = 0;
            gSprites[spriteId].data[1] = i;
            gSprites[spriteId].data[2] = NationalPokedexNumToSpecies(num);
            sPokedexView->monSpriteIds[i] = spriteId;
            return spriteId;
        }
    }
    return 0xFFFF;
}

#define LIST_RIGHT_SIDE_TEXT_X 204
#define LIST_RIGHT_SIDE_TEXT_X_OFFSET 12
#define LIST_RIGHT_SIDE_TEXT_Y_OFFSET 13

static void CreateInterfaceSprites(u8 a)
{
    u8 spriteId;
    u16 r5;
	u8 color[3];
    bool32 _a;
// Up arrow
    spriteId = CreateSprite(&sArrowSpriteTemplate, 10, 4, 0);
    gSprites[spriteId].data[1] = 0;
// Down arrow
    spriteId = CreateSprite(&sArrowSpriteTemplate, 10, 156, 0);
    gSprites[spriteId].data[1] = 1;
    gSprites[spriteId].vFlip = TRUE;

    CreateSprite(&sScrollBarSpriteTemplate, 8, 20, 0);
// Start button
    //CreateSprite(&sInterfaceTextSpriteTemplate, 16, 120, 0);
// Menu text
    //spriteId = CreateSprite(&sInterfaceTextSpriteTemplate, 48, 120, 0);
    //StartSpriteAnim(&gSprites[spriteId], 3);
// Select button
   // spriteId = CreateSprite(&sInterfaceTextSpriteTemplate, 16, 144, 0);
   // StartSpriteAnim(&gSprites[spriteId], 2);
   // gSprites[spriteId].data[2] = 0x80;
// Search text
    //spriteId = CreateSprite(&sInterfaceTextSpriteTemplate, 48, 144, 0);
    //StartSpriteAnim(&gSprites[spriteId], 1);

   // spriteId = CreateSprite(&sRotatingPokeballSpriteTemplate, 0, 80, 2);
    //gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    //gSprites[spriteId].oam.matrixNum = 30;
    //gSprites[spriteId].data[0] = 0x1E;
    //gSprites[spriteId].data[1] = 0;

   // spriteId = CreateSprite(&sRotatingPokeballSpriteTemplate, 0, 80, 2);
    //gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
   // gSprites[spriteId].oam.matrixNum = 31;
    //gSprites[spriteId].data[0] = 0x1F;
    //gSprites[spriteId].data[1] = 0x80;

  //  if (a == 0)
  //  {
   //     u32 _a;

   //     if (!IsNationalPokedexEnabled())
  //      {
// Seen text
         //   CreateSprite(&sSeenOwnTextSpriteTemplate, 32, 40, 1);
// Own text
        //    spriteId = CreateSprite(&sSeenOwnTextSpriteTemplate, 32, 72, 1);
         //   StartSpriteAnim(&gSprites[spriteId], 1);
         //   _a = 0;
// Seen value - 100s
       /*     spriteId = CreateSprite(&gUnknown_0855D224, 24, 48, 1);
            r5 = sPokedexView->seenCount / 100;
            StartSpriteAnim(&gSprites[spriteId], r5);
            if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;
// Seen value - 10s
            spriteId = CreateSprite(&gUnknown_0855D224, 32, 48, 1);
            r5 = (sPokedexView->seenCount % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);
            else
                gSprites[spriteId].invisible = TRUE;
// Seen value - 1s
            spriteId = CreateSprite(&gUnknown_0855D224, 40, 48, 1);
            r5 = (sPokedexView->seenCount % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], r5);
            _a = 0;
// Owned value - 100s
            spriteId = CreateSprite(&gUnknown_0855D224, 24, 80, 1);
            r5 = sPokedexView->ownCount / 100;
            StartSpriteAnim(&gSprites[spriteId], r5);
            if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;
// Owned value - 10s
            spriteId = CreateSprite(&gUnknown_0855D224, 32, 80, 1);
            r5 = (sPokedexView->ownCount % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);
            else
                gSprites[spriteId].invisible = TRUE;
// Owned value -1s
            spriteId = CreateSprite(&gUnknown_0855D224, 40, 80, 1);
            r5 = (sPokedexView->ownCount % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], r5); */
		// Hoenn text
        //    CreateSprite(&gUnknown_0855D20C, LIST_RIGHT_SIDE_TEXT_X, 40 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET - 6, 1);
            // Hoenn seen
         //   CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 6, 1);
            // Hoenn own
      //      spriteId = CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 7, 1);
      //   StartSpriteAnim(&gSprites[spriteId], 1);
		//}
		    if (!IsNationalPokedexEnabled() && a == 0)
    {
        // Hoenn text
        CreateSprite(&gUnknown_0855D20C, LIST_RIGHT_SIDE_TEXT_X, 40 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET - 6, 1);
        // Hoenn seen
        CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 6, 1);
        // Hoenn own
        spriteId = CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 7, 1);
        StartSpriteAnim(&gSprites[spriteId], 1);

        // Hoenn seen value - 100s
        _a = FALSE;
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = sPokedexView->seenCount / 100;
        StartSpriteAnim(&gSprites[spriteId], r5);
        if (r5 != 0)
            _a = TRUE;
        else
            gSprites[spriteId].invisible = TRUE;
		 // Hoenn seen value - 10s
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 8, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = (sPokedexView->seenCount % 100) / 10;
        if (r5 != 0 || _a)
		 StartSpriteAnim(&gSprites[spriteId], r5);
        else
            gSprites[spriteId].invisible = TRUE;

        // Hoenn seen value - 1s
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 16, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = (sPokedexView->seenCount % 100) % 10;
        StartSpriteAnim(&gSprites[spriteId], r5);
		
		// Hoenn owned value - 100s
        _a = FALSE;
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = sPokedexView->ownCount / 100;
        StartSpriteAnim(&gSprites[spriteId], r5);
        if (r5 != 0)
            _a = TRUE;
        else
     /*   {
            u16 seenOwnedCount;

            // Hoenn text
            CreateSprite(&gUnknown_0855D20C, LIST_RIGHT_SIDE_TEXT_X, 40 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET - 6, 1);
            // Hoenn seen
            CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 6, 1);
            // Hoenn own
            spriteId = CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 7, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);

			// National text
            spriteId = CreateSprite(&gUnknown_0855D20C, LIST_RIGHT_SIDE_TEXT_X, 73 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET - 6, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);
            // National seen
            CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 78 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 6, 1);
            // National own
            spriteId = CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 88 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 6, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);

             seenOwnedCount = GetHoennPokedexCount(FLAG_GET_SEEN);
            _a = 0;

            spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
            r5 = seenOwnedCount / 100;
            StartSpriteAnim(&gSprites[spriteId], r5);
            if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;

            spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 8, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
            r5 = (seenOwnedCount % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);
            else
                gSprites[spriteId].invisible = TRUE;

            spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 16, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
            r5 = (seenOwnedCount % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], r5);
			seenOwnedCount = GetHoennPokedexCount(FLAG_GET_CAUGHT);
            // Hoenn owned value - 100s
            _a = 0;

            spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
            r5 = seenOwnedCount / 100;
            StartSpriteAnim(&gSprites[spriteId], r5);
            if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;

                        // Hoenn owned value - 10s
            spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 8, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
            r5 = (seenOwnedCount % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);
            else*/
                gSprites[spriteId].invisible = TRUE;

                        // Hoenn owned value - 1s
         //   spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 16, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
          //  r5 = (seenOwnedCount % 100) % 10;
		  // Hoenn owned value - 10s
			spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 8, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
			r5 = (sPokedexView->ownCount % 100) / 10;
		if (r5 != 0 || _a)
            StartSpriteAnim(&gSprites[spriteId], r5);
		else
            gSprites[spriteId].invisible = TRUE;

        // Hoenn owned value - 1s
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 16, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = (sPokedexView->ownCount % 100) % 10;
        StartSpriteAnim(&gSprites[spriteId], r5);
    }
    else if (a == 0)
    {
        u16 seenOwnedCount;

        // Hoenn text
        CreateSprite(&gUnknown_0855D20C, LIST_RIGHT_SIDE_TEXT_X, 40 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET - 6, 1);
        // Hoenn seen
        CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 6, 1);
        // Hoenn own
        spriteId = CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 7, 1);
        StartSpriteAnim(&gSprites[spriteId], 1);

        // National text
        spriteId = CreateSprite(&gUnknown_0855D20C, LIST_RIGHT_SIDE_TEXT_X, 73 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET - 6, 1);
        StartSpriteAnim(&gSprites[spriteId], 1);
        // National seen
        CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 78 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 6, 1);
        // National own
        spriteId = CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 88 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 6, 1);
        StartSpriteAnim(&gSprites[spriteId], 1);

        // Hoenn seen value - 100s
        seenOwnedCount = GetHoennPokedexCount(FLAG_GET_SEEN);
        _a = FALSE;
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = seenOwnedCount / 100;
        StartSpriteAnim(&gSprites[spriteId], r5);
        if (r5 != 0)
            _a = TRUE;
        else
            gSprites[spriteId].invisible = TRUE;

            //r6 = GetHoennPokedexCount(FLAG_GET_CAUGHT);
			//****************************
            // National seen value - 100s
        /*    _a = 0;

            spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET, 78 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
            r5 = sPokedexView->seenCount / 100;
            StartSpriteAnim(&gSprites[spriteId], r5);
            if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;

            // National seen value - 10s
            spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 8, 78 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
            r5 = (sPokedexView->seenCount % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);
            else
                gSprites[spriteId].invisible = TRUE;

                        // National seen value - 1s
            spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 16, 78 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
            r5 = (sPokedexView->seenCount % 100) % 10;^*/
			// Hoenn seen value - 10s
			spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 8, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
			r5 = (seenOwnedCount % 100) / 10;
        if (r5 != 0 || _a)
            StartSpriteAnim(&gSprites[spriteId], r5);
		 else
            gSprites[spriteId].invisible = TRUE;

        // Hoenn seen value - 1s
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 16, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = (seenOwnedCount % 100) % 10;
        StartSpriteAnim(&gSprites[spriteId], r5);

        seenOwnedCount = GetHoennPokedexCount(FLAG_GET_CAUGHT);
        // Hoenn owned value - 100s
        _a = FALSE;
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = seenOwnedCount / 100;
        StartSpriteAnim(&gSprites[spriteId], r5);
        if (r5 != 0)
            _a = TRUE;
        else
            gSprites[spriteId].invisible = TRUE;

       //     _a = 0;

       //     spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET, 88 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        //    r5 = sPokedexView->ownCount / 100;
		// Hoenn owned value - 10s
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 8, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = (seenOwnedCount % 100) / 10;
        if (r5 != 0 || _a)
		  StartSpriteAnim(&gSprites[spriteId], r5);
      /*      if (r5 != 0)
                _a = 1;
            else
                gSprites[spriteId].invisible = TRUE;

             spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 8, 88 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
            r5 = (sPokedexView->ownCount % 100) / 10;
            if (r5 != 0 || _a != 0)
                StartSpriteAnim(&gSprites[spriteId], r5);*/
            else
                gSprites[spriteId].invisible = TRUE;
			
			  // Hoenn owned value - 1s
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 16, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = (seenOwnedCount % 100) % 10;
        StartSpriteAnim(&gSprites[spriteId], r5);

        //****************************
        // National seen value - 100s
        _a = FALSE;
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET, 78 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = sPokedexView->seenCount / 100;
        StartSpriteAnim(&gSprites[spriteId], r5);
        if (r5 != 0)
            _a = TRUE;
        else
            gSprites[spriteId].invisible = TRUE;

         //   spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 16, 88 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
          //  r5 = (sPokedexView->ownCount % 100) % 10;
		   // National seen value - 10s
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 8, 78 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = (sPokedexView->seenCount % 100) / 10;
        if (r5 != 0 || _a)
            StartSpriteAnim(&gSprites[spriteId], r5);
		        else
            gSprites[spriteId].invisible = TRUE;

        // National seen value - 1s
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 16, 78 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = (sPokedexView->seenCount % 100) % 10;
        StartSpriteAnim(&gSprites[spriteId], r5);

        // National owned value - 100s
        _a = FALSE;
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET, 88 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = sPokedexView->ownCount / 100;
        StartSpriteAnim(&gSprites[spriteId], r5);
        if (r5 != 0)
            _a = TRUE;
        else
            gSprites[spriteId].invisible = TRUE;
		
		 // National owned value  - 10s
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 8, 88 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = (sPokedexView->ownCount % 100) / 10;
        if (r5 != 0 || _a)
            StartSpriteAnim(&gSprites[spriteId], r5);
		else
            gSprites[spriteId].invisible = TRUE;
		
		 // National owned value - 1s
        spriteId = CreateSprite(&gUnknown_0855D23C, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 16, 88 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        r5 = (sPokedexView->ownCount % 100) % 10;
        StartSpriteAnim(&gSprites[spriteId], r5);
    }
	
	 if (a == 0)
    {
       // }
        spriteId = CreateSprite(&gUnknown_0855D254, 136, 96, 1);
        gSprites[spriteId].invisible = TRUE;
    }
    else // PAGE_SEARCH_RESULTS
    {
        spriteId = CreateSprite(&gUnknown_0855D254, 136, 80, 1);
        gSprites[spriteId].invisible = TRUE;
    }
}

void nullsub_38(struct Sprite *sprite)
{
}

void sub_80BE44C(struct Sprite *sprite)
{
    if (sPokedexView->unk64A != 0 && sPokedexView->unk64A != 3)
        DestroySprite(sprite);
}

//Move Pokemon into position for description page
void MoveMonIntoPosition(struct Sprite *sprite)
{
    sprite->oam.priority = 0;
    sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
    sprite->pos2.x = 0;
    sprite->pos2.y = 0;
    if (sprite->pos1.x != 48 || sprite->pos1.y != 56)
    {
        if (sprite->pos1.x > 48)
            sprite->pos1.x -= 4;
        if (sprite->pos1.x < 48)
           sprite->pos1.x = 48;

        if (sprite->pos1.y > 56)
            sprite->pos1.y -= 4;
        if (sprite->pos1.y < 56)
            sprite->pos1.y = 56;
    }
    else
    {
        sprite->callback = nullsub_38;
    }
}

void sub_80BE4E0(struct Sprite *sprite)
{
    u8 data1 = sprite->data[1];

    if (sPokedexView->unk64A != 0 && sPokedexView->unk64A != 3)
    {
        FreeAndDestroyMonPicSprite(sPokedexView->monSpriteIds[data1]);
        sPokedexView->monSpriteIds[data1] = 0xFFFF;
    }
    else
    {
        u32 var;

        sprite->pos2.y = gSineTable[(u8)sprite->data[5]] * 76 / 256;
        var = 0x10000 / gSineTable[sprite->data[5] + 0x40];
        if (var > 0xFFFF)
            var = 0xFFFF;
        SetOamMatrix(sprite->data[1] + 1, 0x100, 0, 0, var);
        sprite->oam.matrixNum = data1 + 1;

        if (sprite->data[5] > -64 && sprite->data[5] < 64)
        {
            sprite->invisible = FALSE;
            sprite->data[0] = 1;
        }
        else
        {
            sprite->invisible = TRUE;
        }

        if ((sprite->data[5] <= -64 || sprite->data[5] >= 64) && sprite->data[0] != 0)
        {
            FreeAndDestroyMonPicSprite(sPokedexView->monSpriteIds[data1]);
            sPokedexView->monSpriteIds[data1] = 0xFFFF;
        }
    }
}

static void SpriteCB_Scrollbar(struct Sprite *sprite)
{
    if (sPokedexView->unk64A != 0 && sPokedexView->unk64A != 3)
        DestroySprite(sprite);
    else
        sprite->pos2.y = sPokedexView->selectedPokemon * 120 / (sPokedexView->pokemonListCount - 1);
}

void sub_80BE658(struct Sprite *sprite)
{
    if (sPokedexView->unk64A != 0 && sPokedexView->unk64A != 3)
    {
        DestroySprite(sprite);
    }
    else
    {
        u8 r0;

        if (sprite->data[1] != 0)
        {
            if (sPokedexView->selectedPokemon == sPokedexView->pokemonListCount - 1)
                sprite->invisible = TRUE;
            else
                sprite->invisible = FALSE;
            r0 = sprite->data[2];
        }
        else
        {
            if (sPokedexView->selectedPokemon == 0)
                sprite->invisible = TRUE;
            else
                sprite->invisible = FALSE;
            r0 = sprite->data[2] - 128;
        }
        sprite->pos2.y = gSineTable[r0] / 64;
        sprite->data[2] = sprite->data[2] + 8;
        if (sPokedexView->menuIsOpen == 0 && sPokedexView->menuY == 0 && sprite->invisible == 0)
            sprite->invisible = FALSE;
        else
            sprite->invisible = TRUE;
    }
}

void sub_80BE758(struct Sprite *sprite)
{
    if (sPokedexView->unk64A != 0 && sPokedexView->unk64A != 3)
        DestroySprite(sprite);
}

void sub_80BE780(struct Sprite *sprite)
{
    if (sPokedexView->unk64A != 0 && sPokedexView->unk64A != 3)
    {
        DestroySprite(sprite);
    }
    else
    {
        u8 val;
        s16 r3;
        s16 r0;

        val = sPokedexView->unk62C + sprite->data[1];
        r3 = gSineTable[val];
        r0 = gSineTable[val + 0x40];
        SetOamMatrix(sprite->data[0], r0, r3, -r3, r0);

        val = sPokedexView->unk62C + (sprite->data[1] + 0x40);
        r3 = gSineTable[val];
        r0 = gSineTable[val + 0x40];
        sprite->pos2.x = r0 * 40 / 256;
        sprite->pos2.y = r3 * 40 / 256;
    }
}

void sub_80BE834(struct Sprite *sprite)
{
    if (sPokedexView->unk64A != 0 && sPokedexView->unk64A != 3)
    {
        DestroySprite(sprite);
    }
    else
    {
        u16 r1 = sPokedexView->unk64A == 0 ? 80 : 96;

        if (sPokedexView->menuIsOpen != 0 && sPokedexView->menuY == r1)
        {
            sprite->invisible = FALSE;
            sprite->pos2.y = sPokedexView->menuCursorPos * 16;
            sprite->pos2.x = gSineTable[(u8)sprite->data[2]] / 64;
            sprite->data[2] += 8;
        }
        else
        {
            sprite->invisible = TRUE;
        }
    }
}

static void PrintInfoPageText(const u8* str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = 0;
    color[1] = 15;
    color[2] = 3;

    AddTextPrinterParameterized4(0, 1, left, top, 0, 0, color, -1, str);
}

#define tMonSpriteId data[4]

static void PrintInfoScreenTextWhite(const u8* str, u8 left, u8 top) //HGSS_Ui
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_COLOR_WHITE;
    color[2] = TEXT_DYNAMIC_COLOR_6;

    AddTextPrinterParameterized4(0, 1, left, top, 0, 0, color, -1, str);
}
static void PrintInfoScreenTextSmall(const u8* str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_DYNAMIC_COLOR_6;
    color[2] = TEXT_COLOR_LIGHT_GREY;

    AddTextPrinterParameterized4(0, 0, left, top, 0, 0, color, 0, str);
}
static void PrintInfoScreenTextSmallWhite(const u8* str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_COLOR_WHITE;
    color[2] = TEXT_DYNAMIC_COLOR_6;

    AddTextPrinterParameterized4(0, 0, left, top, 0, 0, color, 0, str);
}

u8 SetupInfoScreen(struct PokedexListItem* item, u8 monSpriteId)
{
    u8 taskId;

    sPokedexListItem = item;
    UpdateSpecies(TRUE);
    taskId = CreateTask(LoadInfoScreen, 0);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 1;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 0;
    gTasks[taskId].tMonSpriteId = monSpriteId;
    gTasks[taskId].data[5] = 255;
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sInfoScreen_BgTemplate, 4);
    SetBgTilemapBuffer(3, AllocZeroed(0x800));
    SetBgTilemapBuffer(2, AllocZeroed(0x800));
    SetBgTilemapBuffer(1, AllocZeroed(0x800));
    SetBgTilemapBuffer(0, AllocZeroed(0x800));
    InitWindows(sInfoScreen_WindowTemplates);
    DeactivateAllTextPrinters();

    return taskId;
}

bool8 sub_80BE9C4(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0 && gTasks[taskId].func == ChangePokedexScreen)
        return FALSE;
    else
        return TRUE;
}

u8 sub_80BE9F8(struct PokedexListItem *item, u8 b)
{
    sPokedexListItem = item;
    UpdateSpecies(FALSE); // si se cambia a TRUE, al cambiar de poke arriba y abajo se reiniciará la forma
    gTasks[b].data[0] = 1;
    gTasks[b].data[1] = 0;
    gTasks[b].data[2] = 0;
    gTasks[b].data[3] = 0;
    return b;
}

void LoadInfoScreen(u8 taskId)
{
    switch (gMain.state)
    {
        case 0:
        default:
            if (!gPaletteFade.active)
            {
                u16 r2;

                sPokedexView->unk64A = 1;
                gUnknown_030060B4 = gMain.vblankCallback;
                SetVBlankCallback(NULL);
                r2 = 0;
                if (gTasks[taskId].data[1] != 0)
                    r2 += DISPCNT_OBJ_ON;
                if (gTasks[taskId].data[2] != 0)
                    r2 |= DISPCNT_BG1_ON;
                ResetOtherVideoRegisters(r2);
                gMain.state = 1;
            }
            break;
        case 1:
            DecompressAndLoadBgGfxUsingHeap(3, gPokedexMenu_Gfx, 0x2000, 0, 0);
            CopyToBgTilemapBuffer(3, gPokedexTilemap_DescriptionScreen, 0, 0);
            FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
            PutWindowTilemap(WIN_INFO);
            PutWindowTilemap(WIN_FOOTPRINT);
            PrintFootprint(WIN_FOOTPRINT, sPokedexListItem->dexNum);
            CopyWindowToVram(WIN_FOOTPRINT, 2);
            gMain.state++;
            break;
        case 2:
            sub_80BFCDC(0xD);
           // sub_80BFD0C(sPokedexView->selectedScreen, 0xD);
            LoadPokedexBgPalette(sPokedexView->unk64C_1);
            gMain.state++;
            break;
        case 3:
		    sPokedexView->typeIconSpriteIds[0] = 0xFF;
			sPokedexView->typeIconSpriteIds[1] = 0xFF;
			CreateTypeIconSprites();
            if (GetNextFormSpecies() != sPokedexListItem->species)
            BlitBitmapToWindow(WIN_INFO, sSelectFormGfx, 14*8, 9*8 + 3, 32, 16);
            gMain.state++;
            break;
        case 4:
			PrintMonInfo(sPokedexListItem->species, sPokedexView->dexMode == 0 ? 0 : 1, sPokedexListItem->owned, 0);
            if (!sPokedexListItem->owned)
                LoadPalette(gPlttBufferUnfaded + 1, 0x31, 0x1E);
            CopyWindowToVram(WIN_INFO, 3);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(3);
            gMain.state++;
            break;
        case 5:
            if (gTasks[taskId].data[1] == 0)
            {
                gTasks[taskId].tMonSpriteId = (u16)CreateMonSpriteFromSpeciesNumber(sPokedexListItem->species, 48, 56, 0, FALSE);
                gSprites[gTasks[taskId].tMonSpriteId].oam.priority = 0;
            }
            gMain.state++;
            break;
        case 6:
            {
                u32 preservedPalettes = 0;

                if (gTasks[taskId].data[2] != 0)
                    preservedPalettes = 0x14; // each bit represents a palette index
                if (gTasks[taskId].data[1] != 0)
                    preservedPalettes |= (1 << (gSprites[gTasks[taskId].tMonSpriteId].oam.paletteNum + 16));
                BeginNormalPaletteFade(~preservedPalettes, 0, 16, 0, RGB_BLACK);
                SetVBlankCallback(gUnknown_030060B4);
                gMain.state++;
            }
            break;
        case 7:
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            HideBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            gMain.state++;
            break;
        case 8:
            if (!gPaletteFade.active)
            {
                gMain.state++;
                if (gTasks[taskId].data[3] == 0)
                {
                    StopCryAndClearCrySongs();
                    PlayCry2(sPokedexListItem->species, 0, 0x7D, 0xA);
                }
                else
                {
                    gMain.state++;
                } 
            }
            break;
        case 9:
            if (!IsCryPlayingOrClearCrySongs())
                gMain.state++;
            break;
        case 10:
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].data[2] = 1;
            gTasks[taskId].data[3] = 1;
            gTasks[taskId].func = ChangePokedexScreen;
            gMain.state = 0;
            break;
    }
}

static void FreeWindowAndBgBuffers_(void)
{
    void *r0;
    FreeAllWindowBuffers();
    r0 = GetBgTilemapBuffer(0);
    if (r0)
        Free(r0);
    r0 = GetBgTilemapBuffer(1);
    if (r0)
        Free(r0);
    r0 = GetBgTilemapBuffer(2);
    if (r0)
        Free(r0);
    r0 = GetBgTilemapBuffer(3);
    if (r0)
        Free(r0);
}

void ChangePokedexScreen(u8 taskId)
{
    if (gTasks[taskId].data[0] != 0)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = BeginChangeInfoScreen;
        PlaySE(SE_Z_SCROLL);
        return;
    }
    if (gMain.newKeys & B_BUTTON)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = BeginReturnToPokedex;
        PlaySE(SE_PC_OFF);
        return;
    }
    if (gMain.newKeys & SELECT_BUTTON)
        if (TryToChangeForm(taskId, LoadSelectedScreen))
            return;
   /* if (gMain.newKeys & A_BUTTON)
    {
        switch (sPokedexView->selectedScreen)
        {
            case AREA_SCREEN:
                BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 16, RGB_BLACK);
                sPokedexView->unk64E = 1;
                gTasks[taskId].func = LoadSelectedScreen;
                PlaySE(SE_PIN);
                break;
            case CRY_SCREEN:
                BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
                sPokedexView->unk64E = 2;
                gTasks[taskId].func = LoadSelectedScreen;
                PlaySE(SE_PIN);
                break;
            case SIZE_SCREEN:
                if (!sPokedexListItem->owned)
                {
                    PlaySE(SE_HAZURE);
                }
                else
                {
                    BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
                    sPokedexView->unk64E = 3;
                    gTasks[taskId].func = LoadSelectedScreen;
                    PlaySE(SE_PIN);
                }
                break;
            case CANCEL_SCREEN:
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                gTasks[taskId].func = BeginReturnToPokedex;
                PlaySE(SE_PC_OFF);
                break;
        }
        return;
    }
    if (((gMain.newKeys & DPAD_LEFT)
     || ((gMain.newKeys & L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
     && sPokedexView->selectedScreen > 0)
    {
        sPokedexView->selectedScreen--;
        sub_80BFD0C(sPokedexView->selectedScreen, 0xD);
        PlaySE(SE_Z_PAGE);
        return;
    }
    if (((gMain.newKeys & DPAD_RIGHT)
     || ((gMain.newKeys & R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
     && sPokedexView->selectedScreen < 3)
    {
        sPokedexView->selectedScreen++;
        sub_80BFD0C(sPokedexView->selectedScreen, 0xD);
        PlaySE(SE_Z_PAGE);
        return;
    } */
	 if ((gMain.newKeys & DPAD_RIGHT || (gMain.newKeys & R_BUTTON && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)))
	 {
		 sPokedexView->selectedScreen = AREA_SCREEN;
        BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
        sPokedexView->unk64E = 1;
        gTasks[taskId].func = LoadSelectedScreen;
        PlaySE(SE_PIN);
	 }
}

void LoadSelectedScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        switch (sPokedexView->unk64E)
        {
            case 11:
                gTasks[taskId].func = LoadInfoScreen;
                break;
            case 1:
            default:
                gTasks[taskId].func = LoadAreaScreen;
                break;
            case 2:
                gTasks[taskId].func = LoadCryScreen;
                break;
            case 3:
                gTasks[taskId].func = LoadSizeScreen;
                break;
        }
    }
}

void BeginChangeInfoScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        gTasks[taskId].func = LoadInfoScreen;
    }
}

void BeginReturnToPokedex(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        FreeWindowAndBgBuffers_();
        DestroyTask(taskId);
    }
}

void LoadAreaScreen(u8 taskId)
{
    switch (gMain.state)
    {
        case 0:
        default:
            if (!gPaletteFade.active)
            {
                sPokedexView->unk64A = 5;
                gUnknown_030060B4 = gMain.vblankCallback;
                SetVBlankCallback(NULL);
                ResetOtherVideoRegisters(DISPCNT_BG1_ON);
                sPokedexView->selectedScreen = AREA_SCREEN;
                gMain.state = 1;
            }
            break;
        case 1:
            sub_80BFCDC(0xD); //HGSS_Ui
            //sub_80BFD7C(0, 0xD);
            LoadPokedexBgPalette(sPokedexView->unk64C_1);
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(13) | BGCNT_16COLOR | BGCNT_TXT256x256);
            gMain.state++;
            break;
        case 2:
            ShowPokedexAreaScreen(sPokedexListItem->species, &sPokedexView->unk64E);
            SetVBlankCallback(gUnknown_030060B4);
            sPokedexView->unk64E = 0;
            gMain.state = 0;
            gTasks[taskId].func = WaitForAreaScreenInput;
            break;
    }
}

static void WaitForAreaScreenInput(u8 taskId)
{
// See Task_PokedexAreaScreen_1() in pokedex_area_screen.c
    if (sPokedexView->unk64E != 0)
        gTasks[taskId].func = sub_80BF1EC;
}

void sub_80BF1EC(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        switch (sPokedexView->unk64E)
        {
            case 1:
            default:
                gTasks[taskId].func = LoadInfoScreen;
                break;
            case 2:
                if (!sPokedexListItem->owned)
                PlaySE(SE_HAZURE);
            else
                gTasks[taskId].func = Task_LoadStatsScreen;
                break;
        }
    }
}

void LoadCryScreen(u8 taskId)
{
    switch (gMain.state)
    {
        case 0:
        default:
            if (!gPaletteFade.active)
            {
                m4aMPlayStop(&gMPlayInfo_BGM);
                sPokedexView->unk64A = 6;
                gUnknown_030060B4 = gMain.vblankCallback;
                SetVBlankCallback(NULL);
                ResetOtherVideoRegisters(DISPCNT_BG1_ON);
                sPokedexView->selectedScreen = CRY_SCREEN;
                gMain.state = 1;
            }
            break;
        case 1:
            DecompressAndLoadBgGfxUsingHeap(3, &gPokedexMenuRest_Gfx, 0x2000, 0, 0);
            CopyToBgTilemapBuffer(3, &gPokedexTilemap_CryScreen, 0, 0);
            FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
            PutWindowTilemap(WIN_INFO);
            PutWindowTilemap(WIN_VU_METER);
            PutWindowTilemap(WIN_CRY_WAVE);
            gMain.state++;
            break;
        case 2:
            sub_80BFCDC(0xD); //HGSS_Ui
            //sub_80BFD7C(1, 0xD);
            LoadPokedexBgPalette(sPokedexView->unk64C_1);
            gMain.state++;
            break;
        case 3:
            ResetPaletteFade();
            gMain.state++;
            break;
        case 4:
            PrintInfoPageText(gText_CryOf, 0x52, 33);
            sub_80C0B44(0, sPokedexListItem->dexNum, 0x52, 49);
            gMain.state++;
            break;
        case 5:
            gTasks[taskId].tMonSpriteId = CreateMonSpriteFromSpeciesNumber(sPokedexListItem->species, 48, 56, 0, FALSE);
            gSprites[gTasks[taskId].tMonSpriteId].oam.priority = 0;
            gDexCryScreenState = 0;
            gMain.state++;
            break;
        case 6:
            {
                struct CryRelatedStruct sp4;

                sp4.unk0 = 0x4020;
                sp4.unk2 = 0x1F;
                sp4.paletteNo = 8;
                sp4.yPos = 0x1E;
                sp4.xPos = 0xC;
                if (sub_8145354(&sp4, 2) != 0)
                {
                    gMain.state++;
                    gDexCryScreenState = 0;
                }
            }
            break;
        case 7:
            {
                struct CryRelatedStruct spC;

                spC.paletteNo = 9;
                spC.xPos = 0x12;
                spC.yPos = 3;
                if (sub_8145850(&spC, 3) != 0)
                    gMain.state++;
                CopyWindowToVram(WIN_VU_METER, 2);
                CopyWindowToVram(WIN_INFO, 3);
                CopyBgTilemapBufferToVram(0);
                CopyBgTilemapBufferToVram(1);
                CopyBgTilemapBufferToVram(2);
                CopyBgTilemapBufferToVram(3);
            }
            break;
        case 8:
            BeginNormalPaletteFade(0xFFFFFFEB, 0, 0x10, 0, RGB_BLACK);
            SetVBlankCallback(gUnknown_030060B4);
            gMain.state++;
            break;
        case 9:
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            gMain.state++;
            break;
        case 10:
            sPokedexView->unk64E = 0;
            gMain.state = 0;
            gTasks[taskId].func = sub_80BF5CC;
            break;
    }
}

void sub_80BF5CC(u8 taskId)
{
    sub_814545C(2);

    if (IsCryPlaying())
        sub_80BF7FC(1);
    else
        sub_80BF7FC(0);

    if (gMain.newKeys & A_BUTTON)
    {
        sub_80BF7FC(1);
        sub_8145534(sPokedexListItem->species);
        return;
    }
    else if (!gPaletteFade.active)
    {
        if (gMain.newKeys & B_BUTTON)
        {
            BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
            m4aMPlayContinue(&gMPlayInfo_BGM);
            sPokedexView->unk64E = 1;
            gTasks[taskId].func = sub_80BF790;
            PlaySE(SE_PC_OFF);
            return;
        }
        if (gMain.newKeys & SELECT_BUTTON)
            if (TryToChangeForm(taskId, sub_80BF790))
                return;
        if ((gMain.newKeys & DPAD_LEFT)
         || ((gMain.newKeys & L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
        {
            BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
            m4aMPlayContinue(&gMPlayInfo_BGM);
            sPokedexView->unk64E = 2;
            gTasks[taskId].func = sub_80BF790;
            PlaySE(SE_Z_PAGE);
            return;
        }
        if ((gMain.newKeys & DPAD_RIGHT)
         || ((gMain.newKeys & R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
        {
            if (!sPokedexListItem->owned)
            {
                PlaySE(SE_HAZURE);
            }
            else
            {
                BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
                m4aMPlayContinue(&gMPlayInfo_BGM);
                sPokedexView->unk64E = 3;
                gTasks[taskId].func = sub_80BF790;
                PlaySE(SE_Z_PAGE);
            }
            return;
        }
    }
}

void sub_80BF790(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sub_8145914();
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        switch (sPokedexView->unk64E)
        {
            default:
            case 1:
                gTasks[taskId].func = LoadInfoScreen;
                break;
            case 2:
                gTasks[taskId].func = Task_LoadEvolutionScreen;
                break;
            case 11:
                gTasks[taskId].func = LoadCryScreen;
                break;
            case 3:
                gTasks[taskId].func = LoadSizeScreen;
                break;
        }
    }
}

void sub_80BF7FC(u8 a)
{
    u16 unk;

    if (a != 0)
        unk = RGB(18, 28, 0);
    else
        unk = RGB(15, 21, 0);
    LoadPalette(&unk, 0x5D, 2);
}

void LoadSizeScreen(u8 taskId)
{
    u8 spriteId;

    switch (gMain.state)
    {
        default:
        case 0:
            if (!gPaletteFade.active)
            {
                sPokedexView->unk64A = 7;
                gUnknown_030060B4 = gMain.vblankCallback;
                SetVBlankCallback(NULL);
                ResetOtherVideoRegisters(DISPCNT_BG1_ON);
                sPokedexView->selectedScreen = SIZE_SCREEN;
                gMain.state = 1;
            }
            break;
        case 1:
            DecompressAndLoadBgGfxUsingHeap(3, gPokedexMenuRest_Gfx, 0x2000, 0, 0);
            CopyToBgTilemapBuffer(3, gPokedexTilemap_SizeScreen, 0, 0);
            FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
            PutWindowTilemap(WIN_INFO);
            gMain.state++;
            break;
        case 2:
            sub_80BFCDC(0xD); //HGSS_Ui
            //sub_80BFD7C(2, 0xD);
            LoadPokedexBgPalette(sPokedexView->unk64C_1);
            gMain.state++;
            break;
        case 3:
            {
                u8 string[0x40];  //I hope this is the correct size

                StringCopy(string, gText_SizeComparedTo);
                StringAppend(string, gSaveBlock2Ptr->playerName);
                PrintInfoPageText(string, GetStringCenterAlignXOffset(1, string, 0xF0), 0x79);
                gMain.state++;
            }
            break;
        case 4:
            ResetPaletteFade();
            gMain.state++;
            break;
        case 5:
            spriteId = sub_80C0EF8(PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender), 152, 56, 0);
            gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
            gSprites[spriteId].oam.matrixNum = 1;
            gSprites[spriteId].oam.priority = 0;
            gSprites[spriteId].pos2.y = gPokedexEntries[sPokedexListItem->dexNum].trainerOffset;
            SetOamMatrix(1, gPokedexEntries[sPokedexListItem->dexNum].trainerScale, 0, 0, gPokedexEntries[sPokedexListItem->dexNum].trainerScale);
            LoadPalette(gUnknown_0856E610, (gSprites[spriteId].oam.paletteNum + 16) * 16, 0x20);
            gTasks[taskId].data[5] = spriteId;
            gMain.state++;
            break;
        case 6:
            spriteId = CreateMonSpriteFromSpeciesNumber(sPokedexListItem->species, 88, 56, 1, FALSE);
            gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
            gSprites[spriteId].oam.matrixNum = 2;
            gSprites[spriteId].oam.priority = 0;
            gSprites[spriteId].pos2.y = gPokedexEntries[sPokedexListItem->dexNum].pokemonOffset;
            SetOamMatrix(2, gPokedexEntries[sPokedexListItem->dexNum].pokemonScale, 0, 0, gPokedexEntries[sPokedexListItem->dexNum].pokemonScale);
            LoadPalette(gUnknown_0856E610, (gSprites[spriteId].oam.paletteNum + 16) * 16, 0x20);
            gTasks[taskId].tMonSpriteId = spriteId;
            CopyWindowToVram(WIN_INFO, 3);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(3);
            gMain.state++;
            break;
        case 7:
            BeginNormalPaletteFade(0xFFFFFFEB, 0, 0x10, 0, RGB_BLACK);
            SetVBlankCallback(gUnknown_030060B4);
            gMain.state++;
            break;
        case 8:
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            HideBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            gMain.state++;
            break;
        case 9:
            if (!gPaletteFade.active)
            {
                sPokedexView->unk64E = 0;
                gMain.state = 0;
                gTasks[taskId].func = sub_80BFBB0;
            }
            break;
    }
}

void sub_80BFBB0(u8 taskId)
{
    if (gMain.newKeys & B_BUTTON)
    {
        BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
        sPokedexView->unk64E = 1;
        gTasks[taskId].func = sub_80BFC78;
        PlaySE(SE_PC_OFF);
        return;
    }
    if (gMain.newKeys & SELECT_BUTTON)
        if (TryToChangeForm(taskId, sub_80BFC78))
            return;
    if ((gMain.newKeys & DPAD_LEFT)
     || ((gMain.newKeys & L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
    {
        BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
        sPokedexView->unk64E = 2;
        gTasks[taskId].func = sub_80BFC78;
        PlaySE(SE_Z_PAGE);
    }
}

void sub_80BFC78(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        FreeAndDestroyTrainerPicSprite(gTasks[taskId].data[5]);
        switch (sPokedexView->unk64E)
        {
            default:
            case 1:
                gTasks[taskId].func = LoadInfoScreen;
                break;
            case 2:
                gTasks[taskId].func = LoadCryScreen;
                break;
            case 11:
                gTasks[taskId].func = LoadSizeScreen;
                break;
        }
    }
}

void sub_80BFCDC(u16 a)
{
    //CopyToBgTilemapBuffer(1, gPokedexTilemap_ScreenSelectBar1, 0, 0);
    CopyToBgTilemapBuffer(1, gPokedexScreenSelectBarSubmenu_Tilemap_Clear, 0, 0);
    CopyBgTilemapBufferToVram(1);
}

void sub_80BFCF4(u16 a)
{
    CopyToBgTilemapBuffer(1, gPokedexTilemap_ScreenSelectBar2, 0, 0);
	CopyBgTilemapBufferToVram(1);
}
#ifdef NONMATCHING
// This doesn't match because gcc flips the naming of the r3 and r4
// registers.
void sub_80BFD0C(u8 a, u16 unused) //HGSS_Ui
{
    u8 i;
    u8 j;
    u16* ptr = GetBgTilemapBuffer(1);

    for (i = 0; i < 4; i++)
    {
        u8 row = (i * 7) + 1;
        u16 newPalette = 0x4000;

        if (i == a)
            newPalette = 0x2000;

        for (j = 0; j < 7; j++)
        {
            ptr[row + j] = (ptr[row + j] % 0x1000) | newPalette;
            ptr[row + j + 0x20] = (ptr[row + j + 0x20] % 0x1000) | newPalette;
        }
    }
    CopyBgTilemapBufferToVram(1);
}
#else
__attribute__((naked))
void sub_80BFD0C(u8 a, u16 unused)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r8\n\
    push {r7}\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    mov r8, r0\n\
    movs r0, 0x1\n\
    bl GetBgTilemapBuffer\n\
    adds r7, r0, 0\n\
    movs r1, 0\n\
_080BFD22:\n\
    lsls r0, r1, 3\n\
    subs r0, r1\n\
    adds r0, 0x1\n\
    lsls r0, 24\n\
    lsrs r5, r0, 24\n\
    movs r3, 0x80\n\
    lsls r3, 7\n\
    cmp r1, r8\n\
    bne _080BFD38\n\
    movs r3, 0x80\n\
    lsls r3, 6\n\
_080BFD38:\n\
    movs r2, 0\n\
    adds r6, r1, 0x1\n\
    ldr r4, =0x00000fff\n\
_080BFD3E:\n\
    adds r1, r5, r2\n\
    lsls r1, 1\n\
    adds r1, r7\n\
    ldrh r0, [r1]\n\
    ands r0, r4\n\
    orrs r0, r3\n\
    strh r0, [r1]\n\
    adds r1, 0x40\n\
    ldrh r0, [r1]\n\
    ands r0, r4\n\
    orrs r0, r3\n\
    strh r0, [r1]\n\
    adds r0, r2, 0x1\n\
    lsls r0, 24\n\
    lsrs r2, r0, 24\n\
    cmp r2, 0x6\n\
    bls _080BFD3E\n\
    lsls r0, r6, 24\n\
    lsrs r1, r0, 24\n\
    cmp r1, 0x3\n\
    bls _080BFD22\n\
    movs r0, 0x1\n\
    bl CopyBgTilemapBufferToVram\n\
    pop {r3}\n\
    mov r8, r3\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided\n");
}
#endif

#ifdef NONMATCHING
// This doesn't match because gcc flips the naming of the r3 and r4
// registers.
void sub_80BFD7C(u8 a, u16 b)
{
    u8 i;
    u8 j;
    u16* ptr = GetBgTilemapBuffer(1);

    for (i = 0; i < 4; i++)
    {
        u8 row = i * 7 + 1;
        u32 newPalette;

        if (i == a || i == 3)
            newPalette = 0x2000;
        else
            newPalette = 0x4000;

        for (j = 0; j < 7; j++)
        {
            ptr[row + j] = (ptr[row + j] % 0x1000) | newPalette;
            ptr[row + j + 0x20] = (ptr[row + j + 0x20] % 0x1000) | newPalette;
        }
    }
    CopyBgTilemapBufferToVram(1);
}
#else
__attribute__((naked))
void sub_80BFD7C(u8 a, u16 b)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r8\n\
    push {r7}\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    mov r8, r0\n\
    movs r0, 0x1\n\
    bl GetBgTilemapBuffer\n\
    adds r7, r0, 0\n\
    movs r1, 0\n\
_080BFD92:\n\
    lsls r0, r1, 3\n\
    subs r0, r1\n\
    adds r0, 0x1\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    cmp r1, r8\n\
    beq _080BFDA4\n\
    cmp r1, 0x3\n\
    bne _080BFDAA\n\
_080BFDA4:\n\
    movs r3, 0x80\n\
    lsls r3, 6\n\
    b _080BFDAE\n\
_080BFDAA:\n\
    movs r3, 0x80\n\
    lsls r3, 7\n\
_080BFDAE:\n\
    movs r2, 0\n\
    adds r5, r1, 0x1\n\
    ldr r4, =0x00000fff\n\
_080BFDB4:\n\
    adds r1, r6, r2\n\
    lsls r1, 1\n\
    adds r1, r7\n\
    ldrh r0, [r1]\n\
    ands r0, r4\n\
    orrs r0, r3\n\
    strh r0, [r1]\n\
    adds r1, 0x40\n\
    ldrh r0, [r1]\n\
    ands r0, r4\n\
    orrs r0, r3\n\
    strh r0, [r1]\n\
    adds r0, r2, 0x1\n\
    lsls r0, 24\n\
    lsrs r2, r0, 24\n\
    cmp r2, 0x6\n\
    bls _080BFDB4\n\
    lsls r0, r5, 24\n\
    lsrs r1, r0, 24\n\
    cmp r1, 0x3\n\
    bls _080BFD92\n\
    movs r0, 0x1\n\
    bl CopyBgTilemapBufferToVram\n\
    pop {r3}\n\
    mov r8, r3\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided\n");
}
#endif

u8 CreateDexDisplayMonDataTask(u16 species, u32 trainerId, u32 personality)
{
    u8 taskId = CreateTask(Task_DisplayNewMonData, 0);

    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = species;
    gTasks[taskId].data[12] = trainerId;
    gTasks[taskId].data[13] = trainerId >> 16;
    gTasks[taskId].data[14] = personality;
    gTasks[taskId].data[15] = personality >> 16;
    return taskId;
}

// different from pokemon_summary_screen
#define TYPE_ICON_PAL_NUM_0     13
#define TYPE_ICON_PAL_NUM_1     14
#define TYPE_ICON_PAL_NUM_2     15
static const u8 sMoveTypeToOamPaletteNum[NUMBER_OF_MON_TYPES + CONTEST_CATEGORIES_COUNT] =
{
    [TYPE_NORMAL] = TYPE_ICON_PAL_NUM_0,
    [TYPE_FIGHTING] = TYPE_ICON_PAL_NUM_0,
    [TYPE_FLYING] = TYPE_ICON_PAL_NUM_1,
    [TYPE_POISON] = TYPE_ICON_PAL_NUM_1,
    [TYPE_GROUND] = TYPE_ICON_PAL_NUM_0,
    [TYPE_ROCK] = TYPE_ICON_PAL_NUM_0,
    [TYPE_BUG] = TYPE_ICON_PAL_NUM_2,
    [TYPE_GHOST] = TYPE_ICON_PAL_NUM_1,
    [TYPE_STEEL] = TYPE_ICON_PAL_NUM_0,
    [TYPE_MYSTERY] = TYPE_ICON_PAL_NUM_2,
    [TYPE_FIRE] = TYPE_ICON_PAL_NUM_0,
    [TYPE_WATER] = TYPE_ICON_PAL_NUM_1,
    [TYPE_GRASS] = TYPE_ICON_PAL_NUM_2,
    [TYPE_ELECTRIC] = TYPE_ICON_PAL_NUM_0,
    [TYPE_PSYCHIC] = TYPE_ICON_PAL_NUM_1,
    [TYPE_ICE] = TYPE_ICON_PAL_NUM_1,
    [TYPE_DRAGON] = TYPE_ICON_PAL_NUM_2,
    [TYPE_DARK] = TYPE_ICON_PAL_NUM_0,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_COOL] = TYPE_ICON_PAL_NUM_0,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_BEAUTY] = TYPE_ICON_PAL_NUM_1,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_CUTE] = TYPE_ICON_PAL_NUM_1,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_SMART] = TYPE_ICON_PAL_NUM_2,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_TOUGH] = TYPE_ICON_PAL_NUM_0,
    [TYPE_FAIRY] = TYPE_ICON_PAL_NUM_1, //based on battle_engine
};

#define NewMonDataTypeIconSpriteId0 gTasks[taskId].data[4]
#define NewMonDataTypeIconSpriteId1 gTasks[taskId].data[5]
static void Task_DisplayNewMonData(u8 taskId)
{
    u8 spriteId;
    u16 species = gTasks[taskId].data[1];
    u16 dexNum = SpeciesToNationalPokedexNum(species);

    switch (gTasks[taskId].data[0])
    {
        case 0:
        default:
            if (!gPaletteFade.active)
            {
                gUnknown_030060B4 = gMain.vblankCallback;
                SetVBlankCallback(NULL);
                ResetOtherVideoRegisters(DISPCNT_BG0_ON);
                ResetBgsAndClearDma3BusyFlags(0);
                InitBgsFromTemplates(0, sNewEntryInfoScreen_BgTemplate, 2);
                SetBgTilemapBuffer(3, AllocZeroed(0x800));
                SetBgTilemapBuffer(2, AllocZeroed(0x800));
                InitWindows(sNewEntryInfoScreen_WindowTemplates);
                DeactivateAllTextPrinters();
                gTasks[taskId].data[0] = 1;
            }
            break;
        case 1:
            DecompressAndLoadBgGfxUsingHeap(3, gPokedexMenu_Gfx, 0x2000, 0, 0);
            CopyToBgTilemapBuffer(3, gPokedexTilemap_DescriptionScreen, 0, 0);
            FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
            PutWindowTilemap(WIN_INFO);
            PutWindowTilemap(WIN_FOOTPRINT);
            PrintFootprint(WIN_FOOTPRINT, dexNum);
            CopyWindowToVram(WIN_FOOTPRINT, 2);
            ResetPaletteFade();
            LoadPokedexBgPalette(0);
            gTasks[taskId].data[0]++;
            break;
        case 2:
            LoadCompressedSpriteSheet(&sSpriteSheet_MoveTypes);
            LoadCompressedPalette(gMoveTypes_Pal, 0x1D0, 0x60);
            NewMonDataTypeIconSpriteId0 = CreateSprite(&sSpriteTemplate_MoveTypes, 10, 10, 2);
            NewMonDataTypeIconSpriteId1 = CreateSprite(&sSpriteTemplate_MoveTypes, 10, 10, 2);
            gSprites[NewMonDataTypeIconSpriteId0].invisible = gSprites[NewMonDataTypeIconSpriteId1].invisible = TRUE;
            gTasks[taskId].data[0]++;
            break;
        case 3:
            PrintMonInfo(species, IsNationalPokedexEnabled(), 1, 1);
			
            {
                u8 type1 = gBaseStats[species].type1;
                u8 type2 = gBaseStats[species].type2;

                struct Sprite *sprite = &gSprites[NewMonDataTypeIconSpriteId0];
                StartSpriteAnim(sprite, type1);
                sprite->oam.paletteNum = sMoveTypeToOamPaletteNum[type1];
                sprite->pos1.x = 147 + 16;
                sprite->pos1.y = 48 + 8;
                sprite->invisible = FALSE;
                if (type1 != type2)
                {
                    struct Sprite *sprite = &gSprites[NewMonDataTypeIconSpriteId1];
                    StartSpriteAnim(sprite, type2);
                    sprite->oam.paletteNum = sMoveTypeToOamPaletteNum[type2];
                    sprite->pos1.x = 147 + 33 + 16;
                    sprite->pos1.y = 48 + 8;
                    sprite->invisible = FALSE;
                }
            }
			
            CopyWindowToVram(WIN_INFO, 3);
			CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(3);
            gTasks[taskId].data[0]++;
            break;
        case 4:
			spriteId = CreateMonSpriteFromSpeciesNumber(species, 48, 56, 0, SPECIES_HAS_GENDER_DIFFERENCE(species) && GetGenderFromSpeciesAndPersonality(species, gTasks[taskId].data[14] | (gTasks[taskId].data[15] << 16)) == MON_FEMALE);
            gSprites[spriteId].oam.priority = 0;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
            SetVBlankCallback(gUnknown_030060B4);
            gTasks[taskId].data[3] = spriteId;
            gTasks[taskId].data[0]++;
            break;
        case 5:
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            ShowBg(2);
            ShowBg(3);
            gTasks[taskId].data[0]++;
            break;
        case 6:
            if (!gPaletteFade.active)
            {
                PlayCry1(species, 0);
                gTasks[taskId].data[2] = 0;
                gTasks[taskId].func = sub_80C0088;
            }
            break;
    }
}

void sub_80C0088(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
		u32 fadingPalettes = 0x0000FFFF;

        fadingPalettes |= (1 << (gSprites[NewMonDataTypeIconSpriteId0].oam.paletteNum + 16));
        if (gSprites[NewMonDataTypeIconSpriteId1].invisible == FALSE)
            fadingPalettes |= (1 << (gSprites[NewMonDataTypeIconSpriteId1].oam.paletteNum + 16));
        BeginNormalPaletteFade(fadingPalettes, 0, 0, 16, RGB_BLACK);
        gSprites[gTasks[taskId].data[3]].callback = sub_80C01CC;
        gTasks[taskId].func = blockset_load_palette_to_gpu;
    }
    else if (++gTasks[taskId].data[2] & 0x10)
    {
        LoadPalette(gPokedexText_Pal + 1, 0x31, 14);
    }
    else
    {
        LoadPalette(gPokedexCaughtScreenFade_Pal + 1, 0x31, 14);
    }
}

void blockset_load_palette_to_gpu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        u16 species;
        u32 otId;
        u32 personality;
        u8 paletteNum;
        const u32 *lzPaletteData;
        void *buffer;

        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        FreeAllWindowBuffers();
        buffer = GetBgTilemapBuffer(2);
        if (buffer)
            Free(buffer);
        buffer = GetBgTilemapBuffer(3);
        if (buffer)
            Free(buffer);

	    DestroySprite(&gSprites[NewMonDataTypeIconSpriteId0]);
        DestroySprite(&gSprites[NewMonDataTypeIconSpriteId1]);
        species = gTasks[taskId].data[1];
        otId = ((u16)gTasks[taskId].data[13] << 16) | (u16)gTasks[taskId].data[12];
        personality = ((u16)gTasks[taskId].data[15] << 16) | (u16)gTasks[taskId].data[14];
        paletteNum = gSprites[gTasks[taskId].data[3]].oam.paletteNum;
        lzPaletteData = GetMonSpritePalFromSpeciesAndPersonality(species, otId, personality);
        LoadCompressedPalette(lzPaletteData, 0x100 | paletteNum * 16, 32);
        DestroyTask(taskId);
    }
}

void sub_80C01CC(struct Sprite *sprite)
{
    if (sprite->pos1.x < 0x78)
        sprite->pos1.x += 2;
    if (sprite->pos1.x > 0x78)
        sprite->pos1.x -= 2;

    if (sprite->pos1.y < 0x50)
        sprite->pos1.y += 1;
    if (sprite->pos1.y > 0x50)
        sprite->pos1.y -= 1;
}

//Type Icon
static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible)
{
    gSprites[sPokedexView->typeIconSpriteIds[spriteArrayId]].invisible = invisible;
}

static void SetTypeIconPosAndPal(u8 typeId, u8 x, u8 y, u8 spriteArrayId)
{
    struct Sprite *sprite;

    sprite = &gSprites[sPokedexView->typeIconSpriteIds[spriteArrayId]];
    StartSpriteAnim(sprite, typeId);
    sprite->oam.paletteNum = sMoveTypeToOamPaletteNum[typeId];
    sprite->pos1.x = x + 16;
    sprite->pos1.y = y + 8;
    SetSpriteInvisibility(spriteArrayId, FALSE);
}
static void PrintSpeciesTypeInfo(u16 species)
{
    u32 i;
    u8 type1, type2;

    //type icon(s)
    type1 = gBaseStats[species].type1;
    type2 = gBaseStats[species].type2;
    if (species == SPECIES_NONE)
        type1 = type2 = TYPE_MYSTERY;

    if (type1 == type2)
    {
        SetTypeIconPosAndPal(type1, 147, 48, 0);
        SetSpriteInvisibility(1, TRUE);
    }
    else
    {
        SetTypeIconPosAndPal(type1, 147, 48, 0);
        SetTypeIconPosAndPal(type2, 147 + 33, 48, 1);
    }

}
static void CreateTypeIconSprites(void)
{
    u8 i;

    LoadCompressedSpriteSheet(&sSpriteSheet_MoveTypes);
    LoadCompressedPalette(gMoveTypes_Pal, 0x1D0, 0x60);
    for (i = 0; i < 2; i++)
    {
        if (sPokedexView->typeIconSpriteIds[i] == 0xFF)
            sPokedexView->typeIconSpriteIds[i] = CreateSprite(&sSpriteTemplate_MoveTypes, 10, 10, 2);

        SetSpriteInvisibility(i, TRUE);
    }
}

static void PrintMonInfo(u32 natNum, u32 value, u32 owned, u32 newEntry)
{
    u8 str[0x10];
    u8 str2[0x20];
	u16 num = SpeciesToNationalPokedexNum(natNum);
    const u8 *text;
    const u8 *text2;
    const u8 *text3;

   // if (newEntry)
     //   PrintInfoPageText(gText_PokedexRegistration, GetStringCenterAlignXOffset(1, gText_PokedexRegistration, 0xF0), 0);
    if (value == 0)
        value = NationalToHoennOrder(num);
    else
        value = num;
    ConvertIntToDecimalStringN(StringCopy(str, gText_NumberClear01), value, STR_CONV_MODE_LEADING_ZEROS, 3);
    PrintInfoScreenTextWhite(str, 123, 17); //HGSS_Ui
    if (natNum)
        text = gSpeciesNames[natNum];
    else
        text = sText_TenDashes2;
    PrintInfoScreenTextWhite(text, 157, 17); //HGSS_Ui
    if (owned)
    {
        CopyMonCategoryText(num, str2);
        text2 = str2;
    }
    else
    {
        text2 = gText_5MarksPokemon;
    }
    PrintInfoPageText(text2, 123, 31); //HGSS_Ui
    PrintInfoPageText(gText_HTHeight, 155, 64); //HGSS_Ui
    PrintInfoPageText(gText_WTWeight, 155, 77); //HGSS_Ui
    if (owned)
    {
        PrintMonHeight(gPokedexEntries[num].height, 180, 64); //HGSS_Ui
        PrintMonWeight(gPokedexEntries[num].weight, 180, 77); //HGSS_Ui
    }
    else
    {
        PrintInfoPageText(gText_UnkHeight, 180, 64); //HGSS_Ui
        PrintInfoPageText(gText_UnkWeight, 180, 77); //HGSS_Ui
    }
    if (owned)
	{
        text3 = gPokedexEntries[num].description;
	}
    else
        text3 = gExpandedPlaceholder_PokedexDescription;
    PrintInfoPageText(text3, GetStringCenterAlignXOffset(1, text3, 0xF0), 93); //HGSS_Ui

    //Type Icon(s) //HGSS_Ui
    if (owned && !newEntry)
        PrintSpeciesTypeInfo(natNum); //HGSS_Ui
}

static void PrintMonHeight(u16 height, u8 left, u8 top)
{
    u8 buffer[16];
    u32 inches, feet;
    u8 i = 0;
    int offset;
    u8 result;
    offset = 0;
	
	if (FlagGet(FLAG_UNIT_SYSTEM) == 1) //Imperial
	{

    inches = (height * 10000) / 254;
    if (inches % 10 >= 5)
        inches += 10;
    feet = inches / 120;
    inches = (inches - (feet * 120)) / 10;

    buffer[i++] = EXT_CTRL_CODE_BEGIN;
    buffer[i++] = 0x13;
    if (feet / 10 == 0)
    {
        buffer[i++] = 18;
        buffer[i++] = feet + CHAR_0;
    }
    else
    {
        buffer[i++] = 12;
        buffer[i++] = feet / 10 + CHAR_0;
        buffer[i++] = (feet % 10) + CHAR_0;
    }
    buffer[i++] = CHAR_SGL_QUOT_RIGHT;
    buffer[i++] = (inches / 10) + CHAR_0;
    buffer[i++] = (inches % 10) + CHAR_0;
    buffer[i++] = CHAR_DBL_QUOT_RIGHT;
    buffer[i++] = EOS;
    PrintInfoPageText(buffer, left, top);
    }
    else //Metric
    {
        buffer[i++] = EXT_CTRL_CODE_BEGIN;
        buffer[i++] = EXT_CTRL_CODE_CLEAR_TO;
        i++;
        buffer[i++] = CHAR_SPACE;
        buffer[i++] = CHAR_SPACE;
        buffer[i++] = CHAR_SPACE;
        buffer[i++] = CHAR_SPACE;
        buffer[i++] = CHAR_SPACE;

        result = (height / 1000);
        if (result == 0)
        {
            offset = 6;
        }
        else
        {
            buffer[i++] = result + CHAR_0;
        }

        result = (height % 1000) / 100;
        if (result == 0 && offset != 0)
        {
            offset += 6;
        }
        else
        {
            buffer[i++] = result + CHAR_0;
        }

        buffer[i++] = (((height % 1000) % 100) / 10) + CHAR_0;
        buffer[i++] = CHAR_COMMA;
        buffer[i++] = (((height % 1000) % 100) % 10) + CHAR_0;
        buffer[i++] = CHAR_SPACE;
        buffer[i++] = CHAR_m;

        buffer[i++] = EOS;
        buffer[2] = offset;
        PrintInfoPageText(buffer, left, top);   
    }
}

static void PrintMonWeight(u16 weight, u8 left, u8 top)
{
    u8 buffer[16];
    u8 buffer_metric[18];
    bool8 output;
    u8 i = 0;
    u32 lbs = (weight * 100000) / 4536;
    int offset = 0;
    u8 result;

	if (FlagGet(FLAG_UNIT_SYSTEM) == 1) //Imperial
    {
    if (lbs % 10u >= 5)
        lbs += 10;
    i = 0;
    output = FALSE;

    if ((buffer[i] = (lbs / 100000) + CHAR_0) == CHAR_0 && !output)
    {
        buffer[i++] = 0x77;
    }
    else
    {
        output = TRUE;
        i++;
    }

    lbs %= 100000;
    if ((buffer[i] = (lbs / 10000) + CHAR_0) == CHAR_0 && !output)
    {
        buffer[i++] = 0x77;
    }
    else
    {
        output = TRUE;
        i++;
    }

    lbs %= 10000;
    if ((buffer[i] = (lbs / 1000) + CHAR_0) == CHAR_0 && !output)
    {
        buffer[i++] = 0x77;
    }
    else
    {
        output = TRUE;
        i++;
    }

    lbs %= 1000;
    buffer[i++] = (lbs / 100) + CHAR_0;
    lbs %= 100;
    buffer[i++] = CHAR_PERIOD;
    buffer[i++] = (lbs / 10) + CHAR_0;
    buffer[i++] = CHAR_SPACE;
    buffer[i++] = CHAR_l;
    buffer[i++] = CHAR_b;
    buffer[i++] = CHAR_s;
    buffer[i++] = CHAR_PERIOD;
    buffer[i++] = EOS;
    PrintInfoPageText(buffer, left, top);
    }
    else //Metric
    {
        buffer_metric[i++] = EXT_CTRL_CODE_BEGIN;
        buffer_metric[i++] = EXT_CTRL_CODE_CLEAR_TO;
        i++;
        buffer_metric[i++] = CHAR_SPACE;
        buffer_metric[i++] = CHAR_SPACE;
        buffer_metric[i++] = CHAR_SPACE;
        buffer_metric[i++] = CHAR_SPACE;
        buffer_metric[i++] = CHAR_SPACE;

        result = (weight / 1000);
        if (result == 0)
            offset = 6;
        else
            buffer_metric[i++] = result + CHAR_0;

        result = (weight % 1000) / 100;
        if (result == 0 && offset != 0)
            offset += 6;
        else
            buffer_metric[i++] = result + CHAR_0;

        buffer_metric[i++] = (((weight % 1000) % 100) / 10) + CHAR_0;
        buffer_metric[i++] = CHAR_COMMA;
        buffer_metric[i++] = (((weight % 1000) % 100) % 10) + CHAR_0;
        buffer_metric[i++] = CHAR_SPACE;
        buffer_metric[i++] = CHAR_k;
        buffer_metric[i++] = CHAR_g;

        buffer_metric[i++] = EOS;
        buffer_metric[2] = offset;
        PrintInfoPageText(buffer_metric, left, top);
    }
}

const u8 *GetPokedexCategoryName(u16 dexNum) // unused
{
    return gPokedexEntries[dexNum].categoryName;
}

u16 GetPokedexHeightWeight(u16 dexNum, u8 data)
{
    switch (data)
    {
    case 0:  // height
        return gPokedexEntries[dexNum].height;
    case 1:  // weight
        return gPokedexEntries[dexNum].weight;
    default:
        return 1;
    }
}

s8 GetSetPokedexFlag(u16 nationalDexNo, u8 caseID)
{
    u8 index;
    u8 bit;
    u8 mask;
    s8 retVal;

    nationalDexNo--;
    index = nationalDexNo / 8;
    bit = nationalDexNo % 8;
    mask = 1 << bit;
    retVal = 0;
    switch (caseID)
    {
    case FLAG_GET_SEEN:
        if (gSaveBlock2Ptr->pokedex.seen[index] & mask)
        {
            #ifndef FREE_EXTRA_SEEN_FLAGS
            if ((gSaveBlock2Ptr->pokedex.seen[index] & mask) == (gSaveBlock1Ptr->seen1[index] & mask)
             && (gSaveBlock2Ptr->pokedex.seen[index] & mask) == (gSaveBlock1Ptr->seen2[index] & mask))
                retVal = 1;
            else
            {
                gSaveBlock2Ptr->pokedex.seen[index] &= ~mask;
                gSaveBlock1Ptr->seen1[index] &= ~mask;
                gSaveBlock1Ptr->seen2[index] &= ~mask;
                retVal = 0;
            }
            #else
                retVal = 1;
            #endif
        }
        break;
    case FLAG_GET_CAUGHT:
        if (gSaveBlock2Ptr->pokedex.owned[index] & mask)
        {
            #ifndef FREE_EXTRA_SEEN_FLAGS
            if ((gSaveBlock2Ptr->pokedex.owned[index] & mask) == (gSaveBlock2Ptr->pokedex.seen[index] & mask)
             && (gSaveBlock2Ptr->pokedex.owned[index] & mask) == (gSaveBlock1Ptr->seen1[index] & mask)
             && (gSaveBlock2Ptr->pokedex.owned[index] & mask) == (gSaveBlock1Ptr->seen2[index] & mask))
                retVal = 1;
            else
            {
                gSaveBlock2Ptr->pokedex.owned[index] &= ~mask;
                gSaveBlock2Ptr->pokedex.seen[index] &= ~mask;
                gSaveBlock1Ptr->seen1[index] &= ~mask;
                gSaveBlock1Ptr->seen2[index] &= ~mask;
                retVal = 0;
            }
            #else
                retVal = 1;
            #endif
        }
        break;
    case FLAG_SET_SEEN:
        gSaveBlock2Ptr->pokedex.seen[index] |= mask;
        #ifndef FREE_EXTRA_SEEN_FLAGS
        gSaveBlock1Ptr->seen1[index] |= mask;
        gSaveBlock1Ptr->seen2[index] |= mask;
        #endif
        break;
    case FLAG_SET_CAUGHT:
        gSaveBlock2Ptr->pokedex.owned[index] |= mask;
        break;
    }
    return retVal;
}

u16 GetNationalPokedexCount(u8 caseID)
{
    u16 count = 0;
    u16 i;

    for (i = 0; i < NATIONAL_DEX_COUNT; i++)
    {
        switch (caseID)
        {
        case FLAG_GET_SEEN:
            if (GetSetPokedexFlag(i + 1, FLAG_GET_SEEN))
                count++;
            break;
        case FLAG_GET_CAUGHT:
            if (GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT))
                count++;
            break;
        }
    }
    return count;
}

u16 GetHoennPokedexCount(u8 caseID)
{
    u16 count = 0;
    u16 i;

    for (i = 0; i < HOENN_DEX_COUNT; i++)
    {
        switch (caseID)
        {
        case FLAG_GET_SEEN:
            if (GetSetPokedexFlag(HoennToNationalOrder(i + 1), FLAG_GET_SEEN))
                count++;
            break;
        case FLAG_GET_CAUGHT:
            if (GetSetPokedexFlag(HoennToNationalOrder(i + 1), FLAG_GET_CAUGHT))
                count++;
            break;
        }
    }
    return count;
}

u16 GetKantoPokedexCount(u8 caseID)
{
    u16 count = 0;
    u16 i;

    for (i = 0; i < KANTO_DEX_COUNT; i++)
    {
        switch (caseID)
        {
        case FLAG_GET_SEEN:
            if (GetSetPokedexFlag(i + 1, FLAG_GET_SEEN))
                count++;
            break;
        case FLAG_GET_CAUGHT:
            if (GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT))
                count++;
            break;
        }
    }
    return count;
}

bool16 HasAllHoennMons(void)
{
    u16 i;

    for (i = 0; i < HOENN_DEX_COUNT - 2; i++)
    {
        if (!GetSetPokedexFlag(HoennToNationalOrder(i + 1), FLAG_GET_CAUGHT))
            return FALSE;
    }
    return TRUE;
}

bool8 HasAllKantoMons(void)
{
    u16 i;

    for (i = 0; i < KANTO_DEX_COUNT - 1; i++)
    {
        if (!GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT))
            return FALSE;
    }
    return TRUE;
}

bool16 HasAllMons(void)
{
    u16 i;

    for (i = 0; i < NATIONAL_DEX_HYDRAPPLE; i++)
    {
        if (!GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT))
            return FALSE;
    }
    return TRUE;
}

static void ResetOtherVideoRegisters(u16 a)
{
    if (!(a & DISPCNT_BG0_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG0_ON);
        SetGpuReg(REG_OFFSET_BG0CNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    }
    if (!(a & DISPCNT_BG1_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG1_ON);
        SetGpuReg(REG_OFFSET_BG1CNT, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    }
    if (!(a & DISPCNT_BG2_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG2_ON);
        SetGpuReg(REG_OFFSET_BG2CNT, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    }
    if (!(a & DISPCNT_BG3_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG3_ON);
        SetGpuReg(REG_OFFSET_BG3CNT, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    }
    if (!(a & DISPCNT_OBJ_ON))
    {
        ClearGpuRegBits(0, DISPCNT_OBJ_ON);
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
    }
}

void sub_80C0A88(u8 windowId, const u8 *str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = 0;
    color[1] = 15;
    color[2] = 3;

    AddTextPrinterParameterized4(windowId, 1, left, top, 0, 0, color, -1, str);
}

void sub_80C0AC4(u8 windowId, u16 order, u8 left, u8 top) // unused
{
    u8 str[4];

    str[0] = CHAR_0 + order / 100;
    str[1] = CHAR_0 + (order % 100) / 10;
    str[2] = CHAR_0 + (order % 100) % 10;
    str[3] = EOS;
    sub_80C0A88(windowId, str, left, top);
}

u8 sub_80C0B44(u8 windowId, u16 num, u8 left, u8 top)
{
    u8 str[11];
    u8 i;

    for (i = 0; i < 11; i++)
        str[i] = EOS;
    num = NationalPokedexNumToSpecies(num);
    switch (num)
    {
        default:
            for (i = 0; gSpeciesNames[num][i] != EOS && i < 10; i++)
                str[i] = gSpeciesNames[num][i];
            break;
        case 0:
            for (i = 0; i < 5; i++)
                str[i] = CHAR_HYPHEN;
            break;
    }
    sub_80C0A88(windowId, str, left, top);
    return i;
}

void sub_80C0BF0(u8 windowId, const u8* str, u8 left, u8 top) // unused
{
    u8 str2[11];
    u8 i;
    u8 count;

    for (i = 0; i < 11; i++)
        str2[i] = CHAR_SPACE;
    for (count = 0; str[count] != CHAR_SPACE && count < 11; count++)
        ;
    for (i = 0; i < count; i++)
        str2[11 - count + i] = str[i];
    str2[11] = EOS;
    sub_80C0A88(windowId, str2, left, top);
}

void sub_80C0C6C(u8 windowId, u16 b, u8 left, u8 top) // unused
{
    u8 str[6];
    bool8 outputted = FALSE;
    u8 result;

    result = b / 1000;
    if (result == 0)
    {
        str[0] = 0x77;
        outputted = FALSE;
    }
    else
    {
        str[0] = CHAR_0 + result;
        outputted = TRUE;
    }

    result = (b % 1000) / 100;
    if (result == 0 && !outputted)
    {
        str[1] = 0x77;
        outputted = FALSE;
    }
    else
    {
        str[1] = CHAR_0 + result;
        outputted = TRUE;
    }

    str[2] = CHAR_0 + ((b % 1000) % 100) / 10;
    str[3] = CHAR_PERIOD;
    str[4] = CHAR_0 + ((b % 1000) % 100) % 10;
    str[5] = EOS;
    sub_80C0A88(windowId, str, left, top);
}

static void PrintFootprint(u8 windowId, u16 dexNum)
{
    u8 image[32 * 4] = {0};
    const u8 * r12 = gMonFootprintTable[NationalPokedexNumToSpecies(dexNum)];
    u16 r5 = 0;
    u16 i;
    u16 j;

    if (r12 != NULL)
    {
        for (i = 0; i < 32; i++)
        {
            u8 r3 = r12[i];
            for (j = 0; j < 4; j++)
            {
                u8 value = ((r3 >> (2 * j)) & 1 ? 2 : 0);
                if ((2 << (2 * j)) & r3)
                    value |= 0x20;
                image[r5] = value;
                r5++;
            }
        }
    }
    CopyToWindowPixelBuffer(windowId, image, sizeof(image), 0);
}

void sub_80C0DC0(u16 a, u16 b)
{
    *(u16 *)(VRAM + a * 0x800 + 0x232) = 0xF000 + b + 0;
    *(u16 *)(VRAM + a * 0x800 + 0x234) = 0xF000 + b + 1;
    *(u16 *)(VRAM + a * 0x800 + 0x272) = 0xF000 + b + 2;
    *(u16 *)(VRAM + a * 0x800 + 0x274) = 0xF000 + b + 3;
}

u16 sub_80C0E0C(u8 a, u16 b, u16 c, u16 d)
{
    switch (a)
    {
        case 1:
            if (b > c)
                b--;
            break;
        case 0:
            if (b < d)
                b++;
            break;
        case 3:
            if (b > c)
                b--;
            else
                b = d;
            break;
        case 2:
            if (b < d)
                b++;
            else
                b = c;
            break;
    }
    return b;
}

u32 sub_80C0E68(u16 a)
{
    if (a == SPECIES_UNOWN || a == SPECIES_SPINDA)
    {
        if (a == SPECIES_UNOWN)
            return gSaveBlock2Ptr->pokedex.unownPersonality;
        else
            return gSaveBlock2Ptr->pokedex.spindaPersonality;
    }
    else
    {
	// PARTE DEL SCRIPT Support for Gender Differences
         return 0xFF; //Changed from 0 to make it so the Pokédex shows the default mon pics instead of the female versions.
	// PARTE DEL SCRIPT Support for Gender Differences
	}
}

u16 CreateMonSpriteFromNationalDexNumber(u16 nationalNum, s16 x, s16 y, u16 paletteSlot)
{
    u32 personality = sub_80C0E68(nationalNum);
    nationalNum = NationalPokedexNumToSpecies(nationalNum);
	return CreateMonPicSprite_HandleDeoxys(nationalNum, personality ^ 0x8000, personality, TRUE, x, y, paletteSlot, 0xFFFF);
}

u16 CreateMonSpriteFromSpeciesNumber(u16 speciesNum, s16 x, s16 y, u16 paletteSlot, bool8 forceFemale)
{
    u32 personality = sub_80C0E68(speciesNum);
	if (forceFemale) personality = 1;
    return CreateMonPicSprite_HandleDeoxys(speciesNum, personality ^ 0x8000, personality, TRUE, x, y, paletteSlot, 0xFFFF);
}

u16 sub_80C0EF8(u16 species, s16 x, s16 y, s8 paletteSlot)
{
    return CreateTrainerPicSprite(species, TRUE, x, y, paletteSlot, 0xFFFF);
}

bool8  SpeciesCanLearnLvlUpMove(u16 species, u16 move) //Move search PokedexPlus HGSS_Ui
{
    u16 j;
    for (j = 0; j < MAX_LEVEL && gLevelUpLearnsets[species][j] != LEVEL_UP_END; j++)
    {
        if (move == (gLevelUpLearnsets[species][j] & LEVEL_UP_MOVE_ID))
        {
            return TRUE;
        }
    }
    return FALSE;
}

int sub_80C0F30(u8 dexMode, u8 sortMode, u8 abcGroup, u8 bodyColor, u8 type1, u8 type2) // ,u16 move)
{
    u16 species;
    u16 i,j;
    u16 resultsCount;
    u8 types[2];
	
    u8 tutorMoveId, tmMoveId; //PokedexPlus HGSS_Ui
    u16 move = 0xFFFF;

    CreatePokedexList(dexMode, sortMode);

    for (i = 0, resultsCount = 0; i < NATIONAL_DEX_COUNT; i++)
    {
        if (sPokedexView->pokedexList[i].seen)
        {
            sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
            resultsCount++;
        }
    }
    sPokedexView->pokemonListCount = resultsCount;

    // Search by name
    if (abcGroup != 0xFF)
    {
        for (i = 0, resultsCount = 0; i < sPokedexView->pokemonListCount; i++)
        {
            u8 r3;

            species = NationalPokedexNumToSpecies(sPokedexView->pokedexList[i].dexNum);
            r3 = gSpeciesNames[species][0];
            if ((r3 >= gUnknown_0856ED08[abcGroup][0] && r3 < gUnknown_0856ED08[abcGroup][0] + gUnknown_0856ED08[abcGroup][1])
             || (r3 >= gUnknown_0856ED08[abcGroup][2] && r3 < gUnknown_0856ED08[abcGroup][2] + gUnknown_0856ED08[abcGroup][3]))
            {
                sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                resultsCount++;
            }
        }
        sPokedexView->pokemonListCount = resultsCount;
    }

    // Search by body color
    if (bodyColor != 0xFF)
    {
        for (i = 0, resultsCount = 0; i < sPokedexView->pokemonListCount; i++)
        {
            species = NationalPokedexNumToSpecies(sPokedexView->pokedexList[i].dexNum);

            if (bodyColor == gBaseStats[species].bodyColor)
            {
                sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                resultsCount++;
            }
        }
        sPokedexView->pokemonListCount = resultsCount;
    }

    // Search by type
    if (type1 != TYPE_NONE || type2 != TYPE_NONE)
    {
        if (type1 == TYPE_NONE)
        {
            type1 = type2;
            type2 = TYPE_NONE;
        }

        if (type2 == TYPE_NONE)
        {
            for (i = 0, resultsCount = 0; i < sPokedexView->pokemonListCount; i++)
            {
                if (sPokedexView->pokedexList[i].owned)
                {
                    species = NationalPokedexNumToSpecies(sPokedexView->pokedexList[i].dexNum);

                    types[0] = gBaseStats[species].type1;
                    types[1] = gBaseStats[species].type2;
                    if (types[0] == type1 || types[1] == type1)
                    {
                        sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                        resultsCount++;
                    }
                }
            }
        }
        else
        {
            for (i = 0, resultsCount = 0; i < sPokedexView->pokemonListCount; i++)
            {
                if (sPokedexView->pokedexList[i].owned)
                {
                    species = NationalPokedexNumToSpecies(sPokedexView->pokedexList[i].dexNum);

                    types[0] = gBaseStats[species].type1;
                    types[1] = gBaseStats[species].type2;
                    if ((types[0] == type1 && types[1] == type2) || (types[0] == type2 && types[1] == type1))
                    {
                        sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                        resultsCount++;
                    }
                }
            }
        }
        sPokedexView->pokemonListCount = resultsCount;
    }
	
// Search by move
    if (move != 0xFFFF)
    {
        //Calc tutor move ID
        tutorMoveId = 0xFF;
        for (i = 0; i < TUTOR_MOVE_COUNT; i++)
        {
            if(move == gTutorMoves[i])
            {
                tutorMoveId = i;
                break;
            }
        }
        //Calc tm move ID
        tmMoveId = 0xFF;
        for (i = 0; i < NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES; i++)
        {
            if(move == ItemIdToBattleMoveId(ITEM_TM01_FOCUS_PUNCH + i))
            {
                tmMoveId = (ITEM_TM01_FOCUS_PUNCH + i);
                break;
            }
        }

        for (i = 0, resultsCount = 0; i < sPokedexView->pokemonListCount; i++)
        {
            species = NationalPokedexNumToSpecies(sPokedexView->pokedexList[i].dexNum);

            //LevelUp
            if (SpeciesCanLearnLvlUpMove(species, move))
            {
                sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                resultsCount++;
                continue;
            }
            //TMHM
            if(CanSpeciesLearnTMHM(species, tmMoveId))
            {
                sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                resultsCount++;
                continue;
            }
            //Tutor
            if(CanLearnTutorMove(species, tutorMoveId))
            {
                sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                resultsCount++;
                continue;
            }
            //EGGs
            if(SpeciesCanLearnEggMove(species, move))
            {
                sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                resultsCount++;
                continue;
            }
        }
        sPokedexView->pokemonListCount = resultsCount;
    }

    if (sPokedexView->pokemonListCount != 0)
    {
        for (i = sPokedexView->pokemonListCount; i < NATIONAL_DEX_COUNT; i++)
        {
            sPokedexView->pokedexList[i].dexNum = 0xFFFF;
            sPokedexView->pokedexList[i].seen = FALSE;
            sPokedexView->pokedexList[i].owned = FALSE;
        }
    }

    return resultsCount;
}

u8 LoadSearchMenu(void)
{
    return CreateTask(Task_LoadSearchMenu, 0);
}

void sub_80C1270(const u8 *str, u32 left, u32 top)
{
    u8 color[3];

    color[0] = 0;
    color[1] = 15;
    color[2] = 2;
    AddTextPrinterParameterized4(0, 1, left, top, 0, 0, color, -1, str);
}

void sub_80C12B0(u32 x, u32 y, u32 width, u32 height)
{
    FillWindowPixelRect(0, PIXEL_FILL(0), x, y, width, height);
}

void Task_LoadSearchMenu(u8 taskId)
{
    u16 i;

    switch (gMain.state)
    {
        default:
        case 0:
            if (!gPaletteFade.active)
            {
                sPokedexView->unk64A = 2;
                ResetOtherVideoRegisters(0);
                ResetBgsAndClearDma3BusyFlags(0);
                InitBgsFromTemplates(0, sSearchMenu_BgTemplate, 4);
                SetBgTilemapBuffer(3, AllocZeroed(0x800));
                SetBgTilemapBuffer(2, AllocZeroed(0x800));
                SetBgTilemapBuffer(1, AllocZeroed(0x800));
                SetBgTilemapBuffer(0, AllocZeroed(0x800));
                InitWindows(sSearchMenu_WindowTemplate);
                DeactivateAllTextPrinters();
                PutWindowTilemap(0);
                DecompressAndLoadBgGfxUsingHeap(3, gPokedexSearchMenu_Gfx, 0x2000, 0, 0);

                if (!IsNationalPokedexEnabled())
                    CopyToBgTilemapBuffer(3, gPokedexSearch2_Tilemap, 0, 0);
                else
                    CopyToBgTilemapBuffer(3, gPokedexSearch1_Tilemap, 0, 0);
                LoadPalette(gPokedexSearchMenu_Pal + 1, 1, 0x7E);
                gMain.state = 1;
            }
            break;
        case 1:
            LoadCompressedSpriteSheet(sInterfaceSpriteSheet);
            LoadSpritePalettes(sInterfaceSpritePalette);
            LoadSpritePalettes(sStatBarSpritePal); //HGSS_Ui
            sub_80C2594(taskId);
            for (i = 0; i < 16; i++)
                gTasks[taskId].data[i] = 0;
            sub_80C23B8(taskId);
            sub_80C2040(0);
            sub_80C20F8(taskId);
            CopyWindowToVram(0, 3);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(3);
            gMain.state++;
            break;
        case 2:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            sPokedexView->statBarsSpriteId = 0xFF;  //HGSS_Ui
            CreateStatBars(&sPokedexView->pokedexList[sPokedexView->selectedPokemon]); //HGSS_Ui
            gMain.state++;
            break;
        case 3:
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            HideBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            gMain.state++;
            break;
        case 4:
            if (!gPaletteFade.active)
            {
                gTasks[taskId].func = sub_80C1570;
                gMain.state = 0;
            }
            break;
    }
}

void sub_80C152C(void)
{
    void* tilemapBuffer;

    FreeAllWindowBuffers();
    tilemapBuffer = GetBgTilemapBuffer(0);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(1);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(2);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(3);
    if (tilemapBuffer)
        Free(tilemapBuffer);
}

void sub_80C1570(u8 taskId)
{
    sub_80C2040(gTasks[taskId].data[0]);
    sub_80C20F8(taskId);
    CopyWindowToVram(0, 2);
    CopyBgTilemapBufferToVram(3);
    gTasks[taskId].func = sub_80C15B0;
}

void sub_80C15B0(u8 taskId)
{
    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_PC_OFF);
        gTasks[taskId].func = sub_80C1D38;
        return;
    }
    if (gMain.newKeys & A_BUTTON)
    {
        switch (gTasks[taskId].data[0])
        {
            case 0:
                PlaySE(SE_PIN);
                gTasks[taskId].data[1] = 0;
                gTasks[taskId].func = sub_80C16CC;
                break;
            case 1:
                PlaySE(SE_PIN);
                gTasks[taskId].data[1] = 4;
                gTasks[taskId].func = sub_80C16CC;
                break;
            case 2:
                PlaySE(SE_PC_OFF);
                gTasks[taskId].func = sub_80C1D38;
                break;
        }
        return;
    }
    if ((gMain.newKeys & DPAD_LEFT) && gTasks[taskId].data[0] > 0)
    {
        PlaySE(SE_Z_PAGE);
        gTasks[taskId].data[0]--;
        sub_80C2040(gTasks[taskId].data[0]);
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
    }
    if ((gMain.newKeys & DPAD_RIGHT) && gTasks[taskId].data[0] < 2)
    {
        PlaySE(SE_Z_PAGE);
        gTasks[taskId].data[0]++;
        sub_80C2040(gTasks[taskId].data[0]);
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
    }
}

void sub_80C16CC(u8 taskId)
{
    sub_80C2064(gTasks[taskId].data[0], gTasks[taskId].data[1]);
    sub_80C20F8(taskId);
    CopyWindowToVram(0, 2);
    CopyBgTilemapBufferToVram(3);
    gTasks[taskId].func = sub_80C170C;
}

void sub_80C170C(u8 taskId)
{
    const u8 (*r6)[4];

    if (gTasks[taskId].data[0] != 0)
    {
        if (!IsNationalPokedexEnabled())
            r6 = gUnknown_0856EDF0;
        else
            r6 = gUnknown_0856EDB8;
    }
    else
    {
        if (!IsNationalPokedexEnabled())
            r6 = gUnknown_0856EDD4;
        else
            r6 = gUnknown_0856ED9C;
    }

    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_BOWA);
        sub_80C23B8(taskId);
        gTasks[taskId].func = sub_80C1570;
        return;
    }
    if (gMain.newKeys & A_BUTTON)
    {
        if (gTasks[taskId].data[1] == 6)
        {
            if (gTasks[taskId].data[0] != 0)
            {
                gUnknown_02039B52 = 0x40;
                sPokedexView->unk62A = 0x40;
                gUnknown_02039B50 = 0;
                sPokedexView->unk610 = 0;
                gSaveBlock2Ptr->pokedex.mode = GetSearchModeSelection(taskId, SEARCH_DEX_MODE);
                if (!IsNationalPokedexEnabled())
                    gSaveBlock2Ptr->pokedex.mode = DEX_MODE_HOENN;
                sPokedexView->unk614 = gSaveBlock2Ptr->pokedex.mode;
                gSaveBlock2Ptr->pokedex.order = GetSearchModeSelection(taskId, SEARCH_ORDER);
                sPokedexView->unk618 = gSaveBlock2Ptr->pokedex.order;
                PlaySE(SE_PC_OFF);
                gTasks[taskId].func = sub_80C1D38;
            }
            else
            {
                sub_80C2618(gText_SearchingPleaseWait);
                gTasks[taskId].func = sub_80C19A4;
                PlaySE(SE_Z_SEARCH);
                CopyWindowToVram(0, 2);
            }
        }
        else
        {
            PlaySE(SE_PIN);
            gTasks[taskId].func = sub_80C1B64;
        }
        return;
    }

    if ((gMain.newKeys & DPAD_LEFT) && r6[gTasks[taskId].data[1]][0] != 0xFF)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[1] = r6[gTasks[taskId].data[1]][0];
        sub_80C2064(gTasks[taskId].data[0], gTasks[taskId].data[1]);
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
    }
    if ((gMain.newKeys & DPAD_RIGHT) && r6[gTasks[taskId].data[1]][1] != 0xFF)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[1] = r6[gTasks[taskId].data[1]][1];
        sub_80C2064(gTasks[taskId].data[0], gTasks[taskId].data[1]);
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
    }
    if ((gMain.newKeys & DPAD_UP) && r6[gTasks[taskId].data[1]][2] != 0xFF)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[1] = r6[gTasks[taskId].data[1]][2];
        sub_80C2064(gTasks[taskId].data[0], gTasks[taskId].data[1]);
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
    }
    if ((gMain.newKeys & DPAD_DOWN) && r6[gTasks[taskId].data[1]][3] != 0xFF)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[1] = r6[gTasks[taskId].data[1]][3];
        sub_80C2064(gTasks[taskId].data[0], gTasks[taskId].data[1]);
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
    }
}

void sub_80C19A4(u8 taskId)
{
    u8 dexMode = GetSearchModeSelection(taskId, SEARCH_DEX_MODE);
    u8 sortMode = GetSearchModeSelection(taskId, SEARCH_ORDER);
    u8 abcGroup = GetSearchModeSelection(taskId, SEARCH_NAME);
    u8 bodyColor = GetSearchModeSelection(taskId, SEARCH_COLOR);
    u8 type1 = GetSearchModeSelection(taskId, SEARCH_TYPE_1);
    u8 type2 = GetSearchModeSelection(taskId, SEARCH_TYPE_2);

    sub_80C0F30(dexMode, sortMode, abcGroup, bodyColor, type1, type2);
    gTasks[taskId].func = sub_80C1A4C;
}

void sub_80C1A4C(u8 taskId)
{
    if (!IsSEPlaying())
    {
        if (sPokedexView->pokemonListCount != 0)
        {
            PlaySE(SE_SEIKAI);
            sub_80C2618(gText_SearchCompleted);
        }
        else
        {
            PlaySE(SE_HAZURE);
            sub_80C2618(gText_NoMatchingPkmnWereFound);
        }
        gTasks[taskId].func = sub_80C1AB8;
        CopyWindowToVram(0, 2);
    }
}

void sub_80C1AB8(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON)
    {
        if (sPokedexView->pokemonListCount != 0)
        {
            sPokedexView->unk64E = 1;
            sPokedexView->dexMode = GetSearchModeSelection(taskId, SEARCH_DEX_MODE);
            sPokedexView->dexOrder = GetSearchModeSelection(taskId, SEARCH_ORDER);
            gTasks[taskId].func = sub_80C1D38;
            PlaySE(SE_PC_OFF);
        }
        else
        {
            gTasks[taskId].func = sub_80C16CC;
            PlaySE(SE_BOWA);
        }
    }
}

void sub_80C1B64(u8 taskId)
{
    u8 r0;
    u16 *p1;
    u16 *p2;

    sub_80C21D4(0);
    r0 = gTasks[taskId].data[1];
    p1 = &gTasks[taskId].data[sSearchOptions[r0].unk4];
    p2 = &gTasks[taskId].data[sSearchOptions[r0].unk5];
    gTasks[taskId].data[14] = *p1;
    gTasks[taskId].data[15] = *p2;
    sub_80C2294(taskId);
    sub_80C2650(*p1);
    gTasks[taskId].func = sub_80C1BCC;
    CopyWindowToVram(0, 2);
    CopyBgTilemapBufferToVram(3);
}

void sub_80C1BCC(u8 taskId)
{
    u8 r1;
    const struct PokedexOption *r8;
    u16 *p1;
    u16 *p2;
    u16 r2;
    bool8 r3;

    r1 = gTasks[taskId].data[1];
    r8 = sSearchOptions[r1].pokedexList;
    p1 = &gTasks[taskId].data[sSearchOptions[r1].unk4];
    p2 = &gTasks[taskId].data[sSearchOptions[r1].unk5];
    r2 = sSearchOptions[r1].numOptions - 1;
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_PIN);
        sub_80C267C();
        sub_80C21D4(1);
        gTasks[taskId].func = sub_80C16CC;
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
        return;
    }
    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_BOWA);
        sub_80C267C();
        sub_80C21D4(1);
        *p1 = gTasks[taskId].data[14];
        *p2 = gTasks[taskId].data[15];
        gTasks[taskId].func = sub_80C16CC;
        CopyWindowToVram(0, 2);
        CopyBgTilemapBufferToVram(3);
        return;
    }
    r3 = FALSE;
    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        if (*p1 != 0)
        {
            sub_80C2638(*p1);
            (*p1)--;
            sub_80C2650(*p1);
            r3 = TRUE;
        }
        else if (*p2 != 0)
        {
            (*p2)--;
            sub_80C2294(taskId);
            sub_80C2650(*p1);
            r3 = TRUE;
        }
        if (r3)
        {
            PlaySE(SE_SELECT);
            sub_80C2618(r8[*p1 + *p2].description);
            CopyWindowToVram(0, 2);
        }
        return;
    }
    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        if (*p1 < 5 && *p1 < r2)
        {
            sub_80C2638(*p1);
            (*p1)++;
            sub_80C2650(*p1);
            r3 = TRUE;
        }
        else if (r2 > 5 && *p2 < r2 - 5)
        {
            (*p2)++;
            sub_80C2294(taskId);
            sub_80C2650(5);
            r3 = TRUE;
        }
        if (r3)
        {
            PlaySE(SE_SELECT);
            sub_80C2618(r8[*p1 + *p2].description);
            CopyWindowToVram(0, 2);
        }
        return;
    }
}

void sub_80C1D38(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = sub_80C1D70;
}

void sub_80C1D70(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sub_80C152C();
        DestroyTask(taskId);
    }
}

#ifdef NONMATCHING
// This doesn't match because gcc flips the naming of the r7 and r6
// registers. It also does one of the additions backwards.
void sub_80C1D98(u8 a, u8 b, u8 c, u8 d)
{
    u16 i;
    u16* ptr = GetBgTilemapBuffer(3);

    u16* temp;
    for (i = 0; i < d; i++)
    {
        // This addition is supposed to be done in this order; however,
        // gcc will always do it in ptr + (c << 5) order.
        temp = (c << 5) + ptr;
        temp[b + i] %= 0x1000;
        temp[b + i] |= a * 4096;

        temp[b + i + 32] %= 0x1000;
        temp[b + i + 32] |= a * 4096;
    }
}
#else
__attribute__((naked))
void sub_80C1D98(u8 a, u8 b, u8 c, u8 d)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r8\n\
    push {r7}\n\
    adds r4, r3, 0\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    lsls r1, 24\n\
    lsrs r1, 24\n\
    mov r8, r1\n\
    lsls r2, 24\n\
    lsrs r5, r2, 24\n\
    lsls r4, 24\n\
    lsrs r4, 24\n\
    movs r0, 0x3\n\
    bl GetBgTilemapBuffer\n\
    adds r2, r0, 0\n\
    movs r3, 0\n\
    cmp r3, r4\n\
    bcs _080C1DEC\n\
    lsls r0, r5, 6\n\
    adds r7, r0, r2\n\
    ldr r5, =0x00000fff\n\
    lsls r2, r6, 12\n\
_080C1DC8:\n\
    mov r0, r8\n\
    adds r1, r0, r3\n\
    lsls r1, 1\n\
    adds r1, r7\n\
    ldrh r0, [r1]\n\
    ands r0, r5\n\
    orrs r0, r2\n\
    strh r0, [r1]\n\
    adds r1, 0x40\n\
    ldrh r0, [r1]\n\
    ands r0, r5\n\
    orrs r0, r2\n\
    strh r0, [r1]\n\
    adds r0, r3, 0x1\n\
    lsls r0, 16\n\
    lsrs r3, r0, 16\n\
    cmp r3, r4\n\
    bcc _080C1DC8\n\
_080C1DEC:\n\
    pop {r3}\n\
    mov r8, r3\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided\n");
}
#endif

void sub_80C1DFC(u8 a, u8 b, u8 c)
{
    u8 r5 = (b & 1) | ((c & 1) << 1);

    switch (a)
    {
        case 0:
        case 1:
        case 2:
            sub_80C1D98(r5, gUnknown_0856ED30[a].unk4, gUnknown_0856ED30[a].unk5, gUnknown_0856ED30[a].unk6);
            break;
        case 3:
        case 4:
        case 7:
        case 8:
            sub_80C1D98(r5, gUnknown_0856ED48[a - 3].unk4, gUnknown_0856ED48[a - 3].unk5, gUnknown_0856ED48[a - 3].unk6);
            // fall through
        case 5:
        case 6:
            sub_80C1D98(r5, gUnknown_0856ED48[a - 3].unk7, gUnknown_0856ED48[a - 3].unk8, gUnknown_0856ED48[a - 3].unk9);
            break;
        case 10:
            sub_80C1D98(r5, gUnknown_0856ED48[2].unk4, gUnknown_0856ED48[2].unk5, gUnknown_0856ED48[2].unk6);
            break;
        case 9:
            if (!IsNationalPokedexEnabled())
                sub_80C1D98(r5, gUnknown_0856ED48[a - 3].unk4, gUnknown_0856ED48[a - 3].unk5 - 2, gUnknown_0856ED48[a - 3].unk6);
            else
                sub_80C1D98(r5, gUnknown_0856ED48[a - 3].unk4, gUnknown_0856ED48[a - 3].unk5, gUnknown_0856ED48[a - 3].unk6);
            break;
    }
}

void sub_80C1EF4(u8 a)
{
    switch (a)
    {
        case 0:
            sub_80C1DFC(0, 0, 0);
            sub_80C1DFC(1, 1, 0);
            sub_80C1DFC(2, 1, 0);
            sub_80C1DFC(3, 1, 0);
            sub_80C1DFC(4, 1, 0);
            sub_80C1DFC(10, 1, 0);
            sub_80C1DFC(5, 1, 0);
            sub_80C1DFC(6, 1, 0);
            sub_80C1DFC(7, 1, 0);
            sub_80C1DFC(8, 1, 0);
            sub_80C1DFC(9, 1, 0);
            break;
        case 1:
            sub_80C1DFC(0, 1, 0);
            sub_80C1DFC(1, 0, 0);
            sub_80C1DFC(2, 1, 0);
            sub_80C1DFC(3, 1, 1);
            sub_80C1DFC(4, 1, 1);
            sub_80C1DFC(10, 1, 1);
            sub_80C1DFC(5, 1, 1);
            sub_80C1DFC(6, 1, 1);
            sub_80C1DFC(7, 1, 0);
            sub_80C1DFC(8, 1, 0);
            sub_80C1DFC(9, 1, 0);
            break;
        case 2:
            sub_80C1DFC(0, 1, 0);
            sub_80C1DFC(1, 1, 0);
            sub_80C1DFC(2, 0, 0);
            sub_80C1DFC(3, 1, 1);
            sub_80C1DFC(4, 1, 1);
            sub_80C1DFC(10, 1, 1);
            sub_80C1DFC(5, 1, 1);
            sub_80C1DFC(6, 1, 1);
            sub_80C1DFC(7, 1, 1);
            sub_80C1DFC(8, 1, 1);
            sub_80C1DFC(9, 1, 1);
            break;
    }
}

void sub_80C2040(u8 a)
{
    sub_80C1EF4(a);
    sub_80C2618(gUnknown_0856ED30[a].text);
}

void sub_80C2064(u8 a, u8 b)
{
    sub_80C1EF4(a);
    switch (b)
    {
        case 0:
            sub_80C1DFC(3, 0, 0);
            break;
        case 1:
            sub_80C1DFC(4, 0, 0);
            break;
        case 2:
            sub_80C1DFC(10, 0, 0);
            sub_80C1DFC(5, 0, 0);
            break;
        case 3:
            sub_80C1DFC(10, 0, 0);
            sub_80C1DFC(6, 0, 0);
            break;
        case 4:
            sub_80C1DFC(7, 0, 0);
            break;
        case 5:
            sub_80C1DFC(8, 0, 0);
            break;
        case 6:
            sub_80C1DFC(9, 0, 0);
            break;
    }
    sub_80C2618(gUnknown_0856ED48[b].text);
}

void sub_80C20F8(u8 taskId)
{
    u16 var;

    sub_80C12B0(0x28, 0x10, 0x60, 0x50);

    var = gTasks[taskId].data[6] + gTasks[taskId].data[7];
    sub_80C1270(gDexSearchAlphaOptions[var].title, 0x2D, 0x11);

    var = gTasks[taskId].data[8] + gTasks[taskId].data[9];
    sub_80C1270(gDexSearchColorOptions[var].title, 0x2D, 0x21);

    var = gTasks[taskId].data[10] + gTasks[taskId].data[11];
    sub_80C1270(gDexSearchTypeOptions[var].title, 0x2D, 0x31);

    var = gTasks[taskId].data[12] + gTasks[taskId].data[13];
    sub_80C1270(gDexSearchTypeOptions[var].title, 0x5D, 0x31);

    var = gTasks[taskId].data[4] + gTasks[taskId].data[5];
    sub_80C1270(gDexSortOptions[var].title, 0x2D, 0x41);

    if (IsNationalPokedexEnabled())
    {
        var = gTasks[taskId].data[2] + gTasks[taskId].data[3];
        sub_80C1270(gDexModeOptions[var].title, 0x2D, 0x51);
    }
}

void sub_80C21D4(u8 a)
{
    u16 i;
    u16 j;
    u16* ptr = GetBgTilemapBuffer(3);

    if (a == 0)
    {
        *(ptr + 0x11) = 0xC0B;
        for (i = 0x12; i < 0x1F; i++)
            *(ptr + i) = 0x80D;
        for (j = 1; j < 13; j++)
        {
            *(ptr + 0x11 + j * 32) = 0x40A;
            for (i = 0x12; i < 0x1F; i++)
                *(ptr + j * 32 + i) = 2;
        }
        *(ptr + 0x1B1) = 0x40B;
        for (i = 0x12; i < 0x1F; i++)
            *(ptr + 0x1A0 + i) = 0xD;
    }
    else
    {
        for (j = 0; j < 14; j++)
        {
            for (i = 0x11; i < 0x1E; i++)
            {
                *(ptr + j * 32 + i) = 0x4F;
            }
        }
    }
}

void sub_80C2294(u8 taskId)
{
    const struct PokedexOption *r6 = sSearchOptions[gTasks[taskId].data[1]].pokedexList;
    const u16 *r8 = &gTasks[taskId].data[sSearchOptions[gTasks[taskId].data[1]].unk4];
    const u16 *r7 = &gTasks[taskId].data[sSearchOptions[gTasks[taskId].data[1]].unk5];
    u16 i;
    u16 j;

    sub_80C267C();
    for (i = 0, j = *r7; i < 6 && r6[j].title != NULL; i++, j++)
        sub_80C2668(i, r6[j].title);
    sub_80C2618(r6[*r8 + *r7].description);
}

static u8 GetSearchModeSelection(u8 taskId, u8 option)
{
    const u16 *ptr1 = &gTasks[taskId].data[sSearchOptions[option].unk4];
    const u16 *ptr2 = &gTasks[taskId].data[sSearchOptions[option].unk5];
    u16 type = *ptr1 + *ptr2;

    switch (option)
    {
        default:
            return 0;
        case SEARCH_DEX_MODE:
            return sPokedexModes[type];
        case SEARCH_ORDER:
            return sSortOptions[type];
        case SEARCH_NAME:
            if (type == 0)
                return 0xFF;
            else
                return type;
        case SEARCH_COLOR:
            if (type == 0)
                return 0xFF;
            else
                return type - 1;
        case SEARCH_TYPE_1:
        case SEARCH_TYPE_2:
            return gDexSearchTypeIds[type];
    }
}

void sub_80C23B8(u8 taskId)
{
    u16 r3;

    switch (sPokedexView->unk614)
    {
        default:
        case 0:
            r3 = 0;
            break;
        case 1:
            r3 = 1;
            break;
    }
    gTasks[taskId].data[2] = r3;

    switch (sPokedexView->unk618)
    {
        default:
        case 0:
            r3 = 0;
            break;
        case 1:
            r3 = 1;
            break;
        case 2:
            r3 = 2;
            break;
        case 3:
            r3 = 3;
            break;
        case 4:
            r3 = 4;
            break;
        case 5:
            r3 = 5;
            break;
    }
    gTasks[taskId].data[4] = r3;
}

bool8 sub_80C244C(u8 taskId)
{
    u8 val1 = gTasks[taskId].data[1];
    const u16 *ptr = &gTasks[taskId].data[sSearchOptions[val1].unk5];
    u16 val2 = sSearchOptions[val1].numOptions - 1;

    if (val2 > 5 && *ptr != 0)
        return FALSE;
    else
        return TRUE;
}

bool8 sub_80C2494(u8 taskId)
{
    u8 val1 = gTasks[taskId].data[1];
    const u16 *ptr = &gTasks[taskId].data[sSearchOptions[val1].unk5];
    u16 val2 = sSearchOptions[val1].numOptions - 1;

    if (val2 > 5 && *ptr < val2 - 5)
        return FALSE;
    else
        return TRUE;
}

void sub_80C24E0(struct Sprite *sprite)
{
    if (gTasks[sprite->data[0]].func == sub_80C1BCC)
    {
        u8 val;

        if (sprite->data[1] != 0)
        {
            if (sub_80C2494(sprite->data[0]))
                sprite->invisible = TRUE;
            else
                sprite->invisible = FALSE;
        }
        else
        {
            if (sub_80C244C(sprite->data[0]))
                sprite->invisible = TRUE;
            else
                sprite->invisible = FALSE;
        }
        val = sprite->data[2] + sprite->data[1] * 128;
        sprite->pos2.y = gSineTable[val] / 128;
        sprite->data[2] += 8;
    }
    else
    {
        sprite->invisible = TRUE;
    }
}

void sub_80C2594(u8 taskId)
{
    u8 spriteId;

    spriteId = CreateSprite(&sArrowSpriteTemplate, 184, 4, 0);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].data[1] = 0;
    gSprites[spriteId].callback = sub_80C24E0;

    spriteId = CreateSprite(&sArrowSpriteTemplate, 184, 108, 0);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].data[1] = 1;
    gSprites[spriteId].vFlip = TRUE;
    gSprites[spriteId].callback = sub_80C24E0;
}

void sub_80C2618(const u8* str)
{
    sub_80C12B0(8, 0x78, 0xE0, 0x20);
    sub_80C1270(str, 8, 0x79);
}

void sub_80C2638(u32 y)
{
    sub_80C12B0(0x90, y * 16 + 8, 8, 16);
}

void sub_80C2650(u32 left)
{
    sub_80C1270(gText_SelectorArrow, 0x90, left * 16 + 9);
}

void sub_80C2668(u32 left, const u8* str)
{
    sub_80C1270(str, 0x98, left * 16 + 9);
}

void sub_80C267C(void)
{
    sub_80C12B0(0x90, 8, 0x60, 0x60);
}

//PokedexPlus HGSS_Ui Stats Page
#define tMonSpriteId data[4]
static void Task_LoadStatsScreen(u8 taskId)
{
    switch (gMain.state)
    {
    case 0:
    default:
        if (!gPaletteFade.active)
        {
            u16 r2;

            sPokedexView->unk64B = STATS_SCREEN;
            gUnknown_030060B4 = gMain.vblankCallback;
            SetVBlankCallback(NULL);
            r2 = 0;
            if (gTasks[taskId].data[1] != 0)
                r2 += DISPCNT_OBJ_ON;
            if (gTasks[taskId].data[2] != 0)
                r2 |= DISPCNT_BG1_ON;
            ResetOtherVideoRegisters(r2);
            gMain.state = 1;
        }
        break;
    case 1:
        DecompressAndLoadBgGfxUsingHeap(3, gPokedexMenu_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, gPokedexStatsScreen_Tilemap, 0, 0);
        FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
        PutWindowTilemap(WIN_INFO);
        // PutWindowTilemap(WIN_FOOTPRINT);
        // PrintFootprint(WIN_FOOTPRINT, sPokedexListItem->dexNum);
        // CopyWindowToVram(WIN_FOOTPRINT, 2);
		CopyWindowToVram(WIN_INFO, 3);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 2:
        sub_80BFCDC(0xD);
        LoadPokedexBgPalette(sPokedexView->unk64C_1);
        gMain.state++;
        break;
    case 3:
        sPokedexView->typeIconSpriteIds[0] = 0xFF;
        sPokedexView->typeIconSpriteIds[1] = 0xFF;
        CreateTypeIconSprites();
            sPokedexView->splitIconSpriteId = 0xFF; //Physical/Special Split from BE
            LoadCompressedPalette(gMoveTypes_Pal, 0x1D0, 0x60); //Physical/Special Split from BE
            LoadCompressedSpriteSheet(&sSpriteSheet_SplitIcons); //Physical/Special Split from BE
            LoadSpritePalette(&sSpritePal_SplitIcons); //Physical/Special Split from BE
        gMain.state++;
        break;
    case 4:
        sPokedexView->moveSelected = 0;
        sPokedexView->moveMax = 0;
        sPokedexView->numEggMoves = 0;
        sPokedexView->numLevelUpMoves = 0;
        sPokedexView->numTMHMMoves = 0;
        if(CalculateMoves())
            gMain.state++;
        break;
    case 5:
        if (gTasks[taskId].data[1] == 0)
        {
            //Icon
            FreeMonIconPalettes(); //Free space for new pallete
            LoadMonIconPalette(sPokedexListItem->species); //Loads pallete for current mon
            gTasks[taskId].data[4] = CreateMonIcon(sPokedexListItem->species, SpriteCB_MonIcon, 19, 34, 4, 0, TRUE); //Create pokemon sprite
            gSprites[gTasks[taskId].data[4]].oam.priority = 0;
        }
        gMain.state++;
        break;
    case 6:
        gTasks[taskId].data[5] = 0;
        PrintMonStats(taskId, sPokedexListItem->dexNum, sPokedexView->dexMode == DEX_MODE_HOENN ? FALSE : TRUE, sPokedexListItem->owned, 0);
        PrintMonStatsToggle(taskId);
        if (!sPokedexListItem->owned)
            LoadPalette(gPlttBufferUnfaded + 1, 0x31, 0x1E);
        gMain.state++;
        break;
    case 7:
        {
        u32 preservedPalettes = 0;

        if (gTasks[taskId].data[2] != 0)
            preservedPalettes = 0x14; // each bit represents a palette index
        if (gTasks[taskId].data[1] != 0)
            preservedPalettes |= (1 << (gSprites[gTasks[taskId].tMonSpriteId].oam.paletteNum + 16));
        BeginNormalPaletteFade(~preservedPalettes, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(gUnknown_030060B4);
        gMain.state++;
        }
        break;
    case 8:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        HideBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        gMain.state++;
        break;
    case 9:
        if (!gPaletteFade.active)
            gMain.state++;
        break;
    case 10:
        gMain.state++;
        break;
    case 11:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] = 1;
        gTasks[taskId].func = Task_HandleStatsScreenInput;
        gMain.state = 0;
        break;
    }
}
static void FreeStatsScreenWindowAndBgBuffers(void)
{
    void *tilemapBuffer;

    FreeAllWindowBuffers();
    tilemapBuffer = GetBgTilemapBuffer(0);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(1);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(2);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(3);
    if (tilemapBuffer)
        Free(tilemapBuffer);
}
static void Task_HandleStatsScreenInput(u8 taskId)
{
    // gTasks[taskId].data[5] = 0;
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_PC_OFF);
        if (gTasks[taskId].data[5] == 0)
            gTasks[taskId].data[5] = 1;
        else
            gTasks[taskId].data[5] = 0;
        PrintMonStatsToggle(taskId);
        DestroyMoveIcon(taskId);
        PrintMoveNameAndInfo(taskId, TRUE);
    }
    if (gMain.newKeys & B_BUTTON)
    {
        BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
        sPokedexView->unk64E = 0;
        gTasks[taskId].func = Task_SwitchScreensFromStatsScreen;
        PlaySE(SE_PC_OFF);
        return;
    }
    if (gMain.newKeys & SELECT_BUTTON)
        if (TryToChangeForm(taskId, Task_SwitchScreensFromStatsScreen))
            return;

    //Change moves
    if (gMain.newAndRepeatedKeys & DPAD_UP && sPokedexView->moveSelected > 0)
    {
        sPokedexView->moveSelected -= 1;
        PlaySE(SE_SELECT);
        DestroyMoveIcon(taskId);
        PrintMoveNameAndInfo(taskId, FALSE);
    }
    if (gMain.newAndRepeatedKeys & DPAD_DOWN && sPokedexView->moveSelected < sPokedexView->moveMax -1 )
    {
        sPokedexView->moveSelected = sPokedexView->moveSelected + 1;
        PlaySE(SE_SELECT);
        DestroyMoveIcon(taskId);
        PrintMoveNameAndInfo(taskId, FALSE);
    }

    //Switch screens
    if ((gMain.newKeys & DPAD_LEFT || (gMain.newKeys & L_BUTTON && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)))
    {
        sPokedexView->selectedScreen = INFO_SCREEN;
        BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
        sPokedexView->unk64E = 1;
        gTasks[taskId].func = Task_SwitchScreensFromStatsScreen;
        PlaySE(SE_PIN);
    }

    if ((gMain.newKeys & DPAD_RIGHT || (gMain.newKeys & R_BUTTON && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)))
    {
        if (!sPokedexListItem->owned)
            PlaySE(SE_HAZURE);
        else
        {
            sPokedexView->selectedScreen = EVO_SCREEN;
            BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
            sPokedexView->unk64E = 3;
            gTasks[taskId].func = Task_SwitchScreensFromStatsScreen;
            PlaySE(SE_PIN);
        }
    }

}
#define ITEM_TAG 0xFDF3
static void DestroyMoveIcon(u8 taskId)
{
    FreeSpriteTilesByTag(ITEM_TAG);                         //Destroy item icon
    FreeSpritePaletteByTag(ITEM_TAG);                       //Destroy item icon
    FreeSpriteOamMatrix(&gSprites[gTasks[taskId].data[3]]); //Destroy item icon
    DestroySprite(&gSprites[gTasks[taskId].data[3]]);       //Destroy item icon
}

void DestroyWildHeldItemIcons(u8 taskid) {
    // Destroy item icons, if they are loaded
    if (sPokedexView->item1_icon)
    {
        FreeSpriteTilesByTag(ITEM_TAG+1);
        FreeSpritePaletteByTag(ITEM_TAG+1);
        FreeSpriteOamMatrix(&gSprites[sPokedexView->item1_icon]);
        DestroySprite(&gSprites[sPokedexView->item1_icon]);
        sPokedexView->item1_icon = 0; // Mark as not loaded
    }
    if (sPokedexView->item2_icon)
    {
        FreeSpriteTilesByTag(ITEM_TAG+2);
        FreeSpritePaletteByTag(ITEM_TAG+2);
        FreeSpriteOamMatrix(&gSprites[sPokedexView->item2_icon]);
        DestroySprite(&gSprites[sPokedexView->item2_icon]);
        sPokedexView->item2_icon = 0; // Mark as not loaded
    }
}

u16 GetPreSpecies(u16 species) {
    u16 first_in_chain = GetEggSpecies(species);
    if (first_in_chain == species)
        return species;

    switch(first_in_chain) { // at this point, first_in_chain is NOT species
        case SPECIES_AZURILL:
            return SPECIES_MARILL;
        case SPECIES_BUDEW:
            return SPECIES_ROSELIA;
        case SPECIES_HAPPINY:
            return SPECIES_CHANSEY;
        case SPECIES_MIMEJR:
            if (species != SPECIES_MR_MIME) // Galarian Mr. Mime / Mr. Rime
                return SPECIES_GALAR_MRMIME;
            return SPECIES_MR_MIME;
        case SPECIES_WYNAUT:
        case SPECIES_MUNCHLAX:
        case SPECIES_BONSLY:
        case SPECIES_CHINGLING:
        case SPECIES_MANTYKE:
            return species;   // Wobbuffet, Snorlax, and so on
        default:
            return first_in_chain;
    }
}

static bool8 CalculateMoves(void)
{
    //Moves
    u16 species = sPokedexListItem->species;
    u8 numEggMoves = GetEggMovesSpecies(GetPreSpecies(species), sStatsMovesEgg);
    u8 numLevelUpMoves = GetLevelUpMovesBySpecies(species, sStatsMovesLevelUp);
    u8 numTMHMMoves;
    u8 numTutorMoves = 0;
    u16 movestotal;
    u8 i,j;

    // sTutorLearnsets
    for (i=0; i<TUTOR_MOVE_COUNT; i++)
    {
        if (CanLearnTutorMove(species, i)) //if (sTutorLearnsets[species] & (1 << i))
        {
            sStatsMovesTutor[numTutorMoves] = gTutorMoves[i];
            numTutorMoves++;
        }
    }

    //TMHM moves
    for (j = 0; j < NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES; j++)
    {
        if(CanSpeciesLearnTMHM(species, j))
        {
            sStatsMovesTMHM[numTMHMMoves] = ItemIdToBattleMoveId(ITEM_TM01_FOCUS_PUNCH + j);
            sStatsMovesTMHM_ID[numTMHMMoves] = (ITEM_TM01_FOCUS_PUNCH + j);
            numTMHMMoves++;
        }
    }

    movestotal = numEggMoves + numLevelUpMoves + numTMHMMoves + numTutorMoves;
    sPokedexView->moveMax = movestotal;

    sPokedexView->numEggMoves = numEggMoves;
    sPokedexView->numLevelUpMoves = numLevelUpMoves;
    sPokedexView->numTMHMMoves = numTMHMMoves;
    sPokedexView->numTutorMoves = numTutorMoves;

    return TRUE;
}
static void PrintMoveNameAndInfo(u8 taskId, bool8 toggle)
{
    u8 numEggMoves      = sPokedexView->numEggMoves;
    u8 numLevelUpMoves  = sPokedexView->numLevelUpMoves;
    u8 numTMHMMoves     = sPokedexView->numTMHMMoves;
    u8 numTutorMoves    = sPokedexView->numTutorMoves;

    u8 selected = sPokedexView->moveSelected;
    u8 total = sPokedexView->moveMax;

    u16 move;
    u16 item;

    u8 moves_x = 101;
    u8 moves_y = 19;

    u8 level = 0;

    u16 species = sPokedexListItem->species;

    //Contest
    u8 contest_i, contest_effectValue, contest_appeal, contest_jam;

    //Clear space
    if (!toggle)
        FillWindowPixelRect(0, PIXEL_FILL(0), moves_x-1, moves_y, 139, 78);
    else
        FillWindowPixelRect(0, PIXEL_FILL(0), moves_x-1, moves_y+29, 139, 55);

    //Calculate and retrieve correct move from the arrays
    if (selected < numEggMoves)
    {
        move = sStatsMovesEgg[sPokedexView->moveSelected];
        StringCopy(gStringVar3, gMoveNames[move]);
        StringCopy(gStringVar4, gMoveDescriptionPointers[(move - 1)]);
        PrintInfoScreenTextSmall(gText_EggNickname, moves_x + 113, moves_y + 9);
        item = ITEM_LUCKY_EGG;
    }
    else if (selected < (numEggMoves + numLevelUpMoves))
    {
        move = sStatsMovesLevelUp[sPokedexView->moveSelected - numEggMoves];
        StringCopy(gStringVar3, gMoveNames[move]);
        StringCopy(gStringVar4, gMoveDescriptionPointers[(move - 1)]);
        //Calculate level of the move
        while (((gLevelUpLearnsets[species][(selected-numEggMoves)] & LEVEL_UP_MOVE_LV) != (level << 9)) && level < 0xFF)
        {
            level++;
            if (gLevelUpLearnsets[species][(selected-numEggMoves)] == LEVEL_UP_END)
                level = 0xFF;
        }
        if (level == 0) // movimiento aprendido al evolucionar
        {
            u8 stringOnce[] = _("ONCE");
            u8 stringEvol[] = _("EVOL");
            StringCopy(gStringVar1, stringOnce);
            PrintInfoScreenTextSmall(gStringVar1, moves_x + 113, moves_y + 3);
            StringCopy(gStringVar1, stringEvol);
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, level, STR_CONV_MODE_LEFT_ALIGN, 3); //Move learn lvl
            PrintInfoScreenTextSmall(gText_Stats_MoveLevel, moves_x + 113, moves_y + 3); //Level text
        }
        PrintInfoScreenTextSmall(gStringVar1, moves_x + 113, moves_y + 14); //Print level
        item = ITEM_EXP_SHARE;
    }
    else if (selected < (numEggMoves + numLevelUpMoves + numTMHMMoves))
    {
        move = sStatsMovesTMHM[sPokedexView->moveSelected - numEggMoves - numLevelUpMoves];
        StringCopy(gStringVar3, gMoveNames[move]);
        StringCopy(gStringVar4, gMoveDescriptionPointers[(move - 1)]);
        CopyItemName(sStatsMovesTMHM_ID[(selected-numEggMoves-numLevelUpMoves)], gStringVar1); //TM name
        PrintInfoScreenTextSmall(gStringVar1, moves_x + 113, moves_y + 9);
        item = sStatsMovesTMHM_ID[(selected-numEggMoves-numLevelUpMoves)];
    }
    else if (selected < (numEggMoves + numLevelUpMoves + numTMHMMoves + numTutorMoves))
    {
        u8 stringTutor[] = _("TUTOR");
        move = sStatsMovesTutor[sPokedexView->moveSelected - numEggMoves - numLevelUpMoves - numTMHMMoves];
        StringCopy(gStringVar3, gMoveNames[move]);
        StringCopy(gStringVar4, gMoveDescriptionPointers[(move - 1)]);
        StringCopy(gStringVar1, stringTutor);
        PrintInfoScreenTextSmall(gStringVar1, moves_x + 111, moves_y + 9);
        item = ITEM_TEACHY_TV;
    }
    else
    {
        StringCopy(gStringVar4, gText_CommunicationError);
        item = ITEM_MASTER_BALL;
    }


    //Move name and description
    StringCopyPadded(gStringVar3, gStringVar3, CHAR_SPACE, 20);
    PrintInfoScreenTextSmall(gStringVar3, moves_x, moves_y + 17); //Name
    if (gTasks[taskId].data[5] == 0)
        PrintInfoScreenTextSmall(gStringVar4, moves_x, moves_y + 34);
    else
        PrintInfoScreenTextSmall(gContestEffectDescriptionPointers[gContestMoves[move].effect], moves_x, moves_y + 34);


    //Egg/TM/Level/Tutor Item Icon
    gTasks[taskId].data[3] = AddItemIconSprite(ITEM_TAG, ITEM_TAG, item);
    gSprites[gTasks[taskId].data[3]].pos2.x = 203;
    gSprites[gTasks[taskId].data[3]].pos2.y = 39;
    gSprites[gTasks[taskId].data[3]].oam.priority = 0;

    //Moves selected from move max
    ConvertIntToDecimalStringN(gStringVar1, (selected+1), STR_CONV_MODE_RIGHT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, total, STR_CONV_MODE_RIGHT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar1, gText_Stats_MoveSelectedMax);
    PrintInfoScreenTextSmallWhite(gStringVar1, moves_x-1, moves_y+1);

    if (gTasks[taskId].data[5] == 0)
    {
        //Power
        PrintInfoScreenTextSmall(gText_Power,  moves_x + 3, moves_y + 64);
        if (gBattleMoves[move].power < 2)
            StringCopy(gStringVar1, gText_ThreeDashes);
        else
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move].power, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(gStringVar1, moves_x + 48, moves_y + 64);
		//Physical/Special Split from BE
            DestroySplitIcon();
            ShowSplitIcon(GetBattleMoveSplit(move));
        //Accuracy
        PrintInfoScreenTextSmall(gText_Accuracy2,  moves_x + 69, moves_y + 64);
        if (gBattleMoves[move].accuracy == 0)
            StringCopy(gStringVar1, gText_ThreeDashes);
        else
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move].accuracy, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(gStringVar1,  moves_x + 117, moves_y + 64);
    }
    else
    {
        //Appeal
        PrintInfoScreenTextSmall(gText_Appeal,  moves_x + 3, moves_y + 64);
        contest_appeal = 0;
        contest_effectValue = gContestEffects[gContestMoves[move].effect].appeal;
        if (contest_effectValue != 0xFF)
            contest_effectValue /= 10;
        for (contest_i = 0; contest_i < 8; contest_i++)
        {
            if (contest_effectValue != 0xFF && contest_i < contest_effectValue)
                contest_appeal += 1;
        }
        ConvertIntToDecimalStringN(gStringVar1, contest_appeal, STR_CONV_MODE_RIGHT_ALIGN, 1);
        StringCopy(gStringVar2, gText_PlusSymbol);
        StringAppend(gStringVar2, gStringVar1);
        PrintInfoScreenTextSmall(gStringVar2, moves_x + 48, moves_y + 64);

        //Jam
        PrintInfoScreenTextSmall(gText_Jam,  moves_x + 69, moves_y + 64);
        contest_jam = 0;
        contest_effectValue = gContestEffects[gContestMoves[move].effect].jam;
        if (contest_effectValue != 0xFF)
            contest_effectValue /= 10;
        for (contest_i = 0; contest_i < 8; contest_i++)
        {
            if (contest_effectValue != 0xFF && contest_i < contest_effectValue)
                contest_jam += 1;
        }
        ConvertIntToDecimalStringN(gStringVar1, contest_jam, STR_CONV_MODE_RIGHT_ALIGN, 1);
        StringCopy(gStringVar2, gText_Stats_Minus);
        StringAppend(gStringVar2, gStringVar1);
        PrintInfoScreenTextSmall(gStringVar2,  moves_x + 122, moves_y + 64);
    }

    //Draw move type icon
    if (gTasks[taskId].data[5] == 0)
    {
        SetTypeIconPosAndPal(gBattleMoves[move].type, moves_x + 50, moves_y+1, 0);
        SetSpriteInvisibility(1, TRUE);
    }
    else
    {
        SetTypeIconPosAndPal(NUMBER_OF_MON_TYPES + gContestMoves[move].contestCategory, moves_x + 50, moves_y+1, 1);
        SetSpriteInvisibility(0, TRUE);
    }


    //Physical/Special Split from BE
     DestroySplitIcon();
     if (gTasks[taskId].data[5] == 0)
  ShowSplitIcon(GetBattleMoveSplit(move));
}
// u32 value is re-used, but passed as a bool that's TRUE if national dex is enabled
static void PrintMonStats(u8 taskId, u32 num, u32 value, u32 owned, u32 newEntry) //HGSS_Ui
{
    u8 str[16];
    u8 str2[32];
    u8 strEV[25];
    u16 species = sPokedexListItem->species;
    u16 natNum;
    u8 evVal;
    const u8 *category;
    const u8 *description;
    const u8 *strEVtype;

    u8 gender_x, gender_y;

    u8 base_i = 0;
    u8 base_offset = 11;
    u8 base_x = 8;
    u8 base_y = 52;

    //Name
    PrintInfoScreenTextSmall(gSpeciesNames[species], 38, 16);

    //Number
    if (value == 0)
        value = NationalToHoennOrder(num);
    else
        value = num;
    ConvertIntToDecimalStringN(StringCopy(str, gText_NumberClear01), value, STR_CONV_MODE_LEADING_ZEROS, 3);
    PrintInfoScreenTextSmall(str, 38, 26);

    //Gender ratio //MON_GENDERLESS == 0xFF
    gender_x = 38;
    gender_y = 36;
    switch (gBaseStats[species].genderRatio)
    {
    case 0:
        PrintInfoScreenTextSmall(gText_Stats_Gender_0, gender_x, gender_y);
        break;
    case 31:
        PrintInfoScreenTextSmall(gText_Stats_Gender_12_5, gender_x, gender_y);
        break;
    case 63:
        PrintInfoScreenTextSmall(gText_Stats_Gender_25, gender_x, gender_y);
        break;
    case 127:
        PrintInfoScreenTextSmall(gText_Stats_Gender_50, gender_x, gender_y);
        break;
    case 191:
        PrintInfoScreenTextSmall(gText_Stats_Gender_75, gender_x, gender_y);
        break;
    case 223:
        PrintInfoScreenTextSmall(gText_Stats_Gender_87_5, gender_x, gender_y);
        break;
    case 254:
        PrintInfoScreenTextSmall(gText_Stats_Gender_100, gender_x, gender_y);
        break;
    default:
        PrintInfoScreenTextSmall(gText_ThreeDashes, gender_x, gender_y);
        break;
    }


    //Moves
    PrintMoveNameAndInfo(taskId, FALSE);

}
static void PrintMonStatsToggle(u8 taskId)
{
    u8 base_x = 8;
    u8 base_x_offset = 70;
    u8 base_offset = 11;
    u8 base_x_first_row = 23;
    u8 base_x_second_row = 43;
    u8 base_i = 0;
    u8 base_y = 52;
    u32 align_x;
    u8 total_x = 93;
    u16 species = sPokedexListItem->species;
    u8 strEV[25];
    u8 strBase[14];
    u8 abilities_x = 101;
    u8 abilities_y = 99;
    u8 ability0;

    //Clear old text
    FillWindowPixelRect(0, PIXEL_FILL(0), base_x, base_y, 90, 100); //bottom stats
    FillWindowPixelRect(0, PIXEL_FILL(0), abilities_x, 99, 130, 58); //abilities

	DestroyWildHeldItemIcons(taskId);

    //Base stats
    if (gTasks[taskId].data[5] == 0)
    {
        PrintInfoScreenTextSmall(gText_Stats_HP, base_x, base_y + base_offset*base_i);
        ConvertIntToDecimalStringN(strBase, gBaseStats[species].baseHP, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(strBase, base_x+base_x_first_row, base_y + base_offset*base_i);

        PrintInfoScreenTextSmall(gText_Stats_Speed, base_x+base_x_second_row, base_y + base_offset*base_i);
        ConvertIntToDecimalStringN(strBase, gBaseStats[species].baseSpeed, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(strBase, base_x+base_x_offset, base_y + base_offset*base_i);

        base_i++;
        PrintInfoScreenTextSmall(gText_Stats_Attack, base_x, base_y + base_offset*base_i);
        ConvertIntToDecimalStringN(strBase, gBaseStats[species].baseAttack, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(strBase, base_x+base_x_first_row, base_y + base_offset*base_i);

        PrintInfoScreenTextSmall(gText_Stats_SpAtk, base_x+base_x_second_row, base_y + base_offset*base_i);
        ConvertIntToDecimalStringN(strBase, gBaseStats[species].baseSpAttack, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(strBase, base_x+base_x_offset, base_y + base_offset*base_i);

        base_i++;
        PrintInfoScreenTextSmall(gText_Stats_Defense, base_x, base_y + base_offset*base_i);
        ConvertIntToDecimalStringN(strBase, gBaseStats[species].baseDefense, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(strBase, base_x+base_x_first_row, base_y + base_offset*base_i);

        PrintInfoScreenTextSmall(gText_Stats_SpDef, base_x+base_x_second_row, base_y + base_offset*base_i);
        ConvertIntToDecimalStringN(strBase, gBaseStats[species].baseSpDefense, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(strBase, base_x+base_x_offset, base_y + base_offset*base_i);
        base_i++;
    }
    else //EV increses
    {
        PrintInfoScreenTextSmall(gText_Stats_EVHP, base_x, base_y + base_offset*base_i);
        ConvertIntToDecimalStringN(strBase, gBaseStats[species].evYield_HP, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(strBase, base_x+base_x_first_row, base_y + base_offset*base_i);

        PrintInfoScreenTextSmall(gText_Stats_EVSpeed, base_x+base_x_second_row, base_y + base_offset*base_i);
        ConvertIntToDecimalStringN(strBase, gBaseStats[species].evYield_Speed, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(strBase, base_x+base_x_offset, base_y + base_offset*base_i);

        base_i++;
        PrintInfoScreenTextSmall(gText_Stats_EVAttack, base_x, base_y + base_offset*base_i);
        ConvertIntToDecimalStringN(strBase, gBaseStats[species].evYield_Attack, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(strBase, base_x+base_x_first_row, base_y + base_offset*base_i);

        PrintInfoScreenTextSmall(gText_Stats_EVSpAtk, base_x+base_x_second_row, base_y + base_offset*base_i);
        ConvertIntToDecimalStringN(strBase, gBaseStats[species].evYield_SpAttack, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(strBase, base_x+base_x_offset, base_y + base_offset*base_i);

        base_i++;
        PrintInfoScreenTextSmall(gText_Stats_EVDefense, base_x, base_y + base_offset*base_i);
        ConvertIntToDecimalStringN(strBase, gBaseStats[species].evYield_Defense, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(strBase, base_x+base_x_first_row, base_y + base_offset*base_i);

        PrintInfoScreenTextSmall(gText_Stats_EVSpDef, base_x+base_x_second_row, base_y + base_offset*base_i);
        ConvertIntToDecimalStringN(strBase, gBaseStats[species].evYield_SpDefense, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(strBase, base_x+base_x_offset, base_y + base_offset*base_i);
        base_i++;
    }


    base_y = 86;
    base_i = 0;

    if (gTasks[taskId].data[5] == 0)
    {
        //Exp
        PrintInfoScreenTextSmall(gText_Stats_Exp, base_x, base_y + base_offset*base_i);
        ConvertIntToDecimalStringN(gStringVar1, gBaseStats[species].expYield, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(gStringVar1, base_x + base_x_offset, base_y + base_offset*base_i);
        base_i++;

        //friendship
        PrintInfoScreenTextSmall(gText_Stats_Friendship, base_x, base_y + base_offset*base_i);
        ConvertIntToDecimalStringN(strEV, gBaseStats[species].friendship, STR_CONV_MODE_RIGHT_ALIGN, 3);
        align_x = GetStringRightAlignXOffset(0, strEV, total_x);
        PrintInfoScreenTextSmall(strEV, align_x, base_y + base_offset*base_i);
        base_i++;

        //Egg cycles
        if (gBaseStats[species].eggGroup1 == EGG_GROUP_UNDISCOVERED || gBaseStats[species].eggGroup2 == EGG_GROUP_UNDISCOVERED)
        {
            PrintInfoScreenTextSmall(gText_Stats_EggCycles, base_x, base_y + base_offset*base_i);
            PrintInfoScreenTextSmall(gText_ThreeDashes, 78, base_y + base_offset*base_i);
        }
        else
        {
            PrintInfoScreenTextSmall(gText_Stats_EggCycles, base_x, base_y + base_offset*base_i);
            ConvertIntToDecimalStringN(strEV, gBaseStats[species].eggCycles, STR_CONV_MODE_RIGHT_ALIGN, 2);
            align_x = GetStringRightAlignXOffset(0, strEV, total_x);
            PrintInfoScreenTextSmall(strEV, align_x, base_y + base_offset*base_i);
        }
        base_i++;

        //Catch rate
        PrintInfoScreenTextSmall(gText_Stats_Catch, base_x, base_y + base_offset*base_i);
        ConvertIntToDecimalStringN(gStringVar1, gBaseStats[species].catchRate, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintInfoScreenTextSmall(gStringVar1, base_x + base_x_offset, base_y + base_offset*base_i);
        base_i++;

        //Growth rate
        PrintInfoScreenTextSmall(gText_Stats_Growthrate, base_x, base_y + base_offset*base_i);
        switch (gBaseStats[species].growthRate)
        {
        case GROWTH_MEDIUM_FAST:
            StringCopy(strEV, gText_Stats_MEDIUM_FAST);
            break;
        case GROWTH_ERRATIC:
            StringCopy(strEV, gText_Stats_ERRATIC);
            break;
        case GROWTH_FLUCTUATING:
            StringCopy(strEV, gText_Stats_FLUCTUATING);
            break;
        case GROWTH_MEDIUM_SLOW:
            StringCopy(strEV, gText_Stats_MEDIUM_SLOW);
            break;
        case GROWTH_FAST:
            StringCopy(strEV, gText_Stats_FAST);
            break;
        case GROWTH_SLOW:
            StringCopy(strEV, gText_Stats_SLOW);
            break;
        default:
            break;
        }
        align_x = GetStringRightAlignXOffset(0, strEV, total_x);
        PrintInfoScreenTextSmall(strEV, align_x, base_y + base_offset*base_i);
    }
    else
    {
        base_i = 0;
        //Egg group 1
        PrintInfoScreenTextSmall(gText_Stats_eggGroup_g1, base_x, base_y + base_offset*base_i);
        switch (gBaseStats[species].eggGroup1)
        {
        case EGG_GROUP_MONSTER     :
            StringCopy(gStringVar1, gText_Stats_eggGroup_MONSTER);
            break;
        case EGG_GROUP_WATER_1     :
            StringCopy(gStringVar1, gText_Stats_eggGroup_WATER_1);
            break;
        case EGG_GROUP_BUG         :
            StringCopy(gStringVar1, gText_Stats_eggGroup_BUG);
            break;
        case EGG_GROUP_FLYING      :
            StringCopy(gStringVar1, gText_Stats_eggGroup_FLYING);
            break;
        case EGG_GROUP_FIELD       :
            StringCopy(gStringVar1, gText_Stats_eggGroup_FIELD);
            break;
        case EGG_GROUP_FAIRY       :
            StringCopy(gStringVar1, gText_Stats_eggGroup_FAIRY);
            break;
        case EGG_GROUP_GRASS       :
            StringCopy(gStringVar1, gText_Stats_eggGroup_GRASS);
            break;
        case EGG_GROUP_HUMAN_LIKE  :
            StringCopy(gStringVar1, gText_Stats_eggGroup_HUMAN_LIKE);
            break;
        case EGG_GROUP_WATER_3     :
            StringCopy(gStringVar1, gText_Stats_eggGroup_WATER_3);
            break;
        case EGG_GROUP_MINERAL     :
            StringCopy(gStringVar1, gText_Stats_eggGroup_MINERAL);
            break;
        case EGG_GROUP_AMORPHOUS   :
            StringCopy(gStringVar1, gText_Stats_eggGroup_AMORPHOUS);
            break;
        case EGG_GROUP_WATER_2     :
            StringCopy(gStringVar1, gText_Stats_eggGroup_WATER_2);
            break;
        case EGG_GROUP_DITTO       :
            StringCopy(gStringVar1, gText_Stats_eggGroup_DITTO);
            break;
        case EGG_GROUP_DRAGON      :
            StringCopy(gStringVar1, gText_Stats_eggGroup_DRAGON);
            break;
        case EGG_GROUP_UNDISCOVERED:
            StringCopy(gStringVar1, gText_Stats_eggGroup_UNDISCOVERED);
            break;
        }
        PrintInfoScreenTextSmall(gStringVar1, base_x + 37, base_y + base_offset*base_i);
        base_i++;

        //Egg group 2
        if (gBaseStats[species].eggGroup2 != gBaseStats[species].eggGroup1) {
            PrintInfoScreenTextSmall(gText_Stats_eggGroup_g2, base_x, base_y + base_offset*base_i);
            switch (gBaseStats[species].eggGroup2)
            {
            case EGG_GROUP_MONSTER     :
                StringCopy(gStringVar1, gText_Stats_eggGroup_MONSTER);
                break;
            case EGG_GROUP_WATER_1     :
                StringCopy(gStringVar1, gText_Stats_eggGroup_WATER_1);
                break;
            case EGG_GROUP_BUG         :
                StringCopy(gStringVar1, gText_Stats_eggGroup_BUG);
                break;
            case EGG_GROUP_FLYING      :
                StringCopy(gStringVar1, gText_Stats_eggGroup_FLYING);
                break;
            case EGG_GROUP_FIELD       :
                StringCopy(gStringVar1, gText_Stats_eggGroup_FIELD);
                break;
            case EGG_GROUP_FAIRY       :
                StringCopy(gStringVar1, gText_Stats_eggGroup_FAIRY);
                break;
            case EGG_GROUP_GRASS       :
                StringCopy(gStringVar1, gText_Stats_eggGroup_GRASS);
                break;
            case EGG_GROUP_HUMAN_LIKE  :
                StringCopy(gStringVar1, gText_Stats_eggGroup_HUMAN_LIKE);
                break;
            case EGG_GROUP_WATER_3     :
                StringCopy(gStringVar1, gText_Stats_eggGroup_WATER_3);
                break;
            case EGG_GROUP_MINERAL     :
                StringCopy(gStringVar1, gText_Stats_eggGroup_MINERAL);
                break;
            case EGG_GROUP_AMORPHOUS   :
                StringCopy(gStringVar1, gText_Stats_eggGroup_AMORPHOUS);
                break;
            case EGG_GROUP_WATER_2     :
                StringCopy(gStringVar1, gText_Stats_eggGroup_WATER_2);
                break;
            case EGG_GROUP_DITTO       :
                StringCopy(gStringVar1, gText_Stats_eggGroup_DITTO);
                break;
            case EGG_GROUP_DRAGON      :
                StringCopy(gStringVar1, gText_Stats_eggGroup_DRAGON);
                break;
            case EGG_GROUP_UNDISCOVERED:
                StringCopy(gStringVar1, gText_Stats_eggGroup_UNDISCOVERED);
                break;
            }
            PrintInfoScreenTextSmall(gStringVar1, base_x + 37, base_y + base_offset*base_i);
        }
    }



    //Abilitie(s)
    if (gTasks[taskId].data[5] == 0)
    {    
        ability0 = gBaseStats[species].abilities[0];
        PrintInfoScreenTextSmallWhite(gAbilityNames[ability0], abilities_x, abilities_y);
        PrintInfoScreenTextSmall(gAbilityDescriptionPointers[ability0], abilities_x, abilities_y + 14);

        if (gBaseStats[species].abilities[1] != ABILITY_NONE && gBaseStats[species].abilities[1] != gBaseStats[species].abilities[0])
        {
            PrintInfoScreenTextSmallWhite(gAbilityNames[gBaseStats[species].abilities[1]], abilities_x, abilities_y + 30);
            PrintInfoScreenTextSmall(gAbilityDescriptionPointers[gBaseStats[species].abilities[1]], abilities_x, abilities_y + 44);
        }
    // }else{ //For PokemonExpansion
        // ability0 = gBaseStats[species].abilityHidden;
        // PrintInfoScreenTextSmallWhite(gAbilityNames[ability0], abilities_x, abilities_y);
        // PrintInfoScreenTextSmall(gAbilityDescriptionPointers[ability0], abilities_x, abilities_y + 14);
    }
	else
    {
        u8 item1 = gBaseStats[species].item1;
        u8 item2 = gBaseStats[species].item2;
        u8 ico1;
        u8 ico2;
        u8 n_items = (item1 != ITEM_NONE) + (item2 != ITEM_NONE);
        u8 five_pc[] = _("Wild held item: 5%");
        u8 fifty_pc[] = _("Wild held item: 50%");
        u8 hundred_pc[] = _("Wild held item: 100%");

        if (n_items)
        {
            if (item1 == item2) // Un solo item con 100% de salir
            {
                StringCopy(gStringVar1, hundred_pc);
                CopyItemName(item1, gStringVar2);
                PrintInfoScreenTextSmallWhite(gStringVar1, abilities_x, abilities_y);
                PrintInfoScreenTextSmall(gStringVar2, abilities_x, abilities_y + 14);

                ico1 = AddItemIconSprite(ITEM_TAG+1, ITEM_TAG+1, item1);
                gSprites[ico1].pos2.x = abilities_x + 127;
                gSprites[ico1].pos2.y = abilities_y + 19;
            }
            else if (item1 == ITEM_NONE) // Un solo item con 5% de salir
            {
                StringCopy(gStringVar1, five_pc);
                CopyItemName(item2, gStringVar2);
                PrintInfoScreenTextSmallWhite(gStringVar1, abilities_x, abilities_y);
                PrintInfoScreenTextSmall(gStringVar2, abilities_x, abilities_y + 14);

                ico1 = AddItemIconSprite(ITEM_TAG+1, ITEM_TAG+1, item2);
                gSprites[ico1].pos2.x = abilities_x + 127;
                gSprites[ico1].pos2.y = abilities_y + 19;
            }
            else // Hay un item con 50% de salir, y puede que otro
 {
                StringCopy(gStringVar1, fifty_pc);
                CopyItemName(item1, gStringVar2);
                PrintInfoScreenTextSmallWhite(gStringVar1, abilities_x, abilities_y);
                PrintInfoScreenTextSmall(gStringVar2, abilities_x, abilities_y + 14);

                ico1 = AddItemIconSprite(ITEM_TAG+1, ITEM_TAG+1, item1);
                gSprites[ico1].pos2.x = abilities_x + 127;
                gSprites[ico1].pos2.y = abilities_y + 19;
                
                if (item2 != ITEM_NONE) // dos items, falta dibujar el de 5%
                {
                    StringCopy(gStringVar1, five_pc);
                    CopyItemName(item2, gStringVar2);
                    PrintInfoScreenTextSmallWhite(gStringVar1, abilities_x, abilities_y + 30);
                    PrintInfoScreenTextSmall(gStringVar2, abilities_x, abilities_y + 44);

                    ico2 = AddItemIconSprite(ITEM_TAG+2, ITEM_TAG+2, item2);
                    gSprites[ico2].pos2.x = abilities_x + 127;
                    gSprites[ico2].pos2.y = abilities_y + 19 + 30;
                }
            }
        }

        sPokedexView->item1_icon = ico1;
        sPokedexView->item2_icon = ico2;
    }
}
static void Task_SwitchScreensFromStatsScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeSpriteTilesByTag(ITEM_TAG);                         //Destroy item icon
        FreeSpritePaletteByTag(ITEM_TAG);                       //Destroy item icon
        FreeSpriteOamMatrix(&gSprites[gTasks[taskId].data[3]]); //Destroy item icon
        DestroySprite(&gSprites[gTasks[taskId].data[3]]);       //Destroy item icon
        FreeMonIconPalettes();                                          //Destroy pokemon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy pokemon icon sprite
		DestroyWildHeldItemIcons(taskId);

        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        switch (sPokedexView->unk64E)
        {
        case 1:
            gTasks[taskId].func = LoadAreaScreen;
            break;
        case 2:
            gTasks[taskId].func = LoadCryScreen;
            break;
        case 11:
            gTasks[taskId].func = Task_LoadStatsScreen;
            break;
		case 3:
            gTasks[taskId].func = Task_LoadEvolutionScreen;
            break;
        default:
            gTasks[taskId].func = LoadInfoScreen;
            break;
        }
    }
}
static void Task_ExitStatsScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeSpriteTilesByTag(ITEM_TAG);                         //Destroy item icon
        FreeSpritePaletteByTag(ITEM_TAG);                       //Destroy item icon
        FreeSpriteOamMatrix(&gSprites[gTasks[taskId].data[3]]); //Destroy item icon
        DestroySprite(&gSprites[gTasks[taskId].data[3]]);       //Destroy item icon
        FreeMonIconPalettes();                                          //Destroy pokemon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy pokemon icon sprite
		DestroyWildHeldItemIcons(taskId);

        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        FreeWindowAndBgBuffers_();
        DestroyTask(taskId);
    }
}

//Physical/Special Split from BE
static u8 ShowSplitIcon(u32 split)
{
    if (sPokedexView->splitIconSpriteId == 0xFF)
        sPokedexView->splitIconSpriteId = CreateSprite(&sSpriteTemplate_SplitIcons, 139, 90, 0);

    gSprites[sPokedexView->splitIconSpriteId].invisible = FALSE;
    StartSpriteAnim(&gSprites[sPokedexView->splitIconSpriteId], split);
    return sPokedexView->splitIconSpriteId;
}

static void DestroySplitIcon(void)
{
    if (sPokedexView->splitIconSpriteId != 0xFF)
        DestroySprite(&gSprites[sPokedexView->splitIconSpriteId]);
    sPokedexView->splitIconSpriteId = 0xFF;
}

//PokedexPlus HGSS_Ui Evolution Page
static void Task_LoadEvolutionScreen(u8 taskId)
{
    switch (gMain.state)
    {
    case 0:
    default:
        if (!gPaletteFade.active)
        {
            u16 r2;

            sPokedexView->unk64A = EVO_SCREEN;
            gUnknown_030060B4 = gMain.vblankCallback;
            SetVBlankCallback(NULL);
            r2 = 0;
            if (gTasks[taskId].data[1] != 0)
                r2 += DISPCNT_OBJ_ON;
            if (gTasks[taskId].data[2] != 0)
                r2 |= DISPCNT_BG1_ON;
            ResetOtherVideoRegisters(r2);
            gMain.state = 1;
        }
        break;
    case 1:
        DecompressAndLoadBgGfxUsingHeap(3, gPokedexEvo_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, gPokedexEvolutionScreen_Tilemap, 0, 0);
        FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
        PutWindowTilemap(WIN_INFO);
        CopyWindowToVram(WIN_INFO, 3);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 2:
        sub_80BFCDC(0xD);
        LoadPokedexBgPalette(sPokedexView->unk64C_1);
        gMain.state++;
        break;
    case 3:
        if (gTasks[taskId].data[1] == 0)
        {
            sPokedexView->selectedScreen = EVO_SCREEN;
            //Icon
            FreeMonIconPalettes(); //Free space for new pallete
            LoadMonIconPalette(sPokedexListItem->species); //Loads pallete for current mon
			PrintPreEvolutions(taskId, NationalPokedexNumToSpecies(sPokedexListItem->dexNum));
                gTasks[taskId].data[4] = CreateMonIcon(sPokedexListItem->species, SpriteCB_MonIcon, 19 + 32*sPokedexView->numPreEvolutions, 34, 4, 0, TRUE); //Create pokemon sprite
            gSprites[gTasks[taskId].data[4]].oam.priority = 0;
        }
        gMain.state++;
        break;
    case 4:
        //Print evo info and icons
        gTasks[taskId].data[3] = 0;
        PrintEvolutionTargetSpeciesAndMethod(taskId, sPokedexListItem->species, 0, sPokedexView->numPreEvolutions);
        gMain.state++;
        break;
    case 5:
        {
        u32 preservedPalettes = 0;

        if (gTasks[taskId].data[2] != 0)
            preservedPalettes = 0x14; // each bit represents a palette index
        if (gTasks[taskId].data[1] != 0)
            preservedPalettes |= (1 << (gSprites[gTasks[taskId].tMonSpriteId].oam.paletteNum + 16));
        BeginNormalPaletteFade(~preservedPalettes, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(sub_80BB370);
        gMain.state++;
        }
        break;
    case 6:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        HideBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        gMain.state++;
        break;
    case 7:
        if (!gPaletteFade.active)
            gMain.state++;
        break;
    case 8:
        gMain.state++;
        break;
    case 9:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] = 1;
        gTasks[taskId].func = Task_HandleEvolutionScreenInput;
        gMain.state = 0;
        break;
    }
}
static void Task_HandleEvolutionScreenInput(u8 taskId)
{
    //Exit to overview
    if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
        sPokedexView->unk64E = 0;
        gTasks[taskId].func = Task_SwitchScreensFromEvolutionScreen;
        PlaySE(SE_PC_OFF);
        return;
    }
    if (gMain.newKeys & SELECT_BUTTON)
        if (TryToChangeForm(taskId, Task_SwitchScreensFromEvolutionScreen))
            return;

    //Switch screens
    if ((JOY_NEW(DPAD_LEFT) || (JOY_NEW(L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)))
    {
        sPokedexView->selectedScreen = STATS_SCREEN;
        BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
        sPokedexView->unk64E = 1;
        gTasks[taskId].func = Task_SwitchScreensFromEvolutionScreen;
        PlaySE(SE_PIN);
    }
    if ((JOY_NEW(DPAD_RIGHT) || (JOY_NEW(R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)))
    {
        if (!sPokedexListItem->owned)
            PlaySE(SE_HAZURE);
        else
        {
            sPokedexView->selectedScreen = CRY_SCREEN;
            BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
            sPokedexView->unk64E = 2;
            gTasks[taskId].func = Task_SwitchScreensFromEvolutionScreen;
            PlaySE(SE_PIN);
        }
    }
}
static void handleTargetSpeciesPrint(u8 taskId, u16 targetSpecies, u8 base_x, u8 base_y, u8 base_offset, u8 base_i)
{
    bool8 seen = GetSetPokedexFlag(SpeciesToNationalPokedexNum(targetSpecies), FLAG_GET_SEEN);

    if (seen || !HGSS_HIDE_UNSEEN_EVOLUTION_NAMES)
        StringCopy(gStringVar3, gSpeciesNames[targetSpecies]); //evolution mon name
    else
        StringCopy(gStringVar3, gText_ThreeQuestionMarks); //show questionmarks instead of name
    StringExpandPlaceholders(gStringVar3, gText_EVO_Name); //evolution mon name
    PrintInfoScreenTextSmall(gStringVar3, base_x, base_y + base_offset*base_i); //evolution mon name

    if (base_i < 8)
    {
        u8 horizontal_space = 32;
        u8 offset_x = 52;

        if ((targetSpecies >= SPECIES_VAPOREON && targetSpecies <= SPECIES_FLAREON)
          || targetSpecies == SPECIES_ESPEON  || targetSpecies == SPECIES_UMBREON
          || targetSpecies == SPECIES_LEAFEON || targetSpecies == SPECIES_GLACEON
          || targetSpecies == SPECIES_SYLVEON)
        {
            horizontal_space = 25;
            offset_x = 48;
        }

        LoadMonIconPalette(targetSpecies); //Loads pallete for current mon
        gTasks[taskId].data[4+base_i] = CreateMonIcon(targetSpecies, SpriteCB_MonIcon, offset_x + horizontal_space*base_i, 34, 4, 0, TRUE); //Create pokemon sprite
        gSprites[gTasks[taskId].data[4+base_i]].oam.priority = 0;
    }
}

static void CreateCaughtBallEvolutionScreen(u16 targetSpecies, u8 x, u8 y, u16 unused)
{
    bool8 owned = GetSetPokedexFlag(SpeciesToNationalPokedexNum(targetSpecies), FLAG_GET_CAUGHT);
    if (owned)
        BlitBitmapToWindow(0, gUnknown_0855D2BE, x, y-1, 8, 16);
    else
    {
        PrintInfoScreenTextSmall(gText_OneDash, x+1, y-1);
    }
}
static void HandlePreEvolutionSpeciesPrint(u8 taskId, u16 preSpecies, u16 species, u8 base_x, u8 base_y, u8 base_y_offset, u8 base_i)
{
    bool8 seen = GetSetPokedexFlag(SpeciesToNationalPokedexNum(preSpecies), FLAG_GET_SEEN);

    StringCopy(gStringVar1, gSpeciesNames[species]); //evolution mon name
    if (seen || !HGSS_HIDE_UNSEEN_EVOLUTION_NAMES)
        StringCopy(gStringVar2, gSpeciesNames[preSpecies]); //evolution mon name
    else
        StringCopy(gStringVar2, gText_ThreeQuestionMarks); //show questionmarks instead of name

    StringExpandPlaceholders(gStringVar3, gText_EVO_PreEvo); //evolution mon name
    PrintInfoScreenTextSmall(gStringVar3, base_x, base_y + base_y_offset*base_i); //evolution mon name

    if(base_i < 3) 
    {
        LoadMonIconPalette(preSpecies); //Loads pallete for current mon
            gTasks[taskId].data[4+base_i] = CreateMonIcon(preSpecies, SpriteCB_MonIcon, 18 + 32*base_i, 31, 4, 0, TRUE); //Create pokemon sprite
        gSprites[gTasks[taskId].data[4+base_i]].oam.priority = 0;
    }
}

static u8 PrintPreEvolutions(u8 taskId, u16 species)
{
    u16 i;
    u16 j;

    u8 base_x = 13;
    u8 base_x_offset = 54;
    u8 base_y = 51;
    u8 base_y_offset = 9;
    u8 base_i = 0;
    u8 depth_x = 16;

    u16 preEvolutionOne = 0;
    u16 preEvolutionTwo = 0;
    u8 numPreEvolutions = 0;

    //Calculate previous evolution
    for (i = 0; i < NUM_SPECIES; i++)
    {
        for (j = 0; j < EVOS_PER_MON; j++)
        {
            if (gEvolutionTable[i][j].targetSpecies == species)
            {
                preEvolutionOne = i;
                numPreEvolutions += 1;
                break;
            }
        }
    }

    //Calculate if previous evolution also has a previous evolution
    if (numPreEvolutions != 0)
    {
        for (i = 0; i < NUM_SPECIES; i++)
        {
            for (j = 0; j < EVOS_PER_MON; j++)
            {
                if (gEvolutionTable[i][j].targetSpecies == preEvolutionOne)
                {
                    preEvolutionTwo = i;
                    numPreEvolutions += 1;
                    CreateCaughtBallEvolutionScreen(preEvolutionTwo, base_x - 9, base_y + base_y_offset*0, 0);
                    HandlePreEvolutionSpeciesPrint(taskId, preEvolutionTwo, preEvolutionOne, base_x, base_y, base_y_offset, 0);
                    break;
                }
            }
        }
    }

    //Print ball and name
    if (preEvolutionOne != 0)
    {
        CreateCaughtBallEvolutionScreen(preEvolutionOne, base_x - 9, base_y + base_y_offset*(numPreEvolutions - 1), 0);
        HandlePreEvolutionSpeciesPrint(taskId, preEvolutionOne, species, base_x, base_y, base_y_offset, numPreEvolutions - 1);
    }

    //vertical line
    FillWindowPixelRect(0, PIXEL_FILL(5), 33 + 32*numPreEvolutions, 18, 1, 32); //PIXEL_FILL(15) for black

    sPokedexView->numPreEvolutions = numPreEvolutions;

    return numPreEvolutions;
}

#define EVO_SCREEN_LVL_DIGITS 2
static u8 PrintEvolutionTargetSpeciesAndMethod(u8 taskId, u16 species, u8 depth, u8 depth_i)
{
    u16 i;
    u16 targetSpecies = 0;

    u16 item;

    bool8 left = TRUE;
    u8 base_x = 13;
    u8 base_x_offset = 54;
    u8 base_y = 52;
    u8 base_offset = 9;
    u8 base_i = 0;
    u8 times = 0;
    u8 depth_x = 16;

    StringCopy(gStringVar1, gSpeciesNames[species]);

    //Calculate number of possible direct evolutions (e.g. Eevee has 5 but torchic has 1)
    for (i = 0; i < EVOS_PER_MON; i++)
    {
        if(gEvolutionTable[species][i].method != 0)
            times += 1;
    }
	 gTasks[taskId].data[3] = times;

    //If there are no evolutions print text
    if (times == 0 && depth == 0)
    {
        StringExpandPlaceholders(gStringVar4, gText_EVO_NONE); 
        PrintInfoScreenTextSmall(gStringVar4, base_x-7, base_y + base_offset*depth_i);
    }

    //If there are evolutions find out which and print them 1 by 1
    for (i = 0; i < times; i++)
    {
        base_i = i + depth_i;
        left = !left;
        switch (gEvolutionTable[species][i].method)
        {
        case EVO_FRIENDSHIP:
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
			CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
            ConvertIntToDecimalStringN(gStringVar2, 220, STR_CONV_MODE_LEADING_ZEROS, 3); //friendship value
            handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
            StringExpandPlaceholders(gStringVar4, gText_EVO_FRIENDSHIP );
            PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
            break;
        case EVO_FRIENDSHIP_DAY:
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
            CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
            handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
            StringExpandPlaceholders(gStringVar4, gText_EVO_FRIENDSHIP_DAY ); 
            PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
            break;
        case EVO_FRIENDSHIP_NIGHT:
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
            CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
            handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
            StringExpandPlaceholders(gStringVar4, gText_EVO_FRIENDSHIP_NIGHT );
            PrintInfoScreenTextSmall(gStringVar4, base_x+base_x_offset, base_y + base_offset*base_i);
            break;
        case EVO_LEVEL:
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
			CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
            ConvertIntToDecimalStringN(gStringVar2, gEvolutionTable[species][i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
            StringExpandPlaceholders(gStringVar4, gText_EVO_LEVEL );
            PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
            break;
        case EVO_TRADE:
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
            CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
            handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
            StringExpandPlaceholders(gStringVar4, gText_EVO_TRADE );
            PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
            break;
        case EVO_TRADE_ITEM:
            item = gEvolutionTable[species][i].param; //item
            CopyItemName(item, gStringVar2); //item
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
            CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
            handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
            StringExpandPlaceholders(gStringVar4, gText_EVO_TRADE_ITEM );
            PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
            break;
        case EVO_ITEM:
            item = gEvolutionTable[species][i].param;
            CopyItemName(item, gStringVar2);
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
            CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
            handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
            StringExpandPlaceholders(gStringVar4, gText_EVO_ITEM );
            PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
            break;
        case EVO_LEVEL_ATK_GT_DEF:
            ConvertIntToDecimalStringN(gStringVar2, gEvolutionTable[species][i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
            CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
            handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
            StringExpandPlaceholders(gStringVar4, gText_EVO_LEVEL_ATK_GT_DEF );
            PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
            break;
        case EVO_LEVEL_ATK_EQ_DEF:
            ConvertIntToDecimalStringN(gStringVar2, gEvolutionTable[species][i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
            CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
            handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
            StringExpandPlaceholders(gStringVar4, gText_EVO_LEVEL_ATK_EQ_DEF );
            PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
            break;
        case EVO_LEVEL_ATK_LT_DEF:
            ConvertIntToDecimalStringN(gStringVar2, gEvolutionTable[species][i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
            CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
            handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
            StringExpandPlaceholders(gStringVar4, gText_EVO_LEVEL_ATK_LT_DEF );
            PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
            break;
        case EVO_LEVEL_SILCOON:
            ConvertIntToDecimalStringN(gStringVar2, gEvolutionTable[species][i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
            CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
            handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
            StringExpandPlaceholders(gStringVar4, gText_EVO_LEVEL_SILCOON );
            PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
            break;
        case EVO_LEVEL_CASCOON:
            ConvertIntToDecimalStringN(gStringVar2, gEvolutionTable[species][i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
            CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
            handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
            StringExpandPlaceholders(gStringVar4, gText_EVO_LEVEL_CASCOON );
            PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
            break;
        case EVO_LEVEL_NINJASK:
            ConvertIntToDecimalStringN(gStringVar2, gEvolutionTable[species][i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
            CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
            handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
            StringExpandPlaceholders(gStringVar4, gText_EVO_LEVEL_NINJASK );
            PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
            break;
		        case EVO_LEVEL_SHEDINJA:
            ConvertIntToDecimalStringN(gStringVar2, gEvolutionTable[species][i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
            CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
            handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
            StringExpandPlaceholders(gStringVar4, gText_EVO_LEVEL_SHEDINJA );
            PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
            break;
        case EVO_BEAUTY:
            ConvertIntToDecimalStringN(gStringVar2, gEvolutionTable[species][i].param, STR_CONV_MODE_LEADING_ZEROS, 3); //beauty
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
            CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
            handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
            StringExpandPlaceholders(gStringVar4, gText_EVO_BEAUTY );
            PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
            break;
            case EVO_LEVEL_FEMALE:
                ConvertIntToDecimalStringN(gStringVar2, gEvolutionTable[species][i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
				CreateCaughtBallEvolutionScreen(targetSpecies, base_x-9, base_y + base_offset*base_i, 0);
                handleTargetSpeciesPrint(taskId, targetSpecies, base_x, base_y, base_offset, base_i); //evolution mon name
                StringExpandPlaceholders(gStringVar4, gText_EVO_LEVEL_FEMALE );
                PrintInfoScreenTextSmall(gStringVar4, base_x+base_x_offset, base_y + base_offset*base_i);
                break;
		  case EVO_ITEM_MALE:
                item = gEvolutionTable[species][i].param; //item
                CopyItemName(item, gStringVar2); //item
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
                CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
                handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
                StringExpandPlaceholders(gStringVar4, gText_EVO_ITEM_MALE );
                PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
                break;
            case EVO_ITEM_FEMALE:
                item = gEvolutionTable[species][i].param; //item
                CopyItemName(item, gStringVar2); //item
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
                CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
                handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
                StringExpandPlaceholders(gStringVar4, gText_EVO_ITEM_FEMALE );
                PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
                break;
			case EVO_ITEM_LEVEL_30:
				item = gEvolutionTable[species][i].param;
				CopyItemName(item, gStringVar2);
				targetSpecies = gEvolutionTable[species][i].targetSpecies;
                CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
                handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
				StringExpandPlaceholders(gStringVar4, gText_EVO_ITEM_LEVEL_30 );
                PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
				break;
			case EVO_ITEM_LEVEL_40:
				item = gEvolutionTable[species][i].param;
				CopyItemName(item, gStringVar2);
				targetSpecies = gEvolutionTable[species][i].targetSpecies;
                CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
                handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
				StringExpandPlaceholders(gStringVar4, gText_EVO_ITEM_LEVEL_40 );
                PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
				break;
			case EVO_ITEM_LEVEL_50:
				item = gEvolutionTable[species][i].param;
				CopyItemName(item, gStringVar2);
				targetSpecies = gEvolutionTable[species][i].targetSpecies;
                CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_offset*base_i, 0);
                handleTargetSpeciesPrint(taskId, targetSpecies, base_x + depth_x*depth, base_y, base_offset, base_i); //evolution mon name
				StringExpandPlaceholders(gStringVar4, gText_EVO_ITEM_LEVEL_50 );
                PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_offset*base_i);
				break;
        }//Switch end
		
		depth_i += PrintEvolutionTargetSpeciesAndMethod(taskId, targetSpecies, depth+1, base_i+1);
    }//For loop end
	
	  return times;
}
static void Task_SwitchScreensFromEvolutionScreen(u8 taskId)
{
	u8 i;
    if (!gPaletteFade.active)
    {
        FreeMonIconPalettes();                                          //Destroy pokemon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy pokemon icon sprite
		
		for (i = 1; i <= gTasks[taskId].data[3]; i++)
        {
            FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4+i]]); //Destroy pokemon icon sprite
        }
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);

        switch (sPokedexView->unk64E)
        {
        case 1:
            gTasks[taskId].func = Task_LoadStatsScreen;
            break;
        case 11:
            gTasks[taskId].func = Task_LoadEvolutionScreen;
            break;
        case 2:
            gTasks[taskId].func = LoadCryScreen;
            break;
        default:
            gTasks[taskId].func = LoadInfoScreen;
            break;
        }
    }
}
static void Task_ExitEvolutionScreen(u8 taskId)
{
    u8 i;
    if (!gPaletteFade.active)
    {
        FreeMonIconPalettes();                                          //Destroy pokemon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy pokemon icon sprite
        for (i = 1; i <= gTasks[taskId].data[3]; i++)
        {
            FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4+i]]); //Destroy pokemon icon sprite
        }

        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        FreeWindowAndBgBuffers_();
        DestroyTask(taskId);
    }
}

//Stat bars on main screen, code by DizzyEgg, idea by Jaizu
#define PIXEL_COORDS_TO_OFFSET(x, y)(			\
/*Add tiles by X*/								\
((y / 8) * 32 * 8)								\
/*Add tiles by X*/								\
+ ((x / 8) * 32)								\
/*Add pixels by Y*/								\
+ ((((y) - ((y / 8) * 8))) * 4)				    \
/*Add pixels by X*/								\
+ ((((x) - ((x / 8) * 8)) / 2)))

static inline void WritePixel(u8 *dst, u32 x, u32 y, u32 value)
{
    if (x & 1)
    {
        dst[PIXEL_COORDS_TO_OFFSET(x, y)] &= ~0xF0;
        dst[PIXEL_COORDS_TO_OFFSET(x, y)] |= (value << 4);
    }
    else
    {
        dst[PIXEL_COORDS_TO_OFFSET(x, y)] &= ~0xF;
        dst[PIXEL_COORDS_TO_OFFSET(x, y)] |= (value);
    }
}
#define STAT_BAR_X_OFFSET 10
static void CreateStatBar(u8 *dst, u32 y, u32 width)
{
    u32 i, color;

    switch (width)
    {
    case 0 ... 5:
        color = COLOR_WORST;
        break;
    case 6 ... 15:
        color = COLOR_BAD;
        break;
    case 16 ... 25:
        color = COLOR_AVERAGE;
        break;
    case 26 ... 31:
        color = COLOR_GOOD;
        break;
    case 32 ... 37:
        color = COLOR_VERY_GOOD;
        break;
    default:
        color = COLOR_BEST;
        break;
    }

    // white pixes left side
    WritePixel(dst, STAT_BAR_X_OFFSET, y + 0, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET, y + 1, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET, y + 2, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET, y + 3, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET, y + 4, COLOR_ID_BAR_WHITE);

    // white pixels right side
    WritePixel(dst, STAT_BAR_X_OFFSET + width - 1, y + 0, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET + width - 1, y + 1, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET + width - 1, y + 2, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET + width - 1, y + 3, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET + width - 1, y + 4, COLOR_ID_BAR_WHITE);

    // Fill
    for (i = 1; i < width - 1; i++)
    {
        WritePixel(dst, STAT_BAR_X_OFFSET + i, y + 0, COLOR_ID_BAR_WHITE);
        WritePixel(dst, STAT_BAR_X_OFFSET + i, y + 1, COLOR_ID_FILL_SHADOW + color * 2);
        WritePixel(dst, STAT_BAR_X_OFFSET + i, y + 2, COLOR_ID_FILL + color * 2);
        WritePixel(dst, STAT_BAR_X_OFFSET + i, y + 3, COLOR_ID_FILL + color * 2);
        WritePixel(dst, STAT_BAR_X_OFFSET + i, y + 4, COLOR_ID_BAR_WHITE);
    }
}
static const u8 sBaseStatOffsets[] =
{
    offsetof(struct BaseStats, baseHP),
    offsetof(struct BaseStats, baseAttack),
    offsetof(struct BaseStats, baseDefense),
    offsetof(struct BaseStats, baseSpAttack),
    offsetof(struct BaseStats, baseSpDefense),
    offsetof(struct BaseStats, baseSpeed),
};
static void TryDestroyStatBars(void)
{
    if (sPokedexView->statBarsSpriteId != 0xFF)
    {
        FreeSpriteTilesByTag(TAG_STAT_BAR);
        //FreeSpriteOamMatrix(&gSprites[sPokedexView->statBarsSpriteId]);
        DestroySprite(&gSprites[sPokedexView->statBarsSpriteId]);
        sPokedexView->statBarsSpriteId = 0xFF;
    }
}
static void TryDestroyStatBarsBg(void)
{
    if (sPokedexView->statBarsBgSpriteId != 0xFF)
    {
        FreeSpriteTilesByTag(TAG_STAT_BAR_BG);
        //FreeSpriteOamMatrix(&gSprites[sPokedexView->statBarsBgSpriteId]);
        DestroySprite(&gSprites[sPokedexView->statBarsBgSpriteId]);
        sPokedexView->statBarsBgSpriteId = 0xFF;
    }
}
static void CreateStatBars(struct PokedexListItem *dexMon)
{
    u8 offset_x = 184; //Moves the complete stat box left/right
    u8 offset_y = 16; //Moves the complete stat box up/down
    TryDestroyStatBars();

    sPokedexView->justScrolled = FALSE;


    if (dexMon->owned) // Show filed bars
    {
        u8 i;
        u32 width, statValue;
        u8 *gfx = Alloc(64 * 64);
        static const u8 sBarsYOffset[] = {3, 13, 23, 33, 43, 53};
        struct SpriteSheet sheet = {gfx, 64 * 64, TAG_STAT_BAR};
        u32 species = NationalPokedexNumToSpecies(dexMon->dexNum);

        memcpy(gfx, sStatBarsGfx, sizeof(sStatBarsGfx));
        for (i = 0; i < NUM_STATS; i++)
        {
            statValue = *((u8*)(&gBaseStats[species]) + sBaseStatOffsets[i]);
            if (statValue <= 100)
            {
                width = statValue / 3;
                if (width >= 33)
                    width -= 1;
            }
            else
                width = (100 / 3) + ((statValue - 100) / 14);

            if (width > 39) // Max pixels
                width = 39;
            if (width < 3)
                width = 3;

            CreateStatBar(gfx, sBarsYOffset[i], width);
        }

        LoadSpriteSheet(&sheet);
        free(gfx);
    }
    else if (dexMon->seen) // Just HP/ATK/DEF
    {
        static const struct SpriteSheet sheet = {sStatBarsGfx, 64 * 64, TAG_STAT_BAR};

        LoadSpriteSheet(&sheet);
    }
    else // neither seen nor owned
    {
        return;
    }
    sPokedexView->statBarsSpriteId = CreateSprite(&sStatBarSpriteTemplate, 36+offset_x, 107+offset_y, 10);
}
static void CreateStatBarsBg(void) //HGSS_Ui stat bars background text
{
    static const struct SpriteSheet sheetStatBarsBg = {sStatBarsGfx, 64 * 64, TAG_STAT_BAR_BG};
    u8 offset_x = 184; //Moves the complete stat box left/right
    u8 offset_y = 16; //Moves the complete stat box up/down

    TryDestroyStatBarsBg();

    LoadSpriteSheet(&sheetStatBarsBg);
    sPokedexView->statBarsBgSpriteId = CreateSprite(&sStatBarBgSpriteTemplate, 36+offset_x, 107+offset_y, 0);
}
// Hack to destroy sprites when a pokemon data is being loaded in
static bool32 IsMonInfoBeingLoaded(void)
{
    return (gSprites[sPokedexView->selectedMonSpriteId].callback == MoveMonIntoPosition);
}
static void SpriteCB_StatBars(struct Sprite *sprite)
{
    if (IsMonInfoBeingLoaded())
        sprite->invisible = TRUE;
    if (sPokedexView->unk64A != 0 && sPokedexView->unk64A != 3)
    {
        FreeSpriteTilesByTag(TAG_STAT_BAR);
        FreeSpriteOamMatrix(&gSprites[sPokedexView->statBarsSpriteId]);
        DestroySprite(&gSprites[sPokedexView->statBarsSpriteId]);
        sPokedexView->statBarsSpriteId = 0xFF;
    }
}
static void SpriteCB_StatBarsBg(struct Sprite *sprite)
{
    if (IsMonInfoBeingLoaded())
        sprite->invisible = TRUE;
    if (sPokedexView->unk64A != 0 && sPokedexView->unk64A != 3)
    {
        FreeSpriteTilesByTag(TAG_STAT_BAR_BG);
        FreeSpriteOamMatrix(&gSprites[sPokedexView->statBarsBgSpriteId]);
        DestroySprite(&gSprites[sPokedexView->statBarsBgSpriteId]);
        sPokedexView->statBarsBgSpriteId = 0xFF;
    }
}
