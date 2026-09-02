#ifndef BN_REGULAR_BG_ITEMS_ROOM_H
#define BN_REGULAR_BG_ITEMS_ROOM_H

#include "bn_regular_bg_item.h"

//{{BLOCK(room_bn_gfx)

//======================================================================
//
//	room_bn_gfx, 512x512@4, 
//	+ palette 16 entries, not compressed
//	+ 41 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 32 + 1312 + 8192 = 9536
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ROOM_BN_GFX_H
#define GRIT_ROOM_BN_GFX_H

#define room_bn_gfxTilesLen 1312
extern const bn::tile room_bn_gfxTiles[41];

#define room_bn_gfxMapLen 8192
extern const bn::regular_bg_map_cell room_bn_gfxMap[4096];

#define room_bn_gfxPalLen 32
extern const bn::color room_bn_gfxPal[16];

#endif // GRIT_ROOM_BN_GFX_H

//}}BLOCK(room_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item room(
            regular_bg_tiles_item(span<const tile>(room_bn_gfxTiles, 41), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(room_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(room_bn_gfxMap[0], size(64, 64), compression_type::NONE, 1, false));
}

#endif

