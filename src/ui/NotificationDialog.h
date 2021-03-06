/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2015 Jan Bajer aka bajasoft <jbajer@gmail.com>
* Copyright (C) 2015 - 2017 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#ifndef OTTER_NOTIFICATIONDIALOG_H
#define OTTER_NOTIFICATIONDIALOG_H

#include <QtCore/QPropertyAnimation>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

namespace Otter
{

class Notification;

class NotificationDialog final : public QDialog
{
	Q_OBJECT

public:
	explicit NotificationDialog(Notification *notification, QWidget *parent = nullptr);

	bool eventFilter(QObject *object, QEvent *event) override;

protected:
	void timerEvent(QTimerEvent *event) override;
	void resizeEvent(QResizeEvent *event) override;

private:
	Notification *m_notification;
	QLabel *m_closeLabel;
	QPropertyAnimation *m_animation;
	int m_closeTimer;
};

}

#endif
