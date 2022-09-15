#include <QDomNode>
#include <QDir>
#include <QTextStream>
#include "uc_shortcode_generator.h"

QString removeTags(QString tag, QString withTags);
// <!-- example of short program for Useful Clicker
// xy,140:122,ctrl+f,"banana republic gdp",enter,cr,56,cb,"next"

UC_ShortCode_Generator::UC_ShortCode_Generator()
{

}

QString UC(QDomNode& node)
{
    QString code;
    QString image_str;
    QString name = node.toElement().tagName().toLocal8Bit();
    QDomElement e = node.toElement();
    #define a(_name_) e.attribute(_name_).toStdString().c_str()
    #define b(_name_) e.attribute(_name_)
    #define img "<img src = \""+ image_str +"\" alt = \"\" width=\"20\" height=\"20\"/>"
    if( name == "click")
    {
        image_str =  QDir::currentPath() + "/images/mouse_left_click.png";
        if( b("button") == "left" )
            image_str =  QDir::currentPath() + "/images/mouse_left_click.png";
        if( b("button") == "right" )
            image_str =  QDir::currentPath() + "/images/mouse_right_click.png";
        code = code.sprintf("xy,%s:%s",a("x"), a("y"));
        code+="<img src = \""+ image_str +"\" alt = \"\" width=\"20\" height=\"20\"/>";
    }
    if( name == "hotkey")
    {
        code+=b("hotkey");
        image_str =  QDir::currentPath() + "/images/keyboard_color.png";
        code+=img;
    }
    if( name == "shell")
    {
        image_str =  QDir::currentPath() + "/images/Terminal-icon.png";
        code+="[" + b("cmd") + "]";
        code+=img;
    }
    if( name == "type")
    {
        QString multiline = node.toElement().nodeValue().toLocal8Bit();
        multiline = multiline.replace("\n","");
        multiline = multiline.replace("\r","");
        // get node value as text
        QString str;
        QTextStream ss(&str);
        ss << node.firstChild();
        multiline = ss.readAll();

        auto text = b("text") + multiline;
        image_str =  QDir::currentPath() + "/images/type.png";
        code+="\""+text+"\"";
        code+=img;
    }

    return code;
}

QString UC_ShortCode_Generator::UCforFunction(QDomNode& node)
{
    QString out_code="";
    for(int i=0; i < node.childNodes().count(); i++)
    {
        QDomNode child = node.childNodes().at(i);
        out_code+=UC(child)+",";
    }
    return out_code;
}

