#ifndef MAIN_H
#define MAIN_H

#include <QtGui>

#include "control_panel.h"
#include "panel_info.h"
#include "panel_serial.h"
#include "panel_setup.h"
#include "panel_about.h"
#include "panel_detail.h"

extern QStackedWidget *stack;
extern control_panel *cp;
extern panel_info *pnl_info;
extern panel_setup *pnl_setup;
extern panel_serial *pnl_serial;
extern panel_detail *pnl_detail;
extern panel_about *pnl_about;


#endif // MAIN_H
