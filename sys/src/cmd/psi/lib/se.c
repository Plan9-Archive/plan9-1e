#include <u.h>
#include <libc.h>
#include "system.h"
#include "stdio.h"
#include "defines.h"
#include "object.h"
struct 	pstring	se_tab[] =
{	/*0*/
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 6, (unsigned char *) "Aacute"},
{AC_READONLY, 11, (unsigned char *) "Acircumflex"},
{AC_READONLY, 9, (unsigned char *) "Adieresis"},
{AC_READONLY, 6, (unsigned char *) "Agrave"},
{AC_READONLY, 5, (unsigned char *) "Aring"},
{AC_READONLY, 6, (unsigned char *) "Atilde"},
{AC_READONLY, 0, (unsigned char *) ""},		/*Ccedilla*/
	/*10*/
{AC_READONLY, 6, (unsigned char *) "Eacute"},
{AC_READONLY, 11, (unsigned char *) "Ecircumflex"},
{AC_READONLY, 9, (unsigned char *) "Edieresis"},
{AC_READONLY, 6, (unsigned char *) "Egrave"},
{AC_READONLY, 6, (unsigned char *) "Iacute"},
{AC_READONLY, 11, (unsigned char *) "Icircumflex"},
{AC_READONLY, 9, (unsigned char *) "Idieresis"},
{AC_READONLY, 6, (unsigned char *) "Igrave"},
	/*20*/
{AC_READONLY, 6, (unsigned char *) "Oacute"},
{AC_READONLY, 11, (unsigned char *) "Ocircumflex"},
{AC_READONLY, 9, (unsigned char *) "Odieresis"},
{AC_READONLY, 6, (unsigned char *) "Ograve"},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 6, (unsigned char *) "Otilde"},
{AC_READONLY, 6, (unsigned char *) "Scaron"},
{AC_READONLY, 6, (unsigned char *) "Uacute"},
	/*30*/
{AC_READONLY, 11, (unsigned char *) "Ucircumflex"},
{AC_READONLY, 9, (unsigned char *) "Udieresis"},
{AC_READONLY, 6, (unsigned char *) "Ugrave"},
{AC_READONLY, 9, (unsigned char *) "Ydieresis"},
{AC_READONLY, 6, (unsigned char *) "Zcaron"},
{AC_READONLY, 3, (unsigned char *) "Eth"},
{AC_READONLY, 5, (unsigned char *) "Thorn"},
{AC_READONLY, 0, (unsigned char *) ""},
	/*40*/
{AC_READONLY, 5, (unsigned char *) "space"},
{AC_READONLY, 6, (unsigned char *) "exclam"},
{AC_READONLY, 8, (unsigned char *) "quotedbl"},
{AC_READONLY, 10, (unsigned char *) "numbersign"},
{AC_READONLY, 6, (unsigned char *) "dollar"},
{AC_READONLY, 7, (unsigned char *) "percent"},
{AC_READONLY, 9, (unsigned char *) "ampersand"},
{AC_READONLY, 10, (unsigned char *) "quoteright"},
	/*50*/
{AC_READONLY, 9, (unsigned char *) "parenleft"},
{AC_READONLY, 10, (unsigned char *) "parenright"},
{AC_READONLY, 8, (unsigned char *) "asterisk"},
{AC_READONLY, 4, (unsigned char *) "plus"},
{AC_READONLY, 5, (unsigned char *) "comma"},
{AC_READONLY, 6, (unsigned char *) "hyphen"},
{AC_READONLY, 6, (unsigned char *) "period"},
{AC_READONLY, 5, (unsigned char *) "slash"},
	/*60*/
{AC_READONLY, 4, (unsigned char *) "zero"},
{AC_READONLY, 3, (unsigned char *) "one"},
{AC_READONLY, 3, (unsigned char *) "two"},
{AC_READONLY, 5, (unsigned char *) "three"},
{AC_READONLY, 4, (unsigned char *) "four"},
{AC_READONLY, 4, (unsigned char *) "five"},
{AC_READONLY, 3, (unsigned char *) "six"},
{AC_READONLY, 5, (unsigned char *) "seven"},
	/*70*/
{AC_READONLY, 5, (unsigned char *) "eight"},
{AC_READONLY, 4, (unsigned char *) "nine"},
{AC_READONLY, 5, (unsigned char *) "colon"},
{AC_READONLY, 9, (unsigned char *) "semicolon"},
{AC_READONLY, 4, (unsigned char *) "less"},
{AC_READONLY, 5, (unsigned char *) "equal"},
{AC_READONLY, 7, (unsigned char *) "greater"},
{AC_READONLY, 8, (unsigned char *) "question"},
	/*100*/
{AC_READONLY, 2, (unsigned char *) "at"},
{AC_READONLY, 1, (unsigned char *) "A"},
{AC_READONLY, 1, (unsigned char *) "B"},
{AC_READONLY, 1, (unsigned char *) "C"},
{AC_READONLY, 1, (unsigned char *) "D"},
{AC_READONLY, 1, (unsigned char *) "E"},
{AC_READONLY, 1, (unsigned char *) "F"},
{AC_READONLY, 1, (unsigned char *) "G"},
	/*110*/
{AC_READONLY, 1, (unsigned char *) "H"},
{AC_READONLY, 1, (unsigned char *) "I"},
{AC_READONLY, 1, (unsigned char *) "J"},
{AC_READONLY, 1, (unsigned char *) "K"},
{AC_READONLY, 1, (unsigned char *) "L"},
{AC_READONLY, 1, (unsigned char *) "M"},
{AC_READONLY, 1, (unsigned char *) "N"},
{AC_READONLY, 1, (unsigned char *) "O"},
	/*120*/
{AC_READONLY, 1, (unsigned char *) "P"},
{AC_READONLY, 1, (unsigned char *) "Q"},
{AC_READONLY, 1, (unsigned char *) "R"},
{AC_READONLY, 1, (unsigned char *) "S"},
{AC_READONLY, 1, (unsigned char *) "T"},
{AC_READONLY, 1, (unsigned char *) "U"},
{AC_READONLY, 1, (unsigned char *) "V"},
{AC_READONLY, 1, (unsigned char *) "W"},
	/*130*/
{AC_READONLY, 1, (unsigned char *) "X"},
{AC_READONLY, 1, (unsigned char *) "Y"},
{AC_READONLY, 1, (unsigned char *) "Z"},
{AC_READONLY, 11, (unsigned char *) "bracketleft"},
{AC_READONLY, 9, (unsigned char *) "backslash"},
{AC_READONLY, 12, (unsigned char *) "bracketright"},
{AC_READONLY, 11, (unsigned char *) "asciicircum"},
{AC_READONLY, 10, (unsigned char *) "underscore"},
	/*140*/
{AC_READONLY, 9, (unsigned char *) "quoteleft"},
{AC_READONLY, 1, (unsigned char *) "a"},
{AC_READONLY, 1, (unsigned char *) "b"},
{AC_READONLY, 1, (unsigned char *) "c"},
{AC_READONLY, 1, (unsigned char *) "d"},
{AC_READONLY, 1, (unsigned char *) "e"},
{AC_READONLY, 1, (unsigned char *) "f"},
{AC_READONLY, 1, (unsigned char *) "g"},
	/*150*/
{AC_READONLY, 1, (unsigned char *) "h"},
{AC_READONLY, 1, (unsigned char *) "i"},
{AC_READONLY, 1, (unsigned char *) "j"},
{AC_READONLY, 1, (unsigned char *) "k"},
{AC_READONLY, 1, (unsigned char *) "l"},
{AC_READONLY, 1, (unsigned char *) "m"},
{AC_READONLY, 1, (unsigned char *) "n"},
{AC_READONLY, 1, (unsigned char *) "o"},
	/*160*/
{AC_READONLY, 1, (unsigned char *) "p"},
{AC_READONLY, 1, (unsigned char *) "q"},
{AC_READONLY, 1, (unsigned char *) "r"},
{AC_READONLY, 1, (unsigned char *) "s"},
{AC_READONLY, 1, (unsigned char *) "t"},
{AC_READONLY, 1, (unsigned char *) "u"},
{AC_READONLY, 1, (unsigned char *) "v"},
{AC_READONLY, 1, (unsigned char *) "w"},
	/*170*/
{AC_READONLY, 1, (unsigned char *) "x"},
{AC_READONLY, 1, (unsigned char *) "y"},
{AC_READONLY, 1, (unsigned char *) "z"},
{AC_READONLY, 9, (unsigned char *) "braceleft"},
{AC_READONLY, 3, (unsigned char *) "bar"},
{AC_READONLY, 10, (unsigned char *) "braceright"},
{AC_READONLY, 10, (unsigned char *) "asciitilde"},
{AC_READONLY, 0, (unsigned char *) ""},
	/*200*/
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 6, (unsigned char *) "aacute"},
{AC_READONLY, 11, (unsigned char *) "acircumflex"},
{AC_READONLY, 9, (unsigned char *) "adieresis"},
{AC_READONLY, 6, (unsigned char *) "agrave"},
{AC_READONLY, 5, (unsigned char *) "aring"},
{AC_READONLY, 6, (unsigned char *) "atilde"},
{AC_READONLY, 0, (unsigned char *) ""},		/*ccedilla*/
	/*210*/
{AC_READONLY, 6, (unsigned char *) "eacute"},
{AC_READONLY, 11, (unsigned char *) "ecircumflex"},
{AC_READONLY, 9, (unsigned char *) "edieresis"},
{AC_READONLY, 6, (unsigned char *) "egrave"},
{AC_READONLY, 6, (unsigned char *) "iacute"},
{AC_READONLY, 11, (unsigned char *) "icircumflex"},
{AC_READONLY, 9, (unsigned char *) "idieresis"},
{AC_READONLY, 6, (unsigned char *) "igrave"},
	/*220*/
{AC_READONLY, 6, (unsigned char *) "oacute"},
{AC_READONLY, 11, (unsigned char *) "ocircumflex"},
{AC_READONLY, 9, (unsigned char *) "odieresis"},
{AC_READONLY, 6, (unsigned char *) "ograve"},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 6, (unsigned char *) "otilde"},
{AC_READONLY, 6, (unsigned char *) "scaron"},
{AC_READONLY, 6, (unsigned char *) "uacute"},
 	/*230*/
{AC_READONLY, 11, (unsigned char *) "ucircumflex"},
{AC_READONLY, 9, (unsigned char *) "udiresis"},
{AC_READONLY, 6, (unsigned char *) "ugrave"},
{AC_READONLY, 9, (unsigned char *) "ydieresis"},
{AC_READONLY, 6, (unsigned char *) "zcaron"},
{AC_READONLY, 3, (unsigned char *) "eth"},
{AC_READONLY, 5, (unsigned char *) "thorn"},
{AC_READONLY, 0, (unsigned char *) ""},
	/*240*/
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 10, (unsigned char *) "exclamdown"},
{AC_READONLY, 4, (unsigned char *) "cent"},
{AC_READONLY, 8, (unsigned char *) "sterling"},
{AC_READONLY, 8, (unsigned char *) "fraction"},
{AC_READONLY, 3, (unsigned char *) "yen"},
{AC_READONLY, 6, (unsigned char *) "florin"},
{AC_READONLY, 7, (unsigned char *) "section"},
	/*250*/
{AC_READONLY, 8, (unsigned char *) "currency"},
{AC_READONLY, 11, (unsigned char *) "quotesingle"},
{AC_READONLY, 12, (unsigned char *) "quotedblleft"},
{AC_READONLY, 13, (unsigned char *) "guillemotleft"},
{AC_READONLY, 13, (unsigned char *) "guilsinglleft"},
{AC_READONLY, 14, (unsigned char *) "guilsinglright"},
{AC_READONLY, 2, (unsigned char *) "fi"},
{AC_READONLY, 2, (unsigned char *) "fl"},
	/*260*/
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 6, (unsigned char *) "endash"},
{AC_READONLY, 6, (unsigned char *) "dagger"},
{AC_READONLY, 9, (unsigned char *) "daggerdbl"},
{AC_READONLY, 14, (unsigned char *) "periodcentered"},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 9, (unsigned char *) "paragraph"},
{AC_READONLY, 6, (unsigned char *) "bullet"},
	/*270*/
{AC_READONLY, 14, (unsigned char *) "quotesinglbase"},
{AC_READONLY, 12, (unsigned char *) "quotedblbase"},
{AC_READONLY, 13, (unsigned char *) "quotedblright"},
{AC_READONLY, 14, (unsigned char *) "guillemotright"},
{AC_READONLY, 8, (unsigned char *) "ellipsis"},
{AC_READONLY, 11, (unsigned char *) "perthousand"},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 12, (unsigned char *) "questiondown"},
	/*300*/
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 5, (unsigned char *) "grave"},
{AC_READONLY, 5, (unsigned char *) "acute"},
{AC_READONLY, 10, (unsigned char *) "circumflex"},
{AC_READONLY, 5, (unsigned char *) "tilde"},
{AC_READONLY, 6, (unsigned char *) "macron"},
{AC_READONLY, 5, (unsigned char *) "breve"},
{AC_READONLY, 9, (unsigned char *) "dotaccent"},
	/*310*/
{AC_READONLY, 8, (unsigned char *) "dieresis"},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 4, (unsigned char *) "ring"},
{AC_READONLY, 7, (unsigned char *) "cedilla"},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 12, (unsigned char *) "hungarumlaut"},
{AC_READONLY, 6, (unsigned char *) "ogonek"},
{AC_READONLY, 5, (unsigned char *) "caron"},
	/*320*/
{AC_READONLY, 6, (unsigned char *) "emdash"},
{AC_READONLY, 6, (unsigned char *) "divide"},
{AC_READONLY, 2, (unsigned char *) "mu"},
{AC_READONLY, 7, (unsigned char *) "onehalf"},
{AC_READONLY, 10, (unsigned char *) "onequarter"},
{AC_READONLY, 13, (unsigned char *) "threequarters"},
{AC_READONLY, 11, (unsigned char *) "onesuperior"},
{AC_READONLY, 11, (unsigned char *) "twosuperior"},
	/*330*/
{AC_READONLY, 13, (unsigned char *) "threesuperior"},
{AC_READONLY, 9, (unsigned char *) "copyright"},
{AC_READONLY, 10, (unsigned char *) "registered"},
{AC_READONLY, 9, (unsigned char *) "plusminus"},
{AC_READONLY, 9, (unsigned char *) "brokenbar"},
{AC_READONLY, 6, (unsigned char *) "degree"},
{AC_READONLY, 10, (unsigned char *) "logicalnot"},
{AC_READONLY, 8, (unsigned char *) "multiply"},
	/*340*/
{AC_READONLY, 9, (unsigned char *) "trademark"},
{AC_READONLY, 2, (unsigned char *) "AE"},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 11, (unsigned char *) "ordfeminine"},
{AC_READONLY, 6, (unsigned char *) "Ntilde"},
{AC_READONLY, 6, (unsigned char *) "ntilde"},
{AC_READONLY, 6, (unsigned char *) "Yacute"},
{AC_READONLY, 6, (unsigned char *) "yacute"},
	/*350*/
{AC_READONLY, 6, (unsigned char *) "Lslash"},
{AC_READONLY, 6, (unsigned char *) "Oslash"},
{AC_READONLY, 2, (unsigned char *) "OE"},
{AC_READONLY, 12, (unsigned char *) "ordmasculine"},
{AC_READONLY, 5, (unsigned char *) "minus"},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
	/*360*/
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 2, (unsigned char *) "ae"},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 8, (unsigned char *) "dotlessi"},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
	/*370*/
{AC_READONLY, 6, (unsigned char *) "lslash"},
{AC_READONLY, 6, (unsigned char *) "oslash"},
{AC_READONLY, 2, (unsigned char *) "oe"},
{AC_READONLY, 10, (unsigned char *) "germandbls"},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},

} ;
struct	pstring	sye_tab[] =
{
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},

{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},

{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},

{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},

{AC_READONLY, 5, (unsigned char *) "space"},
{AC_READONLY, 6, (unsigned char *) "exclam"},
{AC_READONLY, 9, (unsigned char *) "universal"},
{AC_READONLY, 10, (unsigned char *) "numbersign"},
{AC_READONLY, 11, (unsigned char *) "existential"},
{AC_READONLY, 7, (unsigned char *) "percent"},
{AC_READONLY, 9, (unsigned char *) "ampersand"},
{AC_READONLY, 8, (unsigned char *) "suchthat"},

{AC_READONLY, 9, (unsigned char *) "parenleft"},
{AC_READONLY, 10, (unsigned char *) "parenright"},
{AC_READONLY, 12, (unsigned char *) "asteriskmath"},
{AC_READONLY, 4, (unsigned char *) "plus"},
{AC_READONLY, 5, (unsigned char *) "comma"},
{AC_READONLY, 5, (unsigned char *) "minus"},
{AC_READONLY, 6, (unsigned char *) "period"},
{AC_READONLY, 5, (unsigned char *) "slash"},

{AC_READONLY, 4, (unsigned char *) "zero"},
{AC_READONLY, 3, (unsigned char *) "one"},
{AC_READONLY, 3, (unsigned char *) "two"},
{AC_READONLY, 5, (unsigned char *) "three"},
{AC_READONLY, 4, (unsigned char *) "four"},
{AC_READONLY, 4, (unsigned char *) "five"},
{AC_READONLY, 3, (unsigned char *) "six"},
{AC_READONLY, 5, (unsigned char *) "seven"},

{AC_READONLY, 5, (unsigned char *) "eight"},
{AC_READONLY, 4, (unsigned char *) "nine"},
{AC_READONLY, 5, (unsigned char *) "colon"},
{AC_READONLY, 9, (unsigned char *) "semicolon"},
{AC_READONLY, 4, (unsigned char *) "less"},
{AC_READONLY, 5, (unsigned char *) "equal"},
{AC_READONLY, 7, (unsigned char *) "greater"},
{AC_READONLY, 8, (unsigned char *) "question"},

{AC_READONLY, 9, (unsigned char *) "congruent"},
{AC_READONLY, 5, (unsigned char *) "Alpha"},
{AC_READONLY, 4, (unsigned char *) "Beta"},
{AC_READONLY, 3, (unsigned char *) "Chi"},
{AC_READONLY, 5, (unsigned char *) "Delta"},
{AC_READONLY, 7, (unsigned char *) "Epsilon"},
{AC_READONLY, 3, (unsigned char *) "Phi"},
{AC_READONLY, 5, (unsigned char *) "Gamma"},

{AC_READONLY, 3, (unsigned char *) "Eta"},
{AC_READONLY, 4, (unsigned char *) "Iota"},
{AC_READONLY, 6, (unsigned char *) "theta1"},
{AC_READONLY, 5, (unsigned char *) "Kappa"},
{AC_READONLY, 6, (unsigned char *) "Lambda"},
{AC_READONLY, 2, (unsigned char *) "Mu"},
{AC_READONLY, 2, (unsigned char *) "Nu"},
{AC_READONLY, 7, (unsigned char *) "Omicron"},

{AC_READONLY, 2, (unsigned char *) "Pi"},
{AC_READONLY, 5, (unsigned char *) "Theta"},
{AC_READONLY, 3, (unsigned char *) "Rho"},
{AC_READONLY, 5, (unsigned char *) "Sigma"},
{AC_READONLY, 3, (unsigned char *) "Tau"},
{AC_READONLY, 7, (unsigned char *) "Upsilon"},
{AC_READONLY, 6, (unsigned char *) "sigma1"},
{AC_READONLY, 5, (unsigned char *) "Omega"},

{AC_READONLY, 2, (unsigned char *) "Xi"},
{AC_READONLY, 3, (unsigned char *) "Psi"},
{AC_READONLY, 4, (unsigned char *) "Zeta"},
{AC_READONLY, 11, (unsigned char *) "bracketleft"},
{AC_READONLY, 9, (unsigned char *) "therefore"},
{AC_READONLY, 12, (unsigned char *) "bracketright"},
{AC_READONLY, 13, (unsigned char *) "perpendicular"},
{AC_READONLY, 10, (unsigned char *) "underscore"},

{AC_READONLY, 9, (unsigned char *) "radicalex"},
{AC_READONLY, 5, (unsigned char *) "alpha"},
{AC_READONLY, 4, (unsigned char *) "beta"},
{AC_READONLY, 3, (unsigned char *) "chi"},
{AC_READONLY, 5, (unsigned char *) "delta"},
{AC_READONLY, 7, (unsigned char *) "epsilon"},
{AC_READONLY, 3, (unsigned char *) "phi"},
{AC_READONLY, 5, (unsigned char *) "gamma"},

{AC_READONLY, 3, (unsigned char *) "eta"},
{AC_READONLY, 4, (unsigned char *) "iota"},
{AC_READONLY, 4, (unsigned char *) "phi1"},
{AC_READONLY, 5, (unsigned char *) "kappa"},
{AC_READONLY, 6, (unsigned char *) "lambda"},
{AC_READONLY, 2, (unsigned char *) "mu"},
{AC_READONLY, 2, (unsigned char *) "nu"},
{AC_READONLY, 7, (unsigned char *) "omicron"},

{AC_READONLY, 2, (unsigned char *) "pi"},
{AC_READONLY, 5, (unsigned char *) "theta"},
{AC_READONLY, 3, (unsigned char *) "rho"},
{AC_READONLY, 5, (unsigned char *) "sigma"},
{AC_READONLY, 3, (unsigned char *) "tau"},
{AC_READONLY, 7, (unsigned char *) "upsilon"},
{AC_READONLY, 6, (unsigned char *) "omega1"},
{AC_READONLY, 5, (unsigned char *) "omega"},

{AC_READONLY, 2, (unsigned char *) "xi"},
{AC_READONLY, 3, (unsigned char *) "psi"},
{AC_READONLY, 4, (unsigned char *) "zeta"},
{AC_READONLY, 9, (unsigned char *) "braceleft"},
{AC_READONLY, 3, (unsigned char *) "bar"},
{AC_READONLY, 10, (unsigned char *) "braceright"},
{AC_READONLY, 7, (unsigned char *) "similar"},
{AC_READONLY, 0, (unsigned char *) ""},

{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},

{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},

{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},

{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 0, (unsigned char *) ""},

{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 8, (unsigned char *) "Upsilon1"},
{AC_READONLY, 6, (unsigned char *) "minute"},
{AC_READONLY, 9, (unsigned char *) "lessequal"},
{AC_READONLY, 8, (unsigned char *) "fraction"},
{AC_READONLY, 8, (unsigned char *) "infinity"},
{AC_READONLY, 6, (unsigned char *) "florin"},
{AC_READONLY, 4, (unsigned char *) "club"},

{AC_READONLY, 7, (unsigned char *) "diamond"},
{AC_READONLY, 5, (unsigned char *) "heart"},
{AC_READONLY, 5, (unsigned char *) "spade"},
{AC_READONLY, 9, (unsigned char *) "arrowboth"},
{AC_READONLY, 9, (unsigned char *) "arrowleft"},
{AC_READONLY, 7, (unsigned char *) "arrowup"},
{AC_READONLY, 10, (unsigned char *) "arrowright"},
{AC_READONLY, 9, (unsigned char *) "arrowdown"},

{AC_READONLY, 6, (unsigned char *) "degree"},
{AC_READONLY, 9, (unsigned char *) "plusminus"},
{AC_READONLY, 6, (unsigned char *) "second"},
{AC_READONLY, 12, (unsigned char *) "greaterequal"},
{AC_READONLY, 8, (unsigned char *) "multiply"},
{AC_READONLY, 12, (unsigned char *) "proportional"},
{AC_READONLY, 11, (unsigned char *) "partialdiff"},
{AC_READONLY, 6, (unsigned char *) "bullet"},

{AC_READONLY, 6, (unsigned char *) "divide"},
{AC_READONLY, 8, (unsigned char *) "notequal"},
{AC_READONLY, 11, (unsigned char *) "equivalence"},
{AC_READONLY, 11, (unsigned char *) "approxequal"},
{AC_READONLY, 8, (unsigned char *) "ellipsis"},
{AC_READONLY, 11, (unsigned char *) "arrowvertex"},
{AC_READONLY, 12, (unsigned char *) "arrowhorizex"},
{AC_READONLY, 14, (unsigned char *) "carriagereturn"},

{AC_READONLY, 5, (unsigned char *) "aleph"},
{AC_READONLY, 8, (unsigned char *) "Ifraktur"},
{AC_READONLY, 8, (unsigned char *) "Rfraktur"},
{AC_READONLY, 11, (unsigned char *) "weierstrass"},
{AC_READONLY, 14, (unsigned char *) "circlemultiply"},
{AC_READONLY, 10, (unsigned char *) "circleplus"},
{AC_READONLY, 8, (unsigned char *) "emptyset"},
{AC_READONLY, 12, (unsigned char *) "intersection"},

{AC_READONLY, 5, (unsigned char *) "union"},
{AC_READONLY, 14, (unsigned char *) "propersuperset"},
{AC_READONLY, 14, (unsigned char *) "reflexsuperset"},
{AC_READONLY, 9, (unsigned char *) "notsubset"},
{AC_READONLY, 12, (unsigned char *) "propersubset"},
{AC_READONLY, 12, (unsigned char *) "reflexsubset"},
{AC_READONLY, 7, (unsigned char *) "element"},
{AC_READONLY, 10, (unsigned char *) "notelement"},

{AC_READONLY, 5, (unsigned char *) "angle"},
{AC_READONLY, 8, (unsigned char *) "gradient"},
{AC_READONLY, 13, (unsigned char *) "registerserif"},
{AC_READONLY, 14, (unsigned char *) "copyrightserif"},
{AC_READONLY, 14, (unsigned char *) "trademarkserif"},
{AC_READONLY, 7, (unsigned char *) "product"},
{AC_READONLY, 7, (unsigned char *) "radical"},
{AC_READONLY, 7, (unsigned char *) "dotmath"},

{AC_READONLY, 10, (unsigned char *) "logicalnot"},
{AC_READONLY, 10, (unsigned char *) "logicaland"},
{AC_READONLY, 9, (unsigned char *) "logicalor"},
{AC_READONLY, 12, (unsigned char *) "arrowdblboth"},
{AC_READONLY, 12, (unsigned char *) "arrowdblleft"},
{AC_READONLY, 10, (unsigned char *) "arrowdblup"},
{AC_READONLY, 13, (unsigned char *) "arrowdblright"},
{AC_READONLY, 12, (unsigned char *) "arrowdbldown"},

{AC_READONLY, 7, (unsigned char *) "lozenge"},
{AC_READONLY, 9, (unsigned char *) "angleleft"},
{AC_READONLY, 12, (unsigned char *) "registersans"},
{AC_READONLY, 13, (unsigned char *) "copyrightsans"},
{AC_READONLY, 13, (unsigned char *) "trademarksans"},
{AC_READONLY, 9, (unsigned char *) "summation"},
{AC_READONLY, 11, (unsigned char *) "parenlefttp"},
{AC_READONLY, 11, (unsigned char *) "parenleftex"},

{AC_READONLY, 11, (unsigned char *) "parenleftbt"},
{AC_READONLY, 13, (unsigned char *) "bracketlefttp"},
{AC_READONLY, 13, (unsigned char *) "bracketleftex"},
{AC_READONLY, 13, (unsigned char *) "bracketleftbt"},
{AC_READONLY, 11, (unsigned char *) "bracelefttp"},
{AC_READONLY, 12, (unsigned char *) "braceleftmid"},
{AC_READONLY, 11, (unsigned char *) "braceleftbt"},
{AC_READONLY, 7, (unsigned char *) "braceex"},

{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 10, (unsigned char *) "angleright"},
{AC_READONLY, 8, (unsigned char *) "integral"},
{AC_READONLY, 10, (unsigned char *) "integraltp"},
{AC_READONLY, 10, (unsigned char *) "integralex"},
{AC_READONLY, 10, (unsigned char *) "integralbt"},
{AC_READONLY, 12, (unsigned char *) "parenrighttp"},
{AC_READONLY, 12, (unsigned char *) "parenrightex"},

{AC_READONLY, 12, (unsigned char *) "parenrightbt"},
{AC_READONLY, 14, (unsigned char *) "bracketrighttp"},
{AC_READONLY, 14, (unsigned char *) "bracketrightex"},
{AC_READONLY, 14, (unsigned char *) "bracketrightbt"},
{AC_READONLY, 12, (unsigned char *) "bracerighttp"},
{AC_READONLY, 13, (unsigned char *) "bracerightmid"},
{AC_READONLY, 12, (unsigned char *) "bracerightbt"},
{AC_READONLY, 0, (unsigned char *) ""},
};

struct	pstring	isolatin1_tab[] =
{
{AC_READONLY, 5, (unsigned char *) "minus"},	/*dumb*/
/* 0220 */
{AC_READONLY, 8, (unsigned char *) "dotlessi"},
{AC_READONLY, 5, (unsigned char *) "grave"},
{AC_READONLY, 5, (unsigned char *) "acute"},
{AC_READONLY, 10, (unsigned char *) "circumflex"},
{AC_READONLY, 5, (unsigned char *) "tilde"},
{AC_READONLY, 6, (unsigned char *) "macron"},
{AC_READONLY, 5, (unsigned char *) "breve"},
{AC_READONLY, 9, (unsigned char *) "dotaccent"},
/*230*/
{AC_READONLY, 8, (unsigned char *) "dieresis"},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 4, (unsigned char *) "ring"},
{AC_READONLY, 7, (unsigned char *) "cedilla"},
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 12, (unsigned char *) "hungarumlaut"},
{AC_READONLY, 6, (unsigned char *) "ogonek"},
{AC_READONLY, 5, (unsigned char *) "caron"},
/*240*/
{AC_READONLY, 0, (unsigned char *) ""},
{AC_READONLY, 10, (unsigned char *) "exclamdown"},
{AC_READONLY, 4, (unsigned char *) "cent"},
{AC_READONLY, 8, (unsigned char *) "sterling"},
{AC_READONLY, 8, (unsigned char *) "fraction"},
{AC_READONLY, 3, (unsigned char *) "yen"},
{AC_READONLY, 9, (unsigned char *) "brokenbar"},
{AC_READONLY, 7, (unsigned char *) "section"},
/*250*/
{AC_READONLY, 8, (unsigned char *) "dieresis"},
{AC_READONLY, 9, (unsigned char *) "copyright"},
{AC_READONLY, 11, (unsigned char *) "ordfeminine"},
{AC_READONLY, 13, (unsigned char *) "guillemotleft"},
{AC_READONLY, 10, (unsigned char *) "logicalnot"},
{AC_READONLY, 6, (unsigned char *) "hyphen"},
{AC_READONLY, 10, (unsigned char *) "registered"},
{AC_READONLY, 6, (unsigned char *) "macron"},
/*260*/
{AC_READONLY, 6, (unsigned char *) "degree"},
{AC_READONLY, 9, (unsigned char *) "plusminus"},
{AC_READONLY, 11, (unsigned char *) "twosuperior"},
{AC_READONLY, 13, (unsigned char *) "threesuperior"},
{AC_READONLY, 5, (unsigned char *) "acute"},
{AC_READONLY, 2, (unsigned char *) "mu"},
{AC_READONLY, 9, (unsigned char *) "paragraph"},
{AC_READONLY, 14, (unsigned char *) "periodcentered"},
/*270*/
{AC_READONLY, 7, (unsigned char *) "cedilla"},
{AC_READONLY, 11, (unsigned char *) "onesuperior"},
{AC_READONLY, 12, (unsigned char *) "ordmasculine"},
{AC_READONLY, 14, (unsigned char *) "guillemotright"},
{AC_READONLY, 10, (unsigned char *) "onequarter"},
{AC_READONLY, 7, (unsigned char *) "onehalf"},
{AC_READONLY, 13, (unsigned char *) "threequarters"},
{AC_READONLY, 12, (unsigned char *) "questiondown"},
/*300*/
{AC_READONLY, 6, (unsigned char *) "Agrave"},
{AC_READONLY, 6, (unsigned char *) "Aacute"},
{AC_READONLY, 11, (unsigned char *) "Acircumflex"},
{AC_READONLY, 6, (unsigned char *) "Atilde"},
{AC_READONLY, 9, (unsigned char *) "Adieresis"},
{AC_READONLY, 5, (unsigned char *) "Aring"},
{AC_READONLY, 2, (unsigned char *) "AE"},
{AC_READONLY, 8, (unsigned char *) "Ccedilla"},
/*310*/
{AC_READONLY, 6, (unsigned char *) "Egrave"},
{AC_READONLY, 6, (unsigned char *) "Eacute"},
{AC_READONLY, 11, (unsigned char *) "Ecircumflex"},
{AC_READONLY, 9, (unsigned char *) "Edieresis"},
{AC_READONLY, 6, (unsigned char *) "Igrave"},
{AC_READONLY, 6, (unsigned char *) "Iacute"},
{AC_READONLY, 11, (unsigned char *) "Icircumflex"},
{AC_READONLY, 9, (unsigned char *) "Idieresis"},
/*320*/
{AC_READONLY, 3, (unsigned char *) "Eth"},
{AC_READONLY, 6, (unsigned char *) "Ntilde"},
{AC_READONLY, 6, (unsigned char *) "Ograve"},
{AC_READONLY, 6, (unsigned char *) "Oacute"},
{AC_READONLY, 11, (unsigned char *) "Ocircumflex"},
{AC_READONLY, 6, (unsigned char *) "Otilde"},
{AC_READONLY, 9, (unsigned char *) "Odieresis"},
{AC_READONLY, 8, (unsigned char *) "multiply"},
/*330*/
{AC_READONLY, 6, (unsigned char *) "Oslash"},
{AC_READONLY, 6, (unsigned char *) "Ugrave"},
{AC_READONLY, 6, (unsigned char *) "Uacute"},
{AC_READONLY, 11, (unsigned char *) "Ucircumflex"},
{AC_READONLY, 9, (unsigned char *) "Udieresis"},
{AC_READONLY, 6, (unsigned char *) "Yacute"},
{AC_READONLY, 5, (unsigned char *) "Thorn"},
{AC_READONLY, 10, (unsigned char *) "germandbls"},
/*340*/
{AC_READONLY, 6, (unsigned char *) "agrave"},
{AC_READONLY, 6, (unsigned char *) "aacute"},
{AC_READONLY, 11, (unsigned char *) "acircumflex"},
{AC_READONLY, 6, (unsigned char *) "atilde"},
{AC_READONLY, 9, (unsigned char *) "adieresis"},
{AC_READONLY, 5, (unsigned char *) "aring"},
{AC_READONLY, 2, (unsigned char *) "ae"},
{AC_READONLY, 8, (unsigned char *) "ccedilla"},
/*350*/
{AC_READONLY, 6, (unsigned char *) "egrave"},
{AC_READONLY, 6, (unsigned char *) "eacute"},
{AC_READONLY, 11, (unsigned char *) "ecircumflex"},
{AC_READONLY, 9, (unsigned char *) "edieresis"},
{AC_READONLY, 6, (unsigned char *) "igrave"},
{AC_READONLY, 6, (unsigned char *) "iacute"},
{AC_READONLY, 11, (unsigned char *) "icircumflex"},
{AC_READONLY, 9, (unsigned char *) "idieresis"},
/*360*/
{AC_READONLY, 3, (unsigned char *) "eth"},
{AC_READONLY, 6, (unsigned char *) "ntilde"},
{AC_READONLY, 6, (unsigned char *) "ograve"},
{AC_READONLY, 6, (unsigned char *) "oacute"},
{AC_READONLY, 11, (unsigned char *) "ocircumflex"},
{AC_READONLY, 6, (unsigned char *) "otilde"},
{AC_READONLY, 9, (unsigned char *) "odieresis"},
{AC_READONLY, 6, (unsigned char *) "divide"},
/*370*/
{AC_READONLY, 6, (unsigned char *) "oslash"},
{AC_READONLY, 6, (unsigned char *) "ugrave"},
{AC_READONLY, 6, (unsigned char *) "uacute"},
{AC_READONLY, 11, (unsigned char *) "ucircumflex"},
{AC_READONLY, 9, (unsigned char *) "udieresis"},
{AC_READONLY, 6, (unsigned char *) "yacute"},
{AC_READONLY, 5, (unsigned char *) "thorn"},
{AC_READONLY, 9, (unsigned char *) "ydieresis"},
};
