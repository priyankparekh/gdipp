#pragma once

#include "text.h"
using namespace std;

class gdimm_gdi_text : public gdimm_text
{
	// device context attributes
	RGBQUAD _text_rgb;

	// gamma ramps for gray, red, green, blue
	const BYTE *_gamma_ramps[4];

	void set_bmp_bits_mono(const FT_BitmapGlyph glyph,
		BYTE *dest_bits,
		POINT dest_pos,
		int dest_width,
		int dest_ascent,
		int dest_descent) const;
	void set_bmp_bits_gray(const FT_BitmapGlyph glyph,
		BYTE *dest_bits,
		POINT dest_pos,
		int dest_width,
		int dest_ascent,
		int dest_descent,
		WORD alpha) const;
	void set_bmp_bits_lcd(const FT_BitmapGlyph glyph,
		BYTE *dest_bits,
		POINT dest_pos,
		int dest_width,
		int dest_ascent,
		int dest_descent,
		WORD alpha) const;
	bool draw_glyphs(int x,
		int y,
		UINT options,
		CONST RECT *lprect) const;

	virtual bool render(UINT options, CONST RECT *lprect, LPCWSTR lpString, UINT c, CONST INT *lpDx, FT_Render_Mode render_mode) = 0;

protected:
	POINT _cursor;
	int _char_extra;

	vector<const FT_BitmapGlyph> _glyphs;
	vector<POINT> _glyph_pos;

public:
	gdimm_gdi_text(HDC hdc);

	virtual bool init();
	virtual bool text_out(int x, int y, UINT options, CONST RECT *lprect, LPCWSTR lpString, UINT c, CONST INT *lpDx);
};