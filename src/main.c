/*
** From http://forums.getpebble.com/discussion/18083/draw-text-outline-in-custom-layer
*/

#include <pebble.h>
 
Window *my_window;
Layer *text_layer;
char lorem[64];

void graphics_draw_text_with_outline(GContext * ctx, const char * text, GFont const font, const GRect box, const GTextOverflowMode overflow_mode, const GTextAlignment alignment, const GTextLayoutCacheRef layout, GColor outline_color, GColor inside_color)
{
#define OUTLINE_WIDTH (1)  // larger size, looks worse with small font pitch
#define OUTLINE_OFFSET (OUTLINE_WIDTH + 1)
//#define OUTLINE_OFFSET (OUTLINE_WIDTH * 2)  // as OUTLINE_WIDTH gets larger, outline look more like a shadow with a direction which this helps correct

    graphics_context_set_text_color(ctx, outline_color);
    graphics_draw_text(ctx, text, font, GRect(box.origin.x,box.origin.y, box.size.w,box.size.h), overflow_mode, alignment, layout);

    graphics_draw_text(ctx, text, font, GRect(box.origin.x+OUTLINE_OFFSET,box.origin.y, box.size.w,box.size.h), overflow_mode, alignment, layout);

    graphics_draw_text(ctx, text, font, GRect(box.origin.x,box.origin.y+OUTLINE_OFFSET, box.size.w,box.size.h), overflow_mode, alignment, layout);

    graphics_draw_text(ctx, text, font, GRect(box.origin.x+OUTLINE_OFFSET,box.origin.y+OUTLINE_OFFSET, box.size.w,box.size.h), overflow_mode, alignment, layout);

    graphics_context_set_text_color(ctx, inside_color);
    graphics_draw_text(ctx, text, font, GRect(box.origin.x+OUTLINE_WIDTH,box.origin.y+OUTLINE_WIDTH, box.size.w,box.size.h), overflow_mode, alignment, layout);
}

void draw_custom(Layer *this_layer, GContext *ctx){
    graphics_draw_text_with_outline(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_14), GRect(1,1, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL, GColorBlack, GColorWhite);

    graphics_draw_text_with_outline(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD), GRect(1,31, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL, GColorBlack, GColorWhite);

    graphics_draw_text_with_outline(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_28), GRect(1,61, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL, GColorBlack, GColorWhite);

    graphics_draw_text_with_outline(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD), GRect(1,91, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL, GColorBlack, GColorWhite);

    graphics_draw_text_with_outline(ctx, lorem, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK), GRect(1,121, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL, GColorBlack, GColorWhite);
}

void handle_init(void) {
    my_window = window_create();
    strcpy(lorem, "Lorem ipsum dolor sit amet, consectetur adipiscing elit nullam.");
    text_layer = layer_create(GRect(0, 0, 144, 168));
    layer_set_update_proc(text_layer, draw_custom);
    layer_add_child(window_get_root_layer(my_window), text_layer);
    window_stack_push(my_window, true);
}

void handle_deinit(void) {
    layer_destroy(text_layer);
    window_destroy(my_window);
}

int main(void) {
    handle_init();
    app_event_loop();
    handle_deinit();
}
