//this file is part of notepad++
//Copyright (C)2003 Don HO ( donho@altern.org )
//
//This program is free software; you can redistribute it and/or
//modify it under the terms of the GNU General Public License
//as published by the Free Software Foundation; either
//version 2 of the License, or (at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program; if not, write to the Free Software
//Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

// created by Daniel Volk mordorpost@volkarts.com

#ifndef WINCONTROLS_SHORTCUT_RUNMACRODLG_H
#define WINCONTROLS_SHORTCUT_RUNMACRODLG_H

#ifndef WINCONTROLS_STATICDIALOG_STATICDIALOG_H
#include "WinControls/StaticDialog/StaticDialog.h"
#endif

#define RM_CANCEL -1
#define RM_RUN_MULTI 1
#define RM_RUN_EOF 2

class RunMacroDlg : public StaticDialog
{
public :
	RunMacroDlg() : StaticDialog(), m_Mode(RM_RUN_MULTI), m_Times(1) {};

	void init(HINSTANCE hInst, HWND hParent);
	void doDialog(bool isRTL = false);
	void initMacroList();

	int getMode() const {return m_Mode;};
	int getTimes() const {return m_Times;};
	int getMacro2Exec() const;

private :
	virtual BOOL CALLBACK run_dlgProc(UINT message, WPARAM wParam, LPARAM lParam);

	bool isCheckedOrNot(int checkControlID) const;

	void check(int);

	int m_Mode;
	int m_Times;
	int m_macroIndex;
};

#endif //WINCONTROLS_SHORTCUT_RUNMACRODLG_H
