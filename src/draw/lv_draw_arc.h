/**
 * @file lv_draw_arc.h
 *
 */

#ifndef LV_DRAW_ARC_H
#define LV_DRAW_ARC_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../lv_conf_internal.h"
#include "../misc/lv_color.h"
#include "../misc/lv_area.h"
#include "../misc/lv_style.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    lv_draw_dsc_base_t base;

    /**The color of the arc*/
    lv_color_t color;

    /**The width (thickness) of the arc */
    int32_t width;

    /**The start angle in 1 degree units (if `LV_USE_FLOAT` is enabled a float number can be also used)
     * 0° is the 3 o'clock position, 90° is the 6 o'clock, etc. */
    lv_value_precise_t start_angle;

    /**The end angle, similarly to start_angle. */
    lv_value_precise_t end_angle;

    /**The center point of the arc. */
    lv_point_t center;

    /**An image source to be used instead of `color`. `NULL` if unused*/
    const void * img_src;

    /**The outer radius of the arc*/
    uint16_t radius;

    /**Opacity of the arc in 0...255 range.
     * LV_OPA_TRANSP, LV_OPA_10, LV_OPA_20, .. LV_OPA_COVER can be used as well*/
    lv_opa_t opa;

    /**1: Make the arc ends rounded*/
    uint8_t rounded : 1;
} lv_draw_arc_dsc_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize an arc draw descriptor.
 * @param dsc       pointer to a draw descriptor
 */
void lv_draw_arc_dsc_init(lv_draw_arc_dsc_t * dsc);

/**
 * Try to get an arc draw descriptor from a draw task.
 * @param task      draw task
 * @return          the task's draw descriptor or NULL if the task is not of type LV_DRAW_TASK_TYPE_ARC
 */
lv_draw_arc_dsc_t * lv_draw_task_get_arc_dsc(lv_draw_task_t * task);

/**
 * Create an arc draw task.
 * @param layer         pointer to a layer
 * @param dsc           pointer to an initialized draw descriptor variable
 */
void lv_draw_arc(lv_layer_t * layer, const lv_draw_arc_dsc_t * dsc);

/**
 * Get an area the should be invalidated when the arcs angle changed between start_angle and end_ange
 * @param x             the x coordinate of the center of the arc
 * @param y             the y coordinate of the center of the arc
 * @param radius        the radius of the arc
 * @param start_angle   the start angle of the arc (0 deg on the bottom, 90 deg on the right)
 * @param end_angle     the end angle of the arc
 * @param w             width of the arc
 * @param rounded       true: the arc is rounded
 * @param area          store the area to invalidate here
 */
void lv_draw_arc_get_area(int32_t x, int32_t y, uint16_t radius,  lv_value_precise_t start_angle,
                          lv_value_precise_t end_angle,
                          int32_t w, bool rounded, lv_area_t * area);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_DRAW_ARC_H*/
