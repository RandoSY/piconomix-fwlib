#include "px_gfx.h"
#include "px_gfx_resources.h"

void px_gfx_test_start(void)
{
    // Initialise graphics
    px_gfx_init();

    // Draw pixels
    px_gfx_draw_pixel(PX_GFX_X_MID, PX_GFX_Y_MID - 5);
    px_gfx_draw_pixel(PX_GFX_X_MID, PX_GFX_Y_MID + 5);

    // Draw lines
    px_gfx_draw_line(0, 0, PX_GFX_X_MAX, PX_GFX_Y_MAX);
    px_gfx_draw_line(0, PX_GFX_Y_MAX, PX_GFX_X_MAX, 0);

    // Draw rectangle
    px_gfx_draw_rect(0, 0, PX_GFX_DISP_SIZE_X, PX_GFX_DISP_SIZE_Y);

    // Draw circle
    px_gfx_draw_circ(PX_GFX_X_MID, PX_GFX_Y_MID, 20);

    // Draw text
    px_gfx_draw_str(&px_gfx_font_5x7, 30, 2, "Hello World!");

    // Draw image
    px_gfx_draw_img(&px_gfx_img_dino,
                    PX_GFX_X_MID + 30, 
                    PX_GFX_Y_MID - 15);
}

void px_gfx_test_update(void)
{
    // Update display
    px_gfx_update_frame();
}

