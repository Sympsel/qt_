#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

   public:
    explicit Widget(QWidget* parent = nullptr);
    ~Widget() override;

   private slots:
    void on_pushButton_clicked();

   private:
    void processReSpone();
   private:
    Ui::Widget* ui;
    QUdpSocket* socket;
};
#endif  // WIDGET_H
