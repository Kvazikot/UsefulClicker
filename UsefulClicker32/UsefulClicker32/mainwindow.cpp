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
#include <QComboBox>
#include <QToolBar>
#include <QLabel>
#include <QInputDialog>
#include <QFileDialog>

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
    connect(ui->xmlEditor, SIGNAL(updateStatusBar(const QString&, bool)), this, SLOT(updateStatus(const QString&, bool)));
    connect(ui->xmlEditor_2, SIGNAL(updateStatusBar(const QString&, bool)), this, SLOT(updateStatus(const QString&, bool)));
    //connect(xmlEditor, SIGNAL(textChanged()), this, SLOT(updateFunctionEditor()));
    //updateStatusBar
    statusBar()->addWidget(xmlEditorStatus);

    connect(ui->xmlEditor, SIGNAL(textChanged()), this, SLOT(xmlChanged()));

    connect(ui->xmlEditor_2, SIGNAL(cursorPositionChanged()), this, SLOT(xml2CursorChanged()));

    ui->xmlEditor_2->setReadOnly(false);

    connect(playAction, &QAction::triggered, this, &MainWindow::pause);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openXml);
    addToolBar(toolbar);
    //connect(ui->exitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    //connect(ui->actionsMenu, &QMenu::aboutToShow, this, &MainWindow::updateActions);
    //connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    //connect(ui->actionSave, &QAction::triggered, this, &MainWindow::save);

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
       ui->PlayButton->setIcon(QIcon(":/images/play_123.png"));
    }
    else
    {
       playAction->setIcon(QIcon(":/images/pause.png"));
       ui->PlayButton->setIcon(QIcon(":/images/pause.png"));
       MainWindow* window = MainWindow::getInstance();
       QDomDocument* doc = static_cast<QDomDocument*>(window->getDoc());
       InterpreterWin64*  interpreter = (InterpreterWin64*)window->getInterpreter();
       connect(interpreter, SIGNAL(setCurrentNode(const QDomNode&,Delays)), this, SLOT(currentStep(const QDomNode&,Delays)));
       connect(this, SIGNAL(pause()), interpreter, SLOT(stop()));
       QString func_name = functionSelector->currentText();
       interpreter->executeFunction(doc->documentElement(), doc->documentElement(), func_name);
       playAction->setIcon(QIcon(":/images/play.png"));
       ui->PlayButton->setIcon(QIcon(":/images/play_123.png"));
       pauseFlag = ! pauseFlag;
    }

}

AbstractInterpreter* MainWindow::getInterpreter()
{
    return interpreter;
}

void MainWindow::new_fun()
{
    qDebug() << __FUNCTION__;
    bool ok;
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                         tr("Function name:"), QLineEdit::Normal,
                                         ui->xmlEditor->genFunName(), &ok);
    if (ok && !text.isEmpty())
        ui->xmlEditor->newFun(text);

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
    else
    {
        QString filename = ".\\tests\\UsefulClicker_tests.xml";
        QFile f(filename);
        if ( f.exists() )
        {
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

    }
}

void MainWindow::reload()
{

    reloadFromFile(current_filename);
}


// reload from file
void MainWindow::reloadFromFile(QString& filename)
{
    ClickerSettings::getInstance()->reload();
    current_filename = filename;
    loadDocument(current_filename);
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
