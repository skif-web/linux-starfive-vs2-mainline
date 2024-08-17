/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2023 VeriSilicon Holdings Co., Ltd.
 */

#ifndef __VS_DC_HW_H__
#define __VS_DC_HW_H__

#include <linux/bitfield.h>
#include <linux/bits.h>
#include <drm/drm_atomic.h>

#include "vs_type.h"

#define UPDATE(x, h, l)				FIELD_PREP(GENMASK(h, l), x)

#define AQ_INTR_ACKNOWLEDGE			0x0010
#define AQ_INTR_ENBL				0x0014
#define DC_HW_REVISION				0x0024
#define DC_HW_CHIP_CID				0x0030

#define DC_REG_BASE				0x0800
#define DC_REG_RANGE				0x2000
#define DC_SEC_REG_OFFSET			0x100000

#define DC_FRAMEBUFFER_CONFIG			0x1518
# define PRIMARY_FORMAT(x)			((x) << 26)
# define PRIMARY_FORMAT_MASK			GENMASK(31, 26)
# define PRIMARY_UV_SWIZ(x)			((x) << 25)
# define PRIMARY_UV_SWIZ_MASK			GENMASK(25, 25)
# define PRIMARY_SWIZ(x)			((x) << 23)
# define PRIMARY_SWIZ_MASK			GENMASK(24, 23)
# define PRIMARY_SCALE_EN			BIT(12)
# define PRIMARY_TILE(x)			((x) << 17)
# define PRIMARY_TILE_MASK			GENMASK(21, 17)
# define PRIMARY_YUV_COLOR(x)			((x) << 14)
# define PRIMARY_YUV_COLOR_MASK			GENMASK(16, 14)
# define PRIMARY_ROTATION(x)			((x) << 11)
# define PRIMARY_ROTATION_MASK			GENMASK(13, 11)
# define PRIMARY_CLEAR_EN(x)			((x) << 8)
# define PRIMARY_CLEAR_EN_MASK			GENMASK(8, 8)

#define DC_FRAMEBUFFER_CONFIG_EX		0x1CC0
# define PRIMARY_CHANNEL(x)			((x) << 19)
# define PRIMARY_CHANNEL_MASK			GENMASK(19, 19)
# define PRIMARY_ZPOS(x)			((x) << 16)
# define PRIMARY_ZPOS_MASK			GENMASK(18, 16)
# define PRIMARY_EN(x)				((x) << 13)
# define PRIMARY_EN_MASK			GENMASK(13, 13)
# define PRIMARY_SHADOW_EN			BIT(12)
# define PRIMARY_YUVCLAMP_EN			BIT(8)
# define PRIMARY_RGB2RGB_EN			BIT(6)
# define PRIMARY_SYNC1_EN			BIT(4)
# define PRIMARY_SYNC0_EN			BIT(3)
# define PRIMARY_DECODER_EN(x)			((x) << 1)
# define PRIMARY_DECODER_EN_EN_MASK		GENMASK(1, 1)

#define DC_FRAMEBUFFER_SCALE_CONFIG		0x1520
#define DC_FRAMEBUFFER_TOP_LEFT			0x24D8
#define X_POS(x)				(x)
#define Y_POS(x)				((x) << 15)

#define DC_FRAMEBUFFER_BOTTOM_RIGHT		0x24E0
#define DC_FRAMEBUFFER_ADDRESS			0x1400
#define DC_FRAMEBUFFER_U_ADDRESS		0x1530
#define DC_FRAMEBUFFER_V_ADDRESS		0x1538
#define DC_FRAMEBUFFER_STRIDE			0x1408
#define DC_FRAMEBUFFER_U_STRIDE			0x1800
#define DC_FRAMEBUFFER_V_STRIDE			0x1808
#define DC_FRAMEBUFFER_SIZE			0x1810
#define FB_SIZE(w, h)				((w) | ((h) << 15))

#define DC_FRAMEBUFFER_SCALE_FACTOR_X		0x1828
#define DC_FRAMEBUFFER_SCALE_FACTOR_Y		0x1830
#define DC_FRAMEBUFFER_H_FILTER_COEF_INDEX	0x1838
#define DC_FRAMEBUFFER_H_FILTER_COEF_DATA	0x1A00
#define DC_FRAMEBUFFER_V_FILTER_COEF_INDEX	0x1A08
#define DC_FRAMEBUFFER_V_FILTER_COEF_DATA	0x1A10
#define DC_FRAMEBUFFER_INIT_OFFSET		0x1A20
#define DC_FRAMEBUFFER_COLOR_KEY		0x1508
#define DC_FRAMEBUFFER_COLOR_KEY_HIGH		0x1510
#define DC_FRAMEBUFFER_CLEAR_VALUE		0x1A18
#define DC_FRAMEBUFFER_COLOR_TABLE_INDEX	0x1818
#define DC_FRAMEBUFFER_COLOR_TABLE_DATA		0x1820
#define DC_FRAMEBUFFER_BG_COLOR			0x1528
#define DC_FRAMEBUFFER_ROI_ORIGIN		0x1CB0
#define DC_FRAMEBUFFER_ROI_SIZE			0x1CB8
#define DC_FRAMEBUFFER_WATER_MARK		0x1CE8
#define DC_FRAMEBUFFER_DEGAMMA_INDEX		0x1D88
#define DC_FRAMEBUFFER_DEGAMMA_DATA		0x1D90
#define DC_FRAMEBUFFER_DEGAMMA_EX_DATA		0x1D98
#define DC_FRAMEBUFFER_YUVTORGB_COEF0		0x1DA0
#define DC_FRAMEBUFFER_YUVTORGB_COEF1		0x1DA8
#define DC_FRAMEBUFFER_YUVTORGB_COEF2		0x1DB0
#define DC_FRAMEBUFFER_YUVTORGB_COEF3		0x1DB8
#define DC_FRAMEBUFFER_YUVTORGB_COEF4		0x1E00
#define DC_FRAMEBUFFER_YUVTORGB_COEFD0		0x1E08
#define DC_FRAMEBUFFER_YUVTORGB_COEFD1		0x1E10
#define DC_FRAMEBUFFER_YUVTORGB_COEFD2		0x1E18
#define DC_FRAMEBUFFER_Y_CLAMP_BOUND		0x1E88
#define DC_FRAMEBUFFER_UV_CLAMP_BOUND		0x1E90
#define DC_FRAMEBUFFER_RGBTORGB_COEF0		0x1E20
#define DC_FRAMEBUFFER_RGBTORGB_COEF1		0x1E28
#define DC_FRAMEBUFFER_RGBTORGB_COEF2		0x1E30
#define DC_FRAMEBUFFER_RGBTORGB_COEF3		0x1E38
#define DC_FRAMEBUFFER_RGBTORGB_COEF4		0x1E40
#define DC_FRAMEBUFFER_BLEND_CONFIG		0x2510
# define BLEND_PREMULTI				0x3450
# define BLEND_COVERAGE				0x3950
# define BLEND_PIXEL_NONE			0x3548

#define DC_FRAMEBUFFER_SRC_GLOBAL_COLOR		0x2500
# define PRIMARY_ALPHA_LEN(x)			((x) << 24)

#define DC_FRAMEBUFFER_DST_GLOBAL_COLOR		0x2508

#define DC_OVERLAY_CONFIG			0x1540
# define OVERLAY_SHADOW_EN			BIT(31)
# define OVERLAY_CLAMP_EN			BIT(30)
# define OVERLAY_RGB2RGB_EN			BIT(29)
# define OVERLAY_DEC_EN(x)			((x) << 27)
# define OVERLAY_DEC_EN_MASK			GENMASK(27, 27)
# define OVERLAY_CLEAR_EN(x)			((x) << 25)
# define OVERLAY_CLEAR_EN_MASK			GENMASK(25, 25)
# define OVERLAY_FB_EN(x)			((x) << 24)
# define OVERLAY_FB_EN_MASK			GENMASK(24, 24)
# define OVERLAY_FORMAT(x)			((x) << 16)
# define OVERLAY_FORMAT_MASK			GENMASK(21, 16)
# define OVERLAY_UV_SWIZ(x)			((x) << 15)
# define OVERLAY_UV_SWIZ_MASK			GENMASK(15, 15)
# define OVERLAY_SWIZ(x)			((x) << 13)
# define OVERLAY_SWIZ_MASK			GENMASK(14, 13)
# define OVERLAY_TILE(x)			((x) << 8)
# define OVERLAY_TILE_MASK			GENMASK(12, 8)
# define OVERLAY_YUV_COLOR(x)			((x) << 5)
# define OVERLAY_YUV_COLOR_MASK			GENMASK(7, 5)
# define OVERLAY_ROTATION(x)			((x) << 2)
# define OVERLAY_ROTATION_MASK			GENMASK(4, 2)

#define DC_OVERLAY_CONFIG_EX			0x2540
# define OVERLAY_LAYER_SEL(x)			((x) << 0)
# define OVERLAY_LAYER_SEL_MASK			GENMASK(2, 0)
# define OVERLAY_PANEL_SEL(x)			((x) << 3)
# define OVERLAY_PANEL_SEL_MASK			GENMASK(3, 3)

#define DC_OVERLAY_SCALE_CONFIG			0x1C00
# define OVERLAY_SCALE_EN			BIT(8)

#define DC_OVERLAY_BLEND_CONFIG			0x1580
#define DC_OVERLAY_TOP_LEFT			0x1640
#define DC_OVERLAY_BOTTOM_RIGHT			0x1680
#define DC_OVERLAY_ADDRESS			0x15C0
#define DC_OVERLAY_U_ADDRESS			0x1840
#define DC_OVERLAY_V_ADDRESS			0x1880
#define DC_OVERLAY_STRIDE			0x1600
#define DC_OVERLAY_U_STRIDE			0x18C0
#define DC_OVERLAY_V_STRIDE			0x1900
#define DC_OVERLAY_SIZE				0x17C0
#define DC_OVERLAY_SCALE_FACTOR_X		0x1A40
#define DC_OVERLAY_SCALE_FACTOR_Y		0x1A80
#define DC_OVERLAY_H_FILTER_COEF_INDEX		0x1AC0
#define DC_OVERLAY_H_FILTER_COEF_DATA		0x1B00
#define DC_OVERLAY_V_FILTER_COEF_INDEX		0x1B40
#define DC_OVERLAY_V_FILTER_COEF_DATA		0x1B80
#define DC_OVERLAY_INIT_OFFSET			0x1BC0
#define DC_OVERLAY_COLOR_KEY			0x1740
#define DC_OVERLAY_COLOR_KEY_HIGH		0x1780
#define DC_OVERLAY_CLEAR_VALUE			0x1940
#define DC_OVERLAY_COLOR_TABLE_INDEX		0x1980
#define DC_OVERLAY_COLOR_TABLE_DATA		0x19C0
#define DC_OVERLAY_SRC_GLOBAL_COLOR		0x16C0
# define OVERLAY_ALPHA_LEN(x)			((x) << 24)

#define DC_OVERLAY_DST_GLOBAL_COLOR		0x1700
#define DC_OVERLAY_ROI_ORIGIN			0x1D00
#define DC_OVERLAY_ROI_SIZE			0x1D40
#define DC_OVERLAY_WATER_MARK			0x1DC0
#define DC_OVERLAY_DEGAMMA_INDEX		0x2200
#define DC_OVERLAY_DEGAMMA_DATA			0x2240
#define DC_OVERLAY_DEGAMMA_EX_DATA		0x2280
#define DC_OVERLAY_YUVTORGB_COEF0		0x1EC0
#define DC_OVERLAY_YUVTORGB_COEF1		0x1F00
#define DC_OVERLAY_YUVTORGB_COEF2		0x1F40
#define DC_OVERLAY_YUVTORGB_COEF3		0x1F80
#define DC_OVERLAY_YUVTORGB_COEF4		0x1FC0
#define DC_OVERLAY_YUVTORGB_COEFD0		0x2000
#define DC_OVERLAY_YUVTORGB_COEFD1		0x2040
#define DC_OVERLAY_YUVTORGB_COEFD2		0x2080
#define DC_OVERLAY_Y_CLAMP_BOUND		0x22C0
#define DC_OVERLAY_UV_CLAMP_BOUND		0x2300
#define DC_OVERLAY_RGBTORGB_COEF0		0x20C0
#define DC_OVERLAY_RGBTORGB_COEF1		0x2100
#define DC_OVERLAY_RGBTORGB_COEF2		0x2140
#define DC_OVERLAY_RGBTORGB_COEF3		0x2180
#define DC_OVERLAY_RGBTORGB_COEF4		0x21C0

#define DC_CURSOR_CONFIG			0x1468
# define CURSOR_HOT_X(x)			((x) << 16)
# define CURSOR_HOT_X_MASK			GENMASK(23, 16)
# define CURSOR_HOT_y(x)			((x) << 8)
# define CURSOR_HOT_y_MASK			GENMASK(15, 8)
# define CURSOR_SIZE(x)				((x) << 5)
# define CURSOR_SIZE_MASK			GENMASK(7, 5)
# define CURSOR_VALID(x)			((x) << 3)
# define CURSOR_VALID_MASK			GENMASK(3, 3)
# define CURSOR_TRIG_FETCH(x)			((x) << 2)
# define CURSOR_TRIG_FETCH_MASK			GENMASK(2, 2)
# define CURSOR_FORMAT(x)			((x) << 0)
# define CURSOR_FORMAT_MASK			GENMASK(1, 0)
# define CURSOR_FORMAT_DISABLE			0
# define CURSOR_FORMAT_MARK			1
# define CURSOR_FORMAT_A8R8G8B8			2

#define DC_CURSOR_ADDRESS			0x146C
#define DC_CURSOR_LOCATION			0x1470
# define X_LCOTION(x)				(x)
# define Y_LCOTION(x)				((x) << 16)

#define DC_CURSOR_BACKGROUND			0x1474
#define DC_CURSOR_FOREGROUND			0x1478
#define DC_CURSOR_CLK_GATING			0x1484
#define DC_CURSOR_CONFIG_EX			0x24E8
#define DC_CURSOR_OFFSET			0x1080

#define DC_DISPLAY_DITHER_CONFIG		0x1410
#define DC_DISPLAY_PANEL_CONFIG			0x1418
# define PANEL_RGB2YUV_EN			BIT(16)
# define PANEL_GAMMA_EN				BIT(13)
# define PANEL_OUTPUT_EN			BIT(12)

#define DC_DISPLAY_PANEL_CONFIG_EX		0x2518
# define PANEL_SHADOW_EN			BIT(0)

#define DC_DISPLAY_DITHER_TABLE_LOW		0x1420
#define DC_DISPLAY_DITHER_TABLE_HIGH		0x1428
#define DC_DISPLAY_H				0x1430
# define H_ACTIVE_LEN(x)			(x)
# define H_TOTAL_LEN(x)				((x) << 16)

#define DC_DISPLAY_H_SYNC			0x1438
# define H_SYNC_START_LEN(x)			(x)
# define H_SYNC_END_LEN(x)			((x) << 15)
# define H_PLUS_LEN(x)				((x) << 30)
# define H_POLARITY_LEN(x)			((x) << 31)

#define DC_DISPLAY_V				0x1440
# define V_ACTIVE_LEN(x)			(x)
# define V_TOTAL_LEN(x)				((x) << 16)

#define DC_DISPLAY_V_SYNC			0x1448
# define V_SYNC_START_LEN(x)			(x)
# define V_SYNC_END_LEN(x)			((x) << 15)
# define V_PLUS_LEN(x)				((x) << 30)
# define V_POLARITY_LEN(x)			((x) << 31)

#define DC_DISPLAY_CURRENT_LOCATION		0x1450
#define DC_DISPLAY_GAMMA_INDEX			0x1458
#define DC_DISPLAY_GAMMA_DATA			0x1460
#define DC_DISPLAY_INT				0x147C
#define DC_DISPLAY_INT_ENABLE			0x1480
#define DC_DISPLAY_DBI_CONFIG			0x1488
#define DC_DISPLAY_GENERAL_CONFIG		0x14B0
#define DC_DISPLAY_DPI_CONFIG			0x14B8
#define DC_DISPLAY_PANEL_START			0x1CCC
# define PANEL0_EN				BIT(0)
# define PANEL1_EN				BIT(1)
# define TWO_PANEL_EN				BIT(2)
# define SYNC_EN				BIT(3)

#define DC_DISPLAY_DEBUG_COUNTER_SELECT		0x14D0
#define DC_DISPLAY_DEBUG_COUNTER_VALUE		0x14D8
#define DC_DISPLAY_DP_CONFIG			0x1CD0
# define DP_SELECT				BIT(3)

#define DC_DISPLAY_GAMMA_EX_INDEX		0x1CF0
#define DC_DISPLAY_GAMMA_EX_DATA		0x1CF8
#define DC_DISPLAY_GAMMA_EX_ONE_DATA		0x1D80
#define DC_DISPLAY_RGBTOYUV_COEF0		0x1E48
#define DC_DISPLAY_RGBTOYUV_COEF1		0x1E50
#define DC_DISPLAY_RGBTOYUV_COEF2		0x1E58
#define DC_DISPLAY_RGBTOYUV_COEF3		0x1E60
#define DC_DISPLAY_RGBTOYUV_COEF4		0x1E68
#define DC_DISPLAY_RGBTOYUV_COEFD0		0x1E70
#define DC_DISPLAY_RGBTOYUV_COEFD1		0x1E78
#define DC_DISPLAY_RGBTOYUV_COEFD2		0x1E80

#define DC_CLK_GATTING				0x1A28
#define DC_QOS_CONFIG				0x1A38

#define DC_TRANSPARENCY_OPAQUE			0x00
#define DC_TRANSPARENCY_KEY			0x02
#define DC_DISPLAY_DITHERTABLE_LOW		0x7B48F3C0
#define DC_DISPLAY_DITHERTABLE_HIGH		0x596AD1E2

#define DC_TILE_MODE4X4	0x15

#define GAMMA_SIZE				256
#define GAMMA_EX_SIZE				300
#define DEGAMMA_SIZE				260

#define RGB_TO_RGB_TABLE_SIZE			9
#define YUV_TO_RGB_TABLE_SIZE			16
#define RGB_TO_YUV_TABLE_SIZE			12

#define DC_LAYER_NUM	6
#define DC_DISPLAY_NUM	2
#define DC_CURSOR_NUM	2

enum dc_hw_plane_id {
	PRIMARY_PLANE_0,
	OVERLAY_PLANE_0,
	OVERLAY_PLANE_1,
	PRIMARY_PLANE_1,
	OVERLAY_PLANE_2,
	OVERLAY_PLANE_3,
	CURSOR_PLANE_0,
	CURSOR_PLANE_1,
	PLANE_NUM
};

enum dc_hw_color_format {
	FORMAT_X4R4G4B4,
	FORMAT_A4R4G4B4,
	FORMAT_X1R5G5B5,
	FORMAT_A1R5G5B5,
	FORMAT_R5G6B5,
	FORMAT_X8R8G8B8,
	FORMAT_A8R8G8B8,
	FORMAT_YUY2,
	FORMAT_UYVY,
	FORMAT_INDEX8,
	FORMAT_MONOCHROME,
	FORMAT_YV12 = 0xf,
	FORMAT_A8,
	FORMAT_NV12,
	FORMAT_NV16,
	FORMAT_RG16,
	FORMAT_R8,
	FORMAT_NV12_10BIT,
	FORMAT_A2R10G10B10,
	FORMAT_NV16_10BIT,
	FORMAT_INDEX1,
	FORMAT_INDEX2,
	FORMAT_INDEX4,
	FORMAT_P010,
	FORMAT_YUV444,
	FORMAT_YUV444_10BIT,
};

enum dc_hw_yuv_color_space {
	COLOR_SPACE_601 = 0,
	COLOR_SPACE_709 = 1,
	COLOR_SPACE_2020 = 3,
};

enum dc_hw_rotation {
	ROT_0 = 0,
	ROT_90 = 4,
	ROT_180 = 5,
	ROT_270 = 6,
	FLIP_X = 1,
	FLIP_Y = 2,
	FLIP_XY = 3,
};

enum dc_hw_swizzle {
	SWIZZLE_ARGB = 0,
	SWIZZLE_RGBA,
	SWIZZLE_ABGR,
	SWIZZLE_BGRA,
};

enum dc_hw_out {
	OUT_DPI,
	OUT_DP,
};

enum dc_hw_cursor_size {
	CURSOR_SIZE_32X32 = 0,
	CURSOR_SIZE_64X64,
};

struct dc_hw_plane_reg {
	u32 y_address;
	u32 u_address;
	u32 v_address;
	u32 y_stride;
	u32 u_stride;
	u32 v_stride;
	u32 size;
	u32 top_left;
	u32 bottom_right;
	u32 scale_factor_x;
	u32 scale_factor_y;
	u32 h_filter_coef_index;
	u32 h_filter_coef_data;
	u32 v_filter_coef_index;
	u32 v_filter_coef_data;
	u32 init_offset;
	u32 color_key;
	u32 color_key_high;
	u32 clear_value;
	u32 color_table_index;
	u32 color_table_data;
	u32 scale_config;
	u32 water_mark;
	u32 degamma_index;
	u32 degamma_data;
	u32 degamma_ex_data;
	u32 src_global_color;
	u32 dst_global_color;
	u32 blend_config;
	u32 roi_origin;
	u32 roi_size;
	u32 yuv_to_rgb_coef0;
	u32 yuv_to_rgb_coef1;
	u32 yuv_to_rgb_coef2;
	u32 yuv_to_rgb_coef3;
	u32 yuv_to_rgb_coef4;
	u32 yuv_to_rgb_coefd0;
	u32 yuv_to_rgb_coefd1;
	u32 yuv_to_rgb_coefd2;
	u32 y_clamp_bound;
	u32 uv_clamp_bound;
	u32 rgb_to_rgb_coef0;
	u32 rgb_to_rgb_coef1;
	u32 rgb_to_rgb_coef2;
	u32 rgb_to_rgb_coef3;
	u32 rgb_to_rgb_coef4;
};

struct dc_hw_gamma {
	u16 gamma[GAMMA_EX_SIZE][3];
};

struct dc_hw_read {
	u32			reg;
	u32			value;
};

struct dc_hw {
	enum dc_hw_out		out[DC_DISPLAY_NUM];
	void			*hi_base;
	void			*reg_base;
	struct dc_hw_plane_reg	reg[DC_LAYER_NUM];

	struct dc_hw_gamma	gamma[DC_DISPLAY_NUM];
	struct vs_dc_info	*info;
};

struct vs_dc_plane {
	enum dc_hw_plane_id id;
	u32 offset;
};

struct vs_dc {
	struct vs_crtc		*crtc[DC_DISPLAY_NUM];
	struct dc_hw		hw;

	struct vs_dc_plane	planes[PLANE_NUM];
};

int dc_hw_init(struct vs_dc *dc);
void dc_hw_disable_plane(struct vs_dc *dc, u8 id);
void dc_hw_update_cursor(struct dc_hw *hw, u8 id, dma_addr_t dma_addr,
			 u32 crtc_w, u32 crtc_x, u32 crtc_y,
			 s32 hotspot_x, int32_t hotspot_y);
void dc_hw_disable_cursor(struct dc_hw *hw, u8 id);
void dc_hw_update_gamma(struct dc_hw *hw, u8 id, u16 index,
			u16 r, u16 g, u16 b);
void dc_hw_enable_gamma(struct dc_hw *hw, u8 id, bool enable);
void dc_hw_enable(struct dc_hw *hw, int id, struct drm_display_mode *mode,
		  u8 encoder_type, u32 output_fmt);
void dc_hw_disable(struct dc_hw *hw, int id);
void dc_hw_enable_interrupt(struct dc_hw *hw);
void dc_hw_disable_interrupt(struct dc_hw *hw);
u32 dc_hw_get_interrupt(struct dc_hw *hw);
void dc_hw_enable_shadow_register(struct vs_dc *dc, bool enable);
void dc_hw_set_out(struct dc_hw *hw, enum dc_hw_out out, u8 id);
void dc_hw_commit(struct dc_hw *hw);
void plane_hw_update_format_colorspace(struct vs_dc *dc, u32 format,
				       enum drm_color_encoding encoding, u8 id, bool is_yuv);
void plane_hw_update_address(struct vs_dc *dc, u8 id, u32 format, dma_addr_t *dma_addr,
			     struct drm_framebuffer *drm_fb, struct drm_rect *src);
void plane_hw_update_format(struct vs_dc *dc, u32 format, enum drm_color_encoding encoding,
			    unsigned int rotation, bool visible, unsigned int zpos,
			    u8 id, u8 display_id);
void plane_hw_update_scale(struct vs_dc *dc, struct drm_rect *src, struct drm_rect *dst,
			   u8 id, u8 display_id, unsigned int rotation);
void plane_hw_update_blend(struct vs_dc *dc, u16 alpha, u16 pixel_blend_mode,
			   u8 id, u8 display_id);

#endif /* __VS_DC_HW_H__ */
