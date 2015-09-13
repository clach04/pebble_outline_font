/*
** From http://forums.getpebble.com/discussion/18083/draw-text-outline-in-custom-layer
*/

#include <pebble.h>
 
Window *my_window;
Layer *text_layer;
char lorem[64];

void draw_text(GContext *ctx, char * the_text, GFont the_font, int16_t x, int16_t y, int16_t w, int16_t h)
{
    graphics_context_set_text_color(ctx, GColorBlack);
    //graphics_draw_text(ctx, the_text, the_font, GRect(1,1, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, the_text, the_font, GRect(x,y, w,h), GTextOverflowModeFill, GTextAlignmentLeft, NULL);

    //graphics_draw_text(ctx, the_text, the_font, GRect(3,1, w,h), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, the_text, the_font, GRect(x+2,y, w,h), GTextOverflowModeFill, GTextAlignmentLeft, NULL);

    //graphics_draw_text(ctx, the_text, the_font, GRect(1,3, w,h), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, the_text, the_font, GRect(x,y+2, w,h), GTextOverflowModeFill, GTextAlignmentLeft, NULL);

    //graphics_draw_text(ctx, the_text, the_font, GRect(3,3, w,h), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, the_text, the_font, GRect(x+2,y+2, w,h), GTextOverflowModeFill, GTextAlignmentLeft, NULL);

    graphics_context_set_text_color(ctx, GColorWhite);
    //graphics_draw_text(ctx, the_text, the_font, GRect(2,2, w,h), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, the_text, the_font, GRect(x+1,y+1, w,h), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
}

void draw_custom(Layer *this_layer, GContext *ctx){
    draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_14), 1,1, 144,32);

    draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD), 1,31, 144,32);

    draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_28), 1,61, 144,32);

    draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD), 1,91, 144,32);

    draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK), 1,121, 144,32);

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
