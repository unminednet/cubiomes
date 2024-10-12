#include "util.h"
#include "finders.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



uint64_t *loadSavedSeeds(const char *fnam, uint64_t *scnt)
{
    FILE *fp = fopen(fnam, "r");

    uint64_t seed, i;
    uint64_t *baseSeeds;

    if (fp == NULL)
        return NULL;

    *scnt = 0;

    while (!feof(fp))
    {
        if (fscanf(fp, "%" PRId64, (int64_t*)&seed) == 1) (*scnt)++;
        else while (!feof(fp) && fgetc(fp) != '\n');
    }

    if (*scnt == 0)
        return NULL;

    baseSeeds = (uint64_t*) calloc(*scnt, sizeof(*baseSeeds));

    rewind(fp);

    for (i = 0; i < *scnt && !feof(fp);)
    {
        if (fscanf(fp, "%" PRId64, (int64_t*)&baseSeeds[i]) == 1) i++;
        else while (!feof(fp) && fgetc(fp) != '\n');
    }

    fclose(fp);

    return baseSeeds;
}


const char* mc2str(int mc)
{
    switch (mc)
    {
    case MC_B1_7:   return "Beta 1.7"; break;
    case MC_B1_8:   return "Beta 1.8"; break;
    case MC_1_0:    return "1.0"; break;
    case MC_1_1:    return "1.1"; break;
    case MC_1_2:    return "1.2"; break;
    case MC_1_3:    return "1.3"; break;
    case MC_1_4:    return "1.4"; break;
    case MC_1_5:    return "1.5"; break;
    case MC_1_6:    return "1.6"; break;
    case MC_1_7:    return "1.7"; break;
    case MC_1_8:    return "1.8"; break;
    case MC_1_9:    return "1.9"; break;
    case MC_1_10:   return "1.10"; break;
    case MC_1_11:   return "1.11"; break;
    case MC_1_12:   return "1.12"; break;
    case MC_1_13:   return "1.13"; break;
    case MC_1_14:   return "1.14"; break;
    case MC_1_15:   return "1.15"; break;
    case MC_1_16_1: return "1.16.1"; break;
    case MC_1_16:   return "1.16"; break;
    case MC_1_17:   return "1.17"; break;
    case MC_1_18:   return "1.18"; break;
    case MC_1_19_2: return "1.19.2"; break;
    case MC_1_19:   return "1.19"; break;
    case MC_1_20:   return "1.20"; break;
    case MC_1_21_2: return "1.21.2"; break;
    case MC_1_21_3: return "1.21.3"; break;
    //case MC_1_21:   return "1.21"; break;
    default:        return NULL;
    }
}

int str2mc(const char *s)
{
    if (!strcmp(s, "1.21"))     return MC_1_21;
    if (!strcmp(s, "1.21.3"))   return MC_1_21_3;
    if (!strcmp(s, "1.21.2"))   return MC_1_21_2;
    if (!strcmp(s, "1.20"))     return MC_1_20;
    if (!strcmp(s, "1.20.6"))   return MC_1_20_6;
    if (!strcmp(s, "1.19"))     return MC_1_19;
    if (!strcmp(s, "1.19.4"))   return MC_1_19_4;
    if (!strcmp(s, "1.19.2"))   return MC_1_19_2;
    if (!strcmp(s, "1.18"))     return MC_1_18;
    if (!strcmp(s, "1.18.2"))   return MC_1_18_2;
    if (!strcmp(s, "1.17"))     return MC_1_17;
    if (!strcmp(s, "1.17.1"))   return MC_1_17_1;
    if (!strcmp(s, "1.16"))     return MC_1_16;
    if (!strcmp(s, "1.16.5"))   return MC_1_16_5;
    if (!strcmp(s, "1.16.1"))   return MC_1_16_1;
    if (!strcmp(s, "1.15"))     return MC_1_15;
    if (!strcmp(s, "1.15.2"))   return MC_1_15_2;
    if (!strcmp(s, "1.14"))     return MC_1_14;
    if (!strcmp(s, "1.14.4"))   return MC_1_14_4;
    if (!strcmp(s, "1.13"))     return MC_1_13;
    if (!strcmp(s, "1.13.2"))   return MC_1_13_2;
    if (!strcmp(s, "1.12"))     return MC_1_12;
    if (!strcmp(s, "1.12.2"))   return MC_1_12_2;
    if (!strcmp(s, "1.11"))     return MC_1_11;
    if (!strcmp(s, "1.11.2"))   return MC_1_11_2;
    if (!strcmp(s, "1.10"))     return MC_1_10;
    if (!strcmp(s, "1.10.2"))   return MC_1_10_2;
    if (!strcmp(s, "1.9"))      return MC_1_9;
    if (!strcmp(s, "1.9.4"))    return MC_1_9_4;
    if (!strcmp(s, "1.8"))      return MC_1_8;
    if (!strcmp(s, "1.8.9"))    return MC_1_8_9;
    if (!strcmp(s, "1.7"))      return MC_1_7;
    if (!strcmp(s, "1.7.10"))   return MC_1_7_10;
    if (!strcmp(s, "1.6"))      return MC_1_6;
    if (!strcmp(s, "1.6.4"))    return MC_1_6_4;
    if (!strcmp(s, "1.5"))      return MC_1_5;
    if (!strcmp(s, "1.5.2"))    return MC_1_5_2;
    if (!strcmp(s, "1.4"))      return MC_1_4;
    if (!strcmp(s, "1.4.7"))    return MC_1_4_7;
    if (!strcmp(s, "1.3"))      return MC_1_3;
    if (!strcmp(s, "1.3.2"))    return MC_1_3_2;
    if (!strcmp(s, "1.2"))      return MC_1_2;
    if (!strcmp(s, "1.2.5"))    return MC_1_2_5;
    if (!strcmp(s, "1.1"))      return MC_1_1;
    if (!strcmp(s, "1.1.0"))    return MC_1_1_0;
    if (!strcmp(s, "1.0"))      return MC_1_0;
    if (!strcmp(s, "1.0.0"))    return MC_1_0_0;
    if (!strcmp(s, "Beta 1.8")) return MC_B1_8;
    if (!strcmp(s, "Beta 1.7")) return MC_B1_7;
    return -1;
}


const char *biome2str(int mc, int id)
{
    if (mc >= MC_1_18)
    {
        // a bunch of 'new' biomes in 1.18 actually just got renamed
        // (based on their features and biome id conversion when upgrading)
        switch (id)
        {
        case old_growth_birch_forest: return "old_growth_birch_forest";
        case old_growth_pine_taiga: return "old_growth_pine_taiga";
        case old_growth_spruce_taiga: return "old_growth_spruce_taiga";
        case snowy_plains: return "snowy_plains";
        case sparse_jungle: return "sparse_jungle";
        case stony_shore: return "stony_shore";
        case windswept_hills: return "windswept_hills";
        case windswept_forest: return "windswept_forest";
        case windswept_gravelly_hills: return "windswept_gravelly_hills";
        case windswept_savanna: return "windswept_savanna";
        case wooded_badlands: return "wooded_badlands";
        }
    }

    switch (id)
    {
    case ocean: return "ocean";
    case plains: return "plains";
    case desert: return "desert";
    case mountains: return "mountains";
    case forest: return "forest";
    case taiga: return "taiga";
    case swamp: return "swamp";
    case river: return "river";
    case nether_wastes: return "nether_wastes";
    case the_end: return "the_end";
    // 10
    case frozen_ocean: return "frozen_ocean";
    case frozen_river: return "frozen_river";
    case snowy_tundra: return "snowy_tundra";
    case snowy_mountains: return "snowy_mountains";
    case mushroom_fields: return "mushroom_fields";
    case mushroom_field_shore: return "mushroom_field_shore";
    case beach: return "beach";
    case desert_hills: return "desert_hills";
    case wooded_hills: return "wooded_hills";
    case taiga_hills: return "taiga_hills";
    // 20
    case mountain_edge: return "mountain_edge";
    case jungle: return "jungle";
    case jungle_hills: return "jungle_hills";
    case jungle_edge: return "jungle_edge";
    case deep_ocean: return "deep_ocean";
    case stone_shore: return "stone_shore";
    case snowy_beach: return "snowy_beach";
    case birch_forest: return "birch_forest";
    case birch_forest_hills: return "birch_forest_hills";
    case dark_forest: return "dark_forest";
    // 30
    case snowy_taiga: return "snowy_taiga";
    case snowy_taiga_hills: return "snowy_taiga_hills";
    case giant_tree_taiga: return "giant_tree_taiga";
    case giant_tree_taiga_hills: return "giant_tree_taiga_hills";
    case wooded_mountains: return "wooded_mountains";
    case savanna: return "savanna";
    case savanna_plateau: return "savanna_plateau";
    case badlands: return "badlands";
    case wooded_badlands_plateau: return "wooded_badlands_plateau";
    case badlands_plateau: return "badlands_plateau";
    // 40  --  1.13
    case small_end_islands: return "small_end_islands";
    case end_midlands: return "end_midlands";
    case end_highlands: return "end_highlands";
    case end_barrens: return "end_barrens";
    case warm_ocean: return "warm_ocean";
    case lukewarm_ocean: return "lukewarm_ocean";
    case cold_ocean: return "cold_ocean";
    case deep_warm_ocean: return "deep_warm_ocean";
    case deep_lukewarm_ocean: return "deep_lukewarm_ocean";
    case deep_cold_ocean: return "deep_cold_ocean";
    // 50
    case deep_frozen_ocean: return "deep_frozen_ocean";
    // Alpha 1.2 - Beta 1.7
    case seasonal_forest: return "seasonal_forest";
    case shrubland: return "shrubland";
    case rainforest: return "rainforest";

    case the_void: return "the_void";

    // mutated variants
    case sunflower_plains: return "sunflower_plains";
    case desert_lakes: return "desert_lakes";
    case gravelly_mountains: return "gravelly_mountains";
    case flower_forest: return "flower_forest";
    case taiga_mountains: return "taiga_mountains";
    case swamp_hills: return "swamp_hills";
    case ice_spikes: return "ice_spikes";
    case modified_jungle: return "modified_jungle";
    case modified_jungle_edge: return "modified_jungle_edge";
    case tall_birch_forest: return "tall_birch_forest";
    case tall_birch_hills: return "tall_birch_hills";
    case dark_forest_hills: return "dark_forest_hills";
    case snowy_taiga_mountains: return "snowy_taiga_mountains";
    case giant_spruce_taiga: return "giant_spruce_taiga";
    case giant_spruce_taiga_hills: return "giant_spruce_taiga_hills";
    case modified_gravelly_mountains: return "modified_gravelly_mountains";
    case shattered_savanna: return "shattered_savanna";
    case shattered_savanna_plateau: return "shattered_savanna_plateau";
    case eroded_badlands: return "eroded_badlands";
    case modified_wooded_badlands_plateau: return "modified_wooded_badlands_plateau";
    case modified_badlands_plateau: return "modified_badlands_plateau";
    // 1.14
    case bamboo_jungle: return "bamboo_jungle";
    case bamboo_jungle_hills: return "bamboo_jungle_hills";
    // 1.16
    case soul_sand_valley: return "soul_sand_valley";
    case crimson_forest: return "crimson_forest";
    case warped_forest: return "warped_forest";
    case basalt_deltas: return "basalt_deltas";
    // 1.17
    case dripstone_caves: return "dripstone_caves";
    case lush_caves: return "lush_caves";
    // 1.18
    case meadow: return "meadow";
    case grove: return "grove";
    case snowy_slopes: return "snowy_slopes";
    case stony_peaks: return "stony_peaks";
    case jagged_peaks: return "jagged_peaks";
    case frozen_peaks: return "frozen_peaks";
    // 1.19
    case deep_dark: return "deep_dark";
    case mangrove_swamp: return "mangrove_swamp";
    // 1.20
    case cherry_grove: return "cherry_grove";
    // 1.21.3 (Winter Drop)
    case pale_garden: return "pale_garden";

    // Terralith
    case 54: return "terralith:alpine_highlands";
    case 55: return "terralith:amethyst_canyon";
    case 56: return "terralith:amethyst_rainforest";
    case 57: return "terralith:ancient_sands";
    case 58: return "terralith:arid_highlands";
    case 59: return "terralith:ashen_savanna";
    case 60: return "terralith:basalt_cliffs";
    case 61: return "terralith:birch_taiga";
    case 62: return "terralith:blooming_plateau";
    case 63: return "terralith:blooming_valley";
    case 64: return "terralith:brushland";
    case 65: return "terralith:bryce_canyon";
    case 66: return "terralith:caldera";
    case 67: return "terralith:cave/andesite_caves";
    case 69: return "terralith:cave/diorite_caves";
    case 71: return "terralith:cave/fungal_caves";
    case 72: return "terralith:cave/granite_caves";
    case 73: return "terralith:cave/infested_caves";
    case 75: return "terralith:cave/thermal_caves";
    case 77: return "terralith:cave/underground_jungle";
    case 78: return "terralith:cloud_forest";
    case 79: return "terralith:cold_shrubland";
    case 80: return "terralith:desert_canyon";
    case 81: return "terralith:desert_oasis";
    case 82: return "terralith:desert_spires";
    case 83: return "terralith:emerald_peaks";
    case 84: return "terralith:forested_highlands";
    case 85: return "terralith:fractured_savanna";
    case 86: return "terralith:frozen_cliffs";
    case 87: return "terralith:glacial_chasm";
    case 88: return "terralith:granite_cliffs";
    case 89: return "terralith:gravel_beach";
    case 90: return "terralith:gravel_desert";
    case 91: return "terralith:haze_mountain";
    case 92: return "terralith:highlands";
    case 93: return "terralith:hot_shrubland";
    case 94: return "terralith:ice_marsh";
    case 95: return "terralith:jungle_mountains";
    case 96: return "terralith:lavender_forest";
    case 97: return "terralith:lavender_valley";
    case 98: return "terralith:lush_desert";
    case 99: return "terralith:lush_valley";
    case 100: return "terralith:mirage_isles";
    case 101: return "terralith:moonlight_grove";
    case 102: return "terralith:moonlight_valley";
    case 103: return "terralith:orchid_swamp";
    case 104: return "terralith:painted_mountains";
    case 105: return "terralith:red_oasis";
    case 106: return "terralith:rocky_jungle";
    case 107: return "terralith:rocky_mountains";
    case 108: return "terralith:rocky_shrubland";
    case 109: return "terralith:sakura_grove";
    case 110: return "terralith:sakura_valley";
    case 111: return "terralith:sandstone_valley";
    case 112: return "terralith:savanna_badlands";
    case 113: return "terralith:savanna_slopes";
    case 114: return "terralith:scarlet_mountains";
    case 115: return "terralith:shield";
    case 116: return "terralith:shield_clearing";
    case 117: return "terralith:shrubland";
    case 118: return "terralith:siberian_grove";
    case 119: return "terralith:siberian_taiga";
    case 120: return "terralith:skylands_autumn";
    case 121: return "terralith:skylands_spring";
    case 122: return "terralith:skylands_summer";
    case 123: return "terralith:skylands_winter";
    case 124: return "terralith:snowy_badlands";
    case 126: return "terralith:snowy_maple_forest";
    case 187: return "terralith:snowy_shield";
    case 188: return "terralith:steppe";
    case 189: return "terralith:stony_spires";
    case 190: return "terralith:temperate_highlands";
    case 191: return "terralith:tropical_jungle";
    case 192: return "terralith:valley_clearing";
    case 193: return "terralith:volcanic_crater";
    case 194: return "terralith:volcanic_peaks";
    case 195: return "terralith:warm_river";
    case 196: return "terralith:warped_mesa";
    case 197: return "terralith:white_cliffs";
    case 198: return "terralith:white_mesa";
    case 199: return "terralith:windswept_spires";
    case 200: return "terralith:wintry_forest";
    case 201: return "terralith:wintry_lowlands";
    case 202: return "terralith:yellowstone";
    case 203: return "terralith:yosemite_cliffs";
    case 204: return "terralith:yosemite_lowlands";
    case 205: return "terralith:alpha_islands";
    case 206: return "terralith:alpha_islands_winter";
    case 207: return "terralith:alpine_grove";

    }
    return NULL;
}

const char* struct2str(int stype)
{
    switch (stype)
    {
    case Desert_Pyramid:    return "desert_pyramid";
    case Jungle_Temple:     return "jungle_pyramid";
    case Swamp_Hut:         return "swamp_hut";
    case Igloo:             return "igloo";
    case Village:           return "village";
    case Ocean_Ruin:        return "ocean_ruin";
    case Shipwreck:         return "shipwreck";
    case Monument:          return "monument";
    case Mansion:           return "mansion";
    case Outpost:           return "pillager_outpost";
    case Treasure:          return "buried_treasure";
    case Mineshaft:         return "mineshaft";
    case Desert_Well:       return "desert_well";
    case Ruined_Portal:     return "ruined_portal";
    case Ruined_Portal_N:   return "ruined_portal_nether";
    case Geode:             return "amethyst_geode";
    case Ancient_City:      return "ancient_city";
    case Trail_Ruins:       return "trail_ruins";
    case Trial_Chambers:    return "trial_chambers";
    case Fortress:          return "fortress";
    case Bastion:           return "bastion_remnant";
    case End_City:          return "end_city";
    case End_Gateway:       return "end_gateway";
    }
    return NULL;
}

static void setColor(unsigned char colors[256][3], int id, uint32_t hex)
{
    colors[id][0] = (hex >> 16) & 0xff;
    colors[id][1] = (hex >>  8) & 0xff;
    colors[id][2] = (hex >>  0) & 0xff;
}

void initBiomeColors(unsigned char colors[256][3])
{
    // This coloring scheme is largely inspired by the AMIDST program:
    // https://github.com/toolbox4minecraft/amidst/wiki/Biome-Color-Table
    // but with additional biomes for 1.18+, and with some subtle changes to
    // improve contrast for the new world generation.

    memset(colors, 0, 256*3);
    
    //               biome                             hex color     AMIDST
    setColor(colors, ocean,                            0x000070);
    setColor(colors, plains,                           0x8db360);
    setColor(colors, desert,                           0xfa9418);
    setColor(colors, windswept_hills,                  0x606060);
    setColor(colors, forest,                           0x056621);
    setColor(colors, taiga,                            0x0b6a5f); // 0b6659
    setColor(colors, swamp,                            0x07f9b2);
    setColor(colors, river,                            0x0000ff);
    setColor(colors, nether_wastes,                    0x572526); // bf3b3b
    setColor(colors, the_end,                          0x8080ff);
    setColor(colors, frozen_ocean,                     0x7070d6);
    setColor(colors, frozen_river,                     0xa0a0ff);
    setColor(colors, snowy_plains,                     0xffffff);
    setColor(colors, snowy_mountains,                  0xa0a0a0);
    setColor(colors, mushroom_fields,                  0xff00ff);
    setColor(colors, mushroom_field_shore,             0xa000ff);
    setColor(colors, beach,                            0xfade55);
    setColor(colors, desert_hills,                     0xd25f12);
    setColor(colors, wooded_hills,                     0x22551c);
    setColor(colors, taiga_hills,                      0x163933);
    setColor(colors, mountain_edge,                    0x72789a);
    setColor(colors, jungle,                           0x507b0a); // 537b09
    setColor(colors, jungle_hills,                     0x2c4205);
    setColor(colors, sparse_jungle,                    0x60930f); // 628b17
    setColor(colors, deep_ocean,                       0x000030);
    setColor(colors, stony_shore,                      0xa2a284);
    setColor(colors, snowy_beach,                      0xfaf0c0);
    setColor(colors, birch_forest,                     0x307444);
    setColor(colors, birch_forest_hills,               0x1f5f32);
    setColor(colors, dark_forest,                      0x40511a);
    setColor(colors, snowy_taiga,                      0x31554a);
    setColor(colors, snowy_taiga_hills,                0x243f36);
    setColor(colors, old_growth_pine_taiga,            0x596651);
    setColor(colors, giant_tree_taiga_hills,           0x454f3e);
    setColor(colors, windswept_forest,                 0x5b7352); // 507050
    setColor(colors, savanna,                          0xbdb25f);
    setColor(colors, savanna_plateau,                  0xa79d64);
    setColor(colors, badlands,                         0xd94515);
    setColor(colors, wooded_badlands,                  0xb09765);
    setColor(colors, badlands_plateau,                 0xca8c65);
    setColor(colors, small_end_islands,                0x4b4bab); // 8080ff
    setColor(colors, end_midlands,                     0xc9c959); // 8080ff
    setColor(colors, end_highlands,                    0xb5b536); // 8080ff
    setColor(colors, end_barrens,                      0x7070cc); // 8080ff
    setColor(colors, warm_ocean,                       0x0000ac);
    setColor(colors, lukewarm_ocean,                   0x000090);
    setColor(colors, cold_ocean,                       0x202070);
    setColor(colors, deep_warm_ocean,                  0x000050);
    setColor(colors, deep_lukewarm_ocean,              0x000040);
    setColor(colors, deep_cold_ocean,                  0x202038);
    setColor(colors, deep_frozen_ocean,                0x404090);
    setColor(colors, seasonal_forest,                  0x2f560f); // -
    setColor(colors, rainforest,                       0x47840e); // -
    setColor(colors, shrubland,                        0x789e31); // -
    setColor(colors, the_void,                         0x000000);
    setColor(colors, sunflower_plains,                 0xb5db88);
    setColor(colors, desert_lakes,                     0xffbc40);
    setColor(colors, windswept_gravelly_hills,         0x888888);
    setColor(colors, flower_forest,                    0x2d8e49);
    setColor(colors, taiga_mountains,                  0x339287); // 338e81
    setColor(colors, swamp_hills,                      0x2fffda);
    setColor(colors, ice_spikes,                       0xb4dcdc);
    setColor(colors, modified_jungle,                  0x78a332); // 7ba331
    setColor(colors, modified_jungle_edge,             0x88bb37); // 8ab33f
    setColor(colors, old_growth_birch_forest,          0x589c6c);
    setColor(colors, tall_birch_hills,                 0x47875a);
    setColor(colors, dark_forest_hills,                0x687942);
    setColor(colors, snowy_taiga_mountains,            0x597d72);
    setColor(colors, old_growth_spruce_taiga,          0x818e79);
    setColor(colors, giant_spruce_taiga_hills,         0x6d7766);
    setColor(colors, modified_gravelly_mountains,      0x839b7a); // 789878
    setColor(colors, windswept_savanna,                0xe5da87);
    setColor(colors, shattered_savanna_plateau,        0xcfc58c);
    setColor(colors, eroded_badlands,                  0xff6d3d);
    setColor(colors, modified_wooded_badlands_plateau, 0xd8bf8d);
    setColor(colors, modified_badlands_plateau,        0xf2b48d);
    setColor(colors, bamboo_jungle,                    0x849500); // 768e14
    setColor(colors, bamboo_jungle_hills,              0x5c6c04); // 3b470a
    setColor(colors, soul_sand_valley,                 0x4d3a2e); // 5e3830
    setColor(colors, crimson_forest,                   0x981a11); // dd0808
    setColor(colors, warped_forest,                    0x49907b);
    setColor(colors, basalt_deltas,                    0x645f63); // 403636
    setColor(colors, dripstone_caves,                  0x4e3012); // -
    setColor(colors, lush_caves,                       0x283c00); // -
    setColor(colors, meadow,                           0x60a445); // -
    setColor(colors, grove,                            0x47726c); // -
    setColor(colors, snowy_slopes,                     0xc4c4c4); // -
    setColor(colors, jagged_peaks,                     0xdcdcc8); // -
    setColor(colors, frozen_peaks,                     0xb0b3ce); // -
    setColor(colors, stony_peaks,                      0x7b8f74); // -
    setColor(colors, deep_dark,                        0x031f29); // -
    setColor(colors, mangrove_swamp,                   0x2ccc8e); // -
    setColor(colors, cherry_grove,                     0xff91c8); // -
    setColor(colors, pale_garden,                      0x726c68); // -

    // terralith
    setColor(colors, 202, 0x888888);
    setColor(colors, 65, 0x881E1D);
    setColor(colors, 107, 0x323232);
    setColor(colors, 56, 0xA15DDC);
    setColor(colors, 86, 0x78C1FF);
    setColor(colors, 197, 0xE5E5E5);
    setColor(colors, 60, 0x3E3E3E);
    setColor(colors, 205, 0x63FF32);
    setColor(colors, 88, 0xCE7C84);
    setColor(colors, 114, 0xAB1334);
    setColor(colors, 119, 0x627788);
    setColor(colors, 115, 0x616D51);
    setColor(colors, 106, 0x46773C);
    setColor(colors, 104, 0xF0B7B7);
    setColor(colors, 99, 0x485F44);
    setColor(colors, 87, 0x2AEADD);
    setColor(colors, 95, 0x2D8F00);
    setColor(colors, 63, 0x03E28D);
    setColor(colors, 111, 0xD8DD88);
    setColor(colors, 101, 0x8597C1);
    setColor(colors, 91, 0xA7A490);
    setColor(colors, 85, 0x8D7C58);
    setColor(colors, 55, 0x991DD3);
    setColor(colors, 109, 0xFFC7E5);
    setColor(colors, 93, 0x5C1A0A);
    setColor(colors, 117, 0x906B5A);
    setColor(colors, 79, 0x345640);
    setColor(colors, 89, 0x918494);
    setColor(colors, 96, 0xE0B5F7);
    setColor(colors, 203, 0xB3DBC2);
    setColor(colors, 204, 0x568F67);
    setColor(colors, 83, 0x2A8D5A);
    setColor(colors, 92, 0xB7E1BF);
    setColor(colors, 78, 0x7C98B1);
    setColor(colors, 84, 0x4E9778);
    setColor(colors, 108, 0x563115);
    setColor(colors, 190, 0xE18937);
    setColor(colors, 112, 0xC5B19B);
    setColor(colors, 94, 0x477670);
    setColor(colors, 200, 0x95B1D5);
    setColor(colors, 58, 0xBD976B);
    setColor(colors, 194, 0x0D0D0D);
    setColor(colors, 193, 0xFF5005);
    setColor(colors, 90, 0x9C92A0);
    setColor(colors, 198, 0xDFCBBF);
    setColor(colors, 120, 0xFEBA54);
    setColor(colors, 100, 0x02FFEF);
    setColor(colors, 196, 0x257188);
    setColor(colors, 188, 0x728874);
    setColor(colors, 62, 0x4FA470);
    setColor(colors, 64, 0x92DB50);
    setColor(colors, 124, 0x884E3F);
    setColor(colors, 102, 0x6CA5BF);
    setColor(colors, 66, 0x884539);
    setColor(colors, 192, 0x6E8852);
    setColor(colors, 61, 0x538854);
    setColor(colors, 81, 0xC6D51D);
    setColor(colors, 191, 0xB2FF00);
    setColor(colors, 57, 0xFF8E82);
    setColor(colors, 59, 0x988B73);
    setColor(colors, 113, 0x883949);
    setColor(colors, 110, 0x882C78);
    setColor(colors, 97, 0x9078C5);
    setColor(colors, 126, 0xDB6D63);
    setColor(colors, 187, 0x887F24);
    setColor(colors, 118, 0xEC8C5A);
    setColor(colors, 82, 0x868848);
    setColor(colors, 189, 0x886A60);
    setColor(colors, 199, 0x618875);
    setColor(colors, 103, 0x51C2C6);
    setColor(colors, 207, 0x8E9ABE);
    setColor(colors, 54, 0x68954E);
    setColor(colors, 195, 0x695CE4);
    setColor(colors, 105, 0xFF6600);
    setColor(colors, 116, 0x848845);
    setColor(colors, 206, 0xA9BEE3);
    setColor(colors, 122, 0x4BD765);
    setColor(colors, 121, 0xEC9FDD);
    setColor(colors, 123, 0xA4F5FB);
    setColor(colors, 80, 0x887F11);
    setColor(colors, 201, 0x437688);
    setColor(colors, 98, 0x6E6034);
    setColor(colors, 67, 0xC6C5D4);
    setColor(colors, 69, 0xE2E1F2);
    setColor(colors, 71, 0xC29F76);
    setColor(colors, 72, 0xDE9785);
    setColor(colors, 73, 0x87457E);
    setColor(colors, 75, 0xC7551C);
    setColor(colors, 77, 0x1D9639);

}

void initBiomeTypeColors(unsigned char colors[256][3])
{
    memset(colors, 0, 256*3);

    setColor(colors, Oceanic,  0x0000a0);
    setColor(colors, Warm,     0xffc000);
    setColor(colors, Lush,     0x00a000);
    setColor(colors, Cold,     0x606060);
    setColor(colors, Freezing, 0xffffff);
}


// find the longest biome name contained in 's'
static int _str2id(const char *s)
{
    if (*s == 0)
        return -1;
    const char *f = NULL;
    int ret = -1, id;
    for (id = 0; id < 256; id++)
    {
        const char *p = biome2str(MC_NEWEST, id);
        if (p && (!f || strlen(f) < strlen(p)))
            if (strstr(s, p)) {f = p; ret = id;}

        const char *t = biome2str(MC_1_17, id);
        if (t && t != p && (!f || strlen(f) < strlen(t)))
            if (strstr(s, t)) {f = t; ret = id;}
    }
    return ret;
}

int parseBiomeColors(unsigned char biomeColors[256][3], const char *buf)
{
    const char *p = buf;
    char bstr[64];
    int id, col[4], n, ib, ic;
    n = 0;
    while (*p)
    {
        for (ib = ic = 0; *p && *p != '\n' && *p != ';'; p++)
        {
            if ((size_t)ib+1 < sizeof(bstr))
            {
                if ((*p >= 'a' && *p <= 'z') || *p == '_')
                    bstr[ib++] = *p;
                else if (*p >= 'A' && *p <= 'Z')
                    bstr[ib++] = (*p - 'A') + 'a';
            }
            if (ic < 4 && (*p == '#' || (p[0] == '0' && p[1] == 'x')))
                col[ic++] = strtol(p+1+(*p=='0'), (char**)&p, 16);
            else if (ic < 4 && *p >= '0' && *p <= '9')
                col[ic++] = strtol(p, (char**)&p, 10);
            if (*p == '\n' || *p == ';')
                break;
        }
        while (*p && *p != '\n') p++;
        while (*p == '\n') p++;

        bstr[ib] = 0;
        id = _str2id(bstr);
        if (id >= 0 && id < 256)
        {
            if (ic == 3)
            {
                biomeColors[id][0] = col[0] & 0xff;
                biomeColors[id][1] = col[1] & 0xff;
                biomeColors[id][2] = col[2] & 0xff;
                n++;
            }
            else if (ic == 1)
            {
                biomeColors[id][0] = (col[0] >> 16) & 0xff;
                biomeColors[id][1] = (col[0] >>  8) & 0xff;
                biomeColors[id][2] = (col[0] >>  0) & 0xff;
                n++;
            }
        }
        else if (ic == 4)
        {
            id = col[0] & 0xff;
            biomeColors[id][0] = col[1] & 0xff;
            biomeColors[id][1] = col[2] & 0xff;
            biomeColors[id][2] = col[3] & 0xff;
            n++;
        }
        else if (ic == 2)
        {
            id = col[0] & 0xff;
            biomeColors[id][0] = (col[1] >> 16) & 0xff;
            biomeColors[id][1] = (col[1] >>  8) & 0xff;
            biomeColors[id][2] = (col[1] >>  0) & 0xff;
            n++;
        }
    }
    return n;
}


int biomesToImage(unsigned char *pixels,
        unsigned char biomeColors[256][3], const int *biomes,
        const unsigned int sx, const unsigned int sy,
        const unsigned int pixscale, const int flip)
{
    unsigned int i, j;
    int containsInvalidBiomes = 0;

    for (j = 0; j < sy; j++)
    {
        for (i = 0; i < sx; i++)
        {
            int id = biomes[j*sx+i];
            unsigned int r, g, b;

            if (id < 0 || id >= 256)
            {
                // This may happen for some intermediate layers
                containsInvalidBiomes = 1;
                r = biomeColors[id&0x7f][0]-40; r = (r>0xff) ? 0x00 : r&0xff;
                g = biomeColors[id&0x7f][1]-40; g = (g>0xff) ? 0x00 : g&0xff;
                b = biomeColors[id&0x7f][2]-40; b = (b>0xff) ? 0x00 : b&0xff;
            }
            else
            {
                r = biomeColors[id][0];
                g = biomeColors[id][1];
                b = biomeColors[id][2];
            }

            unsigned int m, n;
            for (m = 0; m < pixscale; m++) {
                for (n = 0; n < pixscale; n++) {
                    int idx = pixscale * i + n;
                    if (flip)
                        idx += (sx * pixscale) * ((pixscale * j) + m);
                    else
                        idx += (sx * pixscale) * ((pixscale * (sy-1-j)) + m);

                    unsigned char *pix = pixels + 3*idx;
                    pix[0] = (unsigned char)r;
                    pix[1] = (unsigned char)g;
                    pix[2] = (unsigned char)b;
                }
            }
        }
    }

    return containsInvalidBiomes;
}

int savePPM(const char *path, const unsigned char *pixels, const unsigned int sx, const unsigned int sy)
{
    FILE *fp = fopen(path, "wb");
    if (!fp)
        return -1;
    fprintf(fp, "P6\n%d %d\n255\n", sx, sy);
    size_t pixelsLen = 3 * sx * sy;
    size_t written = fwrite(pixels, sizeof pixels[0], pixelsLen, fp);
    fclose(fp);
    return written != pixelsLen;
}


