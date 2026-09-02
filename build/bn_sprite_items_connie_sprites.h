#ifndef BN_SPRITE_ITEMS_CONNIE_SPRITES_H
#define BN_SPRITE_ITEMS_CONNIE_SPRITES_H

#include "bn_sprite_item.h"

//{{BLOCK(connie_sprites_bn_gfx)

//======================================================================
//
//	connie_sprites_bn_gfx, 288x32@8, 
//	+ palette 128 entries, not compressed
//	+ 144 tiles Metatiled by 4x4 not compressed
//	Total size: 256 + 9216 = 9472
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CONNIE_SPRITES_BN_GFX_H
#define GRIT_CONNIE_SPRITES_BN_GFX_H

#define connie_sprites_bn_gfxTilesLen 9216
extern const bn::tile connie_sprites_bn_gfxTiles[288];

#define connie_sprites_bn_gfxPalLen 256
extern const bn::color connie_sprites_bn_gfxPal[128];

#endif // GRIT_CONNIE_SPRITES_BN_GFX_H

//}}BLOCK(connie_sprites_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item connie_sprites(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(connie_sprites_bn_gfxTiles, 288), bpp_mode::BPP_8, compression_type::NONE, 9), 
            sprite_palette_item(span<const color>(connie_sprites_bn_gfxPal, 128), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

