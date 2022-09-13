#ifndef EXPRESSIONCALCULATOR_H
#define EXPRESSIONCALCULATOR_H

#include <QObject>

class ExpressionCalculator : public QObject
{
public:
    enum MathError
    {
        NO_MATH_ERROR=0,
        DIVISION_BY_ZERO=1,
        OPERATOR_PRECEDENCE_ERROR=2,
        GENERAL_MATH_EXCEPTION=3,
        UNDEFINED_FUNCTION=4,
        FUNCTION_ARGUMENT_ERROR=5
    };

    explicit ExpressionCalculator(QObject *parent = nullptr);
    int compute(QString expression, QString& result);

};

#endif // EXPRESSIONCALCULATOR_H
