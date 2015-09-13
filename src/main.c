/*
** From http://forums.getpebble.com/discussion/18083/draw-text-outline-in-custom-layer
*/

#include <pebble.h>
 
Window *my_window;
Layer *text_layer;
char lorem[64];
 
void draw_custom(Layer *this_layer, GContext *ctx){
    graphics_context_set_text_color(ctx, GColorBlack);
    
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_14), GRect(1,1, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_14), GRect(3,1, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_14), GRect(1,3, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_14), GRect(3,3, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
 
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD), GRect(1,31, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL); 
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD), GRect(3,31, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD), GRect(1,33, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD), GRect(3,33, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
   
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_28), GRect(1,61, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_28), GRect(3,61, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_28), GRect(1,63, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_28), GRect(3,63, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
 
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD), GRect(1,91, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD), GRect(3,91, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD), GRect(1,93, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD), GRect(3,93, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
 
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK), GRect(1,121, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK), GRect(3,121, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK), GRect(1,123, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK), GRect(3,123, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
    
    graphics_context_set_text_color(ctx, GColorWhite);
 
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_14), GRect(2,2, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
 
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD), GRect(2,32, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
 
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_28), GRect(2,62, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
 
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD), GRect(2,92, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
 
    graphics_draw_text(ctx, lorem, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK), GRect(2,122, 144,32), GTextOverflowModeFill, GTextAlignmentLeft, NULL);
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
