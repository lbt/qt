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
#include <QtDBus>
#include <QtTest>

const char errorName[] = "com.trolltech.tst_QDBusContext.Error";
const char errorMsg[] = "A generic error";

class TestObject: public QObject, protected QDBusContext
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.trolltech.tst_QDBusContext.TestObject")
public:
    inline TestObject(QObject *parent) : QObject(parent) { }
public Q_SLOTS:
    void generateError();
};

class tst_QDBusContext: public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase();
    void sendErrorReply();
};

void TestObject::generateError()
{
    sendErrorReply(errorName, errorMsg);
}

void tst_QDBusContext::initTestCase()
{
    TestObject *obj = new TestObject(this);
    QVERIFY(QDBusConnection::sessionBus().isConnected());
    QVERIFY(QDBusConnection::sessionBus().registerObject("/TestObject", obj,
                                                          QDBusConnection::ExportAllSlots));
}

void tst_QDBusContext::sendErrorReply()
{
    QDBusInterface iface(QDBusConnection::sessionBus().baseService(), "/TestObject");
    QVERIFY(iface.isValid());

    QDBusReply<void> reply = iface.call("generateError");
    QVERIFY(!reply.isValid());

    const QDBusError &error = reply.error();
    QCOMPARE(error.name(), QString::fromLatin1(errorName));
    QCOMPARE(error.message(), QString::fromLatin1(errorMsg));
}

QTEST_MAIN(tst_QDBusContext)

#include "tst_qdbuscontext.moc"
