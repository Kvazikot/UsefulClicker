/*
+ - - - + - + - -
+ - + - + copyright by Vladimir Baranov (Kvazikot)  <br>
+ - + - + email: vsbaranov83@gmail.com  <br>
+ - + - + github: https:/images//github.com/Kvazikot/UsefulMacro/  <br>
```
                          )            (
                         /(   (\___/)  )\
                        ( #)  \ ('')| ( #
                         ||___c\  > '__||
                         ||**** ),_/ **'|
                   .__   |'* ___| |___*'|
                    \_\  |' (    ~   ,)'|
                     ((  |' /(.  '  .)\ |
                      \\_|_/ <_ _____> \______________
                       /   '-, \   / ,-'      ______  \
              b'ger   /      (//   \\)     __/     /   \
                                          './_____/
```
*/


/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https:/images//www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https:/images//www.qt.io/terms-conditions. For further
** information use the contact form at https:/images//www.qt.io/contact-us.
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

#include "ui/mainwindow.h"
#include "dialogtype.h"
#include <stdarg.h>
#include <stdio.h>
#include <QToolBar>
#include <QFile>
#include <QPushButton>
#include <QSettings>
#include <QLabel>
#include <QDir>
#include <QInputDialog>
#include <QTimer>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QPainter>
#include <windows.h>
#include "model/treemodel.h"
#include "model/simpledelegate.h"
#include "model/fancydelegate.h"
#include "model/clickermodel.h"
#include "model/domitem.h"
#include "aboutbox.h"
#include "settings/clickersettings.h"
#include "xml/clickerdocument.h"
#include "ui/shelldialog.h"
#include "interpreter/interpreter.h"
#include "interpreter/interpreterwin64.h"
#include "log/logger.h"

MainWindow* MainWindow::instance;
static InterpreterWin64* interpreter = 0;
static QComboBox* functionSelector;
QString MainWindow::current_filename;
extern void MouseClick(QPoint coordinates, Qt::MouseButton button);


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    setWindowTitle("UsefulClicker");
    instance = this;
    logWindow = 0;
    const QStringList headers({tr("#"), tr("Title"), tr("Description")});

    ///applyChangesFlag = false;
    pauseFlag = false;
    startTimer(50);
    n_cycle = 0;
    current_filename = DEFAULT("last_sheme").toString();
    //----------------------------------------------------
    //QString xml = "<xml> <error message=\"You have xml error. This is a default xml. Check xml document\"> </xml>";
    QString xml = "<?xml version='1.0'?> <xml error=\"This is default document. Make sure you load right xml.\">  </xml>";
    bool ok  = (*(QDomDocument*)&defaultDoc).setContent(xml);
    qDebug() << "defaultDoc.setContent " << ok;
    setDoc(&defaultDoc);


    loadDocument(current_filename);
    //--------------------------------------------------------------------
    loadSettings();
    interpreter = new InterpreterWin64();
    interpreter->init(*getDoc());

    //--------------------------------------------------------------------

    QToolBar* toolbar = new QToolBar(this);
    playAction =  toolbar->addAction(QIcon(":/images/play.png"), "Play");    
    pauseFlag = true;

    QAction* refreshAction =  toolbar->addAction(QIcon(":/images/refresh-icon.png"), "Refresh");
    connect(refreshAction, &QAction::triggered, this, &MainWindow::reload);

    QLabel* label = new QLabel(this);
    label->setText("<b>Fucntion List</b>-->");

    functionSelector = new QComboBox(this);
    QStringList list;
    getDoc()->getFunctionsList(doc->documentElement(),list);
    functionSelector->addItems(list);
    functionSelector->setMinimumWidth(200);
    toolbar->addWidget(label);
    toolbar->addWidget(functionSelector);
    connect(functionSelector, SIGNAL(currentTextChanged(const QString&)), this, SLOT(functionSelected(const QString&)));

    QAction* newFunAction =  toolbar->addAction(QIcon(":/images/new_fun.png"), "New fun");
    connect(newFunAction, &QAction::triggered, this, &MainWindow::new_fun);

    QLabel* xmlEditorStatus = new QLabel(this);
    connect(xmlEditor, SIGNAL(updateStatusBar(const QString&, bool)), this, SLOT(updateStatus(const QString&, bool)));
    connect(xmlEditor_2, SIGNAL(updateStatusBar(const QString&, bool)), this, SLOT(updateStatus(const QString&, bool)));
    //connect(xmlEditor, SIGNAL(textChanged()), this, SLOT(updateFunctionEditor()));
    //updateStatusBar
    statusBar()->addWidget(xmlEditorStatus);

    connect(xmlEditor, SIGNAL(textChanged()), this, SLOT(xmlChanged()));

    connect(xmlEditor_2, SIGNAL(cursorPositionChanged()), this, SLOT(xml2CursorChanged()));

    xmlEditor_2->setReadOnly(false);

    //connect(playAction, &QAction::triggered, daemon, &InterpreterDaemon::terminate);
    connect(playAction, &QAction::triggered, this, &MainWindow::pause);
    connect(actionOpen, &QAction::triggered, this, &MainWindow::openXml);
    addToolBar(toolbar);

    FancyDelegate* spinbox = new FancyDelegate(view);
    view->setItemDelegate(spinbox);
    view->header()->setEditTriggers(QAbstractItemView::NoEditTriggers);


    QImage image(":/images/vector-star-icon.png");
    QStandardItem *item = new QStandardItem();
    //item->setData(QVariant(QPixmap::fromImage(image)), Qt::DecorationRole);
    model->itemData(model->index(0,0))[Qt::DecorationRole].setValue(QPixmap::fromImage(image));

    for (int row = 0; row < model->rowCount(); ++row)
    {
        QMap<int,QVariant> roles;
        roles[Qt::DecorationRole] = QVariant(QPixmap::fromImage(image));
        model->setItemData(model->index(row,0),roles);
        model->setHeaderData(0,Qt::Orientation::Horizontal,roles[Qt::DecorationRole],Qt::DecorationRole);
    }
 //
    connect(view, SIGNAL(clicked(const QModelIndex &)), this, SLOT(itemActivated(const QModelIndex &)));
    connect(view, SIGNAL(activated()), this, SLOT(itemActivated()));
    view->parentWidget()->setStyleSheet("QTreeView::item { padding: 10px }; white-space:pre-wrap; word-wrap:break-word" );

    for (int column = 1; column < model->columnCount(); ++column)
        view->setColumnWidth(column, 500);

    view->setColumnWidth(0, 130);

    connect(exitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

    connect(view->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateActions);

    connect(actionsMenu, &QMenu::aboutToShow, this, &MainWindow::updateActions);
    connect(insertRowAction, &QAction::triggered, this, &MainWindow::insertRow);
    connect(removeRowAction, &QAction::triggered, this, &MainWindow::removeRow);
    connect(insertChildAction, &QAction::triggered, this, &MainWindow::insertChild);
    connect(actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(actionSave, &QAction::triggered, this, &MainWindow::save);
    connect(view,SIGNAL(currentChanged(const QModelIndex &current, const QModelIndex &previous)),
            this,SLOT(elementClicked(const QModelIndex& current, const QModelIndex& previous)));

    updateActions();
}

void MainWindow::setLogWindow(QPlainTextEdit* wnd)
{
    logWindow = wnd;
}

void MainWindow::log(QString msg)
{
   if( logWindow )
   {
       //insertPlainText
       auto cursor = logWindow->textCursor();
       cursor.movePosition(QTextCursor::Start);
       QString time = QDateTime::currentDateTime().toString("[hh:mm:ss.zzz] ");
       cursor.insertText(time + msg + "\n");
       cursor.movePosition(QTextCursor::Start);
       logWindow->setTextCursor(cursor);
   }
   else
       cached_messages.push_back(msg);
}

void MainWindow::xmlChanged()
{

}

void drawPlus(QImage& act_image, QPixmap& plus)
{
    QPainter painter(&act_image);
    QRect rect1 = act_image.rect();
    QRect rect2 = rect1;
    rect2.setWidth(300);
    rect2.setHeight(300);
    rect2.setTop(rect1.height()-rect2.height());
    rect2.setBottom(rect1.bottom());
    rect2.moveLeft(300);
    //painter.fillRect(rect2,Qt::red);
    painter.drawPixmap(rect2, plus);
}


void MainWindow::contextMenuActionTriggered()
{
    QAction* act = static_cast<QAction*>(sender());
    last_action_triggered = act->text();
    qDebug() << __FUNCTION__ << act->text();
    if( action_map.contains(act->text()) )
    {
        DialogType dialog_type = action_map[act->text()];
        createDialog(this, dialog_type);
    }
}

QAction* MainWindow::createAction(QString icon, QString text, bool addPlusFlag)
{
    static QPixmap plus_image(":/images/plus.png");
    QImage act_image = QImage(icon);
    act_image = act_image.scaled(600,600);
    if( addPlusFlag )
        drawPlus(act_image, plus_image);
    QAction* act =  new QAction(QIcon(QPixmap::fromImage(act_image)),text);
    connect(act, SIGNAL(triggered()), this, SLOT(contextMenuActionTriggered()));
    return act;
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(createAction(":/images/copy-icon.png", "Copy this ", false));
    menu.addAction(createAction(":/images/paste-icon.png", "Paste after this", false));
    menu.addSeparator();
    menu.addAction(createAction(":/images/mouse_left_click.png", "Add left click"));
    menu.addAction(createAction(":/images/mouse_right_click.png", "Add right click"));
    menu.addAction(createAction(":/images/mouse_scroll.png", "Add scroll down"));
    menu.addAction(createAction(":/images/mouse_scroll.png", "Add scroll up"));
    menu.addSeparator();
    menu.addAction(createAction(":/images/keyboard_icon.png", "Add keydown"));
    menu.addAction(createAction(":/images/type.png", "Add type"));
    menu.addAction(createAction(":/images/Terminal-icon.png", "Add Shell"));
    menu.addAction(createAction(":/images/area_icon.png", "Add image click"));
    menu.addAction(createAction(":/images/area_icon.png", "Area click"));
    menu.addSeparator();
    menu.addAction(createAction(":/images/clock-icon.png", "Set delay for this"));
    menu.exec(event->globalPos());
}

void MainWindow::XmlStringFromUniversalDialog(QMap<QString,QString> attrs_map)
{
    QString xml_string;
    auto event = attrs_map["event"];
    bool withDelayFlag = attrs_map["withDelayFlag"].toInt();
    if(withDelayFlag)
    {
        if(event == "hotkey")
            xml_string = QString("<hotkey hotkey=\"%1\" delay_fixed=\"%2\" delay_random=\"%3\" repeats=\"%4\" />")
                        .arg(attrs_map["hotkey"])
                        .arg(attrs_map["delay_fixed"])
                        .arg(attrs_map["delay_random"])
                        .arg(attrs_map["repeats"]);
        if(event == "click")
            xml_string = QString("<click button=\"%1\" x=\"%2\" y=\"%3\" delay_fixed=\"%4\" delay_random=\"%5\" repeats=\"%6\"/>")
                                .arg(attrs_map["button"])
                                .arg(attrs_map["x"])
                                .arg(attrs_map["y"])
                                .arg(attrs_map["delay_fixed"])
                                .arg(attrs_map["delay_random"])
                                .arg(attrs_map["repeats"]);
        if(event == "area")
            xml_string = QString("<click button=\"%1\" area=\"%2\" delay_fixed=\"%3\" delay_random=\"%4\" repeats=\"%5\"/>")
                                .arg(attrs_map["button"])
                                .arg(attrs_map["area"])
                                .arg(attrs_map["delay_fixed"])
                                .arg(attrs_map["delay_random"])
                                .arg(attrs_map["repeats"]);

        if(event == "scroll")
        {
            if( attrs_map["delta"].toInt() > 0)
                xml_string = QString("<scrollup delta=\"%1\" delay_fixed=\"%2\" delay_random=\"%3\" repeats=\"%4\"/>")
                             .arg(attrs_map["delta"])
                             .arg(attrs_map["delay_fixed"])
                             .arg(attrs_map["delay_random"])
                             .arg(attrs_map["repeats"]);

            else
                xml_string = QString("<scrolldown delta=\"%1\" delay_fixed=\"%2\" delay_random=\"%3\" repeats=\"%4\"/>")
                             .arg(attrs_map["delta"])
                             .arg(attrs_map["delay_fixed"])
                             .arg(attrs_map["delay_random"])
                             .arg(attrs_map["repeats"]);


        }
    }
    else // without delay attributes (default delay)
    {
        if(event == "hotkey")
            xml_string = QString("<hotkey hotkey=\"%1\" />")
                        .arg(attrs_map["hotkey"]);
        if(event == "click")
            xml_string = QString("<click button=\"%1\" x=\"%2\" y=\"%3\" />")
                                .arg(attrs_map["button"])
                                .arg(attrs_map["x"])
                                .arg(attrs_map["y"]);
        if(event == "area")
            xml_string = QString("<click button=\"%1\" area=\"%2\" />")
                                .arg(attrs_map["button"])
                                .arg(attrs_map["area"]);
        if(event == "scroll")
        {
            if( attrs_map["delta"].toInt() > 0)
                xml_string = QString("<scrollup delta=\"%1\" />")
                             .arg(attrs_map["delta"]);

            else
                xml_string = QString("<scrolldown delta=\"%1\" />")
                             .arg(attrs_map["delta"]);

            if( attrs_map["wheel_repeats"] != "0" )
            {
                if( attrs_map["delta"].toInt() > 0)
                    xml_string = QString("<scrollup delta=\"%1\"  repeats=\"%2\" />")
                                 .arg(attrs_map["delta"])
                                 .arg(attrs_map["wheel_repeats"]);

                else
                    xml_string = QString("<scrolldown delta=\"%1\"  repeats=\"%2\" />")
                                 .arg(attrs_map["delta"])
                                 .arg(attrs_map["wheel_repeats"]);
               modifyXmlString(xml_string);
               return;
            }

        }

    }

    insertXmlString(xml_string);
}

void MainWindow::slotSetAttrs(QMap<QString,QString> attrs_map)
{
    QString xml_string;
    //for()

    if( attrs_map.contains("event") )
    {
        XmlStringFromUniversalDialog(attrs_map);
        return;
    }

    QString act = last_action_triggered;
    if( act.contains("left click") )
    {
        xml_string = QString("<click button=\"left\" x=\"%1\" y=\"%2\" />")
                            .arg(attrs_map["x"])
                            .arg(attrs_map["y"]);
    }
    if( act.contains("right click") )
    {
        xml_string = QString("<click button=\"right\" x=\"%1\" y=\"%2\" />")
                            .arg(attrs_map["x"])
                            .arg(attrs_map["y"]);
    }

    if( act.contains("scroll down") )
    {
        xml_string = QString("<scrolldown repeats=\"5\" />");
    }

    if( act.contains("scroll up") )
    {
        xml_string = QString("<scrollup repeats=\"5\" />");
    }

    if( act.contains("Add keydown") )
    {
        xml_string = QString("<hotkey hotkey=\"ctrl + v\" delay_fixed=\"450\" repeats=\"6\" />");
    }

    if( act.contains("Area") )
    {
        xml_string = QString("<click button=\"left\" area=\"%1\" />").arg(attrs_map["area"]);
    }

    if( act.contains("image click") )
    {
        xml_string = QString("<clickimg targetImg=\"%1\" button=\"left\" delay_fixed=\"1000\"> </clickimg>").arg(attrs_map["targetImg"]);
    }


    if( act.contains("rectangle click") )
    {
        xml_string = QString("<clickrectn=\"%1\" button=\"left\" n=\"%2\" rect=\"200x140\" area_tolerance=\"5%%\" ratio_tolerance=\"2%%\"  /> ")
                     .arg(attrs_map["targetImg"])
                     .arg(attrs_map["targetImg"]);
    }

    if( act.contains("Add type") )
    {
        if(!attrs_map.contains("mode"))
            xml_string = QString("<type> %1 </type>").arg(attrs_map["text"]);
        else
            xml_string = QString("<type mode=\"%2\"> %1 </type>").arg(attrs_map["text"]).arg(attrs_map["mode"]);

    }

    if( act.contains("keydown") )
    {
        xml_string = QString("<hotkey hotkey=\"%1\" />").arg(attrs_map["hotkey"]);
    }


    insertXmlString(xml_string);


}


void MainWindow::insertXmlString(QString xml_string)
{
    QString xml = xmlEditor->toPlainText();
    xml = xml.replace("\n</func>","\n"+xml_string+"\n</func>");
    xmlEditor->setText(xml);
}

void MainWindow::modifyXmlString(QString xml_string)
{
    QString xml = xmlEditor->toPlainText();
    QStringList lines = xml.split("\n");
    int idx = lines.size()-3;
    if(idx>0)
      lines[idx] = xml_string;
    xmlEditor->setText(lines.join("\n"));
}

void MainWindow::new_fun()
{
    qDebug() << __FUNCTION__;
    bool ok;
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                         tr("Function name:"), QLineEdit::Normal,
                                         xmlEditor->genFunName(), &ok);
    if (ok && !text.isEmpty())
        xmlEditor->newFun(text);

}

static QPushButton* applyButton = 0;
static QPushButton* apply_button2 = 0;
static QLabel* errorLabel = 0;

void MainWindow::updateStatus(const QString& text, bool applyChangesFlag)
{
    if( text.contains("error"))
    {
        if(errorLabel!=0)
        {
            statusBar()->removeWidget(errorLabel);
            delete errorLabel;
            errorLabel = 0;
        }
        errorLabel = new QLabel(this);
        errorLabel->setText(text);
        errorLabel->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(255, 255, 255);");
        statusBar()->addWidget(errorLabel, width()-errorLabel->width());

    }
    else
    {
        if(errorLabel!=0)
        {
            statusBar()->removeWidget(errorLabel);
            delete errorLabel;
            errorLabel = 0;
        }
        if( applyChangesFlag && applyButton == 0 )
        {
            applyButton = new QPushButton(this);
            applyButton->setText("Apply changes");
            connect(applyButton, SIGNAL(clicked()), this, SLOT(applyChangesXml()));
            statusBar()->addWidget(applyButton, width()-applyButton->width());

        }
    }


}

QPoint GetMousePos();

#include <QTreeWidgetItem>


void MainWindow::applyChangesXml()
{
    // update model from main XML editor
    if( xmlEditor_2->iamChanged )
    {
        if( current_filename.isNull() || current_filename.contains(":/tests") )
            current_filename = "temp.xml";
        QFile f( current_filename );
        if( !f.open( QFile::WriteOnly | QFile::Truncate ) )
        {
            qDebug() << "Cannot open file " + current_filename;
            return ;
        }
        QTextStream ts(&f);
        ts << xmlEditor_2->toPlainText();
        f.close();
        QString xml = xmlEditor_2->toPlainText();

        if( !doc->checkXmlSyntax(xml) )
            emit xmlEditor->updateStatusBar("Xml error!", false);
        else
        {
            emit xmlEditor->updateStatusBar("Xml OK!", true);
            reloadFromFile(current_filename);
        }





    }

    // update model from function editor
    //if( xmlEditor->iamChanged )
    //    xmlEditor->applyChanges();

    // reload xml model
    auto doc = *model->getDoc();
    delete model;
    model = new ClickerModel(doc);
    //reload tree view model
    view->setModel(model);

    // remove button from status Bar
    statusBar()->removeWidget(applyButton);
    applyButton = 0;

}

void MainWindow::applyChanges()
{
    auto current = view->currentIndex();
    QDomNode node = model->getNodeByIndex(current);
    node.toElement().setAttribute("comment", commentEditor->toPlainText());
    if( commentEditor->toPlainText().size() == 0 )
        node.toElement().removeAttribute("comment");
    statusBar()->removeWidget(apply_button2);
    apply_button2 = 0;
}

void MainWindow::commentChanged()
{
    auto current = view->currentIndex();
    QDomNode node = model->getNodeByIndex(current);
    QString old_comment;
    if( node.toElement().hasAttribute("comment") )
        old_comment = node.toElement().attribute("comment");
    if( old_comment!=commentEditor->toPlainText() )
    {
      //node.toElement().setAttribute("comment", commentEditor->toPlainText());
        //statusBar()->widge
        if( apply_button2 == 0 )
        {
            apply_button2 = new QPushButton(this);
            apply_button2->setText("Apply changes");
            connect(apply_button2, SIGNAL(clicked()), this, SLOT(applyChanges()));
            statusBar()->addWidget(apply_button2);
        }
    }
}

void MainWindow::itemActivated(const QModelIndex &)
{
    auto current = view->currentIndex();
    const int row =  current.row();
    const int column = current.column();
    qDebug() << "Clicked at " << row << column;


    statusBar()->removeWidget(errorLabel);

    QDomNode node = model->getNodeByIndex(current);
    if( node.toElement().hasAttribute("comment") )
        commentEditor->setText(node.toElement().attribute("comment"));
    else
        commentEditor->setText(node.toElement().attribute(""));

    //functionSelector->setCurrentText(node.nodeValue());


    QModelIndex index2 =  current.siblingAtColumn(2);
    QDomNode node2 = model->getNodeByIndex(index2);
    QString value = index2.model()->data(index2, Qt::EditRole).toString();
    // parse func name : name = "GetBooks"
    QStringList tok = value.split("=");
    if(tok.size() >= 2)
    {
        auto func_name = tok[1].trimmed();
        func_name = func_name.replace("\"","");
        qDebug() << func_name;
        int index = functionSelector->findText(func_name);
        if ( index != -1 ) { // -1 for not found
            functionSelector->setCurrentIndex(index);
        }

    }

    qDebug() << "2 column " << value;
    connect(commentEditor, SIGNAL(textChanged()), this, SLOT(commentChanged()) );

    if( node.nodeName() == "func" )
    {
        auto fun_name = node.toElement().attribute("name");
        auto func_body_text = getDoc()->getFunction(fun_name);
        if(!func_body_text.isNull())
        {
            xmlEditor->setFuncNode(node);
            xmlEditor->enableChangeEvent(false);
            xmlEditor->clear();
            xmlEditor->setXml(func_body_text);
            xmlEditor->enableChangeEvent(true);
        }
    }
    if( node.parentNode().nodeName() == "func" )
    {
        node = node.parentNode();
        auto fun_name = node.toElement().attribute("name");
        auto func_body_text = getDoc()->getFunction(fun_name);
        if(!func_body_text.isNull())
        {
            xmlEditor->setFuncNode(node);
            xmlEditor->enableChangeEvent(false);
            xmlEditor->clear();
            xmlEditor->setXml(func_body_text);
            xmlEditor->enableChangeEvent(true);
        }
    }
    //xmlEditor->setText();
}

AbstractInterpreter* MainWindow::getInterpreter()
{
    return interpreter;
}

void MainWindow::xml2CursorChanged()
{
    QTextCursor cursor = xmlEditor_2->textCursor();
    cursor.select(QTextCursor::LineUnderCursor);
    QString searchLine = cursor.selectedText();
    QStringList lines  = xmlEditor_2->toPlainText().split("\n");
    int line_number = 0;
    foreach(QString l, lines)
    {
        if( l.contains(searchLine) )
        {
            int n_max = line_number;
            while(--n_max > 0)
            {
                if( lines[n_max].contains("<func ") )
                {
                    // QRegularExpression re("[<]{0,1}func.*name=(.*)[>]{1}");
                     QRegularExpression re("<func name=\"([\\w _\\d]+)\"");
                     QRegularExpressionMatch match = re.match(lines[n_max]);
                     if( match.hasMatch() )
                     {
                         QString name = match.capturedTexts()[1];
                         name = name.replace("\"","");
                         //qDebug() << name;
                         n_max = -5;
                         disableCursorMove = true;
                         int index = functionSelector->findText(name);
                         if ( index != -1 ) { // -1 for not found
                             functionSelector->setCurrentIndex(index);
                         }
                         disableCursorMove = true;
                         break;
                     }
                }
            }
            if( n_max == -5) break;

            break;
        }
        line_number++;
    }
}

void MainWindow::updateFunctionEditor()
{
    auto func_body_text = getDoc()->getFunction(functionSelector->currentText());
    xmlEditor->clear();
    xmlEditor->setText(func_body_text);
}

void MainWindow::functionSelected(const QString&)
{

    updateFunctionEditor();
    if( !disableCursorMove )
    {
        // select text in xmlEditor_2
        QTextDocument *document = xmlEditor_2->document();
        QTextCursor c_start(document);
        c_start.setPosition(0, QTextCursor::MoveAnchor);
        c_start.setPosition(0, QTextCursor::KeepAnchor);
        QTextCursor c = document->find( functionSelector->currentText(), c_start);
        //c.movePosition(QTextCursor::Start);
        //show_message("",QString::number(c.position()) );
        xmlEditor_2->moveCursor(QTextCursor::End);
        int start = c.selectionStart();
        int end   = c.selectionEnd();
        c.setPosition(end  ,QTextCursor::MoveAnchor);
        c.setPosition(start,QTextCursor::KeepAnchor);
        xmlEditor_2->setTextCursor(c);

    }
    /*

    QList<QTextEdit::ExtraSelection> selections;
    auto cursor = xmlEditor_2->textCursor();
    int _startIndex = xmlEditor_2->toPlainText().indexOf(functionSelector->currentText());
    show_message("", QString::number(_startIndex));
    cursor.setPosition(_startIndex);
    //cursor.
    //cursor.select(QTextCursor::LineUnderCursor);
    xmlEditor_2->moveCursor(QTextCursor::End);

    QTextFormat format;
    QTextEdit::ExtraSelection es;
    es.format.setBackground(Qt::red);
    es.cursor = cursor;
    selections.push_back(es);
    xmlEditor_2->setExtraSelections(selections);

*/

}

MainWindow* MainWindow::getInstance()
{
    return instance;
}


void MainWindow::openXml()
{    
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setDirectory(QDir::currentPath() + "/xml");
    QStringList fileNames;
    if (dialog.exec())
    {
        fileNames = dialog.selectedFiles();
        if( fileNames.size()>0 )
          loadDocument(fileNames[0]);
    }


}

void MainWindow::pause()
{
    pauseFlag = ! pauseFlag;

    if( pauseFlag )
    {
       playAction->setIcon(QIcon(":/images/play.png"));
       PlayButton->setIcon(QIcon(":/images/play_123.png"));
    }
    else
    {
       playAction->setIcon(QIcon(":/images/pause.png"));
       PlayButton->setIcon(QIcon(":/images/pause.png"));
       MainWindow* window = MainWindow::getInstance();
       QDomDocument* doc = static_cast<QDomDocument*>(window->getDoc());
       InterpreterWin64*  interpreter = static_cast<InterpreterWin64*>(window->getInterpreter());
       connect(interpreter, SIGNAL(setCurrentNode(const QDomNode&,Delays)), this, SLOT(currentStep(const QDomNode&,Delays)));
       connect(this, SIGNAL(pause()), interpreter, SLOT(stop()));
       QString func_name = functionSelector->currentText();
       interpreter->executeFunction(doc->documentElement(), doc->documentElement(), func_name);
       playAction->setIcon(QIcon(":/images/play.png"));
       PlayButton->setIcon(QIcon(":/images/play_123.png"));
       pauseFlag = ! pauseFlag;
    }

}

void MainWindow::reload()
{

    reloadFromFile(current_filename);
}

// reload from memory (original document)
void MainWindow::reloadFromMemory()
{
    loadSettings();
    //loadDocument(current_filename);
    model->getDoc()->reload();
    ClickerDocument doc = *model->getDoc();
    delete model;
    model = new ClickerModel(doc);
    view->setModel(model);


}

// reload from file
void MainWindow::reloadFromFile(QString& filename)
{
    loadSettings();
    current_filename = filename;
    loadDocument(current_filename);
}

ClickerDocument* MainWindow::getDoc()
{
    return doc;
}

void MainWindow::setDoc(ClickerDocument* _doc)
{
    doc = _doc;
    xmlEditor->setDoc(doc);
}


void MainWindow::loadDocument(QString filename)
{
    current_filename = filename;
    if( !filename.contains("temp") )
        SAVE_DEFAULT("last_sheme", filename);
    delete model;
    ClickerDocument* doc = new ClickerDocument(filename);
    if( doc->isLoaded )
    {
        setDoc(doc);
        model = new ClickerModel(*doc);
        view->setModel(model);
        view->collapseAll();
        view->expand(view->currentIndex());

        // set full text of documentt to XmlEditor_2
        // (Occam razor)
        QFile f(filename);
        if( !f.open( QFile::ReadOnly ) )
            qDebug() << "Cannot open file " + filename;
        QTextStream ts(&f);
        QString xml_text = ts.readAll();
        xmlEditor_2->enableChangeEvent(true);
        QTextCursor cur = xmlEditor_2->textCursor();
        int p = cur.position();
        xmlEditor_2->setText(xml_text);
        // set cursor at last pos
        QTextCursor c(xmlEditor_2->document());
        int start = c.selectionStart();
        int end   = c.selectionEnd();
        c.setPosition(end + p  ,QTextCursor::MoveAnchor);
        c.setPosition(start + p,QTextCursor::KeepAnchor);
        xmlEditor_2->setTextCursor(c);
        xmlEditor_2->moveCursor(QTextCursor::End);

        //view->expandAll();
    }
    else
    {
        setDoc(&defaultDoc);
        model = new ClickerModel(defaultDoc);
        view->setModel(model);
        view->expandAll();
    }
}

void MainWindow::setNextItem(QModelIndex& index)
{
    auto index2 = view->indexBelow(index);
    view->setCurrentIndex(index2);
}

void MainWindow::setCurentDomNode(QDomNode& currentNode)
{
    traverseTree(model->index(0,0), currentNode, view );
}

void MainWindow::traverseTree(const QModelIndex &index, const QDomNode& targetNode, QTreeView *view)
{
    if (!index.isValid()) {
        return;
    }

    const QModelIndex &child = view->indexBelow(index);
    DomItem *item1 = (DomItem*)(index.internalPointer());

    if(item1)
    {
        if (index.isValid())
        {
            view->setCurrentIndex(view->indexBelow(index));
            if( item1->node() == targetNode)
                return;
        }
    }

    // Recursively call the function for each child node.
    traverseTree(child, targetNode, view);

    if (!view->isExpanded(index)) {
        view->expand(index);
    }
}

void MainWindow::loadSettings()
{
    ClickerSettings::getInstance()->reload();
}

//-----------------------------------------------------------

void MainWindow::timerEvent(QTimerEvent* event)
{
    event->accept();
}

void MainWindow::saveToFile(QString& filename)
{
    QString textData;
    ClickerModel *model =  (ClickerModel*)view->model();
    model->save(filename);

}

void MainWindow::about()
{
    AboutBox* aboutbox = new AboutBox(this);
    aboutbox->show();

}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    event->accept();
}

void MainWindow::insertChild()
{
    const QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel *model = view->model();

    if (model->columnCount(index) == 0) {
        if (!model->insertColumn(0, index))
            return;
    }

    if (!model->insertRow(0, index))
        return;


    for (int column = 0; column < model->columnCount(index); ++column) {
        const QModelIndex child = model->index(0, column, index);
        model->setData(child, QVariant(tr("[No data]")), Qt::EditRole);
        if (!model->headerData(column, Qt::Horizontal).isValid())
            model->setHeaderData(column, Qt::Horizontal, QVariant(tr("[No header]")), Qt::EditRole);
    }

    view->selectionModel()->setCurrentIndex(model->index(0, 0, index),
                                            QItemSelectionModel::ClearAndSelect);
    updateActions();
}


void MainWindow::insertRow()
{
    const QModelIndex index = view->currentIndex();
    QRect rect = view->visualRect(index);
    QPoint center = view->mapToGlobal(rect.center());
    center.setY(center.y()+rect.height());
    auto parentItem = static_cast<DomItem*>(index.internalPointer());
    QDomNode newNode = parentItem->node().cloneNode(false);
    parentItem->node().parentNode().toElement().insertAfter(newNode, parentItem->node());
    //model->domDocument.
    save();
    reloadFromFile(current_filename);
    MouseClick(center, Qt::MouseButton::LeftButton);
}
void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    event->globalPosition();
}

void MainWindow::removeRow()
{
    const QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel *model = view->model();
    model->removeRow(index.row(), index.parent());
}

void MainWindow::updateActions()
{
    const QModelIndex current = view->selectionModel()->currentIndex();
    const int row =  current.row();
    const int column = current.column();
    qDebug() << "Clicked at " << row << column;
}





void MainWindow::on_leftClick_clicked()
{
    last_action_triggered = "left click";
    createDialog(this, DialogType::MOUSE_DIALOG, "click");
}


void MainWindow::on_keyboardClick_clicked()
{
    last_action_triggered = "hotkey";
    createDialog(this, DialogType::MOUSE_DIALOG, "hotkey");
}


void MainWindow::on_areaClick_clicked()
{
    last_action_triggered = "Area click";
    createDialog(this, DialogType::AREA_SELECTOR);
}

void MainWindow::on_imageClick_clicked()
{
    last_action_triggered = "Add image click";
    createDialog(this, DialogType::SCREEN_BUTTONS_DETECTOR);
}


void MainWindow::on_typeTag_clicked()
{
    last_action_triggered =  "Add type";
    createDialog(this, DialogType::TYPE_DIALOG);
}


void MainWindow::on_rectClick_clicked()
{
    last_action_triggered = "Add rectangle click";
    createDialog(this, DialogType::SCREEN_BUTTONS_DETECTOR, "rect_mode");
}


void MainWindow::on_rectClick_triggered(QAction *arg1)
{

}


void MainWindow::on_PlayButton_triggered(QAction *arg1)
{
    playAction->trigger();
}


void MainWindow::on_view_clicked(const QModelIndex &index)
{
    //view->selectionModel()->c
    qDebug() << index.row();
}


void MainWindow::on_PlayButton_clicked()
{
    playAction->trigger();
}

