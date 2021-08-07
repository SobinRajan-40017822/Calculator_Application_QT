#include "dialog.h"
#include "ui_dialog.h"



void Dialog::onOneClicked()
{
    QString one = ui->labelDisplay->text();
    one += "1";
    ui->labelDisplay->setText(one);
}

void Dialog::onTwoClicked()
{
    QString two = ui->labelDisplay->text();
    two += "2";
    ui->labelDisplay->setText(two);
}

void Dialog::onThreeClicked()
{
    QString three = ui->labelDisplay->text();
    three += "3";
    ui->labelDisplay->setText(three);
}

void Dialog::onFourClicked()
{
    QString four = ui->labelDisplay->text();
    four += "4";
    ui->labelDisplay->setText(four);
}

void Dialog::onFiveClicked()
{
    QString five = ui->labelDisplay->text();
    five += "5";
    ui->labelDisplay->setText(five);
}

void Dialog::onSixClicked()
{
    QString six = ui->labelDisplay->text();
    six += "6";
    ui->labelDisplay->setText(six);
}

void Dialog::onSevenClicked()
{
    QString seven = ui->labelDisplay->text();
    seven += "7";
    ui->labelDisplay->setText(seven);
}

void Dialog::onEightClicked()
{
    QString eight = ui->labelDisplay->text();
    eight += "8";
    ui->labelDisplay->setText(eight);
}

void Dialog::onNineClicked()
{
    QString nine = ui->labelDisplay->text();
    nine += "9";
    ui->labelDisplay->setText(nine);
}

void Dialog::onZeroClicked()
{
    QString zero = ui->labelDisplay->text();
    zero += "0";
    ui->labelDisplay->setText(zero);
}

void Dialog::onAddClicked()
{
    QString add = ui->labelDisplay->text();
    if ( add == "" );
    else if ( add.back().isDigit() ){
        add += "+";
        ui->labelDisplay->setText(add);
    }
    oper = true;
}

void Dialog::onSubClicked()
{
    QString sub = ui->labelDisplay->text();
    if ( sub == "" );
    else if ( sub.back().isDigit() ){
        sub += "-";
        ui->labelDisplay->setText(sub);
    }
    oper = true;

}

void Dialog::onMultiplyClicked()
{
    QString multiply = ui->labelDisplay->text();
    if ( multiply == "" );
    else if ( multiply.back().isDigit() ){
        multiply += "x";
        ui->labelDisplay->setText(multiply);
    }
    oper = true;

}

void Dialog::onDivideClicked()
{
    QString divide = ui->labelDisplay->text();
    if ( divide == "" );
    else if ( divide.back().isDigit() ){
        divide += "/";
        ui->labelDisplay->setText(divide);
    }
    oper = true;

}

void Dialog::onClearClicked(){
    ui->labelDisplay->clear();
}

void Dialog::onPartialClearClicked()
{
    QString partialClear = ui->labelDisplay->text();
    if (partialClear != "" ){
        int size = partialClear.size()-1;
        partialClear.remove(size, 1);
        ui->labelDisplay->setText(partialClear);
    }

}

template <typename T>
int precedence(T op){
    if(op == '+'||op == '-')
    return 1;
    if(op == 'x'||op == '/')
    return 2;
    return 0;
}

double applyOp(double a, double b, QChar op){
    if ( op == '+' ){
        return a + b;
    }
    else if ( op == '-' ){
        return a - b;
    }
    else if ( op == 'x' ){
        return a * b;
    }
    return a / b;
}

void Dialog::onEqualClicked()
{
    double firstInput;
    double secondInput;
    QString query = ui->labelDisplay->text();
    QString inputString = "";
    std::stack<double> values;
    std::stack<QChar> operation;
    int index;


    if ( !query.back().isDigit() ){
        query.remove(query.size()-1, 1);
    }
    if ( query.front() == '-' ){
        query = "0" + query;
    }

    for( index = 0; index < query.size(); index ++ ){
        if( query[index].isDigit() ){
            while( ( index < query.size() && query[index].isDigit() ) || ( index < query.size() && query[index] == '.' ) ){
                inputString += query[index];
                index++;
            }
            values.push(inputString.toDouble());
            inputString = "";
            index--;
        }
        else{
            while(!operation.empty() && ( precedence(operation.top()) >= precedence(query[index] ) )){
                firstInput = values.top();
                values.pop();
                secondInput = values.top();
                values.pop();
                QChar sign = operation.top();
                operation.pop();

                values.push(applyOp(secondInput, firstInput, sign));
            }
            operation.push(query[index]);
        }

    }
    while(!operation.empty()){
        firstInput = values.top();
        values.pop();
        secondInput = values.top();
        values.pop();
        QChar sign = operation.top();
        operation.pop();

        values.push(applyOp(secondInput, firstInput, sign));
    }

    ui->labelDisplay->setText(QString::number(values.top()));


}


void Dialog::onDotClicked()
{
    QString dot = ui->labelDisplay->text();
    if ( dot == "" ){
        dot +="0.";
    }
    else if ( dot.back() == '.' || oper == false);
    else if ( ! dot[dot.size()-1].isDigit() ){
        dot += "0.";
        oper = false;
    }
    else{
        dot += ".";
        oper = false;
    }
    ui->labelDisplay->setText(dot);

}



Dialog::Dialog(QWidget *parent)
    : QDialog(parent), oper(true)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(onZeroClicked()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(onOneClicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onTwoClicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(onThreeClicked()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(onFourClicked()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(onFiveClicked()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(onSixClicked()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(onSevenClicked()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(onEightClicked()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(onNineClicked()));
    connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(onAddClicked()));
    connect(ui->pushButton_subtract, SIGNAL(clicked()), this, SLOT(onSubClicked()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(onMultiplyClicked()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(onDivideClicked()));
    connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(onClearClicked()));
    connect(ui->pushButton_partialClear, SIGNAL(clicked()), this, SLOT(onPartialClearClicked()));
    connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(onEqualClicked()));
    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(onDotClicked()));


}

Dialog::~Dialog()
{
    delete ui;
}

