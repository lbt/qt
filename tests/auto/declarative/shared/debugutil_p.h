/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include <QSignalSpy>
#include <QEventLoop>
#include <QPointer>
#include <QTimer>
#include <QThread>
#include <QTest>

#include <QtDeclarative/qdeclarativeengine.h>

#include <private/qdeclarativedebugclient_p.h>
#include <private/qdeclarativedebugservice_p.h>
#include <private/qdeclarativeitem_p.h>

class QDeclarativeDebugTest
{
public:
    static bool waitForSignal(QObject *receiver, const char *member, int timeout = 5000);
};

class QDeclarativeDebugTestService : public QDeclarativeDebugService
{
    Q_OBJECT
public:
    QDeclarativeDebugTestService(const QString &s, QObject *parent = 0);

signals:
    void statusHasChanged();

protected:
    virtual void messageReceived(const QByteArray &ba);
    virtual void statusChanged(Status status);
};

class QDeclarativeDebugTestClient : public QDeclarativeDebugClient
{
    Q_OBJECT
public:
    QDeclarativeDebugTestClient(const QString &s, QDeclarativeDebugConnection *c);

    QByteArray waitForResponse();

signals:
    void statusHasChanged();
    void serverMessage(const QByteArray &);

protected:
    virtual void statusChanged(Status status);
    virtual void messageReceived(const QByteArray &ba);

private:
    QByteArray lastMsg;
};


