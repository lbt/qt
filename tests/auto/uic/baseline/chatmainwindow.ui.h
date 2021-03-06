/********************************************************************************
** Form generated from reading UI file 'chatmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CHATMAINWINDOW_H
#define CHATMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatMainWindow
{
public:
    QAction *actionQuit;
    QAction *actionAboutQt;
    QAction *actionChangeNickname;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QTextBrowser *chatHistory;
    QHBoxLayout *hboxLayout1;
    QLabel *label;
    QLineEdit *messageLineEdit;
    QPushButton *sendButton;
    QMenuBar *menubar;
    QMenu *menuQuit;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChatMainWindow)
    {
        if (ChatMainWindow->objectName().isEmpty())
            ChatMainWindow->setObjectName(QString::fromUtf8("ChatMainWindow"));
        ChatMainWindow->resize(800, 600);
        actionQuit = new QAction(ChatMainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAboutQt = new QAction(ChatMainWindow);
        actionAboutQt->setObjectName(QString::fromUtf8("actionAboutQt"));
        actionChangeNickname = new QAction(ChatMainWindow);
        actionChangeNickname->setObjectName(QString::fromUtf8("actionChangeNickname"));
        centralwidget = new QWidget(ChatMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hboxLayout = new QHBoxLayout(centralwidget);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        chatHistory = new QTextBrowser(centralwidget);
        chatHistory->setObjectName(QString::fromUtf8("chatHistory"));
        chatHistory->setAcceptDrops(false);
        chatHistory->setAcceptRichText(true);

        vboxLayout->addWidget(chatHistory);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout1->addWidget(label);

        messageLineEdit = new QLineEdit(centralwidget);
        messageLineEdit->setObjectName(QString::fromUtf8("messageLineEdit"));

        hboxLayout1->addWidget(messageLineEdit);

        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy);

        hboxLayout1->addWidget(sendButton);


        vboxLayout->addLayout(hboxLayout1);


        hboxLayout->addLayout(vboxLayout);

        ChatMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChatMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 31));
        menuQuit = new QMenu(menubar);
        menuQuit->setObjectName(QString::fromUtf8("menuQuit"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        ChatMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ChatMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChatMainWindow->setStatusBar(statusbar);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(messageLineEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(chatHistory, messageLineEdit);
        QWidget::setTabOrder(messageLineEdit, sendButton);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuQuit->menuAction());
        menuQuit->addAction(actionAboutQt);
        menuFile->addAction(actionChangeNickname);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(ChatMainWindow);
        QObject::connect(messageLineEdit, SIGNAL(returnPressed()), sendButton, SLOT(animateClick()));
        QObject::connect(actionQuit, SIGNAL(triggered(bool)), ChatMainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(ChatMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChatMainWindow)
    {
        ChatMainWindow->setWindowTitle(QApplication::translate("ChatMainWindow", "QtDBus Chat", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("ChatMainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("ChatMainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionAboutQt->setText(QApplication::translate("ChatMainWindow", "About Qt...", 0, QApplication::UnicodeUTF8));
        actionChangeNickname->setText(QApplication::translate("ChatMainWindow", "Change nickname...", 0, QApplication::UnicodeUTF8));
        actionChangeNickname->setShortcut(QApplication::translate("ChatMainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        chatHistory->setToolTip(QApplication::translate("ChatMainWindow", "Messages sent and received from other users", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("ChatMainWindow", "Message:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        sendButton->setToolTip(QApplication::translate("ChatMainWindow", "Sends a message to other people", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        sendButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        sendButton->setText(QApplication::translate("ChatMainWindow", "Send", 0, QApplication::UnicodeUTF8));
        menuQuit->setTitle(QApplication::translate("ChatMainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("ChatMainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChatMainWindow: public Ui_ChatMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CHATMAINWINDOW_H
