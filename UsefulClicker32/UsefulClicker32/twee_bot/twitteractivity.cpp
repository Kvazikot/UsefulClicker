#include <QRegularExpression>
#include <QFile>
#include <QTextStream>
#include <windows.h>
#include "twee_bot/twitteractivity.h"
#include "twee_bot/searchwindow.h"

void print(QString s);

TwitterActivity::TwitterActivity()
{

}

bool isNameLike(QString str)
{
    QStringList lst = str.split(" ");

    bool toLongWords = false;
    foreach(QString s, lst )
    {
        if (s.size() > 14)
            toLongWords = true;
    }

    if( lst.size() > 0 &&   lst.size() < 4 && !toLongWords)
        return true;
    else
        return false;
}

void TwitterActivity::ParseTwit(QString twit_text)
{
    // TODO: delete strings like  2 093 просмотра
    // TODO: delete strings like   0:13 / 0:30
    QRegularExpression re1("[\\d:]+[ /][\\d:]+");

    QStringList lst = twit_text.split("\r");
    for(int i=0; i < lst.size(); i++)
    {
         QRegularExpressionMatch m = re1.match(lst[i]);
         if ( m.hasMatch() )
             lst[i] = " ";
    }

    if(lst.size()>1)
    {
        Twit twit = twits[twits.size()-1];
        Twit prevtwit;
        twit.time = lst[2];
        lst[0] = " ";
        lst[1] = " ";
        lst[2] = " ";
        if (isNameLike(lst[lst.size()-2]))
          lst[lst.size()-2] = " ";
        twit.text = lst.join("\r").trimmed();
        twits[twits.size()-1] = twit;
    }


}

void TwitterActivity::ParseTwits(QString clipboard_data)
{
    twits.clear();

  // parse strings like @mich263213
    QRegularExpression re("([@]{1}(\\w+))");
    QStringList lines = clipboard_data.split("\n");
    Twit t;
    QString twit_text;
    int number_on_screen = 0;
    for(int i=1; i < lines.size(); i++)
    {
        QString& l_prev = lines[i-1];
        QString& l = lines[i];
        if( l.contains("Актуальные темы") )
        {
            ParseTwit(twit_text);
            break;
        }
        QRegularExpressionMatch m = re.match(l);
        if( m.hasMatch() )
        {
            //print(m.capturedTexts()[0]);
            t.nick = m.capturedTexts()[0];
            t.name = l_prev;
            t.number_on_screen = number_on_screen;
            number_on_screen++;
            if(twits.size()>0)
                ParseTwit(twit_text);
            twits.push_back(t);
            twit_text="";
        }
            twit_text+=l;
    }

    print(">> LIST of TWITS--------------------------");
    foreach (auto twit, twits)
        print(twit.nick);
    print("<< END OF LIST--------------------------");

    print(">> TEXTS of TWITS--------------------------");
    foreach (auto twit, twits) {
        print(">>--------------------------<<");
        print(twit.text);
    }
    print("<< END OF LIST--------------------------");

}

void TwitterActivity::run()
{
    SearchWindow search;
    HWND h = search.setWindowFocus("Google Chrome");
    //ShowWindow(h, SW_MAXIMIZE);

    // open prepared test case of my current tweets
    // from the file clipboard.txt
    QFile f("./twee_bot/clipboard.txt");
    if( f.open( QFile::ReadOnly ) )
    {
        QTextStream ts(&f);
        //ts.setCodec("utf8");
        ts.setEncoding(QStringConverter::Utf8);

        ParseTwits( ts.readAll() );
        f.close();
    }

}
