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

   private:
    void processRequest();

    void process(const QString& request, QString& respone);

   private:
    Ui::Widget* ui;
    QUdpSocket* socket;
};
#endif  // WIDGET_H
