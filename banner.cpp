#include <cstdlib>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

void banner(WINDOW *game_win)
{
  // mvprintw(0, 0,
  //        "      ::::::::  :::::::::      :::     ::::::::: :::   :::          ::::::::      :::     :::::::::   :::::::: \n");
  // printw("    :+:    :+: :+:    :+:   :+: :+:        :+:  :+:   :+:         :+:    :+:   :+: :+:   :+:    :+: :+:    :+: \n");
  // printw("   +:+        +:+    +:+  +:+   +:+      +:+    +:+ +:+          +:+         +:+   +:+  +:+    +:+ +:+         \n");
  // printw("  +#+        +#++:++#:  +#++:++#++:    +#+      +#++:           +#+        +#++:++#++: +#++:++#:  +#++:++#++   \n");
  // printw(" +#+        +#+    +#+ +#+     +#+   +#+        +#+            +#+        +#+     +#+ +#+    +#+        +#+    \n");
  // printw("#+#    #+# #+#    #+# #+#     #+#  #+#         #+#            #+#    #+# #+#     #+# #+#    #+# #+#    #+#     \n");
  // printw("########  ###    ### ###     ### #########    ###             ########  ###     ### ###    ###  ########       \n");
}

void banner_car(WINDOW *game_win, int y, int x)
{
  mvwprintw(game_win, y, x, "   ______");
  mvwprintw(game_win, y + 1, x, "  /|_||_\\`.__");
  mvwprintw(game_win, y + 2, x, " (   _    _ _\\");
  mvwprintw(game_win, y + 3, x, " =`-(_)--(_)-'");
}
