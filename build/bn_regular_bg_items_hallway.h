#ifndef BN_REGULAR_BG_ITEMS_HALLWAY_H
#define BN_REGULAR_BG_ITEMS_HALLWAY_H

#include "bn_regular_bg_item.h"

//{{BLOCK(hallway_bn_gfx)

//======================================================================
//
//	hallway_bn_gfx, 512x512@4, 
//	+ palette 16 entries, not compressed
//	+ 30 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 32 + 960 + 8192 = 9184
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_HALLWAY_BN_GFX_H
#define GRIT_HALLWAY_BN_GFX_H

#define hallway_bn_gfxTilesLen 960
extern const bn::tile hallway_bn_gfxTiles[30];

#define hallway_bn_gfxMapLen 8192
extern const bn::regular_bg_map_cell hallway_bn_gfxMap[4096];

#define hallway_bn_gfxPalLen 32
extern const bn::color hallway_bn_gfxPal[16];

#endif // GRIT_HALLWAY_BN_GFX_H

//}}BLOCK(hallway_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item hallway(
            regular_bg_tiles_item(span<const tile>(hallway_bn_gfxTiles, 30), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(hallway_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(hallway_bn_gfxMap[0], size(64, 64), compression_type::NONE, 1, false));
}

#endif

