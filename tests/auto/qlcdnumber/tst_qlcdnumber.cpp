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


#include <QtTest/QtTest>

#include <qcoreapplication.h>
#include <qdebug.h>
#include <qlcdnumber.h>


//TESTED_CLASS=
//TESTED_FILES=

class tst_QLCDNumber : public QObject
{
Q_OBJECT

public:
    tst_QLCDNumber();
    virtual ~tst_QLCDNumber();

private slots:
    void getSetCheck();
};

tst_QLCDNumber::tst_QLCDNumber()
{
}

tst_QLCDNumber::~tst_QLCDNumber()
{
}

// Testing get/set functions
void tst_QLCDNumber::getSetCheck()
{
    QLCDNumber obj1;
    // int QLCDNumber::digitCount()
    // void QLCDNumber::setDigitCount(int)
    obj1.setDigitCount(0);
    QCOMPARE(0, obj1.digitCount());
    obj1.setDigitCount(INT_MIN);
    QCOMPARE(0, obj1.digitCount()); // Range<0, 99>
    obj1.setDigitCount(INT_MAX);
    QCOMPARE(99, obj1.digitCount()); // Range<0, 99>
}

QTEST_MAIN(tst_QLCDNumber)
#include "tst_qlcdnumber.moc"
