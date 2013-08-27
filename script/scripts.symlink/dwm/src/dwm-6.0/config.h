/*
static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#999999";
static const char selbordercolor[]  = "#005577";
static const char selbgcolor[]      = "#005577";
static const char selfgcolor[]      = "#eeeeee";
*/
/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>

/* appearance */
static const char font[]            = "-*-terminusmod-medium-r-normal-*-12-*-*-*-*-*-*-*";
#define NUMCOLORS 9
static const char colors[NUMCOLORS][ColLast][9] = {
// border foreground background
  /*{ "#444444", "#999999", "#222222" }, // 0 = normal
	{ "#005577", "#eeeeee", "#005577" }, // 1 = selected
	{ "#212121", "#DC322F", "#222222" }, // 2 = red
	{ "#212121", "#A6E22E", "#222222" }, // 3 = green
	{ "#212121", "#FFFF55", "#222222" }, // 4 = yellow
	{ "#212121", "#1E6FA8", "#222222" }, // 5 = blue
	{ "#212121", "#EB2657", "#222222" }, // 6 = magenta
	{ "#212121", "#66D9EF", "#222222" }, // 7 = cyan
	{ "#212121", "#AAAAAA", "#222222" }, // 8 = grey*/

	//Solarized - Dark
	{ "#444444", "#999999", "#222222" }, // 0 = normal
	{ "#005577", "#eeeeee", "#268bd2" }, // 1 = selected
	{ "#212121", "#dc322f", "#222222" }, // 2 = red
	{ "#212121", "#859900", "#222222" }, // 3 = green
	{ "#212121", "#b58900", "#222222" }, // 4 = yellow
	{ "#212121", "#268bd2", "#222222" }, // 5 = blue
	{ "#212121", "#d33682", "#222222" }, // 6 = magenta
	{ "#212121", "#2aa198", "#222222" }, // 7 = cyan
	{ "#212121", "#AAAAAA", "#222222" }, // 8 = grey
};
static const unsigned int panelpadding  = 4;    /* padding from fonts on panel */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showsystray       = True;     /* False means no systray */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "1", "2", "3"};

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            True,        -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.6; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "[]|",      deck },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
// static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char  *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *termcmd[]  = { "xterm", NULL };

static const char *volumedown[] = { "amixer", "-q", "set", "Master", "2%-", "unmute", NULL };
static const char *volumeup[] = { "amixer", "-q", "set", "Master", "2%+", "unmute", NULL };
static const char *mediaplay[] = { "mpc", "toggle", NULL };
static const char *systemsuspend[] = { "systemctl", "suspend", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_e,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_a,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_d,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ 0, 		XF86XK_AudioLowerVolume,	   spawn, 			{ .v = volumedown } },
	{ 0, 		XF86XK_AudioRaiseVolume,	   spawn, 			{ .v = volumeup } },
	{ 0, 		XF86XK_AudioPlay,			   spawn, 			{ .v = mediaplay } },
	{ 0, 		XF86XK_Sleep,				   spawn, 			{ .v = systemsuspend } },
	{ MODKEY,                       XK_n,      spawn,    		SHCMD("notify-send \"$(mpc -f 'Artist: %artist%\nAlbum:  %album%\nTitle:  %title%')\n\n$(mpc playlist|head)\"") },
	{ MODKEY, 						XK_p, 	   spawn, 			SHCMD("dmenu-mpd -a") },
	{ MODKEY|ShiftMask,				XK_p, 	   spawn, 			SHCMD("dmenu-mpd -t") },
	{ MODKEY|ShiftMask|ControlMask,	XK_p, 	   spawn, 			SHCMD("dmenu-mpd -l") },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
