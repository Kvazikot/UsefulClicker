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
        QRegularExpressionMatch m = re.match(l);
        if( m.hasMatch() )
        {
            print(m.capturedTexts()[0]);
            t.nick = m.capturedTexts()[0];
            t.name = l_prev;
            t.number_on_screen = number_on_screen;
            number_on_screen++;
            if(twits.size()>0)
            {
                QStringList lst = twit_text.split("\r");
                if(lst.size()>1)
                {
                    lst[0] = " ";
                    lst[1] = " ";
                    lst[2] = " ";
                    lst[lst.size()-1] = " ";
                    lst[lst.size()-2] = " ";
                    twits[twits.size()-1].time = lst[2];
                    twits[twits.size()-1].text = lst.join("\r").trimmed();
                }




            }
            twits.push_back(t);

            twit_text="";
        }
            twit_text+=l;
    }

    foreach (auto twit, twits) {
        print(twit.nick);
        print("--------------------------");
        print(twit.text);
        print("--------------------------");
    }
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
        ts.setCodec("utf8");
        ParseTwits( ts.readAll() );
        f.close();
    }

}
