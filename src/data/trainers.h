const struct Trainer gTrainers[] = {
    [TRAINER_NONE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _(""),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = 0,
        .party = {.NoItemDefaultMoves = NULL},
    },

    [TRAINER_SAWYER_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("SAWYER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sawyer1),
        .party = {.ItemCustomMidele = sParty_Sawyer1},
    },

    [TRAINER_GRUNT_AQUA_HIDEOUT_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntAquaHideout1),
        .party = {.ItemCustomMidele = sParty_GruntAquaHideout1},
    },

    [TRAINER_GRUNT_AQUA_HIDEOUT_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntAquaHideout2),
        .party = {.ItemCustomMidele = sParty_GruntAquaHideout2},
    },

    [TRAINER_GRUNT_AQUA_HIDEOUT_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntAquaHideout3),
        .party = {.ItemCustomMidele = sParty_GruntAquaHideout3},
    },

    [TRAINER_GRUNT_AQUA_HIDEOUT_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntAquaHideout4),
        .party = {.ItemCustomMidele = sParty_GruntAquaHideout4},
    },

    [TRAINER_GRUNT_SEAFLOOR_CAVERN_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntSeafloorCavern1),
        .party = {.ItemCustomMidele = sParty_GruntSeafloorCavern1},
    },

    [TRAINER_GRUNT_SEAFLOOR_CAVERN_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntSeafloorCavern2),
        .party = {.ItemCustomMidele = sParty_GruntSeafloorCavern2},
    },

    [TRAINER_GRUNT_SEAFLOOR_CAVERN_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntSeafloorCavern3),
        .party = {.ItemCustomMidele = sParty_GruntSeafloorCavern3},
    },

    [TRAINER_GABRIELLE_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("GABRIELLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Gabrielle1),
        .party = {.ItemCustomMidele = sParty_Gabrielle1},
    },

    [TRAINER_GRUNT_PETALBURG_WOODS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntPetalburgWoods),
        .party = {.ItemCustomMidele = sParty_GruntPetalburgWoods},
    },

    [TRAINER_MARCEL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("MARCEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Marcel),
        .party = {.ItemCustomMidele = sParty_Marcel},
    },

    [TRAINER_ALBERTO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ALBERTO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Alberto),
        .party = {.ItemCustomMidele = sParty_Alberto},
    },

    [TRAINER_ED] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COLLECTOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("ED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ed),
        .party = {.ItemCustomMidele = sParty_Ed},
    },

    [TRAINER_GRUNT_SEAFLOOR_CAVERN_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntSeafloorCavern4),
        .party = {.ItemCustomMidele = sParty_GruntSeafloorCavern4},
    },

    [TRAINER_DECLAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("DECLAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Declan),
        .party = {.ItemCustomMidele = sParty_Declan},
    },

    [TRAINER_GRUNT_RUSTURF_TUNNEL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntRusturfTunnel),
        .party = {.ItemCustomMidele = sParty_GruntRusturfTunnel},
    },

    [TRAINER_GRUNT_WEATHER_INST_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntWeatherInst1),
        .party = {.ItemCustomMidele = sParty_GruntWeatherInst1},
    },

    [TRAINER_GRUNT_WEATHER_INST_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntWeatherInst2),
        .party = {.ItemCustomMidele = sParty_GruntWeatherInst2},
    },

    [TRAINER_GRUNT_WEATHER_INST_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntWeatherInst3),
        .party = {.ItemCustomMidele = sParty_GruntWeatherInst3},
    },

    [TRAINER_MICOLO_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .battleMusic = CRUELANGELSTHESIS,
        .trainerPic = TRAINER_PIC_MICOLO,
        .trainerName = _("MICOLO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Micolo1),
        .party = {.ItemCustomMidele = sParty_Micolo1},
    },

    [TRAINER_MICOLO_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .battleMusic = CRUELANGELSTHESIS,
        .trainerPic = TRAINER_PIC_MICOLO,
        .trainerName = _("MICOLO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Micolo2),
        .party = {.ItemCustomMidele = sParty_Micolo2},
    },

    [TRAINER_GRUNT_SPACE_CENTER_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntSpaceCenter1),
        .party = {.ItemCustomMidele = sParty_GruntSpaceCenter1},
    },

    [TRAINER_GRUNT_MT_PYRE_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMtPyre1),
        .party = {.ItemCustomMidele = sParty_GruntMtPyre1},
    },

    [TRAINER_GRUNT_MT_PYRE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMtPyre2),
        .party = {.ItemCustomMidele = sParty_GruntMtPyre2},
    },

    [TRAINER_GRUNT_MT_PYRE_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMtPyre3),
        .party = {.ItemCustomMidele = sParty_GruntMtPyre3},
    },

    [TRAINER_GRUNT_WEATHER_INST_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntWeatherInst4),
        .party = {.ItemCustomMidele = sParty_GruntWeatherInst4},
    },

    [TRAINER_GRUNT_AQUA_HIDEOUT_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntAquaHideout5),
        .party = {.ItemCustomMidele = sParty_GruntAquaHideout5},
    },

    [TRAINER_GRUNT_AQUA_HIDEOUT_6] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntAquaHideout6),
        .party = {.ItemCustomMidele = sParty_GruntAquaHideout6},
    },

    [TRAINER_FREDRICK] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .trainerName = _("FREDRICK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Fredrick),
        .party = {.ItemCustomMidele = sParty_Fredrick},
    },

    [TRAINER_MATT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_AQUA_ADMIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_M,
        .trainerName = _("MATT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Matt),
        .party = {.ItemCustomMidele = sParty_Matt},
    },

    [TRAINER_ZANDER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("ZANDER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Zander),
        .party = {.ItemCustomMidele = sParty_Zander},
    },

    [TRAINER_SHELLY_WEATHER_INSTITUTE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_AQUA_ADMIN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("SHELLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_ShellyWeatherInstitute),
        .party = {.ItemCustomMidele = sParty_ShellyWeatherInstitute},
    },

    [TRAINER_SHELLY_SEAFLOOR_CAVERN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_AQUA_ADMIN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("SHELLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_ShellySeafloorCavern),
        .party = {.ItemCustomMidele = sParty_ShellySeafloorCavern},
    },

    [TRAINER_ARCHIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_AQUA_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .trainerName = _("ARCHIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Archie),
        .party = {.ItemCustomMidele = sParty_Archie},
    },

    [TRAINER_LEAH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .trainerName = _("LEAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Leah),
        .party = {.ItemCustomMidele = sParty_Leah},
    },

    [TRAINER_DAISY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("DAISY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Daisy),
        .party = {.ItemCustomMidele = sParty_Daisy},
    },

    [TRAINER_ROSE_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("ROSE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Rose1),
        .party = {.ItemCustomMidele = sParty_Rose1},
    },

    [TRAINER_FELIX] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("FELIX"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Felix),
        .party = {.ItemCustomMidele = sParty_Felix},
    },

    [TRAINER_VIOLET] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("VIOLET"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Violet),
        .party = {.ItemCustomMidele = sParty_Violet},
    },

    [TRAINER_ROSE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("ROSE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Rose2),
        .party = {.ItemCustomMidele = sParty_Rose2},
    },

    [TRAINER_ROSE_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("ROSE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Rose3),
        .party = {.ItemCustomMidele = sParty_Rose3},
    },

    [TRAINER_ROSE_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("ROSE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Rose4),
        .party = {.ItemCustomMidele = sParty_Rose4},
    },

    [TRAINER_ROSE_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("ROSE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Rose5),
        .party = {.ItemCustomMidele = sParty_Rose5},
    },

    [TRAINER_DUSTY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("DUSTY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dusty1),
        .party = {.ItemCustomMidele = sParty_Dusty1},
    },

    [TRAINER_CHIP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("CHIP"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Chip),
        .party = {.ItemCustomMidele = sParty_Chip},
    },

    [TRAINER_FOSTER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("FOSTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Foster),
        .party = {.ItemCustomMidele = sParty_Foster},
    },

    [TRAINER_DUSTY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("DUSTY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dusty2),
        .party = {.ItemCustomMidele = sParty_Dusty2},
    },

    [TRAINER_DUSTY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("DUSTY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dusty3),
        .party = {.ItemCustomMidele = sParty_Dusty3},
    },

    [TRAINER_DUSTY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("DUSTY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dusty4),
        .party = {.ItemCustomMidele = sParty_Dusty4},
    },

    [TRAINER_DUSTY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("DUSTY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dusty5),
        .party = {.ItemCustomMidele = sParty_Dusty5},
    },

    [TRAINER_GABBY_AND_TY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .trainerName = _("GABBY & TY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GabbyAndTy1),
        .party = {.ItemCustomMidele = sParty_GabbyAndTy1},
    },

    [TRAINER_GABBY_AND_TY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .trainerName = _("GABBY & TY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GabbyAndTy2),
        .party = {.ItemCustomMidele = sParty_GabbyAndTy2},
    },

    [TRAINER_GABBY_AND_TY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .trainerName = _("GABBY & TY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GabbyAndTy3),
        .party = {.ItemCustomMidele = sParty_GabbyAndTy3},
    },

    [TRAINER_GABBY_AND_TY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .trainerName = _("GABBY & TY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GabbyAndTy4),
        .party = {.ItemCustomMidele = sParty_GabbyAndTy4},
    },

    [TRAINER_GABBY_AND_TY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .trainerName = _("GABBY & TY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GabbyAndTy5),
        .party = {.ItemCustomMidele = sParty_GabbyAndTy5},
    },

    [TRAINER_GABBY_AND_TY_6] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .trainerName = _("GABBY & TY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GabbyAndTy6),
        .party = {.ItemCustomMidele = sParty_GabbyAndTy6},
    },

    [TRAINER_LOLA_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("LOLA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lola1),
        .party = {.ItemCustomMidele = sParty_Lola1},
    },

    [TRAINER_AUSTINA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("AUSTINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Austina),
        .party = {.ItemCustomMidele = sParty_Austina},
    },

    [TRAINER_GWEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("GWEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Gwen),
        .party = {.ItemCustomMidele = sParty_Gwen},
    },

    [TRAINER_LOLA_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("LOLA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lola2),
        .party = {.ItemCustomMidele = sParty_Lola2},
    },

    [TRAINER_LOLA_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("LOLA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lola3),
        .party = {.ItemCustomMidele = sParty_Lola3},
    },

    [TRAINER_LOLA_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("LOLA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lola4),
        .party = {.ItemCustomMidele = sParty_Lola4},
    },

    [TRAINER_LOLA_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("LOLA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lola5),
        .party = {.ItemCustomMidele = sParty_Lola5},
    },

    [TRAINER_RICKY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .trainerName = _("RICKY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ricky1),
        .party = {.ItemCustomMidele = sParty_Ricky1},
    },

    [TRAINER_SIMON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .trainerName = _("SIMON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Simon),
        .party = {.ItemCustomMidele = sParty_Simon},
    },

    [TRAINER_CHARLIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .trainerName = _("CHARLIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Charlie),
        .party = {.ItemCustomMidele = sParty_Charlie},
    },

    [TRAINER_RICKY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .trainerName = _("RICKY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ricky2),
        .party = {.ItemCustomMidele = sParty_Ricky2},
    },

    [TRAINER_RICKY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .trainerName = _("RICKY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ricky3),
        .party = {.ItemCustomMidele = sParty_Ricky3},
    },

    [TRAINER_RICKY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .trainerName = _("RICKY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ricky4),
        .party = {.ItemCustomMidele = sParty_Ricky4},
    },

    [TRAINER_RICKY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .trainerName = _("RICKY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ricky5),
        .party = {.ItemCustomMidele = sParty_Ricky5},
    },

    [TRAINER_RANDALL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("RANDALL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_PREFER_BATON_PASS,
        .partySize = ARRAY_COUNT(sParty_Randall),
        .party = {.ItemCustomMidele = sParty_Randall},
    },

    [TRAINER_PARKER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("PARKER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Parker),
        .party = {.ItemCustomMidele = sParty_Parker},
    },

    [TRAINER_GEORGE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("GEORGE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_George),
        .party = {.ItemCustomMidele = sParty_George},
    },

    [TRAINER_BERKE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("BERKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Berke),
        .party = {.ItemCustomMidele = sParty_Berke},
    },

    [TRAINER_BRAXTON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("BRAXTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Braxton),
        .party = {.ItemCustomMidele = sParty_Braxton},
    },

    [TRAINER_VINCENT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("VINCENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Vincent),
        .party = {.ItemCustomMidele = sParty_Vincent},
    },

    [TRAINER_LEROY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("LEROY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Leroy),
        .party = {.ItemCustomMidele = sParty_Leroy},
    },

    [TRAINER_WILTON_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("WILTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Wilton1),
        .party = {.ItemCustomMidele = sParty_Wilton1},
    },

    [TRAINER_EDGAR] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("EDGAR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Edgar),
        .party = {.ItemCustomMidele = sParty_Edgar},
    },

    [TRAINER_ALBERT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("ALBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Albert),
        .party = {.ItemCustomMidele = sParty_Albert},
    },

    [TRAINER_SAMUEL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("SAMUEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Samuel),
        .party = {.ItemCustomMidele = sParty_Samuel},
    },

    [TRAINER_VITO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("VITO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Vito),
        .party = {.ItemCustomMidele = sParty_Vito},
    },

    [TRAINER_OWEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("OWEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Owen),
        .party = {.ItemCustomMidele = sParty_Owen},
    },

    [TRAINER_WILTON_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("WILTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Wilton2),
        .party = {.ItemCustomMidele = sParty_Wilton2},
    },

    [TRAINER_WILTON_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("WILTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Wilton3),
        .party = {.ItemCustomMidele = sParty_Wilton3},
    },

    [TRAINER_WILTON_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("WILTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Wilton4),
        .party = {.ItemCustomMidele = sParty_Wilton4},
    },

    [TRAINER_WILTON_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("WILTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Wilton5),
        .party = {.ItemCustomMidele = sParty_Wilton5},
    },

    [TRAINER_WARREN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("WARREN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Warren),
        .party = {.ItemCustomMidele = sParty_Warren},
    },

    [TRAINER_MARY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("MARY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Mary),
        .party = {.ItemCustomMidele = sParty_Mary},
    },

    [TRAINER_ALEXIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("ALEXIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Alexia),
        .party = {.ItemCustomMidele = sParty_Alexia},
    },

    [TRAINER_JODY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("JODY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jody),
        .party = {.ItemCustomMidele = sParty_Jody},
    },

    [TRAINER_WENDY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("WENDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Wendy),
        .party = {.ItemCustomMidele = sParty_Wendy},
    },

    [TRAINER_KEIRA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("KEIRA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Keira),
        .party = {.ItemCustomMidele = sParty_Keira},
    },

    [TRAINER_BROOKE_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("BROOKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brooke1),
        .party = {.ItemCustomMidele = sParty_Brooke1},
    },

    [TRAINER_JENNIFER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("JENNIFER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jennifer),
        .party = {.ItemCustomMidele = sParty_Jennifer},
    },

    [TRAINER_HOPE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("HOPE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Hope),
        .party = {.ItemCustomMidele = sParty_Hope},
    },

    [TRAINER_SHANNON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("SHANNON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Shannon),
        .party = {.ItemCustomMidele = sParty_Shannon},
    },

    [TRAINER_MICHELLE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("MICHELLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Michelle),
        .party = {.ItemCustomMidele = sParty_Michelle},
    },

    [TRAINER_CAROLINE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("CAROLINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Caroline),
        .party = {.ItemCustomMidele = sParty_Caroline},
    },

    [TRAINER_JULIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("JULIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Julie),
        .party = {.ItemCustomMidele = sParty_Julie},
    },

    [TRAINER_BROOKE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("BROOKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brooke2),
        .party = {.ItemCustomMidele = sParty_Brooke2},
    },

    [TRAINER_BROOKE_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("BROOKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brooke3),
        .party = {.ItemCustomMidele = sParty_Brooke3},
    },

    [TRAINER_BROOKE_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("BROOKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brooke4),
        .party = {.ItemCustomMidele = sParty_Brooke4},
    },

    [TRAINER_BROOKE_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("BROOKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brooke5),
        .party = {.ItemCustomMidele = sParty_Brooke5},
    },

    [TRAINER_PATRICIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .trainerName = _("PATRICIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Patricia),
        .party = {.ItemCustomMidele = sParty_Patricia},
    },

    [TRAINER_KINDRA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .trainerName = _("KINDRA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kindra),
        .party = {.ItemCustomMidele = sParty_Kindra},
    },

    [TRAINER_TAMMY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .trainerName = _("TAMMY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tammy),
        .party = {.ItemCustomMidele = sParty_Tammy},
    },

    [TRAINER_VALERIE_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .trainerName = _("VALERIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Valerie1),
        .party = {.ItemCustomMidele = sParty_Valerie1},
    },

    [TRAINER_TASHA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .trainerName = _("TASHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tasha),
        .party = {.ItemCustomMidele = sParty_Tasha},
    },

    [TRAINER_VALERIE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .trainerName = _("VALERIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Valerie2),
        .party = {.ItemCustomMidele = sParty_Valerie2},
    },

    [TRAINER_VALERIE_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .trainerName = _("VALERIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Valerie3),
        .party = {.ItemCustomMidele = sParty_Valerie3},
    },

    [TRAINER_VALERIE_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .trainerName = _("VALERIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Valerie4),
        .party = {.ItemCustomMidele = sParty_Valerie4},
    },

    [TRAINER_VALERIE_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .trainerName = _("VALERIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Valerie5),
        .party = {.ItemCustomMidele = sParty_Valerie5},
    },

    [TRAINER_CINDY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("CINDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cindy1),
        .party = {.ItemCustomMidele = sParty_Cindy1},
    },

    [TRAINER_DAPHNE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("DAPHNE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Daphne),
        .party = {.ItemCustomMidele = sParty_Daphne},
    },

    [TRAINER_GRUNT_SPACE_CENTER_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntSpaceCenter2),
        .party = {.ItemCustomMidele = sParty_GruntSpaceCenter2},
    },

    [TRAINER_CINDY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("CINDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cindy2),
        .party = {.ItemCustomMidele = sParty_Cindy2},
    },

    [TRAINER_BRIANNA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("BRIANNA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brianna),
        .party = {.ItemCustomMidele = sParty_Brianna},
    },

    [TRAINER_NAOMI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("NAOMI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Naomi),
        .party = {.ItemCustomMidele = sParty_Naomi},
    },

    [TRAINER_CINDY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("CINDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cindy3),
        .party = {.ItemCustomMidele = sParty_Cindy3},
    },

    [TRAINER_CINDY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("CINDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cindy4),
        .party = {.ItemCustomMidele = sParty_Cindy4},
    },

    [TRAINER_CINDY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("CINDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cindy5),
        .party = {.ItemCustomMidele = sParty_Cindy5},
    },

    [TRAINER_CINDY_6] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("CINDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cindy6),
        .party = {.ItemCustomMidele = sParty_Cindy6},
    },

    [TRAINER_MELISSA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("MELISSA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Melissa),
        .party = {.ItemCustomMidele = sParty_Melissa},
    },

    [TRAINER_SHEILA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("SHEILA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sheila),
        .party = {.ItemCustomMidele = sParty_Sheila},
    },

    [TRAINER_SHIRLEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("SHIRLEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Shirley),
        .party = {.ItemCustomMidele = sParty_Shirley},
    },

    [TRAINER_JESSICA_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("JESSICA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jessica1),
        .party = {.ItemCustomMidele = sParty_Jessica1},
    },

    [TRAINER_CONNIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("CONNIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Connie),
        .party = {.ItemCustomMidele = sParty_Connie},
    },

    [TRAINER_BRIDGET] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("BRIDGET"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Bridget),
        .party = {.ItemCustomMidele = sParty_Bridget},
    },

    [TRAINER_OLIVIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("OLIVIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Olivia),
        .party = {.ItemCustomMidele = sParty_Olivia},
    },

    [TRAINER_TIFFANY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("TIFFANY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tiffany),
        .party = {.ItemCustomMidele = sParty_Tiffany},
    },

    [TRAINER_JESSICA_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("JESSICA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jessica2),
        .party = {.ItemCustomMidele = sParty_Jessica2},
    },

    [TRAINER_JESSICA_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("JESSICA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jessica3),
        .party = {.ItemCustomMidele = sParty_Jessica3},
    },

    [TRAINER_JESSICA_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("JESSICA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jessica4),
        .party = {.ItemCustomMidele = sParty_Jessica4},
    },

    [TRAINER_JESSICA_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("JESSICA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jessica5),
        .party = {.ItemCustomMidele = sParty_Jessica5},
    },

    [TRAINER_WINSTON_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RICH_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .trainerName = _("WINSTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Winston1),
        .party = {.ItemCustomMidele = sParty_Winston1},
    },

    [TRAINER_MOLLIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .trainerName = _("MOLLIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Mollie),
        .party = {.ItemCustomMidele = sParty_Mollie},
    },

    [TRAINER_GARRET] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RICH_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .trainerName = _("GARRET"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Garret),
        .party = {.ItemCustomMidele = sParty_Garret},
    },

    [TRAINER_WINSTON_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RICH_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .trainerName = _("WINSTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Winston2),
        .party = {.ItemCustomMidele = sParty_Winston2},
    },

    [TRAINER_WINSTON_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RICH_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .trainerName = _("WINSTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Winston3),
        .party = {.ItemCustomMidele = sParty_Winston3},
    },

    [TRAINER_WINSTON_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RICH_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .trainerName = _("WINSTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Winston4),
        .party = {.ItemCustomMidele = sParty_Winston4},
    },

    [TRAINER_WINSTON_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RICH_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .trainerName = _("WINSTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Winston5),
        .party = {.ItemCustomMidele = sParty_Winston5},
    },

    [TRAINER_STEVE_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("STEVE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Steve1),
        .party = {.ItemCustomMidele = sParty_Steve1},
    },

    [TRAINER_THALIA_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("THALIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Thalia1),
        .party = {.ItemCustomMidele = sParty_Thalia1},
    },

    [TRAINER_MARK] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("MARK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Mark),
        .party = {.ItemCustomMidele = sParty_Mark},
    },

    [TRAINER_GRUNT_MT_CHIMNEY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMtChimney1),
        .party = {.ItemCustomMidele = sParty_GruntMtChimney1},
    },

    [TRAINER_STEVE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("STEVE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Steve2),
        .party = {.ItemCustomMidele = sParty_Steve2},
    },

    [TRAINER_STEVE_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("STEVE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Steve3),
        .party = {.ItemCustomMidele = sParty_Steve3},
    },

    [TRAINER_STEVE_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("STEVE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Steve4),
        .party = {.ItemCustomMidele = sParty_Steve4},
    },

    [TRAINER_STEVE_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("STEVE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Steve5),
        .party = {.ItemCustomMidele = sParty_Steve5},
    },

    [TRAINER_LUIS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("LUIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Luis),
        .party = {.ItemCustomMidele = sParty_Luis},
    },

    [TRAINER_DOMINIK] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("DOMINIK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dominik),
        .party = {.ItemCustomMidele = sParty_Dominik},
    },

    [TRAINER_DOUGLAS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("DOUGLAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Douglas),
        .party = {.ItemCustomMidele = sParty_Douglas},
    },

    [TRAINER_DARRIN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("DARRIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Darrin),
        .party = {.ItemCustomMidele = sParty_Darrin},
    },

    [TRAINER_TONY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("TONY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tony1),
        .party = {.ItemCustomMidele = sParty_Tony1},
    },

    [TRAINER_JEROME] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("JEROME"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jerome),
        .party = {.ItemCustomMidele = sParty_Jerome},
    },

    [TRAINER_MATTHEW] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("MATTHEW"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Matthew),
        .party = {.ItemCustomMidele = sParty_Matthew},
    },

    [TRAINER_DAVID] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("DAVID"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_David),
        .party = {.ItemCustomMidele = sParty_David},
    },

    [TRAINER_SPENCER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("SPENCER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Spencer),
        .party = {.ItemCustomMidele = sParty_Spencer},
    },

    [TRAINER_ROLAND] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("ROLAND"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Roland),
        .party = {.ItemCustomMidele = sParty_Roland},
    },

    [TRAINER_NOLEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("NOLEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nolen),
        .party = {.ItemCustomMidele = sParty_Nolen},
    },

    [TRAINER_STAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("STAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Stan),
        .party = {.ItemCustomMidele = sParty_Stan},
    },

    [TRAINER_BARRY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("BARRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Barry),
        .party = {.ItemCustomMidele = sParty_Barry},
    },

    [TRAINER_DEAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("DEAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dean),
        .party = {.ItemCustomMidele = sParty_Dean},
    },

    [TRAINER_RODNEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("RODNEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Rodney),
        .party = {.ItemCustomMidele = sParty_Rodney},
    },

    [TRAINER_RICHARD] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("RICHARD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Richard),
        .party = {.ItemCustomMidele = sParty_Richard},
    },

    [TRAINER_HERMAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("HERMAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Herman),
        .party = {.ItemCustomMidele = sParty_Herman},
    },

    [TRAINER_SANTIAGO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("SANTIAGO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Santiago),
        .party = {.ItemCustomMidele = sParty_Santiago},
    },

    [TRAINER_GILBERT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("GILBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Gilbert),
        .party = {.ItemCustomMidele = sParty_Gilbert},
    },

    [TRAINER_FRANKLIN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("FRANKLIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Franklin),
        .party = {.ItemCustomMidele = sParty_Franklin},
    },

    [TRAINER_KEVIN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("KEVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kevin),
        .party = {.ItemCustomMidele = sParty_Kevin},
    },

    [TRAINER_JACK] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("JACK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jack),
        .party = {.ItemCustomMidele = sParty_Jack},
    },

    [TRAINER_LAEX] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_LAEX,
        .trainerName = _("LAEX"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Laex),
        .party = {.ItemCustomMidele = sParty_Laex},
    },

    [TRAINER_CHAD] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("CHAD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Chad),
        .party = {.ItemCustomMidele = sParty_Chad},
    },

    [TRAINER_TONY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("TONY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tony2),
        .party = {.ItemCustomMidele = sParty_Tony2},
    },

    [TRAINER_TONY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("TONY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tony3),
        .party = {.ItemCustomMidele = sParty_Tony3},
    },

    [TRAINER_TONY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("TONY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tony4),
        .party = {.ItemCustomMidele = sParty_Tony4},
    },

    [TRAINER_TONY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("TONY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tony5),
        .party = {.ItemCustomMidele = sParty_Tony5},
    },

    [TRAINER_TAKAO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("TAKAO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Takao),
        .party = {.ItemCustomMidele = sParty_Takao},
    },

    [TRAINER_HITOSHI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("HITOSHI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Hitoshi),
        .party = {.ItemCustomMidele = sParty_Hitoshi},
    },

    [TRAINER_KIYO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KIYO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kiyo),
        .party = {.ItemCustomMidele = sParty_Kiyo},
    },

    [TRAINER_KOICHI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KOICHI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Koichi),
        .party = {.ItemCustomMidele = sParty_Koichi},
    },

    [TRAINER_NOB_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("NOB"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nob1),
        .party = {.ItemCustomMidele = sParty_Nob1},
    },

    [TRAINER_NOB_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("NOB"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nob2),
        .party = {.ItemCustomMidele = sParty_Nob2},
    },

    [TRAINER_NOB_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("NOB"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nob3),
        .party = {.ItemCustomMidele = sParty_Nob3},
    },

    [TRAINER_NOB_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("NOB"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nob4),
        .party = {.ItemCustomMidele = sParty_Nob4},
    },

    [TRAINER_NOB_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("NOB"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nob5),
        .party = {.ItemCustomMidele = sParty_Nob5},
    },

    [TRAINER_YUJI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("YUJI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Yuji),
        .party = {.ItemCustomMidele = sParty_Yuji},
    },

    [TRAINER_DAISUKE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("DAISUKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Daisuke),
        .party = {.ItemCustomMidele = sParty_Daisuke},
    },

    [TRAINER_ATSUSHI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("ATSUSHI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Atsushi),
        .party = {.ItemCustomMidele = sParty_Atsushi},
    },

    [TRAINER_KIRK] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("KIRK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kirk),
        .party = {.ItemCustomMidele = sParty_Kirk},
    },

    [TRAINER_GRUNT_AQUA_HIDEOUT_7] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntAquaHideout7),
        .party = {.ItemCustomMidele = sParty_GruntAquaHideout7},
    },

    [TRAINER_GRUNT_AQUA_HIDEOUT_8] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntAquaHideout8),
        .party = {.ItemCustomMidele = sParty_GruntAquaHideout8},
    },

    [TRAINER_SHAWN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("SHAWN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Shawn),
        .party = {.ItemCustomMidele = sParty_Shawn},
    },

    [TRAINER_FERNANDO_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("FERNANDO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Fernando1),
        .party = {.ItemCustomMidele = sParty_Fernando1},
    },

    [TRAINER_DALTON_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("DALTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dalton1),
        .party = {.ItemCustomMidele = sParty_Dalton1},
    },

    [TRAINER_DALTON_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("DALTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dalton2),
        .party = {.ItemCustomMidele = sParty_Dalton2},
    },

    [TRAINER_DALTON_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("DALTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dalton3),
        .party = {.ItemCustomMidele = sParty_Dalton3},
    },

    [TRAINER_DALTON_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("DALTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dalton4),
        .party = {.ItemCustomMidele = sParty_Dalton4},
    },

    [TRAINER_DALTON_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("DALTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dalton5),
        .party = {.ItemCustomMidele = sParty_Dalton5},
    },

    [TRAINER_COLE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("COLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cole),
        .party = {.ItemCustomMidele = sParty_Cole},
    },

    [TRAINER_JEFF] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("JEFF"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jeff),
        .party = {.ItemCustomMidele = sParty_Jeff},
    },

    [TRAINER_AXLE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("AXLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Axle),
        .party = {.ItemCustomMidele = sParty_Axle},
    },

    [TRAINER_JACE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("JACE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jace),
        .party = {.ItemCustomMidele = sParty_Jace},
    },

    [TRAINER_KEEGAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("KEEGAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Keegan),
        .party = {.ItemCustomMidele = sParty_Keegan},
    },

    [TRAINER_BERNIE_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("BERNIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Bernie1),
        .party = {.ItemCustomMidele = sParty_Bernie1},
    },

    [TRAINER_BERNIE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("BERNIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Bernie2),
        .party = {.ItemCustomMidele = sParty_Bernie2},
    },

    [TRAINER_BERNIE_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("BERNIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Bernie3),
        .party = {.ItemCustomMidele = sParty_Bernie3},
    },

    [TRAINER_BERNIE_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("BERNIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Bernie4),
        .party = {.ItemCustomMidele = sParty_Bernie4},
    },

    [TRAINER_BERNIE_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("BERNIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Bernie5),
        .party = {.ItemCustomMidele = sParty_Bernie5},
    },

    [TRAINER_DREW] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("DREW"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Drew),
        .party = {.ItemCustomMidele = sParty_Drew},
    },

    [TRAINER_BEAU] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("BEAU"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Beau),
        .party = {.ItemCustomMidele = sParty_Beau},
    },

    [TRAINER_LARRY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("LARRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Larry),
        .party = {.ItemCustomMidele = sParty_Larry},
    },

    [TRAINER_SHANE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("SHANE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Shane),
        .party = {.ItemCustomMidele = sParty_Shane},
    },

    [TRAINER_JUSTIN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("JUSTIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Justin),
        .party = {.ItemCustomMidele = sParty_Justin},
    },

    [TRAINER_ETHAN_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ETHAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ethan1),
        .party = {.ItemCustomMidele = sParty_Ethan1},
    },

    [TRAINER_AUTUMN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("AUTUMN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Autumn),
        .party = {.ItemCustomMidele = sParty_Autumn},
    },

    [TRAINER_TRAVIS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TRAVIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Travis),
        .party = {.ItemCustomMidele = sParty_Travis},
    },

    [TRAINER_ETHAN_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ETHAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ethan2),
        .party = {.ItemCustomMidele = sParty_Ethan2},
    },

    [TRAINER_ETHAN_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ETHAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ethan3),
        .party = {.ItemCustomMidele = sParty_Ethan3},
    },

    [TRAINER_ETHAN_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ETHAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ethan4),
        .party = {.ItemCustomMidele = sParty_Ethan4},
    },

    [TRAINER_ETHAN_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ETHAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ethan5),
        .party = {.ItemCustomMidele = sParty_Ethan5},
    },

    [TRAINER_BRENT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("BRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brent),
        .party = {.ItemCustomMidele = sParty_Brent},
    },

    [TRAINER_DONALD] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("DONALD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Donald),
        .party = {.ItemCustomMidele = sParty_Donald},
    },

    [TRAINER_TAYLOR] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("TAYLOR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Taylor),
        .party = {.ItemCustomMidele = sParty_Taylor},
    },

    [TRAINER_JEFFREY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("JEFFREY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jeffrey1),
        .party = {.ItemCustomMidele = sParty_Jeffrey1},
    },

    [TRAINER_DEREK] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("DEREK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Derek),
        .party = {.ItemCustomMidele = sParty_Derek},
    },

    [TRAINER_JEFFREY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("JEFFREY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jeffrey2),
        .party = {.ItemCustomMidele = sParty_Jeffrey2},
    },

    [TRAINER_JEFFREY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("JEFFREY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jeffrey3),
        .party = {.ItemCustomMidele = sParty_Jeffrey3},
    },

    [TRAINER_JEFFREY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("JEFFREY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jeffrey4),
        .party = {.ItemCustomMidele = sParty_Jeffrey4},
    },

    [TRAINER_JEFFREY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("JEFFREY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jeffrey5),
        .party = {.ItemCustomMidele = sParty_Jeffrey5},
    },

    [TRAINER_EDWARD] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("EDWARD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Edward),
        .party = {.ItemCustomMidele = sParty_Edward},
    },

    [TRAINER_PRESTON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("PRESTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Preston),
        .party = {.ItemCustomMidele = sParty_Preston},
    },

    [TRAINER_VIRGIL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("VIRGIL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Virgil),
        .party = {.ItemCustomMidele = sParty_Virgil},
    },

    [TRAINER_BLAKE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("BLAKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Blake),
        .party = {.ItemCustomMidele = sParty_Blake},
    },

    [TRAINER_WILLIAM] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("WILLIAM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_William),
        .party = {.ItemCustomMidele = sParty_William},
    },

    [TRAINER_JOSHUA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("JOSHUA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Joshua),
        .party = {.ItemCustomMidele = sParty_Joshua},
    },

    [TRAINER_CAMERON_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("CAMERON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cameron1),
        .party = {.ItemCustomMidele = sParty_Cameron1},
    },

    [TRAINER_CAMERON_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("CAMERON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cameron2),
        .party = {.ItemCustomMidele = sParty_Cameron2},
    },

    [TRAINER_CAMERON_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("CAMERON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cameron3),
        .party = {.ItemCustomMidele = sParty_Cameron3},
    },

    [TRAINER_CAMERON_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("CAMERON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cameron4),
        .party = {.ItemCustomMidele = sParty_Cameron4},
    },

    [TRAINER_CAMERON_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("CAMERON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cameron5),
        .party = {.ItemCustomMidele = sParty_Cameron5},
    },

    [TRAINER_JACLYN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("JACLYN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jaclyn),
        .party = {.ItemCustomMidele = sParty_Jaclyn},
    },

    [TRAINER_HANNAH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("HANNAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Hannah),
        .party = {.ItemCustomMidele = sParty_Hannah},
    },

    [TRAINER_SAMANTHA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("SAMANTHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Samantha),
        .party = {.ItemCustomMidele = sParty_Samantha},
    },

    [TRAINER_MAURA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("MAURA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Maura),
        .party = {.ItemCustomMidele = sParty_Maura},
    },

    [TRAINER_KAYLA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("KAYLA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kayla),
        .party = {.ItemCustomMidele = sParty_Kayla},
    },

    [TRAINER_ALEXIS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("ALEXIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Alexis),
        .party = {.ItemCustomMidele = sParty_Alexis},
    },

    [TRAINER_JACKI_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("JACKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jacki1),
        .party = {.ItemCustomMidele = sParty_Jacki1},
    },

    [TRAINER_JACKI_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("JACKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jacki2),
        .party = {.ItemCustomMidele = sParty_Jacki2},
    },

    [TRAINER_JACKI_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("JACKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jacki3),
        .party = {.ItemCustomMidele = sParty_Jacki3},
    },

    [TRAINER_JACKI_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("JACKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jacki4),
        .party = {.ItemCustomMidele = sParty_Jacki4},
    },

    [TRAINER_JACKI_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("JACKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jacki5),
        .party = {.ItemCustomMidele = sParty_Jacki5},
    },

    [TRAINER_WALTER_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("WALTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Walter1),
        .party = {.ItemCustomMidele = sParty_Walter1},
    },

    [TRAINER_MICAH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("MICAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Micah),
        .party = {.ItemCustomMidele = sParty_Micah},
    },

    [TRAINER_THOMAS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("THOMAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Thomas),
        .party = {.ItemCustomMidele = sParty_Thomas},
    },

    [TRAINER_WALTER_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("WALTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Walter2),
        .party = {.ItemCustomMidele = sParty_Walter2},
    },

    [TRAINER_WALTER_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("WALTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Walter3),
        .party = {.ItemCustomMidele = sParty_Walter3},
    },

    [TRAINER_WALTER_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("WALTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Walter4),
        .party = {.ItemCustomMidele = sParty_Walter4},
    },

    [TRAINER_WALTER_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("WALTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Walter5),
        .party = {.ItemCustomMidele = sParty_Walter5},
    },

    [TRAINER_SIDNEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_SIDNEY,
        .trainerName = _("SIDNEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sidney),
        .party = {.ItemCustomMidele = sParty_Sidney},
    },

    [TRAINER_PHOEBE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_PHOEBE,
        .trainerName = _("PHOEBE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Phoebe),
        .party = {.ItemCustomMidele = sParty_Phoebe},
    },

    [TRAINER_GLACIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_GLACIA,
        .trainerName = _("GLACIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Glacia),
        .party = {.ItemCustomMidele = sParty_Glacia},
    },

    [TRAINER_DRAKE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_DRAKE,
        .trainerName = _("DRAKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Drake),
        .party = {.ItemCustomMidele = sParty_Drake},
    },

    [TRAINER_ROXANNE_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .trainerName = _("ROXANNE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Roxanne1),
        .party = {.ItemCustomMidele = sParty_Roxanne1},
    },

    [TRAINER_BRAWLY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .trainerName = _("BRAWLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brawly1),
        .party = {.ItemCustomMidele = sParty_Brawly1},
    },

    [TRAINER_WATTSON_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .trainerName = _("WATTSON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Wattson1),
        .party = {.ItemCustomMidele = sParty_Wattson1},
    },

    [TRAINER_FLANNERY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .trainerName = _("FLANNERY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Flannery1),
        .party = {.ItemCustomMidele = sParty_Flannery1},
    },

    [TRAINER_NORMAN_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .trainerName = _("NORMAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Norman1),
        .party = {.ItemCustomMidele = sParty_Norman1},
    },

    [TRAINER_WINONA_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .trainerName = _("WINONA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_RISKY,
        .partySize = ARRAY_COUNT(sParty_Winona1),
        .party = {.ItemCustomMidele = sParty_Winona1},
    },

    [TRAINER_TATE_AND_LIZA_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("TATE&LIZA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_TateAndLiza1),
        .party = {.ItemCustomMidele = sParty_TateAndLiza1},
    },

    [TRAINER_JUAN_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .trainerName = _("JUAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Juan1),
        .party = {.ItemCustomMidele = sParty_Juan1},
    },

    [TRAINER_JERRY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jerry1),
        .party = {.ItemCustomMidele = sParty_Jerry1},
    },

    [TRAINER_TED] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("TED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ted),
        .party = {.ItemCustomMidele = sParty_Ted},
    },

    [TRAINER_PAUL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("PAUL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Paul),
        .party = {.ItemCustomMidele = sParty_Paul},
    },

    [TRAINER_JERRY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jerry2),
        .party = {.ItemCustomMidele = sParty_Jerry2},
    },

    [TRAINER_JERRY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jerry3),
        .party = {.ItemCustomMidele = sParty_Jerry3},
    },

    [TRAINER_JERRY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jerry4),
        .party = {.ItemCustomMidele = sParty_Jerry4},
    },

    [TRAINER_JERRY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jerry5),
        .party = {.ItemCustomMidele = sParty_Jerry5},
    },

    [TRAINER_KAREN_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .trainerName = _("KAREN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Karen1),
        .party = {.ItemCustomMidele = sParty_Karen1},
    },

    [TRAINER_GEORGIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .trainerName = _("GEORGIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Georgia),
        .party = {.ItemCustomMidele = sParty_Georgia},
    },

    [TRAINER_KAREN_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .trainerName = _("KAREN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Karen2),
        .party = {.ItemCustomMidele = sParty_Karen2},
    },

    [TRAINER_KAREN_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .trainerName = _("KAREN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Karen3),
        .party = {.ItemCustomMidele = sParty_Karen3},
    },

    [TRAINER_KAREN_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .trainerName = _("KAREN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Karen4),
        .party = {.ItemCustomMidele = sParty_Karen4},
    },

    [TRAINER_KAREN_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .trainerName = _("KAREN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Karen5),
        .party = {.ItemCustomMidele = sParty_Karen5},
    },

    [TRAINER_KATE_AND_JOY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("KATE & JOY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_KateAndJoy),
        .party = {.ItemCustomMidele = sParty_KateAndJoy},
    },

    [TRAINER_ANNA_AND_MEG_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("ANNA & MEG"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_AnnaAndMeg1),
        .party = {.ItemCustomMidele = sParty_AnnaAndMeg1},
    },

    [TRAINER_ANNA_AND_MEG_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("ANNA & MEG"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_AnnaAndMeg2),
        .party = {.ItemCustomMidele = sParty_AnnaAndMeg2},
    },

    [TRAINER_ANNA_AND_MEG_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("ANNA & MEG"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_AnnaAndMeg3),
        .party = {.ItemCustomMidele = sParty_AnnaAndMeg3},
    },

    [TRAINER_ANNA_AND_MEG_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("ANNA & MEG"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_AnnaAndMeg4),
        .party = {.ItemCustomMidele = sParty_AnnaAndMeg4},
    },

    [TRAINER_ANNA_AND_MEG_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("ANNA & MEG"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_AnnaAndMeg5),
        .party = {.ItemCustomMidele = sParty_AnnaAndMeg5},
    },

    [TRAINER_VICTOR] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_WINSTRATE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("VICTOR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Victor),
        .party = {.ItemCustomMidele = sParty_Victor},
    },

    [TRAINER_MIGUEL_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("MIGUEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Miguel1),
        .party = {.ItemCustomMidele = sParty_Miguel1},
    },

    [TRAINER_COLTON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("COLTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Colton),
        .party = {.ItemCustomMidele = sParty_Colton},
    },

    [TRAINER_MIGUEL_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("MIGUEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Miguel2),
        .party = {.ItemCustomMidele = sParty_Miguel2},
    },

    [TRAINER_MIGUEL_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("MIGUEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Miguel3),
        .party = {.ItemCustomMidele = sParty_Miguel3},
    },

    [TRAINER_MIGUEL_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("MIGUEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Miguel4),
        .party = {.ItemCustomMidele = sParty_Miguel4},
    },

    [TRAINER_MIGUEL_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("MIGUEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Miguel5),
        .party = {.ItemCustomMidele = sParty_Miguel5},
    },

    [TRAINER_VICTORIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_WINSTRATE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("VICTORIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_Victoria),
        .party = {.ItemCustomMidele = sParty_Victoria},
    },

    [TRAINER_VANESSA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("VANESSA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Vanessa),
        .party = {.ItemCustomMidele = sParty_Vanessa},
    },

    [TRAINER_BETHANY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("BETHANY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Bethany),
        .party = {.ItemCustomMidele = sParty_Bethany},
    },

    [TRAINER_ISABEL_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("ISABEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isabel1),
        .party = {.ItemCustomMidele = sParty_Isabel1},
    },

    [TRAINER_ISABEL_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("ISABEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isabel2),
        .party = {.ItemCustomMidele = sParty_Isabel2},
    },

    [TRAINER_ISABEL_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("ISABEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isabel3),
        .party = {.ItemCustomMidele = sParty_Isabel3},
    },

    [TRAINER_ISABEL_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("ISABEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isabel4),
        .party = {.ItemCustomMidele = sParty_Isabel4},
    },

    [TRAINER_ISABEL_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("ISABEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isabel5),
        .party = {.ItemCustomMidele = sParty_Isabel5},
    },

    [TRAINER_TIMOTHY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .trainerName = _("TIMOTHY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Timothy1),
        .party = {.ItemCustomMidele = sParty_Timothy1},
    },

    [TRAINER_TIMOTHY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .trainerName = _("TIMOTHY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Timothy2),
        .party = {.ItemCustomMidele = sParty_Timothy2},
    },

    [TRAINER_TIMOTHY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .trainerName = _("TIMOTHY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Timothy3),
        .party = {.ItemCustomMidele = sParty_Timothy3},
    },

    [TRAINER_TIMOTHY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .trainerName = _("TIMOTHY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Timothy4),
        .party = {.ItemCustomMidele = sParty_Timothy4},
    },

    [TRAINER_TIMOTHY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .trainerName = _("TIMOTHY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Timothy5),
        .party = {.ItemCustomMidele = sParty_Timothy5},
    },

    [TRAINER_VICKY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_WINSTRATE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .trainerName = _("VICKY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Vicky),
        .party = {.ItemCustomMidele = sParty_Vicky},
    },

    [TRAINER_SHELBY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .trainerName = _("SHELBY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Shelby1),
        .party = {.ItemCustomMidele = sParty_Shelby1},
    },

    [TRAINER_SHELBY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .trainerName = _("SHELBY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Shelby2),
        .party = {.ItemCustomMidele = sParty_Shelby2},
    },

    [TRAINER_SHELBY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .trainerName = _("SHELBY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Shelby3),
        .party = {.ItemCustomMidele = sParty_Shelby3},
    },

    [TRAINER_SHELBY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .trainerName = _("SHELBY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Shelby4),
        .party = {.ItemCustomMidele = sParty_Shelby4},
    },

    [TRAINER_SHELBY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .trainerName = _("SHELBY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Shelby5),
        .party = {.ItemCustomMidele = sParty_Shelby5},
    },

    [TRAINER_CALVIN_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("CALVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Calvin1),
        .party = {.ItemCustomMidele = sParty_Calvin1},
    },

    [TRAINER_BILLY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("BILLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Billy),
        .party = {.ItemCustomMidele = sParty_Billy},
    },

    [TRAINER_JOSH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOSH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Josh),
        .party = {.ItemCustomMidele = sParty_Josh},
    },

    [TRAINER_TOMMY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("TOMMY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tommy),
        .party = {.ItemCustomMidele = sParty_Tommy},
    },

    [TRAINER_JOEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Joey),
        .party = {.ItemCustomMidele = sParty_Joey},
    },

    [TRAINER_BEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("BEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ben),
        .party = {.ItemCustomMidele = sParty_Ben},
    },

    [TRAINER_QUINCY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("QUINCY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Quincy),
        .party = {.ItemCustomMidele = sParty_Quincy},
    },

    [TRAINER_KATELYNN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("KATELYNN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Katelynn),
        .party = {.ItemCustomMidele = sParty_Katelynn},
    },

    [TRAINER_JAYLEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JAYLEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jaylen),
        .party = {.ItemCustomMidele = sParty_Jaylen},
    },

    [TRAINER_DILLON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("DILLON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dillon),
        .party = {.ItemCustomMidele = sParty_Dillon},
    },

    [TRAINER_CALVIN_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("CALVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Calvin2),
        .party = {.ItemCustomMidele = sParty_Calvin2},
    },

    [TRAINER_CALVIN_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("CALVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Calvin3),
        .party = {.ItemCustomMidele = sParty_Calvin3},
    },

    [TRAINER_CALVIN_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("CALVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Calvin4),
        .party = {.ItemCustomMidele = sParty_Calvin4},
    },

    [TRAINER_CALVIN_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("CALVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Calvin5),
        .party = {.ItemCustomMidele = sParty_Calvin5},
    },

    [TRAINER_EDDIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("EDDIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Eddie),
        .party = {.ItemCustomMidele = sParty_Eddie},
    },

    [TRAINER_ALLEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("ALLEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Allen),
        .party = {.ItemCustomMidele = sParty_Allen},
    },

    [TRAINER_TIMMY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("TIMMY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Timmy),
        .party = {.ItemCustomMidele = sParty_Timmy},
    },

    [TRAINER_WALLACE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CHAMPION,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CHAMPION_WALLACE,
        .trainerName = _("WALLACE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Wallace),
        .party = {.ItemCustomMidele = sParty_Wallace},
    },

    [TRAINER_ANDREW] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ANDREW"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Andrew),
        .party = {.ItemCustomMidele = sParty_Andrew},
    },

    [TRAINER_IVAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("IVAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ivan),
        .party = {.ItemCustomMidele = sParty_Ivan},
    },

    [TRAINER_CLAUDE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("CLAUDE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Claude),
        .party = {.ItemCustomMidele = sParty_Claude},
    },

    [TRAINER_ELLIOT_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ELLIOT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Elliot1),
        .party = {.ItemCustomMidele = sParty_Elliot1},
    },

    [TRAINER_NED] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("NED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ned),
        .party = {.ItemCustomMidele = sParty_Ned},
    },

    [TRAINER_DALE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("DALE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dale),
        .party = {.ItemCustomMidele = sParty_Dale},
    },

    [TRAINER_NOLAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("NOLAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nolan),
        .party = {.ItemCustomMidele = sParty_Nolan},
    },

    [TRAINER_BARNY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("BARNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Barny),
        .party = {.ItemCustomMidele = sParty_Barny},
    },

    [TRAINER_WADE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("WADE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Wade),
        .party = {.ItemCustomMidele = sParty_Wade},
    },

    [TRAINER_CARTER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("CARTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Carter),
        .party = {.ItemCustomMidele = sParty_Carter},
    },

    [TRAINER_ELLIOT_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ELLIOT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Elliot2),
        .party = {.ItemCustomMidele = sParty_Elliot2},
    },

    [TRAINER_ELLIOT_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ELLIOT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Elliot3),
        .party = {.ItemCustomMidele = sParty_Elliot3},
    },

    [TRAINER_ELLIOT_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ELLIOT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Elliot4),
        .party = {.ItemCustomMidele = sParty_Elliot4},
    },

    [TRAINER_ELLIOT_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ELLIOT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_Elliot5),
        .party = {.ItemCustomMidele = sParty_Elliot5},
    },

    [TRAINER_RONALD] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RONALD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ronald),
        .party = {.ItemCustomMidele = sParty_Ronald},
    },

    [TRAINER_JACOB] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("JACOB"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jacob),
        .party = {.ItemCustomMidele = sParty_Jacob},
    },

    [TRAINER_ANTHONY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("ANTHONY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Anthony),
        .party = {.ItemCustomMidele = sParty_Anthony},
    },

    [TRAINER_BENJAMIN_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("BENJAMIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Benjamin1),
        .party = {.ItemCustomMidele = sParty_Benjamin1},
    },

    [TRAINER_BENJAMIN_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("BENJAMIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Benjamin2),
        .party = {.ItemCustomMidele = sParty_Benjamin2},
    },

    [TRAINER_BENJAMIN_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("BENJAMIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Benjamin3),
        .party = {.ItemCustomMidele = sParty_Benjamin3},
    },

    [TRAINER_BENJAMIN_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("BENJAMIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Benjamin4),
        .party = {.ItemCustomMidele = sParty_Benjamin4},
    },

    [TRAINER_BENJAMIN_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("BENJAMIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Benjamin5),
        .party = {.ItemCustomMidele = sParty_Benjamin5},
    },

    [TRAINER_ABIGAIL_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .trainerName = _("ABIGAIL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Abigail1),
        .party = {.ItemCustomMidele = sParty_Abigail1},
    },

    [TRAINER_JASMINE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .trainerName = _("JASMINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jasmine),
        .party = {.ItemCustomMidele = sParty_Jasmine},
    },

    [TRAINER_ABIGAIL_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .trainerName = _("ABIGAIL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Abigail2),
        .party = {.ItemCustomMidele = sParty_Abigail2},
    },

    [TRAINER_ABIGAIL_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .trainerName = _("ABIGAIL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Abigail3),
        .party = {.ItemCustomMidele = sParty_Abigail3},
    },

    [TRAINER_ABIGAIL_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .trainerName = _("ABIGAIL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Abigail4),
        .party = {.ItemCustomMidele = sParty_Abigail4},
    },

    [TRAINER_ABIGAIL_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .trainerName = _("ABIGAIL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Abigail5),
        .party = {.ItemCustomMidele = sParty_Abigail5},
    },

    [TRAINER_DYLAN_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("DYLAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dylan1),
        .party = {.ItemCustomMidele = sParty_Dylan1},
    },

    [TRAINER_DYLAN_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("DYLAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dylan2),
        .party = {.ItemCustomMidele = sParty_Dylan2},
    },

    [TRAINER_DYLAN_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("DYLAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dylan3),
        .party = {.ItemCustomMidele = sParty_Dylan3},
    },

    [TRAINER_DYLAN_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("DYLAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dylan4),
        .party = {.ItemCustomMidele = sParty_Dylan4},
    },

    [TRAINER_DYLAN_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("DYLAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dylan5),
        .party = {.ItemCustomMidele = sParty_Dylan5},
    },

    [TRAINER_MARIA_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("MARIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Maria1),
        .party = {.ItemCustomMidele = sParty_Maria1},
    },

    [TRAINER_MARIA_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("MARIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Maria2),
        .party = {.ItemCustomMidele = sParty_Maria2},
    },

    [TRAINER_MARIA_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("MARIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Maria3),
        .party = {.ItemCustomMidele = sParty_Maria3},
    },

    [TRAINER_MARIA_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("MARIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Maria4),
        .party = {.ItemCustomMidele = sParty_Maria4},
    },

    [TRAINER_MARIA_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("MARIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Maria5),
        .party = {.ItemCustomMidele = sParty_Maria5},
    },

    [TRAINER_CAMDEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("CAMDEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Camden),
        .party = {.ItemCustomMidele = sParty_Camden},
    },

    [TRAINER_DEMETRIUS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("DEMETRIUS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Demetrius),
        .party = {.ItemCustomMidele = sParty_Demetrius},
    },

    [TRAINER_ISAIAH_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("ISAIAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isaiah1),
        .party = {.ItemCustomMidele = sParty_Isaiah1},
    },

    [TRAINER_PABLO_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("PABLO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Pablo1),
        .party = {.ItemCustomMidele = sParty_Pablo1},
    },

    [TRAINER_CHASE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("CHASE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Chase),
        .party = {.ItemCustomMidele = sParty_Chase},
    },

    [TRAINER_ISAIAH_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("ISAIAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isaiah2),
        .party = {.ItemCustomMidele = sParty_Isaiah2},
    },

    [TRAINER_ISAIAH_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("ISAIAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isaiah3),
        .party = {.ItemCustomMidele = sParty_Isaiah3},
    },

    [TRAINER_ISAIAH_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("ISAIAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isaiah4),
        .party = {.ItemCustomMidele = sParty_Isaiah4},
    },

    [TRAINER_ISAIAH_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("ISAIAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isaiah5),
        .party = {.ItemCustomMidele = sParty_Isaiah5},
    },

    [TRAINER_ISOBEL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("ISOBEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isobel),
        .party = {.ItemCustomMidele = sParty_Isobel},
    },

    [TRAINER_DONNY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("DONNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Donny),
        .party = {.ItemCustomMidele = sParty_Donny},
    },

    [TRAINER_TALIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("TALIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Talia),
        .party = {.ItemCustomMidele = sParty_Talia},
    },

    [TRAINER_KATELYN_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("KATELYN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Katelyn1),
        .party = {.ItemCustomMidele = sParty_Katelyn1},
    },

    [TRAINER_ALLISON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("ALLISON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Allison),
        .party = {.ItemCustomMidele = sParty_Allison},
    },

    [TRAINER_KATELYN_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("KATELYN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Katelyn2),
        .party = {.ItemCustomMidele = sParty_Katelyn2},
    },

    [TRAINER_KATELYN_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("KATELYN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Katelyn3),
        .party = {.ItemCustomMidele = sParty_Katelyn3},
    },

    [TRAINER_KATELYN_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("KATELYN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Katelyn4),
        .party = {.ItemCustomMidele = sParty_Katelyn4},
    },

    [TRAINER_KATELYN_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("KATELYN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Katelyn5),
        .party = {.ItemCustomMidele = sParty_Katelyn5},
    },

    [TRAINER_NICOLAS_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("NICOLAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nicolas1),
        .party = {.ItemCustomMidele = sParty_Nicolas1},
    },

    [TRAINER_NICOLAS_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("NICOLAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nicolas2),
        .party = {.ItemCustomMidele = sParty_Nicolas2},
    },

    [TRAINER_NICOLAS_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("NICOLAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nicolas3),
        .party = {.ItemCustomMidele = sParty_Nicolas3},
    },

    [TRAINER_NICOLAS_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("NICOLAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nicolas4),
        .party = {.ItemCustomMidele = sParty_Nicolas4},
    },

    [TRAINER_NICOLAS_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("NICOLAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nicolas5),
        .party = {.ItemCustomMidele = sParty_Nicolas5},
    },

    [TRAINER_AARON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("AARON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Aaron),
        .party = {.ItemCustomMidele = sParty_Aaron},
    },

    [TRAINER_PERRY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("PERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Perry),
        .party = {.ItemCustomMidele = sParty_Perry},
    },

    [TRAINER_HUGH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("HUGH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Hugh),
        .party = {.ItemCustomMidele = sParty_Hugh},
    },

    [TRAINER_PHIL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("PHIL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Phil),
        .party = {.ItemCustomMidele = sParty_Phil},
    },

    [TRAINER_JARED] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("JARED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jared),
        .party = {.ItemCustomMidele = sParty_Jared},
    },

    [TRAINER_HUMBERTO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("HUMBERTO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Humberto),
        .party = {.ItemCustomMidele = sParty_Humberto},
    },

    [TRAINER_PRESLEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("PRESLEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Presley),
        .party = {.ItemCustomMidele = sParty_Presley},
    },

    [TRAINER_EDWARDO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("EDWARDO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Edwardo),
        .party = {.ItemCustomMidele = sParty_Edwardo},
    },

    [TRAINER_COLIN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("COLIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Colin),
        .party = {.ItemCustomMidele = sParty_Colin},
    },

    [TRAINER_ROBERT_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Robert1),
        .party = {.ItemCustomMidele = sParty_Robert1},
    },

    [TRAINER_BENNY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("BENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Benny),
        .party = {.ItemCustomMidele = sParty_Benny},
    },

    [TRAINER_CHESTER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("CHESTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Chester),
        .party = {.ItemCustomMidele = sParty_Chester},
    },

    [TRAINER_ROBERT_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Robert2),
        .party = {.ItemCustomMidele = sParty_Robert2},
    },

    [TRAINER_ROBERT_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Robert3),
        .party = {.ItemCustomMidele = sParty_Robert3},
    },

    [TRAINER_ROBERT_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Robert4),
        .party = {.ItemCustomMidele = sParty_Robert4},
    },

    [TRAINER_ROBERT_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Robert5),
        .party = {.ItemCustomMidele = sParty_Robert5},
    },

    [TRAINER_ALEX] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ALEX"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Alex),
        .party = {.ItemCustomMidele = sParty_Alex},
    },

    [TRAINER_BECK] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("BECK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Beck),
        .party = {.ItemCustomMidele = sParty_Beck},
    },

    [TRAINER_YASU] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("YASU"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_Yasu),
        .party = {.ItemCustomMidele = sParty_Yasu},
    },

    [TRAINER_TAKASHI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("TAKASHI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_Takashi),
        .party = {.ItemCustomMidele = sParty_Takashi},
    },

    [TRAINER_DIANNE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("DIANNE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dianne),
        .party = {.ItemCustomMidele = sParty_Dianne},
    },

    [TRAINER_JANI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("JANI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jani),
        .party = {.ItemCustomMidele = sParty_Jani},
    },

    [TRAINER_LAO_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("LAO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lao1),
        .party = {.ItemCustomMidele = sParty_Lao1},
    },

    [TRAINER_LUNG] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("LUNG"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lung),
        .party = {.ItemCustomMidele = sParty_Lung},
    },

    [TRAINER_LAO_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("LAO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lao2),
        .party = {.ItemCustomMidele = sParty_Lao2},
    },

    [TRAINER_LAO_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("LAO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lao3),
        .party = {.ItemCustomMidele = sParty_Lao3},
    },

    [TRAINER_LAO_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("LAO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lao4),
        .party = {.ItemCustomMidele = sParty_Lao4},
    },

    [TRAINER_LAO_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("LAO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lao5),
        .party = {.ItemCustomMidele = sParty_Lao5},
    },

    [TRAINER_JOCELYN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("JOCELYN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jocelyn),
        .party = {.ItemCustomMidele = sParty_Jocelyn},
    },

    [TRAINER_LAURA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("LAURA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Laura),
        .party = {.ItemCustomMidele = sParty_Laura},
    },

    [TRAINER_CYNDY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("CYNDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cyndy1),
        .party = {.ItemCustomMidele = sParty_Cyndy1},
    },

    [TRAINER_CORA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("CORA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cora),
        .party = {.ItemCustomMidele = sParty_Cora},
    },

    [TRAINER_PAULA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("PAULA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Paula),
        .party = {.ItemCustomMidele = sParty_Paula},
    },

    [TRAINER_CYNDY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("CYNDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cyndy2),
        .party = {.ItemCustomMidele = sParty_Cyndy2},
    },

    [TRAINER_CYNDY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("CYNDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cyndy3),
        .party = {.ItemCustomMidele = sParty_Cyndy3},
    },

    [TRAINER_CYNDY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("CYNDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cyndy4),
        .party = {.ItemCustomMidele = sParty_Cyndy4},
    },

    [TRAINER_CYNDY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("CYNDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cyndy5),
        .party = {.ItemCustomMidele = sParty_Cyndy5},
    },

    [TRAINER_MADELINE_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("MADELINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Madeline1),
        .party = {.ItemCustomMidele = sParty_Madeline1},
    },

    [TRAINER_CLARISSA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("CLARISSA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Clarissa),
        .party = {.ItemCustomMidele = sParty_Clarissa},
    },

    [TRAINER_ANGELICA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("ANGELICA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Angelica),
        .party = {.ItemCustomMidele = sParty_Angelica},
    },

    [TRAINER_MADELINE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("MADELINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Madeline2),
        .party = {.ItemCustomMidele = sParty_Madeline2},
    },

    [TRAINER_MADELINE_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("MADELINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Madeline3),
        .party = {.ItemCustomMidele = sParty_Madeline3},
    },

    [TRAINER_MADELINE_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("MADELINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Madeline4),
        .party = {.ItemCustomMidele = sParty_Madeline4},
    },

    [TRAINER_MADELINE_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("MADELINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Madeline5),
        .party = {.ItemCustomMidele = sParty_Madeline5},
    },

    [TRAINER_BEVERLY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("BEVERLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Beverly),
        .party = {.ItemCustomMidele = sParty_Beverly},
    },

    [TRAINER_IMANI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("IMANI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Imani),
        .party = {.ItemCustomMidele = sParty_Imani},
    },

    [TRAINER_KYLA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("KYLA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kyla),
        .party = {.ItemCustomMidele = sParty_Kyla},
    },

    [TRAINER_DENISE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("DENISE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Denise),
        .party = {.ItemCustomMidele = sParty_Denise},
    },

    [TRAINER_BETH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("BETH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Beth),
        .party = {.ItemCustomMidele = sParty_Beth},
    },

    [TRAINER_TARA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("TARA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tara),
        .party = {.ItemCustomMidele = sParty_Tara},
    },

    [TRAINER_MISSY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("MISSY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Missy),
        .party = {.ItemCustomMidele = sParty_Missy},
    },

    [TRAINER_ALICE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("ALICE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Alice),
        .party = {.ItemCustomMidele = sParty_Alice},
    },

    [TRAINER_JENNY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("JENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jenny1),
        .party = {.ItemCustomMidele = sParty_Jenny1},
    },

    [TRAINER_GRACE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("GRACE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Grace),
        .party = {.ItemCustomMidele = sParty_Grace},
    },

    [TRAINER_TANYA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("TANYA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tanya),
        .party = {.ItemCustomMidele = sParty_Tanya},
    },

    [TRAINER_SHARON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("SHARON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sharon),
        .party = {.ItemCustomMidele = sParty_Sharon},
    },

    [TRAINER_NIKKI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("NIKKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nikki),
        .party = {.ItemCustomMidele = sParty_Nikki},
    },

    [TRAINER_BRENDA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("BRENDA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brenda),
        .party = {.ItemCustomMidele = sParty_Brenda},
    },

    [TRAINER_KATIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("KATIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Katie),
        .party = {.ItemCustomMidele = sParty_Katie},
    },

    [TRAINER_SUSIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("SUSIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Susie),
        .party = {.ItemCustomMidele = sParty_Susie},
    },

    [TRAINER_KARA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("KARA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kara),
        .party = {.ItemCustomMidele = sParty_Kara},
    },

    [TRAINER_DANA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("DANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dana),
        .party = {.ItemCustomMidele = sParty_Dana},
    },

    [TRAINER_SIENNA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("SIENNA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sienna),
        .party = {.ItemCustomMidele = sParty_Sienna},
    },

    [TRAINER_DEBRA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("DEBRA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Debra),
        .party = {.ItemCustomMidele = sParty_Debra},
    },

    [TRAINER_LINDA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("LINDA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Linda),
        .party = {.ItemCustomMidele = sParty_Linda},
    },

    [TRAINER_GERPH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCIENTISH,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTISH_FRLG,
        .trainerName = _("GERPH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Gerph),
        .party = {.ItemCustomMidele = sParty_Gerph},
    },

    [TRAINER_LAUREL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("LAUREL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Laurel),
        .party = {.ItemCustomMidele = sParty_Laurel},
    },

    [TRAINER_CARLEE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("CARLEE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Carlee),
        .party = {.ItemCustomMidele = sParty_Carlee},
    },

    [TRAINER_JENNY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("JENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jenny2),
        .party = {.ItemCustomMidele = sParty_Jenny2},
    },

    [TRAINER_JENNY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("JENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jenny3),
        .party = {.ItemCustomMidele = sParty_Jenny3},
    },

    [TRAINER_JENNY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("JENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jenny4),
        .party = {.ItemCustomMidele = sParty_Jenny4},
    },

    [TRAINER_JENNY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("JENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jenny5),
        .party = {.ItemCustomMidele = sParty_Jenny5},
    },

    [TRAINER_HEIDI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("HEIDI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Heidi),
        .party = {.ItemCustomMidele = sParty_Heidi},
    },

    [TRAINER_BECKY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("BECKY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Becky),
        .party = {.ItemCustomMidele = sParty_Becky},
    },

    [TRAINER_CAROL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CAROL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Carol),
        .party = {.ItemCustomMidele = sParty_Carol},
    },

    [TRAINER_NANCY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("NANCY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nancy),
        .party = {.ItemCustomMidele = sParty_Nancy},
    },

    [TRAINER_MARTHA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("MARTHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Martha),
        .party = {.ItemCustomMidele = sParty_Martha},
    },

    [TRAINER_DIANA_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("DIANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Diana1),
        .party = {.ItemCustomMidele = sParty_Diana1},
    },

    [TRAINER_CEDRIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("CEDRIC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cedric),
        .party = {.ItemCustomMidele = sParty_Cedric},
    },

    [TRAINER_IRENE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("IRENE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Irene),
        .party = {.ItemCustomMidele = sParty_Irene},
    },

    [TRAINER_DIANA_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("DIANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Diana2),
        .party = {.ItemCustomMidele = sParty_Diana2},
    },

    [TRAINER_DIANA_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("DIANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Diana3),
        .party = {.ItemCustomMidele = sParty_Diana3},
    },

    [TRAINER_DIANA_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("DIANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Diana4),
        .party = {.ItemCustomMidele = sParty_Diana4},
    },

    [TRAINER_DIANA_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("DIANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Diana5),
        .party = {.ItemCustomMidele = sParty_Diana5},
    },

    [TRAINER_AMY_AND_LIV_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("AMY & LIV"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_AmyAndLiv1),
        .party = {.ItemCustomMidele = sParty_AmyAndLiv1},
    },

    [TRAINER_AMY_AND_LIV_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("AMY & LIV"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_AmyAndLiv2),
        .party = {.ItemCustomMidele = sParty_AmyAndLiv2},
    },

    [TRAINER_GINA_AND_MIA_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("GINA & MIA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GinaAndMia1),
        .party = {.ItemCustomMidele = sParty_GinaAndMia1},
    },

    [TRAINER_MIU_AND_YUKI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("MIU & YUKI"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MiuAndYuki),
        .party = {.ItemCustomMidele = sParty_MiuAndYuki},
    },

    [TRAINER_MAXIE_AND_ARCHIE] = // MAXIE EQUIPO MAGMA BATALLA FINAL
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .trainerName = _("MAXIE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MaxieFinal),
        .party = {.ItemCustomMidele = sParty_MaxieFinal},
    },

    [TRAINER_PICHU7] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCIENTISH,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerPic = TRAINER_PIC_SCIENTISH_FRLG,
        .trainerName = _("PICHU7"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Pichu7),
        .party = {.ItemCustomMidele = sParty_Pichu7},
    },

    [TRAINER_AMY_AND_LIV_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("AMY & LIV"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_AmyAndLiv4),
        .party = {.ItemCustomMidele = sParty_AmyAndLiv4},
    },

    [TRAINER_AMY_AND_LIV_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("AMY & LIV"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_AmyAndLiv5),
        .party = {.ItemCustomMidele = sParty_AmyAndLiv5},
    },

    [TRAINER_AMY_AND_LIV_6] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("AMY & LIV"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_AmyAndLiv6),
        .party = {.ItemCustomMidele = sParty_AmyAndLiv6},
    },

    [TRAINER_HUEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HUEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Huey),
        .party = {.ItemCustomMidele = sParty_Huey},
    },

    [TRAINER_EDMOND] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("EDMOND"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Edmond),
        .party = {.ItemCustomMidele = sParty_Edmond},
    },

    [TRAINER_ERNEST_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("ERNEST"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ernest1),
        .party = {.ItemCustomMidele = sParty_Ernest1},
    },

    [TRAINER_DWAYNE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("DWAYNE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dwayne),
        .party = {.ItemCustomMidele = sParty_Dwayne},
    },

    [TRAINER_PHILLIP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("PHILLIP"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Phillip),
        .party = {.ItemCustomMidele = sParty_Phillip},
    },

    [TRAINER_LEONARD] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("LEONARD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Leonard),
        .party = {.ItemCustomMidele = sParty_Leonard},
    },

    [TRAINER_DUNCAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("DUNCAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Duncan),
        .party = {.ItemCustomMidele = sParty_Duncan},
    },

    [TRAINER_ERNEST_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("ERNEST"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ernest2),
        .party = {.ItemCustomMidele = sParty_Ernest2},
    },

    [TRAINER_ERNEST_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("ERNEST"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ernest3),
        .party = {.ItemCustomMidele = sParty_Ernest3},
    },

    [TRAINER_ERNEST_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("ERNEST"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ernest4),
        .party = {.ItemCustomMidele = sParty_Ernest4},
    },

    [TRAINER_ERNEST_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("ERNEST"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ernest5),
        .party = {.ItemCustomMidele = sParty_Ernest5},
    },

    [TRAINER_ELI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ELI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Eli),
        .party = {.ItemCustomMidele = sParty_Eli},
    },

    [TRAINER_ANNIKA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("ANNIKA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Annika),
        .party = {.ItemCustomMidele = sParty_Annika},
    },

    [TRAINER_JAZMYN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER_2,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("JAZMYN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jazmyn),
        .party = {.ItemCustomMidele = sParty_Jazmyn},
    },

    [TRAINER_JONAS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("JONAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jonas),
        .party = {.ItemCustomMidele = sParty_Jonas},
    },

    [TRAINER_KAYLEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("KAYLEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kayley),
        .party = {.ItemCustomMidele = sParty_Kayley},
    },

    [TRAINER_AURON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .trainerName = _("AURON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Auron),
        .party = {.ItemCustomMidele = sParty_Auron},
    },

    [TRAINER_KELVIN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("KELVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kelvin),
        .party = {.ItemCustomMidele = sParty_Kelvin},
    },

    [TRAINER_MARLEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("MARLEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Marley),
        .party = {.ItemCustomMidele = sParty_Marley},
    },

    [TRAINER_REYNA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("REYNA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Reyna),
        .party = {.ItemCustomMidele = sParty_Reyna},
    },

    [TRAINER_HUDSON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HUDSON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Hudson),
        .party = {.ItemCustomMidele = sParty_Hudson},
    },

    [TRAINER_CONOR] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .trainerName = _("CONOR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Conor),
        .party = {.ItemCustomMidele = sParty_Conor},
    },

    [TRAINER_EDWIN_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COLLECTOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("EDWIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Edwin1),
        .party = {.ItemCustomMidele = sParty_Edwin1},
    },

    [TRAINER_HECTOR] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COLLECTOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("HECTOR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Hector),
        .party = {.ItemCustomMidele = sParty_Hector},
    },

    [TRAINER_TABITHA_MOSSDEEP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_MAGMA_ADMIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN,
        .trainerName = _("TABITHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_TabithaMossdeep),
        .party = {.ItemCustomMidele = sParty_TabithaMossdeep},
    },

    [TRAINER_EDWIN_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COLLECTOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("EDWIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Edwin2),
        .party = {.ItemCustomMidele = sParty_Edwin2},
    },

    [TRAINER_EDWIN_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COLLECTOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("EDWIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Edwin3),
        .party = {.ItemCustomMidele = sParty_Edwin3},
    },

    [TRAINER_EDWIN_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COLLECTOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("EDWIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Edwin4),
        .party = {.ItemCustomMidele = sParty_Edwin4},
    },

    [TRAINER_EDWIN_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COLLECTOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("EDWIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Edwin5),
        .party = {.ItemCustomMidele = sParty_Edwin5},
    },

    [TRAINER_WALLY_VR_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = WALLYBATTLETHEME,
        .trainerPic = TRAINER_PIC_WALLY,
        .trainerName = _("WALLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_WallyVR1),
        .party = {.ItemCustomMidele = sParty_WallyVR1},
    },

    [TRAINER_BRENDAN_ROUTE_103_MUDKIP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_BrendanRoute103Mudkip),
        .party = {.ItemCustomMidele = sParty_BrendanRoute103Mudkip},
    },

    [TRAINER_BRENDAN_ROUTE_110_MUDKIP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BrendanRoute110Mudkip),
        .party = {.ItemCustomMidele = sParty_BrendanRoute110Mudkip},
    },

    [TRAINER_BRENDAN_ROUTE_119_MUDKIP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BrendanRoute119Mudkip),
        .party = {.ItemCustomMidele = sParty_BrendanRoute119Mudkip},
    },

    [TRAINER_BRENDAN_ROUTE_103_TREECKO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_BrendanRoute103Treecko),
        .party = {.ItemCustomMidele = sParty_BrendanRoute103Treecko},
    },

    [TRAINER_BRENDAN_ROUTE_110_TREECKO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BrendanRoute110Treecko),
        .party = {.ItemCustomMidele = sParty_BrendanRoute110Treecko},
    },

    [TRAINER_BRENDAN_ROUTE_119_TREECKO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BrendanRoute119Treecko),
        .party = {.ItemCustomMidele = sParty_BrendanRoute119Treecko},
    },

    [TRAINER_BRENDAN_ROUTE_103_TORCHIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_BrendanRoute103Torchic),
        .party = {.ItemCustomMidele = sParty_BrendanRoute103Torchic},
    },

    [TRAINER_BRENDAN_ROUTE_110_TORCHIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BrendanRoute110Torchic),
        .party = {.ItemCustomMidele = sParty_BrendanRoute110Torchic},
    },

    [TRAINER_BRENDAN_ROUTE_119_TORCHIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BrendanRoute119Torchic),
        .party = {.ItemCustomMidele = sParty_BrendanRoute119Torchic},
    },

    [TRAINER_MAY_ROUTE_103_MUDKIP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_MayRoute103Mudkip),
        .party = {.ItemCustomMidele = sParty_MayRoute103Mudkip},
    },

    [TRAINER_MAY_ROUTE_110_MUDKIP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MayRoute110Mudkip),
        .party = {.ItemCustomMidele = sParty_MayRoute110Mudkip},
    },

    [TRAINER_MAY_ROUTE_119_MUDKIP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MayRoute119Mudkip),
        .party = {.ItemCustomMidele = sParty_MayRoute119Mudkip},
    },

    [TRAINER_MAY_ROUTE_103_TREECKO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_MayRoute103Treecko),
        .party = {.ItemCustomMidele = sParty_MayRoute103Treecko},
    },

    [TRAINER_MAY_ROUTE_110_TREECKO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MayRoute110Treecko),
        .party = {.ItemCustomMidele = sParty_MayRoute110Treecko},
    },

    [TRAINER_MAY_ROUTE_119_TREECKO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MayRoute119Treecko),
        .party = {.ItemCustomMidele = sParty_MayRoute119Treecko},
    },

    [TRAINER_MAY_ROUTE_103_TORCHIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_MayRoute103Torchic),
        .party = {.ItemCustomMidele = sParty_MayRoute103Torchic},
    },

    [TRAINER_MAY_ROUTE_110_TORCHIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MayRoute110Torchic),
        .party = {.ItemCustomMidele = sParty_MayRoute110Torchic},
    },

    [TRAINER_MAY_ROUTE_119_TORCHIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MayRoute119Torchic),
        .party = {.ItemCustomMidele = sParty_MayRoute119Torchic},
    },

    [TRAINER_ISAAC_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .trainerName = _("ISAAC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isaac1),
        .party = {.ItemCustomMidele = sParty_Isaac1},
    },

    [TRAINER_DAVIS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("DAVIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Davis),
        .party = {.ItemCustomMidele = sParty_Davis},
    },

    [TRAINER_MITCHELL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("MITCHELL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Mitchell),
        .party = {.ItemCustomMidele = sParty_Mitchell},
    },

    [TRAINER_ISAAC_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .trainerName = _("ISAAC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isaac2),
        .party = {.ItemCustomMidele = sParty_Isaac2},
    },

    [TRAINER_ISAAC_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .trainerName = _("ISAAC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isaac3),
        .party = {.ItemCustomMidele = sParty_Isaac3},
    },

    [TRAINER_ISAAC_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .trainerName = _("ISAAC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isaac4),
        .party = {.ItemCustomMidele = sParty_Isaac4},
    },

    [TRAINER_ISAAC_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .trainerName = _("ISAAC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isaac5),
        .party = {.ItemCustomMidele = sParty_Isaac5},
    },

    [TRAINER_LYDIA_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("LYDIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lydia1),
        .party = {.ItemCustomMidele = sParty_Lydia1},
    },

    [TRAINER_HALLE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("HALLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Halle),
        .party = {.ItemCustomMidele = sParty_Halle},
    },

    [TRAINER_GARRISON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("GARRISON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Garrison),
        .party = {.ItemCustomMidele = sParty_Garrison},
    },

    [TRAINER_LYDIA_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("LYDIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lydia2),
        .party = {.ItemCustomMidele = sParty_Lydia2},
    },

    [TRAINER_LYDIA_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("LYDIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lydia3),
        .party = {.ItemCustomMidele = sParty_Lydia3},
    },

    [TRAINER_LYDIA_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("LYDIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lydia4),
        .party = {.ItemCustomMidele = sParty_Lydia4},
    },

    [TRAINER_LYDIA_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("LYDIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lydia5),
        .party = {.ItemCustomMidele = sParty_Lydia5},
    },

    [TRAINER_JACKSON_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("JACKSON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jackson1),
        .party = {.ItemCustomMidele = sParty_Jackson1},
    },

    [TRAINER_LORENZO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("LORENZO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lorenzo),
        .party = {.ItemCustomMidele = sParty_Lorenzo},
    },

    [TRAINER_SEBASTIAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("SEBASTIAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sebastian),
        .party = {.ItemCustomMidele = sParty_Sebastian},
    },

    [TRAINER_JACKSON_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("JACKSON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jackson2),
        .party = {.ItemCustomMidele = sParty_Jackson2},
    },

    [TRAINER_JACKSON_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("JACKSON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jackson3),
        .party = {.ItemCustomMidele = sParty_Jackson3},
    },

    [TRAINER_JACKSON_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("JACKSON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jackson4),
        .party = {.ItemCustomMidele = sParty_Jackson4},
    },

    [TRAINER_JACKSON_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("JACKSON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jackson5),
        .party = {.ItemCustomMidele = sParty_Jackson5},
    },

    [TRAINER_CATHERINE_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("CATHERINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Catherine1),
        .party = {.ItemCustomMidele = sParty_Catherine1},
    },

    [TRAINER_JENNA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("JENNA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jenna),
        .party = {.ItemCustomMidele = sParty_Jenna},
    },

    [TRAINER_SOPHIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("SOPHIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sophia),
        .party = {.ItemCustomMidele = sParty_Sophia},
    },

    [TRAINER_CATHERINE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("CATHERINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Catherine2),
        .party = {.ItemCustomMidele = sParty_Catherine2},
    },

    [TRAINER_CATHERINE_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("CATHERINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Catherine3),
        .party = {.ItemCustomMidele = sParty_Catherine3},
    },

    [TRAINER_CATHERINE_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("CATHERINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Catherine4),
        .party = {.ItemCustomMidele = sParty_Catherine4},
    },

    [TRAINER_CATHERINE_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("CATHERINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Catherine5),
        .party = {.ItemCustomMidele = sParty_Catherine5},
    },

    [TRAINER_JULIO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("JULIO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Julio),
        .party = {.ItemCustomMidele = sParty_Julio},
    },

    [TRAINER_GRUNT_SEAFLOOR_CAVERN_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntSeafloorCavern5),
        .party = {.ItemCustomMidele = sParty_GruntSeafloorCavern5},
    },

    [TRAINER_ARCHIE_AND_MAXIE] = // ARCHIE EQUIPO AQUA BATALLA FINAL
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_AQUA_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .trainerName = _("ARCHIE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_ArchieFinal),
        .party = {.ItemCustomMidele = sParty_ArchieFinal},
    },

    [TRAINER_GRUNT_MT_PYRE_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMtPyre4),
        .party = {.ItemCustomMidele = sParty_GruntMtPyre4},
    },

    [TRAINER_GRUNT_JAGGED_PASS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntJaggedPass),
        .party = {.ItemCustomMidele = sParty_GruntJaggedPass},
    },

    [TRAINER_MARC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("MARC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Marc),
        .party = {.ItemCustomMidele = sParty_Marc},
    },

    [TRAINER_BRENDEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("BRENDEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brenden),
        .party = {.ItemCustomMidele = sParty_Brenden},
    },

    [TRAINER_LILITH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("LILITH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lilith),
        .party = {.ItemCustomMidele = sParty_Lilith},
    },

    [TRAINER_CRISTIAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("CRISTIAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cristian),
        .party = {.ItemCustomMidele = sParty_Cristian},
    },

    [TRAINER_SYLVIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .trainerName = _("SYLVIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sylvia),
        .party = {.ItemCustomMidele = sParty_Sylvia},
    },

    [TRAINER_LEONARDO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("LEONARDO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Leonardo),
        .party = {.ItemCustomMidele = sParty_Leonardo},
    },

    [TRAINER_ATHENA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("ATHENA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Athena),
        .party = {.ItemCustomMidele = sParty_Athena},
    },

    [TRAINER_HARRISON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .trainerName = _("HARRISON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Harrison),
        .party = {.ItemCustomMidele = sParty_Harrison},
    },

    [TRAINER_GRUNT_MT_CHIMNEY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMtChimney2),
        .party = {.ItemCustomMidele = sParty_GruntMtChimney2},
    },

    [TRAINER_CLARENCE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("CLARENCE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Clarence),
        .party = {.ItemCustomMidele = sParty_Clarence},
    },

    [TRAINER_MELKOR] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .battleMusic = JENOVA,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("MELKOR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Melkor),
        .party = {.ItemCustomMidele = sParty_Melkor},
    },

    [TRAINER_NATE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("NATE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nate),
        .party = {.ItemCustomMidele = sParty_Nate},
    },

    [TRAINER_KATHLEEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .trainerName = _("KATHLEEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kathleen),
        .party = {.ItemCustomMidele = sParty_Kathleen},
    },

    [TRAINER_CLIFFORD] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("CLIFFORD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Clifford),
        .party = {.ItemCustomMidele = sParty_Clifford},
    },

    [TRAINER_NICHOLAS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("NICHOLAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Nicholas),
        .party = {.ItemCustomMidele = sParty_Nicholas},
    },

    [TRAINER_GRUNT_SPACE_CENTER_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntSpaceCenter3),
        .party = {.ItemCustomMidele = sParty_GruntSpaceCenter3},
    },

    [TRAINER_GRUNT_SPACE_CENTER_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntSpaceCenter4),
        .party = {.ItemCustomMidele = sParty_GruntSpaceCenter4},
    },

    [TRAINER_GRUNT_SPACE_CENTER_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntSpaceCenter5),
        .party = {.ItemCustomMidele = sParty_GruntSpaceCenter5},
    },

    [TRAINER_GRUNT_SPACE_CENTER_6] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntSpaceCenter6),
        .party = {.ItemCustomMidele = sParty_GruntSpaceCenter6},
    },

    [TRAINER_GRUNT_SPACE_CENTER_7] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntSpaceCenter7),
        .party = {.ItemCustomMidele = sParty_GruntSpaceCenter7},
    },

    [TRAINER_MACEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("MACEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Macey),
        .party = {.ItemCustomMidele = sParty_Macey},
    },

    [TRAINER_BRENDAN_RUSTBORO_TREECKO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BrendanRustboroTreecko),
        .party = {.ItemCustomMidele = sParty_BrendanRustboroTreecko},
    },

    [TRAINER_BRENDAN_RUSTBORO_MUDKIP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BrendanRustboroMudkip),
        .party = {.ItemCustomMidele = sParty_BrendanRustboroMudkip},
    },

    [TRAINER_PAXTON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .trainerName = _("PAXTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Paxton),
        .party = {.ItemCustomMidele = sParty_Paxton},
    },

    [TRAINER_ISABELLA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .trainerName = _("ISABELLA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isabella),
        .party = {.ItemCustomMidele = sParty_Isabella},
    },

    [TRAINER_GRUNT_WEATHER_INST_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntWeatherInst5),
        .party = {.ItemCustomMidele = sParty_GruntWeatherInst5},
    },

    [TRAINER_TABITHA_MT_CHIMNEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_MAGMA_ADMIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN,
        .trainerName = _("TABITHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_TabithaMtChimney),
        .party = {.ItemCustomMidele = sParty_TabithaMtChimney},
    },

    [TRAINER_JONATHAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("JONATHAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jonathan),
        .party = {.ItemCustomMidele = sParty_Jonathan},
    },

    [TRAINER_BRENDAN_RUSTBORO_TORCHIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BrendanRustboroTorchic),
        .party = {.ItemCustomMidele = sParty_BrendanRustboroTorchic},
    },

    [TRAINER_MAY_RUSTBORO_MUDKIP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MayRustboroMudkip),
        .party = {.ItemCustomMidele = sParty_MayRustboroMudkip},
    },

    [TRAINER_MAXIE_MAGMA_HIDEOUT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .trainerName = _("MAXIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MaxieMagmaHideout),
        .party = {.ItemCustomMidele = sParty_MaxieMagmaHideout},
    },

    [TRAINER_MAXIE_MT_CHIMNEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .trainerName = _("MAXIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MaxieMtChimney),
        .party = {.ItemCustomMidele = sParty_MaxieMtChimney},
    },

    [TRAINER_TIANA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("TIANA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tiana),
        .party = {.ItemCustomMidele = sParty_Tiana},
    },

    [TRAINER_HALEY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("HALEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Haley1),
        .party = {.ItemCustomMidele = sParty_Haley1},
    },

    [TRAINER_JANICE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("JANICE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Janice),
        .party = {.ItemCustomMidele = sParty_Janice},
    },

    [TRAINER_VIVI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_WINSTRATE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("VIVI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Vivi),
        .party = {.ItemCustomMidele = sParty_Vivi},
    },

    [TRAINER_HALEY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("HALEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Haley2),
        .party = {.ItemCustomMidele = sParty_Haley2},
    },

    [TRAINER_HALEY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("HALEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Haley3),
        .party = {.ItemCustomMidele = sParty_Haley3},
    },

    [TRAINER_HALEY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("HALEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Haley4),
        .party = {.ItemCustomMidele = sParty_Haley4},
    },

    [TRAINER_HALEY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("HALEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Haley5),
        .party = {.ItemCustomMidele = sParty_Haley5},
    },

    [TRAINER_SALLY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("SALLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sally),
        .party = {.ItemCustomMidele = sParty_Sally},
    },

    [TRAINER_ROBIN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("ROBIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Robin),
        .party = {.ItemCustomMidele = sParty_Robin},
    },

    [TRAINER_ANDREA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("ANDREA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Andrea),
        .party = {.ItemCustomMidele = sParty_Andrea},
    },

    [TRAINER_CRISSY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("CRISSY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Crissy),
        .party = {.ItemCustomMidele = sParty_Crissy},
    },

    [TRAINER_RICK] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("RICK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Rick),
        .party = {.ItemCustomMidele = sParty_Rick},
    },

    [TRAINER_LYLE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("LYLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lyle),
        .party = {.ItemCustomMidele = sParty_Lyle},
    },

    [TRAINER_JOSE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("JOSE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jose),
        .party = {.ItemCustomMidele = sParty_Jose},
    },

    [TRAINER_DOUG] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("DOUG"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Doug),
        .party = {.ItemCustomMidele = sParty_Doug},
    },

    [TRAINER_GREG] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("GREG"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Greg),
        .party = {.ItemCustomMidele = sParty_Greg},
    },

    [TRAINER_KENT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("KENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kent),
        .party = {.ItemCustomMidele = sParty_Kent},
    },

    [TRAINER_JAMES_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("JAMES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_James1),
        .party = {.ItemCustomMidele = sParty_James1},
    },

    [TRAINER_JAMES_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("JAMES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_James2),
        .party = {.ItemCustomMidele = sParty_James2},
    },

    [TRAINER_JAMES_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("JAMES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_James3),
        .party = {.ItemCustomMidele = sParty_James3},
    },

    [TRAINER_JAMES_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("JAMES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_James4),
        .party = {.ItemCustomMidele = sParty_James4},
    },

    [TRAINER_JAMES_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("JAMES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_James5),
        .party = {.ItemCustomMidele = sParty_James5},
    },

    [TRAINER_BRICE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("BRICE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brice),
        .party = {.ItemCustomMidele = sParty_Brice},
    },

    [TRAINER_TRENT_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("TRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Trent1),
        .party = {.ItemCustomMidele = sParty_Trent1},
    },

    [TRAINER_LENNY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("LENNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lenny),
        .party = {.ItemCustomMidele = sParty_Lenny},
    },

    [TRAINER_LUCAS_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("LUCAS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lucas1),
        .party = {.ItemCustomMidele = sParty_Lucas1},
    },

    [TRAINER_ALAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ALAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Alan),
        .party = {.ItemCustomMidele = sParty_Alan},
    },

    [TRAINER_CLARK] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("CLARK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Clark),
        .party = {.ItemCustomMidele = sParty_Clark},
    },

    [TRAINER_ERIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ERIC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Eric),
        .party = {.ItemCustomMidele = sParty_Eric},
    },

    [TRAINER_LORD] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("INFINIT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lord),
        .party = {.ItemCustomMidele = sParty_Lord},
    },

    [TRAINER_IZABE_MAYOR_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("GARM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_IzabeIsland_Mayor_2),
        .party = {.ItemCustomMidele = sParty_IzabeIsland_Mayor_2},
    },

    [TRAINER_MIKE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("MIKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Mike2),
        .party = {.ItemCustomMidele = sParty_Mike2},
    },

    [TRAINER_TRENT_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("TRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Trent2),
        .party = {.ItemCustomMidele = sParty_Trent2},
    },

    [TRAINER_TRENT_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("TRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Trent3),
        .party = {.ItemCustomMidele = sParty_Trent3},
    },

    [TRAINER_TRENT_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("TRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Trent4),
        .party = {.ItemCustomMidele = sParty_Trent4},
    },

    [TRAINER_TRENT_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("TRENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Trent5),
        .party = {.ItemCustomMidele = sParty_Trent5},
    },

    [TRAINER_DEZ_AND_LUKE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("DEZ & LUKE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_DezAndLuke),
        .party = {.ItemCustomMidele = sParty_DezAndLuke},
    },

    [TRAINER_LEA_AND_JED] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("LEA & JED"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_LeaAndJed),
        .party = {.ItemCustomMidele = sParty_LeaAndJed},
    },

    [TRAINER_KIRA_AND_DAN_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("KIRA & DAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_KiraAndDan1),
        .party = {.ItemCustomMidele = sParty_KiraAndDan1},
    },

    [TRAINER_KIRA_AND_DAN_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("KIRA & DAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_KiraAndDan2),
        .party = {.ItemCustomMidele = sParty_KiraAndDan2},
    },

    [TRAINER_KIRA_AND_DAN_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("KIRA & DAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_KiraAndDan3),
        .party = {.ItemCustomMidele = sParty_KiraAndDan3},
    },

    [TRAINER_KIRA_AND_DAN_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("KIRA & DAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_KiraAndDan4),
        .party = {.ItemCustomMidele = sParty_KiraAndDan4},
    },

    [TRAINER_KIRA_AND_DAN_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("KIRA & DAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_KiraAndDan5),
        .party = {.ItemCustomMidele = sParty_KiraAndDan5},
    },

    [TRAINER_JOHANNA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("JOHANNA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Johanna),
        .party = {.ItemCustomMidele = sParty_Johanna},
    },

    [TRAINER_GERALD] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("GERALD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Gerald),
        .party = {.ItemCustomMidele = sParty_Gerald},
    },

    [TRAINER_VIVIAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("VIVIAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Vivian),
        .party = {.ItemCustomMidele = sParty_Vivian},
    },

    [TRAINER_DANIELLE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("DANIELLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Danielle),
        .party = {.ItemCustomMidele = sParty_Danielle},
    },

    [TRAINER_HIDEO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("HIDEO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_Hideo),
        .party = {.ItemCustomMidele = sParty_Hideo},
    },

    [TRAINER_KEIGO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("KEIGO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_Keigo),
        .party = {.ItemCustomMidele = sParty_Keigo},
    },

    [TRAINER_RILEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("RILEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_Riley),
        .party = {.ItemCustomMidele = sParty_Riley},
    },

    [TRAINER_FLINT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("FLINT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Flint),
        .party = {.ItemCustomMidele = sParty_Flint},
    },

    [TRAINER_ASHLEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("ASHLEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ashley),
        .party = {.ItemCustomMidele = sParty_Ashley},
    },

    [TRAINER_WALLY_MAUVILLE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_WALLY,
        .trainerName = _("WALLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_WallyMauville),
        .party = {.ItemCustomMidele = sParty_WallyMauville},
    },

    [TRAINER_WALLY_VR_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = WALLYBATTLETHEME,
        .trainerPic = TRAINER_PIC_WALLY,
        .trainerName = _("WALLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_WallyVR2),
        .party = {.ItemCustomMidele = sParty_WallyVR2},
    },

    [TRAINER_WALLY_VR_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = WALLYBATTLETHEME,
        .trainerPic = TRAINER_PIC_WALLY,
        .trainerName = _("WALLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_WallyVR3),
        .party = {.ItemCustomMidele = sParty_WallyVR3},
    },

    [TRAINER_WALLY_VR_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = WALLYBATTLETHEME,
        .trainerPic = TRAINER_PIC_WALLY,
        .trainerName = _("WALLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_WallyVR4),
        .party = {.ItemCustomMidele = sParty_WallyVR4},
    },

    [TRAINER_WALLY_VR_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = WALLYBATTLETHEME,
        .trainerPic = TRAINER_PIC_WALLY,
        .trainerName = _("WALLY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_WallyVR5),
        .party = {.ItemCustomMidele = sParty_WallyVR5},
    },

    [TRAINER_BRENDAN_LILYCOVE_MUDKIP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BrendanLilycoveMudkip),
        .party = {.ItemCustomMidele = sParty_BrendanLilycoveMudkip},
    },

    [TRAINER_BRENDAN_LILYCOVE_TREECKO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BrendanLilycoveTreecko),
        .party = {.ItemCustomMidele = sParty_BrendanLilycoveTreecko},
    },

    [TRAINER_BRENDAN_LILYCOVE_TORCHIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BrendanLilycoveTorchic),
        .party = {.ItemCustomMidele = sParty_BrendanLilycoveTorchic},
    },

    [TRAINER_MAY_LILYCOVE_MUDKIP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MayLilycoveMudkip),
        .party = {.ItemCustomMidele = sParty_MayLilycoveMudkip},
    },

    [TRAINER_MAY_LILYCOVE_TREECKO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MayLilycoveTreecko),
        .party = {.ItemCustomMidele = sParty_MayLilycoveTreecko},
    },

    [TRAINER_MAY_LILYCOVE_TORCHIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MayLilycoveTorchic),
        .party = {.ItemCustomMidele = sParty_MayLilycoveTorchic},
    },

    [TRAINER_JONAH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("JONAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jonah),
        .party = {.ItemCustomMidele = sParty_Jonah},
    },

    [TRAINER_HENRY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("HENRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Henry),
        .party = {.ItemCustomMidele = sParty_Henry},
    },

    [TRAINER_ROGER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ROGER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Roger),
        .party = {.ItemCustomMidele = sParty_Roger},
    },

    [TRAINER_ALEXA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("ALEXA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Alexa),
        .party = {.ItemCustomMidele = sParty_Alexa},
    },

    [TRAINER_RUBEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("RUBEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ruben),
        .party = {.ItemCustomMidele = sParty_Ruben},
    },

    [TRAINER_KOJI_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KOJI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Koji1),
        .party = {.ItemCustomMidele = sParty_Koji1},
    },

    [TRAINER_WAYNE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("WAYNE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Wayne),
        .party = {.ItemCustomMidele = sParty_Wayne},
    },

    [TRAINER_AIDAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("AIDAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Aidan),
        .party = {.ItemCustomMidele = sParty_Aidan},
    },

    [TRAINER_REED] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("REED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Reed),
        .party = {.ItemCustomMidele = sParty_Reed},
    },

    [TRAINER_TISHA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("TISHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tisha),
        .party = {.ItemCustomMidele = sParty_Tisha},
    },

    [TRAINER_TORI_AND_TIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("TORI & TIA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_ToriAndTia),
        .party = {.ItemCustomMidele = sParty_ToriAndTia},
    },

    [TRAINER_KIM_AND_IRIS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("KIM & IRIS"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_KimAndIris),
        .party = {.ItemCustomMidele = sParty_KimAndIris},
    },

    [TRAINER_TYRA_AND_IVY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .trainerName = _("TYRA & IVY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_TyraAndIvy),
        .party = {.ItemCustomMidele = sParty_TyraAndIvy},
    },

    [TRAINER_MEL_AND_PAUL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("MEL & PAUL"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MelAndPaul),
        .party = {.ItemCustomMidele = sParty_MelAndPaul},
    },

    [TRAINER_JOHN_AND_JAY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .trainerName = _("JOHN & JAY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_JohnAndJay1),
        .party = {.ItemCustomMidele = sParty_JohnAndJay1},
    },

    [TRAINER_JOHN_AND_JAY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .trainerName = _("JOHN & JAY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_JohnAndJay2),
        .party = {.ItemCustomMidele = sParty_JohnAndJay2},
    },

    [TRAINER_JOHN_AND_JAY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .trainerName = _("JOHN & JAY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_JohnAndJay3),
        .party = {.ItemCustomMidele = sParty_JohnAndJay3},
    },

    [TRAINER_JOHN_AND_JAY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .trainerName = _("JOHN & JAY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_JohnAndJay4),
        .party = {.ItemCustomMidele = sParty_JohnAndJay4},
    },

    [TRAINER_JOHN_AND_JAY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .trainerName = _("JOHN & JAY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_JohnAndJay5),
        .party = {.ItemCustomMidele = sParty_JohnAndJay5},
    },

    [TRAINER_RELI_AND_IAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("RELI & IAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_ReliAndIan),
        .party = {.ItemCustomMidele = sParty_ReliAndIan},
    },

    [TRAINER_LILA_AND_ROY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LILA & ROY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_LilaAndRoy1),
        .party = {.ItemCustomMidele = sParty_LilaAndRoy1},
    },

    [TRAINER_LILA_AND_ROY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LILA & ROY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_LilaAndRoy2),
        .party = {.ItemCustomMidele = sParty_LilaAndRoy2},
    },

    [TRAINER_LILA_AND_ROY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LILA & ROY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_LilaAndRoy3),
        .party = {.ItemCustomMidele = sParty_LilaAndRoy3},
    },

    [TRAINER_LILA_AND_ROY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LILA & ROY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_LilaAndRoy4),
        .party = {.ItemCustomMidele = sParty_LilaAndRoy4},
    },

    [TRAINER_LILA_AND_ROY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LILA & ROY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_LilaAndRoy5),
        .party = {.ItemCustomMidele = sParty_LilaAndRoy5},
    },

    [TRAINER_LISA_AND_RAY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LISA & RAY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_LisaAndRay),
        .party = {.ItemCustomMidele = sParty_LisaAndRay},
    },

    [TRAINER_CHRIS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("CHRIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Chris),
        .party = {.ItemCustomMidele = sParty_Chris},
    },

    [TRAINER_DAWSON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RICH_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .trainerName = _("DAWSON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dawson),
        .party = {.ItemCustomMidele = sParty_Dawson},
    },

    [TRAINER_SARAH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("SARAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sarah),
        .party = {.ItemCustomMidele = sParty_Sarah},
    },

    [TRAINER_DARIAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("DARIAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Darian),
        .party = {.ItemCustomMidele = sParty_Darian},
    },

    [TRAINER_HAILEY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("HAILEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Hailey),
        .party = {.ItemCustomMidele = sParty_Hailey},
    },

    [TRAINER_CHANDLER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .trainerName = _("CHANDLER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Chandler),
        .party = {.ItemCustomMidele = sParty_Chandler},
    },

    [TRAINER_KALEB] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("KALEB"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kaleb),
        .party = {.ItemCustomMidele = sParty_Kaleb},
    },

    [TRAINER_JOSEPH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("JOSEPH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Joseph),
        .party = {.ItemCustomMidele = sParty_Joseph},
    },

    [TRAINER_ALYSSA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .trainerName = _("ALYSSA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Alyssa),
        .party = {.ItemCustomMidele = sParty_Alyssa},
    },

    [TRAINER_MARCOS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("MARCOS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Marcos),
        .party = {.ItemCustomMidele = sParty_Marcos},
    },

    [TRAINER_RHETT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("RHETT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Rhett),
        .party = {.ItemCustomMidele = sParty_Rhett},
    },

    [TRAINER_TYRON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TYRON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tyron),
        .party = {.ItemCustomMidele = sParty_Tyron},
    },

    [TRAINER_CELINA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("CELINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Celina),
        .party = {.ItemCustomMidele = sParty_Celina},
    },

    [TRAINER_BIANCA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("BIANCA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Bianca),
        .party = {.ItemCustomMidele = sParty_Bianca},
    },

    [TRAINER_HAYDEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("HAYDEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Hayden),
        .party = {.ItemCustomMidele = sParty_Hayden},
    },

    [TRAINER_SOPHIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("SOPHIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sophie),
        .party = {.ItemCustomMidele = sParty_Sophie},
    },

    [TRAINER_COBY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("COBY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Coby),
        .party = {.ItemCustomMidele = sParty_Coby},
    },

    [TRAINER_LAWRENCE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("LAWRENCE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lawrence),
        .party = {.ItemCustomMidele = sParty_Lawrence},
    },

    [TRAINER_WYATT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("WYATT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Wyatt),
        .party = {.ItemCustomMidele = sParty_Wyatt},
    },

    [TRAINER_ANGELINA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("ANGELINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Angelina),
        .party = {.ItemCustomMidele = sParty_Angelina},
    },

    [TRAINER_KAI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("KAI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kai),
        .party = {.ItemCustomMidele = sParty_Kai},
    },

    [TRAINER_CHARLOTTE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CHARLOTTE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Charlotte),
        .party = {.ItemCustomMidele = sParty_Charlotte},
    },

    [TRAINER_DEANDRE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("DEANDRE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Deandre),
        .party = {.ItemCustomMidele = sParty_Deandre},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout1),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout1},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout2),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout2},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout3),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout3},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout4),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout4},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout5),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout5},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_6] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout6),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout6},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_7] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout7),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout7},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_8] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout8),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout8},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_9] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout9),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout9},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_10] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout10),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout10},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_11] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout11),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout11},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_12] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout12),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout12},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_13] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout13),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout13},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_14] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout14),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout14},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_15] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout15),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout15},
    },

    [TRAINER_GRUNT_MAGMA_HIDEOUT_16] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_GruntMagmaHideout16),
        .party = {.ItemCustomMidele = sParty_GruntMagmaHideout16},
    },

    [TRAINER_TABITHA_MAGMA_HIDEOUT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_MAGMA_ADMIN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN,
        .trainerName = _("TABITHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_TabithaMagmaHideout),
        .party = {.ItemCustomMidele = sParty_TabithaMagmaHideout},
    },

    [TRAINER_DARCY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("DARCY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Darcy),
        .party = {.ItemCustomMidele = sParty_Darcy},
    },

    [TRAINER_MAXIE_MOSSDEEP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .trainerName = _("MAXIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MaxieMossdeep),
        .party = {.ItemCustomMidele = sParty_MaxieMossdeep},
    },

    [TRAINER_PETE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("PETE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Pete),
        .party = {.ItemCustomMidele = sParty_Pete},
    },

    [TRAINER_ISABELLE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("ISABELLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Isabelle),
        .party = {.ItemCustomMidele = sParty_Isabelle},
    },

    [TRAINER_ANDRES_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("ANDRES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Andres1),
        .party = {.ItemCustomMidele = sParty_Andres1},
    },

    [TRAINER_JOSUE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("JOSUE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Josue),
        .party = {.ItemCustomMidele = sParty_Josue},
    },

    [TRAINER_CAMRON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("CAMRON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Camron),
        .party = {.ItemCustomMidele = sParty_Camron},
    },

    [TRAINER_CORY_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("CORY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cory1),
        .party = {.ItemCustomMidele = sParty_Cory1},
    },

    [TRAINER_CAROLINA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("CAROLINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Carolina),
        .party = {.ItemCustomMidele = sParty_Carolina},
    },

    [TRAINER_ELIJAH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ELIJAH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Elijah),
        .party = {.ItemCustomMidele = sParty_Elijah},
    },

    [TRAINER_CELIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CELIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Celia),
        .party = {.ItemCustomMidele = sParty_Celia},
    },

    [TRAINER_BRYAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("BRYAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Bryan),
        .party = {.ItemCustomMidele = sParty_Bryan},
    },

    [TRAINER_BRANDEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("BRANDEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Branden),
        .party = {.ItemCustomMidele = sParty_Branden},
    },

    [TRAINER_BRYANT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("BRYANT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Bryant),
        .party = {.ItemCustomMidele = sParty_Bryant},
    },

    [TRAINER_SHAYLA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("SHAYLA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Shayla),
        .party = {.ItemCustomMidele = sParty_Shayla},
    },

    [TRAINER_KYRA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("KYRA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kyra),
        .party = {.ItemCustomMidele = sParty_Kyra},
    },

    [TRAINER_JAIDEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("JAIDEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Jaiden),
        .party = {.ItemCustomMidele = sParty_Jaiden},
    },

    [TRAINER_ALIX] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("ALIX"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Alix),
        .party = {.ItemCustomMidele = sParty_Alix},
    },

    [TRAINER_HELENE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("HELENE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Helene),
        .party = {.ItemCustomMidele = sParty_Helene},
    },

    [TRAINER_MARLENE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("MARLENE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Marlene),
        .party = {.ItemCustomMidele = sParty_Marlene},
    },

    [TRAINER_DEVAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("DEVAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Devan),
        .party = {.ItemCustomMidele = sParty_Devan},
    },

    [TRAINER_JOHNSON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOHNSON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Johnson),
        .party = {.ItemCustomMidele = sParty_Johnson},
    },

    [TRAINER_MELINA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .trainerName = _("MELINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Melina),
        .party = {.ItemCustomMidele = sParty_Melina},
    },

    [TRAINER_BRANDI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("BRANDI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brandi),
        .party = {.ItemCustomMidele = sParty_Brandi},
    },

    [TRAINER_AISHA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("AISHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Aisha),
        .party = {.ItemCustomMidele = sParty_Aisha},
    },

    [TRAINER_MAKAYLA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_EXPERT,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .trainerName = _("MAKAYLA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Makayla),
        .party = {.ItemCustomMidele = sParty_Makayla},
    },

    [TRAINER_FABIAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("FABIAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Fabian),
        .party = {.ItemCustomMidele = sParty_Fabian},
    },

    [TRAINER_DAYTON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_KINDLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("DAYTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dayton),
        .party = {.ItemCustomMidele = sParty_Dayton},
    },

    [TRAINER_RACHEL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .trainerName = _("RACHEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Rachel),
        .party = {.ItemCustomMidele = sParty_Rachel},
    },

    [TRAINER_LEONEL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("LEONEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Leonel),
        .party = {.ItemCustomMidele = sParty_Leonel},
    },

    [TRAINER_CALLIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .trainerName = _("CALLIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Callie),
        .party = {.ItemCustomMidele = sParty_Callie},
    },

    [TRAINER_CALE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("CALE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cale),
        .party = {.ItemCustomMidele = sParty_Cale},
    },

    [TRAINER_MYLES] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .trainerName = _("MYLES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Myles),
        .party = {.ItemCustomMidele = sParty_Myles},
    },

    [TRAINER_PAT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("PAT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Pat),
        .party = {.ItemCustomMidele = sParty_Pat},
    },

    [TRAINER_CRISTIN_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("CRISTIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cristin1),
        .party = {.ItemCustomMidele = sParty_Cristin1},
    },

    [TRAINER_MAY_RUSTBORO_TREECKO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MayRustboroTreecko),
        .party = {.ItemCustomMidele = sParty_MayRustboroTreecko},
    },

    [TRAINER_MAY_RUSTBORO_TORCHIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MayRustboroTorchic),
        .party = {.ItemCustomMidele = sParty_MayRustboroTorchic},
    },

    [TRAINER_ROXANNE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .trainerName = _("ROXANNE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Roxanne2),
        .party = {.ItemCustomMidele = sParty_Roxanne2},
    },

    [TRAINER_ROXANNE_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .trainerName = _("ROXANNE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Roxanne3),
        .party = {.ItemCustomMidele = sParty_Roxanne3},
    },

    [TRAINER_ROXANNE_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .trainerName = _("ROXANNE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Roxanne4),
        .party = {.ItemCustomMidele = sParty_Roxanne4},
    },

    [TRAINER_ROXANNE_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .trainerName = _("ROXANNE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Roxanne5),
        .party = {.ItemCustomMidele = sParty_Roxanne5},
    },

    [TRAINER_BRAWLY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .trainerName = _("BRAWLY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brawly2),
        .party = {.ItemCustomMidele = sParty_Brawly2},
    },

    [TRAINER_BRAWLY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .trainerName = _("BRAWLY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brawly3),
        .party = {.ItemCustomMidele = sParty_Brawly3},
    },

    [TRAINER_BRAWLY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .trainerName = _("BRAWLY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brawly4),
        .party = {.ItemCustomMidele = sParty_Brawly4},
    },

    [TRAINER_BRAWLY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .trainerName = _("BRAWLY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brawly5),
        .party = {.ItemCustomMidele = sParty_Brawly5},
    },

    [TRAINER_WATTSON_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .trainerName = _("WATTSON"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Wattson2),
        .party = {.ItemCustomMidele = sParty_Wattson2},
    },

    [TRAINER_WATTSON_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .trainerName = _("WATTSON"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Wattson3),
        .party = {.ItemCustomMidele = sParty_Wattson3},
    },

    [TRAINER_WATTSON_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .trainerName = _("WATTSON"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Wattson4),
        .party = {.ItemCustomMidele = sParty_Wattson4},
    },
	
    [TRAINER_FRANTASY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("FRANTASY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Frantasy),
        .party = {.ItemCustomMidele = sParty_Frantasy},
    },

    [TRAINER_FLANNERY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .trainerName = _("FLANNERY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Flannery2),
        .party = {.ItemCustomMidele = sParty_Flannery2},
    },

    [TRAINER_FLANNERY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .trainerName = _("FLANNERY"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Flannery3),
        .party = {.ItemCustomMidele = sParty_Flannery3},
    },

    [TRAINER_PAJAROESPIN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("PAJAROESPIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Pajaroespin),
        .party = {.ItemCustomMidele = sParty_Pajaroespin},
    },
    [TRAINER_GATOLETE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("GATOLETE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Gatolete),
        .party = {.ItemCustomMidele = sParty_Gatolete},
    },

    [TRAINER_NORMAN_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .trainerName = _("NORMAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Norman2),
        .party = {.ItemCustomMidele = sParty_Norman2},
    },

    [TRAINER_NORMAN_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .trainerName = _("NORMAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Norman3),
        .party = {.ItemCustomMidele = sParty_Norman3},
    },

    [TRAINER_NORMAN_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .trainerName = _("NORMAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Norman4),
        .party = {.ItemCustomMidele = sParty_Norman4},
    },

    [TRAINER_NORMAN_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .trainerName = _("NORMAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Norman5),
        .party = {.ItemCustomMidele = sParty_Norman5},
    },

    [TRAINER_WINONA_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .trainerName = _("WINONA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_RISKY,
        .partySize = ARRAY_COUNT(sParty_Winona2),
        .party = {.ItemCustomMidele = sParty_Winona2},
    },

    [TRAINER_WINONA_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .trainerName = _("WINONA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_RISKY,
        .partySize = ARRAY_COUNT(sParty_Winona3),
        .party = {.ItemCustomMidele = sParty_Winona3},
    },

    [TRAINER_NEUER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("NEUER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Neuer),
        .party = {.ItemCustomMidele = sParty_Neuer},
    },
    [TRAINER_KRAFT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("KRAFT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kraft),
        .party = {.ItemCustomMidele = sParty_Kraft},
    },

    [TRAINER_TATE_AND_LIZA_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("TATE&LIZA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_TateAndLiza2),
        .party = {.ItemCustomMidele = sParty_TateAndLiza2},
    },

    [TRAINER_TATE_AND_LIZA_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("TATE&LIZA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_TateAndLiza3),
        .party = {.ItemCustomMidele = sParty_TateAndLiza3},
    },

    [TRAINER_TATE_AND_LIZA_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("TATE&LIZA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_TateAndLiza4),
        .party = {.ItemCustomMidele = sParty_TateAndLiza4},
    },

    [TRAINER_TATE_AND_LIZA_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("TATE&LIZA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_TateAndLiza5),
        .party = {.ItemCustomMidele = sParty_TateAndLiza5},
    },

    [TRAINER_JUAN_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .trainerName = _("JUAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Juan2),
        .party = {.ItemCustomMidele = sParty_Juan2},
    },

    [TRAINER_JUAN_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .trainerName = _("JUAN"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Juan3),
        .party = {.ItemCustomMidele = sParty_Juan3},
    },

    [TRAINER_FARMEO_DOBLES] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RANDOM,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .battleMusic = MUS_VS_FRONT,
        .trainerPic = TRAINER_PIC_RANDOM,
        .trainerName = _("FARMEO"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Farmeo),
        .party = {.ItemCustomMidele = sParty_Farmeo},
    },

    [TRAINER_POKEXAVI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("POKEXAVI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Pokexavi),
        .party = {.ItemCustomMidele = sParty_Pokexavi},
    },

    [TRAINER_ANGELO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("ANGELO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Angelo),
        .party = {.ItemCustomMidele = sParty_Angelo},
    },

    [TRAINER_DARIUS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("DARIUS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Darius),
        .party = {.ItemCustomMidele = sParty_Darius},
    },

    [TRAINER_STEVEN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_STEVEN,
        .trainerName = _("STEVEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Steven),
        .party = {.ItemCustomMidele = sParty_Steven},
    },

    [TRAINER_ANABEL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SALON_MAIDEN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SALON_MAIDEN_ANABEL,
        .trainerName = _("ANABEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Anabel),
        .party = {.NoItemDefaultMoves = sParty_Anabel},
    },

    [TRAINER_TUCKER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_DOME_ACE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_DOME_ACE_TUCKER,
        .trainerName = _("TUCKER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tucker),
        .party = {.NoItemDefaultMoves = sParty_Tucker},
    },

    [TRAINER_SPENSER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PALACE_MAVEN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PALACE_MAVEN_SPENSER,
        .trainerName = _("SPENSER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Spenser),
        .party = {.NoItemDefaultMoves = sParty_Spenser},
    },

    [TRAINER_GRETA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_ARENA_TYCOON,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ARENA_TYCOON_GRETA,
        .trainerName = _("GRETA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Greta),
        .party = {.NoItemDefaultMoves = sParty_Greta},
    },

    [TRAINER_NOLAND] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FACTORY_HEAD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FACTORY_HEAD_NOLAND,
        .trainerName = _("NOLAND"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Noland),
        .party = {.NoItemDefaultMoves = sParty_Noland},
    },

    [TRAINER_LUCY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PIKE_QUEEN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PIKE_QUEEN_LUCY,
        .trainerName = _("LUCY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lucy),
        .party = {.NoItemDefaultMoves = sParty_Lucy},
    },

    [TRAINER_BRANDON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PYRAMID_KING,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PYRAMID_KING_BRANDON,
        .trainerName = _("BRANDON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brandon),
        .party = {.NoItemDefaultMoves = sParty_Brandon},
    },

    [TRAINER_ANDRES_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("ANDRES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Andres2),
        .party = {.ItemCustomMidele = sParty_Andres2},
    },

    [TRAINER_ANDRES_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("ANDRES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Andres3),
        .party = {.ItemCustomMidele = sParty_Andres3},
    },

    [TRAINER_ANDRES_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("ANDRES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Andres4),
        .party = {.ItemCustomMidele = sParty_Andres4},
    },

    [TRAINER_ANDRES_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("ANDRES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Andres5),
        .party = {.ItemCustomMidele = sParty_Andres5},
    },

    [TRAINER_CORY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("CORY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cory2),
        .party = {.ItemCustomMidele = sParty_Cory2},
    },

    [TRAINER_CORY_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("CORY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cory3),
        .party = {.ItemCustomMidele = sParty_Cory3},
    },

    [TRAINER_CORY_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("CORY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cory4),
        .party = {.ItemCustomMidele = sParty_Cory4},
    },

    [TRAINER_CORY_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("CORY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cory5),
        .party = {.ItemCustomMidele = sParty_Cory5},
    },

    [TRAINER_PABLO_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("PABLO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Pablo2),
        .party = {.ItemCustomMidele = sParty_Pablo2},
    },

    [TRAINER_PABLO_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("PABLO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Pablo3),
        .party = {.ItemCustomMidele = sParty_Pablo3},
    },

    [TRAINER_PABLO_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("PABLO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Pablo4),
        .party = {.ItemCustomMidele = sParty_Pablo4},
    },

    [TRAINER_PABLO_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .trainerName = _("PABLO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Pablo5),
        .party = {.ItemCustomMidele = sParty_Pablo5},
    },

    [TRAINER_KOJI_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KOJI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Koji2),
        .party = {.ItemCustomMidele = sParty_Koji2},
    },

    [TRAINER_KOJI_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KOJI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Koji3),
        .party = {.ItemCustomMidele = sParty_Koji3},
    },

    [TRAINER_KOJI_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KOJI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Koji4),
        .party = {.ItemCustomMidele = sParty_Koji4},
    },

    [TRAINER_KOJI_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KOJI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Koji5),
        .party = {.ItemCustomMidele = sParty_Koji5},
    },

    [TRAINER_CRISTIN_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("CRISTIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cristin2),
        .party = {.ItemCustomMidele = sParty_Cristin2},
    },

    [TRAINER_CRISTIN_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("CRISTIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cristin3),
        .party = {.ItemCustomMidele = sParty_Cristin3},
    },

    [TRAINER_CRISTIN_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("CRISTIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cristin4),
        .party = {.ItemCustomMidele = sParty_Cristin4},
    },

    [TRAINER_CRISTIN_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("CRISTIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cristin5),
        .party = {.ItemCustomMidele = sParty_Cristin5},
    },

    [TRAINER_FERNANDO_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("FERNANDO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Fernando2),
        .party = {.ItemCustomMidele = sParty_Fernando2},
    },

    [TRAINER_FERNANDO_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("FERNANDO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Fernando3),
        .party = {.ItemCustomMidele = sParty_Fernando3},
    },

    [TRAINER_FERNANDO_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("FERNANDO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Fernando4),
        .party = {.ItemCustomMidele = sParty_Fernando4},
    },

    [TRAINER_FERNANDO_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("FERNANDO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Fernando5),
        .party = {.ItemCustomMidele = sParty_Fernando5},
    },

    [TRAINER_SAWYER_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("SAWYER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sawyer2),
        .party = {.ItemCustomMidele = sParty_Sawyer2},
    },

    [TRAINER_SAWYER_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("SAWYER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sawyer3),
        .party = {.ItemCustomMidele = sParty_Sawyer3},
    },

    [TRAINER_SAWYER_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("SAWYER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sawyer4),
        .party = {.ItemCustomMidele = sParty_Sawyer4},
    },

    [TRAINER_SAWYER_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("SAWYER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sawyer5),
        .party = {.ItemCustomMidele = sParty_Sawyer5},
    },

    [TRAINER_GABRIELLE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("GABRIELLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Gabrielle2),
        .party = {.ItemCustomMidele = sParty_Gabrielle2},
    },

    [TRAINER_GABRIELLE_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("GABRIELLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Gabrielle3),
        .party = {.ItemCustomMidele = sParty_Gabrielle3},
    },

    [TRAINER_GABRIELLE_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("GABRIELLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Gabrielle4),
        .party = {.ItemCustomMidele = sParty_Gabrielle4},
    },

    [TRAINER_GABRIELLE_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .trainerName = _("GABRIELLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Gabrielle5),
        .party = {.ItemCustomMidele = sParty_Gabrielle5},
    },

    [TRAINER_THALIA_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("THALIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Thalia2),
        .party = {.ItemCustomMidele = sParty_Thalia2},
    },

    [TRAINER_THALIA_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("THALIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Thalia3),
        .party = {.ItemCustomMidele = sParty_Thalia3},
    },

    [TRAINER_THALIA_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("THALIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Thalia4),
        .party = {.ItemCustomMidele = sParty_Thalia4},
    },

    [TRAINER_THALIA_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("THALIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Thalia5),
        .party = {.ItemCustomMidele = sParty_Thalia5},
    },

    [TRAINER_MARIELA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("MARIELA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Mariela),
        .party = {.ItemCustomMidele = sParty_Mariela},
    },

    [TRAINER_ALVARO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("ALVARO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Alvaro),
        .party = {.ItemCustomMidele = sParty_Alvaro},
    },

    [TRAINER_EVERETT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("EVERETT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Everett),
        .party = {.ItemCustomMidele = sParty_Everett},
    },

    [TRAINER_RED] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RED,
        .trainerName = _("RED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Red),
        .party = {.NoItemDefaultMoves = sParty_Red},
    },

    [TRAINER_LEAF] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_LEAF,
        .trainerName = _("LEAF"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Leaf),
        .party = {.NoItemDefaultMoves = sParty_Leaf},
    },

    [TRAINER_BRENDAN_PLACEHOLDER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RS_PROTAG,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RS_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_BrendanLinkPlaceholder),
        .party = {.NoItemDefaultMoves = sParty_BrendanLinkPlaceholder},
    },

    [TRAINER_MAY_PLACEHOLDER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RS_PROTAG,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RS_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_MayLinkPlaceholder),
        .party = {.NoItemDefaultMoves = sParty_MayLinkPlaceholder},
    },

    [TRAINER_DEBUG] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_DEBUG,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .battleMusic = BATTLESAPPH,
        .trainerPic = TRAINER_PIC_LEAF,
        .trainerName = _("MIDELE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Debug),
        .party = {.ItemCustomMidele = sParty_Debug},
    },
    [TRAINER_SIDNEY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_SIDNEY,
        .trainerName = _("SIDNEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sidney_2),
        .party = {.ItemCustomMidele = sParty_Sidney_2},
    },

    [TRAINER_PHOEBE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_PHOEBE,
        .trainerName = _("PHOEBE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Phoebe_2),
        .party = {.ItemCustomMidele = sParty_Phoebe_2},
    },

    [TRAINER_GLACIA_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_GLACIA,
        .trainerName = _("GLACIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Glacia_2),
        .party = {.ItemCustomMidele = sParty_Glacia_2},
    },

    [TRAINER_DRAKE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_DRAKE,
        .trainerName = _("DRAKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Drake_2),
        .party = {.ItemCustomMidele = sParty_Drake_2},
    },
    [TRAINER_WALLACE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CHAMPION,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CHAMPION_WALLACE,
        .trainerName = _("WALLACE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Wallace_2),
        .party = {.ItemCustomMidele = sParty_Wallace_2},
    },
    [TRAINER_PERICO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("PERICO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Perico),
        .party = {.ItemCustomMidele = sParty_Perico},
    },
    [TRAINER_RANDOM_PARTY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RANDOM,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_RANDOM,
        .battleMusic = MUS_VS_FRONT,
        .trainerName = _("BOT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Random),
        .party = {.ItemCustomMidele = sParty_Random},
    },
    [TRAINER_OMARI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("OMARI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Omari),
        .party = {.ItemCustomMidele = sParty_Omari},
    },
    [TRAINER_DAVIAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("DAVIAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Davian),
        .party = {.ItemCustomMidele = sParty_Davian},
    },
    [TRAINER_IZABE_SAILOR] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SAILOR,
        .battleMusic = UNDERTALEMEGALOVANIA,
        .trainerName = _("FURRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_IzabeIsland_Sailor),
        .party = {.ItemCustomMidele = sParty_IzabeIsland_Sailor},
    },
    [TRAINER_IZABE_MAYOR] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("GARM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_IzabeIsland_Mayor),
        .party = {.ItemCustomMidele = sParty_IzabeIsland_Mayor},
    },
    [TRAINER_IZABE_YOUNGSTER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_IzabeIsland_Youngster),
        .party = {.ItemCustomMidele = sParty_IzabeIsland_Youngster},
    },
    [TRAINER_IZABE_HIKER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("MANOLO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_IzabeIsland_Hiker),
        .party = {.ItemCustomMidele = sParty_IzabeIsland_Hiker},
    },
    [TRAINER_IZABE_FISHERMAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("VLADIMIR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_IzabeIsland_Fisherman),
        .party = {.ItemCustomMidele = sParty_IzabeIsland_Fisherman},
    },
    [TRAINER_IZABE_POKEMANIAC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("EREN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_IzabeIsland_Pokemaniac),
        .party = {.ItemCustomMidele = sParty_IzabeIsland_Pokemaniac},
    },
    [TRAINER_IZABE_GOOSES] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = UMINEKONONAKUKORO,
        .trainerPic = TRAINER_PIC_BERNKASTEL,
        .trainerName = _("GOOSES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_IzabeIsland_Gooses),
        .party = {.ItemCustomMidele = sParty_IzabeIsland_Gooses},
    },
    [TRAINER_IZABE_LAVENDER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = SASAGEYO,
        .trainerPic = TRAINER_PIC_EMIL,
        .trainerName = _("LAVENDER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_IzabeIsland_Lavender),
        .party = {.ItemCustomMidele = sParty_IzabeIsland_Lavender},
    },
    [TRAINER_BRENDAN_PROFESSORBIRCHSLAB_MUDKIP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BrendanProfessorBirchsLabMudkip),
        .party = {.ItemCustomMidele = sParty_BrendanProfessorBirchsLabMudkip},
    },

    [TRAINER_BRENDAN_PROFESSORBIRCHSLAB_TREECKO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BrendanProfessorBirchsLabTreecko),
        .party = {.ItemCustomMidele = sParty_BrendanProfessorBirchsLabTreecko},
    },

    [TRAINER_BRENDAN_PROFESSORBIRCHSLAB_TORCHIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BrendanProfessorBirchsLabTorchic),
        .party = {.ItemCustomMidele = sParty_BrendanProfessorBirchsLabTorchic},
    },

    [TRAINER_MAY_PROFESSORBIRCHSLAB_MUDKIP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MayProfessorBirchsLabMudkip),
        .party = {.ItemCustomMidele = sParty_MayProfessorBirchsLabMudkip},
    },

    [TRAINER_MAY_PROFESSORBIRCHSLAB_TREECKO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MayProfessorBirchsLabTreecko),
        .party = {.ItemCustomMidele = sParty_MayProfessorBirchsLabTreecko},
    },

    [TRAINER_MAY_PROFESSORBIRCHSLAB_TORCHIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_MAY,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MayProfessorBirchsLabTorchic),
        .party = {.ItemCustomMidele = sParty_MayProfessorBirchsLabTorchic},
    },

    [TRAINER_BROCK] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerPic = TRAINER_PIC_BROCK,
        .trainerName = _("BROCK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Brock),
        .party = {.ItemCustomMidele = sParty_Brock},
    },

    [TRAINER_MISTY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerPic = TRAINER_PIC_MISTY,
        .trainerName = _("MISTY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Misty),
        .party = {.ItemCustomMidele = sParty_Misty},
    },

    [TRAINER_ERIKA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerPic = TRAINER_PIC_ERIKA,
        .trainerName = _("ERIKA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Erika),
        .party = {.ItemCustomMidele = sParty_Erika},
    },

    [TRAINER_LTSURGE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerPic = TRAINER_PIC_LT_SURGE,
        .trainerName = _("LT.SURGE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_LtSurge),
        .party = {.ItemCustomMidele = sParty_LtSurge},
    },

    [TRAINER_SABRINA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerPic = TRAINER_PIC_SABRINA,
        .trainerName = _("SABRINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sabrina),
        .party = {.ItemCustomMidele = sParty_Sabrina},
    },

    [TRAINER_KOGA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerPic = TRAINER_PIC_KOGA,
        .trainerName = _("KOGA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Koga),
        .party = {.ItemCustomMidele = sParty_Koga},
    },

    [TRAINER_BLAINE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerPic = TRAINER_PIC_BLAINE,
        .trainerName = _("BLAINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Blaine),
        .party = {.ItemCustomMidele = sParty_Blaine},
    },

    [TRAINER_GIOVANNI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerPic = TRAINER_PIC_GIOVANNI,
        .trainerName = _("GIOVANNI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Giovanni),
        .party = {.ItemCustomMidele = sParty_Giovanni},
    },

    [TRAINER_LORELEI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerPic = TRAINER_PIC_LORELEI,
        .trainerName = _("LORELEI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lorelei),
        .party = {.ItemCustomMidele = sParty_Lorelei},
    },

    [TRAINER_BRUNO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerPic = TRAINER_PIC_BRUNO,
        .trainerName = _("BRUNO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Bruno),
        .party = {.ItemCustomMidele = sParty_Bruno},
    },

    [TRAINER_AGATHA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerPic = TRAINER_PIC_AGATHA,
        .trainerName = _("AGATHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Agatha),
        .party = {.ItemCustomMidele = sParty_Agatha},
    },

    [TRAINER_LANCE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerPic = TRAINER_PIC_LANCE,
        .trainerName = _("LANCE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lance),
        .party = {.ItemCustomMidele = sParty_Lance},
    },

    [TRAINER_BLUE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = MUS_RG_VS_LAST,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("BLUE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Blue),
        .party = {.ItemCustomMidele = sParty_Blue},
    },

    [TRAINER_RED2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = MUS_RG_VS_LAST,
        .trainerPic = TRAINER_PIC_RED,
        .trainerName = _("RED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Red2),
        .party = {.ItemCustomMidele = sParty_Red2},
    },

    [TRAINER_LEAF2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .battleMusic = MUS_RG_VS_LAST,
        .trainerPic = TRAINER_PIC_LEAF,
        .trainerName = _("LEAF"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Leaf2),
        .party = {.ItemCustomMidele = sParty_Leaf2},
    },
    [TRAINER_AVADER_OLDALE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = ZANZATHEME,
        .trainerPic = TRAINER_PIC_VADER,
        .trainerName = _("A.VADER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Oldale_Avader),
        .party = {.ItemCustomMidele = sParty_Oldale_Avader},
    },
    [TRAINER_RANDOM_PARTY_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RANDOM,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_RANDOM,
        .battleMusic = MUS_VS_FRONT,
        .trainerName = _("BOT"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Random_2),
        .party = {.ItemCustomMidele = sParty_Random_2},
    },
	[TRAINER_FORBIDDENFOREST_EZECUTER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("EZECUTER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_ForbiddenForest_Ezecuter),
        .party = {.ItemCustomMidele = sParty_ForbiddenForest_Ezecuter},
    },
	[TRAINER_ISMAPKM_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = BUTTERFLYWADAKOUJI,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("ISMAPKM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_IsmaPkm1),
        .party = {.ItemCustomMidele = sParty_IsmaPkm1},
    },
    [TRAINER_FIERYPATH_PACOCHEF] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_PACOCHEF_FIERY_PATH,
		.battleMusic = BATTLE_TOWER_SWSH,
        .trainerPic = TRAINER_PIC_ROCKER,
        .trainerName = _("PACOCHEF"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Pacochef),
        .party = {.ItemCustomMidele = sParty_Pacochef},
    },
    [TRAINER_FIERYPATH_KRUB] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("KRUB"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Krub),
        .party = {.ItemCustomMidele = sParty_Krub},
    },
    [TRAINER_FIERYPATH_KADERETE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .battleMusic = MUS_BATTLE35,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("KADERETE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE | AI_SCRIPT_USE_PERISH_SONG_EVEN_IF_LAST_POKEMON,
        .partySize = ARRAY_COUNT(sParty_Kaderete),
        .party = {.ItemCustomMidele = sParty_Kaderete},
    },
    [TRAINER_FIERYPATH_CHINPO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("CHINPO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Chinpo),
        .party = {.ItemCustomMidele = sParty_Chinpo},
    },
    [TRAINER_FIERYPATH_DOBLEC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("DOBLEC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_DobleC),
        .party = {.ItemCustomMidele = sParty_DobleC},
    },
    [TRAINER_GOLDIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .battleMusic = MUSICAVEGAGOLDY,
        .trainerPic = TRAINER_PIC_GOLDIE,
        .trainerName = _("GOLDIE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Goldie),
        .party = {.ItemCustomMidele = sParty_Goldie},
    },
    [TRAINER_JOSITO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("JOSITO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Josito),
        .party = {.ItemCustomMidele = sParty_Josito},
    },
    [TRAINER_GHADDAR] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
		.battleMusic = JACKROOM,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("GHADDAR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ghaddar),
        .party = {.ItemCustomMidele = sParty_Ghaddar},
	},
    [TRAINER_HYPEANTONIO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("HYPEANTONIO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Hypeantonio),
        .party = {.ItemCustomMidele = sParty_Hypeantonio},
    },
    [TRAINER_VLADILAND] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("VLADILAND"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Vladiland),
        .party = {.ItemCustomMidele = sParty_Vladiland},
    },
    [TRAINER_JAVISITO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
		.battleMusic = THEREINCARNATION,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("JAVISITO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Javisito),
        .party = {.ItemCustomMidele = sParty_Javisito},
    },
    [TRAINER_KEFKY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
		.battleMusic = FF6BOSS,
        .trainerPic = TRAINER_PIC_KEFKY,
        .trainerName = _("KEFKY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kefky),
        .party = {.ItemCustomMidele = sParty_Kefky},
    },
    [TRAINER_ELPRINCIPE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("EL PRINCIPE"),
        .battleMusic = MUS_RG_VS_TORE,
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_ElPrincipe),
        .party = {.ItemCustomMidele = sParty_ElPrincipe},
    },
    [TRAINER_GRANITECAVE_JZOMBIE] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("JZOMBIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_JZombie),
        .party = {.ItemCustomMidele = sParty_JZombie},
    },
    [TRAINER_JZOMBIE2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("JZOMBIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_JZombie2),
        .party = {.ItemCustomMidele = sParty_JZombie2},
    },
    [TRAINER_CHARIZARD_FAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("CHARFAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_CharizardFan),
        .party = {.ItemCustomMidele = sParty_CharizardFan},
    },
    [TRAINER_JAVISITO_POSTGAME] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
	    .battleMusic = THEREINCARNATION,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("JAVISITO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Javisito2),
        .party = {.ItemCustomMidele = sParty_Javisito2},
    },
    [TRAINER_MERUM] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = INCOMINGX2,
        .trainerPic = TRAINER_PIC_MERUM,
        .trainerName = _("MERÚM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Merum),
        .party = {.ItemCustomMidele = sParty_Merum},
    },
    [TRAINER_ENTROPIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_ENTROPIA,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("ENTROPÍA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Entropia),
        .party = {.ItemCustomMidele = sParty_Entropia},
    },
    [TRAINER_TREVEJO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("TREVEJO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Trevejo),
        .party = {.ItemCustomMidele = sParty_Trevejo},
    },
    [TRAINER_PUFFU] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .battleMusic = MUS_RG_VS_TORE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .trainerName = _("PUFFU FAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Puffu),
        .party = {.ItemCustomMidele = sParty_Puffu},
    },
    [TRAINER_MERCIBOKU] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("MERCIBOKU"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Merciboku),
        .party = {.ItemCustomMidele = sParty_Merciboku},
    },
    [TRAINER_DUNK] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTISH_FRLG,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("DUNK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dunk),
        .party = {.ItemCustomMidele = sParty_Dunk},
    },
    [TRAINER_EEVEETO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .battleMusic = DIALGAPALKIABATTLE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .trainerName = _("EEVEETO"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Eeveeto),
        .party = {.ItemCustomMidele = sParty_Eeveeto},
    },
    [TRAINER_UTALAWEA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .battleMusic = JOHTOTRAIN,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("UTALAWEA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Utalawea),
        .party = {.ItemCustomMidele = sParty_Utalawea},
    },
    [TRAINER_SANTYGRASS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
		.battleMusic = FINALBOSSBREATHFIRE2,
        .trainerPic = TRAINER_PIC_SANTY,
        .trainerName = _("SANTYGRASS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Santygrass1),
        .party = {.ItemCustomMidele = sParty_Santygrass1},
    },
    [TRAINER_SANTYGRASS_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
		.battleMusic = FINALBOSSBREATHFIRE2,
        .trainerPic = TRAINER_PIC_SANTY,
        .trainerName = _("SANTYGRASS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Santygrass2),
        .party = {.ItemCustomMidele = sParty_Santygrass2},
    },
    [TRAINER_SANTYGRASS_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER_MIDELE,
        .battleWeather = WEATHER_DROUGHT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
		.battleMusic = FINALBOSSBREATHFIRE2,
        .trainerPic = TRAINER_PIC_SANTY,
        .trainerName = _("SANTYGRASS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Santygrass3),
        .party = {.ItemCustomMidele = sParty_Santygrass3},
    },
    [TRAINER_DARKI_MALRO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .battleMusic = DELTARUNCHAOSK,
        .trainerPic = TRAINER_PIC_DARKIMALRO,
        .trainerName = _("DARKIMALRO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Darkimalro),
        .party = {.ItemCustomMidele = sParty_Darkimalro},
    },
    [TRAINER_TENSHINHAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("TENSHINHAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tenshinhan),
        .party = {.ItemCustomMidele = sParty_Tenshinhan},
    },
    [TRAINER_KAISSER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .battleMusic = HEARTMULHOLLAND,
        .trainerName = _("KAISSER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kaisser),
        .party = {.ItemCustomMidele = sParty_Kaisser},
    },
    [TRAINER_FELIPEX88] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("FELIPEX88"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Felipex88),
        .party = {.ItemCustomMidele = sParty_Felipex88},
    },
    [TRAINER_GOOSES] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
	    .battleMusic = UMINEKONONAKUKORO,
	    .battleWeather = WEATHER_SNOW,
        .trainerPic = TRAINER_PIC_BERNKASTEL,
        .trainerName = _("GOOSES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Gooses),
        .party = {.ItemCustomMidele = sParty_Gooses},
    },
    [TRAINER_RANDOM_PARTY_GYM] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("RANDOM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_RandomGym),
        .party = {.ItemCustomMidele = sParty_RandomGym},
    },
    [TRAINER_RED_KROW] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .battleMusic = ZINNIATHEME,
        .trainerPic = TRAINER_PIC_REDKROW,
        .trainerName = _("RED KROW"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_RedKrow),
        .party = {.ItemCustomMidele = sParty_RedKrow},
    },
    [TRAINER_TOPO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("TOPO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Topo),
        .party = {.ItemCustomMidele = sParty_Topo},
    },
    [TRAINER_GRIM] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .battleMusic = THEMEOFENCOUNTER,
        .trainerName = _("GRIM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Grim),
        .party = {.ItemCustomMidele = sParty_Grim},
    },
	[TRAINER_MAESTRO_ARENA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerName = _("M.ARENA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Maestro_Arena),
        .party = {.ItemCustomMidele = sParty_Maestro_Arena},
    },
	[TRAINER_MANEC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
		.battleMusic = SHUM,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("MANEC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Manec),
        .party = {.ItemCustomMidele = sParty_Manec},
    },
	[TRAINER_RAGU] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
		.battleMusic = BATTLECYRUS,
        .trainerPic = TRAINER_PIC_RAGU,
        .trainerName = _("RAGU"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ragu),
        .party = {.ItemCustomMidele = sParty_Ragu},
    },
	[TRAINER_PACOCHEF_MICOLANDIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
		.battleMusic = BATTLE_TOWER_SWSH,
        .trainerPic = TRAINER_PIC_ROCKER,
        .trainerName = _("PACOCHEF"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Pacochef2),
        .party = {.ItemCustomMidele = sParty_Pacochef2},
    },
    [TRAINER_LAVENDER_MICOLANDIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = SASAGEYO,
        .trainerPic = TRAINER_PIC_EMIL,
        .trainerName = _("LAVENDER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Lavender2),
        .party = {.ItemCustomMidele = sParty_Lavender2},
    },
    [TRAINER_AVADER_MICOLANDIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = ZANZATHEME,
        .trainerPic = TRAINER_PIC_VADER,
        .trainerName = _("A.VADER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Avader2),
        .party = {.ItemCustomMidele = sParty_Avader2},
    },
    [TRAINER_MICOLO_MICOLANDIA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CHAMPION_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .battleMusic = CRUELANGELSTHESIS,
        .trainerPic = TRAINER_PIC_MICOLO,
        .trainerName = _("MICOLO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Micolo3),
        .party = {.ItemCustomMidele = sParty_Micolo3},
    },
    [TRAINER_ALPHA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RICH_ALPHA,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .battleMusic = MUS_ENCOUNTER_CYNTHIA,
        .trainerPic = TRAINER_PIC_DOCTOR,
        .trainerName = _("ALPHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Alpha),
        .party = {.ItemCustomMidele = sParty_Alpha},
    },
    [TRAINER_JPROGAMER] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_SCIENTISH_FRLG,
        .trainerName = _("JPROGAMER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_JProgamer),
        .party = {.ItemCustomMidele = sParty_JProgamer},
    },
    [TRAINER_SLOWBRO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_CURSED,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_CURSED_SLOWBRO,
        .battleMusic = MUS_RG_SHION,
        .trainerName = _("SLOWBRO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Slowbro),
        .party = {.ItemCustomMidele = sParty_Slowbro},
    },
    [TRAINER_BOTONES] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("BOTONES"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Botones),
        .party = {.ItemCustomMidele = sParty_Botones},
    },
    [TRAINER_HYPEANTONIO_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("HYPEANTONIO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Hypeantonio2),
        .party = {.ItemCustomMidele = sParty_Hypeantonio2},
    },
    [TRAINER_DARKI_BUENRO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .battleMusic = BONETROUSLEUNDERTALE,
        .trainerPic = TRAINER_PIC_DARKIBUENRO,
        .trainerName = _("DARKIBUENRO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Darkibuenro),
        .party = {.ItemCustomMidele = sParty_Darkibuenro},
    },
    [TRAINER_VIN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_VIN,
        .trainerName = _("VIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Vin),
        .party = {.ItemCustomMidele = sParty_Vin},
    },
    [TRAINER_MAESTRO_ARENA_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerName = _("M.ARENA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Maestro_Arena2),
        .party = {.ItemCustomMidele = sParty_Maestro_Arena2},
    },
    [TRAINER_ESBIRRO_DARKI_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .trainerName = _("RED SRIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Red_Secretaria),
        .party = {.ItemCustomMidele = sParty_Red_Secretaria},
    },
    [TRAINER_ESBIRRO_DARKI_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_SCIENTISH,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_SCIENTISH_FRLG,
        .trainerName = _("KIZARDE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Loco_Kizarde),
        .party = {.ItemCustomMidele = sParty_Loco_Kizarde},
    },
    [TRAINER_ESBIRRO_DARKI_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("ESPI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Espi),
        .party = {.ItemCustomMidele = sParty_Espi},
    },
    [TRAINER_ESBIRRO_DARKI_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("MOBU"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Mobu),
        .party = {.ItemCustomMidele = sParty_Mobu},
    },
    [TRAINER_ESBIRRO_DARKI_5] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("ROXY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Roxy),
        .party = {.ItemCustomMidele = sParty_Roxy},
    },
    [TRAINER_ANTHONYPXP] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("ANTHONY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Anthonypxp),
        .party = {.ItemCustomMidele = sParty_Anthonypxp},
    },
    [TRAINER_DRANIX] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("DRANIX"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dranix),
        .party = {.ItemCustomMidele = sParty_Dranix},
    },
    [TRAINER_UMBREON123] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("UMBREON123"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Umbreon123),
        .party = {.ItemCustomMidele = sParty_Umbreon123},
    },
    [TRAINER_PHENT] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_NERD_HGSS,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("PHENT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Phent),
        .party = {.ItemCustomMidele = sParty_Phent},
    },
    [TRAINER_ULTRA_MAGIC] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_DOOD,
        .battleMusic = SASAGEYO,
        .trainerName = _("ULTRA MAGIC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_UltraMagic),
        .party = {.ItemCustomMidele = sParty_UltraMagic},
    },
    [TRAINER_CHARZ] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("CHARZ"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Charz),
        .party = {.ItemCustomMidele = sParty_Charz},
    },
    [TRAINER_GHADDAR_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = JACKROOM,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("GHADDAR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Ghaddar2),
        .party = {.ItemCustomMidele = sParty_Ghaddar2},
	},
    [TRAINER_KADERETE_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .battleMusic = MUS_BATTLE35,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("KADERETE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Kaderete2),
        .party = {.ItemCustomMidele = sParty_Kaderete2},
    },
    [TRAINER_FURRY] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .battleMusic = UNDERTALEMEGALOVANIA,
        .trainerPic = TRAINER_PIC_OFFICER,
        .trainerName = _("FURRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Furry),
        .party = {.ItemCustomMidele = sParty_Furry},
    },
    [TRAINER_DARK_MELKOR] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .battleMusic = JENOVA,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("DARK MELKOR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_DarkMelkor),
        .party = {.ItemCustomMidele = sParty_DarkMelkor},
    },
    [TRAINER_FANBOY_KALOS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("FANBOYKALOS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_FanboyKalos),
        .party = {.ItemCustomMidele = sParty_FanboyKalos},
    },
    [TRAINER_ANGELFS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("ANGELFS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_AngelFS),
        .party = {.ItemCustomMidele = sParty_AngelFS},
    },
    [TRAINER_TILO_ALOLA] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("TILO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Tilo),
        .party = {.ItemCustomMidele = sParty_Tilo},
    },
    [TRAINER_YUME] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("YUME"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Yume),
        .party = {.ItemCustomMidele = sParty_Yume},
    },
    [TRAINER_MDRAGON] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .battleMusic = MUS_RG_VS_GYM,
        .trainerName = _("M DRAGON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MDragon),
        .party = {.ItemCustomMidele = sParty_MDragon},
    },
    [TRAINER_ALBERMAUS] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .battleMusic = MUS_MOLGERA_WW,
        .trainerPic = TRAINER_PIC_MAUS,
        .trainerName = _("ALBERMAUS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Albermaus),
        .party = {.ItemCustomMidele = sParty_Albermaus},
    },
    [TRAINER_HATHAR] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .battleMusic = MUS_CHAMPION_BATTLE_HGSS,
        .trainerPic = TRAINER_PIC_JUGON,
        .trainerName = _("HATHAR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Hathar),
        .party = {.ItemCustomMidele = sParty_Hathar},
    },
    [TRAINER_CASTILLO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
		.battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("CASTILLO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Castillo),
        .party = {.ItemCustomMidele = sParty_Castillo},
    },
    [TRAINER_JOSITO_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
		.battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("JOSITO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Josito2),
        .party = {.ItemCustomMidele = sParty_Josito2},
    },
    [TRAINER_MR_ZERO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
		.battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("MR. ZERO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Mrzero),
        .party = {.ItemCustomMidele = sParty_Mrzero},
    },
    [TRAINER_ZZZ] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
		.battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .trainerName = _("ZZZ"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Zzz),
        .party = {.ItemCustomMidele = sParty_Zzz},
    },
    [TRAINER_FENAN] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
		.battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("FENAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Fenan),
        .party = {.ItemCustomMidele = sParty_Fenan},
    },
    [TRAINER_ADDRI] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
		.battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("ADDRI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Addri),
        .party = {.ItemCustomMidele = sParty_Addri},
    },
    [TRAINER_ESCROTO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
		.battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .trainerName = _("ESCROTO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Escroto),
        .party = {.ItemCustomMidele = sParty_Escroto},
    },
    [TRAINER_POISONMASTAHHHH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
		.battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("POISONMASTA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_PoisonMastahhhh),
        .party = {.ItemCustomMidele = sParty_PoisonMastahhhh},
    },
    [TRAINER_BLUE_AND_YELLOW] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("BLUE&YELLOW"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_BlueandYellow),
        .party = {.ItemCustomMidele = sParty_BlueandYellow},
    },
    [TRAINER_DUNK_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTISH_FRLG,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerName = _("DUNK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Dunk2),
        .party = {.ItemCustomMidele = sParty_Dunk2},
    },
    [TRAINER_SAPPH] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_LEADER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
	    .battleMusic = BATTLESAPPH,
	    .battleWeather = WEATHER_RAIN,
        .trainerPic = TRAINER_PIC_SAPPH,
        .trainerName = _("SAPPHIRE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Sapph),
        .party = {.ItemCustomMidele = sParty_Sapph},
    },
    [TRAINER_MIRORB] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_WANDERER,
	    .battleMusic = MIRORBCOLO,
        .trainerPic = TRAINER_PIC_MIRORB,
        .trainerName = _("MIROR B"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_MirorB),
        .party = {.ItemCustomMidele = sParty_MirorB},
    },
    [TRAINER_SAPPH_GYM_1] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
	    .battleMusic = LIYUEBATTLETHEMEIMAIN,
	    .battleWeather = WEATHER_RAIN,
        .trainerPic =  TRAINER_PIC_SOLDIER_MIKU,
        .trainerName = _("LT. MIKU"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_SapphGymTrainer1),
        .party = {.ItemCustomMidele = sParty_SapphGymTrainer1},
    },
    [TRAINER_SAPPH_GYM_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
	    .battleMusic = LIYUEBATTLETHEMEIMAIN,
	    .battleWeather = WEATHER_RAIN,
        .trainerPic =  TRAINER_PIC_MEIKO,
        .trainerName = _("MEIKO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_SapphGymTrainer2),
        .party = {.ItemCustomMidele = sParty_SapphGymTrainer2},
    },
    [TRAINER_SAPPH_GYM_3] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
	    .battleMusic = LIYUEBATTLETHEMEIMAIN,
	    .battleWeather = WEATHER_RAIN,
        .trainerPic =  TRAINER_PIC_LUKA,
        .trainerName = _("LUKA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_SapphGymTrainer3),
        .party = {.ItemCustomMidele = sParty_SapphGymTrainer3},
    },
    [TRAINER_SAPPH_GYM_4] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
	    .battleMusic = LIYUEBATTLETHEMEIMAIN,
	    .battleWeather = WEATHER_RAIN,
        .trainerPic =  TRAINER_PIC_MIKU,
        .trainerName = _("MIKU"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_SapphGymTrainer4),
        .party = {.ItemCustomMidele = sParty_SapphGymTrainer4},
    },
    [TRAINER_KRUB_2] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_MIDELE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .battleMusic = MUS_RG_VS_TORE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("KRUB"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Krub2),
        .party = {.ItemCustomMidele = sParty_Krub2},
    },
    [TRAINER_CHERYL] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_3,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .battleMusic = MUS_RG_VS_LAST,
        .trainerPic = TRAINER_PIC_CHERYL,
        .trainerName = _("CHERYL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE,
        .partySize = ARRAY_COUNT(sParty_Cheryl),
        .party = {.ItemCustomMidele = sParty_Cheryl},
    },
    [TRAINER_FARMEO] =
    {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MIDELE,
        .trainerClass = TRAINER_CLASS_RANDOM,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .battleMusic = MUS_VS_FRONT,
        .trainerPic = TRAINER_PIC_RANDOM,
        .trainerName = _("FARMEO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_Farmeo),
        .party = {.ItemCustomMidele = sParty_Farmeo},
    }
};
