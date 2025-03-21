/*
**	Command & Conquer Red Alert(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//	ToolTip.h

#ifdef WOLAPI_INTEGRATION

#ifndef TOOLTIP_H
#define TOOLTIP_H

#include "Gadget.h"

#define TOOLTIPTEXT_MAX_LEN		100

#define TOOLTIPDELAY			400		//	Milliseconds

class ToolTipClass
{
public:
	ToolTipClass( GadgetClass* pGadget, const char* szText, int xShow, int yShow, bool bRightAlign = false, bool bIconList = false );
	~ToolTipClass()
	{
		delete [] pSaveRect;
	}

	ToolTipClass*	GetToolTipHit();
	void			Show();
	void			Unshow();
	void			Move( int xShow, int yShow );
	bool			bOverDifferentLine() const;

	ToolTipClass*	next;					//	Next tooltip in list of which *this is a part.

	GadgetClass*	pGadget;							//	Gadget to which this tooltip is bound.

	bool			bRightAlign;

	bool			bShowing;
	bool			bIconList;			//	True if gadget is iconlist and line-specific tooltips are to be used.

protected:
	bool			bGadgetHit() const;

	int				xShow;
	int				yShow;
	int				wShow;
	int				hShow;
	char			szTip[ TOOLTIPTEXT_MAX_LEN + 1 ];	//	Text to show as tip.

	char*			pSaveRect;

	//	Used only if bIconList.
	int				iLastIconListIndex;
	bool			bLastShowNoText;
	int				xLastShow;
	int				yLastShow;
	int				wLastShow;
};

#endif

#endif
