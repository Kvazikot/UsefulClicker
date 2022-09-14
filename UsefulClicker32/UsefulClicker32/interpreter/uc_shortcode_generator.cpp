#include <QDomNode>
#include "uc_shortcode_generator.h"

// <!-- example of short program for Useful Clicker
// xy,140:122,ctrl+f,"banana republic gdp",enter,cr,56,cb,"next"

UC_ShortCode_Generator::UC_ShortCode_Generator()
{

}

QString UC(QDomNode& node)
{
    QString code;
    QString name = node.toElement().tagName().toLocal8Bit();
    QDomElement e = node.toElement();
    #define a(_name_) e.attribute(_name_).toStdString().c_str()
    if( name == "click")
    {
        code = code.sprintf("xy,%s:%s",a("x"), a("y"));
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

