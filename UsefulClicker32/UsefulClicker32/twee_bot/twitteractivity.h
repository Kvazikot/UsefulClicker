#ifndef TWITTERACTIVITY_H
#define TWITTERACTIVITY_H

#include <vector>
#include "twee_bot/regularactivity.h"

class Twit
{
public:
    Twit(){}
    int     number_on_screen;
    QString nick;
    QString name;
    QString text;
    QString time;
};

class TwitterActivity : public RegularActivity
{
public:
    std::vector<Twit> twits;
    TwitterActivity();
    virtual void run();
    void ParseTwits(QString clipboard_data);
};

#endif // TWITTERACTIVITY_H
