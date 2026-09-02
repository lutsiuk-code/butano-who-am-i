#ifndef BN_REGULAR_BG_TILES_ITEMS_CONNIE_HOUSE_TILES_32X32_H
#define BN_REGULAR_BG_TILES_ITEMS_CONNIE_HOUSE_TILES_32X32_H

#include "bn_regular_bg_tiles_item.h"

//{{BLOCK(connie_house_tiles_32x32_bn_gfx)

//======================================================================
//
//	connie_house_tiles_32x32_bn_gfx, 256x256@4, 
//	+ 1024 tiles not compressed
//	Total size: 32768 = 32768
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CONNIE_HOUSE_TILES_32X32_BN_GFX_H
#define GRIT_CONNIE_HOUSE_TILES_32X32_BN_GFX_H

#define connie_house_tiles_32x32_bn_gfxTilesLen 32768
extern const bn::tile connie_house_tiles_32x32_bn_gfxTiles[1024];

#endif // GRIT_CONNIE_HOUSE_TILES_32X32_BN_GFX_H

//}}BLOCK(connie_house_tiles_32x32_bn_gfx)

namespace bn::regular_bg_tiles_items
{
    constexpr inline regular_bg_tiles_item connie_house_tiles_32x32(
            span<const tile>(connie_house_tiles_32x32_bn_gfxTiles, 1024), bpp_mode::BPP_4, compression_type::NONE);
}

#endif

