/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the examples of the Qt Toolkit.
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

#ifndef ABSTRACTVIEWITEM_H
#define ABSTRACTVIEWITEM_H

#include <QModelIndex>

#include "gvbwidget.h"
#include "abstractitemview.h"
#include "listitem.h"

class QGraphicsWidget;

class AbstractViewItem : public GvbWidget
{
    Q_OBJECT
public:
    AbstractViewItem(QGraphicsWidget *parent = 0);
    virtual ~AbstractViewItem();

    virtual AbstractViewItem *newItemInstance() = 0;

    QModelIndex modelIndex() const;

    void setModelIndex(const QModelIndex &index);

    AbstractViewItem *prototype() const;
    AbstractItemView *itemView() const;
    void setItemView(AbstractItemView *itemView) ;
    virtual void updateItemContents();
    virtual void themeChange();

#if (QT_VERSION >= 0x040600)
    virtual void setSubtreeCacheEnabled(bool enabled);
#endif

    virtual QSizeF effectiveSizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const;

    virtual void setModel(QAbstractItemModel *model) = 0;
    virtual QVariant data(int role) const = 0;
    virtual void setData(const QVariant &value, int role = Qt::DisplayRole) = 0;
    virtual void setTwoColumns(const bool enabled) = 0;

protected:
    virtual bool event(QEvent *e);

    QPersistentModelIndex m_index;

private:
    Q_DISABLE_COPY(AbstractViewItem)

    AbstractItemView *m_itemView;
    AbstractViewItem *m_prototype;

};

#endif // ABSTRACTVIEWITEM_H
