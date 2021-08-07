#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QChar>
#include <QString>
#include <stack>
#include <cctype>
#include <string>
#include <QStack>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public slots:
    void onOneClicked();
    void onTwoClicked();
    void onThreeClicked();
    void onFourClicked();
    void onFiveClicked();
    void onSixClicked();
    void onSevenClicked();
    void onEightClicked();
    void onNineClicked();
    void onZeroClicked();
    void onAddClicked();
    void onSubClicked();
    void onMultiplyClicked();
    void onDivideClicked();
    void onClearClicked();
    void onPartialClearClicked();
    void onEqualClicked();
    void onDotClicked();


public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    bool oper;
};
#endif // DIALOG_H
