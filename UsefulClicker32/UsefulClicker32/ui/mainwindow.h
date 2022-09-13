/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui/ui_mainwindow.h"
#include "model/clickermodel.h"
#include "xml/clickerdocument.h"
#include "interpreter/interpreter.h"
#include <QMouseEvent>
#include <QTimerEvent>
#include <QMainWindow>
#include <QPlainTextEdit>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setLogWindow(QPlainTextEdit* logWindow);
    void timerEvent(QTimerEvent* event);
    //Main Action of the Application UsefulClicker
    void traverseTree(const QModelIndex &index, const QDomNode& targetNode, QTreeView *view);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void loadDocument(QString filename);
    void XmlStringFromUniversalDialog(QMap<QString,QString> attrs_map);
    void loadSettings();
    QAction* createAction(QString icon, QString text, bool addPlusFlag=true);
    static MainWindow* getInstance();
    static MainWindow* instance;
    QString last_action_triggered;

public slots:
    void updateActions();
    void contextMenuActionTriggered();
    void updateStatus(const QString&, bool);
    void applyChangesXml();
    void contextMenuEvent(QContextMenuEvent *event);
    void about();
    void pause();
    void new_fun();
    void openXml();
    void save(){saveToFile(current_filename);}
    void saveToFile(QString& filename=current_filename);
    void setNextItem(QModelIndex& index);
    void reloadFromFile(QString& filename);
    void functionSelected(const QString&);
    void reloadFromMemory();
    void reload();
    ClickerDocument* getDoc();
    void setDoc(ClickerDocument* doc);
    AbstractInterpreter* getInterpreter();
    void itemActivated(const QModelIndex &);
    void xmlChanged();
    void log(QString msg);
    void slotSetAttrs(QMap<QString,QString> attrs_map);
    void insertXmlString(QString xml_string);
    void modifyXmlString(QString xml_string);

private slots:
    void updateFunctionEditor();
    void xml2CursorChanged();
    void insertChild();
    void applyChanges();
    void commentChanged();
    void insertRow();
    void removeRow();
    void setCurentDomNode(QDomNode& currentNode);
    void on_leftClick_clicked();
    void on_keyboardClick_clicked();

    void on_areaClick_clicked();

    void on_imageClick_clicked();

    void on_typeTag_clicked();

    void on_rectClick_clicked();

    void on_rectClick_triggered(QAction *arg1);

    void on_PlayButton_triggered(QAction *arg1);

    void on_view_clicked(const QModelIndex &index);

    void on_PlayButton_clicked();

private:
    QPlainTextEdit*  logWindow;
    ClickerModel* model=0;
    bool disableCursorMove;
    ClickerDocument* doc;
    ClickerDocument  defaultDoc;
    static QString current_filename;
    QAction* playAction;
    bool pauseFlag;
    int n_cycle;
    QVector<QString> cached_messages;

};

#endif // MAINWINDOW_H
