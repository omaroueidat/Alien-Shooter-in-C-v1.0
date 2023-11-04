#include "typedef.h"

extern player Create_player();
extern void Place_Player(char ** border, player p);
extern void Remove_Player(char **border, player p);
extern void Move_Up(player *p);
extern void Move_Down(player *p);
extern void Move_Right(player *p);
extern void Move_Left(player *p);
extern void *Shoot_fire (char **border, player p);
extern void *Move_Player(char user_input, char **border, player *p);