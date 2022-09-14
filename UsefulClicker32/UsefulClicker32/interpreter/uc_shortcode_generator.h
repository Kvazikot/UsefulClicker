#ifndef UC_SHORTCODE_GENERATOR_H
#define UC_SHORTCODE_GENERATOR_H

#include <QDomNode>
#include <QString>

class UC_ShortCode_Generator
{
public:
    UC_ShortCode_Generator();
    QString UCforFunction(QDomNode& node);
};

#endif // UC_SHORTCODE_GENERATOR_H
