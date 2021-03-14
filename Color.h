#ifndef COLOR_H
#include <windows.h>
#define COLOR_H

namespace ECC {
	void setColor(int text, int background);
	enum ConsoleColor {
		Black,
		Blue,
		Green,
		Cyan,
		Red,
		Magenta,
		Brown,
		LightGray,
		DarkGray,
		LightBlue,
		LightGreen,
		LightCyan,
		LightRed,
		LightMagenta,
		Yellow,
		White
	};
}



#endif // !COLOR_H
