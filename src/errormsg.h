/*
 * Copyright (C) 2003 Cies Breijs <cies # kde ! nl>

    This program is free software; you can redistribute it and/or
    modify it under the terms of version 2 of the GNU General Public
    License as published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

// BEGIN include and defines 

#ifndef _ERRORMSG_H_
#define _ERRORMSG_H_

#include <kdialogbase.h>

#include <qlayout.h>
#include <qlabel.h>
#include <qstring.h>
#include <qtable.h>


// this const is used in executer, treenode and errormsg when uint row/col information is N/A
//const uint NA = 999999999;  --->  leads to redefinition, thats why:
#include "treenode.h"


class ErrorMessage : public KDialogBase {
 Q_OBJECT
	public:
	ErrorMessage(QWidget *parent);
	~ErrorMessage() {}
	
	bool containsErrors();

	void display();

	public slots:
	void slotAddError(QString msg = "", uint row = NA, uint col = NA, uint code = NA);
	void updateSelection();

	signals:
	void SetCursor(uint row, uint column);

	private:
	QTable       *errTable;

	protected:
	QDialog      *dialog;
	QVBoxLayout  *baseLayout;
	QLabel       *label;
	QSpacerItem  *spacer;
};


#endif // _ERRORMSG_H_
