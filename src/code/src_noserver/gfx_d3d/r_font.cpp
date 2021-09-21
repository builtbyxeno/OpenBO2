#include "types.h"
#include "functions.h"

/*
==============
R_GetCharacterGlyph
==============
*/
Glyph *R_GetCharacterGlyph(Font_s *font, unsigned int letter)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_GetKerningAmount
==============
*/
int R_GetKerningAmount(Font_s *font, int previousLetter, int letter)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_FontGetRandomLetter
==============
*/
unsigned int R_FontGetRandomLetter(Font_s *font, int seed)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_FontGetRandomNumberCharacter
==============
*/
unsigned int R_FontGetRandomNumberCharacter(Font_s *font, int seed)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TRACK_r_font
==============
*/
void TRACK_r_font()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_RegisterFont_LoadObj
==============
*/
Font_s *R_RegisterFont_LoadObj(const char *fontName, int imageTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_RegisterFont_FastFile
==============
*/
Font_s *R_RegisterFont_FastFile(const char *fontName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_RegisterFont
==============
*/
Font_s *R_RegisterFont()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_NormalizedTextScale
==============
*/
double R_NormalizedTextScale(Font_s *font, float scale)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetButtonProperties
==============
*/
void GetButtonProperties(LocalClientNum_t localClientNum, const char *text, Font_s *font, int *buttonCharLength, int *buttonMaterialWidth)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_TextWidth
==============
*/
int R_TextWidth(LocalClientNum_t localClientNum, const char *text, int maxChars, Font_s *font)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_TextHeight
==============
*/
int R_TextHeight(Font_s *font)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_TextLineWrapPosition
==============
*/
const char *R_TextLineWrapPosition(const char *text, int bufferSize, int pixelsAvailable, Font_s *font, float scale)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_ConsoleTextWidth
==============
*/
int R_ConsoleTextWidth(const char *textPool, int poolSize, int firstChar, int charCount, Font_s *font)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

