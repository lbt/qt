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
#ifndef XMLDATA_H
#define XMLDATA_H

#include <QtXml>

#include <QMap>
#include <QDateTime>

enum GeneratorFlag {
    Normal      = 0x1 << 0,
    Default     = 0x1 << 1,
    Foreign     = 0x1 << 2,
    Reference   = 0x1 << 3
};
Q_DECLARE_FLAGS(GeneratorFlags, GeneratorFlag);

struct XMLData
{
    XMLData()
        : date(QDateTime::currentDateTime()),
          timeToRender(0), iterations(0), maxElapsed(0),
          minElapsed(0)
    {}
    XMLData(const QDateTime &dt, int ttr, int itrs = 1)
        : date(dt), timeToRender(ttr),
          iterations(itrs), maxElapsed(0), minElapsed(0)
    {}
    XMLData(const QString &dt, int ttr, int itrs = 1)
        : timeToRender(ttr), iterations(itrs),
          maxElapsed(0), minElapsed(0)
    {
        date = QDateTime::fromString(dt);
    }
    QDateTime date;
    int timeToRender;
    int iterations;
    QString details;
    int maxElapsed;
    int minElapsed;
};

struct XMLFile
{
    XMLFile()
    {}
    XMLFile(const QString &testcase)
        : name(testcase)
    {}
    XMLFile(const QString &testcase, const QString &img)
        : name(testcase), output(img)
    {}

    QString name;
    QString output;
    QList<XMLData> data;
};

struct XMLSuite
{
    XMLSuite()
    {}
    XMLSuite(const QString &n)
        : name(n)
    {}

    QString name;
    QMap<QString, XMLFile*> files;
};

struct XMLEngine
{
    XMLEngine()
        : defaultEngine(false), foreignEngine(false),
          referenceEngine(false)
    {}
    XMLEngine(const QString &engine, bool def)
        : name(engine), defaultEngine(def), foreignEngine(false),
          referenceEngine(false)
    {}

    QString name;
    bool defaultEngine;
    bool foreignEngine;
    bool referenceEngine;
    QMap<QString, XMLSuite*> suites;
    QDateTime generationDate;
};



class XMLReader : public QXmlDefaultHandler
{
public:
    XMLEngine *xmlEngine() const
    {
        return engine;
    }

    bool startElement(const QString &namespaceURI,
                      const QString &localName,
                      const QString &qName,
                      const QXmlAttributes &attributes);
    bool endElement(const QString &namespaceURI,
                    const QString &localName,
                    const QString &qName);
    bool fatalError(const QXmlParseException &exception);
private:
    XMLEngine *engine;
    XMLSuite  *suite;
    XMLFile   *file;
};

#endif
