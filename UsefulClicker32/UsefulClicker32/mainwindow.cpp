/*
+ - - - + - + - -
+ - + - + copyright by Vladimir Baranov (Kvazikot)  <br>
+ - + - + email: vsbaranov83@gmail.com  <br>
+ - + - + github: https:/images//github.com/Kvazikot/UsefulClicker/  <br>
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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings/clickersettings.h"
#include "xml/clickerdocument.h"
#include "interpreter/interpreter.h"
#include "interpreter/interpreterwin64.h"
//#include "log/logger.h"

#include <QDateTime>
#include <QDebug>

MainWindow* MainWindow::instance;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("UsefulClicker");
    instance = this;
    logWindow = 0;
    pauseFlag = false;
    startTimer(50);
    current_filename = DEFAULT("last_sheme").toString();

    //----------------------------------------------------
    // setting up default xml doc
    QString xml = "<?xml version='1.0'?> <xml error=\"This is default document. Make sure you load right xml.\">  </xml>";
    bool ok  = (*(QDomDocument*)&defaultDoc).setContent(xml);
    qDebug() << "defaultDoc.setContent " << ok;
    setDoc(&defaultDoc);


    loadDocument(current_filename);
    //--------------------------------------------------------------------
    ClickerSettings::getInstance()->reload();
    interpreter = new InterpreterWin64();
    interpreter->init(*getDoc());

    //--------------------------------------------------------------------
/*
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
*/
}

ClickerDocument* MainWindow::getDoc()
{
    return doc;
}

void MainWindow::setDoc(ClickerDocument* _doc)
{
    doc = _doc;
    ui->xmlEditor->setDoc(doc);
    ui->xmlEditor_2->setDoc(doc);
}

void MainWindow::loadDocument(QString filename)
{
    current_filename = filename;
    if( !filename.contains("temp") )
        SAVE_DEFAULT("last_sheme", filename);
    ClickerDocument* doc = new ClickerDocument(filename);
    if( doc->isLoaded )
    {
        setDoc(doc);
        // set full text of documentt to XmlEditor_2
        QFile f(filename);
        if( !f.open( QFile::ReadOnly ) )
            qDebug() << "Cannot open file " + filename;
        QTextStream ts(&f);
        QString xml_text = ts.readAll();
        ui->xmlEditor_2->enableChangeEvent(true);
        QTextCursor cur = ui->xmlEditor_2->textCursor();
        int p = cur.position();
        ui->xmlEditor_2->setText(xml_text);
        // set cursor at last pos
        QTextCursor c(ui->xmlEditor_2->document());
        int start = c.selectionStart();
        int end   = c.selectionEnd();
        c.setPosition(end + p  ,QTextCursor::MoveAnchor);
        c.setPosition(start + p,QTextCursor::KeepAnchor);
        ui->xmlEditor_2->setTextCursor(c);
        ui->xmlEditor_2->moveCursor(QTextCursor::End);
    }
}

MainWindow* MainWindow::getInstance()
{
    return instance;
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

MainWindow::~MainWindow()
{
    delete ui;
}
